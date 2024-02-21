/* File : list2.c */
/* Deskripsi : ADT list berkait ganda dengan representasi fisik pointer */
/* NIM & Nama : 24060122130071 Muthia Zhafira Sahnah*/
/* Tanggal : 12 NOVEMBER 2023 */

#ifndef list2_c
#define list2_c

#include <stdio.h>
#include "list2.h"
/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:list2)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (list2 *L){
    /*KAMUS LOKAL*/
    /*ALGORITMA*/
    L->First = NIL;
}
/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:list2) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (list2 L){
    /*KAMUS LOKAL*/
    /*ALGORITMA*/
    if (L.First == NIL){
        return true;
    }
    else {
        return false;
    }
}
/*PENELUSURAN*/
/*procedure PrintList(input L:list2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(list2 L){
/*Kamus Lokal*/
 address P;
/*Algoritma*/ 
 P = L.First;
while (P != NIL)
{
    printf("%c\t", P->info);
    P= P->next;
}
}
/*function NbElm(L:list2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(list2 L){
    /*KAMUS LOKAL*/
        address P;
        int Nb;
    /*ALGORITMA*/
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
    /*Kamus Lokal*/
    /*Algoritma*/
    (*P) = (address) malloc ( sizeof (ElmList2) );
} //representasi fisik prosedur
//address Alokasi(); //representasi fisik fungsi
 
