#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10

typedef struct {
  int data[MAX];
  int front;
  int rear;
} Queue;

void init(Queue *queue) {
  queue->front = -1;
  queue->rear = -1;
}

bool isEmpty(Queue *queue) {
  return queue->front == -1 && queue->rear == -1;
}

bool isFull(Queue *queue) {
  return queue->rear == MAX - 1;
}

int size(Queue *queue) {
  return queue->rear + 1;
}

int front(Queue *queue) {
  return !isEmpty(queue) ? queue->data[queue->front] : -1;
}

void enqueue(Queue *queue, int newValue) {
  if(!isFull(queue)){
    if(isEmpty(queue)){
      queue->front++;
      queue->data[++queue->rear] = newValue;
      return;
    }
    queue->data[++queue->rear] = newValue;
    return;
  }
  printf("Queue penuh!\n");
}

void dequeue(Queue *queue) {
  if(!isEmpty(queue)){
    if(queue->front == 0 && queue->rear == 0){
      queue->front--;
      queue->rear--;
      return;
    }
    for(int i = queue->front + 1; i < queue->rear + 1; i++){
      queue->data[i - 1] = queue->data[i];
    }
    queue->rear--;
    return;
  }
  printf("Queue kosong!\n");
}

void printQueue(Queue *queue) {
  if(!isEmpty(queue)){
    for(int i = queue->front; i < queue->rear + 1; i++){
      printf("%d ", queue->data[i]);
    }
    return;
  }
  printf("Queue kosong!");
}

int main(){
  Queue queue;
  init(&queue);

  int option;
  
  while(1) {
    printf("---------------------------------------------------------------\n");
    printf("Queue: ");
    printQueue(&queue);
    printf("\t|\tFront: %d", front(&queue));
    printf("\t|\tSize: %d\n", size(&queue));
    printf("---------------------------------------------------------------\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Exit\n");
    printf("---------------------------------------------------------------\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &option);
    if(option == 1) {
      int value;
      printf("Masukkan nilai baru: ");
      scanf("%d", &value);
      enqueue(&queue, value);
    } else if(option == 2) {
      dequeue(&queue);
    } else if(option == 3) {
      break;
    } else {
      printf("Opsi tidak valid!\n");
    }
    system("cls"); // gunakan system("cls") pada sistem operasi Windows
  }
  return 0;
}