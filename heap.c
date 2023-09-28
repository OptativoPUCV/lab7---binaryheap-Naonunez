#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if (pq == NULL || pq->size == 0){
    return NULL;
  }
  else{
    return pq->heapArray[0].data;
  }   
}


void heap_push(Heap* pq, void* data, int priority){
  if (pq->size == pq->capac){
    pq->capac = pq->capac * 2 + 1;
    pq->heapArray = (heapElem*) realloc(pq->heapArray, sizeof(heapElem) * pq->capac);
  }
  int Nuevo = pq->size;
  pq->heapArray[Nuevo].data = data;
  pq->heapArray[Nuevo].priority = priority;
  pq->size= pq->size + 1;

  heapElem Aux, Padre;
  while(Nuevo != 0){
    Padre = pq->heapArray[(Nuevo-1) / 2];
    if(Padre.priority > pq->heapArray[Nuevo].priority){
      break;
    }
    Aux = Padre;
    pq->heapArray[(Nuevo-1)/2] = pq->heapArray[Nuevo];
    pq->heapArray[Nuevo] = Aux; 

    Nuevo= (Nuevo -1)/2;
  }
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap *Nuevo= (Heap*) malloc(sizeof(Heap));

  Nuevo->capac = 3;
  Nuevo->heapArray = (heapElem*) malloc(sizeof(heapElem) * Nuevo->capac);
  Nuevo->size=0;

   return Nuevo;
}
