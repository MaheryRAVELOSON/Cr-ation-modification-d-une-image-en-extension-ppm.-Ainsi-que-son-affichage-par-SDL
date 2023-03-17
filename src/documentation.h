/**
 @mainpage Le Module Image

//___________________________________________________________________________
 @section Label_intro Introduction
Le module Image regroupe trois fichier principale (main):
\n  Le mainExemple.cpp: pour créer deux fichier d'image d'éxtension ".ppm" 
dans le repertoire data
\n Le mainTest.cpp: pour réaliser un teste de regression
\n Le dernier dont je n'ai pas encore finit


//___________________________________________________________________________
 @section Label_compiler Pour compiler
Tapez la commande "make" dans le repertoire contenant le fichier Makefie puis ça créera
dans le repertoire "bin" les executable "exemple" et "test" 


//___________________________________________________________________________
 @section Label_executer Pour executer
"./bin/exemple": il va créer dans le répertoire "data" les image "image1.ppm" et "image2.ppm"
\n "./bin/test": il va lancer une teste de regression
\n "./bin/affichage": il va afficher une image à travers une fenêtre SDL


//___________________________________________________________________________
 @section Label_exec_valgrind executer avec Valgrind
"make v_e" pour executer le "exemple" avec valgrind
\n "make v_t" pour executer le "test" avec valgrind
\n "make v_a" pour executer le "affichage" avec valgrind

*/



//ATTENTION : seul le module Terrain est documenté.