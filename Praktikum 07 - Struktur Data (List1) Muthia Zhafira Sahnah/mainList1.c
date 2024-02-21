/* File : mainlist1.c */
/* Deskripsi : ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122130071*/
/* Tanggal : 4 NOVEMBER 2023 */
#include <stdio.h>
#include <stdlib.h>
#include "List1.c"
int main()
{ //kamus
  address A; 
  address B;
  address S;
  List1 LL;
  char P;
  infotype X;
  //algoritma
  printf("\n----------------------PRAKTIKUM 07 LIST1------------------------\n");
  printf("\n----------------By : MUTHIA 24060122130071----------------------\n");
  CreateList(&LL);
  Alokasi(&A);
  A->info = 'G';   A->next = NIL; // A diisi G dan Next nya dibuat NIL 
  printf("\n------MENCETAK INFO A-----\n");
  printf("info(A)=%c\t", A->info );
  Alokasi(&B);
  B->info = 'H';   B->next = A; // B diisi H dan next nya diisi A
  printf("\n------MENCETAK INFO B-----\n");
  printf("info(B)=%c\n", B->info );
  LL.First = B; // LL adalah elemen list dimana first nya (awalnnya) adalah B 
  printf("\n------MENGECEK APAKAH LIST KOSONG------\n");
  if (IsEmptyList(LL)){
    printf("\nList Kosong\n");
  }
  else{
    printf("\nList Tidak Kosong\n");
  }
  printf("\n------MENCETAK LIST LL------\n");
  PrintList( LL );
  printf("\n------MENGHITUNG ELEMEN LIST------\n");
  printf( "Jumlah elemen list adalah : %d " ,NbElm(LL) );
  printf("\n------MENAMBAHKAN ELEMEN M KEDEPAN LIST LL------\n");
  InsertVFirst(&LL,'M');
  PrintList( LL );
  printf("\n------MENAMBAHKAN ELEMEN Z KEBELAKANG LIST LL------\n");
  InsertVLast(&LL,'Z');
  PrintList( LL );
  printf("\n------MENGHAPUS ELEMEN  PERTAMA LIST LL------\n");
  DeleteVFirst(&LL,&X);
  PrintList(LL);
  printf("\n------MENGHAPUS ELEMEN  TERAKHIR LIST LL------\n");
  DeleteVLast(&LL,&X);
  PrintList(LL);
  printf("\n------MENCARI ELEMEN H DI LIST LL------\n");
  SearchX(LL, 'H', &A);
  printf("\nElemen yang dicari berada di alamat %p\n", A);
  printf("\n------MENCARI ELEMEN S DI LIST LL------\n");
  SearchX(LL, 'S', &A);
  printf("\nElemen yang dicari berada di alamat %p\n", A);
  printf("\n------UPDATE NILAI G MENJADI O------\n");
  UpdateX(&LL,'G','O');
  PrintList(LL);
  printf("\n");
  printf("-----MENAMBAHKAN ELEMEN A DIAKHIR-----\n");
  InsertVLast(&LL,'A');
  PrintList(LL);
  printf("\n");
  printf("------MENAMBAHKAN ELEMEN A DIAWAL-----\n");
  InsertVFirst(&LL,'A');
  PrintList(LL);
  printf("\n-------------INVERS LIST--------   \n");
  Invers(&LL);
  PrintList(LL);
  printf("\n-------------MENGHITUNG JUMLAH ELEMEN A DI LIST--------   \n");
  printf("\n jumlah elemen di list adalah : %d \n" , CountX(LL,'A'));
  printf("\n-------------MENGHITUNG FREKUENSI JUMLAH ELEMEN A DI LIST--------   \n");
  printf("\nRasio Kemunculan elemen tersebut adalah: %f\n", FrekuensiX(LL, 'A'));
  printf("\n-------------MENCARI MODUS DI LIST LL--------   \n");
  printf("\nModus list adalah : %c\n",Modus(LL));
  printf("\n------MENCETAK LIST LL TERKINI-----\n");
  PrintList(LL);
  printf("\n------MENAMBAHKAN ELEMEN A SETELAH A-----\n");
  InsertVAfter(&LL ,'A','A');
  PrintList(LL);
  printf("\n------MENAMBAHKAN ELEMEN X SETELAH A-----\n");
  InsertVAfter(&LL ,'A','X');
  PrintList(LL);
  printf("\n------MENAMBAHKAN ELEMEN A SETELAH O-----\n");
  InsertVAfter(&LL ,'O','Y');
  PrintList(LL);
  printf("\n-------------MENCARI INDEKS SEMUA ELEMEN A DI LIST LL--------   \n");
  printf("\n elemen A ada di indeks :  " );
  printf ("\t");
  SearchAllX(LL,'A');
  printf ("\n");
  printf("\n--------------------------SELESAI TERIMAKASIH ^_^------------------------------------\n");
return 0;
}

