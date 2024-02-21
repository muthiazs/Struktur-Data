/* File : drivermainlist3.c */
/* Deskripsi : ADT list berkait tunggal sirkular dengan representasi fisik pointer */
/* NIM & Nama : Muthia Zhafira 24060122130071*/
/* Tanggal : 17 NOVEMBER 2023 */
#include <stdio.h>
#include <stdlib.h>
#include "List3.c"

int main()
{
    /*Kamus Lokal*/
    address A;
    address B;
    address S;
    List3 L1;
    List3 L2;
    infotype X;
    /*Algoritma*/
   printf("\n----------------------PRAKTIKUM 09 LIST3------------------------\n");
   printf("\n----------------By : MUTHIA 24060122130071----------------------\n");
   CreateList(&L1);
   InsertVFirst(&L1,'M');
   InsertVFirst(&L1,'U');
   InsertVFirst(&L1,'G');
   printf("\n------MENCETAK LIST L1------\n");
   PrintList(L1);
   CreateList(&L2);
   InsertVFirst(&L2,'M');
   InsertVFirst(&L2,'U');
   InsertVFirst(&L2,'T');
   printf("\n------MENCETAK LIST L1------\n");
   PrintList(L2);
   printf("\nApakah L1 dan L2 simetri ? %s " , IsListSimetri(L1,L2)? "YA" : "TIDAK");
//    printf("\n------MENGECEK APAKAH LIST KOSONG------\n");
//     if (IsEmptyList(LL)){
//         printf("\nList Kosong\n");
//     }
//     else{
//         printf("\nList Tidak Kosong\n");
//     }
//     printf("\n------MENGHITUNG ELEMEN DALAM LIST------\n");
//     printf("\nJumlah elemen dalam list : %d " , NbElm(LL));
//     printf("\n------MENAMBAHKAN ELEMEN A KEDEPAN LIST------\n"); 
//     InsertVFirst(&LL,'A');
//     PrintList(LL);
//     printf("\n------MENAMBAHKAN ELEMEN X KEDEPAN LIST------\n"); 
//     InsertVFirst(&LL,'X');
//     PrintList(LL);
//     printf("\n------MENAMBAHKAN ELEMEN A KEAKHIR LIST------\n"); 
//     InsertVLast(&LL,'A');
//     PrintList(LL);
//     printf("\n------MENAMBAHKAN ELEMEN S KEAKHIR LIST------\n"); 
//     InsertVLast(&LL,'S');
//     PrintList(LL);
//     printf("\n------MENGHAPUS ELEMEN PERTAMA LIST------\n"); 
//     DeleteVFirst(&LL,&X);
//     PrintList(LL);
//     printf("\n------MENGHAPUS ELEMEN TERAKHIR LIST------\n"); 
//     DeleteVLast(&LL,&X);
//     PrintList(LL);
//     printf("\n------MENGHAPUS ELEMEN C DI LIST------\n"); 
//     DeleteX(&LL,'C');
//     PrintList(LL);
//     printf("\n------MENCARI ELEMEN X DI LIST LL------\n");
//     SearchX(LL, 'X', &A);
//     printf("\nElemen yang dicari berada di alamat %p\n", A);
//     printf("\n------MENCARI ELEMEN E DI LIST LL------\n");
//     SearchX(LL, 'E', &A);
//     printf("\nElemen yang dicari berada di alamat %p\n", A);
//     printf("\n------UPDATE NILAI E MENJADI O------\n");
//     printf("\nList sebelum di update : \n");
//     PrintList(LL);
//     UpdateX(&LL,'E','O');
//     printf("\nList sesudah di update : \n");
//     PrintList(LL);
//     printf("\n-------------INVERS LIST--------   \n");
//     Invers(&LL);
//     PrintList(LL);
//     printf("\n-------------MENGHITUNG JUMLAH ELEMEN A DI LIST--------   \n");
//     printf("\n jumlah elemen di list adalah : %d \n" , CountX(LL,'A'));
//     printf("\n-------------MENGHITUNG JUMLAH ELEMEN R DI LIST--------   \n");
//     printf("\n jumlah elemen di list adalah : %d \n" , CountX(LL,'R'));
//     printf("\n-------------MENGHITUNG JUMLAH ELEMEN X DI LIST--------   \n");
//     printf("\n jumlah elemen di list adalah : %d \n" , CountX(LL,'X'));
//     printf("\n-------------MENGHITUNG FREKUENSI JUMLAH ELEMEN A DI LIST--------   \n");
//     printf("\nRasio Kemunculan elemen tersebut adalah: %f\n", FrekuensiX(LL, 'A'));
//     printf("\n-------------MENCARI MODUS DI LIST LL--------   \n");
//     printf("\nModus di list adalah : %c\n",Modus(LL));
//     printf("\n------MENAMBAHKAN ELEMEN G KEDEPAN LIST------\n"); 
//     InsertVFirst(&LL,'G');
//     PrintList(LL);
//     printf("\n------MENAMBAHKAN ELEMEN N KEDEPAN LIST------\n"); 
//     InsertVFirst(&LL,'N');
//     PrintList(LL);
//     printf("\n------MENAMBAHKAN ELEMEN N KEAKHIR LIST------\n"); 
//     InsertVLast(&LL,'N');
//     PrintList(LL);
//     printf("\n-------------MENGHITUNG JUMLAH ELEMEN VOCAL DI LIST--------   \n");
//     printf("\n jumlah elemen vocal di list adalah : %d \n" , CountVocal(LL));
//     printf("\n-------------MENGHITUNG JUMLAH ELEMEN HURUF N YANG LANGSUNG DIIKUTI HURUF G DI LIST--------   \n");
//     printf("\n jumlah elemen N yang diikuti langsung oleh G di list adalah : %d \n" , CountNG(LL));
//     printf("\n------MENAMBAHKAN ELEMEN U SETELAH R-----\n");
//     InsertVAfterX(&LL ,'R','U');
//     PrintList(LL);
//     printf("\n------MENAMBAHKAN ELEMEN U SEBELUM R -----\n");
//     InsertVBeforeX(&LL ,'R','U');
//     PrintList(LL);
//     printf("\n------MENGHAPUS ELEMEN SETELAH N -----\n");
//     DeleteVAfterX(&LL ,'N',&X);
//     PrintList(LL);
//     printf("\n------MENGHAPUS ELEMEN SEBELUM R-----\n");
//     DeleteVBeforeX(&LL ,'R',&X);
//     PrintList(LL);
//     printf("\n-------------MENCARI INDEKS SEMUA ELEMEN  A DI LIST LL--------   \n");
//     printf("\n elemen A ada di indeks :  " );
//     printf ("\t");
//     SearchAllX(LL,'A');
//     printf ("\n");
    printf("\n--------------------------SELESAI TERIMAKASIH ^_^------------------------------------\n");
    }
