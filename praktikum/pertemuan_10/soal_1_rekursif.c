#include <stdio.h>
#include <string.h>

// cetakSubsekuen() => digunakan untuk menampilkan subsekuen yang ada di dalam str.
void cetakSubsekuen(char str[], int index, char subsekuen[]) {
  // Basis: Jika mencapai index akhir pada str, maka cetak subsekuen yang telah terbentuk.
  if(str[index] == '\0') {
    printf("\"%s\" ", subsekuen);
    return;
  }

  // Rekurens: Memanggil fungsi cetakSubsekuen() dengan index selanjutnya dan subsekuen di awal.
  cetakSubsekuen(str, index + 1, subsekuen);
  // Masukkan str pada nilai index ke dalam subsekuen dengan index setelah index akhir dari subsekuen.
  subsekuen[strlen(subsekuen)] = str[index];
  // Rekurens: Memanggil fungsi cetakSubsekuen() dengan index selanjutnya dan subsekuen yang telah diupdate.
  cetakSubsekuen(str, index + 1, subsekuen);
  // Mengembalikan subsekuen pada index terakhir dari subsekuen menjadi char kosong.
  subsekuen[strlen(subsekuen) - 1] = '\0';
}

int main() {
  // Deklarasi variabel str bertipe data char untuk menyimpan input dari user.
  // Inisialisasi variabel subsekuen bertipe data char dengan nilai awal, yaitu " ".
  char str[100], subsekuen[100] = "";
  // Meminta user untuk memasukkan input string yang ingin dicari subsekuennya.
  scanf("%s", &str);

  // Memanggil fungsi cetakSubsekuen() untuk menampilkan semua subsekuen yang ada di dalam str.
  cetakSubsekuen(str, 0, subsekuen);
}
