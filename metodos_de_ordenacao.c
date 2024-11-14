#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubbleSort(int *arr, int n)
{
    int temporario;
    
    for(int base = 0; base < n ; base++)
    {
        for(int comparador = 0; comparador < n - base -1 ; comparador++)
        {    
            if(arr[comparador] > arr[comparador + 1])
            {
              temporario = arr[comparador];
              arr[comparador] = arr[comparador + 1];
              arr[comparador + 1] = temporario;
            }
        }
    }
}
void selectionSort(int *arr, int n)
{
  int Indice;
  int *p;
    for (Indice = 0; Indice < n - 1; Indice++)
    {  
        int menor = arr[Indice];
        for (int Indice2 = Indice ; Indice2 < n; Indice2++)
        {
            if (menor >= arr[Indice2])
            {
                menor = arr[Indice2];
                p = &arr[Indice2];
            }
        }
        int Temp = arr[Indice];
        arr[Indice] = menor;
        *p = Temp;
    }
}


void insertionSort(int *arr, int n)
{
    for(int base = 1; base < n ; base++)
    {
        int chave = arr[base];
        int ordenado = base - 1;
        while(ordenado >=0 && arr[ordenado] > chave)
        {
            arr[ordenado + 1] = arr[ordenado];
            ordenado--;
        }
        arr[ordenado + 1] = chave;
    }
}


int* junta_tudo_organizado(int *arr1, int *arr2, int n1, int n2)
{
    int *arr_reconstruido = malloc(sizeof(int) * (n1 + n2));
    int tamanho1 = 0;
    int tamanho2 = 0;


        while (tamanho1 < n1 && tamanho2 < n2)
        {
            if (arr1[tamanho1] <= arr2[tamanho2])
            {
                arr_reconstruido[tamanho1 + tamanho2] = arr1[tamanho1];
                tamanho1++;
            } else
            {
                arr_reconstruido[tamanho1 + tamanho2] = arr2[tamanho2];
                tamanho2++;
            }
        }


        while (tamanho1 < n1)
        {
            arr_reconstruido[tamanho1 + tamanho2] = arr1[tamanho1];
            tamanho1++;
        }
        while (tamanho2 < n2)
        {
            arr_reconstruido[tamanho1 + tamanho2] = arr2[tamanho2];
            tamanho2++;
        }
    return arr_reconstruido;
}


void mergeSort(int *arr, int n)
{
    if (n > 1)
    {
        int novo_tamanho = n / 2;
        int novo_arr[novo_tamanho];
        int novo_arr2[n - novo_tamanho];
       
        for (int i = 0; i < novo_tamanho; i++)
            novo_arr[i] = arr[i];
        for (int i = novo_tamanho; i < n; i++)
            novo_arr2[i-novo_tamanho] = arr[i];


        mergeSort(novo_arr, novo_tamanho);
        mergeSort(novo_arr2, n - novo_tamanho);


        int *arr_ordenado = junta_tudo_organizado(novo_arr, novo_arr2, novo_tamanho, n - novo_tamanho);


        for (int k = 0; k < n; k++)
            arr[k] = arr_ordenado[k];


        free(arr_ordenado);
    }
}



void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}



int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;


    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}



void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void maxHeapify(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;


    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }


    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }


    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}


void heapSort(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }


    for (int i = n - 1; i >= 1; i--)
    {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}




int main()
{
    int arr[10];
    int n = sizeof(arr) / sizeof(arr[0]);
    int arr0[n];
    int arr1[n];
    int arr2[n];
    int arr3[n];
    int arr4[n];
    int arr5[n];
   
    srand(time(NULL));


    for (int i=0; i<n; i++)
    {
        arr[i] = rand() % 100;
        arr0[i] = arr[i];
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i]= arr[i];
        arr4[i] = arr[i];
        arr5[i] = arr[i];
    }

    printf("Vetor Original: {");
    for (int i = 0; i < n; i++)
        printf("%d, ", arr[i]);
    printf("\b\b}\n\n");
    


// Printa BubbleSort


    clock_t inicio, fim;
    double tempo_cpu;
   
    inicio = clock();
    bubbleSort(arr0, n);
    fim = clock();


    
    printf("\nVetor Ordenado: {");
    for (int i = 0; i < n; i++)
        printf("%d, ", arr0[i]);
    printf("\b\b}\n");
    
   
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
   
    printf("Tempo de execução BubbleSort: %f segundos\n", tempo_cpu);
   
// Printa SelectionSort




    inicio = clock();
    selectionSort(arr1, n);
    fim = clock();


    
    printf("\nVetor Ordenado: {");
    for (int i = 0; i < n; i++)
        printf("%d, ", arr1[i]);
    printf("\b\b}\n");
    
   
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
   
    printf("Tempo de execução SelectionSort: %f segundos\n", tempo_cpu);


// Printa InsertionSort




    inicio = clock();
    insertionSort(arr2, n);
    fim = clock();


    
    printf("\nVetor Ordenado: {");
    for (int i = 0; i < n; i++)
        printf("%d, ", arr2[i]);
    printf("\b\b}\n");
    
   
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
   
    printf("Tempo de execução InsertionSort: %f segundos\n", tempo_cpu);


// Printa MergeSort


   
    inicio = clock();
    mergeSort(arr3, n);
    fim = clock();

    
    
    printf("\nVetor Ordenado: {");
    for (int i = 0; i < n ; i++)
        printf("%d, ", arr3[i]);
    printf("\b\b}\n");
    
   
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
   
    printf("Tempo de execução MergeSort: %f segundos\n", tempo_cpu);


// Printa QuickSort




    inicio = clock();
    quickSort(arr4, 0, n - 1);
    fim = clock();


    
    printf("\nVetor Ordenado: {");
    for (int i = 0; i < n; i++)
        printf("%d, ", arr4[i]);
    printf("\b\b}\n");
    
   
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
   
    printf("Tempo de execução QuickSort: %f segundos\n", tempo_cpu);


// Printa HeapSort


   
    inicio = clock();
    heapSort(arr5, n);
    fim = clock();


    
    printf("\nVetor Ordenado: {");
    for (int i = 0; i < n; i++)
        printf("%d, ", arr5[i]);
    printf("\b\b}\n");
    
  
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
   
    printf("Tempo de execução HeapSort: %f segundos\n", tempo_cpu);


   
    return 0;
}