#ifndef   TABEL_c
#define   TABEL_c
#include "tabel.h"
#include "boolean.h"
/*Deskripsi : */  
/*Pembuat : Muthia zhafira */ 
/*Tanggal : 9 september 2023*/ 
  
/* type Tabel = < wadah : array[1..10] of integer,
                   size : integer > */ 
/* asumsi: indeks 0 tidak digunakan */ 
  typedef struct
{
  int wadah[11];
int size;} Tabel;

void createTable (Tabel *T) {
    (*T).size = 0;
    for(int i = 1; i <= 10; i++) {
        (*T).wadah[i] = -999;
    }
}

void printTable (Tabel T) {
    for(int i = 1; i <= 10; i++) {
        printf("%d ", T.wadah[i]);
    }
    printf("\n");
}

void viewTable (Tabel T) {
    for(int i = 1; i <= T.size; i++) {
        printf("%d ", T.wadah[i]);
    }
    printf("\n");
}

int getSize (Tabel T) {
    return T.size;
}

int countEmpty (Tabel T) {
    return 10 - T.size;
}

boolean isEmptyTable (Tabel T) {
    return T.size == 0;
}

boolean isFullTable (Tabel T) {
    return T.size == 10;
}

void populate1 (Tabel *T, int N) {
    if(N >= 1 && N <= 10) {
        int num;
        for(int i = 1; i <= N; i++) {
            scanf("%d", &num);
            if(num > 0) {
                (*T)wadah[i] = num;
                (*T)->size++;
            }
        }
    }
}

void searchX1 (Tabel T, int X, int *Pos) {
    *Pos = -999;
    for(int i = 1; i <= T.size; i++) {
        if(T.wadah[i] == X) {
            *Pos = i;
            break;
        }
    }
}

void countX (Tabel T, int X, int *Byk) {
    *Byk = 0;
    for(int i = 1; i <= T.size; i++) {
        if(T.wadah[i] == X) (*Byk)++;
    }
}

int SumEl (Tabel T) {
    int sum = 0;
    for(int i = 1; i <= T.size; i++) sum += T.wadah[i];
    return sum;
}

int AverageEl (Tabel T) {
    return SumEl(T)/T.size;
}

int getMaxEl (Tabel T) {
    int max = -999;
    for(int i = 1; i <= T.size; i++) if(T.wadah[i] > max) max = T.wadah[i];
    return max;
}

int getMinEl (Tabel T) {
    int min = 9999999;
    for(int i = 1; i <= T.size; i++) if(T.wadah[i] < min) min = T.wadah[i];
    return min;
}

void populate2 (Tabel *T) {
    int num;
    while(scanf("%d", &num), num > 0 && !isFullTable(*T)) {
        addXTable(T, num);
    }
}

void addXTable (Tabel *T, int X) {
    if(!isFullTable(*T)) {
        (*T).wadah[(*T).size + 1] = X;
        (*T).size++;
    }
}

void delXTable (Tabel *T, int X) {
   int i =1;
   int j;
   while (i<=(*T).size && (*T).wadah[i] != X){
       i++;
   }
   if ((*T).wadah[i]== X {
       for (int j = i; j < (*T)size; j++) {
           (*T).wadah[j] == (*T).wadah[j+1];
       }
       (*T).size--;
   }
}

void delAllXTable (Tabel *T, int X) {
   int i=1;
   while (i<= (*T).size--){
       if ((*T).wadah[i] == X){
           for (int j = i; j< (*T).size; j++){
               (*T).wadah[j] = (*T).wadah[j+i];
           }
           (*T).size--;
       } else {
           i++
       }
   }
}

int Modus (Tabel T){
   int maxCount = 0;
    int modus = -999;
    for(int i = 1; i <= T.size; i++) {
        int count = 0;
        for(int j = 1; j <= T.size; j++) {
            if(T.wadah[j] == T.wadah[i]) count++;
        }
        if(count > maxCount) {
            maxCount = count;
            modus = T.wadah[i];
        }
    }
    return modus;
}
}
 
