// DO NOT EDIT!!! GENERATED FILE - 2023-11-27T15:59:20.600275+04:00
#pragma once

/**
 # Звуки
 */
namespace sound {
    
    /**
      ## Звуки Кабины
     */
    namespace cab {

      /**
        ## Группа 1
        ### some group
       */
      enum class gr1 : unsigned short {
      
        /**
          ##### some group
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
          ##### some group
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
          ##### some group
          #### **** Brake switch ****
          ### UNCOMMENTED TRIGGER
          ID: `115`
          Type: `StartLoopRelease`
          File: `chme3_airb_auto3.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`115`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            ||`116`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
          Paired as: `On`
          
         */
        trg_115 = 115,
  
        /**
          ##### some group
          #### **** Brake switch ****
          ### UNCOMMENTED TRIGGER
          ID: `116`
          Type: `ReleaseLoopReleaseWithJump`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`115`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            |ME|`116`|`ReleaseLoopReleaseWithJump`|UNCOMMENTED TRIGGER
          Paired as: `Off`
          
         */
        trg_116 = 116,
  
        /**
          ##### some group
          #### **** Brake switch ****
          ### UNCOMMENTED TRIGGER
          ID: `113`
          Type: `PlayOneShot`
          File: `chme3_abrakef.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`113`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`114`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_113 = 113,
  
        /**
          ##### some group
          #### **** Brake switch ****
          ### UNCOMMENTED TRIGGER
          ID: `114`
          Type: `PlayOneShot`
          File: `chme3_airb_auto1.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`113`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`114`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_114 = 114,
  
        /**
          ##### some group
          #### **** Sand ****
          ### UNCOMMENTED TRIGGER
          ID: `111`
          Type: `StartLoopRelease`
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_sand.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`111`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            ||`112`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
         */
        trg_111 = 111,
  
        /**
          ##### some group
          #### **** Sand ****
          ### UNCOMMENTED TRIGGER
          ID: `112`
          Type: `ReleaseLoopRelease`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`111`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            |ME|`112`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
         */
        trg_112 = 112,
  
        /**
          ##### some group
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
          ##### some group
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
  
        /**
          ##### some group
          #### **** Reverse Throttle Brakes ****
          ### UNCOMMENTED TRIGGER
          ID: `15`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_reverser_forwards_1.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`15`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`16`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`18`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_15 = 15,
  
        /**
          ##### some group
          #### **** Reverse Throttle Brakes ****
          ### UNCOMMENTED TRIGGER
          ID: `16`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_trottle.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`15`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`16`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`18`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_16 = 16,
  
        /**
          ##### some group
          #### **** Reverse Throttle Brakes ****
          ### UNCOMMENTED TRIGGER
          ID: `18`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_locomotive-brake_click.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`15`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`16`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`18`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_18 = 18,
  
        /**
          ##### some group
          #### **** Switches ****
          ### UNCOMMENTED TRIGGER
          ID: `6`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_ventilator_switch_on_1.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`6`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`7`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`37`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`102`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`105`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_6 = 6,
  
        /**
          ##### some group
          #### **** Switches ****
          ### UNCOMMENTED TRIGGER
          ID: `7`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_ventilator_switch_off.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`6`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`7`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`37`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`102`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`105`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_7 = 7,
  
        /**
          ##### some group
          #### **** Switches ****
          ### UNCOMMENTED TRIGGER
          ID: `37`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_switch_on_1.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`6`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`7`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`37`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`102`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`105`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_37 = 37,
  
        /**
          ##### some group
          #### **** Switches ****
          ### UNCOMMENTED TRIGGER
          ID: `102`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_switch_on_1.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`6`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`7`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`37`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`102`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`105`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_102 = 102,
  
        /**
          ##### some group
          #### **** Switches ****
          ### UNCOMMENTED TRIGGER
          ID: `105`
          Type: `PlayOneShot`
          File: `chme3_rb.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`6`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`7`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`37`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`102`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`105`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_105 = 105,
  
        /**
          ##### some group
          #### **** Vigilance alarm ****
          ### UNCOMMENTED TRIGGER
          ID: `109`
          Type: `SetStreamVolume`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`109`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            |ME|`109`|`StartLoopRelease`|comment for 109
            ||`110`|`comment`|comment for 110
            ||`110`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
            ||`117`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            ||`117`|`comment`|comment for 117
         */
        trg_109 = 109,
  
