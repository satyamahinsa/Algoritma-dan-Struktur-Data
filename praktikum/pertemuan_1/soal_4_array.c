#include <stdio.h>

// hitung_rata_rata() => digunakan untuk menghitung rata-rata dari jumlah seluruh elemen array.
float hitung_rata_rata(int *arr) {
  // Menginisialisasi variabel total dengan nilai awal, yaitu 0.
  float total = 0;
  // Perulangan ini digunakan untuk mengakses elemen array secara satu per satu, lalu dijumlahkan dengan variabel total.
  for (int i = 0; i < 70; i++) {
    total += arr[i];
  }
  // Mengembalikan nilai rata-rata dengan tipe data float.
  return total / 70;
}

// print_array() => digunakan untuk menampilkan seluruh elemen array.
void print_array(int *arr) {
  // Perulangan ini digunakan untuk mengakses setiap elemen berdasarkan indeks.
  for (int i = 0; i < 70; i++) {
    printf("%d, ", arr[i]);
  }
}

int main() {
  // Deklarasi sebuah array dengan ukuran sebanyak 70 elemen.
  int arr[70];

  // Memasukkan elemen dengan angka 1 - 70 ke dalam array.
  for(int i = 0; i < 70; i++) {
    // Memasukkan i + 1 ke dalam setiap elemen karena indeks dimulai dari 0.
    arr[i] = i + 1;
  }

  // Menampilkan semua elemen yang ada di dalam array.
  printf("Array: ");
  print_array(arr);

  // Melakukan perhitungan rata-rata dari jumlah seluruh elemen array.
  printf("\nRata - rata dari array tersebut adalah: %.2f\n", hitung_rata_rata(arr));

  return 0;
}