#include "Pixel.h"
#include <iostream>
using namespace std;

Pixel::Pixel()
{
    r=0;
    g=0;
    b=0;
}

Pixel::Pixel(unsigned char nr, unsigned char ng, unsigned char nb)
{
    r= nr;
    g= ng;
    b= nb;
}

const unsigned char Pixel::getRouge(void) const
{
    return r;
}

const unsigned char Pixel::getVert(void) const
{
    return g;
}

const unsigned char Pixel::getBleu(void) const
{
    return b;
}

void Pixel::setRouge(const int nr)
{
    r= nr;
}

void Pixel::setVert(const int ng)
{
    g= ng;
}

void Pixel::setBleu(const int nb)
{
    b= nb;
}
