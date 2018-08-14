#include <stdlib.h>
#include <stdio.h>

#define NUM_ELEMENTOS 5

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
    printf("\nArray antes da troca:\n");
    Imprime(array);

    quicksort(array, 0, 4);
    
    printf("\nDepois da troca:\n");
    Imprime(array);

    return 0;
}