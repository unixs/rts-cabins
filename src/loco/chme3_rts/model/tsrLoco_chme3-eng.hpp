// DO NOT EDIT!!! GENERATED FILE - 2023-11-27T15:59:20.562671+04:00
#pragma once

/**
 # Звуки
 */
namespace sound {
    
    /**
      ## Звуки Внешние
     */
    namespace ext {

      /**
        ## Группа 1
        ### UNCOMMENTED GROUP
       */
      enum class gr1 : unsigned short {
      
        /**
          ##### UNCOMMENTED GROUP
          #### **** Engine Starter ****
          ### UNCOMMENTED TRIGGER
          ID: `103`
          Type: `StartLoopRelease`
          File: `start1.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`103`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            ||`104`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
         */
        trg_103 = 103,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Engine Starter ****
          ### UNCOMMENTED TRIGGER
          ID: `104`
          Type: `ReleaseLoopRelease`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`103`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            |ME|`104`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
         */
        trg_104 = 104,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Ventilator ****
          ### UNCOMMENTED TRIGGER
          ID: `6`
          Type: `StartLoopRelease`
          File: `../../tsrLoco_CHME3-Alias/Sound/x_chme3_ventilator_2501.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`6`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            ||`7`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
         */
        trg_6 = 6,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Ventilator ****
          ### UNCOMMENTED TRIGGER
          ID: `7`
          Type: `ReleaseLoopReleaseWithJump`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`6`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            |ME|`7`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
         */
        trg_7 = 7,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Tifon ****
          ### UNCOMMENTED TRIGGER
          ID: `8`
          Type: `StartLoopRelease`
          File: `../../tsrLoco_CHME3-Alias/Sound/x_chme3_tifon_2562.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`8`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            ||`9`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
         */
        trg_8 = 8,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Tifon ****
          ### UNCOMMENTED TRIGGER
          ID: `9`
          Type: `ReleaseLoopReleaseWithJump`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`8`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            |ME|`9`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
         */
        trg_9 = 9,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Whistle ****
          ### UNCOMMENTED TRIGGER
          ID: `10`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/x_chme3_whistle_2562.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`10`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_10 = 10,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Coupling & Sand ****
          ### UNCOMMENTED TRIGGER
          ID: `58`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/x_chme3_couple.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`58`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`61`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`61`|`EnableTrigger`|UNCOMMENTED TRIGGER
            ||`111`|`StartLoop`|UNCOMMENTED TRIGGER
            ||`112`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
         */
        trg_58 = 58,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Coupling & Sand ****
          ### UNCOMMENTED TRIGGER
          ID: `61`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/x_chme3_uncouple.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`58`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`61`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`61`|`EnableTrigger`|UNCOMMENTED TRIGGER
            ||`111`|`StartLoop`|UNCOMMENTED TRIGGER
            ||`112`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
         */
        trg_61 = 61,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Coupling & Sand ****
          ### UNCOMMENTED TRIGGER
          ID: `61`
          Type: `EnableTrigger`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`58`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`61`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`61`|`EnableTrigger`|UNCOMMENTED TRIGGER
            ||`111`|`StartLoop`|UNCOMMENTED TRIGGER
            ||`112`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
         */
        trg_61 = 61,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Coupling & Sand ****
          ### UNCOMMENTED TRIGGER
          ID: `111`
          Type: `StartLoop`
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_sand.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`58`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`61`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`61`|`EnableTrigger`|UNCOMMENTED TRIGGER
            |ME|`111`|`StartLoop`|UNCOMMENTED TRIGGER
            ||`112`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
         */
        trg_111 = 111,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Coupling & Sand ****
          ### UNCOMMENTED TRIGGER
          ID: `112`
          Type: `ReleaseLoopRelease`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`58`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`61`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`61`|`EnableTrigger`|UNCOMMENTED TRIGGER
            ||`111`|`StartLoop`|UNCOMMENTED TRIGGER
            |ME|`112`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
         */
        trg_112 = 112,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Brakes ****
          ### UNCOMMENTED TRIGGER
          ID: `80`
          Type: `StartLoopRelease`
          File: `../../tsrLoco_VL80-Alias/Sound_3/flow.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`80`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            ||`81`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
            ||`14`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`54`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
            ||`53`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`54`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_80 = 80,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Brakes ****
          ### UNCOMMENTED TRIGGER
          ID: `81`
          Type: `ReleaseLoopReleaseWithJump`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`80`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            |ME|`81`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
            ||`14`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`54`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
            ||`53`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`54`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_81 = 81,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Brakes ****
          ### UNCOMMENTED TRIGGER
          ID: `14`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/*.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`80`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            ||`81`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
            |ME|`14`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`54`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
            ||`53`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`54`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_14 = 14,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Brakes ****
          ### UNCOMMENTED TRIGGER
          ID: `54`
          Type: `ReleaseLoopReleaseWithJump`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`80`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            ||`81`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
            ||`14`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`54`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
            ||`53`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`54`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_54 = 54,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Brakes ****
          ### UNCOMMENTED TRIGGER
          ID: `53`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/*.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`80`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            ||`81`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
            ||`14`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`54`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
            |ME|`53`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`54`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_53 = 53,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Brakes ****
          ### UNCOMMENTED TRIGGER
          ID: `54`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/*.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`80`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            ||`81`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
            ||`14`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`54`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
            ||`53`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`54`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_54 = 54,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Compressor ****
          ### UNCOMMENTED TRIGGER
          ID: `107`
          Type: `StartLoopRelease`
          File: `comp.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`107`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            ||`108`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
          Paired as: `On`
          
