#include <stdio.h>
#define SIZE 10
#define SUCCESS 0
#define ERROR (-1)

/* Struct to hold an array and its size and sum of elements */
struct arrayLength{
    int arrInt[SIZE]; /* Array of integers */
    int arrSize; /* Size of the array */
    int arrAdd; /* Sum of the elements in the array */
};
typedef struct arrayLength arrayLength_t;

/* Function to print the array */
int printArr(arrayLength_t *);

/* Function to initialize the array */
int initArray(arrayLength_t *);

/* Function to add an element to the array */
int addElement(arrayLength_t *, int);

/* Function to get the size of the array */
int getArrSize(arrayLength_t *);

/* Function to get the sum of the elements in the array */
int getArrAdd(arrayLength_t *);

/* Function to get an element from the array */
int getElement(arrayLength_t *, int);

/* Function to set an element in the array */
int setElement(arrayLength_t *, int, int);

/* Function to reset the array */
int resetArr(arrayLength_t *);

/* Function to add an element to the array and print the array */
void addElementAndPrint(arrayLength_t *, int);

/* Main function */
int main(){
    /* Variable declarations */
    arrayLength_t arrEst, al1, al2;
    int i, a=0, v=-1;

    /* Initialize array and print it */
    if(initArray(&arrEst) == SUCCESS){
        printf("Array inicializado: ");
        printArr(&arrEst);
    }else{
        printf("Error al inicializar el array.\n");
    }

    /* Add elements to the array and print it */
    addElementAndPrint(&arrEst, 22);
    addElementAndPrint(&arrEst, 44);
    addElementAndPrint(&arrEst, 24);

    /* Get and print the size of the array */
    printf("El número total de elementos actualmente en arrInt es: %d\n", getArrSize(&arrEst));

    /* Get and print the sum of the elements in the array */
    printf("La suma total de los elementos almacenados actualmente en arrInt: %d\n", getArrAdd(&arrEst));

    /* Get and print an element from the array */
    printf("El elemento arrInt[%d] es: %d\n", 1, getElement(&arrEst, 1));

    /* Set an element in the array and print it */
    if (setElement(&arrEst, 32, 2) == SUCCESS){
        printf("Elemento reemplazado con éxito: ");
        printArr(&arrEst);
    }else{
        printf("-1\n");
    }

    /* Reset the array and print it */
    if (resetArr(&arrEst) == SUCCESS){
        printf("El array ha vuelto a sus valores predeterminados");
        printArr(&arrEst);
    }else{
        printf("Error al volver a inicializar el array\n");
    }

    /* Initialize two arrays */
    initArray(&al1);
    initArray(&al2);

    /* Add elements to the first array and print it */
    for(i=0; i<SIZE; i++){
        addElement(&al1, a);
        a=a+10;
    }
    printf("Elementos añadidos en al1 con éxito: ");
    printArr(&al1);

    /* Set elements in the first array and print it */
    for(i=0; i<SIZE; i++){
        v=v+2;
        setElement(&al1, v, i);
    }
    printf("Cambios en al1 implementados: ");
    printArr(&al1);

    /* Add elements from the first array to the second array */
    for(i=0; i<SIZE; i++){
        v=v+2;
        addElement(&al2, al1.arrInt[i]);
    }

    /* Add elements to the second array and print it */
    for(i=0; i<SIZE; i++){
        addElement(&al2, i);
    }
    printf("Elementos añadidos en al2 correctamente: ");
    printArr(&al2);
}

/* Function to add an element to the array and print the array */
void addElementAndPrint(arrayLength_t *arr, int element){
    if(addElement(arr, element) == SUCCESS){
        printf("Elemento añadido con éxito: ");
        printArr(arr);
    }else{
        printf("Error al añadir el elemento\n");
    }
}

/* Function to print the array */
int printArr(arrayLength_t *a1){
    int i;
    printf("{[");
    for(i = 0; i < SIZE; i++){
        printf("%d", a1->arrInt[i]);
        if(i < SIZE - 1) printf(", ");
    }
    printf("] %d, %d}\n", a1->arrSize, a1->arrAdd);
    return SUCCESS;
}

/* Function to initialize the array */
int initArray(arrayLength_t *a2){
    int i;
    for(i=0; i<SIZE; i++){
        (*a2).arrInt[i]=-1;
    }
    (*a2).arrSize=0;
    (*a2).arrAdd=0;
    if (a2->arrSize == 0 && a2->arrAdd == 0){
        return SUCCESS;
    }else{
        return ERROR;
    }
}

/* Function to add an element to the array */
int addElement(arrayLength_t *a3, int v){
    if((*a3).arrSize < SIZE && (*a3).arrSize >= 0 && v >= 0){
        (*a3).arrInt[(*a3).arrSize] = v;
        (*a3).arrSize++;
        (*a3).arrAdd += v;
        return SUCCESS;
    }else{
        return ERROR;
    }
}

/* Function to get the size of the array */
int getArrSize(arrayLength_t *a4){
    return (*a4).arrSize;
}

/* Function to get the sum of the elements in the array */
int getArrAdd(arrayLength_t *a5){
    return a5->arrAdd;
}

/* Function to get an element from the array */
int getElement(arrayLength_t *a6, int i){
    if(0<=i && i<a6->arrSize){
        return a6->arrInt[i];
    }else{
        return ERROR;
    }
}

/* Function to set an element in the array */
int setElement(arrayLength_t *a7, int v, int i){
    if (0<=i && i<(*a7).arrSize && v>=0){
        (*a7).arrAdd=(*a7).arrAdd-((*a7).arrInt[i]);
        (*a7).arrInt[i]=v;
        (*a7).arrAdd+=(*a7).arrInt[i];
        return SUCCESS;
    }else{
        return ERROR;
    }
}

/* Function to reset the array */
int resetArr (arrayLength_t *a8){
    return initArray(a8);
}