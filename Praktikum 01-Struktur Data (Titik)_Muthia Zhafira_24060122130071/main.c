/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060122130071 Muthia Zhafira Sahnah*/
/* Tanggal   : 2 September 2023*/
/***********************************/
#include <stdio.h>
#include "titik.h"

int main() {
	//kamus main
	Titik A;
	Titik B;

	//algoritma
	printf("Halo, ini driver modul Titik \n");
	makeTitik(&A); //saat dimain *T menjadi &A
	setAbsis(&A,6);
	printf("\nNilai absis A = %d",A.absis);
	setOrdinat(&A,3);
	printf("\nNilai ordinat A = %d ", A.ordinat);
	setAbsis(&B,10);
	printf("\nNilai absis B = %d",B.absis);
	setOrdinat(&B,6);
	printf("\nNilai ordinat B = %d ", B.ordinat);
	printf("\njarak euclidian titik T1 dan T2 = %d ", Jarak(A,B));
	printf("\nNilai absis adalah = %d",getAbsis(A));
	printf("\nNilai ordinat adalah = %d ", getOrdinat(A));
	geserXY(&A,2,1);
	printf("\nNilai titik A menjadi : \n X = %d \n Y = %d", A.absis, A.ordinat);
	refleksiSumbuX(&A);
	printf("\nNilai titik A setelah di refleksi terhadap sumbu X adalah, \nX = %d \nY = %d " ,A.absis, A.ordinat);
	refleksiSumbuY(&A);
	printf("\nNilai titik A setelah di refleksi terhadap sumbu Y adalah, \nX = %d \nY = %d " ,A.absis, A.ordinat);
	printf("\nDi kuadran berapakah titik itu berada = %d ", Kuadran(A));
	
	
	if (isOrigin(A)) {
	    printf ("\nnilai A adalah origin");
	}
	else {
	    printf ("\nnilai A tidak origin");
	}
	return 0;
	
}