/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P){
    /*Kamus Lokal*/
    /*Algoritma*/
     free (*P);
     (*P) = NIL;
}
/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:list2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(list2 *L, infotype V ){
    /*Kamus Lokal*/ 
    address P;
    /*Algoritma*/
    Alokasi(&P);
    if (P != NIL) 
    {
        info(P) = V;
        prev(P) = NIL;
        next(P) = First(*L);
        if (First(*L)!=NIL)
        {
        prev(First(*L)) = P;
        }
        First(*L)=P;
    }   
}
/*Procedure InsertVLast(input/output L:list2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(list2 *L, infotype V ){
    /*Kamus Lokal*/
    address P;
    address last;
    /*Algoritma*/
    Alokasi(&P);
    if (P != NIL){
        info(P)= V;
        next(P)= NIL;
        if (First(*L)==NIL){
            prev(P) = NIL;
            First(*L) = P;
        }
        else{
            last = First(*L);
            while (next(last)!=NIL)
            {
                last = next(last);
            }
            prev(P) = last;
            next(last) = P;    
        }  
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:list2, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(list2 *L, infotype *V){
    /*Kamus Lokal*/
    address P;
    /*Algoritma*/ 
    P = First(*L);
    (*V) = info(P);
    First(*L)=next(P);
    prev(First(*L)) = NIL;
    Dealokasi(&P);
}
/*Procedure DeleteVLast(input/output L:list2, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(list2 *L, infotype *V){
    /*Kamus Lokal*/
    address last;
    /*Algoritma*/
    if (First(*L)!= NIL){
        last = First(*L);
        while (next(last) != NIL)
        {
            last = next(last);
        }
        *V = info(last);
        next(prev(last))=NIL;
        prev(last) = NIL;
        Dealokasi(&last);
    }
}
/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteX(list2 *L, infotype X){
    /*Kamus Lokal*/
    address P;
    /*Algoritma*/
    if (First(*L) != NIL){
        P = First(*L);
        while (next(P) != NIL && info(P)!= X)
        {
            P = next(P);
        }
        if (info(P) = X){
            if (next(P)==NIL){
                DeleteVLast(L,&X);
            }
            else if (prev(P)==NIL){
                DeleteVFirst(L,&X);
            }
            else{
                next(prev(P))=next(P);
                prev(next(P))=prev(P);
            }
        }    
    }
}
/*** PENCARIAN ***/
/*Procedure SearchX(input L:list2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(list2 L, infotype X, address *A){
    /*Kamus Lokal*/
    address P;
    boolean found;
    /*Algoritma*/
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
/*Procedure UpdateX(input/output L:list2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(list2 *L, infotype X, infotype Y){
    /*Kamus Lokal*/
    address P;
    boolean found;
    /*Algoritma*/
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
/*Procedure Invers(input/output L:list2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(list2 *L){
    /*Kamus Lokal*/
    address P;
    list2 Lo;
    /*Algoritma*/
    CreateList(&Lo);
    P = L->First;
    while(P != NIL){
        InsertVFirst(&Lo, info(P));
        P = next(P);
    }
    (*L) = Lo;
}
/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(list2 *L, infotype X, infotype V){
 /*Kamus Lokal*/
    address P, Q;
    /*Algoritma*/
    Alokasi(&P);
    info(P)=V;
    Q = First(*L);
    while (info(Q) != X && Q != NIL)
    {
        Q = next(Q);
    }
    if (Q != NIL) {
        prev(P) = Q;
        next(P) = next(Q);
        if (next(Q) != NIL) {
            prev(next(Q)) = P;
        }
        next(Q) = P;
    } 
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(list2 *L, infotype X, infotype V){
    /*Kamus Lokal*/
    address P,Q;
    /*Algoritma*/
    Alokasi(&P);
    info(P)=V;
    Q = First(*L);
    while (info(Q) != X && Q != NIL){
        Q = next(Q);
    }
    if (Q!=NIL){
        if (prev(Q)==NIL)
        {
            P = First(*L);
            prev(P) = NIL;
        }
        else
        {
            next(prev(Q))=P;
            prev(P)=prev(Q);

        }
        next(P)=Q;
        prev(Q)=P;
    }
}
/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(list2 *L, infotype X, infotype *V){
    /*Kamus Lokal*/
    address P,Q;
    /*Algoritma*/
    Q = First(*L);
    while (Q != NIL && info(Q) != X)
    {
        Q = next(Q);
    }
    if (Q != NIL && next(Q) != NIL) {
        P = next(Q);
        *V = info(P);
        next(Q) = next(P);
        if (next(P) != NIL) {
            prev(next(P)) = Q;
        }
        Dealokasi(&P);
    }
}
/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(list2 *L, infotype X, infotype *V){
    /*Kamus Lokal*/
    address P,Q;
    /*Algoritma*/
    Q = First(*L);
    while (Q != NIL && info(Q) != X)
    {
        Q = next(Q);
    }
    if (Q != NIL && prev(Q) != NIL) {
        P = prev(Q);
        *V = info(P);
        prev(Q) = prev(P);
        if (prev(P) != NIL) {
            next(prev(P)) = Q;
        } else {
            First(*L) = Q;  // P was the first node
        }
        Dealokasi(&P);
    }
}
int CountX(list2 L, infotype X){
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
float FrekuensiX(list2 L, infotype X){
    //KAMUS LOKAL
    //ALGORITMA
    return (float)CountX(L,X)/NbElm(L);
}
/*function Modus(L:List1) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(list2 L)
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
void SearchAllX(list2 L, infotype X){
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

// void IntersectList(list2 L1, list2 L2, list2 *L3)
// {
//     /*Kamus Lokal*/
//     address P, Q;

//     /*Algoritma*/
//     CreateList(&L3);
//     P = First(L1);
//     Q = First(L2);
//     if (NbElm(L1) == NbElm(L2))
//     {
//         while (P != NIL && Q != NIL)
//         {
//             if (info(P) == info(Q))
//             {
//                 InsertVLast(L3, info(P));
//             }
//             P = next(P);
//             Q = next(Q);
//         }
        
//     }
//     else
//     {
//         if (NbElm(L1) < NbElm(L2))
//         {
//             while (P != NIL)
//             {
//                 if (info(P) == info(Q))
//                 {
//                     InsertVLast(L3, info(P));
//                 }
//                 P = next(P);
//                 Q = next(Q);
//             }
            
//         }
//         else
//         {
//             while (Q != NIL)
//             {
//                 if (info(P) == info(Q))
//                 {
//                     InsertVLast(L3, info(Q));
//                 }
//                 P = next(P);
//                 Q = next(Q);
//             }
//         }
//     }
// }

void IntersectList(list2 L1, list2 L2, list2 *L3)
{
    /* Kamus Lokal */
    address P, Q;

    /* Algoritma */
    P = First(L1);
    Q = First(L2);
    
    while (P != NIL && Q != NIL)
    {
        if (info(P) == info(Q))
        {
            InsertVLast(L3, info(P));
            P = next(P);
            Q = next(Q);
        }
        else if (info(P) < info(Q))
        {
            P = next(P);
        }
        else
        {
            Q = next(Q);
        }
    }
    
    // Loop tambahan untuk menangani kasus kedua
    while (Q != NIL)
    {
        Q = next(Q);
    }
}

#endif

