/** 
* @file G201210034 src SayilarListesi.cpp
* @description Sayilar Listesi işlemlerinin yapılabilmesi için yaratıldı.
* @course 1. Öğretim C grubu
* @assignment 1.Ödev
* @date 27 Ekim 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#include "SayilarListesi.hpp"
#include "Sayi.hpp"
#include "EkranaYazdir.hpp"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

//SayilarListesi sınıfı kurucu methodu.
SayilarListesi::SayilarListesi()
{
    head == nullptr;
}

//SayilarListesi adlı bağlı liste sınıfımıza Dugum sınıfı yardımıyla düğümlerimizi eklemek için kullanılan method.
void SayilarListesi::insertDugum(Sayi* sayi)
{
    //Dugum ekleyebilmek icin yeni bir dugum olusturma
    Dugum *dugum = new Dugum(sayi);

    if(head == nullptr)
    {
        head = dugum;
        return;
    }
    // Head degerini kaybetmemek için last'a atadık.
    Dugum *last = head;
    
    //Dugumun sonuna gitmek için for döngüsü
    while (last->next != nullptr)
    {
        last = last->next;
    }

    //Dugumun sonuna yeni dugumu ekleme işlemi burada yapılıyor.
    last->next = dugum;
}

//Bağlı listemizin head referansının döndürüldüğü method.
Dugum* SayilarListesi::getHead()
{
    return head;
}

//Bağlı liste içerisindeki en büyük sayıyı bulmamıza yarayan method.
Sayi* SayilarListesi::calculateBigNum()
{
    int data = 0;
    int bigNum = 0;
    Dugum *gecici = getHead();
    Sayi *bigSayi = nullptr;
    Basamak *sayiData = gecici->sayi->getHead();
    string str = {};
    while(gecici != nullptr)
    {
        string str = {};
        sayiData = gecici->sayi->getHead();
        while(sayiData != nullptr)
        {
            str = str + to_string(sayiData->data);
            sayiData = sayiData->next;
        }
        if(!str.empty())
        {
            data = stol(str, nullptr);
        }
        if(bigNum == 0)
        {
            bigNum = data;
            bigSayi = gecici->sayi;
        }
        else
        {
            if(data > bigNum)
            {
                bigNum = data;
                bigSayi = gecici->sayi;
            }
        }
        gecici = gecici->next;
    }
    return bigSayi;
}

//Bağlı listemizdeki en büyük sayıyı silmemizi sağlayan method.
void SayilarListesi::deleteBiggest(Sayi* sayi)
{
    if(head == nullptr)
    {
        return;
    }
    
    Dugum *temp = head;
    Dugum *siradaki = head->next;
    
    if(siradaki == nullptr)
    {
        head = nullptr;
    }

    while(siradaki != nullptr)
    {
        if(head->sayi == sayi)
        {
            head = head->next; 
            
        }
        else if(siradaki->sayi == sayi)
        {
            if(siradaki->next != nullptr)
            {
                siradaki = siradaki->next;
                temp->next = siradaki;
            }
            else
            {
                temp->next = nullptr;
            }
        }
        if(head->next == nullptr && head->sayi == sayi)
        {
            head = nullptr;
            
        }
        siradaki = siradaki->next;
        temp = temp->next;
    }
}

//Ekrana Yazdırma Methodu
void SayilarListesi::printAll()
{
    Dugum *gecici = getHead();
    while(gecici != nullptr)
    {
        Basamak* adress = gecici->sayi->getHead();
        Basamak* sayiData = gecici->sayi->getHead();
        int b = 0;
        EkranaYazdir.ekran(xC,yC);
        cout<<"##########\n";
        while(adress != nullptr)
        {
            char basamakChar[20];
            snprintf(basamakChar, sizeof(basamakChar), "%p", (void *)sayiData);
            size_t l = strlen(basamakChar);
            if(b == 0)
            {
                EkranaYazdir.ekran(xC,yC = yC+1);
                cout << "#" << setw(5) << gecici->sayi << setw(1) << "#";
                EkranaYazdir.ekran(xC,yC = yC+1);
                cout << "#" << setw(5) << "--------" << setw(1) << "#";
            }
            EkranaYazdir.ekran(xC = xC+15, yC-2);
            cout<<"***********\n";
            xC = xC-15;
            EkranaYazdir.ekran(xC = xC+15,yC = yC-1);
            cout << "#" << setw(3) << basamakChar[l-3] << basamakChar[l-2] << basamakChar[l-1] << setw(5) << "#";
            yC++;
            EkranaYazdir.ekran(xC, yC);
            cout<<"***********\n";
            sayiData = sayiData->next;
            adress = adress->next;
            b++;
        }
        xC=0;
        sayiData = gecici->sayi->getHead();
        int count = 0;
        int cond = 0;
        int zero = 0;
        string str;
        while(sayiData != nullptr)
        {
            if(sayiData->data == 0 && cond == 0)
            {
                zero = sayiData->data;
                sayiData = sayiData->next;
            }
            else
            {
                str = str + to_string(sayiData->data);
                sayiData = sayiData->next;
            }
            
            cond = 1;
        }
        sayiData = gecici->sayi->getHead();
        EkranaYazdir.ekran(xC, yC = yC+1);
        int a = 0;
        while(sayiData != nullptr)
        {
            if(a == 0)
            {
                EkranaYazdir.ekran(xC,yC = yC);
                cout << "#" << setw(5) << str << setw(4) << "#";
                EkranaYazdir.ekran(xC,yC = yC+1);
                cout<<"##########";
                yC = yC-1;
            }
            EkranaYazdir.ekran(xC = xC+15,yC);
            cout << "*" << setw(5) << sayiData->data << setw(5) << "*";
            sayiData = sayiData->next;
            a++;
            EkranaYazdir.ekran(xC,yC = yC+1);
            cout<<"***********";
            yC = yC-1;
        }
        xC=0;
        EkranaYazdir.ekran(xC,yC = yC+3);
        gecici = gecici->next;
    }
    xC = 0;
    yC = yC+5;
}

//SayilarListesi sınıfı için yıkıcı method.
SayilarListesi::~SayilarListesi()
{
    Dugum *temp = head;
    while(temp != nullptr)
    {
        Dugum *sil = temp;
        temp = temp->next;
        delete sil;
    }
}
