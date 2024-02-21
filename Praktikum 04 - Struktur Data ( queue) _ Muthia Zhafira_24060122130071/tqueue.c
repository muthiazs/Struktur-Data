/***********************************/
/* Program   : tqueue.c */
/* Deskripsi : header file modul boolean */
/* NIM/Nama  : 24060122130071  Muthia Zhafira Sahnah */
/* Tanggal   : 22 September 2023  */
/***********************************/
#include <stdio.h>
#include "tqueue.h"
#include "boolean.h"

#ifndef TQUEUE_C
#define TQUEUE_C

/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan huruf '$', head=tail=0 }*/ 
void createQueue(tqueue *Q){
     //Kamus lokal
    int i;
    //Algoritma
    (*Q).head=0;
    (*Q).tail=0;
    for (i=1; i<=5;i++) {
        (*Q).wadah[i] = '$';
    }
}

/*function Head(Q:tQueue)-> integer 
{mengembalikan posisi elemen terdepan antrian Q} */
//int Head(tqueue Q);
#define head(Q) (Q).head //implementasi fisik macro

/*function Tail(Q:tQueue)-> integer 
{mengembalikan posisi elemen terakhir antrian Q} */
//int Tail(tqueue Q);
#define tail(Q) (Q).tail //implementasi fisik macro

/*function infoHead(Q:tQueue)-> character 
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
char infoHead(tqueue Q){
    return (Q).wadah[head(Q)];
}

/*function infoTail(Q:tQueue)-> character 
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
char infoTail(tqueue Q){
    return (Q).wadah[tail(Q)];
}

/*function sizeQueue(Q:tQueue)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue(tqueue Q){
    return (Q).tail;
}

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue Q){
    //Kamus lokal
    int i;
    //Algoritma
    for (i=1; i<=5; i++) {
        printf(" %c ",Q.wadah[i]) ;
    }
}

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(tqueue Q){
        //Kamus lokal
    int i;
    //Algoritma
    if (isEmptyQueue(Q)){
        printf("antrian kosong");
    }
    else{
    for (i=1; i<=5; i++) {
        if (Q.wadah[i]!='$'){
            printf(" %c ",Q.wadah[i]) ;
            }
    }
}}

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q){
    //Kamus Lokal

    //Algoritma
    if(Q.head == 0 && Q.tail == 0){
        return true;
    }
    else{
        return false;
    }
}

/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q){
    //Kamus lokal
    //Algoritma
    if (Q.tail==5 && Q.head==1){
        return true;
    }
    else {
        return false;
    }
}

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q){
    if (sizeQueue(Q)==1){
        return true;
    }
    else {
        return false;
    }
}

/*procedure enqueue( input/output Q:tQueue, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, char E){
     // kamus lokal

    // algoritma
    if (!isFullQueue(*Q)) {
        if (isEmptyQueue(*Q)) {
            (*Q).head += 1;
        }
        (*Q).tail += 1;
        (*Q).wadah[(*Q).tail] = E;
    }
    else{
        printf("queue sudah penuh !");
    }
    }
  
/*procedure deQueue( input/output Q:tQueue, output E: character )
{I.S.: }
{F.S.: E=infohead(Q) atau E=' ' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue *Q, char *E){
    // Kamus Lokal
    int i;
    
    //Algoritma
    if (isEmptyQueue(*Q)) {
        printf("antrian kosong");
    }
    else {
        (*E)=infoHead(*Q);
        if ((*Q).tail == 1){
            (*Q).head--;
        }
        else{
            for (i=1;i<=(*Q).tail;i++){
                (*Q).wadah[i] = (*Q).wadah[i+1];
            }
        }
        (*Q).wadah[(*Q).tail] = '$';
        (*Q).tail--;
}
}


/*function maxlength(Q1:tqueue, Q2:tqueue) --> integer */
/*{mengembalikan ukuran yang terpanjang dari 2 antrian}*/
int maxlength(tqueue Q1, tqueue Q2){
    // kamus lokal 

    //algoritma 
    if (sizeQueue(Q1)>sizeQueue(Q2)){
        return sizeQueue(Q1);
    }
    else{
        return sizeQueue(Q2);
    }
    //diasumsikan apabila panjang sama akan mengembalikan antrian Q2
}

/*procedure enqueue2( input/output Q1:tQueue, input/output Q2:tQueue, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q1 atau Q2 bertambah 1, bila belum penuh}
{proses: menambah elemen wadah pada antrian terpendek dari Q1 atau Q2} */
void enqueue2(tqueue *Q1, tqueue *Q2, char E){
        if (sizeQueue(*Q1) < sizeQueue(*Q2)){
            enqueue(Q1,E);
        }
        else if (sizeQueue(*Q2)<sizeQueue(*Q1)) {
            enqueue(Q2,E);
        }
        else {
            printf("dua antrian penuh");
        }
    }

/*procedure deQueue2( input/output Q1:tQueue, input/output Q2:tQueue, output E: character )
{I.S.: }
{F.S.: E=infohead Q1 atau Q2 atau E=' ' bila Q1 dan Q2 kosong, elemen wadah Q1 atau Q2 berkurang 1 }
{proses: mengurangi elemen wadah antrian terpanjang Q1 atau Q2, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail antrian menjadi 0 } */
void dequeue2(tqueue *Q1, tqueue *Q2, char *E){
    if (sizeQueue(*Q1) > sizeQueue(*Q2)){
            dequeue(Q1,E);
        }
        else if (sizeQueue(*Q2)>sizeQueue(*Q1)) {
            dequeue(Q2,E);
        }
        else if (sizeQueue(*Q2)==sizeQueue(*Q1)){  
            dequeue(Q2,E); //diasumsikan kalo jumlah nya sama akan menambahkan ke q2
        }
        else {
            printf("dua antrian penuh");
        }
}


#endif