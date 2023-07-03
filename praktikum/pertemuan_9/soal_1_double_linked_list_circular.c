#include <stdio.h>
#include <stdlib.h>

// Deklarasi node dengan menggunakan struct DoubleLinkedListCircular.
// Di dalamnya, terdapat variabel data bertipe data integer,
// pointer prev yang merujuk ke node sebelumnya dan pointer next yang merujuk ke node selanjutnya
struct DoubleLinkedListCircular {
  struct DoubleLinkedListCircular *prev;
  int data;
  struct DoubleLinkedListCircular *next;
};

// Membuat sebuah alias dalam membentuk node dengan menyimpan pointernya.
typedef struct DoubleLinkedListCircular *node;

// createNode() => digunakan untuk membuat node baru.
node createNode() {
  // Inisialisasi cariabel node_baru untuk menyimpan node baru.
  node node_baru = (node)malloc(sizeof(struct DoubleLinkedListCircular));
  // Meminta masukkan dari user sebagai data di dalam node.
  printf("Masukkan data: ");
  scanf("%d", &node_baru->data);
  // Mengembalikan node_baru untuk digunakan di dalam list.
  return node_baru;
}

// insertLast() => digunakan untuk menambahkan node baru ke dalam list.
node insertLast(node head, node node_baru) {
  // Jika list masih kosong, maka node_baru akan menjadi head.
  if(head == NULL) {
    // Pointer prev pada node_baru merujuk ke node itu sendiri.
    node_baru->prev = node_baru;
    // Pointer next pada node_baru merujuk ke node itu sendiri.
    node_baru->next = node_baru;
    // node_baru menjadi head.
    head = node_baru;
  // Jika sudah ada node di dalam list, maka tambahkan node_baru ke akhir list.
  } else {
    // Inisialisasi node last yang merujuk ke node terakhir di list.
    node last = head->prev;
    // Pointer next pada node_baru merujuk ke node awal di list.
    node_baru->next = head;
    // Pointer prev pada node_baru merujuk ke node terakhir di list.
    node_baru->prev = last;
    // Pointer prev pada head merujuk ke node_baru.
    head->prev = node_baru;
    // Pointer next pada last merujuk ke node_baru.
    last->next = node_baru;
  }

  // Mengembalikan head yang sudah diupdate.
  return head;
}

// acakData() => digunakan untuk mengacak data yang ada di dalam suatu list.
node acakData(node head, int banyak_data) {
  // Inisialisasi node curr yang merujuk ke head.
  node curr = head;
  int i = 0;

  // Perulangan berikut dilakukan hingga bertemu dengan node terakhir di dalam list.
  do {
    // Inisialisasi variabel random_data bertipe data integer
    // yang berisi bilangan acak antara 1 dan banyak_data.
    int random_data = (rand() % banyak_data) + 1;
    // Inisialisasi node tukar yang merujuk ke node curr.
    node tukar = curr;
    // Lakukan perulangan sebanyak bilangan yang dihasilkan oleh random_data.
    for(int i = 0; i < random_data; i++) {
      // Update node tukar menjadi node selanjutnya.
      tukar = tukar->next;
    }

    // Lakukan pertukaran data antara node curr dan node tukar 
    // dengan melibatkan variabel temp sebagai tempat penampungan data sementara.
    int temp = curr->data;
    curr->data = tukar->data;
    tukar->data = temp;
    curr = curr->next;
    banyak_data--;
  } while(curr != head);
  
  // Mengembalikan head yang sudah diupdate.
  return head;
}

// viewData() => digunakan untuk melihat seluruh data di dalam list.
void viewData(node head) {
  // Inisialisasi node curr yang merujuk ke head.
  node curr = head;

  printf("List: ");
  // Perulangan berikut dilakukan hingga bertemu dengan node terakhir di dalam list.
  while(curr->next != head) {
    // Menampilkan data pada node saat ini.
    printf("%d ", curr->data);
    // Mengubah node curr menjadi node selanjutnya. 
    curr = curr->next;
  }
  // Menampilkan data pada node saat ini.
  printf("%d\n", curr->data);
}

int main() {
  // Inisialisasi node head dengan nilai awal, yaitu NULL.
  node head = NULL;
  // Inisialisasi variabel banyak_data bertipe data integer dengan nilai awal, yaitu 0.
  int banyak_data = 0; 
  // Deklarasi variabel input bertipe data char.
  char input;

  // Lakukan perulangan berikut hingga user melakukan input 'n'.
  do {
    // Update node head dengan memanggil fungsi insertLast().
    head = insertLast(head, createNode());
    // Tambah banyak_data dengan 1 setiap node yang berhasil masuk ke dalam list.
    banyak_data++;
    // Meminta user untuk memasukkan input dalam melanjutkan perulangan.
    printf("Tambah data lagi? (y/n): ");
    fflush(stdin);
    scanf("%c", &input);
  } while(input != 'n');

  // Menampilkan seluruh data yang ada di dalam list sebelum direverse.
  printf("Sebelum diacak: \n");
  viewData(head);

  // Update head dengan memanggil fungsi acakData().
  head = acakData(head, banyak_data);

  // Menampilkan seluruh data yang ada di dalam list setelah direverse.
  printf("Setelah diacak: \n");
  viewData(head);

  return 0;
}