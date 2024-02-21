
/* File : list3.c */
/* Deskripsi : ADT list berkait sirkular dengan representasi fisik pointer */
/* NIM & Nama : 24060122130071 Muthia Zhafira Sahnah*/
/* Tanggal : 12 NOVEMBER 2023 */

#ifndef List3_c
#define List3_c

#include <stdio.h>
#include "List3.h"

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List3 *L){
    /*Kamus Lokal*/
    /*Algoritma*/
    L->First = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List3 L){
    /*Kamus Lokal*/
    /*Algoritma*/
    return L.First == NIL;
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List3 L){
    /*Kamus Lokal*/
    address P;
    /*Algoritma*/ 
    P = First(L);
    do {
        printf("%c\t", info(P));
    } while ( P != First(L));  
}


/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L){
    /*KAMUS LOKAL*/
    address P;
    int Nb;
    /*ALGORITMA*/
    if (First(L) != NIL)
    {
        P = First(L);
        Nb = 1;
        while (P != First(l))
        {
            Nb = Nb + 1;
            P = next(P);
        } 
    }
    else 
    {
        Nb = 0;
    }
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
    (*P) = (address) malloc ( sizeof (ElmList3) );
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
/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V) {
    /*Kamus Lokal*/
    address P;
    address last;
    /*Algoritma*/
    Alokasi(&P);
    info(P) = V;
    if (First(*L) == NIL) {
            First(*L) = P;
            next(P)= P;
        } 
        else 
        {
            last = First(*L);
            while (next(last) != First(*L)) {
                last = next(last);
            }
            next(last) = P;
            next (P) = L->First;
        }
    }
        


/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V ){
    /*Kamus Lokal*/
    address P;
    address last;
    /*Algoritma*/
    Alokasi(&P);
    if (P != NIL)
    {
        info(P) = V;
        if (First(*L) == NIL){
            First(*L) = P;
            next(P)=P;
        }
        else
        {
            last = First(*L);
            while (next(last) != First(*L))
            {
                last = next(last);
            }
            next(last) = P;
            next(P) = First(*L);
        }
    }

}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V){
    /*Kamus Lokal*/
    address last;
    address P;
    /*Algoritma*/
    if(next(First(*L)) == First(*L)){
        First(*L)=NIL;
    }
    else
    {
        P = First(*L);
        last = First(*L);
        while (next(last) != First(*L))
        {
            last = next(last);
        }
        *V = info(P);
        next(last)= next(P);
        First(*L) = next(P);
        Dealokasi(P);
    }
}

/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V){
    /*Kamus Lokal*/
    
}
#endif