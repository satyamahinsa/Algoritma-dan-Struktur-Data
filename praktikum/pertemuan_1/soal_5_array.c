#include <stdio.h>

int main() {
  // Menginisialisasi array lantai dengan elemen sebanyak lantai gedung.
  int lantai[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // Menginisialisasi variabel banyak_lantai untuk menampung banyak elemen yang ada di dalam array lantai.
  int banyak_lantai = sizeof(lantai)/sizeof(int);
  // Deklarasi variabel pilihan untuk menampung pilihan lantai dari user.
  int pilihan;
  printf("Pilih nomor lantai: ");
  scanf("%d", &pilihan);

  // Menginisialisasi variabel before dan start sebagai nilai awal banyak elemen yang berada di sebelum dan sesudah pilihan dari user.
  int before = 2, after = 2;

  // Melakukan perulangan sebanyak ukuran dari array untuk mengecek pilihan dari user.
  for(int i = 0; i < banyak_lantai; i++) {
    // Jika pilihan dari user terdapat di dalam array, maka lakukan pengecekan kondisi untuk menyesuaikan urutan lantai sebanyak 5 lantai.
    if(lantai[i] == pilihan) {
      if(i + after >= banyak_lantai) {
        // Jika banyak lantai yang ada setelah lantai pilihan user adalah kurang dari 2, maka lakukan operasi berikut agar dapat menyesuaikan dengan kondisi yang terjadi.
        // Untuk mendapatkan nilai before dan after secara dinamis yang bergantung pada banyak lantai, maka dapat menggunakan rumus di bawah ini.
        // Misal, angka pilihan adalah 9 (i = 8), maka banyak angka yang tersedia sebelum angka pilihan user bertambah menjadi 3. Sedangkan, banyak angka yang tersedia setelah angka pilihan user berkurang menjadi 1.  
        before += i + after - (banyak_lantai - 1);
        after -= i + after - (banyak_lantai - 1);
      } else if (i - before < 0) {
        // Jika banyak lantai yang ada sebelum lantai pilihan user adalah kurang dari 2, maka lakukan operasi berikut agar dapat menyesuaikan dengan kondisi yang terjadi.
        // Untuk mendapatkan nilai before dan after secara dinamis tergantung dari banyak lantai, maka dapat menggunakan rumus di bawah ini.
        // Misal, angka pilihan adalah 1 (i = 0), maka banyak angka yang tersedia sebelum angka pilihan user menjadi 0. Sedangkan, banyak angka yang tersedia setelah angka pilihan user bertambah menjadi 4. 
        before = i;
        after -= i - after;
      }
      // Menampilkan urutan 5 lantai sesuai dengan kondisi.
      for(int j = i - before; j <= i + after; j++) {
        printf("%d, ", lantai[j]);
      }
    }
  }

  return 0;
} 