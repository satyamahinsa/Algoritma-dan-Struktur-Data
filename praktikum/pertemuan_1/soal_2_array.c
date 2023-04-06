#include <stdio.h>

// sorting_array() => digunakan untuk melakukan pengurutan elemen array dari yang terkecil ke terbesar dengan menggunakan metode bubble sort.
void sorting_array(int *arr, int size) {
  // Perulangan pertama digunakan untuk mengakses seluruh elemen secara satu per satu.
  for (int i = 0; i < size - 1; i++) {
    // Membuat variabel temp yang digunakan sebagai variabel sementara.
    int temp;
    // Perulangan kedua digunakan untuk membandingkan satu per satu elemen dalam menentukan urutan dengan benar.
    for(int j = 0; j < size - i - 1; j++) {
      // Melakukan pengecekan apakah elemen saat ini lebih besar daripada elemen setelahnya.
      if(arr[j] > arr[j + 1]) {
        // Jika kondisi di atas terpenuhi, maka proses pertukaran elemen dilakukan dengan menggunakan bantuan dari variabel temp.
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// print_array() => digunakan untuk menampilkan seluruh elemen array.
void print_array(int *arr, int size) {
  // Perulangan ini digunakan untuk mengakses setiap elemen berdasarkan indeks.
  for (int i = 0; i < size; i++) {
    // Menampilkan elemen di dalam array.
    printf("%d, ", arr[i]);
  }
}

int main() {
  // Menginisialisasi array 1 dimensi bertipe data integer dengan elemen sebanyak 5 buah bilangan bulat.
  int x[5] = {15, 21, 4, 6, 2};
  // Membuat variabel size untuk mengetahui panjang dari array dengan menggunakan sizeof dari array dan sizeof dari integer.
  int size = sizeof(x)/sizeof(int);

  // Menampilkan seluruh elemen array yang belum terurut.
  printf("Array awal :\n");
  // Memanggil fungsi print_array dengan parameter x merupakan array dan size merupakan panjang array.
  print_array(x, size);

  // Melakukan pengurutan elemen di dalam array menggunakan sorting_array() dengan parameter x merupakan array dan size merupakan panjang array.
  sorting_array(x, size);

  // Menampilkan seluruh array yang sudah terurut.
  printf("\nArray yang telah diurutkan :\n");
  // Memanggil fungsi print_array dengan parameter x merupakan array dan size merupakan panjang array.
  print_array(x, size);

  return 0;
} 