        /**
          ##### some group
          #### **** Vigilance alarm ****
          ### comment for 109
          ID: `109`
          Type: `StartLoopRelease comment`
          File: `epk.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`109`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            |ME|`109`|`StartLoopRelease`|comment for 109
            ||`110`|`comment`|comment for 110
            ||`110`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
            ||`117`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            ||`117`|`comment`|comment for 117
         */
        trg_109 = 109,
  
        /**
          ##### some group
          #### **** Vigilance alarm ****
          ### comment for 110
          ID: `110`
          Type: `comment SetStreamVolume`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`109`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            ||`109`|`StartLoopRelease`|comment for 109
            |ME|`110`|`comment`|comment for 110
            |ME|`110`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
            ||`117`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            ||`117`|`comment`|comment for 117
         */
        trg_110 = 110,
  
        /**
          ##### some group
          #### **** Vigilance alarm ****
          ### UNCOMMENTED TRIGGER
          ID: `110`
          Type: `ReleaseLoopRelease`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`109`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            ||`109`|`StartLoopRelease`|comment for 109
            |ME|`110`|`comment`|comment for 110
            |ME|`110`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
            ||`117`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            ||`117`|`comment`|comment for 117
         */
        trg_110 = 110,
  
        /**
          ##### some group
          #### **** Vigilance alarm ****
          ### UNCOMMENTED TRIGGER
          ID: `117`
          Type: `SetStreamVolume`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`109`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            ||`109`|`StartLoopRelease`|comment for 109
            ||`110`|`comment`|comment for 110
            ||`110`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
            |ME|`117`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            |ME|`117`|`comment`|comment for 117
         */
        trg_117 = 117,
  
        /**
          ##### some group
          #### **** Vigilance alarm ****
          ### comment for 117
          ID: `117`
          Type: `comment PlayOneShot`
          File: `epk_rel.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`109`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            ||`109`|`StartLoopRelease`|comment for 109
            ||`110`|`comment`|comment for 110
            ||`110`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
            |ME|`117`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            |ME|`117`|`comment`|comment for 117
         */
        trg_117 = 117,
  
        /**
          ##### some group
          #### **** Tifon ****
          ### UNCOMMENTED TRIGGER
          ID: `8`
          Type: `StartLoop`
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_tifon_2562.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`8`|`StartLoop`|UNCOMMENTED TRIGGER
            ||`9`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
         */
        trg_8 = 8,
  
        /**
          ##### some group
          #### **** Tifon ****
          ### UNCOMMENTED TRIGGER
          ID: `9`
          Type: `ReleaseLoopRelease`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`8`|`StartLoop`|UNCOMMENTED TRIGGER
            |ME|`9`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
         */
        trg_9 = 9,
  
        /**
          ##### some group
          #### **** Whistle ****
          ### UNCOMMENTED TRIGGER
          ID: `10`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_whistle_2562.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`10`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_10 = 10,
  
        /**
          ##### some group
          #### UNCOMMENTED STREAM
          ### UNCOMMENTED TRIGGER
          ID: `100`
          Type: `EnableTrigger`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`100`|`EnableTrigger`|UNCOMMENTED TRIGGER
            |ME|`100`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            ||`101`|`DisableTrigger`|UNCOMMENTED TRIGGER
            ||`101`|`SetStreamVolume`|UNCOMMENTED TRIGGER
         */
        trg_100 = 100,
  
        /**
          ##### some group
          #### UNCOMMENTED STREAM
          ### UNCOMMENTED TRIGGER
          ID: `100`
          Type: `SetStreamVolume`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`100`|`EnableTrigger`|UNCOMMENTED TRIGGER
            |ME|`100`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            ||`101`|`DisableTrigger`|UNCOMMENTED TRIGGER
            ||`101`|`SetStreamVolume`|UNCOMMENTED TRIGGER
         */
        trg_100 = 100,
  
