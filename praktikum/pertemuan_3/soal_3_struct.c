#include <stdio.h>

// Struct coordinatTrapesium berisi variabel x dan y dengan tipe data integer.
// coordinatTrapesium memiliki nama alias Trapesium dengan menggunakan kata kunci typedef.
typedef struct coordinatTrapesium {
  int x, y;
} Trapesium;

int main() {
  // Deklarasi variabel A, B, C, D, E, F  dengan menggunakan tipe data struct Trapesium.
  Trapesium A, B, C, D, E, F;

  // Melakukan cetak koordinat titik A dalam x dan y untuk meminta data ke user.
  printf("Koordinat Titik A (x, y): ");
  // Meminta data titik x dan y dalam koordinat A kepada user.
  scanf("%d %d", &A.x, &A.y);
  // Melakukan cetak koordinat titik B dalam x dan y untuk meminta data ke user.
  printf("Koordinat Titik B (x, y): ");
  // Meminta data titik x dan y dalam koordinat BA kepada user.
  scanf("%d %d", &B.x, &B.y);
  // Melakukan cetak koordinat titik C dalam x dan y untuk meminta data ke user.
  printf("Koordinat Titik C (x, y): ");
  // Meminta data titik x dan y dalam koordinat C kepada user.
  scanf("%d %d", &C.x, &C.y);
  // Melakukan cetak koordinat titik D dalam x dan y untuk meminta data ke user.
  printf("Koordinat Titik D (x, y): ");
  // Meminta data titik x dan y dalam koordinat D kepada user.
  scanf("%d %d", &D.x, &D.y);
  // Melakukan cetak koordinat titik E dalam x dan y untuk meminta data ke user.
  printf("Koordinat Titik E (x, y): ");
  // Meminta data titik x dan y dalam koordinat E kepada user.
  scanf("%d %d", &E.x, &E.y);
  // Melakukan cetak koordinat titik F dalam x dan y untuk meminta data ke user.
  printf("Koordinat Titik F (x, y): ");
  // Meminta data titik x dan y dalam koordinat F kepada user.
  scanf("%d %d", &F.x, &F.y);

  // Inisialisasi variabel luas denga nilai perhitungan (tinggi * penjumlahan 2 sisi sejajar) / 2
  // Tinggi = A.y - C.y
  // Penjumlahan 2 sisi sejajar = ((B.x - A.x) + (F.x - E.x)) / 2;
  float luas = (A.y - C.y) * ((B.x - A.x) + (F.x - E.x)) / 2;
  // Melakukan cetak hasil perhitungan luas trapesium dengan presisi 2 angka di belakang koma.
  printf("Luas Trapesium : %.2f", luas);

  return 0;
}