/***********************************/
/* Program   : drivermain.c */
/* Deskripsi :  ADT Queue representasi kontigu dengan array, 
 model II: head bergeser/jelajah */
/* NIM/Nama  :  24060122130071 Muthia Zhafira Sahnah*/
/* Tanggal   : 29 eptember 2023 */
/***********************************/

#include "tqueue3.c"
#include "boolean.h"
#include <stdio.h>

int main(){
    //Kamus Lokal 
    tqueue3 A; 
    tqueue3 B;
    char X;
     //Algoritma 
    printf("\n-----PRAKTIKUM 6 QUEUE 3 ------\n");
    printf("        Membentuk Queue  A       \n");
    printf("---------------------------------\n");
    createQueue3(&A);
    A.head=1;
    A.tail=3;
    A.wadah[1]='a';
    A.wadah[2]='b';
    A.wadah[3]='c';
    printQueue3(A);
    printf("\n");
    viewQueue3(A);
    printf("\n");
    printf("\nMengecek apakah Queue  kosong? \n");
    if (isEmptyQueue3(A)){
        printf("Ya queue kosong");
    } 
    else {
        printf("queue tidak kosong");
    }
    printf("\n-------------------------------\n");
    printf("\nMengecek apakah Queue penuh ?\n");
    if(isFullQueue3(A)){
        printf("Ya queue penuh");
    }
    else{
        printf("queue tidak penuh");
    }
    printf("\n---------------------------------\n");
    printf("\nMengecek apakah elemen Queue 1 ? \n");
    if (isFullQueue3(A)){
        printf("Ya elemen dalam queue hanya 1");
    }
    else {
        printf("isi queue tidak hanya 1");
    }
    printf("\n---------------------------------\n");
    printf("\nPosisi Head ada di : %d \n" , head3(A) );
    printf("\n---------------------------------\n");
    printf("\nPosisi Tail ada di : %d \n" , tail3(A) );
    printf("\n---------------------------------\n");
    printf("\nNilai Head : %c \n" , infoHead3(A) );
    printf("\n---------------------------------\n");
    printf("\nNilai Tail : %c \n" , infoTail3(A) );
    printf("\nPanjang Queue : %d \n" , sizeQueue3(A) );
    printf("\n---------------------------------\n");
    
    
    printf("\nMenambahkan elemen kedalam queue\n");
    enqueue3(&A,'d');
    enqueue3(&A,'e');
    printQueue3(A);
    printf("\n---------------------------------\n");
    printf("\nMengurangi elemen queue\n");
    dequeue3(&A,&X);
    dequeue3(&A,&X);
    printQueue3(A);
    printf("\n");
    viewQueue3(A);
    printf("\n");
    enqueue3(&A,'d');
    printQueue3(A);
    printf("\n");
    viewQueue3(A);
    printf("\n---------------------------------\n");
    printf("\nPosisi Head ada di : %d \n" , head3(A) );
    printf("\n---------------------------------\n");
    printf("\nPosisi Tail ada di : %d \n" , tail3(A) );
    printf("\n---------------------------------\n");
    printf("\nMengecek apakah tail berada didepan head ? \n");
    if(isTailOverHead(A)){
        printf("Ya");
    }
    else{
        printf("Tidak");
    }
    printf("\n---------------------------------\n");
    printf("\nAda berapa char 'd' di queue: %d \n" , countMember(A,'d'));
    printf("\n---------------------------------\n");
    printf("\nMenambahkan elemen kedalam queue menggunakan enqueue3E\n");
    enqueue3E(&A,'d');
    printf("\n");
    printQueue3(A);
     enqueue3E(&A,'f');
    printf("\n");
    printQueue3(A);
    return 0;
}
    