        /**
          ##### some group
          #### UNCOMMENTED STREAM
          ### UNCOMMENTED TRIGGER
          ID: `101`
          Type: `DisableTrigger`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`100`|`EnableTrigger`|UNCOMMENTED TRIGGER
            ||`100`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            |ME|`101`|`DisableTrigger`|UNCOMMENTED TRIGGER
            |ME|`101`|`SetStreamVolume`|UNCOMMENTED TRIGGER
         */
        trg_101 = 101,
  
        /**
          ##### some group
          #### UNCOMMENTED STREAM
          ### UNCOMMENTED TRIGGER
          ID: `101`
          Type: `SetStreamVolume`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`100`|`EnableTrigger`|UNCOMMENTED TRIGGER
            ||`100`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            |ME|`101`|`DisableTrigger`|UNCOMMENTED TRIGGER
            |ME|`101`|`SetStreamVolume`|UNCOMMENTED TRIGGER
         */
        trg_101 = 101,
  
      };
    }
  
    /**
      ## Звуки Кабины
     */
    namespace cab {

      /**
        ## Группа 2
        ### UNCOMMENTED GROUP
       */
      enum class gr2 : unsigned short {
      
        /**
          ##### UNCOMMENTED GROUP
          #### **** Reverse Throttle Brakes ****
          ### UNCOMMENTED TRIGGER
          ID: `15`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_reverser_forwards_1.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`15`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`16`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`18`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_15 = 15,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Reverse Throttle Brakes ****
          ### UNCOMMENTED TRIGGER
          ID: `16`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_trottle.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`15`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`16`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`18`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_16 = 16,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Reverse Throttle Brakes ****
          ### UNCOMMENTED TRIGGER
          ID: `18`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_locomotive-brake_click.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`15`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`16`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`18`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_18 = 18,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Switches ****
          ### UNCOMMENTED TRIGGER
          ID: `6`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_ventilator_switch_on_1.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`6`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`7`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`37`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_6 = 6,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Switches ****
          ### UNCOMMENTED TRIGGER
          ID: `7`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_ventilator_switch_off.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`6`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`7`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`37`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_7 = 7,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Switches ****
          ### UNCOMMENTED TRIGGER
          ID: `37`
          Type: `PlayOneShot`
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_switch_on_1.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`6`|`PlayOneShot`|UNCOMMENTED TRIGGER
            ||`7`|`PlayOneShot`|UNCOMMENTED TRIGGER
            |ME|`37`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_37 = 37,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Vigelence alarm ****
          ### UNCOMMENTED TRIGGER
          ID: `56`
          Type: `SetStreamVolume`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`56`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            |ME|`56`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            ||`57`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            ||`57`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
         */
        trg_56 = 56,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Vigelence alarm ****
          ### UNCOMMENTED TRIGGER
          ID: `56`
          Type: `StartLoopRelease`
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_epk.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`56`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            |ME|`56`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            ||`57`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            ||`57`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
         */
        trg_56 = 56,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Vigelence alarm ****
          ### UNCOMMENTED TRIGGER
          ID: `57`
          Type: `SetStreamVolume`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`56`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            ||`56`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            |ME|`57`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            |ME|`57`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
         */
        trg_57 = 57,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Vigelence alarm ****
          ### UNCOMMENTED TRIGGER
          ID: `57`
          Type: `ReleaseLoopRelease`
          File: ``
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            ||`56`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            ||`56`|`StartLoopRelease`|UNCOMMENTED TRIGGER
            |ME|`57`|`SetStreamVolume`|UNCOMMENTED TRIGGER
            |ME|`57`|`ReleaseLoopRelease`|UNCOMMENTED TRIGGER
         */
        trg_57 = 57,
  
        /**
          ##### UNCOMMENTED GROUP
          #### **** Tifon ****
          ### UNCOMMENTED TRIGGER
          ID: `8`
          Type: `StartLoopRelease`
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_tifon_2562.wav`
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
          File: `../../tsrLoco_CHME3-Alias/Sound/chme3_whistle_2562.wav`
          Triggers group:
            | is ME? | ID | TYPE | COMMENT |
            | :----: | :---: | :-------: | :-----: |
            |ME|`10`|`PlayOneShot`|UNCOMMENTED TRIGGER
         */
        trg_10 = 10,
  
      };
    }
  
}
  