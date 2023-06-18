#include <stdio.h>
#include <stdlib.h>

// Deklarasi node dengan menggunakan struct Node.
// Di dalamnya, terdapat pointer prev yang mengarah ke node sebelumnya,
// num digunakan untuk menyimpan bilangan, 
// dan pointer next yang mengarah ke node selanjutnya.
struct Node {
  struct Node *prev;
  int num;
  struct Node *next;
};

// Membuat sebuah alias dalam membentuk sebuah node dengan menyimpan pointernya.
typedef struct Node *node;

// insertNilai() => digunakan untuk memasukkan sebuah bilangan ke akhir list.
node insertNilai(node head) {
  // Inisialisasi sebuah node baru dengan untuk menyimpan data baru.
  node nilai_baru = (node)malloc(sizeof(struct Node));

  // Meminta masukan dari user untuk dimasukkan ke dalam num di node,
  printf("Masukkan nilai: ");
  scanf("%d", &nilai_baru->num);

  // Pointer prev pada nilai baru akan menjadi NULL.
  nilai_baru->prev = NULL;
  // Pointer next pada nilai baru akan merujuk ke head.
  nilai_baru->next = head;

  // Jika head tidak bernilai NULL, 
  // maka pointer prev pada head akan merujuk ke nilai baru.
  if(head != NULL) {
    head->prev = nilai_baru;
  }

  // Update head menjadi nilai baru.
  head = nilai_baru;
  // Mengembalikan head yang sudah diupdate.
  return head;
}

// reverse() => digunakan untuk membalikkan posisi node secara keseluruhan. 
node reverse(node head) {
  // Inisialisasi node curr dengan nilai head.
  node curr = head;
  // Inisialisasi node temp dengan nilai NULL.
  node temp = NULL;

  // Lakukan perulangan hingga node curr bernilai NULL.
  while(curr != NULL) {
    // Update node temp menjadi pointer prev pada curr.
    temp = curr->prev;
    // Pointer prev pada curr akan merujuk ke pointer next pada curr.
    curr->prev = curr->next;
    // Pointer next pada curr akan merujuk ke temp.
    curr->next = temp;
    // Update node curr menjadi pointer prev pada curr.
    curr = curr->prev;
  }

  // Jika temp tidak bernilai NULL, 
  // maka head akan merujuk ke pointer prev pada temp.
  if(temp != NULL) {
    head = temp->prev;
  }

  // Mengembalikan head yang sudah diupdate.
  return head;
}

// view() => digunakan untuk melihat seluruh isi list.
void view(node head) {
  // Inisialisasi node bernama curr untuk melacak node saat ini di dalam list.
  node curr = head;
  
  // Jika node curr bernilai NULL,
  if(curr == NULL) {
    // Maka cetak bahwa data kosong.
    printf("Data Kosong!");
  } else {
    // Jika node curr tidak kosong, 
    // maka lacak setiap node yang ada di dalam list.
    // Lakukan perulangan hingga node curr bernilai NULL.
    while(curr != NULL) {
      // Cetak bilangan yang ada di dalam node curr
      printf("%d ", curr->num);
      // Update node curr menjadi node selanjutnya.
      curr = curr->next;
    }
  }
}

int main() {
  printf("------ PROGRAM REVERSE DLL STACK ------\n");
  // Inisialisasi node bernama head dengan nilai awal, yaitu NULL.
  node head = NULL;
  // Deklarasi variabel bernama lanjut bertipe data integer.
  int lanjut;

  // Lakukan perulangan berikut terlebih dahulu hingga input dari user bernilai 999.
  do {
    // Update node head dengan memanggil fungsi insertNilai(); 
    head = insertNilai(head);
    // Meminta masukan dari user untuk menambah node ke dalam list.
    printf("Tambah nilai lagi? 999 = Exit : ");
    scanf("%d", &lanjut);
  } while(lanjut != 999);

  // Memanggil fungsi view() untuk menampilkan seluruh bilangan sebelum direverse.
  printf("\nStack sebelum di reverse: ");
  view(head);

  // Update node head dengan memanggil fungsi reverse().
  // Digunakan untuk membalikkan posisi node secara keseluruhan.
  head = reverse(head);

  // Memanggil fungsi view() untuk menampilkan seluruh bilangan setelah direverse.
  printf("\nStack setelah di reverse: ");
  view(head);

  return 0;
}