         */
        trg_107 = 107,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Compressor ****
          ### UNCOMMENTED TRIGGER
          ID: `108`
          Type: `ReleaseLoopReleaseWithJump`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`107`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            |ME|`108`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
          Paired as: `Off`
          
         */
        trg_108 = 108,
  
      };
    }
  
    /**
      ## Звуки Внешние
     */
    namespace ext {

      /**
        ## Группа 2
        ### UNCOMMENTED GROUP
       */
      enum class gr2 : unsigned short {
      
        /**
          ##### UNCOMMENTED GROUP
          #### **** Ventilator ****
          ### UNCOMMENTED TRIGGER
          ID: `6`
          Type: `StartLoopRelease`
          File: `../../tsrLoco_CHME3-Alias/Sound/x_chme3_ventilator_2501.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`6`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            ||`7`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
         */
        trg_6 = 6,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Ventilator ****
          ### UNCOMMENTED TRIGGER
          ID: `7`
          Type: `ReleaseLoopReleaseWithJump`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`6`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            |ME|`7`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
         */
        trg_7 = 7,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Tifon ****
          ### UNCOMMENTED TRIGGER
          ID: `8`
          Type: `StartLoopRelease`
          File: `../../tsrLoco_CHME3-Alias/Sound/x_chme3_tifon_2562.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`8`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            ||`9`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
         */
        trg_8 = 8,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Tifon ****
          ### UNCOMMENTED TRIGGER
          ID: `9`
          Type: `ReleaseLoopReleaseWithJump`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`8`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            |ME|`9`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
         */
        trg_9 = 9,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Whistle ****
          ### UNCOMMENTED TRIGGER
          ID: `10`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/x_chme3_whistle_2562.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`10`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_10 = 10,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Coupling ****
          ### UNCOMMENTED TRIGGER
          ID: `58`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/x_chme3_couple.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`58`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`61`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`61`|`EnableTrigger`|UNCOMMENTED TRIGGER
         */
        trg_58 = 58,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Coupling ****
          ### UNCOMMENTED TRIGGER
          ID: `61`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/x_chme3_uncouple.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`58`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`61`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`61`|`EnableTrigger`|UNCOMMENTED TRIGGER
         */
        trg_61 = 61,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Coupling ****
          ### UNCOMMENTED TRIGGER
          ID: `61`
          Type: `EnableTrigger`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`58`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`61`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`61`|`EnableTrigger`|UNCOMMENTED TRIGGER
         */
        trg_61 = 61,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Brakes ****
          ### UNCOMMENTED TRIGGER
          ID: `14`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/*.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`14`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`54`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
            ||`53`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`54`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_14 = 14,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Brakes ****
          ### UNCOMMENTED TRIGGER
          ID: `54`
          Type: `ReleaseLoopReleaseWithJump`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`14`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`54`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
            ||`53`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`54`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_54 = 54,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Brakes ****
          ### UNCOMMENTED TRIGGER
          ID: `53`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/*.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`14`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`54`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
            |ME|`53`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`54`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_53 = 53,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Brakes ****
          ### UNCOMMENTED TRIGGER
          ID: `54`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/*.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`14`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`54`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
            ||`53`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`54`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_54 = 54,
  
      };
    }
  
}
  