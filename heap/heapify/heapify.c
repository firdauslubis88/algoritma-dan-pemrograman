/*
  Author: Fakhra Najm
  Email: fnajm09@gmail.com
  
  Topic: Creation of max heap by heapify
*/

#include <stdio.h>
#include <stdlib.h>

int *__HEAP;
int HEAP_SIZE;
void heapify(int index);
void swap(int *parent, int *child);
void createHeap();

int main()
{

  scanf("%d", &HEAP_SIZE);
  createHeap();
  for (int i = 1; i <= HEAP_SIZE; i++)
  {
    printf("%d ", __HEAP[i]);
  }
  printf("\n");

  return 0;
}

void createHeap()
{
  __HEAP = (int *)malloc(sizeof(int) * (HEAP_SIZE + 1));
  __HEAP[0] = 0;
  for (int i = 1; i <= HEAP_SIZE; i++)
    scanf("%d", &__HEAP[i]);
  for (int i = HEAP_SIZE / 2; i > 0; i--)
    heapify(i);
}

void heapify(int index)
{
  for(int i = (index/2)-1; i >= 0; i--){
    int j = index * 2 +1 ;
    while (j < index - 1)
    {
      if (__HEAP[j] < __HEAP[j + 1])
        j = j + 1;
      if (__HEAP[i] < __HEAP[j])
      {
        swap(&__HEAP[i], &__HEAP[j]);
        i = j;
        j = 2*i +1;
      }
      else
        break;
    }
  }
}

void swap(int *parent, int *child)
{
  int temp;
  temp = *parent;
  *parent = *child;
  *child = temp;
}