#include <stdio.h>
#include <string.h>

// palindrom() => digunakan untuk mengecek apakah sebuah kata merupakan palindrom atau bukan.
int palindrom(char *str, int i, int j) {
  // Variabel i digunakan sebagai indeks awal dan variabel j digunakan sebagai indeks akhir dalam variabel str.
  // Jika nilai i atau nilai j kurang dari 0, maka tidak ada kata yang ingin dicek (return 0)
  if(i < 0 || j < 0) {
    return 0;
  // Jika nilai i atau nilai j lebih dari 0, maka ada kata yang ingin dicek.
  } else {
    // Jika nilai i lebih besar atau sama dengan dari nilai j, artinya pengecekan terhadap semua karakter telah selesai dilakukan.
    if(i >= j) {
      return 1;
    }

    // Jika karakter pada indeks ke-i sama dengan karakter pada indeks ke-j, maka panggil fungsi palindrom kembali dengan nilai i + 1 dan nilai j - 1 hingga nantinya nilai i lebih besar dari nilai j.
    if(str[i] == str[j]) {
      return palindrom(str, i + 1, j - 1); 
    }
  }
  
  return 0;
}

int main(void) {
  // Deklarasi variabel str beripe data char dengan ukuran 100.
  char str[100];

  // Meminta input data kepada user untuk dimasukkan ke dalam variabel str.
  printf("Input: ");
  scanf("%s", &str);

  // Menampilkan hasil pengecekan apakah sebuah kata merupakan palindrom atau bukan.
  printf("Output: ");
  // Melakukan pengecekan dengan memanggil fungsi palindrom() yang memiliki parameter str, indeks awal, dan indeks akhir.
  if(palindrom(str, 0, strlen(str) - 1)) {
    printf("Kata %s merupakan kata palindrom.", str);
  } else {
    printf("Kata %s bukan merupakan kata palindrom.", str);
  } 
  
  return 0;
}
