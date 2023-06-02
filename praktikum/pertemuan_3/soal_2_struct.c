#include <stdio.h>

// Struct Pecahan berisi variabel pembilang dan penyebut dengan tipe data integer. 
// Pecahan memiliki nama alias pecahan dengan menggunakan kata kunci typedef.
typedef struct Pecahan {
  int pembilang, penyebut;
} pecahan;

int main() {
  // Deklarasi variabel pecahan berbentuk array 
  // dengan size sebanyak 3 menggunakan tipe data struct pecahan.
  pecahan pecahan[3];

  // Perulangan berikut digunakan untuk mengakses array pecahan sebanyak 3.
  for(int i = 0; i < 3; i++) {
    // Melakukan cetak (pembilang, penyebut) untuk meminta data kepada user.
    printf("(pembilang, penyebut) : ");
    // Meminta data pembilang dan penyebut kepada user.
    // Lalu, data dimasukkan ke dalam variabel pecahan.pembilang dan pecahan.penyebut setiap perulangan.
    scanf("%d %d", &pecahan[i].pembilang, &pecahan[i].penyebut);
  }

  // Perulangan berikut digunakan untuk mengecek nilai minimum antara pembilang dan penyebut.
  // Kemudian, memberikan hasil penyederhanaan 3 pecahan.
  for(int i = 0; i < 3; i++) {
    // Membuat variabel min dengan nilai awal, yaitu pembilang.
    int min = pecahan[i].pembilang;
    // Melakukan pengecekan apakah nilai penyebut lebih kecil daripada pembilang.
    if(pecahan[i].penyebut < min) {
      // Jika iya, maka nilai variabel min diganti menjadi penyebut.
      min = pecahan[i].penyebut;
    }

    // Melakukan catak hasil penyederhanaan pecahan
    // Dengan melakukan pembagian pembilang dengan min dan penyebut dengan min.
    printf("%d/%d\n", pecahan[i].pembilang/min, pecahan[i].penyebut/min);
  }

  return 0;
}