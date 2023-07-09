#include <stdio.h>
#include <string.h>

// palindrom() => digunakan untuk mengecek apakah sebuah kata yang sama
// jika dibaca dari depan atau belakang.
int palindrom(char str[], int start, int end) {
  // Basis: Jika terdapat karakter pada index start dan index end yang tidak sama,
  // maka dapat dipastikan bahwa kata tersebut bukan palindrom.
  if(str[start] != str[end]) {
    return 0;
  // Rekurens: Jika index start dan index end sudah sama atau bertemu, 
  // maka hal tersebut menandakan bahwa seluruh karakter sama dari depan maupun belakang.
  } else if(start == end) {
    return 1;
  // Rekurens: Memanggil fungsi palindrom() dengan nilai parameter start bertambah 1 dan end berkurang 1.
  // Hal ini digunakan untuk melakukan pengecekan karakter 
  // dari depan maupun dari belakang secara bersamaan.
  } else {
    return palindrom(str, start + 1, end - 1);
  }
}

int main() {
  // Deklarasi variabel str bertipe data char.
  char str[100];
  // Meminta user untuk memasukkan input string yang ingin dicek.
  scanf("%s", &str);

  // Memanggil fungsi palindrom()
  // Jika nilai kembalian = 1, maka string dari user merupakan palindrom.
  if(palindrom(str, 0, strlen(str) - 1) == 1) {
    printf("%s merupakan palindrom.", str);
  // Jika nilai kembalian = 0, maka string dari user bukan merupakan palindrom.
  } else {
    printf("%s bukan merupakan palindrom.", str);
  }
  return 0;
}