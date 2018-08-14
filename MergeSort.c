#include <stdlib.h>
#include <stdio.h>

void Merge(int *array, int comeco, int mid, int fim){
    int tamanho = fim-comeco+1;
    int c1 = comeco;
    int c2 = mid+1;
    int caux = 0;
    int i=0;

    int *arrayaux;

    arrayaux = (int*)malloc(tamanho * sizeof(int));

    while(c1 <= mid && c2 <=fim){

        if(array[c1] < array[c2]){
            arrayaux[caux] = array[c1];
            c1++;
        }else{
            arrayaux[caux] = array[c2];
            c2++;
        }

        caux++;
    }

    while(c1 <=mid){
        arrayaux[caux] = array[c1];
        caux++;
        c1++;
    }

    while(c2<=fim){
        arrayaux[caux] = array[c2];
        caux++;
        c2++;
    }

    for(i = comeco ; i <= fim ; i++ ){
        array[i] = arrayaux[i-comeco];
    }

    free(arrayaux);
}

void MergeSort(int *array, int comeco, int fim){

    if(comeco<fim){
        int mid;
        mid = (comeco+fim)/2;   

        MergeSort(array, comeco, mid);
        MergeSort(array, mid+1, fim);
        Merge(array, comeco, mid, fim);

    }
}

void Imprime(int *array){
    int k=0;
    
    for (k ; k<5 ; k++){
        printf(" |%d| ", array[k]);
    }
    puts("");
}


int main(){

    //int array[5] = {21,2,34,17,33}; 
    //int array[5] = {1, 15, 2, 1, 89}; 
    int array[5] = {50,40,30,20,10};
    printf("\nArray antes da troca:\n");
    Imprime(array);

    MergeSort(array, 0, 4);
    
    printf("\nDepois da troca:\n");
    Imprime(array);

    return 0;
}