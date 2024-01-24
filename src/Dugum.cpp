/** 
* @file G201210034 src Dugum.cpp
* @description Düğüm işlemleri için konfigürasyon kısımları yaratıldı.
* @course 1. Öğretim C grubu
* @assignment 1.Ödev
* @date 27 Ekim 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"
#include "SayilarListesi.hpp"
#include <iostream>
using namespace std;

//Dugum sınıfı kurucu methodu.
Dugum::Dugum()
{
    next = NULL;
}

//Dugum kurucu parametreli(Sayi'ların referanslarını aldığımızda kullanılması için) methodu oluşturuldu.
Dugum::Dugum(Sayi*& sayi)
{
    this->sayi = sayi;
    this->next = NULL;
}

//Dugum sınıfı için yıkıcı methodu.
Dugum::~Dugum()
{
    Dugum *temp = next;
    while(temp != nullptr)
    {
        Dugum *sil = temp;
        temp = temp->next;
        delete sil;
    }
}



