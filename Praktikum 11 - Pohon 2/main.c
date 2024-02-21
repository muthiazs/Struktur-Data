/* File : main.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : Muthia Zhafira 24060122130071*/
/* Tanggal : 1 NOVEMBER 2023 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon2.c" 


int main()
{
    printf("\n----------------------PRAKTIKUM 11 POHON BINER------------------------\n");
    printf("\n----------------By : MUTHIA 24060122130071----------------------\n");

    /*Kamus Lokal*/
    infotype X;

    printf("\n********** PEMBUATAN POHON A***********\n");
    bintree A;
    A = Tree('M',Tree('B',Tree('A',NIL,NIL),Tree('D',NIL,NIL)),Tree('R',Tree('P',NIL,NIL),Tree('Z',NIL,NIL)));
    printf("\n****** Mencetak pohon biner A dengan prefix lengkap*****\n");
    PrintPrefix(A);

    printf("\n********** PEMBUATAN POHON B***********\n");
    bintree B;
    B = Tree('Z',Tree('H',Tree('A',NIL,NIL),NIL),Tree('J',NIL,NIL));
    printf("\n****** Mencetak pohon biner B dengan prefix lengkap*****\n");
    PrintPrefix(B);

    printf("\n********** PEMBUATAN POHON C***********\n");
    bintree C;
    C = Tree('F',NIL,Tree('I',NIL,Tree('R',NIL,Tree('A',NIL,NIL))));
    printf("\n****** Mencetak pohon biner C dengan prefix lengkap*****\n");
    PrintPrefix(C);

    printf("\n******Menampilkan elemen pohon A di level 1*****\n");
    PrintLevel(A,1);
    
    printf("\n******Menampilkan elemen pohon A di level 2*****\n");
    PrintLevel(A,2);

    printf("\n******Menampilkan elemen pohon A di level 3*****\n");
    PrintLevel(A,3);

    printf("\n*******MEMBANGUN POHON SEIMBANG ********\n");
    bintree P;
    P = BuildBalanceTree(5);
    PrintPref(P);
    printf("\n*******=MENGECEK APAKAH POHON SEIMBANG********\n");
    printf("\nPohon P : %s\n", IsBalanceTree(P) ? "seimbang" : "tidak seimbang");


    printf("\n******* PENAMBAHAN ELEMEN ********\n");
    printf("\n----ADDDAUNTERKIRI----\n");
    printf("\nMenambahkan T ke paling kiri pohon A\n");
    AddDaunTerkiri(A,'T');
    PrintPref(A);
    printf("\nMenambahkan F ke paling kiri pohon B\n");
    AddDaunTerkiri(B,'F');
    PrintPref(B);
    printf("\nMenambahkan S ke paling kiri pohon C\n");
    AddDaunTerkiri(C,'S');
    PrintPref(C);
    printf("\n");
    printf("\n----ADDDAUN----\n");
    printf("\nMenambahkan X kekanan elemen F di pohon B\n");
    AddDaun(B,'F','X', false);
    PrintPref(B);
    printf("\n");
    printf("\n----INSERTX----\n");
    printf("\nMenambahkan Y ke pohon C jika belum ada\n");
    InsertX(&C,'Y');
    PrintPrefix(C);

    printf("\n");

    printf("\n******* PENGHAPUSAN ELEMEN ********\n");
    printf("\n----DELDAUNTERKIRI----\n");
    printf("Menghapus elemen daun terkiri di pohon C\n");
    DelDaunTerkiri(&C,X);
    PrintPrefix(C);
    printf("\n");
    printf("\n----DELDAUN----\n");
    printf("\nMenghapus elemen daun X di pohon C\n");
    printf("pohon B sebelum diapus : \n");
    PrintPrefix(B);
    printf("\n");
    printf("pohon B setelah diapus : \n");
    DelDaun(&B,'X');
    PrintPrefix(B);
    printf("\n");
    printf("\n----DELETE X----\n");
    printf("\nMenghapus elemen R pada pohon C");
    printf("pohon C sebelum diapus : \n");
    PrintPrefix(C);
    printf("\n");
    printf("pohon C setelah diapus : \n");
    DeleteX(&C,'R');
    PrintPrefix(C);

    printf("\n");

    printf("\n*** MANIPULASI ELEMEN bintree ***\n");
    printf("Mengubah elemen A menjadi I di pohon B\n");
    UpdateAllX(&B,'A','I');
    PrintPrefix(B);

    printf("\n");

    printf("\nmengembalikan huruf maksimal dari pohon, A<B<C<..<Z \n");
    printf("\nhuruf maksimal dari elemen di pohon A adalah : %c" , maxTree(A));
    printf("\nhuruf maksimal dari elemen di pohon B adalah : %c" , maxTree(B));
    printf("\nhuruf maksimal dari elemen di pohon C adalah : %c\n" , maxTree(C));

    printf("\nmengembalikan huruf minimal dari pohon, A<B<C<..<Z \n");
    printf("\nhuruf minimal dari elemen di pohon A adalah : %c" , minTree(A));
    printf("\nhuruf minimal dari elemen di pohon B adalah : %c" , minTree(B));
    printf("\nhuruf minimal dari elemen di pohon C adalah : %c" , minTree(C));
    
    printf("\n");

    printf("\n****MENCARI ELEMEN X DI POHON****\n");
    printf("\nelemen Z di pohon B : %s\n", BSearch(B,'Z') ? "ada" : "tidak ada");
    printf("\nelemen M di pohon B : %s\n", BSearch(B,'M') ? "ada" : "tidak ada");

    printf("\n****MENYISIPKAN ELEMEN X KEDALAM POHON BINER A YANG MERUPAKAN BST****\n");
    InsSearch(A,'X');
    PrintPref(A);

    printf("\n--------------------------SELESAI TERIMAKASIH ^_^------------------------------------\n");
    
}