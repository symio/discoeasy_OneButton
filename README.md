
# discoeasy_OneButton
Modifications pour Marlin_1.1.0RC6 par Dagoma afin d'activer la prise en compte d'un bouton pause/marche sur l'entrée Z-

# Disclaimer :
Je ne suis pas associé ni employé par la société Dagoma.
Ce que je vous propose ici fonctionne sur ma DiscoEasy 200 équipée d'un écran et sur la base du firmware officiel Dagoma en date du 2018/04/04-14h27 choisit sur https://dist.dagoma.fr/ avec pour options : "avec écran" et "sans filamentRunout".
L'objectif et d'activer le mode de changement rapide de filament sur l'action d'un bouton comme Dagoma le propose dans son AddOn numéro2 "extrudeur+" sans l'extrudeur amélioré par Dagoma.
Pour fonctionner vous devez connecter un bouton poussoir sur le port "z-" de la carte MKS base.

Vous utilisez ce hack à vos risques et périls.

# configuration :

Lisez ce [guide](https://github.com/symio/discoeasy_OneButton/blob/master/config.md) pour configurer vos options

# installation :

 - Copiez les fichiers dans le répertoire Marlin ou vous avez extrait les derniers fichiers source fournit par Dagoma (cf https://dist.dagoma.fr/)
Pour installer ce hack vous avez 2 possibilités :
1°) appliquer des patchs
 - Appliquez les patchs de code source fournit sur ce dépôt :
 -- Configuration.h.patch
 -- pins.h.patch
 -- ultralcd.cpp.patch
 
 2°) Modifiez les fichiers de code sources suivants :
- Configuration.h :
 Ligne 41  ajoutez :

```cpp
 #define MODED_EASY_BOARD
```
- Fichier pins.h à la fin du fichier ajoutez :

```cpp
#if defined(MODED_EASY_BOARD) && !defined(MODED_EASY_H)
  #include "moded_easy.h"
#endif
```
- Fichier ultralcd.cpp remplacez la ligne 762 telle que :

```cpp
    //#if ENABLED(SUMMON_PRINT_PAUSE)
    #if ENABLED(SUMMON_PRINT_PAUSE) && ENABLED(FILAMENT_RUNOUT_SENSOR)
```
# Appliquer les fichiers de patchs :
1°) sous Linux :
- Ouvrez un terminal et naviguer jusqu'à vos sources
`$ cd ~/Documents/Marlin/`
- Vérifiez la présence des patchs :
```
$ ll *.patch
 Configuration.h.patch
 pins.h.patch
 ultralcd.cpp.patch
```
- Patchez chaque fichier individuellement :
`$ patch Configuration.h < Configuration.h.patch`
`$ patch pins.h < pins.h.patch`
`$ patch ultralcd.cpp < ultralcd.cpp.patch`

2°) sous Windows :
- Suivez cette documentation : https://docs.moodle.org/dev/How_to_apply_a_patch
- placez votre terminal au répertoire sources fourni par Dagoma (et dans lequel vous avez copié les fichiers de patch et la configuration)
- Patchez chaque fichier individuellement :
`c:\bin\patch.exe Configuration.h < Configuration.h.patch`
`c:\bin\patch.exe pins.h < pins.h.patch`
`c:\bin\patch.exe ultralcd.cpp < ultralcd.cpp.patch`

# Options de configuration :
Dans le fichier moded_easy.h :
- Les lignes 3 et 5 permettent de choisir :
-- ligne 3 Auto nivellage à 9 points avec bonne couverture de la surface du plateau
-- ligne 5 Mod one button
- commentez ou décommentez les lignes qui vous interressent
-- ex: activer le mod : (ligne 5)
`  #define ONE_BUTTON_MOD	 // active ou désactive le mod one button`
-- ex: désactiver le mod : (ligne 5)
`  //#define ONE_BUTTON_MOD	 // active ou désactive le mod one button`

# compiler et flasher l'imprimante

En suivant les tutos disponibles sur internet (https://www.lesimprimantes3d.fr/forum/topic/6228-tuto-flasher-firmware-discoeasy/) compilez et téléverser votre firmaware modifié avec Arduino dans votre imprimante.

# conclusion :
Il ne vous reste qu'à brancher un bouton poussoir sur le endstop Z- comme sur la vidéo de montage de l'extrudeur+ sur le site de Dagoma.

Enjoy et n'hésitez pas à envoyer des pull requests ou ouvrir des tickets si vous avez des soucis.

Photos et vidéo du montage ici : https://www.lesimprimantes3d.fr/forum/topic/14344-mod-bouton-pausechange-fil-pour-discoeasy200/

Le stl de face avant modifiée est là : https://www.tinkercad.com/things/0Ngym5hLYUM-discoeasy200modonebutton

Merci au Dagonautes sur le forum et sur Facebook vous êtes géniaux les mecs (et les filles) (sauf un ou deux dont moi bien sur) ...

