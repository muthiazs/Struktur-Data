/* File : pohon.c */
/* NIM & Nama : Muthia Zhafira 24060122130071*/
/* Tanggal : 1 NOVEMBER 2023 */
#include "pohon2.h"
#include "pohon1.c"

/*PENELUSURAN*/
/* procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N} */
void PrintLevel(bintree P, int N){
    /*Kamus lokal*/
    /*Algoritma*/
    if ( P == NIL)
    {
        printf ("-");
    }
    else if(N == 1)
    {
        printf(" %c" , (info(P)));
    }
    else if (N>1){
        PrintLevel(left(P),N-1);
        PrintLevel(right(P), N-1);
    }
}

/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca }*/
bintree BuildBalanceTree(int n){
    // Kamus Lokal
    bintree P;
    infotype X;
    // Algoritma
    if (n == 0){
        P = NIL;
    }
    else{
        P = Tree(X,NIL,NIL); 
        printf("masukkan elemen ke-%d: ", n);
        scanf(" %c", &info(P)); 
        left(P) = BuildBalanceTree(n/2); 
        right(P) = BuildBalanceTree(n - n/2 -1); 
    }
    return P; 
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P){
    /*Kamus Lokal*/
    int selisih;
    /*Algoritma*/
    if ( (P == NIL))
    {
        return true;
    }
    else 
    {
        selisih = abs(NbElm(left(P))-NbElm(right(P)));
        return selisih <= 1 && IsBalanceTree(left(P)) && IsBalanceTree(right(P));
    }
    
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree P, infotype X){
    /*Kamus Lokal*/
    /*Algoritma*/
    if (P == NIL)
    {
        P = Tree(X,NIL,NIL);
    }
    else if (left(P) != NIL)
    {
        AddDaunTerkiri(left(P),X);
    }
    else
    {
        left(P) = Tree(X,NIL,NIL);
    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree P, infotype X, infotype Y, boolean Kiri){
    /*Kamus Lokal*/

    /*Algoritma*/
    if (!IsEmptyTree(P))
    {
        if (IsDaun(P))
        {
            if (info(P) == X)
            {
                if (Kiri)
                {
                    left(P) = Tree(Y, NIL, NIL);
                }
                else
                {
                    right(P) = Tree(Y, NIL, NIL);
                }
            
            }
        }
        else
        {
            AddDaun(left(P), X, Y, Kiri);
            AddDaun(right(P), X, Y, Kiri);
        }
    }
}

// Prosedur untuk menambahkan simpul baru dengan nilai X ke pohon P. Tidak ada simpul di P yang memiliki nilai X.
// Diasumsikan menambahkan simpul ke kiri.
void InsertX(bintree *P, infotype X)
{
    // Kamus Lokal
    // Algoritma
    if (IsEmptyTree(*P)) // Jika P kosong, buat simpul baru dengan X sebagai akar
    {
        (*P) = Tree(X,NIL,NIL);
    }
    else // Jika P tidak kosong, cari apakah ada simpul yang memiliki nilai X
    {
        if(!SearchX(*P, X)) // Jika tidak ada simpul yang memiliki nilai X, tambahkan simpul baru ke kiri
        {
            InsertX(&left(*P),X);
        }
    } 
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype X)
{
    /*Kamus Lokal*/
    /*Algoritma*/
    if ( *P != NIL) 
    {
        if (IsDaun(*P)) /*Jika P adalah daun*/
        {
            (X)=info(*P);
            (*P) = NIL;
            Dealokasi(P);
        }
        else
        {
            DelDaunTerkiri(&left(*P),X);
        }  
    }
}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X){
    /*Kamus Lokal*/
    /*Algoritma*/
    if (*P != NIL) 
    {
        if (IsDaun(*P))
        {
            if (info(*P) == X)
            {
                (*P) = NIL;
                Dealokasi(P);
            }
        }
        else 
        {
            DelDaun(&left(*P),X);
            DelDaun(&right(*P),X);
        }
    }
}

/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y)
{
    /*Kamus Lokal*/
    /*Algoritma*/
    if(*P != NIL){
        if (info(*P)==X){
            info(*P) = Y;
        }
        else{
            UpdateAllX(&left(*P),X,Y);
            UpdateAllX(&right(*P),X,Y);
        }
}
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X)
{
    /*Kamus Lokal*/
    /*Algoritma*/
    if(*P != NIL)
    {
        if (info(*P)==X){
            (*P) = NIL;
            Dealokasi(P);
        }
        else{
            DeleteX(&left(*P),X);
            DeleteX(&right(*P),X);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/* function maxTree(P:bintree)->character
//mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z */
int maxTree(bintree P) {
/*Kamus Lokal*/
char max_kanan , max_kiri;
//jika P kosong, kembalikan nilai minimum
if (P == NIL) 
{
    return 'A'-1; 
}
//jika P tidak kosong, bandingkan elemen P dengan elemen anak kiri dan kanan
else
{
    //mencari huruf maksimal dari anak kiri dan kanan
    max_kanan = maxTree(right(P));
    max_kiri =  maxTree(left(P));
    //mengembalikan huruf maksimal dari ketiga elemen
    return max2(info(P), max2(max_kanan, max_kiri));
  }
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
int minTree(bintree P){
    /*Kamus Lokal*/
    char min_kanan , min_kiri;
    /*Algoritma*/
    if (P == NIL)
    {
        return 'Z'+1;
        // return 'Z' + 1;
    }
    else
    {
        min_kiri = minTree(left(P));
        min_kanan = minTree(right(P));

        return min2(info(P),min2(min_kanan,min_kiri));
    }
}

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X)
{
    /*Kamus Lokal*/
    /*Algoritma*/
    if (IsEmptyTree(P))
    {
        return false;
    }
    else 
    {   
         if (X == info(P))
        {
            return true;
        }
        else 
        {
            if (X > info(P))
            {
                BSearch(right(P),X);
            }
            else 
            {
                BSearch(left(P),X);
            }
        }
    }
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X){
/*Kamus Lokal*/
/*Algoritma*/
    if (P == NIL)
    {
        return Tree(X,NIL,NIL);

    }
    else if ( X == info(P))
    {
        return P;
    }
    else if ( X>info(P))
    {
        right(P) = InsSearch(right(P),X);
    }
        else if ( X<info(P))
    {
        left(P) = InsSearch(left(P),X);
    }
    return P;
}



