/** 
* @file G201210034 include SayilarListesi.hpp
* @description SayilarListesi.cpp sınıfı için gerekli method, değişken tanımlamaları yapıldı.
* @course 1. Öğretim C grubu
* @assignment 1.Ödev
* @date 27 Ekim 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#ifndef SAYILARLISTESI_HPP
#define SAYILARLISTESI_HPP

#include "Dugum.hpp"
#include "Sayi.hpp"

class SayilarListesi
{
    Dugum* head = nullptr;

    public:
        SayilarListesi();
        ~SayilarListesi();
        void insertDugum(Sayi* sayi);
        Dugum* getHead();
        void deleteBiggest(Sayi* sayi);
        void printAll();
        Sayi* calculateBigNum();
        int xC = 0;
        int yC = 0;

    private:
        int length;
};

#endif