/** 
* @file G201210034 include EkranaYazdir.hpp
* @description Ekrana Yazdırma işlemleri için gerekli method, değişken tanımlamaları yapıldı.
* @course 1. Öğretim C grubu
* @assignment 1.Ödev
* @date 27 Ekim 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#ifndef EKRANAYAZDIR_HPP 
#define EKRANAYAZDIR_HPP
#include <windows.h>

static class EkranaYazdir
{

    public:

        static void ekran(int x, int y)
        {
            COORD c;
            c.X = x;
            c.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
        }

}EkranaYazdir;

#endif



