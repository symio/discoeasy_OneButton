#ifndef MODED_EASY_H
  #define MODED_EASY_H
  //#define MOD_BED_LEVELING_9P // (décommentez (enlevez les "//" en début de ligne pour 
				 // activer le leveling en 9 points))
  #define ONE_BUTTON_MOD	 // active ou désactive le mod one button
#endif
#ifdef MODED_EASY_BOARD
  // Configuration.h
  #ifdef MOD_BED_LEVELING_9P
  // palpage en 9 points avec meilleure prise en compte de la taille du plateau
    #undef LEFT_PROBE_BED_POSITION
    #define LEFT_PROBE_BED_POSITION 2
    #undef RIGHT_PROBE_BED_POSITION
    #define RIGHT_PROBE_BED_POSITION 200
    #undef FRONT_PROBE_BED_POSITION
    #define FRONT_PROBE_BED_POSITION 25
    #undef BACK_PROBE_BED_POSITION
    #define BACK_PROBE_BED_POSITION 205
    #undef AUTO_BED_LEVELING_GRID_POINTS
    #define AUTO_BED_LEVELING_GRID_POINTS 3
  #endif

  #if defined(ONE_BUTTON_MOD) && !ENABLED(FILAMENT_RUNOUT_SENSOR)
  // one button mod
    #define ONE_BUTTON_INVERTING true
    #define ONE_BUTTON
    #define SUMMON_PRINT_PAUSE_SCRIPT "M600 U5 V195 X195 Y195"
    #define SUMMON_PRINT_PAUSE_INVERTING true
    #define SUMMON_PRINT_PAUSE

  // pins.h
    #undef SUMMON_PRINT_PAUSE_PIN
    #define SUMMON_PRINT_PAUSE_PIN 18
    #undef ONE_BUTTON_PIN
    #define ONE_BUTTON_PIN SUMMON_PRINT_PAUSE_PIN
  #endif
#endif
