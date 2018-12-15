#ifndef MODED_EASY_H
  #define MODED_EASY_H
    #define MODED_MACHINE_NAME ModedEasy200 // Décommentez pour changer le nom de la machine
//  #define MOD_BED_LEVELING_9P // décommentez (enlevez les "//" en début de ligne) pour 
				 // activer le leveling en 9 points
  #define ONE_BUTTON_MOD	 // active ou désactive le mod one button
//  #define MODED_INVERT_EXTRUD // invertion extrudeur 0 en extrudeur 1
//  #define MODED_TRAPEZ        // Z en trapézoïdales sans pack expert
//  #define MODED_PRECISION     // Définition de la précision des prints 
                                // (très utile pour personaliser les pid)
//  Et définissez vos pid ci-dessous voir :
//  https://www.lesimprimantes3d.fr/forum/topic/3394-tuto-calcul-des-steps-per-mmunit-une-fois-pour-toutes/
    #define MODED_PID_X 80      // X Par défaut la valeur dagoma est 80
    #define MODED_PID_Y 80      // Y Par défaut la valeur dagoma est 80
    #define MODED_PID_Z 2560    // Z Par défaut la valeur dagoma est 400 
                                // en trapez pack expert et 2560 en filetés standard 
    #define MODED_PID_E 98      // E (extru) Par défaut la valeur dagoma est 98
#endif
/*-----------------------------------------------------------------------------*/
// Fin de config ne touchez à rien ci-dessous configurez ce que vous voulez au dessus de cette ligne
/*-----------------------------------------------------------------------------*/
#ifdef MODED_EASY_BOARD
  // Configuration.h
  #ifdef MODED_MACHINE_NAME
    #undef CUSTOM_MACHINE_NAME
    #define CUSTOM_MACHINE_NAME MODED_MACHINE_NAME
  #endif
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

  #if defined(ONE_BUTTON_MOD) && !ENABLED(FILAMENT_RUNOUT_SENSOR) && !defined(ONE_BUTTON)
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
  #ifdef MODED_INVERT_EXTRUD
  // invertion du port extrudeur (si vous n'avez pas modifié le branchement de votre 
  // extrudeur commentez la ligne 4)
  // pins_RAMPS_14.h
    #undef E1_STEP_PIN
    #define E1_STEP_PIN        26
    #undef E1_DIR_PIN
    #define E1_DIR_PIN         28
    #undef E1_ENABLE_PIN
    #define E1_ENABLE_PIN      24

    #undef E0_STEP_PIN
    #define E0_STEP_PIN        36
    #undef E0_DIR_PIN
    #define E0_DIR_PIN         34
    #undef E0_ENABLE_PIN
    #define E0_ENABLE_PIN      30
  #endif
  #ifdef MODED_TRAPEZ
    #undef DEFAULT_AXIS_STEPS_PER_UNIT
    #ifdef MODED_PRECISION
      #define DEFAULT_AXIS_STEPS_PER_UNIT {MODED_PID_X,MODED_PID_Y,MODED_PID_Z,MODED_PID_E}
    #else
      #define DEFAULT_AXIS_STEPS_PER_UNIT {MODED_PID_X,MODED_PID_Y,MODED_PID_Z,MODED_PID_E}
    #endif
  #else
    #ifdef MODED_PRECISION
      #undef DEFAULT_AXIS_STEPS_PER_UNIT
      #define DEFAULT_AXIS_STEPS_PER_UNIT {MODED_PID_X,MODED_PID_Y,MODED_PID_Z,MODED_PID_E}
    #endif
  #endif
#endif