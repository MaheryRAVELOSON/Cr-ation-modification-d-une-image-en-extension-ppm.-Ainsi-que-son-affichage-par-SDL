#include "Image.h"
#include <stdlib.h>     /* abs */
#include <iostream>
#include <cassert>
#include <fstream>


using namespace std;

Image::Image()
{
    dimx= 0;
    dimy= 0;
    tab = nullptr;
}


Image::Image(const int dimensionX, const int dimensionY)
{
    dimx= abs(dimensionX);
    dimy= abs(dimensionY);
    assert(dimx>0);
    assert(dimy>0);
    tab = new Pixel[dimx*dimy];
}


Image::~Image()
{
    if (tab!=nullptr) delete [] tab;
    tab = nullptr;
    dimx=0;
    dimy=0;
}

const Pixel& Image::getPix(int x, int y) const
{
    assert(x>=0);
    assert(y>=0);
    assert(x<dimx);
    assert(y<dimy);
    return tab[y*dimx+x];
    /* quand on appelle cette fonction dans une variable, le & permet de ne pas COPIER
    l'objet retourné par la fonction mais de passer/associer à la variable l'adresse
    memoire de l'objet retourné. declaration de la variable: Pixel Var= getPix(1,2);
    sans le & apres le Pixel*/
}


void Image::setPix(int x, int y, const Pixel &couleur) 
{
    tab[y*dimx+x].setRouge(couleur.getRouge());
    tab[y*dimx+x].setVert(couleur.getVert());
    tab[y*dimx+x].setBleu(couleur.getBleu());
    /*On ne peut manipuler/modifier/récupérer un donnée membre privée depuis l'exterieur
    de la défintion d'une classe que par les fonction de sa classe
    Ex: tab[y*dimx+x].r= couleur.r;  => erreur car rbg sont privée d'une autre classe*/

}

void Image::dessinerRectangle(const int Xmin, const int Ymin, const int Xmax, const int Ymax, Pixel couleur)
{
    int i;
    for (int Y=Ymin; Y<=Ymax; Y++)
    {
        for (int X=Xmin; X<=Xmax; X++)
        {
            assert(X<dimx);
            assert(Y<dimy);

            i= Y*dimx+X;
            if (i<(dimx*dimy))
            {
                tab[i].setRouge(couleur.getRouge());
                tab[i].setVert(couleur.getVert());
                tab[i].setBleu(couleur.getBleu());
            }
        }
    }

}


void Image::effacer (const Pixel couleur)
{
    Image::dessinerRectangle(0, 0, dimx-1, dimy-1, couleur);
}


void Image::sauver(const string & filename) const {
    ofstream fichier (filename.c_str()); //c_str permet de transformer une chaine de 
    assert(fichier.is_open());           // caractère en une chaine de caractère CONSTANTE
    fichier << "P3" << endl;             // car le "ofstream" (et le ifstream) ne prennent
    fichier << dimx << " " << dimy << endl;   // que des chaine CONSTANTE
    fichier << "255" << endl;
    for(int y=0; y<dimy; ++y)
    {
        for(int x=0; x<dimx; ++x) 
        {
            Pixel pix = getPix(x,y);
            fichier << int (pix.getRouge()) << " " << int(pix.getVert()) << " " << int(pix.getBleu()) << " ";
            //cout << pix.getRouge() << " " << pix.getVert() << " " << pix.getBleu() << " "<<endl;
        }
    }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const string & filename) {
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
	int r,g,b;
	string mot;
	dimx = dimy = 0;
    Pixel Pix;
	fichier >> mot >> dimx >> dimy >> mot;
	assert(dimx > 0 && dimy > 0);
	if (tab != NULL) delete [] tab;
	tab = new Pixel [dimx*dimy];
    for(int y=0; y<dimy; y++)
        for(int x=0; x<dimx; x++) {
            fichier >> r >> g >> b;
            Pix.setRouge(r);
            Pix.setVert(g);
            Pix.setBleu(b);
            setPix(x, y, Pix);
            //cout << r << " " << g << " " << b << " "<<endl;
        }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficherConsole(){
    cout << dimx << " " << dimy << endl;
    for(int y=0; y<dimy; ++y) {
        for(int x=0; x<dimx; ++x) {
            Pixel pix = getPix(x,y);
            cout << int(pix.getRouge()) << " " << int(pix.getVert()) << " " << int(pix.getBleu()) << " ";
        }
        cout << endl;
    }
}

void Image::testRegression()
{
    /*Meme si ça nous parrait etrange de créer un varable image (et tout ce qui va avec)
     l'intérieur d'un autre variable image, pour l'ordinateur c'est juste une instruction
     en plus qui demande une allocation de memoire pour une variable comme les autres*/
    
    Image test;
    
    int tailleX= 100;
    int tailleY= 100;

    Image Img2(tailleX, tailleY);
    assert( Img2.dimx==tailleX);
    assert( Img2.dimy==tailleY);
    assert( Img2.tab!=nullptr);

    
    Pixel Rouge(255, 0, 0);
    Img2.setPix(tailleX-1, tailleY-1, Rouge);
    Rouge= Img2.getPix(tailleX-1, tailleY-1);
    Rouge.setRouge(2);
    assert( Rouge.getRouge() == 2); 
    
    Pixel PIXEL(0, 255, 0);
    Img2.dessinerRectangle(0, 0, 99, 99, PIXEL);
    Pixel VarPixel= Img2.getPix(5, 50);
    assert(VarPixel.getBleu()==PIXEL.getBleu());
    assert(VarPixel.getVert()==PIXEL.getVert());
    assert(VarPixel.getRouge()==PIXEL.getRouge());


    Img2.effacer (Rouge);
    VarPixel= Img2.getPix(7, 43);
    assert(VarPixel.getBleu()==Rouge.getBleu());
    assert(VarPixel.getVert()==Rouge.getVert());
    assert(VarPixel.getRouge()==Rouge.getRouge());

    //Img2.afficherConsole();
    cout<<endl<<"-- Test de regression terminée --"<<endl<<endl; //affiché si toute
                                                    // les assert précédent sont verifié
}


//_________________________________SDL_____________________________

void Image::afficherInit(SDL_Window* &fenetre, SDL_Renderer* &Rendu)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)  //SDL_INIT_EVERYTHING aussi
    {
        cout<<endl<<"Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    fenetre = nullptr;
    fenetre = SDL_CreateWindow("Module Image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 200, 200, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (fenetre == nullptr) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

    Rendu = nullptr;
    Rendu= SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);


}


