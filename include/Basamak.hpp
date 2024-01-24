/** 
* @file G201210034 include Basamak.hpp
* @description Basamak.cpp sınıfı için gerekli method, değişken tanımlamaları yapıldı.
* @course 1. Öğretim C grubu
* @assignment 1.Ödev
* @date 27 Ekim 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#ifndef BASAMAK_HPP
#define BASAMAK_HPP


class Basamak
{

    public:
        Basamak();
        Basamak(int);
        ~Basamak();
        int data;
        Basamak *next;
};

#endif