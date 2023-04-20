#include <stdio.h>

// arrayMean() => digunakan untuk mencari nilai rata-rata dari sebuah array yang memiliki N elemen.
float arrayMean(int *arr, int N) {
  // Inisialisasi variabel sum bertipe data float dengan nilai awal, yaitu 0.
  float sum = 0;
  // Melakukan perulangan di dalam array sebanyak N kali.
  // Perulangan ini dilakukan untuk mendapatkan elemen yang ada di dalam array.
  for(int i = 0; i < N; i++) {
    // Variabel sum ditambahkan dengan setiap elemen di dalam array berdasarkan indeks ke-i.
    sum += *(arr + i);
  }
  // Mengembalikan nilai rata-rata dari array, 
  // yaitu pembagian antara hasil penjumlahan semua elemen di dalam array 
  // dengan banyak elemen yang ada di dalam array.
  return sum / N;
}

int main() {
  // Deklarasi variabel N yang nantinya digunakan sebagai 
  // banyak elemen yang ada di dalam array.
  int N;
  // User melakukan input nilai ke dalam variabel N.
  scanf("%d", &N);

  // Deklarasi variabel arr sebagai array yang memiliki N elemen di dalamnya.
  int arr[N];
  // Perulangan ini dilakukan untuk menampung input dari user 
  // berupa angka integer sebanyak N elemen yang dipisahkan tanda spasi.
  for(int i = 0; i < N; i++) {
    // User melakukan input nilai ke dalam variabel arr dengan indeks ke-i.
    scanf("%d", &arr[i]);
  }

  // Menampilkan nilai kembali dari fungsi arrayMean() berupa 
  // hasil rata-rata dari sebuah array dengan presisi hingga 2 angka di belakang koma.
  printf("%.2f", arrayMean(arr, N));
  return 0;
} 