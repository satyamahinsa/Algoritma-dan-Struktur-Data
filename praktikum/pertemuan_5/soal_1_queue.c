#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Inisialisasi struct dengan nama queue menggunakan typedef.
typedef struct {
  // Queue berisi variabel data bertipe data array of integer dengan ukuran 100, 
  // front dan rear bertipe data integer.
  int data[100];
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
bool isFull(queue *input, int banyak_data) {
  // Periksa apakah nilai dari index rear sama dengan banyak data yang diinputkan oleh user.
  // Jika rear bernilai sama dengan banyak data, maka queue penuh.
  return input->rear == banyak_data;
}

// front() => digunakan untuk mengembalikan / melihat nilai data queue paling depan. 
int front(queue *input) {
  // Periksa apakah queue kosong atau tidak.
  // Jika queue tidak kosong, maka kembalikan data queue paling depan.
  // Jika queue kosong, maka kembalikan -1.
  return !isEmpty(input) ? input->data[input->front] : -1;
}

// rear() => digunakan untuk mengembalikan / melihat nilai data queue paling belakang. 
int rear(queue *input) {
  // Periksa apakah queue kosong atau tidak.
  // Jika queue tidak kosong, maka kembalikan data queue paling belakang.
  // Jika queue kosong, maka kembalikan -1.
  return !isEmpty(input) ? input->data[input->rear] : -1;
}

// enqueue() => digunakan untuk menambahkan data baru di belakang queue (index terakhir).
void enqueue(queue *input, int value, int banyak_data) {
  // Jika queue tidak penuh, maka lanjut ke pengecekan selanjutnya.
  if(!isFull(input, banyak_data)) {
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

// compareQueue() => digunakan untuk membandingkan queue mahasiswa dan bubur
// dalam rangka menentukan banyak mahasiswa yang tidak mendapatkan bubur sesuai yang diinginkannya.
int compareQueue(queue *mahasiswa, queue *bubur, int banyak_data) {
  // Inisialisasi variabel point bertipe data integer dengan nilai 1.
  // Point digunakan untuk mengecek apakah masih ada mahasiswa 
  // yang sesuai dengan varian bubur paling depan dalam queue.
  int point = 1;

  // Lakukan perulangan berikut selama queue mahasiswa dan bubur tidak kosong,
  // serta masih ada mahasiswa yang sesuai dengan varian bubur paling depan dalam queue.
  while(!isEmpty(mahasiswa) && !isEmpty(bubur) && point) {
    // Di awal, point = 0 sebagai tanda bahwa jika tidak ada yang sama, maka perulangan berhenti.
    point = 0;

    // Jika varian bubur paling depan sama dengan varian mahasiswa paling depan,
    // maka lakukan dequeue terhadap mahasiswa dan bubur serta banyak data - 1.
    if(front(mahasiswa) == front(bubur)) {
      dequeue(mahasiswa);
      dequeue(bubur);
      banyak_data--;
    } else {
      // Jika tidak sama, maka data mahasiswa paling depan disimpan ke dalam temporary.
      int temp = front(mahasiswa);
      // Lakukan dequeue terhadap data mahasiswa.
      dequeue(mahasiswa);
      // Lakukan enqueue terhadap data mahasiswa dengan memasukkan temp.
      enqueue(mahasiswa, temp, banyak_data);
    }

    // Lakukan perulangan sebanyak banyak data.
    for(int i = 0; i < banyak_data; i++) {
      // Jika masih ada varian mahasiswa yang sama dengan varian bubur paling depan di queue,
      // maka ganti point menjadi 1 agar perulangan berlanjut.
      if(mahasiswa->data[i] == front(bubur)) {
        point = 1;
        break;
      }
    }
  }

  // Mengembalikan nilai banyak_data yang merupakan 
  // banyak mahasiswa yang tidak mendapatkan bubur sesuai yang diinginkannya.
  return banyak_data;
}

int main() {
  // Deklarasi queue dengan nama bubur dan mahasiswa.
  queue bubur, mahasiswa;
  // Lakukan inisialisasi queue kosong pada bubur dan mahasiswa.
  init(&bubur);
  init(&mahasiswa);

  // Deklarasi variabel banyak_data bertipe data integer.
  int banyak_data;
  // Meminta input data dari user untuk dimasukkan ke dalam variabel banyak_data.
  printf("Banyak data: ");
  scanf("%d", &banyak_data);

  // Deklarasi variabel input bertipe data integer.
  int input;
  printf("Student: ");
  // Perulangan ini digunakan untuk memasukkan input user ke dalam queue mahasiswa.
  for(int i = 0; i < banyak_data; i++) {
    scanf("%d", &input);
    enqueue(&mahasiswa, input, banyak_data);
  }

  printf("Bubur: ");
  // Perulangan ini digunakan untuk memasukkan input user ke dalam queue bubur.
  for(int i = 0; i < banyak_data; i++) {
    scanf("%d", &input);
    enqueue(&bubur, input, banyak_data);
  }

  // Memanggil fungsi compareQueue() dalam membandingkan queue mahasiswa dan bubur.
  // Lalu, menampilkan hasil pengembalian nilai banyak_data dari fungsi compareQueue().
  printf("%d", compareQueue(&mahasiswa, &bubur, banyak_data));
  return 0;
}