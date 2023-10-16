#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
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
  //si esta vacio
  if(pq->size == 0){
    return;
  }

  //Eliminar el mayor elemento
  pq->heapArray[0]=pq->heapArray[pq->size-1];
  pq->size=pq->size-1;

  //Reordenamos
  int aux=0, HijoIz, HijoDer, Padre;

  while(true){
    HijoIz = 2 * aux + 1;
    HijoDer = 2 * aux + 2;

    //Si el izquierdo es mayor
    if(HijoIz < pq->size && pq->heapArray[HijoIz].priority > pq->heapArray[aux].priority){
      Padre = HijoIz;
    }
    else{
      Padre = aux;
    }

    //Si el derecho es mayor
    if(HijoDer < pq->size && pq->heapArray[HijoDer].priority > pq->heapArray[Padre].priority){
      Padre = HijoDer;
    }

    if(aux == Padre){
      break;
    }

    heapElem Nuevo = pq->heapArray[aux];
    pq->heapArray[aux] = pq->heapArray[Padre];
    pq->heapArray[Padre] = Nuevo;
  }

}

Heap* createHeap(){
  Heap *Nuevo= (Heap*) malloc(sizeof(Heap));

  Nuevo->capac = 3;
  Nuevo->heapArray = (heapElem*) malloc(sizeof(heapElem) * Nuevo->capac);
  Nuevo->size=0;

   return Nuevo;
}
