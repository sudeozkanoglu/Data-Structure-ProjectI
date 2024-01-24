/** 
* @file G201210034 src Sayi.cpp
* @description Sayi işlemleri için ekleme ve sayi yön değiştirme, tek öne alma yapıldı.
* @course 1. Öğretim C grubu
* @assignment 1.Ödev
* @date 27 Ekim 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#include "Sayi.hpp"
#include "Dugum.hpp"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

//Sayi sınıfının kurucu methodu oluşturuldu.
Sayi::Sayi()
{
    head=nullptr;
}

//Bağlı listerimizi oluşturabilmek adına basamak düğümlerimizi Sayi altında birleştirdik.
void Sayi::insertBasamak(int data)
{
    if(data < 10)
    {
        Basamak *basamak = new Basamak(data);
        if (head == nullptr)
        {
            head = basamak;
        }
        else
        {
            Basamak *last = head;
            while (last->next != nullptr)
            {
                last = last->next;
            }
            last->next = basamak;    
        }
    }
}

//Sayi sınıfının head değerini döndüren method.
Basamak* Sayi::getHead()
{
    return head;
}

//Sayi sınıfındaki belirli bir Basamak düğümünü getiren method.
Basamak* Sayi::getDugum(int index, int count)
{
    if(index < 0)
    {
        return nullptr;
    }
    Basamak *temp = head;
    while(temp->next->data != index)
    {
        temp = temp->next;
    }
    return temp;

}

//Bağlı listemizin uzunluğunu hesaplayan method.
int Sayi::countLength()
{
    int count = 0;
    if(head == nullptr)
    {
        cout << "Head is empty";
        return 0;
    }
    Basamak *gecici = head;
    while(gecici != nullptr)
    {
        count++;
        gecici = gecici->next;
    }
    return count;
}

//Bağlı listeyi tersine çevirmek için kullanılan method.
void Sayi::changeQueue(int count)
{
    if (head == nullptr)
    {
        cout << "List Empty." << endl;
        return;
    }

    if(count > 2)
    {
        Basamak *temp = head->next;
        Basamak *newHead = nullptr;
        Basamak *oldHead = head;
        Basamak *num = head;
        Basamak *pr = head;
        Basamak *lt = nullptr;

        while(num->next != nullptr)
        {
            num = num->next;
            
        }
        cout << num->data << endl;
        while(num != oldHead->next)
        {
            lt = oldHead->next;
            oldHead->next = lt->next;
            if(count == 0)
            {
                lt->next = oldHead;
            }
            else
            {
                lt->next = newHead;
            }
            newHead = lt;
            count++;
        }
        pr = newHead;
        Basamak* xy = head;
        while(xy->next != nullptr)
        {
            xy = xy->next;
        }
        xy->next = newHead;
        xy = head;
        Basamak *degis = xy;
        head = degis->next;
        while(pr->next != nullptr)
        {
            pr = pr->next;
        }
        degis->next = nullptr;
        pr->next = degis;
    }
    else if(count <= 2)
    {
        if(count == 1)
        {

        }
        else if(count == 2)
        {
            Basamak *second = head->next;
            second->next = head;
            head->next = nullptr;
            head = second;
        }
    }
    /* while(pr != nullptr)
    {
        cout << "SAYI:" << pr->data << endl;
        pr = pr->next;
    } */

    /* for(int i = 0; i < count; i++)
    {
        cout << "burada" << endl;
        while(gecici != nullptr)
        {
            Basamak *prev = getDugum(gecici->data, count);
            gecici->next = geciciHead;
            prev->next = nullptr;
            geciciHead = gecici;

        }
        cout << "gecici head:"<< geciciHead << endl;
    } */
}

//Bağlı listemizdeki tek sayı düğümlerini sırayla liste başına getiren method.
void Sayi::changeOdd(int count)
{
    if (head == nullptr)
    {
        cout << "List Empty" << endl;
        return;
    }
    Basamak* gecici = head;
    Basamak* siradaki = head->next;
    
    if(count > 1 && count <= 2)
    {
        if(gecici->data %2 == 0 && siradaki->data %2 != 0)
        {
            siradaki->next = gecici;
            gecici->next = nullptr;
            head = siradaki;
        }
    }
    else if(count > 2)
    {
        gecici = head;
        Basamak *headTek = nullptr;
        Basamak *contTek = nullptr;
        Basamak *headCift = nullptr;
        Basamak *contCift = nullptr;
        Basamak* siradaki = head->next;
        
        if(head->data%2 == 0 && siradaki->data %2 !=0)
        {
            gecici->next = siradaki->next;
            siradaki->next = gecici;  
            head = siradaki;
        }
        gecici = head;

        while(gecici != nullptr)
        {
            if(gecici->data %2 != 0)
            {
                if(headTek == nullptr)
                {
                    headTek = gecici;
                }
                else
                {
                    if(contTek == nullptr)
                    {
                        contTek = gecici;
                        headTek->next = contTek;
                    }
                    else
                    {
                        contTek->next = gecici;
                        contTek = contTek->next;
                    }
                }
            }
            else if(gecici->data %2 == 0)
            {
                if(headCift == nullptr)
                {
                    headCift = gecici;
                }
                else
                {
                    if(contCift == nullptr)
                    {
                        contCift = gecici;
                        headCift->next = contCift;
                    }
                    else
                    {
                        contCift->next = gecici;
                        contCift = contCift->next;
                    }
                }
            }
            gecici = gecici->next;
        }
        if(headTek != nullptr)
        {
            head = headTek;
        }

        if(contTek == nullptr && headTek != nullptr && headCift != nullptr)
        {
            headTek->next = headCift;
        }
        if(contTek != nullptr && headCift != nullptr)
        {
            contTek->next = headCift;
        }
        else if(contTek == nullptr && headTek != nullptr && headCift != nullptr)
        {
            headTek->next = headCift;
        }
        if(contCift != nullptr)
        {
            contCift->next = nullptr;
        }
        if(headCift != nullptr && contCift == nullptr)
        {
            headCift->next = nullptr;
        }
        //contTek->next = headCift;
        
        /* gecici=head;
        Basamak* siradaki = head->next;
        if(head->data%2 == 0 && gecici->next->data %2 !=0)
        {
            gecici->next = siradaki->next;
            siradaki->next = gecici;  
            head = siradaki;
        }
        gecici=head->next;
        siradaki = gecici->next;
        Basamak* headTek = head;
        Basamak *prev = nullptr;
        Basamak *secondPrev = nullptr;
        
        while(siradaki != nullptr)
        {
            if(siradaki->data %2 != 0)
            {
                prev = getDugum(siradaki->data,count);
                prev->next = siradaki->next;
                secondPrev = getDugum(prev->data,count);
                siradaki->next = prev;
                headTek->next = siradaki;
                siradaki = prev->next;
                headTek = headTek->next;
                //headTek->next = prev;   
            }
            else
            {
                siradaki = siradaki->next;
                prev = prev->next;
            }
        } */
    }
    /* while(gecici != nullptr)
    {
        cout << gecici->data << endl;
        gecici = gecici->next;
    } */

}

//Sayi sınıfının yıkıcı methodu.
Sayi::~Sayi()
{
    Basamak *temp = head;
    while(temp != nullptr)
    {
        Basamak *sil = temp;
        temp = temp->next;
        delete sil;
    }
}

