#include <vector>
#include <string>
#include <cmath>

#include "sfxrparams.h"

namespace Synthesizer   
{
  double random();
	/**
	 * SfxrParams
	 * 
	 * Copyright 2010 Thomas Vian
	 *
	 * Licensed under the Apache License, Version 2.0 (the "License");
	 * you may not use this file except in compliance with the License.
	 * You may obtain a copy of the License at
	 *
	 * 	http://www.apache.org/licenses/LICENSE-2.0
	 *
	 * Unless required by applicable law or agreed to in writing, software
	 * distributed under the License is distributed on an "AS IS" BASIS,
	 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	 * See the License for the specific language governing permissions and
	 * limitations under the License.
	 * 
	 * @author Thomas Vian
	 */
		
  SfxrParams::SfxrParams()
      // real name, decription, grouping, default, min, max, 
      : masterVolume ( Param<double>{"Master Volume","Overall volume of the sound.", 1,0.5,0,1}) 	
      , attackTime ( Param<double>{"Attack Time","Length of the volume envelope attack.", 1,0,0,1})		
      , sustainTime ( Param<double>{"Sustain Time","Length of the volume envelope sustain.", 1,0.3,0,1}) 	
      , sustainPunch ( Param<double>{"Punch","Tilts the sustain envelope for more 'pop'.", 1,0,0,1}) 		
      , decayTime ( Param<double>{"Decay Time","Length of the volume envelope decay (yes, I know it's called release).", 1,0.4,0,1}) 	
      , compressionAmount ( Param<double>{"Compression","Pushes amplitudes together into a narrower range to make them stand out more.  Very good for sound effects, where you want them to stick out against background music.", 15,0.3,0,1})
      , startFrequency ( Param<double>{"Frequency","Base note of the sound.", 2,0.3,0,1}) 		
      , minFrequency ( Param<double>{"Frequency Cutoff","If sliding, the sound will stop at this frequency, to prevent really low notes.  If unlocked, this is set to zero during randomization.", 2,0.0,0,1}) 		
      , slide ( Param<double>{"Frequency Slide","Slides the frequency up or down.", 3,0.0,-1,1}) 	
      , deltaSlide ( Param<double>{"Delta Slide","Accelerates the frequency slide.  Can be used to get the frequency to change direction.", 3,0.0,-1,1}) 		
      , vibratoDepth ( Param<double>{"Vibrato Depth","Strength of the vibrato effect.", 4,0,0,1}) 		
      , vibratoSpeed ( Param<double>{"Vibrato Speed","Speed of the vibrato effect (i.e. frequency).", 4,0,0,1}) 		
      , overtones ( Param<double>{"Harmonics","Overlays copies of the waveform with copies and multiples of its frequency.  Good for bulking out or otherwise enriching the texture of the sounds (warning: this is the number 1 cause of bfxr slowdown!).", 13,0,0,1}) 		
      , overtoneFalloff ( Param<double>{"Harmonics Falloff","The rate at which higher overtones should decay.", 13,0,0,1}) 
      , changeRepeat ( Param<double>{"Pitch Jump Repeat Speed","Larger Values means more pitch jumps, which can be useful for arpeggiation.", 5,0,0,1}) 		
      , changeAmount ( Param<double>{"Pitch Jump Amount 1","Jump in pitch, either up or down.", 5,0,-1,1}) 		
      , changeSpeed ( Param<double>{"Pitch Jump Onset 1","How quickly the note shift happens.", 5,0,0,1}) 		
      , changeAmount2 ( Param<double>{"Pitch Jump Amount 2","Jump in pitch, either up or down.", 5,0,-1,1}) 	
      , changeSpeed2 ( Param<double>{"Pitch Jump Onset 2","How quickly the note shift happens.", 5,0,0,1}) 		
      , squareDuty ( Param<double>{"Square Duty","Square waveform only : Controls the ratio between the up and down states of the square wave, changing the tibre.", 8,0,0,1}) 		
      , dutySweep ( Param<double>{"Duty Sweep","Square waveform only : Sweeps the duty up or down.", 8,0,-1,1}) 		
      , repeatSpeed ( Param<double>{"Repeat Speed","Speed of the note repeating - certain variables are reset each time.", 9,0,0,1}) 	
      , flangerOffset ( Param<double>{"Flanger Offset","Offsets a second copy of the wave by a small phase, changing the tibre.", 10,0,-1,1}) 		
      , flangerSweep ( Param<double>{"Flanger Sweep","Sweeps the phase up or down.", 10,0,-1,1}) 
      , lpFilterCutoff ( Param<double>{"Low-pass Filter Cutoff","Frequency at which the low-pass filter starts attenuating higher frequencies.  Named most likely to result in 'Huh why can't I hear anything?' at her high-school grad. ", 11,1,0,1}) 		
      , lpFilterCutoffSweep ( Param<double>{"Low-pass Filter Cutoff Sweep","Sweeps the low-pass cutoff up or down.", 11,0,-1,1}) 	
      , lpFilterResonance ( Param<double>{"Low-pass Filter Resonance","Changes the attenuation rate for the low-pass filter, changing the timbre.", 11,0,0,1}) 		
      , hpFilterCutoff ( Param<double>{"High-pass Filter Cutoff","Frequency at which the high-pass filter starts attenuating lower frequencies.", 12,0,0,1}) 	
      , hpFilterCutoffSweep ( Param<double>{"High-pass Filter Cutoff Sweep","Sweeps the high-pass cutoff up or down.", 12,0,-1,1}) 	
      , bitCrush ( Param<double>{"Bit Crush","Resamples the audio at a lower frequency.", 14,0,0,1})
      , bitCrushSweep ( Param<double>{"Bit Crush Sweep","Sweeps the Bit Crush filter up or down.", 14,0,-1,1}) 
		{
			//initialize param object 
			resetParams();


      attackTime.random_power = 4;
      sustainTime.random_power = 2;
      sustainPunch.random_power = 2;
      overtones.random_power = 3;
      overtoneFalloff.random_power = 0.25;
      vibratoDepth.random_power = 3;
      dutySweep.random_power = 3;
      flangerOffset.random_power = 3;
      flangerSweep.random_power = 3;
      lpFilterCutoff.random_power = 0.3;
      // lpFilterCutoffSweep.random_power = 3;
      hpFilterCutoff.random_power = 5;
      // hpFilterCutoffSweep.random_power = 5;
      bitCrush.random_power = 4;
      bitCrushSweep.random_power = 5;
		}

