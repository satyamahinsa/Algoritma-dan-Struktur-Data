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

// reverseData() => digunakan untuk membalikkan posisi node di dalam list.
// node awal menjadi node terakhir dan begitu seterusnya.
node reverseData(node head) {
  // Inisialisasi node head_baru sebagai head yang sudah direverse
  node head_baru = NULL;
  // Inisialisasi node last yang merujuk ke node terakhir di list.
  node last = head->prev;
  // Inisialisasi node curr yang merujuk ke node last
  // Deklarasi node prev untuk merujuk ke node sebelumnya.
  node curr = last, prev;

  // Perulangan berikut dilakukan hingga bertemu dengan node awal di dalam list.
  while(curr->prev != last) {
    // Node prev merujuk ke node sebelumnya.
    prev = curr->prev;
    // Update head_baru dengan memasukkan node curr ke dalam list.
    head_baru = insertLast(head_baru, curr);
    // Update curr menjadi node sebelumnya.
    curr = prev;
  }

  // Update head_baru dengan memasukkan node curr ke dalam list.
  head_baru = insertLast(head_baru, curr);
  // Mengembalikan head_baru yang sudah direverse.
  return head_baru;
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
  // Deklarasi variabel input bertipe data char.
  char input;

  // Lakukan perulangan berikut hingga user melakukan input 'n'.
  do {
    // Update node head dengan memanggil fungsi insertLast().
    head = insertLast(head, createNode());
    // Meminta user untuk memasukkan input dalam melanjutkan perulangan.
    printf("Tambah data lagi? (y/n): ");
    fflush(stdin);
    scanf("%c", &input);
  } while(input != 'n');

  // Menampilkan seluruh data yang ada di dalam list sebelum direverse.
  printf("Sebelum direverse: \n");
  viewData(head);

  // Update head dengan memanggil fungsi reverse().
  head = reverseData(head);

  // Menampilkan seluruh data yang ada di dalam list setelah direverse.
  printf("Setelah direverse: \n");
  viewData(head);
  return 0;
}