#include <stdio.h>
#include <stdlib.h>

// Deklarasi node dengan menggunakan struct SingleLinkedList.
// Di dalamnya, terdapat variabel jarak bertipe data integer dan
// pointer next yang merujuk ke node selanjutnya.
struct SingleLinkedList {
  int jarak;
  struct SingleLinkedList *next;
};

// Membuat sebuah alias dalam membentuk node dengan menyimpan pointernya.
typedef struct SingleLinkedList *node;

// tambahTerminal() => digunakan untuk menambahkan terminal baru sebagai node.
node tambahTerminal(node head) {
  // Inisialisasi sebuah terminal baru untuk menyimpan node baru.
  node terminal_baru = (node)malloc(sizeof(struct SingleLinkedList));
  // Meminta user untuk memasukkan nilai jarak dari terminal saat ini ke terminal selanjutnya.
  scanf("%d", &terminal_baru->jarak);

  // Jika belum ada node di dalam list, maka node terminal_baru menjadi head.
  if(head == NULL) {
    // Pointer next pada node terminal_baru merujuk ke node itu sendiri.
    terminal_baru->next = terminal_baru;
    // Node terminal_baru menjadi head.
    head = terminal_baru;
  } else {
    // Jika sudah ada node di dalam list,
    // maka lakukan pelacakan untuk mengetahui node terakhir di dalam list.
    node tail = head;
    while(tail->next != head) {
      tail = tail->next;
    }

    // Setelah mendapatkan node terakhir,
    // maka ubah pointer next pada node terakhir merujuk ke node terminal_baru.
    tail->next = terminal_baru;
    // Pointer next pada node terminal_baru merujuk ke head.
    terminal_baru->next = head;
  }
  
  // Mengembalikan head yang sudah diupdate.
  return head;
}

// terminalTerakhir() => digunakan untuk menentukan di terminal mana Andi turun dari bus.
void terminalTerakhir(node head, int jarak_tempuh) {
  // Inisialisasi node terminal_terakhir yang merujuk ke head di awal.
  node terminal_terakhir = head;
  // Inisialisasi variabel nama_terminal bertipe data char dengan nilai awal, yaitu 64.
  // Variabel ini digunakan untuk memberi nama terminal yang dimulai dari A.
  char nama_terminal = 64;
  // Inisialisasi variabel total_jarak_bus dan putaran bertipe data integer.
  // Variabel total_jarak_bus digunakan untuk menghitung total jarak bus setelah melewati suatu terminal.
  // Variabel putaran digunakan untuk menentukan banyak putaran yang dilakukan oleh bus 
  // di seluruh terminal secara berulang.
  int total_jarak_bus = 0, putaran = -1;

  // Perulangan berikut dilakukan selama jarak tempuh yang ditentukan oleh Andi
  // masih lebih besar dari total jarak bus setelah melewati suatu terminal.
  while(jarak_tempuh > total_jarak_bus) {
    // total_jarak_bus ditambah oleh nilai jarak setiap terminal saat ini ke terminal berikutnya.
    total_jarak_bus += terminal_terakhir->jarak;
    // nama_terminal ditambah 1 untuk mendapatkan nama terminal saat ini.
    nama_terminal++;
    // Jika terminal_terakhir sama dengan head, maka bus telah melewati seluruh terminal
    // dan sudah melakukan 1 putaran.
    if(terminal_terakhir == head) {
      // nama_terminal diubah menjadi 65 sebagai representasi huruf A.
      nama_terminal = 65;
      // putaran ditambah 1.
      putaran++;
    }
    // terminal_terakhir diubah menjadi terminal selanjutnya.
    terminal_terakhir = terminal_terakhir->next;
  }

  // Menampilkan Andi turun di terminal tujuannya.
  printf("Andi turun di stasiun %c\n", nama_terminal);
  // Jika putaran lebih dari 0, maka menampilkan bahwa Andi telah melewati seluruh terminal 
  // dan kembali ke terminal awal.
  if(putaran > 0) {
    printf("Andi telah berputar sebanyak %d putaran\n", putaran);
  }
}

int main() {
  // Inisialisasi node head sebagai rute dari bus dengan nilai awal, yaitu NULL.
  node head = NULL;

  // Deklarasi variabel jarak_tempuh dan banyak_terminal.
  // jarak_tempuh digunakan untuk mengetahui jarak yang ingin Andi tempuh.
  // banyak_terminal digunakan untuk mengetahui banyak terminal di kota tempat Andi tinggal.
  int jarak_tempuh, banyak_terminal;
  // Meminta user untuk memasukkan nilai jarak tempuh dan banyak terminal.
  scanf("%d %d", &jarak_tempuh, &banyak_terminal);

  // Perulangan dilakukan sebanyak terminal yang ada di kota tempat Andi tinggal.
  for(int i = 0; i < banyak_terminal; i++) {
    // Update node head dengan memanggil fungsi tambahTerminal().
    head = tambahTerminal(head);
  }

  // Memanggil fungsi terminalTerakhir(). 
  terminalTerakhir(head, jarak_tempuh);
  return 0;
}