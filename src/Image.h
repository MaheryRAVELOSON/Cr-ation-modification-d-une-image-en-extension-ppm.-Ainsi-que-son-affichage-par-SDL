/**
 @file Image.h

 @author P2003422 P2207683

 @brief ceci est le fichier Image.h
 \n Il contient 3 données membres privés, 11 fonction membre et 1 fonction ami au total

 @version 0.1

 @date 2023-02-20

 @copyright Copyright (c) 2023
 */


#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"
#include <SDL.h>
#include <iostream>
using namespace std;
//_______________Code


/**
 @brief La classe image contient les dimensions x et y de l'image ainsi que le
 tableau de pixel.
 */
class Image
{
    private:
        int dimx, dimy;
        Pixel * tab;

//_____________________________________________________________________________________
        /**
         * @brief Il permet d'initialiser les bibliothèque de SDL2 qu'on veut utiliser.
         * Il permet aussi de créer la fenêtre SDL.
         * 
         * @param fenetre : un pointeur qui va contenir l'adresse memoire de la fenetre
         * SDL une fois qu'il sera créée dans cette fonction
         * @param Rendu : un pointeur qui va contenir l'adresse memoire du rendu SDL
         * une fois qu'il sera créée dans cette fonction
        */
        void afficherInit(SDL_Window* &fenetre, SDL_Renderer* &Rendu);

//_____________________________________________________________________________________
        /**
         * @brief Il permet de desallouer tout les memoire alloué par SDL.
         * 
         * @param fenetre : un pointeur qui va contenir l'adresse memoire de la fenetre
         * SDL qui a été créée.
         * @param Rendu : un pointeur qui va contenir l'adresse memoire du rendu SDL qui
         * a été créée.
         */
        void afficherDetruit(SDL_Window* &fenetre, SDL_Renderer* &Rendu);

//_____________________________________________________________________________________
        /**
         * @brief Il va appeller en boucle la fonction d'affichage jusqu'à ce que
         * l'utilisateur décide d'arrêter
         * 
         * @param fenetre : un pointeur qui va contenir l'adresse memoire de la fenetre
         * SDL qui a été créée.
         * @param Rendu : un pointeur qui va contenir l'adresse memoire du rendu SDL qui
         * a été créée.
         */
        void afficherBoucle(SDL_Window* &fenetre, SDL_Renderer* &Rendu);



    public:
    //Pixel * tab;

//_____________________________________________________________________________________
        /**
          @brief Un constructeur d'image qui initialise les données membre:
          \n dimx et dimy à 0 ET le pointeut de tableau de pixel "tab" à nullptr
        */
        Image();
        
//_____________________________________________________________________________________
        /**
        * @brief Un constructeur qui initialise les données dimx et dimy par les valeus
        * données par l'utilisateur: dimenxionsX et dimensionY. Il alloue aussi un tableau
        * de pixel dans le tas par le donnée membre "tab" de taille dimensionX*dimensionY
        * 
        * @param dimensionX: le nombre total de la colonne d'une ligne du tableau du pixel 
        * @param dimensionY le nombre total de ligne du tableau du pixel
         */
        Image(const int dimensionX, const int dimensionY); // constructeur + allouage pour le tab

//_____________________________________________________________________________________
        /**
         @brief destructeur d'image: il désalloue chaque case du tableau de pixel pointé
         par le donnée membre "tab". Ensuite il pointe "tab" à nullptr
         */
        ~Image();

//_____________________________________________________________________________________
        /**
         * @brief il reccupère le Pixel d'une case du tableau d'indice x et y et le
         * retourne
         * 
         * @param x : un entier: l'indice de la colonne du tableau
         * @param y : un entier: l'indice de la ligne du tableau
         * @return const Pixel& : il retourne l'adresse memoire du Pixel à l'indice
         * démandé: le Pixel qui sera retourné ne sera pas modifiable grâce au 1er const
         */
        const Pixel& getPix(int x, int y) const;

//_____________________________________________________________________________________
        /**
         * @brief il permet de modifier le Pixel d'une case du tableau en mettant comme
         * nouveau pixel la variable "couleur" donnée
         * 
         * @param x : un entier: l'indice de la colonne du tableau
         * @param y : un entier: l'indice de la ligne du tableau
         * @param couleur : un Pixel: le nouveau pixel qu'on veut mettre à la case d'indice
         * x et y.
         */
        void setPix(int x, int y, const Pixel &couleur);

//_____________________________________________________________________________________        
        /**
         * @brief il change le pixel de quelque case donnée par la variable "couleur" donnée
         * en paramètre
         * 
         * @param Xmin : un entier: l'indice de la colonne de départ du réctangle
         * @param Ymin : un entier: l'indice de la ligne de départ du réctangle
         * @param Xmax : un entier: l'indice de la colonne d'arrivée du réctangle
         * @param Ymax : un entier: l'indice de la ligne d'arrivée du réctangle
         * @param couleur : un Pixel: le couleur dont on veut attribué à toute les cases
         * composant la rectangle 
         */
        void dessinerRectangle(const int Xmin, const int Ymin, int Xmax, const int Ymax, const Pixel couleur);

//_____________________________________________________________________________________
        /**
         * @brief il change le pixel de TOUTE les case du tableau composant l'image par
         * la variable "couleur" donnée en paramètre
         * 
         * @param couleur : un Pixel
         */
        void effacer (const Pixel couleur);

//_____________________________________________________________________________________
        /**
         * @brief cette fonction membre crée une autre variable de type image et d'autres
         * variables de types Pixel. Puis à travers cette nouvelle variable, il appelle la
         * majorité des fonctions qui existe dans la classe Image: la 2ème constructeur,
         * getPix, setPix, dessinerRectangle, effacer
         * 
         */
        void testRegression();

//_____________________________________________________________________________________
        /**
         * @brief il permet d'afficher sur l'écran les trois données membres d'une pixel
         * passée ne paramètre: utilisé que lors du débogage du programme => plus
         * pratique. La fonction est définit dans une main.cpp qui n'est pas dans cette
         * repertoire car non démandé.
         * 
         * @param os 
         * @param Pix : la variable Pixel à affiché sur l'écran. 
         * @return ostream& : il affiche sur l'écran "r, g, b" où r, g et b sont des entier
         */
        friend ostream& operator<<(ostream& os, const Pixel& Pix);

//_____________________________________________________________________________________
        /**
         * @brief il permet de stocker les données de chaque Pixel de toute les cases du
         * tableau pointé par le donnée membre privée "tab" dans un fichier dont le
         * chemin et le nom du fichier est donnée dans en paramètre dans la variable
         * filename
         * 
         * @param filename: le chemin + le nom du fichier: par défaut "./data/image1.ppm"
         */
        void sauver(const string & filename) const;

//_____________________________________________________________________________________
        /**
         * @brief il permet d'ouvrir un fichier passé en paramètre et de copier les données
         * du fichier dans les trois données membres privées de la variable de type Image
         * depuis laquelle cette fonction est appellé
         * 
         * @param filename: le chemin + le nom du fichier dont on veut les donnée:
         * par défaut "./data/image1.ppm" 
         */
        void ouvrir(const string & filename);

//_____________________________________________________________________________________
        /**
         * @brief il afficher sur l'écran les contenue de tout les données membre privée de 
         * la variable Image depuis laquelle on appelle cette fonction.
         * 
         */
        void afficherConsole();

//_____________________________________________________________________________________
        /**
         * @brief il permet d'afficher la variable image depuis laquelle il est appellé
         * dans une fenêtre SDL2.
         * 
         */
        void afficher();
};

#endif