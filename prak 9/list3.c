/* File : list3.c */
/* Deskripsi : ADT list berkait sirkular dengan representasi fisik pointer */
/* NIM & Nama : 24060122130071 Muthia Zhafira Sahnah*/
/* Tanggal : 17 NOVEMBER 2023 */

#ifndef list3_c
#define list3_c

#include <stdio.h>
#include "list3.h"

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List3 *L){
    /*Kamus Lokal*/
    /*Algoritma*/
    L->First = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List3 L){
    /*Kamus Lokal*/
    /*Algoritma*/
    return L.First == NIL;
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List3 L){
    /*Kamus Lokal*/
    address P;
    /*Algoritma*/ 
    P = First(L);
    do {
        printf("%c\t", info(P));
        P = next(P);
    } while ( P!= NIL && P != First(L));  
}

/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L){
    /*KAMUS LOKAL*/
    address P;
    int Nb;
    /*ALGORITMA*/
    Nb = 0;
    P = First(L);
    if (P != NIL)
    {
        Nb = 1;
        while (next(P) != First(L))
        {
            Nb = Nb + 1;
            P = next(P);
        } 
    }
    return Nb;
}

/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* procedure Alokasi (output P:address) */ 
/* {I.S. - 
    F.S. P ter-alokasi 
	Proses: Memesan ruang memori untuk address P} */
void Alokasi (address *P){
    /*Kamus Lokal*/
    /*Algoritma*/
    (*P) = (address) malloc ( sizeof (ElmList3) );
} //representasi fisik prosedur
//address Alokasi(); //representasi fisik fungsi
 
/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P){
    /*Kamus Lokal*/
    /*Algoritma*/
     free (*P);
     (*P) = NIL;
}

/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V) {
    /*Kamus Lokal*/
    address P;
    address last;
    /*Algoritma*/
    Alokasi(&P);
    info(P) = V;
    if (First(*L) == NIL) /*List Kosong*/
       {
            First(*L) = P;
            next(P)= First(*L);
        } 
    else 
        { /*List tidak kosong*/
            last = First(*L);
            while (next(last) != First(*L)) {
                last = next(last);
            }
            /*next(last)=first(L)*/
            next(last) = P;
            next (P) = First(*L);
            First(*L) = P;
        }
    }

/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V ){
    /*Kamus Lokal*/
    address P;
    address last;
    /*Algoritma*/
    Alokasi(&P);
    if (P != NIL)
    {
        info(P) = V;
        if (First(*L) == NIL){
            First(*L) = P;
            next(P)=P;
        }
        else
        {
            last = First(*L);
            while (next(last) != First(*L))
            {
                last = next(last);
            }
            next(last) = P;
            next(P) = First(*L);
        }
    }

}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V){
    /*Kamus Lokal*/
    address last;
    address P;
    /*Algoritma*/
    if(next(First(*L)) == First(*L)){
        First(*L)=NIL;
    }
    else
    {
        P = First(*L);
        last = First(*L);
        while (next(last) != First(*L))
        {
            last = next(last);
        }
        *V = info(P);
        next(last)= next(P);
        First(*L) = next(P);
        Dealokasi(&P);
    }
}

/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V){
    /*Kamus Lokal*/
    address P; /*Penjelajah*/
    address last; /*Elemen Terakhir*/
    /*Algoritma*/
    if (First(*L) != NIL) /*List tidak kosong*/
    {
        P = First(*L);
        if(next(First(*L))==First(*L)) /*Kasus 1 elemen*/
        {
            (*V) = info(P);
            First(*L) = NIL;
        }
        else /*Kasus lebih dari 1 elemen*/
        {
            last = next(P);
            while (next(last) != First(*L))
            {
                P = last;
                last = next(last);
            }
            next(P) = First(*L);
            (*V) = info(last);
            Dealokasi(last);
        }
    }
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteX(List3 *L, infotype X){
    /*Kamus Lokal*/
    address P; /*ELEMEN X*/
    address prev; /*ELEMEN SEBELUM X*/
    infotype V;
    /*Algoritma*/
    if (!IsEmptyList(*L))
    {
        P = First(*L);
        while (info(P) != X && next(P) != First(*L))
        {
            prev = P;
            P = next(P);
        }
        if (info(P) == X)
        {
            if(NbElm(*L) == 1)
            {
                DeleteVFirst(L,&V);
            }
            else 
            {
              if ( P == First(*L))
                {
                    DeleteVFirst(L,&V);
                }
              else
                {
                    if(next(P) == First(*L)){
                        DeleteVLast(L,&V);
                    }
                    else 
                    {
                        V = info(P);
                        next(prev) = next(P);
                        Dealokasi(&P);
                    }
                }
            }
        }
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A){
    /*Kamus Lokal*/
    address P; 
    /*Algoritma*/
    if (First(L) != NIL)
    {
        P = First(L);
        while (next(P) != First(L) && info(P) != X)
        {
            P = next(P);
        }
        if (info(P) == X){
            *A = P;
        }
        else
        {
            *A = NIL;
        }  
    } 
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List3 *L, infotype X, infotype Y){
    /*Kamus Lokal*/
    address P;
    /*Algoritma*/
        if (First(*L) != NIL)
    {
        P = First(*L);
        while (next(P) != First(*L) && info(P) != X)
        {
            P = next(P);
        }
        if (info(P) == X){
            info(P) = Y;
        }
    } 
}   

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L){
    /*Kamus Lokal*/
    address P;
    List3 Lo;
    /*Algoritma*/
    CreateList(&Lo);
    P = First(*L);
    do{
        InsertVFirst(&Lo, info(P));
        P = next(P);
    }while (P != First(*L));
    (*L) = Lo;    
}

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X){
    /*Kamus Lokal*/
    address P;
    int count;
    /*Algoritma*/
    count = 0;
    P = First(L);
    if ( P != NIL){
        do{
            if (info(P) == X)
            {
                count = count + 1;
            }
            P = next(P);
        }while (P != First(L));   
    }
    return count;
}

