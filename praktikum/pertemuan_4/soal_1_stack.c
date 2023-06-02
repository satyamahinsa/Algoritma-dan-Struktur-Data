#include <stdio.h>

// menara_hanoi() => digunakan untuk melakukan pemindahan disk dari tiang asal ke tiang tujuan dengan menggunakan tiang bantu.
void menara_hanoi(int banyak_disk, char tiang_asal, char tiang_bantu, char tiang_tujuan) {
  // Mengecek apakah banyak disk sama dengan 1 atau tidak.
  // Jika iya, maka tampilkan pemindahan disk 1 dari tiang asal ke tiang tujuan.
  if(banyak_disk == 1) {
    printf("Pindah disk 1 dari '%c' ke '%c'\n", tiang_asal, tiang_tujuan);
  // Jika tidak, maka lakukan rekursi dengan pemanggilan fungsi menara_hanoi() kembali.
  } else {
    // Dengan mengikuti pola perpindahan disk yang ada di dalam soal, maka di dapatkan sebagai berikut:
    // Pemanggilan menara_hanoi() pertama digunakan untuk memindahkan disk dari tiang asal ke tiang bantu.
    menara_hanoi(banyak_disk - 1, tiang_asal, tiang_tujuan, tiang_bantu);
    // Menampilkan perpindahan disk saat ini dari tiang asal ke tiang tujuan.
    printf("Pindah disk %d dari '%c' ke '%c'\n", banyak_disk, tiang_asal, tiang_tujuan);
    // Pemanggilan menara_hanoi() kedua digunakan untuk memindahkan disk dari tiang bantu ke tiang tujuan.
    menara_hanoi(banyak_disk - 1, tiang_bantu, tiang_asal, tiang_tujuan);
  }
}

int main() {
  // Deklarasi variabel jumlah_disk untuk menentukan banyak disk yang digunakan.
  int jumlah_disk;

  // Meminta input data kepada user untuk dimasukkan ke dalam variabel jumlah_disk.
  printf("Masukkan jumlah disk: ");
  scanf("%d", &jumlah_disk);

  // Panggil fungsi menara_hanoi() dengan parameter jumlah_disk, tiang asal, tiang bantu, dan tiang tujuan.
  menara_hanoi(jumlah_disk, 'S', 'A', 'D');
  return 0;
}