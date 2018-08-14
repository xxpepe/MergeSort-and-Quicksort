#include <stdlib.h>
#include <stdio.h>

#define NUM_ELEMENTOS 5

//Quick Sort - começo
void swap(int *x, int *y){ 
   int aux;
   aux=*x;
   *x=*y;
   *y=aux;
}

int partition(int *A, int l, int r){
    
    int pivo = A[r];
    int i, j;
    i = l-1;

    for (j=l ; j<=r-1 ; j++){
        if(A[j] <= pivo){
            i++;
            swap(&A[i], &A[j]);
        }  
    }
    i++;
    swap(&A[i], &A[j]);

    return i;
}

void quicksort(int *A, int l, int r){
    int q;
    if(l<r){
        q = partition(A, l, r);
        quicksort(A, l, q-1);
        quicksort(A, q+1, r); 
    }
}

//Final do QuickSort

//Começo do MergeSort
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

//Final do MergeSort

//Funcao para imprimir o array
void Imprime(int *array){
    int k=0;
    
    for (k ; k<5 ; k++){
        printf(" |%d| ", array[k]);
    }
    puts("");
}


int main(){

    int array[NUM_ELEMENTOS] = {21,2,34,17,33}; 
    //int array[NUM_ELEMENTOS] = {1, 15, 2, 1, 89}; 
    //int array[NUM_ELEMENTOS] = {50,40,30,20,10};
    printf("\nArray 1 antes da troca:\n");
    Imprime(array);

    puts("Organizando o array 1 com o QuickSort:");
    quicksort(array, 0, 4);
    Imprime(array);

    //int array2[NUM_ELEMENTOS] = {21,2,34,17,33}; 
    //int array2[NUM_ELEMENTOS] = {1, 15, 2, 1, 89}; 
    int array2[NUM_ELEMENTOS] = {50,40,30,20,10};

    printf("\nArray 2 antes da troca:\n");
    Imprime(array2);

    puts("Organizando o array 2 com o MergeSort:");
    MergeSort(array2, 0, 4);
    Imprime(array2);

    return 0;
}