		void SfxrParams::setAllLocked(bool locked)
    {
      waveType_locked = locked;
      auto params = GetParams();
      for(auto* p: params)
      {
        p->locked = locked;
      }
    }
		
    std::vector<SfxrParams::Param<double>*> SfxrParams::GetParams()
		{
      std::vector<Param<double>*> ret;

      ret.push_back(&masterVolume);
      ret.push_back(&attackTime);
      ret.push_back(&sustainTime);
      ret.push_back(&sustainPunch);
      ret.push_back(&decayTime);
      ret.push_back(&compressionAmount);
      ret.push_back(&startFrequency);
      ret.push_back(&minFrequency);
      ret.push_back(&slide);
      ret.push_back(&deltaSlide);
      ret.push_back(&vibratoDepth);
      ret.push_back(&vibratoSpeed);
      ret.push_back(&overtones);
      ret.push_back(&overtoneFalloff);
      ret.push_back(&changeRepeat);
      ret.push_back(&changeAmount);
      ret.push_back(&changeSpeed);
      ret.push_back(&changeAmount2);
      ret.push_back(&changeSpeed2);
      ret.push_back(&squareDuty);
      ret.push_back(&dutySweep);
      ret.push_back(&repeatSpeed);
      ret.push_back(&flangerOffset);
      ret.push_back(&flangerSweep);
      ret.push_back(&lpFilterCutoff);
      ret.push_back(&lpFilterCutoffSweep);
      ret.push_back(&lpFilterResonance);
      ret.push_back(&hpFilterCutoff);
      ret.push_back(&hpFilterCutoffSweep);
      ret.push_back(&bitCrush);
      ret.push_back(&bitCrushSweep);

      return ret;
		}
		
		//--------------------------------------------------------------------------
		//
		//  Generator Methods
		//
		//--------------------------------------------------------------------------
		
		/**
		 * Sets the parameters to generate a pickup/coin sound
		 */
		void SfxrParams::generatePickupCoin()
		{
			resetParams();
			
			startFrequency.set(0.4+random()*0.5);
			
			sustainTime.set( random() * 0.1);
			decayTime.set( 0.1 + random() * 0.4);
			sustainPunch.set( 0.3 + random() * 0.3);
			
			if(random() < 0.5) 
			{
				changeSpeed.set( 0.5 + random() * 0.2);
				auto cnum = int(random()*7)+1;
				auto cden = cnum+int(random()*7)+2;
				
				changeAmount.set(static_cast<double>(cnum)/cden);
			}
			
		}
		
