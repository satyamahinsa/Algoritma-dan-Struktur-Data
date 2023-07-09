#include <stdio.h>

// hitungDigit() => digunakan untuk menghitung jumlah digit dari suatu bilangan.
int hitungDigit(int input) {
  // Basis: Jika bilangan kurang dari 10, maka kembalikan 1 (artinya terdapat 1 digit). 
  if(input < 10) {
    return 1;
  // Rekurens: Jika bilangan lebih dari 10, maka kembalikan fungsi hitungDigit() sebagai rekursif
  // dengan membagi bilangan dengan 10 untuk menghapus digit terakir dan tambahkan 1 
  // karena digit terakhir telah terhitung.
  } else {
    return hitungDigit(input / 10) + 1;
  }
}

int main() {
  // Meminta user untuk memasukkan input bilangan bulat yang ingin dihitung jumlah digitnya.
  int input;
  scanf("%d", &input);

  // Menampilkan hasil perhitungan jumlah digit dari fungsi hitungDigit().
  printf("%d", hitungDigit(input));
  return 0;
}