/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List3 L, infotype X){
    return(float)CountX(L,X)/NbElm(L);
}

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List3 L){
    /*Kamus Lokal*/
    infotype max;
    int frekuensiMax = 0;
    address P;
    /*Algoritma*/
    P = First(L);
    if (P != NIL){
        do{
            if (CountX(L, info(P)) > frekuensiMax)
            {
                frekuensiMax = CountX(L, info(P));
                max = info(P);
            }
            P = next(P);
        }while (P != First(L));   
    }
    return max;
}

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L){
    /*Kamus Lokal*/
    address P;
    int count;
    /*Algoritma*/
    count = 0;
    P = First(L);
    if (P != NIL){
        do{
            if (info(P) == 'a' || info(P) == 'e' || info(P) == 'i' || info(P) == 'o' || info(P) == 'u' ||
                info(P) == 'A' || info(P) == 'E' || info(P) == 'I' || info(P) == 'O' || info(P) == 'U')
            {
                count = count + 1;
            }
            P = next(P);
        }while (P != First(L));   
    }
    return count;
}

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L){
    /*Kamus Lokal*/
    address P;
    int count;
    /*Algoritma*/
    count = 0;
    P = First(L);
    if (P != NIL){
        do{
            if (info(P) == 'N' && info(next(P)) == 'G')
            {
                count = count + 1;
            }
            P = next(P);
        }while (P != First(L));   
    }
    return count;
}

/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V){
    /*Kamus Lokal*/
    address P; /*Posisi V elemen baru*/
    address Q; /*Posisi X*/
    /*Algoritma*/
    if (First(*L) != NIL)
    {
        Q = First(*L);
        while (next(Q) != First(*L) && info(Q) != X)
        {
            Q = next(Q);
        }
        if (info(Q) == X)
        {
            Alokasi(P);
            if(P != NIL){
                info(P) = V;
                next(P) = next(Q);
                next(Q)=P;
            }
        } 
    }
}

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V){
    //Kamus Lokal
    address P;
    address Q;
    address prec;

    //Algoritma 
    if(First(*L) != NIL) {
        Q = First(*L);
        while(next(Q) != First(*L) && info (Q) != X){
            prec = Q;
            Q = next (Q);
        }
        if (info(Q) == X) {
            Alokasi(&P);
            if (P!= NIL) {
                info (P) = V;
                next (P) = Q;
                next (prec) = P;
            }
}
}
}


/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V){
    /*Kamus Lokal*/
    address P, Q;
    /*Algoritma*/
    P = First(*L);
    if (P != NIL){
        do{
            if (info(P) == X)
            {
                Q = next(P);
                if (Q != NIL){
                    *V = info(Q);
                    next(P) = next(Q);
                    Dealokasi(&Q);
                }
                break;
            }
            P = next(P);
        }while (P != First(*L));   
    }
}

/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V){
    /*Kamus Lokal*/
    address P, Q, R;
    /*Algoritma*/
    P = First(*L);
    if (P != NIL){
        R = P;
        while (next(R) != First(*L)){
            R = next(R);
        }
        do{
            if (info(next(P)) == X)
            {
                Q = P;
                *V = info(Q);
                if (Q == First(*L)){
                    First(*L) = next(Q);
                    next(R) = next(Q);
                } else {
                    next(R) = next(Q);
                }
                Dealokasi(&Q);
                break;
            }
            R = P;
            P = next(P);
        }while (P != First(*L));   
    }
}

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
void SearchAllX(List3 L, infotype X){
    /*Kamus Lokal*/
    address P;
    int position = 1;
    int count = 0;
    /*Algoritma*/
    P = First(L);
    if (P != NIL){
        do{
            if (info(P) == X)
            {
                printf("%d ", position);
                count++;
            }
            P = next(P);
            position++;
        }while (P != First(L));   
    }
    if (count == 0){
        printf("0");
    }
    printf("\n");
}


boolean IsListSimetri(List3 L1, List3 L2){
    /*Kamus Lokal*/
    address P;
    address Q;
    int sama;
    /*Algoritma*/
    if (NbElm(L1) != NbElm(L2))
    {
        return false;
    }
    else 
    {
        P = First(L1);
        Q = First(L2);
        sama = 0;
        do
        {
            if (info(P) == info(Q))
            {
                sama = sama + 1;
            }
            P = next(P);
            Q = next(Q);
        } while(P != First(L1) && Q != First(L2));

        if (sama == NbElm(L1))
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
}



#endif