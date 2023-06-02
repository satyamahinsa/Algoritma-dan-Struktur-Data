#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Inisialisasi struct dengan nama queue menggunakan typedef.
// Queue berisi variabel data bertipe data array of char dengan ukuran 100, 
// front dan rear bertipe data integer.
typedef struct {
  char data[100];
  int front, rear;
} queue;

// init() => digunakan untuk melakukan inisialisasi sebuah queue kosong.
void init(queue *input) {
  // Memberi nilai index front dan rear dengan nilai -1. 
  input->front = -1;
  input->rear = -1;
}

// isEmpty() => digunakan untuk mengecek apakah sebuah queue kosong atau tidak.
bool isEmpty(queue *input) {
  // Periksa apakah nilai dari index front dan rear bernilai -1 atau tidak.
  // Jika front dan rear bernilai -1, maka queue kosong.
  return input->front == -1 && input->rear == -1;
}

// isFull() => digunakan untuk mengecek apakah sebuah queue penuh atau tidak.
bool isFull(queue *input) {
  // Periksa apakah nilai dari index rear sama dengan panjang string data.
  // Jika rear bernilai sama dengan panjang string data, maka queue penuh.
  return input->rear == strlen(input->data);
}

// front() => digunakan untuk mengembalikan / melihat nilai data queue paling depan. 
int front(queue *input){
  // Periksa apakah queue kosong atau tidak.
  // Jika queue tidak kosong, maka kembalikan data queue paling depan.
  // Jika queue kosong, maka kembalikan -1.
  return !isEmpty(input) ? input->data[input->front] : -1;
}

// enqueue() => digunakan untuk menambahkan data baru di belakang queue (index terakhir).
void enqueue(queue *input, int value) {
  // Jika queue tidak penuh, maka lanjut ke pengecekan selanjutnya.
  if(!isFull(input)) {
    // Jika queue kosong, maka ubah nilai front dan rear di dalam queue.
    if(isEmpty(input)) {
      // Tambah nilai front dan rear dengan 1
      // Lalu, masukkan value ke dalam data paling belakang.
      input->front++;
      input->data[++input->rear] = value;
      return;
    }
    // Jika queue tidak kosong, maka nilai rear + 1,
    // dan masukkan value ke dalam data paling belakang.
    input->data[++input->rear] = value;
    return;
  }
  // Jika queue penuh, maka tampilkan pesan bahwa queue penuh.
  printf("Queue is full!\n");
}

// dequeue() => digunakan untuk menghapus data di depan queue (index terdepan).
void dequeue(queue *queue) {
  // Jika queue tidak kosong, maka lanjut ke pengecekan selanjutnya.
  if(!isEmpty(queue)){
    // Jika nilai front dan rear bernilai 0,
    // maka kurangi nilai front dan rear dengan 1. 
    if(queue->front == 0 && queue->rear == 0){
      queue->front--;
      queue->rear--;
      return;
    }
    // Jika tidak, maka lakukan perulangan berikut
    // untuk menghapus data dengan pergeseran data ke kiri.
    for(int i = queue->front + 1; i < queue->rear + 1; i++){
      queue->data[i - 1] = queue->data[i];
    }
    // Kurangi nilai rear dengan 1 untuk menghapus data terakhir. 
    queue->rear--;
    return;
  }
  
  // Jika queue kosong, maka tampilkan pesan bahwa queue kosong.
  printf("Queue is empty!\n");
}

// karakter_tunggal() => digunakan untuk mengecek apakah di dalam queue terdapat karakter tunggal.
// Fungsi ini mengembalikan -1 jika tidak terdapat karakter tunggal, 
// Sedangkan jika terdapat karakter tunggal, maka mengembalikan nilai index dari karakter tersebut.
int karakter_tunggal(queue *input) {
  // Deklarasi variabel index bertipe data integer untuk menyimpan nilai index setiap pengecekan.
  int index;
  // Perulangan ini digunakan untuk mengecek setiap karakter satu per satu di dalam queue.
  for(int i = 0; i < input->rear + 1; i++) {
    // Inisialisasi nilai index dengan i sebagai index setiap pengecekan.
    index = i;
    // Perulangan ini digunakan untuk membandingkan karakter 
    // pada index ke-i dengan index ke-i+1 (index selanjutnya).
    for(int j = i + 1; j < input->rear + 1; j++) {
      // Jika terdapat karakter yang sama, maka ubah nilai index menjadi -1 dan hentikan perulangan.
      if(input->data[i] == input->data[j]) {
        index = -1;
        break;
      }
    }
    // Lakukan dequeue setelah pengecekan pada index yang sudah tidak digunakan.
    dequeue(input);
    // Jika selama perulangan tadi tidak terdapat karakter yang sama,
    // maka dapat dipastikan karakter pada index tersebut tunggal.
    if(index != -1) {
      return index;
    }
  }

  return index;
}


int main() {
  // Deklarasi variabel string bertipe data queue.
  queue string;
  // Lakukan inisialisasi queue kosong pada string.
  init(&string);

  // Deklarasi variabel input bertipe data array of char dengan ukuran 100.
  char input[100];
  // Meminta input data kepada user untuk dimasukkan ke dalam variabel input. 
  scanf("%s", &input);

  // Perulangan ini digunakan untuk memasukkan data setiap input sesuai dengan indexnya ke dalam queue.
  for(int i = 0; i < strlen(input); i++) {
    enqueue(&string, input[i]);
  }

  // Menampilkan hasil pengecekan karakter tunggal di dalam queue.
  printf("%d", karakter_tunggal(&string));
  return 0;
}