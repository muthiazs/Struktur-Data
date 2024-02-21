/* File : mainList3.c */
/* Deskripsi : ADT list berkait ganda dengan representasi fisik pointer */
/* NIM & Nama : Muthia Zhafira 24060122130071*/
/* Tanggal : 12 NOVEMBER 2023 */
#include <stdio.h>
#include <stdlib.h>
#include "List3.c"

int main()
{
    /*Kamus Lokal*/
    address A;
    address B;
    address S;
    List3 LL;
    infotype X;
    /*Algoritma*/
   printf("\n----------------------PRAKTIKUM 09 LIST3------------------------\n");
   printf("\n----------------By : MUTHIA 24060122130071----------------------\n");
   CreateList(&LL);
   InsertVFirst(&LL,'T');
   InsertVFirst(&LL,'A');
   InsertVFirst(&LL,'B');
   printf("\n------MENGECEK APAKAH LIST KOSONG------\n");
    if (IsEmptyList(LL)){
        printf("\nList Kosong\n");
    }
    else{
        printf("\nList Tidak Kosong\n");
    }
  printf("\n------MENCETAK LIST LL------\n");
  PrintList(LL);
  printf("\n------MENGHITUNG ELEMEN DALAM LIST------\n");
  printf("\nJumlah elemen dalam list : %d " , NbElm(LL)); 
}
