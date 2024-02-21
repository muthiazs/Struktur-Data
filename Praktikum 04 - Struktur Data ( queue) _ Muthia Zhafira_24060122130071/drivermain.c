/***********************************/
/* Program   : drivermain.c */
/* Deskripsi : header file modul boolean */
/* NIM/Nama  :  24060122130071 Muthia Zhafira Sahnah*/
/* Tanggal   : 22 eptember 2023 */
/***********************************/

#include "tqueue.c"
#include "boolean.h"
#include <stdio.h>

int main(){

    //kamus
    tqueue A;
    tqueue B;
    char X;

    //Algoritma
    printf("------PRAKTIKUM KE-4 QUEUE------\n");
    printf("        Membentuk Queue  A       \n");
    printf("--------------------------------\n");
    createQueue(&A);
    head(A)= 1;
    tail(A) = 3;
    A.wadah[1] = 'a';
    A.wadah[2] = 't';
    A.wadah[3] = 'h';
    printf("\n--------------------------------\n");
    printf("Mencetak semua isi wadah : ");
    printQueue(A);
    printf("\n--------------------------------\n");
    printf("Mencetak elemen tak kosong : ");
    viewQueue(A);

    printf("\n--------------------------------\n");
    printf("Mengecek posisi Head sekarang= %d", head(A));
    printf("\n--------------------------------\n");
    printf("Mengecek posisi Tail sekarang= %d", tail(A));
    printf("\n--------------------------------\n");
    printf("Mengecek info nilai Head= %c", infoHead(A));
    printf("\n--------------------------------\n");
    printf("Mengecek info nilai Tail= %c", infoTail(A));
    printf("\n--------------------------------\n");
    printf("Mengecek ukuran antrian = %d", sizeQueue(A));
    printf("\n--------------------------------\n");
    printf("Mengecek apakah antrian penuh  ?  \n");
    if(isFullQueue(A)){
        printf("Ya, antrian penuh");
    }
    else{
        printf("Tidak, antrian tidak penuh");}   
    printf("\n--------------------------------\n");
    printf("Mengecek apakah antrian kosong ?  \n");
    if(isEmptyQueue(A)){
        printf("Ya, antrian kosong");
    }
    else{
        printf("Tidak, antrian tidak kosong");
    }
    printf("\n--------------------------------\n");
    printf("Mengecek apakah antrian berisi 1 elemen saja ?  \n");
    if(isOneElement(A)){
        printf("Ya, hanya terdapat 1 elemen");
    }
    else{
        printf("Tidak, ada lebih dari satu elemen");
    }
    printf("\n--------------------------------\n");
    printf("Menambahkan elemen kedalam queue\n");
    enqueue(&A,'i');
    enqueue(&A,'a');
    enqueue(&A,'a');
    printf("stack setelah di enque : \n");
    viewQueue(A);
    printf("\n--------------------------------\n");
    printf("Mengurangi elemen kedalam queue\n");
    dequeue(&A,&X);
    printf("stack setelah di dequeue : \n");
    printQueue(A);

    printf("\n--------------------------------\n");
    printf("       Membentuk Queue  B       \n");
    printf("--------------------------------\n");
    createQueue(&B);
    enqueue(&B,'z');
    enqueue(&B,'h');
    enqueue(&B,'a');
    enqueue(&B,'f');
    enqueue(&B,'i');
    printf("Menampilkan queue B       \n");
    viewQueue(B);  
 
    printf("\n--------------------------------\n");
    printf("\nMembandingkan antrean satu dengan yang lain   \n");
    printf("\nJumlah antrean terpanjang adalah= %d  \n",maxlength(A,B));
    printf("\nMengecek ukuran antrian A = %d", sizeQueue(A));
    printf("\nMengecek ukuran antrian B = %d", sizeQueue(B));
    printf("\n--------------------------------\n");
    printf("\nmenambah elemen wadah pada antrian terpendek dari A atau B\n");
    enqueue2(&A,&B,'w');
    printf("\n Menampilkan queue A       \n");
    viewQueue(A);
    printf("\nMenampilkan queue B       \n");
    viewQueue(B);
     printf("\nmengurangi elemen wadah pada antrian terpanjang dari A atau B\n");
    dequeue2(&A,&B,&X);
    printf("\n Menampilkan queue A       \n");
    viewQueue(A);
    printf("\nMenampilkan queue B       \n");
    viewQueue(B);

    // return 0;
}