#include <stdio.h>

struct Buku {
  int id;
  char  *judul;
  int tahun;
};

struct Perpustakaan {
  char *nama;
  char *alamat;
  
  struct Buku data_buku; //struct didalam struct
} data_perpustakaan;

int main( ) {

  struct Perpustakaan data_perpustakaan = {"Perpustakaan ITTS", "Ketintang No. 156", 001, "Dilan", 2018};
  printf( "Id Buku : %d\n",data_perpustakaan.data_buku.id);
  printf( "Judul Buku : %s\n",data_perpustakaan.data_buku.judul);
  printf( "Tahun Buku : %d\n",data_perpustakaan.data_buku.tahun);
  printf( "Nama Perpustakaan : %s\n",data_perpustakaan.nama);
  printf( "Alamat Perpustakaan : %s\n",data_perpustakaan.alamat);

  return 0;
}