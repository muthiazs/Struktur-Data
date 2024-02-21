/* File : pohon3.c */
/* NIM & Nama : Muthia Zhafira 24060122130071*/
/* Tanggal : 8 NOVEMBER 2023 */
#include "pohon3.h"
#include "List1.h"
#include "List1.c"

/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* procedure Alokasi (output P:bintree3) */ 
/* {I.S. - 
    F.S. P ter-alokasi 
	Proses: Memesan ruang memori untuk bintree3 P} */
void Alokasi3 (bintree3 *P)
{
/*kamus lokal*/

/*Algoritma*/
  (*P) = (bintree3) malloc (sizeof(node3));
} 
//representasi fisik prosedur
//bintree3 Alokasi(); //representasi fisik fungsi

/* procedure Dealokasi (input/output P:bintree3) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian bintree3 P} */
void Dealokasi3 (bintree3 *P)
{
/*kamus lokal*/

/*algoritma*/
  free(*P);
}

/********** PEMBUATAN bintree3 KOSONG ***********/
/* function Tree(A:bintree3, X:infotype, V:boolean, kiri:bintree3, kanan:bintree3)-> bintree3
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree3 Tree3 (bintree3 A, infotype X, boolean V, bintree3 kiri, bintree3 kanan)
{
  /*kamus lokal*/
  bintree3 P;

  /*algoritma*/
  Alokasi3(&P);
  if (P != NIL){
    parent(P) = A;
    info(P) = X;
    visited(P) =V;
    left(P) = kiri;
    right(P) = kanan;
  }
  return P;
}

/****** SELEKTOR *****/

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree3) --> boolean 
   {mengembalikan true bila bintree3 L kosong} */
boolean IsEmptyTree (bintree3 P)
{
/*kamus lokal*/

/*algoritma*/
  return (P == NIL);
}

/* function IsDaun (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree3 P)
{
/*kamus lokal*/

/*algoritma*/
    if (P!=NIL)
    {
        return left(P) == NIL && right(P) == NIL;
    }
}

/* function IsBiner (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree3 P)
{
/*kamus lokal*/

/*algoritma*/
    if (P!=NIL)
    {
        return left(P) != NIL && right(P) != NIL;
    }
}

/* function IsUnerLeft(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree3 P)
{
/*kamus lokal*/

/*algoritma*/
     if (P!=NIL)
    {
        return left(P) != NIL && right(P) == NIL;
    }
}

/* function IsUnerRight(P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree3 P)
{
/*kamus lokal*/

/*algoritma*/
    if (P!=NIL)
    {
        return left(P) == NIL && right(P) != NIL;
    }
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree3 P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree3 P)
{
    /*Kamus Lokal*/
    /*Algoritma*/
    if (IsEmptyTree(P)){ /*basis 0*/
        printf("( )");
    } 
    else { /*rekurens*/
        printf("%c(",akar(P)) ;
        PrintPrefix(left(P));
        printf(",");
        PrintPrefix(right(P));
        printf(")");
    }
}

/* function NbElmTree(P:bintree3) --> integer
{ menghitung banyaknya elemen bintree3 P} */
int NbElmTree(bintree3 P)
{
    /*Kamus Lokal*/
    int Nb;
    /*Algoritma*/
    Nb = 0;
    if (P != NIL)
    {
        Nb = 1;
        Nb += NbElmTree(left(P));
        Nb += NbElmTree(right(P));
    }

    return Nb;
    
}

/* function NbDaun(P:bintree3)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree3 P)
{
        /*Kamus Lokal*/
    int Nb;
    /*Algoritma*/
    Nb = 0;
    if (P != NIL){
        if (left(P) == NIL && right(P) == NIL)
        {
            Nb = 1;
        }
        else{
            Nb = NbDaun(left(P)) + NbDaun(right(P));
        }
    }
    return Nb;
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b)
{
/*Kamus Lokal*/

/*Algoritma*/
    if (a>b){
        return a;
    }
    else
    {
        return b;
    }
}

/* function Tinggi(P:bintree3)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi(bintree3 P)
{
/*Kamus Lokal*/
    int tkiri, tkanan;
    int t;
/*Algoritma*/
    t = -1;
    if (P!=NIL)
    {
        tkiri = Tinggi(left(P));
        tkanan =Tinggi(right(P));
        t = max2(tkiri,tkanan)+1;
    }
    return t;
}

/* function Level(P:bintree3)-> integer
{menghitung tingkat/generasi node pohon P, level akar=1 }*/
int Level(bintree3 P)
{
/*Kamus Lokal*/
int levelkanan, levelkiri, level;

/*Algoritma*/
    if (P == NIL)
    {
        return 0; 
    }
    else if (IsDaun(P))
    {
        return 1; 
    }
    else 
    {
        levelkanan = Level(right(P)) + 1; 
        levelkiri = Level(left(P)) + 1; 
        level = max2(levelkanan,levelkiri);
    }
    return level;
}

/*function CountLevelT(P:bintree3, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT(bintree3 P, int T)
{
/*Kamus Lokal*/
int node;
/*Algoritma*/
    if ( P == NIL)
    {
        node = 0;
    }
    else if ( T == 1 )
    {
        node = 1;
    }
    else 
    {
        node = CountLevelT(left(P),T-1) + CountLevelT(right(P),T-1);
    }
    return node;
}

