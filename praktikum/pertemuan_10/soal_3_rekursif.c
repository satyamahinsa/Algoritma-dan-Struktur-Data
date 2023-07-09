#include <stdio.h>

// nilaiTerbesar() => digunakan untuk mencari nilai terbesar di dalam array.
int nilaiTerbesar(int arr[], int index, int ukuran, int max) {
  // Basis: Jika nilai index sama dengan ukuran dari array (mencapai nilai terakhir di array),
  // maka kembalikan nilai max yang sudah didapatkan.
  if(index == ukuran) {
    return max;
  // Jika belum mencapai nilai terakhir di array,
  // maka lakukan pengecekan nilai max terhadap setiap elemen di dalam array.
  } else {
    // Rekurens: Jika nilai elemen di dalam array lebih besar dari max,
    // maka ubah nilai max menjadi nilai elemen tersebut.
    if(arr[index] > max) {
      max = arr[index];
    }
    // Kembalikan fungsi nilaiTerbesar() sebagai rekursif dengan menambahkan 1 pada nilai index
    // dan nilai max terbaru.
    return nilaiTerbesar(arr, index + 1, ukuran, max);
  }
}

int main() {
  // Meminta user untuk memasukkan input ukuran dari array.
  int ukuran;
  printf("Ukuran Array: ");
  scanf("%d", &ukuran);

  // Meminta user untuk memasukkan input setiap elemen di dalam array.
  int num_arr[ukuran];
  printf("Masukkan bilangan sebanyak %d: ", ukuran);
  for(int i = 0; i < ukuran; i++) {
    scanf("%d", &num_arr[i]);
  }

  // Menampilkan hasil pencarian nilai terbesar di dalam array.
  printf("%d", nilaiTerbesar(num_arr, 0, ukuran, num_arr[0]));
  return 0;
}