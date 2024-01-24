/** 
* @file G201210034 src Basamak.cpp
* @description Basamak işlemleri için konfigürasyon kısımları yapıldı ve gerekli methodlar entegre edildi.
* @course 1. Öğretim C grubu
* @assignment 1.Ödev
* @date 27 Ekim 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#include "Basamak.hpp"
#include "Sayi.hpp"
#include "Dugum.hpp"
#include <iostream>
using namespace std;

//Basamak kurucu methodu oluşturuldu.
Basamak::Basamak()
{
    data = 0;
    next = NULL;
}

//Basamak kurucu parametreli(sayıların basamaklarını aldığımızda kullanılması için) methodu oluşturuldu. 
Basamak::Basamak(int data)
{
    this->data=data;
    this->next=NULL;
}

//Basamak sınıfının yıkıcı methodu oluşturuldu.
Basamak::~Basamak()
{
    Basamak* temp = next;
    while(temp != nullptr)
    {
        Basamak *sil = temp;
        temp = temp->next;
        delete sil;
    }
}
