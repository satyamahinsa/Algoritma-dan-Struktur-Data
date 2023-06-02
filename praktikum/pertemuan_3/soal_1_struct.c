#include <stdio.h>

// Struct DataBarang berisi variabel nama dengan tipe data string, 
// modal dengan tipe data integer, dan jual dengan tipe data integer. 
// DataBarang memiliki nama alias data barang dengan menggunakan kata kunci typedef.
typedef struct DataBarang {
  char nama;
  int modal, jual;
} data_barang;

int main() { 
  
  // Deklarasi variabel barang menggunakan tips data struct data_barang.
  data_barang barang;

  // Malakukan cetak Nama untuk meminta data kepada user. 
  printf("Nama: ");

  // Meminta nama barang kepada user, lalu dimasukkan ke dalam variabel barang.nama
  scanf("%s", &barang.nama); 

  // Melakukan cetak Modal untuk meminta data kepada user.
  printf("Modal: ");

  // Meminta harga modal barang kepada user, lalu dimasukkan ke dalam variabel barang.modal 
  scanf("%d", &barang.modal);
  
  // Malakukan cetak Jual untuk meminta data kepada user. 
  printf("Jual: ");

  // Meminta harus jual barang kepada user, lalu dimasukkan ke dalam variabel barang.jual 
  scanf("%d", &barang.jual);
  
  // Membuat variabel laba untuk melakukan perhitungan antara harga jual barang dan harga modal barang.
  int laba = barang.jual - barang.modal;

  // Melakukan cetak hasil perhitungan dalam variabel laba.
  printf("Margin adalah: %d", laba);
  return 0;
}