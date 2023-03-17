/**
 * @file Pixel.h
 * @author your name P2003422 P2207683
 * @brief Ceci est le fichier Pixel.h
 * @version 0.1
 * @date 2023-02-20
 * 
 * @copyright Copyright (c) 2023
 */


#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
using namespace std;
//_______________Code


/**
 * @brief La classe Pixel contient trois donnée membres privée qui sont tous de types
 * unsigned char: r, g et b
 * 
 */
class Pixel
{
    private:
        unsigned char r, g, b; //entier entre 0 et 255 inclu
        /*IMPORTANT: même si ce sont des unsigned char, tout les manipulation de leur
        valeur (les modifier/ les reccupérer) seront fait comme des "int"*/
    public:
//_____________________________________________________________________________________
        /**
         * @brief Constructeur d'un nouveau Pixel: r, g et b ont tous 0 comme valeur par
         * défaut
         * 
         */
        Pixel();

//_____________________________________________________________________________________
        /**
         * @brief Constructeur d'un nouveau Pixel: les valeurs des r, g et b seront donnée
         * par l'utilisateur
         * 
         * @param nr : un entier: le futur valeur du donnée menbre privée "r"
         * @param ng : un entier: le futur valeur du donnée menbre privée "g"
         * @param nb : un entier: le futur valeur du donnée menbre privée "b"
         */
        Pixel(unsigned char nr, unsigned char ng, unsigned char nb);

//_____________________________________________________________________________________
        /**
         * @brief il renvoie la valeur du données membre privée "r"
         * 
         * @return const int : un entier : la valeur de "r" retourné ne sera pas
         * modifiable
         */
        const unsigned char getRouge(void) const;

//_____________________________________________________________________________________
        /**
         * @brief il renvoie la valeur du données membre privée "g"
         * 
         * @return const int : un entier : la valeur de "g" retourné ne sera pas
         * modifiable
         */
        const unsigned char getVert(void) const;

//_____________________________________________________________________________________
        /**
         * @brief il renvoie la valeur du données membre privée "b"
         * 
         * @return const int : un entier : la valeur de "b" retourné ne sera pas
         * modifiable
         */
        const unsigned char getBleu(void) const;

//_____________________________________________________________________________________
        /**
         * @brief il modifie la valeur du données membre privée "r" par le paramètre
         * effectif
         * 
         * @param nr : un entier: le nouvelle valeur de la donnée membre privée "r"
         */
        void setRouge(const int nr); //modifie la composante rouge du pixel

//_____________________________________________________________________________________
        /**
         * @brief il modifie la valeur du données membre privée "r" par le paramètre
         * effectif
         * 
         * @param ng : un entier: le nouvelle valeur de la donnée membre privée "g"
         */
        void setVert(const int ng);

//_____________________________________________________________________________________
        /**
         * @brief il modifie la valeur du données membre privée "b" par le paramètre
         * effectif
         * 
         * @param nb : un entier: le nouvelle valeur de la donnée membre privée "b"
         */
        void setBleu(const int nb);
};

#endif