		/**
		 * Sets the parameters to generate a laser/shoot sound
		 */
		void SfxrParams::generateLaserShoot()
		{
			resetParams();
			
			auto wt = static_cast<unsigned int>(random() * 3);
			if( wt == 2 && random() < 0.5) 
			{
				wt = static_cast<unsigned int>(random() * 2);
			}
      waveType = static_cast<WaveType>(wt);
			
			startFrequency.set(0.5 + random() * 0.5);
			minFrequency.set(startFrequency.get() - 0.2 - random() * 0.6);
			
			if(minFrequency.get() < 0.2) 
				minFrequency.set(0.2);
			
			slide.set( -0.15 - random() * 0.2);			
			 
			if(random() < 0.33)
			{
				startFrequency.set( random() * 0.6);
				minFrequency.set( random() * 0.1);
				slide.set( -0.35 - random() * 0.3);
			}
			
			if(random() < 0.5) 
			{
				squareDuty.set( random() * 0.5);
				dutySweep.set( random() * 0.2);
			}
			else
			{
				squareDuty.set( 0.4 + random() * 0.5);
				dutySweep.set(- random() * 0.7);	
			}
			
			sustainTime.set( 0.1 + random() * 0.2);
			decayTime.set( random() * 0.4);
			if(random() < 0.5) sustainPunch.set( random() * 0.3);
			
			if(random() < 0.33)
			{
				flangerOffset.set( random() * 0.2);
				flangerSweep.set( -random() * 0.2);
			}
			
			if(random() < 0.5) hpFilterCutoff.set( random() * 0.3);
		}
		
		/**
		 * Sets the parameters to generate an explosion sound
		 */
		void SfxrParams::generateExplosion()
		{
			resetParams();
			waveType = WaveType::Noise;
			
			if(random() < 0.5)
			{
				startFrequency.set( 0.1 + random() * 0.4);
				slide.set( -0.1 + random() * 0.4);
			}
			else
			{
				startFrequency.set( 0.2 + random() * 0.7);
				slide.set( -0.2 - random() * 0.2);
			}
			
			startFrequency.set( startFrequency.get() * startFrequency.get());
			
			if(random() < 0.2) slide.set( 0.0);
			if(random() < 0.33) repeatSpeed.set( 0.3 + random() * 0.5);
			
			sustainTime.set( 0.1 + random() * 0.3);
			decayTime.set( random() * 0.5);
			sustainPunch.set( 0.2 + random() * 0.6);
			
			if(random() < 0.5)
			{
				flangerOffset.set( -0.3 + random() * 0.9);
				flangerSweep.set( -random() * 0.3);
			}
			
			if(random() < 0.33)
			{
				changeSpeed.set( 0.6 + random() * 0.3);
				changeAmount.set( 0.8 - random() * 1.6);
			}
		}
		
		/**
		 * Sets the parameters to generate a powerup sound
		 */
		void SfxrParams::generatePowerup()
		{
			resetParams();
			
			if(random() < 0.5) waveType = WaveType::Saw;
			else 					squareDuty.set( random() * 0.6);
			
			if(random() < 0.5)
			{
				startFrequency.set( 0.2 + random() * 0.3);
				slide.set( 0.1 + random() * 0.4);
				repeatSpeed.set( 0.4 + random() * 0.4);
			}
			else
			{
				startFrequency.set( 0.2 + random() * 0.3);
				slide.set( 0.05 + random() * 0.2);
				
				if(random() < 0.5)
				{
					vibratoDepth.set( random() * 0.7);
					vibratoSpeed.set( random() * 0.6);
				}
			}
			
			sustainTime.set( random() * 0.4);
			decayTime.set( 0.1 + random() * 0.4);
		}
		
		/**
		 * Sets the parameters to generate a hit/hurt sound
		 */
		void SfxrParams::generateHitHurt()
		{
			resetParams();
			
			const auto wt = static_cast<unsigned int>(random() * 3);
			switch(wt) {
        case 0: waveType = WaveType::Square; break;
        case 1: waveType = WaveType::Saw; break;
        case 2: waveType = WaveType::Noise; break;
      }
			if(waveType == WaveType::Square) 
				squareDuty.set( random() * 0.6);
			
			startFrequency.set( 0.2 + random() * 0.6);
			slide.set( -0.3 - random() * 0.4);
			
			sustainTime.set( random() * 0.1);
			decayTime.set( 0.1 + random() * 0.2);
			
			if(random() < 0.5) hpFilterCutoff.set( random() * 0.3);
		}
		
