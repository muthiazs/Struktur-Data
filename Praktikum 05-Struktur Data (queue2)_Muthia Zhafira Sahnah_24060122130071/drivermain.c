/***********************************/
/* Program   : drivermain.c */
/* Deskripsi :  ADT Queue representasi kontigu dengan array, 
 model II: head bergeser/jelajah */
/* NIM/Nama  :  24060122130071 Muthia Zhafira Sahnah*/
/* Tanggal   : 29 eptember 2023 */
/***********************************/

#include "tqueue2.c"
#include "boolean.h"
#include <stdio.h>

int main(){
    //Kamus Lokal 
    tqueue2 A; 
    tqueue2 B;
    char X;
    //Algoritma 
    printf("\n-----PRAKTIKUM 5 QUEUE 2 ------\n");
    printf("        Membentuk Queue  A       \n");
    printf("---------------------------------\n");
    createQueue2(&A);
    A.head=1;
    A.tail=3;
    A.wadah[1]='a';
    A.wadah[2]='b';
    A.wadah[3]='c';
    printQueue2(A);
    printf("\n");
    printf("\nMengecek apakah Queue  kosong? \n");
    if (isEmptyQueue2(A)){
        printf("Ya queue kosong");
    } 
    else {
        printf("queue tidak kosong");
    }
    printf("\n-------------------------------\n");
    printf("\nMengecek apakah Queue penuh ?\n");
    if(isFullQueue2(A)){
        printf("Ya queue penuh");
    }
    else{
        printf("queue tidak penuh");
    }
    printf("\n---------------------------------\n");
    printf("\nMengecek apakah elemen Queue 1 ? \n");
    if (isFullQueue2(A)){
        printf("Ya elenmen dalam queue hanya 1");
    }
    else {
        printf("isi queue tidak hanya 1");
    }
    printf("\n---------------------------------\n");
    printf("\nPosisi Head ada di : %d \n" , head2(A) );
    printf("\n---------------------------------\n");
    printf("\nPosisi Tail ada di : %d \n" , tail2(A) );
    printf("\n---------------------------------\n");
    printf("\nNilai Head : %c \n" , infoHead2(A) );
    printf("\n---------------------------------\n");
    printf("\nNilai Tail : %c \n" , infoTail2(A) );
    printf("\n---------------------------------\n");
    printf("\nPanjang Queue : %d \n" , sizeQueue2(A) );
    printf("\n---------------------------------\n");
    printf("\nMenambahkan elemen kedalam queue\n");
    enqueue2(&A,'d');
    enqueue2(&A,'e');


    printQueue2(A);
    printf("\n---------------------------------\n");
    printf("\nMengurangi elemen queue\n");
    dequeue2(&A,&X);
    dequeue2(&A,&X);
    dequeue2(&A,&X);
    printQueue2(A);
    printf("\n---------------------------------\n");
    printf("\nTambahkan elemen sebanyak 3 kali !\n");
    enqueue2N(&A,3);
    printf("\n---------------------------------\n");
    printf("\nMengurangi elemen queue A\n");
    dequeue2(&A,&X);
    printQueue2(A);
    printf("\n---------------------------------\n");
    printf("\nMembuat queue B\n");
    printf("\nTambahkan elemen sebanyak 4 kali !\n");
    createQueue2(&B);
    enqueue2N(&B,4);
    printQueue2(B);
    printf("\n-----------------------------------------------\n");
    printf("\n Mengecek apakah elemen A dan B sama atau tidak\n");
    printf("\n");
    printQueue2(A);
    printf("\n");
    printQueue2(B);
    printf("\n");
    if(isEqualQueue2(A,B)){
        printf("Ya queue A dan B sama");
    }
    else{
        printf("Tidak sama");
    }
    return 0;
}
    
