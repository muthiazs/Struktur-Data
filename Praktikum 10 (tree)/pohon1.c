/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : Muthia Zhafira Sahnah 24060122130071 */
/* Tanggal : 24 November 2023*/

#include "pohon1.h"

/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* procedure Alokasi (output P:bintree) */ 
/* {I.S. - 
    F.S. P ter-alokasi 
	Proses: Memesan ruang memori untuk bintree P} */
void Alokasi (bintree *P){ //representasi fisik prosedur
//bintree Alokasi(); //representasi fisik fungsi
  /*kamus lokal*/

  /*algoritma*/
  (*P) = (bintree) malloc (sizeof(node));
}

/* procedure Dealokasi (input/output P:bintree) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian bintree P} */
void Dealokasi (bintree *P){
  /*kamus lokal*/

  /*algoritma*/
  free(*P);
}

/********** PEMBUATAN bintree KOSONG ***********/
/* function Tree(Akar:infotype, Left:BinTree, Right:BinTree)-> BinTree
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree Tree (infotype akar, bintree left, bintree right){
  /*kamus lokal*/
  bintree P;

  /*algoritma*/
  Alokasi(&P);
  if (P != NIL){
    info(P) = akar;
    left(P) = left;
    right(P) = right;
  }
  return P;
}

/****** SELEKTOR *****/
/*function GetAkar (P : BinTree) -> infotype
{ Mengirimkan nilai Akar pohon biner P }*/
infotype GetAkar(bintree P){
  /*kamus lokal*/

  /*algoritma*/
  return akar(P);
}

/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P){
  /*kamus lokal*/

  /*algoritma*/
  return left(P);
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P){
  /*kamus lokal*/

  /*algoritma*/
  return right(P);
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> boolean 
   {mengembalikan true bila bintree L kosong} */
boolean IsEmptyTree (bintree P){
  /*kamus lokal*/

  /*algoritma*/
  return (P == NIL);
}

/* function IsDaun (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree P){
  /*kamus lokal*/

  /*algoritma*/
  if (P != NIL){
    return left(P) == NIL && right(P) == NIL;
  }
}

/* function IsBiner (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree P){
  /*kamus lokal*/

  /*algoritma*/
  if (P != NIL){
    return left(P) != NIL && right(P) != NIL;
  }
}

/* function IsUnerLeft(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree P){
  /*kamus lokal*/

  /*algoritma*/
  if (P != NIL){
    return left(P) != NIL && right(P) == NIL;
  }
}