void Image::afficherDetruit(SDL_Window* &fenetre, SDL_Renderer* &Rendu)
{
    SDL_DestroyRenderer(Rendu);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}


void Image::afficherBoucle(SDL_Window* &fenetre, SDL_Renderer* &Rendu)
{
    float Zoom= 1.0;
    SDL_Event evenement;
    bool isOpen= true;
    while (isOpen)
    {
        while (SDL_PollEvent(&evenement))
        {
            switch (evenement.type)
            {
                case SDL_QUIT:
                    isOpen = false;
                    break;
                case SDL_KEYDOWN:
                    if (evenement.key.keysym.sym == SDLK_ESCAPE)
                    {
                        isOpen = false;
                        break;
                    }
                    if (evenement.key.keysym.sym == SDLK_t)
                    {
                        Zoom += 0.1; //zoomer
                    }
                    if (evenement.key.keysym.sym == SDLK_g)
                    {
                        Zoom -= 0.1; //dézoomer
                    }
                default:
                    isOpen = true;
            }

//________________________________Parti de mis à jour___________________________________
//----------nettoyage de la fenêtre
            SDL_RenderClear(Rendu);  // nettoyage de la fenêtre avec la couleur du Render
            SDL_SetRenderDrawColor(Rendu, 0, 255, 0, 255); //Remplir l'écran de vert: le fond
            


//----------Mis à jour

            for (int Y=0; Y<dimy; Y++)
            {
                for (int X=0; X<dimx; X++)
                {
                    int i= Y*dimx+X;
                    SDL_Rect VarRect;  //declaration d'un coordonnée en type point
                    VarRect.h= 1*Zoom;
                    VarRect.w= 1*Zoom;
                    VarRect.x = X + (VarRect.h*X);
                    VarRect.y = Y + (VarRect.w*Y);
                    SDL_SetRenderDrawColor(Rendu, int(tab[i].getRouge()),
                    int(tab[i].getVert()), int(tab[i].getBleu()), 255);  // définition de la couleur du pt

                    SDL_RenderFillRect(Rendu, &VarRect);
                }
            }


//----------Affichage de la mis à jour
            SDL_RenderPresent(Rendu);  // MAJ de la fenêtre avec le nouveau dessiner
//____________________________fin de la Parti de mis à jour_______________________________
        }
    }
}

void Image::afficher()
{
    SDL_Window* fenetre = nullptr;
    SDL_Renderer* Rendu = nullptr;
    afficherInit(fenetre, Rendu);
    afficherBoucle(fenetre, Rendu);
    afficherDetruit(fenetre, Rendu);
}
