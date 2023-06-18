#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Deklarasi node dengan menggunakan struct DataPasien.
// Di dalamnya, terdapat pointer prev yang mengarah ke node sebelumnya,
// nama digunakan untuk menyimpan nama pasien, 
// dan pointer next yang mengarah ke node selanjutnya.
struct DataPasien {
  struct DataPasien *prev;
  char nama[100];
  struct DataPasien *next;
};

// Membuat sebuah alias dalam membentuk sebuah node dengan menyimpan pointernya.
typedef struct DataPasien *pasien; 

// tambahAntrian() => digunakan untuk menambahkan data pasien ke dalam antrian.
pasien tambahAntrian(pasien head) {
  // Inisialisasi pasien baru untuk menyimpan nama pasien.
  pasien pasien_baru = (pasien)malloc(sizeof(struct DataPasien));
  
  // Meminta masukan dari user untuk dimasukkan ke dalam nama di node.
  printf("Masukkan nama pasien: ");
  scanf("%s", &pasien_baru->nama);

  // Inisialisasi node pasien bernama tail untuk mengetahui node terakhir.
  pasien tail = head;

  // Jika belum ada node di dalam antrian, 
  if(head == NULL) {
    // Pointer prev pada pasien baru akan merujuk ke head.
    pasien_baru->prev = head;
    // Pointer next pada pasien baru akan merujuk ke head.
    pasien_baru->next = head;
    // Pasien baru akan menjadi head.
    head = pasien_baru;
  } else {
    // Jika sudah ada node di dalam antrian,
    // maka lakukan pelacakan untuk mengetahui node terakhir di dalam antrian.
    while(tail->next != NULL) {
      tail = tail->next;
    }

    // Pointer next pada node terakhir akan merujuk ke pasien baru.
    tail->next = pasien_baru;
    // Pointer prev pada pasien baru akan merujuk ke tail.
    pasien_baru->prev = tail;
    // Pointer next pada pasien baru akan menjadi NULL.
    pasien_baru->next = NULL;
  }

  // Menampilkan pesan bahwa data berhasil dimasukkan.
  printf("Data berhasil dimasukkan!\n");
  // Mengembalikan head yang sudah diupdate.
  return head;
}

// hapusAntrian() => digunakan untuk menghapus data pasien dari dalam antrian.
pasien hapusAntrian(pasien head) {
  // Jika belum ada node di dalam antrian,
  // maka tampilkan pesan bahwa data kosong.
  if(head == NULL) {
    printf("Data kosong!\n");
  } else {
    // Jika sudah ada node di dalam antrian,
    // maka lanjutkan kode berikut.

    // Deklarasi variabel bernama nama_pasien bertipe data char.
    char nama_pasien[100];

    // Meminta masukan dari user untuk dimasukkan ke dalam nama_pasien.
    printf("Masukkan nama pasien: ");
    scanf("%s", &nama_pasien);
    // Inisialisasi node bernama cari untuk melacak node sesuai dengan pasien yang dicari.
    pasien cari = head;

    // Lakukan perulangan hingga cari bernilai NULL dan
    // nama pasien yang dicari sama dengan nama yang ada di dalam antrian.
    while(cari != NULL && strcmp(cari->nama, nama_pasien)) {
      // Jika kondisi terpenuhi, maka lanjut ke node berikutnya.
      cari = cari->next;
    }

    // Jika cari bernilai NULL, maka data tidak ditemukan.
    if(cari == NULL) {
      printf("Data tidak ditemukan!\n");
    } else {
      // Jika cari bernilai head, maka
      if(cari == head) {
        // cari menjadi head dan head menjadi node berikutnya.
        cari = head;
        head = head->next;
      } else if(cari->next == NULL) {
        // Jika node berikutnya pada cari bernilai NULL, maka
        // node berikutnya pada node sebelumnya di node cari bernilai NULL.
        cari->prev->next = NULL;
      } else {
        // Jika semua kondisi di atas tidak terpenuhi, maka
        // node berikutnya pada node sebelumnya di node cari bernilai node berikutnya di node cari.
        cari->prev->next = cari->next;
        // node sebelumnya pada node berikutnya di node cari bernilai node sebelumnya di node cari.
        cari->next->prev = cari->prev;
      }
      // Menampilkan pesan bahwa data berhasil dihapus.
      printf("Data berhasil dihapus!\n");
    }
    // Lakukan penghapusan memori pada node cari.
    free(cari);
  }
  
  // Mengembalikan head yang sudah diupdate.
  return head;
}

