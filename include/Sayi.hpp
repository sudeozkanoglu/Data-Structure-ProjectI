/** 
* @file G201210034 include Sayi.hpp
* @description Sayi.cpp sınıfı için gerekli method, değişken tanımlamaları yapıldı.
* @course 1. Öğretim C grubu
* @assignment 1.Ödev
* @date 27 Ekim 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#ifndef SAYI_HPP
#define SAYI_HPP

#include "Basamak.hpp"

class Sayi
{
    
    public:
        Sayi();
        ~Sayi();
        void insertBasamak(int);
        void changeOdd(int);
        void changeQueue(int);
        Basamak* getHead();
        Basamak* getDugum(int,int);
        int countLength();
        
    private:
        int length;
        Basamak* head;
};

#endif