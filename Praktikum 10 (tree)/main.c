/* File : main.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : Muthia Zhafira 24060122130071*/
/* Tanggal : 24 NOVEMBER 2023 */
#include <stdio.h>
#include <stdlib.h>
#include "pohon1.c"

int main()
{
    /*Kamus Lokal*/
    printf("\n----------------------PRAKTIKUM 10 POHON BINER------------------------\n");
    printf("\n----------------By : MUTHIA 24060122130071----------------------\n");

    printf("\n********** PEMBUATAN POHON A***********\n");
    bintree A;
    A = Tree('M', Tree('U',Tree('T',NIL,NIL),Tree('H',NIL,NIL)) ,Tree('I',Tree('A',NIL,NIL),NIL)); 
    printf("\n****** Mencetak pohon biner A dengan prefix lengkap*****\n");
    PrintPrefix(A);

    printf("\n********** PEMBUATAN POHON B***********\n");
    bintree B;
    B = Tree('Z',Tree('H',Tree('A',NIL,NIL),NIL),NIL);
    printf("\n****** Mencetak pohon biner B dengan prefix lengkap*****\n");
    PrintPrefix(B);

    printf("\n********** PEMBUATAN POHON C***********\n");
    bintree C;
    C = Tree('F',NIL,Tree('I',NIL,Tree('R',NIL,Tree('A',NIL,NIL))));
    printf("\n****** Mencetak pohon biner C dengan prefix lengkap*****\n");
    PrintPrefix(C);

    printf("\n****** SELEKTOR *****\n");

    printf("\n****** Mencari Akar pohon biner A *****\n");
    printf("\nAkar dari pohon biner A : %c\n" , GetAkar(A));

    printf("\n****** Mencari anak kiri pohon biner A *****\n");
    printf("\nAnak kiri dari pohon biner A ada di alamat : %d\n" , GetLeft(A));

    printf("\n****** Mencari anak kanan pohon biner A *****\n");
    printf("\nAnak kanan dari pohon biner A ada di alamat : %d\n" , GetRight(A));

    printf("\n****************** PREDIKAT ******************\n");

    printf("\n****** Mengecek apakah pohon A kosong*****\n");
    printf("\nPohon A : %s\n", IsEmptyTree(A) ? "kosong" : "tidak kosong");

    printf("\n****** Mengecek apakah pohon  A daun*****\n");
    printf("\nPohon A : %s\n", IsDaun(A) ? "adalah daun" : "bukan daun");

    printf("\n****** Mengecek apakah pohon  A biner *****\n");
    printf("\nPohon A : %s\n", IsBiner(A) ? "adalah biner" : "bukan biner");

    printf("\n****** Mengecek apakah pohon  B biner *****\n");
    printf("\nPohon B : %s\n", IsBiner(B) ? "adalah biner" : "bukan biner");

    printf("\n****** Mengecek apakah pohon A unerleft *****\n");
    printf("\nPohon A : %s\n", IsUnerLeft(A) ? "adalah unerleft" : "bukan unerleft");

    printf("\n****** Mengecek apakah pohon B unerleft *****\n");
    printf("\nPohon  B : %s\n", IsUnerLeft(B) ? "adalah unerleft" : "bukan unerleft");

    printf("\n****** Mengecek apakah pohon biner A unerright *****\n");
    printf("\nPohon A : %s\n", IsUnerRight(A) ? "adalah unerright" : "bukan unerright");

        printf("\n****** Mengecek apakah pohon biner C unerright *****\n");
    printf("\nPohon C : %s\n", IsUnerRight(C) ? "adalah unerright" : "bukan unerright");

    printf("\n******************PENELUSURAN******************\n");

    printf("\n****** Mencetak pohon anak kiri pohon  A *****\n");
    PrintPrefix(left(A));

    printf("\n****** Mencetak pohon anak kanan pohon  A *****\n");
    PrintPrefix(right(A));

    printf("\n****** Menghitung banyak elemen pohon  A *****\n");
    printf("\nBanyak elemen pada pohon A : %d\n" , NbElm(A));

    printf("\n****** Menghitung banyak daun pohon A *****\n");
    printf("\nBanyak daun pada pohon  A : %d" , NbDaun(A));

    printf("\n****** Mencari tinggi pohon A *****\n");
    printf("\nTinggi pohon biner A : %d" , Tinggi(A));

    printf("\n****** Mencari elemen T pada pohon A*****\n");
    printf("\nElemen T %s" , SearchX(A,'T')? "ada di pohon\n":"tidak ada dipohon\n");
    printf("\n****** Mencari elemen Z pada pohon*****\n");
    printf("\nElemen T %s" , SearchX(A,'Z')? "ada di pohon\n":"tidak ada dipohon\n");
    printf("\n****** Update elemen A dengan I*****\n");
    printf("\n Pohon sebelum di update :\t");
    PrintPrefix(A);
    UpdateX(&A,'A','I');
    printf("\n Pohon setelah di update :\t");
    PrintPrefix(A);

    printf("\n");

    printf("\n****** Menghitung elemen I pada pohon *****\n");
    printf("\nelemen I pada pohon : %d\n" , CountX(A,'I'));
    printf("\n****** Menghitung elemen Z pada pohon *****\n");
    printf("\nelemen Z pada pohon : %d\n" , CountX(A,'Z'));

    printf("\n****** Mengecek apakah pohon A condong ke kiri*****\n");
    printf("\nPohon A %s" , IsSkewLeft(A)? "condong ke kiri\n":"tidak condong ke kiri\n");
    printf("\n****** Mengecek apakah pohon B condong ke kiri*****\n");
    printf("\nPohon B %s" , IsSkewLeft(B)? "condong ke kiri\n":"tidak condong ke kiri\n");

    printf("\n****** Mengecek apakah pohon A condong ke kanan*****\n");
    printf("\nPohon A %s" , IsSkewRight(A)? "condong ke kanan\n":"tidak condong ke kanan\n");
    printf("\n****** Mengecek apakah pohon C condong ke kanan*****\n");
    printf("\nPohon C %s" , IsSkewRight(C)? "condong ke kanan\n":"tidak condong ke kanan\n");

    printf("\n****** Mencetak pohon A dengan prefix ringkas*****\n");
    PrintPref(A);
    printf("\n****** Mencetak pohon B dengan prefix ringkas*****\n");
    PrintPref(B);
    printf("\n****** Mencetak pohon C dengan prefix ringkas*****\n");
    PrintPref(C);

    printf("\n****** Mengecek level T pada pohon A****\n");
    printf("\nelemen T ada pada level %d\n" , LevelX(A,'T'));
    printf("\n****** Mengecek level M pada pohon A****\n");
    printf("\nelemen M ada pada level %d\n" , LevelX(A,'M'));

    printf("\n****** Menghitung banyaknya node pada level 2 di pohon A****\n");
    printf("\nbanyaknya node pada tingkatan 2 di pohon A adalah %d\n" , CountLevelT(A,2));
    printf("\n****** Menghitung banyaknya node pada level 3 di pohon B****\n");
    printf("\nbanyaknya node pada tingkatan 3 di pohon B adalah %d\n" , CountLevelT(B,3));

    printf("\n***** Mengembalikan nilai daun terkiri pohon*****");
    printf("\ndaun terkiri dari pohon A adalah %c" , GetDaunTerkiri(A));
    printf("\ndaun terkiri dari pohon B adalah %c " , GetDaunTerkiri(B));
    printf("\ndaun terkiri dari pohon C adalah %c\n" , GetDaunTerkiri(C));

    printf("\n***** Menghitung frekuensi elemen I pada pohon A  *****");
    printf("\nfrekuensi elemen I adalah %f\n" , FrekuensiX(A,'I'));

    printf("\n*****menghitung elemen vocal pada pohon*****");
    printf("\nelemen vocal pada pohon A : %d" , CountVocal(A));
    printf("\nelemen vocal pada pohon B : %d" , CountVocal(B));
    printf("\nelemen vocal pada pohon C : %d\n" , CountVocal(C));

    printf("\n--------------------------SELESAI TERIMAKASIH ^_^------------------------------------\n");






    





    



}