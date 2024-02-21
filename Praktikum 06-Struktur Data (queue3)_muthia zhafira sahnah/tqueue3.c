#include <stdio.h>
#include "tqueue3.h"
#include "boolean.h"

#ifndef TQUEUE3_C
#define TQUEUE3_C

/*function isEmptyQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue3(tqueue3 Q){
    //Kamus Lokal
    //Algoritma 
    return (Q.head == 0 && Q.tail == 0);
}
 
/*function isFullQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue3(tqueue3 Q){
   return ( (Q.head - 1) == (Q.tail) && Q.head == 1 && Q.tail == 10);
}

/*function isOneElement3(Q:tQueue3) -> boolean
{mengembalikan true jika Q 1 elemen}*/
boolean isOneElement3(tqueue3 Q){
    return ((Q.head == Q.tail) && (!isEmptyQueue3(Q)));
}

/*procedure createQueue3 ( output Q:tQueue3)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='#'}*/ 
void createQueue3(tqueue3 *Q){
    //Kamus Lokal 
    int i; 
    //Algoritma 
    for (i=1;i<=5;i++){
        (*Q).wadah[i] = '#';
    }
    (*Q).head = 0; 
    (*Q).tail = 0;
}

/*Function Head3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terdepan} */
int head3(tqueue3 Q){
    return (Q).head;
}

/*Function Tail3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terakhir} */
int tail3(tqueue3 Q){
    return (Q).tail;
}

/*Function InfoHead3(Q:tqueue3) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead3(tqueue3 Q){
    return Q.wadah[head3(Q)];
}

/*Function InfoTail3(Q:tqueue3) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail3(tqueue3 Q){
    return Q.wadah[tail3(Q)];
}

/*function sizeQueue3(Q:tQueue3)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue3(tqueue3 Q){
    if(isEmptyQueue3(Q)) {
        return 0;
    } else if(isOneElement3(Q)) {
        return 1;
    } else if(Q.head <= Q.tail) {
        return (Q.tail - Q.head + 1);
    } else { // when tail has wrapped around
        return (5 - Q.head + Q.tail + 1);
    }
}


/*procedure printQueue3(input Q:tQueue3)
\\{I.S.: Q terdefinisi}
\\{F.S.: -}
\\{proses: mencetak isi wadah ke layar, berisi atau kosong}*/
void printQueue3(tqueue3 Q){
    //Kamus Lokal
    int i;

    //Algoritma
    for(i = 1; i <= 5; i++){
        printf("%c ", Q.wadah[i]);
}
}

/*procedure viewQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue3(tqueue3 Q){
    //Kamus Lokal
    int count; 
    int i; 
    //Algoritma 
    count = 0; 
    i = head3(Q); 
    while (count < sizeQueue3(Q)){
        printf("%c ", Q.wadah[i]);
        if ( i == 5){
            i = 0; 
        }
        i++;
        count++;
    }
}

/*procedure enQueue3( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 } */
void enqueue3(tqueue3 *Q, char E){
    //Kamus Lokal 
    //Algoritma 
    if (isFullQueue3(*Q)){
        printf("\nQueue sudah penuh\n");
    }
    else{
        if(isEmptyQueue3(*Q)){
            (*Q).head = 1; }
        else if((*Q).tail == 5){
            (*Q).tail = 0; 
       }
       (*Q).tail++;
       (*Q).wadah[tail3(*Q)] = E;
    }
}

/*procedure deQueue3( input/output Q:tQueue3,output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q), bila kosong E=' '}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue3(tqueue3 *Q, char *E){
    //Kamus Lokal 
    //Algoritma 
    if(isEmptyQueue3(*Q)){
        printf("Queue Kosong");
    }
    else{
        *E = infoHead3(*Q);
        (*Q).wadah[head3(*Q)] = '#';
        if(isOneElement3(*Q)){
            (*Q).head=0;
            (*Q).tail=0;
        }
        else if((head3(*Q)==5) && ((*Q).tail != 5)){
            (*Q).head = 1;
        }
        else{
            (*Q).head++;
        }
    }
}

/*EKSTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*function isTailOverHead(Q:tQueue3) -> boolean
{mengembalikan true jika tail berada di depan head}*/
boolean isTailOverHead(tqueue3 Q){
    return tail3(Q)<head3(Q);
}

/*function countMember(Q:tQueue3, E:character) -> integer
{mengembalikan banyaknya nilai E dalam antrian Q}*/
int countMember(tqueue3 Q, char E) {
    int count = 0;
    int i;

    for(i = 1; i <= 5; i++) {
        if(Q.wadah[i] == E) {
            count++;
        }
    }
    return count;
}

/*procedure enQueue3E( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 dengan syarat nilai E belum ada di Q} */
void enqueue3E(tqueue3 *Q, char E){
    //Kamus Lokal
    //Algoritma  
    if(isFullQueue3(*Q)){
        printf("\n\nQueue Penuh");
    }
    else{
        if(countMember((*Q),E) == 0){
            enqueue3(Q,E);
        }
        else{
            printf("\nElemen sudah ada");
 }
 }
}

#endif