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
  if (pq != NULL || pq->size != 0){
    return pq->heapArray[0].data;
  }
  
    return NULL;
}



void heap_push(Heap* pq, void* data, int priority){

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