// cekAntrian() => digunakan untuk mengetahui banyak antrian di depan pasien.
void cekAntrian(pasien head) {
  // Jika belum ada node di dalam antrian,
  // maka tampilkan pesan bahwa data kosong.
  if(head == NULL) {
    printf("Data kosong!\n");
  } else {
    // Jika sudah ada node di dalam antrian,
    // maka lanjutkan kode berikut.

    // Deklarasi variabel bernama nama_pasien bertipe data char.
    char nama_pasien[100];
    // Inisialisasi variabel count bertipe data integer dengan nilai awal, yaitu 0.
    int count = 0;
    
    // Meminta masukan dari user untuk dimasukkan ke dalam nama_pasien.
    printf("Masukkan nama pasien: ");
    scanf("%s", &nama_pasien);
    // Inisialisasi node bernama cari untuk melacak node sesuai dengan pasien yang dicari.
    pasien cari = head;

    // Lakukan perulangan hingga cari bernilai NULL dan
    // nama pasien yang dicari sama dengan nama yang ada di dalam antrian.
    while(cari != NULL && strcmp(cari->nama, nama_pasien)) {
      // Tambah count senilai 1.
      count++;
      // Jika kondisi terpenuhi, maka lanjut ke node berikutnya.
      cari = cari->next;
    }

    // Jika cari bernilai NULL, maka data tidak ditemukan.
    if(cari == NULL) {
      printf("Data tidak ditemukan!\n");
    } else {
      // Jika nama pasien ditemukan, maka tampilkan pesan berikut.
      printf("Antrian atas nama %s, kurang %d antrian lagi.\n", cari->nama, count);
    }
  }
}

// listAntrian() => digunakan untuk mencetak semua data nama pasien di dalam antrian. 
void listAntrian(pasien head) {
  // Inisialisasi node bernama curr untuk melacak node saat ini di dalam list.
  pasien curr = head;
  // Inisialisasi variabel i bertipe data integer dengan nilai awal, yaitu 0.
  int i = 0;
  
  printf("Daftar Pasien dalam Antrian: \n");
  // Jika node curr bernilai NULL, maka data kosong.
  if(curr == NULL) {
    printf("Data Kosong!");
  } else {
    // Jika node curr tidak kosong, maka lakukan perulangan berikut hingga curr bernilai NULL.
    while(curr != NULL) {
      // Tambah i senilai 1.
      i++;
      // Menampilkan nomor dan nama pasien saat ini.
      printf("[%d] Nama: %s\n", i, curr->nama);
      // Jika kondisi terpenuhi, maka lanjut ke node berikutnya.
      curr = curr->next;
    }
  }
}

int main() {
  printf("------ ANTRIAN RUMAH SAKIT ------\n");
  // Inisialisasi node bernama head dengan nilai awal, yaitu NULL.
  pasien head = NULL;
  // Inisialisasi variabel pilihan bertipe data integer dengan nilai awal yaitu, 0.
  int pilihan = 0;

  // Lakukan perulangan berikut.
  while(1) {
    system("cls");
    // Menampilkan semua data nama pasien di dalam antrian.
    listAntrian(head);
    printf("\n\n");

    // Memberikan beberapa pilihan kepada user.
    printf("1. Tambah Antrian\n");
    printf("2. Hapus Antrian\n");
    printf("3. Cek Antrian\n");
    printf("4. Exit\n");
    printf("Pilihan: ");
    // Meminta masukan kepada user untuk dimasukkan ke dalam pilihan.
    scanf("%d", &pilihan);
    scanf("%*[^\n]");

    printf("\n");
    // Lakukan pengecekan terhadap nilai pilihan untuk mengeksekusi kode yang sesuai.
    switch(pilihan) {
      // Jika pilihan adalah 1, maka
      case 1:
        // Update head dengan memanggil fungsi tambahAntrian().
        head = tambahAntrian(head);
        system("pause");
        break;
      // Jika pilihan adalah 2, maka
      case 2:
        // Update head dengan memanggil fungsi hapusAntrian().
        head = hapusAntrian(head);
        system("pause");
        break;
      // Jika pilihan adalah 3, maka
      case 3:
        // Memanggil fungsi cekAntrian();
        cekAntrian(head);
        system("pause");
        break;
      // Jika pilihan adalah 4, maka
      case 4:
        // Keluar dari perulangan.
        exit(1);
      // Jika user memasukkan input yang tidak sesuai, 
      // maka tampilkan pesan berikut.
      default:
        printf("Pilihan tidak valid!\n");
    }
  }
  
  return 0;
}