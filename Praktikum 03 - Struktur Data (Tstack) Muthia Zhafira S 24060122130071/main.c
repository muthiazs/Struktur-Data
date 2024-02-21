/* Program   : main.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 2060122130071 Muthia Zhafira Sahnah */
/* Tanggal   : 16 September 2023*/
/***********************************/
#include <stdio.h>
#include <string.h>
#include "tstack.h"
#include "boolean.h"

boolean isPalindrom (Tstack T){
    /*Kamus*/
    int i,j;
    boolean check;

    /*Algoritma*/
    check = true;
    i = 1;
    j = T.top;
    while (i<=T.top/2){
        if (T.wadah[i] != T.wadah[j]){
            check = false;
        }
        i++;
        j--;
    }
    return check;
}

int main(){

    Tstack T;
    Tstack A;
    char X;
    int N;

    //Algoritma
    printf("\n\n----PRAKTIKUM TSTACK----\n");
    
	printf("\n\n-----Create Stack T-----\n");
    createStack(&T);
    top(T) = 2;
    T.wadah[1] = 'm';
    T.wadah[2] = 'a';
    printStack(T);
    
    printf("\n--------------------------------\n");
    printf("  PUSH Mengisi Elemen Top Baru  \n");
    printf("--------------------------------\n");
    push(&T, 'l');
    printf("PrintStack : \n");
    printStack(T);
    
    printf("\n--------------------------------\n");
    printf("   POP Mengambil Elemen Top     \n");
    printf("--------------------------------\n");
    pop(&T, &X); 
    printf("Isi Stack Sekarang : \n");
    viewStack(T);
    
    
    printf("\n--------------------------------\n");
    printf("     Cek Apakah Stack Penuh     \n");
    printf("--------------------------------\n");
    if(isFullStack(T)){
        printf("Ya, stack penuh");
    }
    else{
        printf("Tidak, stack tidak penuh");}
    
    printf("\n--------------------------------\n");
    printf("     Cek Apakah Stack Kosong    \n");
    printf("--------------------------------\n");
    if(isEmptyStack(T)){
        printf("Ya, stack kosong");
    }
    else{
        printf("Tidak, stack tidak kosong");
    }
   
    printf("\n--------------------------------\n");
    printf("\n        PUSH N               \n");
    printf("--------------------------------\n");
    printf("masukkan nilai tanpa spasi, ex: can");
    pushN(&T,3);
    printf("stack setelah di push sebanyak N kali:\n");
    viewStack(T);
   
    
    printf("\n--------------------------------\n");
    printf("\n        PUSH BABEL               \n");
    printf("--------------------------------\n");
    pushBabel1(&T, 'x');
    printf("Pushbabel : \n");
    viewStack(T);
    
    
    printf("\n--------------------------------\n");
    printf("\n        PUSH ZUMA               \n");
    printf("--------------------------------\n");
    pushZuma(&T, 'x');
    printf("Push zuma : \n");
    viewStack(T);
    
    printf("\n\n-----Create Stack A -----\n");
    createStack(&A);
    top(A) = 5;
    A.wadah[1] = 'k';
    A.wadah[2] = 'a';
    A.wadah[3] = 't';
    A.wadah[4] = 'a';
    A.wadah[5] = 'k';
    printf("\nviewStack : \n");
    viewStack(A);
    printf("\n");
    printStack(A);
    printf("\n\n-----Mengecek apakah Palindrom?-----\n");
    if(isPalindrom(A)){
        printf("\nYa, stack A merupakan kata palindrom");

    }else{
        printf("\nSalah, stack A bukan merupakan kata palindrom");
    }

	return 0;
 
}
    
