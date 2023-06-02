#include <stdio.h>
#include <stdbool.h>
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

int front(Queue *queue){
  return !isEmpty(queue) ? queue->data[queue->front] : -1;
}

void enqueue(Queue *queue, int newValue) {
  if(!isFull(queue)) {
    if(isEmpty(queue)) {
      queue->front++;
      queue->data[++queue->rear] = newValue;
      return;
    }
    queue->data[++queue->rear] = newValue;
    return;
  }
  printf("Queue penuh!\n");
}

void dequeue(Queue *queue){
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

void tingkat_keparahan(Queue *queue) {
  for(int i = queue->front; i < queue->rear + 1; i++) {
    if(queue->data[i] > 0 && queue->data[i] <= 10) {
      if(queue->data[i] <= 5) {
        printf("ditangani dokter umum");
      } else {
        printf("ditangani dokter spesialis");
      }
    } else {
      printf("tingkat keparahan invalid!");
    }
    printf("\n");
  }
}

int main() {
  Queue pasien;
  init(&pasien);

  int input;
  while(pasien.rear < 9) {
    scanf("%d", &input);
    enqueue(&pasien, input);
  }

  tingkat_keparahan(&pasien);
  return 0;
}