/* procedure PrintLevel(input P:bintree3, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N} */
List1 LinearLevel(bintree3 P, int N)
{
    /*Kamus lokal*/
    List1 L;
    /*Algoritma*/
    CreateList(&L);
    if ( P == NIL)
    {
        printf ("-");
    }
    else if(N == 1)
    {
        InsertVLast(&L,info(P));
    }
    else if (N>1){
        pconcat(&L,LinearLevel(left(P),N-1));
        pconcat(&L,LinearLevel(right(P),N-1));
    }
    return L;
}

/*** operator khusus LIST1 ***/
//printList sudah ADA di list1.h

/*procedure concat( input/output Asli:list1, input Tambahan:list1) */
/*{I.S:- ; F.S: list Asli berubah karena disambung list Tambahan}*/
/*{menyambung list Tambahan ke belakang list Asli}*/
void pconcat(List1 *Asli, List1 Tambahan)
{
    /*Kamus Lokal*/
    address P; 
    /*Algoritma*/
    if ( IsEmptyList(*Asli))
    {
        *Asli = Tambahan; // Kalo asli kosong yauda brati masukin aja tambahan nya kedalam asli
    }
    else 
    {
        //mencari elemen terakhir asli untuk disambungkan dengan node pertama tambahan
        P = First(*Asli);
        while (next(P) != NIL)
        {
            P = next(P);
        }
        next(P) = First(Tambahan); //menyambungkan node terakhir asli dengan elemen pertama tambahan
    }
}

/*function fconcat( Asli:list1, Tambahan:list1) -> list1 */
/*{membentuk list Baru hasil penyambungan list Tambahan ke belakang list Asli}*/
/*{periksa dampaknya, list Asli tidak boleh berubah }*/
List1 fconcat(List1 Asli, List1 Tambahan)
{
    /*Kamus Lokal*/
    List1 Baru;
    /*Algoritma*/
    CreateList(&Baru);
    pconcat(&Baru,Asli);
    pconcat(&Baru,Tambahan);
    return Baru;
}

/*** LINEARISASI POHON ***/
/*function linearPrefix(P:bintree3) -> list1
{menghasilkan list node dari P terurut prefix akar,kiri,kanan}*/
List1 linearPrefix(bintree3 P)
{
/*Kamus Lokal*/
    List1 L;
/*Algoritma*/
    CreateList(&L);
    if (P != NIL)
    {
        InsertVLast(&L,akar(P));
        pconcat(&L,linearPrefix(left(P)));
        pconcat(&L,linearPrefix(right(P)));
    }
    return L;  
}

/*function linearPosfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut posfix kiri,kanan,akar}*/
List1 linearPosfix(bintree3 P)
{
/*Kamus Lokal*/
    List1 L;
/*Algoritma*/
    CreateList(&L);
    if (P != NIL)
    {
        pconcat(&L,linearPosfix(left(P)));
        pconcat(&L,linearPosfix(right(P)));
        InsertVLast(&L,akar(P));
    }
    return L;  
}

/*function linearInfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut infix kiri,akar,kanan}*/
List1 linearInfix(bintree3 P)
{
/*Kamus Lokal*/
    List1 L;
/*Algoritma*/
    CreateList(&L);
    if (P != NIL)
    {
    pconcat(&L,linearInfix(left(P)));
    InsertVLast(&L,akar(P));
    pconcat(&L,linearInfix(right(P)));
    }
    return L;  
}

/*function linearBreadthFS(P:bintree3) -> list1
{menghasilkan list node dari P terurut level/tingkat}*/
List1 linearBreadthFS(bintree3 P)
{
/*Kamus Lokal*/
    int i;
    List1 L;
/*Algoritma*/
    CreateList(&L);
    if (P != NIL)
    {
        for ( i = 1; i <= Level(P); i++)
        {
            pconcat(&L,LinearLevel(P,i));
        }  
    }
    return L;
}

/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> boolean 
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchXTree(bintree3 P, infotype X){
    /*Kamus Lokal*/
    /*Algoritma*/
    if( P == NIL){
        return false;
    }
    else if (info(P)==X){
        return true;
    }
    else{
        return SearchXTree(left(P),X) || SearchXTree(right(P),X);
    }
}


void printPathX(bintree3 P, infotype X) {
    //Kamus Lokal

    //Algoritma
    if (IsEmptyTree(P)) {
        printf("Tidak ketemu!\n");
        return;
    }

    printf("%c", info(P));

    if (info(P) == X) {
        printf("\n");
        return;
    }
    printf(" -> ");
    if (SearchXTree(left(P), X)) {
        printPathX(left(P), X);
    } 
    else if (SearchXTree(right(P), X)) {
        printPathX(right(P), X);
    }
}


void printPathDaunX(bintree3 P, infotype X) {
    //Kamus Lokal

    //Algoritma
    if (IsEmptyTree(P)) {
        printf("Tidak ketemu!\n");
        return;
    }

    printf("%c", info(P));

    if (SearchXTree(left(P), X)) {
        printf(" -> ");
        printPathDaunX(left(P), X);
    } 
    else if (SearchXTree(right(P), X)) {
        printf(" -> ");
        printPathDaunX(right(P), X);
    } 
    else if (info(P) == X) {
        if (IsDaun(P)) {
            printf("\n");
        } else {
            printf(" bukan daun!\n");
        }
    }
}