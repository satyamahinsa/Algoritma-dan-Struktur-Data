#include <stdio.h>
#include <stdlib.h>

// Deklarasi node dengan menggunakan struct SingleLinkedList.
// Di dalamnya, terdapat variabel bagian bertipe data char dan
// pointer next yang merujuk ke node selanjutnya.
struct SingleLinkedList {
  char bagian;
  struct SingleLinkedList *next;
};

// Membuat sebuah alias dalam membentuk node dengan menyimpan pointernya.
typedef struct SingleLinkedList *node;

// tambahBagian() => digunakan untuk menambah bagian baru sebagai node pada tubuh ular.
node tambahBagian(node head) {
  // Inisialisasi sebuah bagian baru untuk menyimpan node baru.
  node bagian_baru = (node)malloc(sizeof(struct SingleLinkedList));
  // Meminta user untuk memasukkan bagian tubuh pada ular, 
  // yaitu T (bagian tidak beracun) dan B (bagian beracun).
  printf("Bagian (T/B): ");
  fflush(stdin);
  scanf("%c", &bagian_baru->bagian);

  // Jika belum ada node di dalam list, maka node bagian_baru menjadi head.
  if(head == NULL) {
    // Pointer next pada node bagian_baru merujuk ke node itu sendiri.
    bagian_baru->next = bagian_baru;
    // Node bagian_baru menjadi head.
    head = bagian_baru;
  } else {
    // Jika sudah ada node di dalam list,
    // maka lakukan pelacakan untuk mengetahui node terakhir di dalam list.
    node tail = head;
    while(tail->next != head) {
      tail = tail->next;
    }

    // Setelah mendapatkan node terakhir,
    // maka ubah pointer next pada node terakhir merujuk ke node bagian_baru.
    tail->next = bagian_baru;
    // Pointer next pada node bagian_baru merujuk ke head.
    bagian_baru->next = head;
  }
  
  // Mengembalikan head yang sudah diupdate.
  return head;
}

// ularKanibal() => digunakan untuk mengetahui banyak ekor yang telah dimakan 
// hingga ular memakan ekor yang beracun dan mati.
void ularKanibal(node head) {
  // Inisialisasi node tail merujuk ke head.
  node tail = head;
  // Inisialisasi variabel count bertipe data integer dengan nilai awal, yaitu 0.
  int count = 0;

  // Perulangan berikut dilakukan hingga ular memakan ekor yang beracun.
  while(1) {
    // Setiap perulangan kembalikan node tail menjadi head.
    tail = head;

    // Lakukan pelacakan untuk mengetahui node sebelum node terakhir di dalam list.
    while(tail->next->next != head) {
      tail = tail->next;
    }
    // Variabel count ditambah 1 untuk mengetahui bahwa ular sudah memakan 1 bagian tubuh.
    count++;
    
    // Jika node terakhir di dalam list memiliki ekor yang beracun, maka perulangan dihentikan.
    if(tail->next->bagian == 'B') {
      // Menampilkan pesan berikut di akhir.
      printf("Ular mati ketika memakan ekornya sebanyak %d kali", count);
      break;
    } else {
      // Jika node terakhir di dalam list memiliki ekor yang tidak beracun, 
      // maka ular tidak akan mati dan memakan ekornya sendiri.
      // Inisialisasi node tmp yang merujuk ke node terakhir.
      node tmp = tail->next;
      // Pointer next pada node sebelum node terakhir merujuk ke head.
      tail->next = head;
      // Menghapus memori dari node terakhir.
      free(tmp);
    }
  } 
}

// view() => digunakan untuk melihat seluruh isi list.
void view(node head) {
  // Inisialisasi node tail merujuk ke head.
  node tail = head;

  // Lakukan pelacakan untuk mengetahui node terakhir di dalam list.
  while(tail->next != head) {
    // Menampilkan setiap bagian tubuh ular.
    printf("%c ", tail->bagian);
    // Mengubah node tail menjadi node selanjutnya. 
    tail = tail->next;
  }

  // Menampilkan bagian tubuh ular yang terakhir.
  printf("%c\n", tail->bagian);
}

int main() {
  // Inisialisasi node head sebagai bagian tubuh ular dengan nilai awal, yaitu NULL.
  node head = NULL;
  // Deklarasi variabel input bertipe data char.
  char input;

  // Lakukan perulangan berikut hingga user melakukan input 't'.
  do {
    // Update node head dengan memanggil fungsi tambahBagian().
    head = tambahBagian(head);
    // Meminta user untuk memasukkan input dalam melanjutkan perulangan.
    printf("Input lagi? (y/t): ");
    fflush(stdin);
    scanf("%c", &input);
  } while(input != 't');

  // Menampilkan seluruh bagian ular dengan memanggil fungsi view().
  printf("\nInput:\n");
  view(head);

  // Menampilkan hasil banyak ekor yang telah dimakan oleh ular.
  printf("\nOutput:\n");
  ularKanibal(head);
  return 0;
}