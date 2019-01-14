#ifndef BFXR_LANG_EN_H
#define BFXR_LANG_EN_H

// this file contains all the language strings for bfxr

// ------------------------------------------------------------
// Buttons
// ------------------------------------------------------------

#define TEXT_BTN_PICKUP_COIN "Pickup/Coin"
#define TEXT_BTN_PICKUP_COIN_DESCRIPTION "Blips and baleeps.  Try messing with the wave-forms to get your own sound."

#define TEXT_BTN_LASER_SHOOT "Laser/Shoot"
#define TEXT_BTN_LASER_SHOOT_DESCRIPTION "Pew pew.  Try playing about with the Frequency properties (slide + delta slide especially).  If you want to add some texture, try adding some light, high-frequency vibrato."

#define TEXT_BTN_EXPLOSION "Explosion"
#define TEXT_BTN_EXPLOSION_DESCRIPTION "Boom.  To make this louder, try increasing compression, or fiddling with the frequency parameters.  To make this softer, try switching to pink noise or decreasing the frequency.  If you're hearing nothing after messing with parameters, try fiddling with 'frequency cutoff'."

#define TEXT_BTN_POWERUP "Powerup"
#define TEXT_BTN_POWERUP_DESCRIPTION "Whoo.  Try messing with the slide + delta slide parameters to make these less unreservedly exhuberant.  Or how about increasing the decay and playing with the Pitch Jump/Onset parameters?"

#define TEXT_BTN_HIT_HURT "Hit/Hurt"
#define TEXT_BTN_HIT_HURT_DESCRIPTION "If you want something more crackly, try out a tan wave here."

#define TEXT_BTN_JUMP "Jump"
#define TEXT_BTN_JUMP_DESCRIPTION "Try turn your jump into a soggy kiss with some bitcrush.  "

#define TEXT_BTN_BLIP_SELECT "Blip/Select"
#define TEXT_BTN_BLIP_SELECT_DESCRIPTION "You might want to make a variation of this with longer decay for blips that accompany fadeouts or animations."

#define TEXT_BTN_RANDOMIZE "Randomize"
#define TEXT_BTN_RANDOMIZE_DESCRIPTION "Taking your life into your hands... . (Only modifies unlocked parameters)"

#define TEXT_BTN_MUTATE "Mutation"
#define TEXT_BTN_MUTATE_DESCRIPTION "Modify each unlocked parameter by a small wee amount."

// ------------------------------------------------------------
// Waveforms
// ------------------------------------------------------------

#define TEXT_WT_TRIANGLE "Triangle"
#define TEXT_WT_TRIANGLE_DESCRIPTION "Triangle waves are robust at all frequencies, stand out quite well in most situations, and have a clear, resonant quality."

#define TEXT_WT_SIN "Sin"
#define TEXT_WT_SIN_DESCRIPTION "Sin waves are the most elementary of all wave-types.  However, they can be sensitive to context (background noise or accoustics can drown them out sometimes), so be careful."

#define TEXT_WT_SQUARE "Square"
#define TEXT_WT_SQUARE_DESCRIPTION "Square waves can be quite powerful.  They have two extra properties, Square Duty and Duty Sweep, that can further control the timbre of the wave"

#define TEXT_WT_SAW "Saw"
#define TEXT_WT_SAW_DESCRIPTION "Saw waves are raspy mother-fuckers."

#define TEXT_WT_BREAKER "Breaker"
#define TEXT_WT_BREAKER_DESCRIPTION "These are defined by a quadratic equation (a=t*t%1, giving a toothed-shaped), making them a little more hi-fi than other wave-types on this list.  For the most part, like a smoother, slicker triangle wave."											

#define TEXT_WT_TAN "Tan"
#define TEXT_WT_TAN_DESCRIPTION "A potentially crazy wave.  Does strange things.  Tends to produce plenty of distortion	 (because the basic shape goes outside of the standard waveform range)."											

#define TEXT_WT_WHISTLE "Whistle"
#define TEXT_WT_WHISTLE_DESCRIPTION "A sin wave with an additional sine wave overlayed at a lower amplitude and 20x the frequency.  It can end up sounding buzzy, hollow, resonant, or breathy."											

#define TEXT_WT_WHITE "White"
#define TEXT_WT_WHITE_DESCRIPTION "White noise is your bog standard random number stream.  Quite hard-sounding, compared to pink noise."										

#define TEXT_WT_PINK "Pink"
#define TEXT_WT_PINK_DESCRIPTION "Pink noise is a stream of random numbers with a filtered frequency spectrum to make it softer than white noise."											

#define TEXT_WT_ONEBIT "1b Noise"
#define TEXT_WT_ONEBIT_DESCRIPTION "Periodic 1-bit \"white\" noise. Useful for glitchy and punky sound effects."

#define TEXT_WT_BUZZ "Buzz"
#define TEXT_WT_BUZZ_DESCRIPTION "Periodic 1-bit noise with a shortened period. It makes a nice digital buzz or clang sound."

// ------------------------------------------------------------
// Sound parameters
// ------------------------------------------------------------



#endif  // BFXR_LANG_EN_H
