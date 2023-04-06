#include <stdio.h>

// find_index() => digunakan untuk melakukan pengecekan terhadap semua elemen yang ada di dalam array untuk mencari indeks dari bilangan yang diinputkan oleh user
void find_index(int arr[3][2], int input) {
  // Menginisialisaso variabel found yang digunakan sebagai tanda apakah bilangan sudah ditemukan atau belum.
  // Nilai awal dari found adalah 0 sebagai tanda bahwa bilangan belum ditemukan.
  int found = 0;
  // Perulangan pertama berfungsi untuk melakukan pemanggilan terhadap baris.
  for (int i = 0; i < 3; i++) {
    // Perulangan kedua berfungsi untuk melakukan pemanggilan terhadap kolom.
    for(int j = 0; j < 2; j++) {
      // Melakukan pengecekan apakah array pada baris ke-i dan kolom ke-j sama dengan bilangan yang dicari oleh user.
      if(arr[i][j] == input) {
        // Jika elemen pada baris ke-i dan kolom ke-j sama dengan bilangan yang dicari oleh user, maka tampilkan indeks dari bilanga tersebut.
        printf("Elemen %d berada di indeks[%d][%d]\n", input, i, j);
        // Mengubah variabel found menjadi 1 sebagai tanda bahwa bilangan yang dicari oleh user telah ditemukan.
        found = 1;
        // Lakukan break untuk menghentikan perulangan saat ini.
        break;
      }
    }
  }

  // Jika nilai dari found tetap 0, maka bilangan yang dicari oleh user tidak ditemukan di dalam array tersebut.
  if(found == 0) {
    printf("Tidak ada elemen tersebut di dalam array\n");
  }
}

int main() {
  // Menginisialisasi array 2 dimensi bertipe data integer yang terdiri dari 3 baris dan 2 kolom.
  int arr[3][2] = {{3, 6}, {9, 8}, {15, 10}};

  // Menampilkan elemen yang ada di dalam array.
  printf("Array: ");
  // Perulangan pertama berfungsi untuk melakukan pemanggilan terhadap baris.
  for(int i = 0; i < 3; i++) {
    // Perulangan kedua berfungsi untuk melakukan pemanggilan terhadap kolom.
    for(int j = 0; j < 2; j++) {
      // Menampilkan elemen di dalam array dengan i sebagai baris dan j sebagai kolom.
      printf("%d, ", arr[i][j]);
    }
  }

  // Meminta user untuk memasukkan sebuah bilangan yang ingin dicari indeksnya di dalam array.
  int user_input;
  printf("\nMasukkan elemen yang ingin dicari indeksnya: ");
  scanf("%d", &user_input);

  // Melakukan pengecekan terhadap bilangan dari user.
  find_index(arr, user_input);
  
  return 0;
} 