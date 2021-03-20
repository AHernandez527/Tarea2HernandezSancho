#include <iostream>//Importacion de librerias
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <stdio.h> 
#include <pthread.h>
#include <string.h> 
using namespace std;
const int elementos=100000;//definicion de variables generales
int array1[elementos];

void* elevador(void* arg)
{
int array [100000];
int parar = 1;
for (int i = 0; i<= 100000; i++){ //funcion para 1 hilo con 100000 elementos
    array[i]= pow(parar,6);// Condicion parar llena los datos con numeros del 1 al 500
    

        if (parar<500){
            parar ++;
        }
        else {
            parar = 0;
        }
    
    }
pthread_exit(0);

}

void* elevador1(void* arg)//Funciones para 4 hilos, llenan 25000 datos del array por hilo
{
int parar = 1;
for (int i = 0; i<= 25000; i++){
    array1[i]= pow(parar,6);
    

        if (parar<500){
            parar ++;
        }
        else {
            parar = 0;
        }
    
    }
pthread_exit(0);
}

void* elevador2(void* arg)
{

int parar = 1;
for (int i = 25001; i<= 50000; i++){
    array1[i]= pow(parar,6);
    

        if (parar<500){
            parar ++;
        }
        else {
            parar = 0;
        }
    
    }
pthread_exit(0);
}
void* elevador3(void* arg)
{

int parar = 1;
for (int i = 50001; i<= 75000; i++){
    array1[i]= pow(parar,6);
    

        if (parar<500){
            parar ++;
        }
        else {
            parar = 0;
        }
    
    }
pthread_exit(0);
}

void* elevador4(void* arg)
{

int parar = 1; // esta cambia el limite en i de <= a < para no exceder la cant. de datos
for (int i = 75001; i< 100000; i++){
    array1[i]= pow(parar,6);
    

        if (parar<500){
            parar ++;
        }
        else {
            parar = 0;
        }
    
    }
pthread_exit(0);
}


int main(int miau, char **argv)
{   
   /* Ejecucion del codigo para un hilo, imprime el tiempo de un unico 
   hilo y llena los 100000 valores con la funcion elevador*/

    pthread_t Hilo9;
    pthread_attr_t(punterito1);
    pthread_attr_init(&punterito1);
    unsigned t7,t8;
    t7=clock();
    pthread_create (&Hilo9 , &punterito1  , elevador,NULL);
    pthread_join(Hilo9, NULL);
    t8=clock();
    double time1 = (double (t7-t8)/CLOCKS_PER_SEC);
    cout << "Tiempo con 1 hilo: "<< time1 << endl; 





    /*Esta parte llama las funciones que llenan 25000 elementos por hilo e imprime el tiempo al final*/
   // long long barrier = atoll(argv[1]);
    pthread_t Hilo1;
    pthread_t Hilo2;
    pthread_t Hilo3;
    pthread_t Hilo4;
    pthread_attr_t(punterito);
    pthread_attr_init(&punterito);
    unsigned t0,t1;
   
    t0=clock();
    pthread_create (&Hilo1 , &punterito  , elevador1,NULL);
    pthread_create (&Hilo2 , &punterito  , elevador2,NULL);
    pthread_create (&Hilo3 , &punterito  , elevador3,NULL);
    pthread_create (&Hilo4 , &punterito  , elevador4,NULL);
    pthread_join(Hilo1, NULL);
    pthread_join(Hilo2, NULL);
    pthread_join(Hilo3, NULL);
    pthread_join(Hilo4, NULL);
    t1=clock();
    double time = (double (t1-t0)/CLOCKS_PER_SEC);
    cout << "tiempo con 4 hilos: "<< time << endl; 
    return 0;

}