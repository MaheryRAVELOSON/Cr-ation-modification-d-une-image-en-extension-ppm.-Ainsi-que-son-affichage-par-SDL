#include "Image.h"
 
int main() {
 
    Pixel rouge (120, 15, 10);
    Pixel vert (20, 202, 15);
    Pixel bleu (4, 58, 218);
 
    Image image1 (64,48);
    image1.effacer(bleu);    // fond bleu
    image1.dessinerRectangle(5, 20, 30, 40, rouge);  // un rectangle rouge sur la moitié gauche
    image1.setPix(51,4,vert);  // une pixel en vert
    image1.setPix(20,30,vert); // Une deuxième pixel en vert
    image1.sauver("./data/image1.ppm");
 
    Image image2;
    image2.ouvrir("./data/image1.ppm"); //copie Img1 dans Img2
    image2.dessinerRectangle(29, 10, 48, 15, rouge); // rajoute un rectangle rouge
    image2.dessinerRectangle(25, 24, 40, 45, vert);  // puis rajoute un rectangle vert
    image2.sauver("./data/image2.ppm");
 
    return 0;
}

