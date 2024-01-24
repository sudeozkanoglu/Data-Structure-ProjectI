/** 
* @file G201210034 src Test.cpp
* @description Test işlemleri için dosyadan okuma yapıldı ve ekrana yazma işlemi gerçekleştirildi.
* @course 1. Öğretim C grubu
* @assignment 1.Ödev
* @date 27 Ekim 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "Basamak.hpp"
#include "Sayi.hpp"
#include "SayilarListesi.hpp"
#include "EkranaYazdir.hpp"
#include "Dugum.hpp"
using namespace std;

int main()
{
    string line,val;
    int i = 0;
    int data,digit = 0;
    int headNum = 0;
    int bigNum = 0;
    Sayi *bigSayi = nullptr;
    int array[20]; //Sayılar 20 basamaktan daha fazla olamaz diye 20 atandı.
    SayilarListesi *sayilarListesi = new SayilarListesi();
    SayilarListesi *headNumList = new SayilarListesi();
    ifstream newfile;
    int xC =0;
    int yC =0;
    
    //Dosya okuma işlemleri yapıldı.
    newfile.open("sayilar.txt");
    if(!newfile.is_open())
    {
        cout << "Dosya acma islemi basarisiz!" <<endl;
        return 0;
    }
    system("cls");
    while(getline(newfile,line))
    {
        istringstream resultedLine(line);
        while(getline(resultedLine, val, ' '))
        {
            Sayi *sayi = new Sayi();
            Sayi *headNums = new Sayi();
            Dugum *dugum = new Dugum();
            data = stol(val, nullptr);
            headNum = data;
            if(bigNum == 0)
            {
                bigNum = headNum;
                bigSayi = sayi;
            }
            else
            {
                if(headNum > bigNum)
                {
                    bigNum = headNum;
                    bigSayi = sayi;
                }
            }
            while(data > 0)
            {
                digit = data % 10;
                array[i] = digit;
                data /= 10;
                i++;
            }
            array[i] = headNum;
            headNums->insertBasamak(headNum);
            for(int x = i-1; x >= 0 ; x--)
            {
              sayi->insertBasamak(array[x]);
            }
            sayilarListesi->insertDugum(sayi);
            headNumList->insertDugum(headNums);
            i = 0; 
        }
    }
    //Dosya okuma işlemi sonrası ekrana yazdırma ve seçeneklerin sunulduğu kısım.
    int choice;
    sayilarListesi->printAll();
    do
    {
        Dugum *tempDugum = sayilarListesi->getHead();
        Dugum *tempHeadDugum = headNumList->getHead();
        cout<<"1- Tek Basamaklari Basa Al "<<endl;
        cout<<"2- Basamaklari Tersle"<<endl;
        cout<<"3- En Buyuk Cikar"<<endl;
        cout<<"4- Cikis"<<endl;
        int count=0;
        int index=2;

        cin>>choice;
        if(choice == 1)
        {
            while(tempDugum != nullptr)
            {
                count = tempDugum->sayi->countLength();
                tempDugum->sayi->changeOdd(count);
                tempDugum = tempDugum->next;
            }
            if(sayilarListesi->getHead() != nullptr)
            {
                sayilarListesi->printAll();
            }
        }
        else if(choice == 2)
        {
            while(tempDugum != nullptr)
            {
                count = tempDugum->sayi->countLength();
                tempDugum->sayi->changeQueue(count);
                tempDugum = tempDugum->next;
            }
            sayilarListesi->printAll();
        }
        else if(choice == 3)
        {
            sayilarListesi->deleteBiggest(sayilarListesi->calculateBigNum());
            sayilarListesi->printAll();

        }
        else if(choice != 4 && choice != 3 && choice != 2 && choice != 1)
        {
            cout<<"Hatali Giris Yaptiniz" << endl;
        }
    }
    while(choice != 4);
    cout << "Gorusmek Uzere" << endl;
    
    
    /* Dugum* currentDugum = sayilarListesi->getHead();
    while(currentDugum != nullptr)
    {
        cout << "Dugum Adres: " << currentDugum << endl;
        cout << "Sayi Isaretcisi Adres: " <<currentDugum->sayi << endl;
        if(currentDugum->next != nullptr)
        {
           cout << "Siradaki Dugum Adres: " <<currentDugum->next->sayi << endl; 
        }
        currentDugum = currentDugum->next;
    } */
    /*int a = 0;
    int b = 0;
    cout << endl;
    Dugum* addressDugum = sayilarListesi->getHead();
    Dugum* dataDugum = sayilarListesi->getHead();
    cout << "Sayilar Listesi Adresi(Icinde Dugumler Olan): " <<sayilarListesi << endl;
    cout << endl;
    while(addressDugum != nullptr)
    {
        if(a == 0)
        {
        }
        cout << addressDugum << "\t ";
        
        a++;
        addressDugum = addressDugum->next;
    }
    cout << endl;
    while(dataDugum != nullptr)
    {
        
        cout << dataDugum->sayi << "\t "; 
        dataDugum = dataDugum->next;
    }
    cout << endl;
    cout << endl;
    dataDugum = sayilarListesi->getHead();
    while(dataDugum != nullptr)
    {
        cout << " "; 
        if(dataDugum->next != nullptr)
        {
           cout << " S: " << dataDugum->next->sayi << "\t "; 
        } 
        
        dataDugum = dataDugum->next;
    } */
}



// OLD PRINT SCREEN
/* Basamak* adress = sayi->getHead();
            Basamak* sayiData = sayi->getHead();
            int b = 0;
            //cout << "HEAD: " << array[i] << endl;
            //cout << "Sayi List Address:" << sayi << endl;
            
            EkranaYazdir.ekran(xC,yC);
            cout<<"##########\n";
            //EkranaYazdir.ekran(xC,yC);
            //cout << "#" << setw(5) << "HEAD ADDRESS:" << sayi << setw(2) << "#";
            while(adress != nullptr)
            {
                char basamakChar[20];
                snprintf(basamakChar, sizeof(basamakChar), "%p", (void *)sayiData);
                size_t l = strlen(basamakChar);
                if(b == 0)
                {
                    EkranaYazdir.ekran(xC,yC = yC+1);
                    cout << "#" << setw(5) << sayi << setw(1) << "#";
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
            
            sayiData = sayi->getHead();
            EkranaYazdir.ekran(xC, yC = yC+1);
            int a = 0;
            while(sayiData != nullptr)
            {
                if(a == 0)
                {
                    EkranaYazdir.ekran(xC,yC = yC);
                    cout << "#" << setw(5) << array[i] << setw(4) << "#";
                    EkranaYazdir.ekran(xC,yC = yC+1);
                    cout<<"##########";
                    yC = yC-1;
                }
                EkranaYazdir.ekran(xC = xC+15,yC);
                cout << "*" << setw(5) << sayiData->data << setw(5) << "*";
                //cout << "S:" << setw << sayiData->next << ""; 
                sayiData = sayiData->next;
                a++;
                EkranaYazdir.ekran(xC,yC = yC+1);
                cout<<"***********";
                yC = yC-1;
            }
            xC=0;
            EkranaYazdir.ekran(xC,yC = yC+3); */