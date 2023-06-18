#include <stdio.h>
#include <stdlib.h>

// Deklarasi node dengan menggunakan struct DoubleLinkedList.
// Di dalamnya, terdapat pointer prev yang mengarah ke node sebelumnya,
// data digunakan untuk menyimpan nilai, dan pointer next yang mengarah ke node selanjutnya.
struct DoubleLinkedList {
  struct DoubleLinkedList *prev;
  int data;
  struct DoubleLinkedList *next;
};

// Membuat sebuah alias dalam membentuk sebuah node dengan menyimpan pointernya.
typedef struct DoubleLinkedList *node;

// insertLast() => digunakan untuk memasukkan sebuah node ke akhir list.
node insertLast(node head) {
  // Inisialisasi sebuah node baru untuk menyimpan data baru.
  node node_baru = (node)malloc(sizeof(struct DoubleLinkedList));
  // Inisialisasi node bernama tail untuk mengetahui node terakhir.
  node tail = head;
  
  // Meminta masukan dari user untuk dimasukkan ke dalam data di node baru.
  printf("Masukkan bilangan: ");
  scanf("%d", &node_baru->data);

  // Jika belum ada node di dalam list, maka node baru akan menjadi head.
  if(head == NULL) {
    // Pointer prev pada node baru akan merujuk ke head.
    node_baru->prev = head;
    // Pointer next pada node baru akan merujuk ke head.
    node_baru->next = head;
    // Node baru akan menjadi head.
    head = node_baru;
  } else {
    // Jika sudah ada node di dalam list, 
    // maka lakukan pelacakan untuk mengetahui node terakhir di dalam list.
    while(tail->next != NULL) {
      tail = tail->next;
    }

    // Pointer next pada node terakhir akan merujuk ke node baru.
    tail->next = node_baru;
    // Pointer prev pada node baru akan merujuk ke node terakhir.
    node_baru->prev = tail;
    // Pointer next pada node baru akan menjadi NULL. 
    node_baru->next = NULL;
  }

  // Mengembalikan head yang sudah diupdate.
  return head;
}

// view() => digunakan untuk melihat seluruh isi list.
void view(node head) {
  // Inisialisasi node bernama curr untuk melacak node saat ini di dalam list.
  node curr = head;
  // Deklarasi node bernama lastNode untuk mendapatkan node terakhir.
  node lastNode;
  
  // Mencetak seluruh bilangan secara First In First Out.
  printf("Data Bilangan yang Telah Diinputkan secara FIFO: ");
  // Jika node curr bernilai NULL,
  if(curr == NULL) {
    // Maka tampilkan pesan bahwa data kosong.
    printf("Data Kosong!");
  } else {
    // Jika node curr tidak kosong,
    printf("\n");
    // Maka lacak setiap node yang ada di dalam list.
    // Lakukan perulangan hingga node curr bernilai NULL.
    while(curr != NULL) {
      // Cetak data yang ada di dalam node curr.
      printf("%d\t", curr->data);
      // Update lastNode menjadi node curr.
      lastNode = curr;
      // Update node curr menjadi node selanjutnya.
      curr = curr->next;
    }

    // Update curr menjadi lastNode sebagai perulangan dari akhir node.
    curr = lastNode;
    printf("\n");


    // Mencetak seluruh bilangan secara Last In First Out.
    printf("Data Bilangan yang Telah Diinputkan secara LIFO: ");
    printf("\n");
    // Lakukan perulangan hingga node curr bernilai NULL.
    while(curr != NULL) {
      // Cetak data yang ada di dalam node curr.
      printf("%d\t", curr->data);
      // Update node curr menjadi node sebelumnya.
      curr = curr->prev;
    }
  }
}

int main() {
  printf("------ PROGRAM DLL LIFO & FIFO ------\n");
  // Inisialisasi node bernama head dengan nilai awal, yaitu NULL.
  node head = NULL;
  // Deklarasi variabel bernama input bertipe data char.
  char input;

  // Lakukan perulangan berikut terlebih dahulu hingga input dari user bernilai 't'.
  do {
    // Update node head dengan memanggil fungsi insertLast().
    head = insertLast(head);
    // Meminta masukan dari user untuk menambah node ke dalam list.
    printf("Ada data lagi (y/t): ");
    // fflush(stdin) digunakan untuk menghapus stream/buffer yang ada.
    fflush(stdin);
    scanf("%c", &input);
  } while(input != 't');

  // Memanggil fungsi view() untuk menampilkan seluruh bilangan secara FIFO maupun LIFO.
  view(head);
  return 0;
}