/* function IsUnerRight(P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree P){
  /*kamus lokal*/

  /*algoritma*/
  if (P != NIL){
    return left(P) == NIL && right(P) != NIL;
  }
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree P) {
    /*Kamus Lokal*/
    /*Algoritma*/
    if (P != NIL) {
        printf("%c", info(P)); 
        printf("(");
        if (left(P) != NIL) 
        {
            PrintPrefix(left(P));
        } 
        else 
        {
            printf("( ),");
        }
        if (right(P) != NIL) 
        {
            PrintPrefix(right(P));
        } else 
        {
            printf("( )");
        }
        printf(")");
    }
}

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P){
    /*Kamus Lokal*/
    int Nb;
    /*Algoritma*/
    Nb = 0;
    if (P != NIL)
    {
        Nb = 1;
        Nb += NbElm(left(P));
        Nb += NbElm(right(P));
    }

    return Nb;
    
}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P){
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
int max2(int a, int b){
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

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi(bintree P){
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

/******* PENGHAPUSAN ELEMEN ********/

/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> boolean 
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchX(bintree P, infotype X){
    /*Kamus Lokal*/
    /*Algoritma*/
    if( P == NIL){
        return false;
    }
    else if (info(P)==X){
        return true;
    }
    else{
        return SearchX(left(P),X) || SearchX(right(P),X);
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(bintree *P, infotype X, infotype Y){
    /*Kamus Lokal*/
    /*Algoritma*/
    if ((*P) != NIL){
        if (info(*P)==X){
            info(*P)=Y;
        }
        else{
            UpdateX(&left(*P),X,Y);
            UpdateX(&right(*P),X,Y);
        }
    }
}

/*function CountX(P:BinTree, X:infotype) -> integer 
{ Mengirimkan banyaknya node dari P yang bernilai X }*/
int CountX(bintree P, infotype X){
    /*Kamus Lokal*/
    int count;
    /*Algoritma*/
    count = 0;
    if ((P) != NIL){
        if (info(P)==X){
            count = count + 1;
        }
        count += CountX(left(P),X);
        count += CountX(right(P),X);
    }
    return count;
}

/*function IsSkewLeft (P : BinTree)-> boolean 
{ Mengirim true jika P adalah pohon condong kiri } */
boolean IsSkewLeft (bintree P){
    /*Kamus Lokal*/
    /*Algoritma*/
    if (IsEmptyTree(P)){
        return true;//diasumsikan jika kosong dianggap condong kiri
    }
    else if (right(P)!=NIL)
    {
        return false;
    }
    else{
        return IsSkewLeft(left(P));
    }
}

/*function IsSkewRight (P : BinTree) -> boolean
{ Mengirim true jika P adalah pohon condong kanan }*/
boolean IsSkewRight (bintree P){
    /*Kamus Lokal*/
    /*Algoritma*/
    if (IsEmptyTree(P)){
        return true;//diasumsikan jika kosong dianggap condong kanan
    }
    else if (left(P)!=NIL)
    {
        return false;
    }
    else{
        return IsSkewRight(right(P));
    }
}

/* procedure PrintPref(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier ringkas} */
/*contoh: A(B(( ),D),C)*/
void PrintPref(bintree P) {
    /*Kamus Lokal*/
    /*Algoritma*/
    if (P != NIL) {
        printf("%c", info(P)); 
        if (left(P) != NIL || right(P) != NIL) {
            printf("(");
        }
        if (left(P) != NIL) {
            PrintPref(left(P));
        }
        if (right(P) != NIL) {
            if (left(P) != NIL) {
                printf(",");
            }
            PrintPref(right(P));
        }
        if (left(P) != NIL || right(P) != NIL) {
            printf(")");
        }
    }
}

/*function LevelX(P:BinTree, X:infotype)-> integer
{ Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype X){
    /*Kamus Lokal*/
    int level;
    /*Algoritma*/
    if (P == NIL) {
        return 0;
    }
    if (info(P) == X) {
        return 1;
    }
    level = LevelX(left(P), X);
    if (level != 0) {
        return level + 1;
    }
    level = LevelX(right(P), X);
    if (level != 0) {
        return level + 1;
    }
    return 0;
}

/*function CountLevelT(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT(bintree P, int T){
    /*Kamus Lokal*/
    int level;
    /*Algoritma*/
    if ( P == NIL){
        level = 0;
    }
    else if (T == 1){
        level = 1;
    }
    else{
        level = CountLevelT(left(P),T-1)+CountLevelT(right(P),T-1);
    }
    return level;
}

/*function GetDaunTerkiri(bintree P)-> infotype 
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P){
    /*Kamus Lokal*/
    /*Algoritma*/
    if (P == NIL){
        return printf("#");
    }
    else if (left(P) != NIL){
        return GetDaunTerkiri(left(P));
    }
    else{
        return info(P);
    }  
}

/*function FrekuensiX(L:bintree, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran bintree L }*/
float FrekuensiX(bintree P, infotype X){
    /*Kamus Lokal*/
    /*Algoritma*/
    return(float)CountX(P,X)/NbElm(P);
}

/*function CountVocal(L:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree L}*/
int CountVocal(bintree P){
    /*Kamus Lokal*/
    int vocal;
    /*Algoritma*/
    if (P == NIL){
        vocal = 0;
    }
    else if (info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || info(P) == 'O')
    {
        vocal = 1 + CountVocal(left(P)) + CountVocal(right(P));
    }
    else
    {
        vocal = CountVocal(left(P)) + CountVocal(right(P));
    }
return vocal;
}

