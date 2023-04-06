#include <stdio.h>

int main() {
  // Menginisialisasi array 2 dimensi bertipe data integer yang terdiri dari 3 baris dan 2 kolom.
  int x[3][2] = {{3, 6}, {9, 8}, {15, 10}};

  // Melakukan perulangan bersarang untuk menampilkan elemen pada indeks ke-i dan ke-j.
  // Perulangan pertama berfungsi untuk melakukan pemanggilan terhadap baris.
  for(int i = 0; i < 3; i++) {
    // Perulangan kedua berfungsi untuk melakukan pemanggilan terhadap kolom.
    for(int j = 0; j < 2; j++) {
      // Menampilkan elemen di dalam array dengan i sebagai baris dan j sebagai kolom.
      printf("Nilai array x[%d][%d] adalah : %d\n", i, j, x[i][j]);
    }
  }

  return 0;
} 