		/**
		 * Sets the parameters to generate a jump sound
		 */
		void SfxrParams::generateJump()
		{
			resetParams();
			
			waveType = WaveType::Square;
			squareDuty.set( random() * 0.6);
			startFrequency.set( 0.3 + random() * 0.3);
			slide.set( 0.1 + random() * 0.2);
			
			sustainTime.set( 0.1 + random() * 0.3);
			decayTime.set( 0.1 + random() * 0.2);
			
			if(random() < 0.5) hpFilterCutoff.set( random() * 0.3);
			if(random() < 0.5) lpFilterCutoff.set( 1.0 - random() * 0.6);
		}
		
		/**
		 * Sets the parameters to generate a blip/select sound
		 */
		void SfxrParams::generateBlipSelect()
		{
			resetParams();
			
      waveType = (random() < 0.5)? WaveType::Square : WaveType::Saw;
			if(waveType == WaveType::Square) 
				squareDuty.set( random() * 0.6);
			
			startFrequency.set(0.2 + random() * 0.4);
			
			sustainTime.set( 0.1 + random() * 0.1);
			decayTime.set( random() * 0.2);
			hpFilterCutoff.set( 0.1);
		}
		
		/**
		 * Resets the parameters, used at the start of each generate function
		 */
		void SfxrParams::resetParams()
		{
      waveType = WaveType::Square;
      auto params = GetParams();
      for(auto* p: params)
      {
        p->set( p->default_value);
        p->locked = false;
      }
			masterVolume.locked = true;
		}
		
		//--------------------------------------------------------------------------
		//
		//  Randomize Methods
		//
		//--------------------------------------------------------------------------
		
		/**
		 * Randomly adjusts the parameters ever so slightly
		 */
		void SfxrParams::mutate(double mutation)
		{			
      // should waveType be mutated... I dont think so
      auto params = GetParams();
			for (auto* param : params)
			{
				if (!param->locked)
				{
					if (random()<0.5)
					{
						param->set(param->get() + random()*mutation*2 - mutation);
					}
				}
			}
		}
		
		/**
		 * Sets all parameters to random values
		 * If passed null, no fields constrained
		 */
		void SfxrParams::randomize()
		{
			auto params = GetParams();
			for (auto* param : params)
			{
				if (!param->locked)
				{
          const auto min = param->min_value;
          const auto max = param->max_value;
          const auto r = pow(random(), param->random_power);
					param->set(min  + (max-min)*r);
				}
			}
			
			if (!waveType_locked)
			{
        waveType = static_cast<WaveType>(random() * static_cast<int>(WaveType::COUNT));
			}
			
			if (!repeatSpeed.locked)
			{
				if (random()<0.5)
					repeatSpeed.set(0);
			}
						
			if (!slide.locked)
			{
				auto r=random()*2-1;
				r=pow(r,5);
				slide.set(r);
			}
			if (!deltaSlide.locked)
			{
				auto r=random()*2-1;
				r=pow(r,3);
				deltaSlide.set(r);
			}
			
			if (!minFrequency.locked)
				minFrequency.set(0);
			
			if (!startFrequency.locked)
				startFrequency.set(  	(random() < 0.5) ? pow(random()*2-1, 2) : (pow(random() * 0.5, 3) + 0.5));
			
			if ((!sustainTime.locked) && (!decayTime.locked))
			{
				if(attackTime.get() + sustainTime.get() + decayTime.get() < 0.2)
				{
					sustainTime.set( 0.2 + random() * 0.3);
					decayTime.set( 0.2 + random() * 0.3);
				}
			}
			
			if (!slide.locked)
			{
				if((startFrequency.get() > 0.7 && slide.get() > 0.2) || (startFrequency.get() < 0.2 && slide.get() < -0.05)) 
				{
					slide.set( -slide.get());
				}
			}
			
			if (!lpFilterCutoffSweep.locked)
			{
				if(lpFilterCutoff.get() < 0.1 && lpFilterCutoffSweep.get() < -0.05) 
				{
					lpFilterCutoffSweep.set( -lpFilterCutoffSweep.get());
				}
			}
		}
}
