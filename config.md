# Loamok ModedEasy200 configuration

Allez hop nouvelle version vous pouvez configurer : 

 - Le nom de votre imprimante 
 - Le nivelage à 9 points de palpage (non proposé par Dagoma) 
 - Le bouton pause sans dépendance de l'extrudeur+ 
 - L'inversion des ports des extrudeurs
 - Les trapézoïdales sans pack expert 
 - Les pid x,y,z et E 
 
 - L’inversion des ports des extrudeurs (non proposé par Dagoma)
## Le nom de l'imprimante :
Dé-commentez la ligne 3 et changez (si vous le voulez) le nom ici je vous propose "ModedEasy200" :

    #define MODED_MACHINE_NAME "ModedEasy200"

## leveling en 9 points
Dé-commentez la ligne 4 pour activer le leveling en 9 points (plus précis que les 5 points de Dagoma) :

    #define MOD_BED_LEVELING_9P

## Le bouton pause sans dépendance de l'extrudeur+
Dé-commentez la ligne 6 pour activer le bouton pause non dépendant du détecteur de filament :

    #define ONE_BUTTON_MOD

## Inversion des ports extrudeurs
Vous pouvez inverser les ports d'extrudeurs (E1 en E0 et vice et versa) en dé-commentant la ligne 7

    #define MODED_INVERT_EXTRUD

## Inversion des ports extrudeurs
Vous pouvez inverser les ports d'extrudeurs (E1 en E0 et vice et versa) en dé-commentant la ligne 7

    #define MODED_INVERT_EXTRUD

## Les trapézoïdales sans pack expert 
Vous pouvez définir votre imprimante comme utilisant des tiges trapézoïdales sans pack expert en dé-commentant la ligne 8 (configurez aussi les pid en dessous à 80, 80, 400, 98 pour les trapez)

    #define MODED_TRAPEZ

## Les pid x,y,z et E 
Vous pouvez définir les pid de votre imprimante en dé-commentant la ligne 9 et en les configurant lignes 13 à 17 

    #define MODED_PRECISION
    #define MODED_PID_X 80 // X Par défaut la valeur dagoma est 80
    #define MODED_PID_Y 80 // Y Par défaut la valeur dagoma est 80
    #define MODED_PID_Z 2560// Z Par défaut la valeur dagoma est 400 
    #define MODED_PID_E 98  // E pour extrudeur
Les valeurs sont :

 - X Dagoma : 80 ; X chez moi : 79.4934
 - Y Dagoma : 80 ; Y chez moi : 79.2864
 - Z Dagoma filetés : 2560 ; Z Dagoma Trapez (pack expert) : 400  ; Y chez moi : 397.2195
 - E Dagoma : 98 ; E chez moi : 100.8023
Reportez vous à cette discussion pour bien régler vos pid :
https://www.lesimprimantes3d.fr/forum/topic/3394-tuto-calcul-des-steps-per-mmunit-une-fois-pour-toutes/

