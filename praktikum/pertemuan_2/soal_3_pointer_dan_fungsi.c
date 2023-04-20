#include <stdio.h>
#include <stdlib.h>

// koboImaginaryChess() => digunakan untuk mensimulasikan skenario yang dimiliki oleh Kobo.
// Simulasi tersebut, yaitu di dalam papan catur berukuran 8x8, 
// Kobo ingin mengetahui posisi mana saja yang dapat dicapai oleh 
// bidak kuda dalam sekali jalan apabila bidak tersebut berada pada posisi i, j.
// Fungsi koboImaginaryChess() memiliki 4 buah parameter, yaitu 
// i sebagai posisi kuda dalam baris, j sebagai posisi kuda dalam kolom, 
// size sebagai ukuran papan catur, dan
// chessBoard sebagai papan catur yang berisi elemen sebanyak 64.
void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
  // Inisialisasi sebuah array bernama posisi sebagai langkah atau jalan 
  // yang mungkin dilalui oleh bidak kuda (kuda berjalan seperti membentuk huruf L).
  // Kumpulan array di dalam array posisi memiliki 2 buah elemen masing-masingnya,
  // yaitu indeks ke-0 sebagai jalan kuda yang mengacu kepada baris dan 
  // indeks ke-1 sebagai jalan kuda yang mengacu kepada kolom.
  int posisi[][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {2, -1}, {2, 1}, {1, -2}, {1, 2}};

  // Perulangan ini dilakukan untuk mengecek setiap kemungkinan langkah atau jalan
  // yang dapat dilalui oleh bidak kuda sesuai dengan array posisi.
  for(int k = 0; k < 8; k++) {
    // Inisialisasi variabel baris dan kolom bertipe data integer 
    // dengan nilai sesuai dengan setiap array yang ada di dalam array posisi.
    int baris = posisi[k][0], kolom = posisi[k][1];
    // Melakukan pengecekan apakah setiap jalan yang dilalui oleh bidak kuda
    // melewati papan catur atau tidak.
    if(i + baris >= 0 && i + baris < 8 && j + kolom >= 0 && j + kolom < 8) {
      // Jika jalan bidak kuda tidak melewati papan catur, 
      // maka nilai papan catur chessBoard dengan indeks baris (i + baris) dan 
      // indeks kolom (j + kolom) diubah menjadi 1.
      // *(chessBoard + (i + baris) * 8 + (j + kolom)) sama artinya 
      // dengan chessBoard[(i + baris) * 8][j + kolom]
      *(chessBoard + (i + baris) * 8 + (j + kolom)) = 1;
    }
  }
}

// print_array() => digunakan untuk menampilkan semua elemen yang ada di dalam array chessBoard.
void print_array(int *chessBoard) {
  // Perulangan pertama berfungsi untuk melakukan pemanggilan terhadap baris. 
  for(int i = 0; i < 8; i++) {
    // Perulangan kedua berfungsi untuk melakukan pemanggilan terhadap kolom. 
    for(int j = 0; j < 8; j++) {
      // Menampilkan elemen yang ada di dalam array dengan indeks baris ke i*8 
      // (karena setiap baris ada 8 elemen) dan indeks kolom ke j.
      // *(chessBoard + i * 8 + j) sama dengan chessBoard[i * 8][j]
      printf("%d", *(chessBoard + i * 8 + j));
    }
    // \n digunakan untuk membuat baris baru.
    printf("\n");
  }
}

int main() {
  // Deklarasi variabel i dan j bertipe data integer sebagai posisi awal bidak kuda.
  int i, j;
  // User melakukan input nilai i sebagai posisi baris dan j sebagai posisi kolom.
  scanf("%d %d", &i, &j);
  // Inisialisasi variabel size bertipe data integer sebagai ukuran papan catur.
  int size = 8;
  // Mengalokasikan memori secara dinamis sejumlah 256 byte karena 
  // setiap tipe data integer membutuhkan 4 byte memori dalam menyimpan sebuah nilai.
  int *chessBoard = (int*) malloc(size * size * sizeof(int));
  // Perulangan ini dilakukan untuk membuat semua elemen di dalam array chessBoard menjadi 0.
  for (int k = 0; k < size * size; k++) {
    // *(chessBoard + k) untuk mengakses setiap elemen yang ada di dalam array chessBoard.
    *(chessBoard + k) = 0;
  }

  // Memanggil fungsi koboImaginaryChess() untuk menjalankan skenario yang diinginkan oleh Kobo.
  koboImaginaryChess(i, j, size, chessBoard);
  // Memanggil fungsi print_array() untuk menampilkan seluruh elemen 
  // yang ada di dalam array chessBoard dan mengetahui posisi mana saja yang 
  // dapat dicapai oleh bidak kuda.
  print_array(chessBoard);
  return 0;
} 