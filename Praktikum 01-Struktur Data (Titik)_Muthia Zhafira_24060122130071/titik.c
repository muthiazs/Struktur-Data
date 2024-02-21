/************************************/  
/* Program   : titik.c */ 
/* Deskripsi : realisasi body modul Titik */ 
/* NIM/Nama  : 24060122130071 Muthia Zhafira Sahnah*/ 
/* Tanggal   : 2 September 2023*/ 
/***********************************/ 
#include <stdio.h>
#include "titik.h"
#include <math.h>
   /*KONSTRUKTOR*/ 
/* procedure makeTitik(output T:Titik)*/ 
/*{I.S.: -}*/ 
/*{F.S.: T terdefinisi}*/ 
/*{proses: mengisi nilai komponen absis dan ordinat T dengan 0}*/ 
//tanda *T menandakan T adalah suatu input dan output , kalo input aja cukup T aja
  void
makeTitik (Titik * T)
{
  
(*T).absis = 0;
  
(*T).ordinat = 0;

} 
 

/*********MUTATOR*/ 
/*procedure setAbsis(input/output T, input xx)*/ 
/*{I.S.: T terdefinisi}*/ 
/*{F.S.: T.absis=xx}*/ 
/*{proses: mengisi nilai komponen absis T}*/ 
  void
setAbsis (Titik * T, int xx)
{
  
(*T).absis = xx;

}

/*procedure setOrdinat(input/output T, input yy)*/ 
/*{I.S.: T terdefinisi}*/ 
/*{F.S.: T.ordinat=yy}*/ 
/*{proses: mengisi nilai komponen ordinat T}*/ 
void setOrdinat (Titik * T, int yy){
    (*T).ordinat = yy;
}

/*DESTRUKTOR*/ 
 
/**********SELEKTOR*/ 
/*function getAbsis(T:Titik)->integer*/ 
/*{mengembalikan nilai komponen absis T}*/ 
int getAbsis (Titik T){
    return T.absis;
}

 
/*function getOrdinat(T:Titik)->integer*/ 
/*{mengembalikan nilai komponen ordinat T}*/ 
int getOrdinat (Titik T){
    return T.ordinat;
}

/*********PREDIKAT*/ 
/*function isOrigin(T:Titik)->boolean*/ 
/*{mengembalikan true jika Titik T ada di persilangan sumbu X dan Y}*/ 
  bool isOrigin (Titik T){
     return (T.absis==0) && (T.ordinat==0);                                                                                                                                                                                                                                                                                                                                                                                  ;
  }

/*********SUBRUTIN LAIN*/ 
/*procedure geserXY(input/output T:Titik, input dx, input dy)*/ 
/*{I.S.: T terdefinisi}*/ 
/*{F.S.: T bergeser sejauh (dx,dy)}*/ 
/*{proses: mengubah nilai komponen absis dan ordinat T}*/ 
void geserXY (Titik * T, int dx, int dy){
    (*T).absis = (*T).absis + dx;
    (*T).ordinat = (*T).ordinat + dy;
}

/*procedure refleksiSumbuX(input/output T:Titik)*/ 
/*{I.S.: T terdefinisi}*/ 
/*{F.S.: T dicerminkan ke sumbu X }*/ 
/*{proses: mengubah nilai komponen ordinat T}*/ 
void refleksiSumbuX (Titik * T) {
    (*T).ordinat = -(*T).ordinat;
}

/*procedure refleksiSumbuY(input/output T:Titik)*/ 
/*{I.S.: T terdefinisi}*/ 
/*{F.S.: T dicerminkan ke sumbu Y }*/ 
/*{proses: mengubah nilai komponen absis T}*/ 
void refleksiSumbuY (Titik * T){
    (*T).absis = -(*T).absis;
}

/*function Kuadran(T:Titik)->integer*/ 
/*{mengembalikan posisi Titik T pada kuadran 1,2,3 atau 4}*/ 
/*{asumsi: bila titik memotong sumbu, maka nilai 0 dianggap positif}*/ 
int Kuadran (Titik T){
    if ((T.absis>0) && (T.ordinat>0)) {
        return (1);
    }
    else if ((T.absis<0) && (T.ordinat>0)){
        return (2);
    }
    else if ((T.absis<0) && (T.ordinat<0)) {
        return (3);
    }
    else if ((T.absis>0) && (T.ordinat <0)) {
        return (4);
    }
}

/*function Jarak(T1:Titik, T2:Titik)->real*/
/*{mengembalikan jarak euclidian titik T1 dan T2}*/
/*{asumsi: aplikasikan rumus Pitagoras dan fungsi akar sqrt}*/
int Jarak(Titik T1, Titik T2){
    return sqrt(pow(T2.absis - T1.absis, 2) + pow(T2.ordinat - T1.ordinat, 2));
}

