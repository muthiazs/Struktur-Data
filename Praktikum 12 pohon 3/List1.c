/* File : list1.c */
/* Deskripsi : ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122130071*/
/* Tanggal : 4 NOVEMBER 2023 */

#ifndef List1_c
#define List1_c

#include <stdio.h>
#include "List1.h"

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List1)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List1 *L){
    //KAMUS LOKAL
    //ALGORITMA
    L->First = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List1) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List1 L){
    //KAMUS LOKAL
    //ALGORITMA
    if (L.First == NIL){
        return true;
    }
    else {
        return false;
    }
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List1)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List1 L){
// Kamus Lokal
 address P;
// Algoritma 
 P = L.First;
while (P != NIL)
{
    printf("%c\t", P->info);
    P= P->next;
}
}

/*function NbElm(L:List1) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List1 L){
    //KAMUS LOKAL
        address P;
        int Nb;
    //ALGORITMA 
     Nb = 0;
     P = First(L);
     while (P != NIL)
     {
        Nb = Nb + 1;
        P = next(P);
     }
     return Nb;     
}

/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* procedure Alokasi (output P:address) */ 
/* {I.S. - 
    F.S. P ter-alokasi 
	Proses: Memesan ruang memori untuk address P} */
    
void Alokasi (address *P){
    //KAMUS LOKAL
    //ALGORITMA
    (*P) = (address) malloc ( sizeof (ElmList) );
}

/* procedure Dealokasi (P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P){
    //KAMUS LOKAL
    //ALGORITMA
     free (*P);
     (*P) = NIL;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List1, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List1 *L, infotype V ){
    //Kamus Lokal
    address P;
    //Algoritma 
    Alokasi(&P);
    if (P != NIL){
        info(P) =  V;
        next(P) = First(*L);
        First(*L) = P;
    }  
}

/*Procedure InsertVLast(input/output L:List1, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List1 *L, infotype V ){
    //Kamus Lokal
    address P;
    address Last;
    //Algoritma 
    Alokasi(&P);
    if (P != NIL){
        info(P) = V;
        next(P) = NIL;
        if (First(*L)==NIL){
            First(*L) = P;
        }
        else 
        {
            Last = First(*L);
            while (next(Last) != NIL)
            {
                Last = next(Last);
            }
            next(Last) = P;        
        }
        }
    }

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List1, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List1 *L, infotype *V){
    //Kamus Lokal
    address P;
    //Algoritma
    P = L->First;
    (*V) = info(P);
    L->First = next(L->First);
    Dealokasi(&P);
}

/*Procedure DeleteVLast(input/output L:List1, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List1 *L, infotype *V){
    //Kamus Lokal
    address P, Last;

    //Algoritma
    P = L->First;
    if (next(P) == NIL){
        L->First = NIL;
    } else {
        Last = L->First;
        while (next(next(Last)) != NIL){
            Last = next(Last);
        }
        P = next(Last);
        (*V) = info(P);
        next(Last) = NIL;
    }
    Dealokasi(&P);
}
/*Procedure SearchX(input L:List1, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List1 L, infotype X, address *A)
{
    /* I.S. : L, X terdefinisi */
    /* F.S. : A berisi alamat elemen yang nilainya X.
    Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil */
    //Kamus Lokal
    address P;
    boolean found;
    //Algoritma
    (*A) = NIL;
    P = First(L);
    found = false;
    
    while(P != NIL && (!found)){
        if(info(P) == X){
            found = true;
            (*A) = P;
        }
        P = next(P);
    }
    
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List1 *L, infotype X, infotype Y)
{
    /* I.S. : L, X, Y terdefinisi */
    /* F.S. : L tetap, atau elemen bernilai X berubah menjadi Y.
    Mengganti elemen bernilai X menjadi Y}*/
    //Kamus Lokal
    address P;
    boolean found;
    //Algoritma 
    P = First(*L);
    found = false;
    while (P != NIL)
    {
        if (info(P)==X){
            info(P)=Y;
        }
        P = next(P);
    }   
}

/*Procedure Invers(input/output L:List1)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List1 *L){
    //KAMUS LOKAL
    address P;
    List1 Lo;
    //ALGORITMA
    CreateList(&Lo);
    P = L->First;
    while(P != NIL){
        InsertVFirst(&Lo, info(P));
        P = next(P);
    }
    (*L) = Lo;
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*function CountX(L:List1) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List1 L, infotype X){
    //Kamus Lokal
    address P;
    int count;
    //Algoritma
    count = 0;
    P = First(L);
    while(P != NIL){
        if(info(P) == X){
            count = count + 1;
        }
        P = next(P);
    }
    return count;
}

/*function FrekeuensiX(L:List1) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List1 L, infotype X){
    //KAMUS LOKAL
    //ALGORITMA
    return (float)CountX(L,X)/NbElm(L);
}

/*function Modus(L:List1) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List1 L)
{
    /* I.S. : L terdefinisi */
    /* F.S. : mengembalikan huruf yang paling banyak muncul dalam list L */
    //KAMUS LOKAL
    infotype max;
    int frekuensiMax = 0;
    address P;
    //ALGORITMA
    for (P = L.First; P != NIL; P = P->next)
    {
        if (CountX(L, info(P)) > frekuensiMax)
        {
            frekuensiMax = CountX(L, info(P));
            max = info(P);
        }
    }
    return max;
}

/*Procedure SearchAllX(input L:List1, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
void SearchAllX(List1 L, infotype X){
    //KAMUS LOKAL
    address P;
    int i;
    //ALGORITMA
    i = 0;
    P = First(L);
    while(P != NIL){
        if(info(P) == X){
            printf(" %d  ", i);
        }
        i = i + 1;
        P = next(P);
    }
}
/* Procedure InsertVAfter(input/output L:List1, input V:infotype, input VA:infotype )
{ I.S. List L mungkin kosong, V, S terdefinisi }
{ F.S. L tetap, atau bertambah 1 elemen (VA) pada posisi setelah elemen berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=VA 	Zsebagai elemen setelah elemen V list linier L yg mungkin kosong } */
void InsertVAfter(List1 *L, infotype V, infotype VA )
{
    /* I.S. List L mungkin kosong, V, S terdefinisi }
    /* F.S. L tetap, atau bertambah 1 elemen (VA) pada posisi setelah elemen berinfo V}
    /* Insert sebuah elemen beralamat P dengan Info(P)=VA 	Zsebagai elemen setelah elemen V list linier L yg mungkin kosong } */
    //KAMUS LOKAL
    address P, Q;
    //ALGORITMA
    Alokasi(&P);
    info(P)=VA;
    Q = First(*L);
        while (info(Q) != V && (Q) != NIL)
        {
           Q = next(Q); 
        }  
        next(P) = next(Q);
        next(Q) = P;  
    }
#endif