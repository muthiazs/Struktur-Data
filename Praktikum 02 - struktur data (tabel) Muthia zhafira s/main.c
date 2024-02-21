#include <stdio.h>
#include "tabel.h"
/*Deskripsi : driver ADT tabel integer*/
/*Pembuat : Muthia Zhafira Sahnah*/
/*Tanggal : 9 september 2023*/

int main() {
    Tabel T;
    createTable(&T);
     int N, X;
    printf("Ukuran tabel: %d\n", getSize(T));
    printf("Jumlah elemen kosong: %d\n", countEmpty(T));
    printf("Elemen tabel: ");
    printTable(T);
    printf("\n");
    printf("Enter the number of elements to populate: ");
    scanf("%d", &N);
    populate1(&T, N);

    printf("Table after population: ");
    printTable(T);

    printf("Enter the element to delete: ");
    scanf("%d", &X);
    delXTable(&T, X);

    printf("Table after deletion: ");
    printTable(T);

    printf("Enter the element to delete all occurrences: ");
    scanf("%d", &X);
    delAllXTable(&T, X);

    printf("Table after deletion of all occurrences: ");
    printTable(T);

    printf("Modus of the table: %d\n", Modus(T));

    return 0;
}
  