/* File : main.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : Muthia Zhafira 24060122130071*/
/* Tanggal : 1 NOVEMBER 2023 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon3.c" 


int main()
{
    printf("\n----------------------PRAKTIKUM 12 POHON BINER 3------------------------\n");
    printf("\n----------------By : MUTHIA 24060122130071----------------------\n");

    printf("\n********** PEMBUATAN POHON A,B, dan C***********\n");
    bintree3 A;
    bintree3 B;
    bintree3 C;
    A = Tree3(NIL,'M', false , Tree3(A,'T', false , Tree3(B,'H', false , NIL , NIL) , Tree3(B,'I', false , NIL , NIL)) , Tree3(A,'U', false , Tree3(C,'A', false , NIL , NIL) , Tree3(C,'A', false , NIL , NIL)));
    B = Tree3(A,'T', false , NIL , NIL);
    C = Tree3(A,'U', false , NIL , NIL);
    printf("-----PENELUSURAN-----");
    printf("\n****** Mencetak pohon biner A dengan prefix lengkap*****\n");
    PrintPrefix(A);
    printf("\n****** Menghitung banyak elemen pohon  A *****\n");
    printf("\nBanyak elemen pada pohon A : %d\n" , NbElmTree(A));
    printf("\n****** Menghitung banyak daun pohon A *****\n");
    printf("\nBanyak daun pada pohon  A : %d" , NbDaun(A));
    printf("\n****** Mencari tinggi pohon A *****\n");
    printf("\nTinggi pohon biner A : %d" , Tinggi(A));
    printf("\n****** Mencari ada berapa level di pohon A *****\n");
    printf("\npohon biner A terdidi dari : %d level" , Level(A));
    printf("\n****** Menghitung banyaknya node pada level 3 di pohon A****\n");
    printf("\nbanyaknya node pada tingkatan 3 di pohon A adalah %d\n" , CountLevelT(A,3));
    // printf("\noperator khusus LIST1\n");
    // printf("\nMembuat L1 dan L2\n");
    // List1 asli;
    // List1 tambahan;
    // CreateList(&asli);
    // CreateList(&tambahan);
    // InsertVFirst(&asli,'B');
    // InsertVFirst(&asli,'A');
    // printf("mengeprint list asli : \t");
    // PrintList(asli);
    // InsertVFirst(&tambahan,'D');
    // InsertVFirst(&tambahan,'C');
    // printf("\nmengeprint list tambahan : \t");
    // PrintList(tambahan);
    // printf("\nmenyambung asli dan tambahan (pconcat)\n");
    // fconcat(asli,tambahan);
    // // pconcat(&asli, tambahan);
    // printf("setelah disambung : \t ");
    // PrintList(asli);
    printf("\n-----LINEARISASI POHON-----\n");
    printf("\nMencetak pohon A secara prefix : \t");
    List1 LPrefix;
    LPrefix = linearPrefix(A);
    PrintList(LPrefix);
    printf("\nMencetak pohon A secara posfix : \t");
    List1 LPosfix;
    LPosfix = linearPosfix(A);
    PrintList(LPosfix);
    printf("\nMencetak pohon A secara infix : \t");
    List1 LInfix;
    LInfix = linearInfix(A);
    PrintList(LInfix);
    printf("\nMencetak pohon A secara BFS : \t");
    List1 Lbfs;
    Lbfs = linearBreadthFS(A);
    PrintList(Lbfs);
    printf("\n");
    printf("PRINTPATHX: \t");
    printPathX(A,'U');
    printf("PRINTPATHDAUN: \t");
    printPathX(A,'T');
    printf("\n--------------------------SELESAI TERIMAKASIH ^_^------------------------------------\n");
    
}