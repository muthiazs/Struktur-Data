/* File : drivermainlist2.c */
/* Deskripsi : ADT list berkait ganda dengan representasi fisik pointer */
/* NIM & Nama : Muthia Zhafira 24060122130071*/
/* Tanggal : 12 NOVEMBER 2023 */
#include <stdio.h>
#include <stdlib.h>
#include "list2.c"
int main()
{ 
    //kamus
    address A;
    address B;
    address S;
    list2 L1;
    list2 L2;
    list2 L3;
    infotype X;
    //algoritma
   printf("\n----------------------PRAKTIKUM 08 LIST2------------------------\n");
   printf("\n----------------By : MUTHIA 24060122130071----------------------\n");
   CreateList(&L1);
   InsertVFirst(&L1,'T');
   InsertVFirst(&L1,'H');
   InsertVFirst(&L1,'I');
   InsertVFirst(&L1,'A');
   printf("\nMencetak L1 : \n");
   PrintList(L1);
   CreateList(&L2);
   InsertVFirst(&L2,'T');
   InsertVFirst(&L2,'I');
   InsertVFirst(&L2,'R');
   InsertVFirst(&L2,'Z');
   InsertVFirst(&L2,'A');
   printf("\nMencetak L2 : \n");
   PrintList(L2);  
   IntersectList(L1,L2,&L3);
   printf("\nMencetak L3 : \n");
   PrintList(L3);
  //  Alokasi(&B);
  //  B->info = 'U';   B->next = A; // B diisi H dan next nya diisi A
  //  printf("\n------MENCETAK INFO B-----\n");
  //  printf("info(B)=%c\n", B->info );
  //  LL.First = B; // LL adalah elemen list dimana first nya (awalnnya) adalah B 
  //  printf("\n------MENGECEK APAKAH LIST KOSONG------\n");
  // if (IsEmptyList(LL)){
  //   printf("\nList Kosong\n");
  // }
  // else{
  //   printf("\nList Tidak Kosong\n");
  // }
  // printf("\n------MENCETAK LIST LL------\n");
  // PrintList( LL );
  // printf("\n------MENGHITUNG ELEMEN LIST------\n");
  // printf( "Jumlah elemen list adalah : %d " ,NbElm(LL) );
  // printf("\n------MENAMBAHKAN ELEMEN M KEDEPAN LIST LL------\n");
  // InsertVFirst(&LL,'M');
  // PrintList( LL );
  // printf("\n------MENAMBAHKAN ELEMEN A KEDEPAN LIST LL------\n");
  // InsertVFirst(&LL,'A');
  // PrintList( LL );
  // printf("\n------MENAMBAHKAN ELEMEN J KEDEPAN LIST LL------\n");
  // InsertVFirst(&LL,'J');
  // PrintList( LL );
  // printf("\n------MENAMBAHKAN ELEMEN Z KEBELAKANG LIST LL------\n");
  // InsertVLast(&LL,'Z');
  // PrintList( LL );
  // printf("\n------MENGHAPUS ELEMEN  PERTAMA LIST LL------\n");
  // DeleteVFirst(&LL,&X);
  // PrintList(LL);
  // printf("\n------MENGHAPUS ELEMEN  TERAKHIR LIST LL------\n");
  // DeleteVLast(&LL,&X);
  // PrintList(LL);
  // printf("\n------MENGHAPUS ELEMEN U di LIST LL------\n");
  // DeleteX(&LL,'U');
  // PrintList(LL);
  // printf("\n------MENCARI ELEMEN X DI LIST LL------\n");
  // SearchX(LL, 'X', &A);
  // printf("\nElemen yang dicari berada di alamat %p\n", A);
  // printf("\n------MENCARI ELEMEN M DI LIST LL------\n");
  // SearchX(LL, 'M', &A);
  // printf("\nElemen yang dicari berada di alamat %p\n", A);
  // printf("\n------UPDATE NILAI A MENJADI O------\n");
  // UpdateX(&LL,'A','O');
  // PrintList(LL);
  // printf("\n");
  // printf("\n-------------INVERS LIST--------   \n");
  // Invers(&LL);
  // PrintList(LL);
  // printf("\n------MENAMBAHKAN ELEMEN X SETELAH T-----\n");
  // InsertVAfterX(&LL ,'T','X');
  // PrintList(LL);
  // printf("\n------MENAMBAHKAN ELEMEN X SETELAH X-----\n");
  // InsertVAfterX(&LL ,'X','X');
  // PrintList(LL); 
  // printf("\n------MENAMBAHKAN ELEMEN M SETELAH X-----\n");
  // InsertVAfterX(&LL ,'X','M');
  // PrintList(LL);
  // printf("\n------MENAMBAHKAN ELEMEN Y SETELAH O-----\n");
  // InsertVAfterX(&LL ,'O','Y');
  // PrintList(LL);
  // printf("\n------MENAMBAHKAN ELEMEN Y SEBELUM O-----\n");
  // InsertVBeforeX(&LL ,'O','Y');
  // PrintList(LL);
  // printf("\n------MENGHAPUS ELEMEN SETELAH X-----\n");
  // DeleteVAfterX(&LL ,'X',&X);
  // PrintList(LL);
  // printf("\n------MENGHAPUS ELEMEN SETELAH O-----\n");
  // DeleteVAfterX(&LL ,'O',&X);
  // PrintList(LL);
  // printf("\n------MENGHAPUS ELEMEN SEBELUM O-----\n");
  // DeleteVBeforeX(&LL ,'O',&X);
  // PrintList(LL);
  // printf("\n-------------MENGHITUNG JUMLAH ELEMEN X DI LIST--------   \n");
  // printf("\n jumlah elemen di list adalah : %d \n" , CountX(LL,'X'));
  // printf("\n-------------MENGHITUNG FREKUENSI JUMLAH ELEMEN X DI LIST--------   \n");
  // printf("\nRasio Kemunculan elemen tersebut adalah: %f\n", FrekuensiX(LL, 'X'));
  // printf("\n-------------MENCARI MODUS DI LIST LL--------   \n");
  // printf("\nModus list adalah : %c\n",Modus(LL));
  // printf("\n-------------MENCARI INDEKS SEMUA ELEMEN X DI LIST LL--------   \n");
  // printf("\n elemen X ada di indeks :  " );
  // printf ("\t");
  // SearchAllX(LL,'X');
  // printf ("\n");
  printf("\n--------------------------SELESAI TERIMAKASIH ^_^------------------------------------\n");
  return 0;
}
