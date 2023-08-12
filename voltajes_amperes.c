#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    srand(time(NULL));
    int n;
    int i;
    int j;
    do{
    printf("Indique cuantos voltajes aleatorios generara \n");
    scanf("%d",&n);
    }while(n < 2);
int vector_voltajes[n];

//INGRESO RANDOM VOLTAJES
 for(i = 0; i < n; i++){
    vector_voltajes[i] = rand() %10000 + 99;
 }

 //INGRESO MANUAL AMPERES
 int vector_amperes[n];
for(i = 0; i < n; i++){
  do{
    printf("Ingrese cantidad de corriente en amperes en la posicion %d \n", i + 1);
    scanf("%d",&vector_amperes[i]);
    if((vector_amperes[i] > 10000 || vector_amperes[i] < 100)){
        printf("Las corrientes deben ser valores entre 100A y 10000A \n");
    }
}while(vector_amperes[i] > 10000 || vector_amperes[i] < 100);
}

//MOSTRAR VECTOR VOLTAJES
    printf(" \n Vector de Voltajes: \n");
    for(i = 0; i < n; i++){
        printf("[%dV]",vector_voltajes[i]);
    }
    printf("\n");

//MOSTRAR VECTOR AMPERES
    printf("\n Vector de Amperes: \n");
    for(i = 0; i < n; i++){
        printf("[%dA]",vector_amperes[i]);
    }
      printf("\n");

//ORDENAMIENTO VOLTAJE MENOR A MAYOR 
   int aux = 0; 
    for(i = 1; i < n; i++){
        for(j = 0; j < n - 1; j++){
            if(vector_voltajes[j] > vector_voltajes[j + 1]){
                aux = vector_voltajes[j];
                vector_voltajes[j] = vector_voltajes[j + 1];
                vector_voltajes[j + 1] = aux;
            }
        }
    }

 //MOSTRAR VECTOR VOLTAJE ORDENADO   
    printf("\n Vector de Voltajes ordenado menor a mayor : \n");
    for(i = 0; i < n; i++){
        printf("[%dV]",vector_voltajes[i]);
    }
      printf("\n");

//ORDENAMIENTO AMPERIOS MAYOR A MENOR 
    aux = 0; 
    for(i = 1; i < n; i++){
        for(j = 0; j < n - 1; j++){
            if(vector_amperes[j] < vector_amperes[j + 1]){
                aux = vector_amperes[j];
                vector_amperes[j] = vector_amperes[j + 1];
                vector_amperes[j + 1] = aux;
            }
        }
    }

 //MOSTRAR VECTOR AMPERES ORDENADO   
printf("\n Vector de Amperes ordenado mayor a menor  : \n");
    for(i = 0; i < n; i++){
        printf("[%dA]",vector_amperes[i]);
    }
      printf("\n");

//VOLTAJE A KV
float resultado;
printf("\n Vector de Voltajes a Kv : \n");
    for(i = 0; i < n; i++){
        resultado = vector_voltajes[i] / 1000;
        printf("[%.5fV]", resultado);
    }
    printf("\n");

//AMPER A MILIAMPER  
 printf("\n Vector de Amper a Miliamper : \n");
    for(i = 0; i < n; i++){
        resultado = vector_amperes[i] * 1000;
        printf("[%.5fV]",resultado);
    }
      printf("\n");

//VECTOR RESISTENCIA LEY OHM
float vector_resistencias[n];
for(i = 0; i < n; i++){
 vector_resistencias[i] = vector_voltajes[i] / vector_amperes[i];
}
printf("Vector de resistencia ley ohm: \n");
    for(i = 0; i < n; i++){
 printf("[%.5f]",vector_resistencias[i]);
}


system("pause");
return 0;
}

