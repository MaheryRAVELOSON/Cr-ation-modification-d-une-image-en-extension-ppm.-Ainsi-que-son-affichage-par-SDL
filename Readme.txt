===========================noms/prénoms/numéros des étudiants==========================
- Yamani Abdeslam P2207683
- RAVELOSON Maherinirina P2003422

====================================comment compiler===================================
"make" => il va créer les executable "exemple", et "test". Il va aussi créer objet 
"Image.o", "mainExemple.o", "mainTest.o" et "Pixel.o"

====================================comment executer===================================
Depuis le repertoire contenant le Makefile:
- "./bin/exemple" pour l'executable "exemple
- "./bin/test" pour l'executable "test"
- "./bin/affichage" pour l'executable "affichage"
- Pour les executer avec valgrind:
    - "make v_e" pour l'executable "exemple"
    - "make v_t" pour l'executable "test"
    - "make v_a" pour l'executable "affichage"

==================================Ce que fait le module================================
- le module image permet de crée un variable de type image.
- une variable image est un tableau 2D où chaque case contient un Pixel.
- Chaque Pixel est composé de trois couleurs rouge, vert et bleu
- Cette module peut enregistrer les contenus de chaque variable image dans un fichier
  d'extension ".ppm"
- il peut aussi lire le donnée d'un fichier ".ppm" et le copier dans une variable image.
- il peut également afficher une variable Image sur dans une fenêtre SDL.

============================ce que fait chacun des executables=========================
- l'executable "exemple" crée deux images dans un répertoire
- lexecutable "test" fait une teste de regression de la classe image à travers une
  variable de type image.
- l'executable "affichage" va affiché une variable image dans une fenêtre SDL
===============================l'organisation de l'archive=============================
- dossier src: il contient tout les fichier .cpp et .h
- dossier data: il contient tout les images sauvés et lue
- dossier doc/: 
	- il contient le fichier de configuration de doxygen: NomModule.doxy.
	- il contient aussi le repertoire html/ qui contiendra la page index.html générée avec
	  doxygen
- dossier obj: il contient le objet: les .o
