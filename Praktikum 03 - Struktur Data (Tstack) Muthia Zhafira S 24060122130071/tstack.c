/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 2060122130071 Muthia Zhafira Sahnah */
/* Tanggal   : 16 September 2023*/
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T){
    //Kamus Lokal
    int i;

    //Algoritma
    for (i = 1; i<=10; i++){
        (*T).wadah[i]='#';
    }
    (*T).top = 0;
}

/*function top( T: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
//int top (Tstack T);
//dalam praktikum ini, fungsi dapat direalisasikan
//menjadi macro dalam bahasa C.
#define top(T) (T).top

/*function infotop( T: Tstack) -> character
	{mengembalikan nilai elemen top stack } */
//char infotop (Tstack T);
#define infotop(T) (T).wadah[(T).top]

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T){
    // Kamus Lokal
    
    //Algoritma
    return T.top == 0; 
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T){
    //Kamus Lokal
    
    //Algoritma
    return T.top == 10 ;
}
    
/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E){
    if (isFullStack(*T)) {
        printf("Stack sudah penuh\n");
    }
    else {
        (*T).top++;
        (*T).wadah[(*T).top] = E;
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X){
    if(isEmptyStack(*T)){
        printf("stack kosong");
    }
    else{
        (*X) = infotop(*T);
        (*T).wadah[top(*T)] ='#';
        (*T).top = top(*T)--;
    }
    
}


/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T){
    //Kamus Lokal
    int i;
    
    //Algoritma
    
    if (isEmptyStack(T)) {
        printf("Stack Kosong \n");
    }
    else {
        for (i=1;i<=10;i++){
         if (i < 10) {
            printf("%c;", T.wadah[i] );
        }
         else if (i = 10) {
             printf("%c", T.wadah[i] );
         }
        
    }
}
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T){
    //Kamus Lokal 
    int i; 
    
    //Algoritma 
    if (isEmptyStack(T)) {
        printf("Stack Kosong \n");
    }
    else {
        for (i=1;i<=10;i++){
            if (i < top(T) && T.wadah[i] != '#')
        {
            printf("%c;", T.wadah[i] );
        } 
        else if (i == top(T) && T.wadah[i] != '#') {
            printf("%c", T.wadah[i] );
        }
    }
}
}

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N){
    //Kamus Lokal 
    int i; 
    //Algoritma 
    if ( top(*T) + N <= 10 ){
        printf("\nMasukkan nilai yg ingin di push :\n");
        for (i=1;i<=N;i++){
          (*T).top++;
          scanf("%c",&(*T).wadah[(*T).top]);
        }
    }
    else {
        printf("stack sudah penuh");
    }
}

/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) bila belum penuh atau menjadi kosong bila stack penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1 (Tstack *T, char E){
    //Kamus lokal
    int i;
    //Algoritma
    if (isFullStack(*T)){
        (*T).top = 0;
        for(i=1; i<=10; i++){
            (*T).wadah[i] = '#';
        }
    }else{
        (*T).top++;
        (*T).wadah[(*T).top] = E;
    }
}


/*procedure pushZuma ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau berkurang 1 elemen bila E bernilai sama dengan top }
	{Proses: menumpuk top atau menghapus elemen top }
    {contoh: T=['A','B','C'], E='C' menjadi T=['A','B']}*/
void pushZuma (Tstack *T, char E){
    if(infotop(*T)==E){
        (*T).wadah[top(*T)] = '#';
        (*T).top = top(*T)--;
    }
    else{
        (*T).top++;
        (*T).wadah[top(*T)] = 'E';
    }
}



