/** 
* @file G201210034 include Dugum.hpp
* @description Dugum.cpp sınıfı için gerekli method, değişken tanımlamaları yapıldı.
* @course 1. Öğretim C grubu
* @assignment 1.Ödev
* @date 27 Ekim 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP

#include "Sayi.hpp"

class Dugum
{

    public:
        Dugum();
        Dugum(Sayi*& sayi);
        ~Dugum();
        Sayi *sayi;
        Dugum *next;
};

#endif