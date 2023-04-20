#include <stdio.h>

// greatestOf() => digunakan untuk mencari nilai maksimum dari 4 bilangan yang ada di dalam parameter.
int greatestOf(int a, int b, int c, int d) {
  // Inisialisasi variabel max bertipe data integer dengan nilai, yaitu a.
  int max = a;
  // Melakukan pengecekan menggunakan if secara bergantian antara 
  // variabel max dengan bilangan selanjutnya yang ada di dalam parameter, yaitu b, c, dan d.
  // Pengecekan secara berurutan ini dilakukan agar semua bilangan 
  // melewati proses perbandingan sehingga dapat menentukan nilai maksimum dari 4 bilangan.
  if(b > max) {
    max = b;
  }
  if(c > max) {
    max = c;
  }
  if(d > max) {
    max = d;
  }

  // Mengembalikan nilai max.
  return max;
}

int main() {
  // Deklarasi 4 variabel bertipe data integer.
  int a, b, c, d;
  // User melakukan input nilai ke dalam 4 variabel tersebut.
  scanf("%d %d %d %d", &a, &b, &c, &d);
  // Menampilkan nilai kembali dari fungsi greatestOf(), yaitu 
  // nilai maksimum dari 4 bilangan yang ada di dalam argumen.
  printf("%d", greatestOf(a, b, c, d));
  return 0;
} 