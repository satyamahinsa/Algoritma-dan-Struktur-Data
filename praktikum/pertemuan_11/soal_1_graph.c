#include <stdio.h>
#include <stdlib.h>

// Deklarasi graph dengan menggunakan struct yang memiliki alias Graph.
// Di dalamnya, terdapat variabel vertex bertipe data integer untuk menyimpan nilai,
// variabel jumlah_tetangga bertipe data integer untuk menyimpan banyak tetangga,
// variabel pointer tetangga untuk menyimpan tetangga yang berhubungan.
typedef struct {
  int vertex;
  int jumlah_tetangga;
  int *tetangga;
} Graph;

// buatGraph() => digunakan untuk membuat sebuah graph dengan banyak vertex yang telah ditentukan.
Graph* buatGraph(int banyak_vertex) {
  Graph* graph = (Graph*)malloc(banyak_vertex * sizeof(Graph));
  
  // Inisialisasi setiap vertex dengan nilai dari 0 hingga banyak vertex - 1.
  for (int i = 0; i < banyak_vertex; i++) {
    graph[i].vertex = i;
    graph[i].jumlah_tetangga = 0;
    graph[i].tetangga = NULL;
  }
  
  // Mengembalikan graph yang telah dibuat.
  return graph;
}

// tambahEdge() => digunakan untuk menambahkan edge antara dua vertex, yaitu asal (src) dan tujuan (dest).
void tambahEdge(Graph* graph, int src, int dest) {
  // Mengalokasikan ulang memori pada tetangga src sesuai dengan jumlah tetangga yang sudah diupdate.
  graph[src].tetangga = (int*)realloc(graph[src].tetangga, (graph[src].jumlah_tetangga + 1) * sizeof(int));
  // Menambahkan nilai dest ke dalam tetangga dari src
  graph[src].tetangga[graph[src].jumlah_tetangga] = dest;
  // Menambahkan jumlah_tetangga dengan 1.
  graph[src].jumlah_tetangga++;
  
  // Mengalokasikan ulang memori pada tetangga dest sesuai dengan jumlah tetangga yang sudah diupdate.
  graph[dest].tetangga = (int*)realloc(graph[dest].tetangga, (graph[dest].jumlah_tetangga + 1) * sizeof(int));
  // Menambahkan nilai src ke dalam tetangga dest
  graph[dest].tetangga[graph[dest].jumlah_tetangga] = src;
  // Menambahkan jumlah_tetangga dengan 1.
  graph[dest].jumlah_tetangga++;
}

int main() {
  // Deklarasi variabel jumlah_orang, banyak_tetangga, src, dan dest bertipe data integer.
  int jumlah_orang, banyak_tetangga, src, dest;

  // Meminta user untuk memasukkan jumlah orang dan banyak tetangga.
  scanf("%d %d", &jumlah_orang, &banyak_tetangga);

  // Memanggil fungis buatGraph() untuk membuat sebuah graph dengan banyak vertex sesuai jumlah orang.
  Graph* graph = buatGraph(jumlah_orang);

  // Melakukan perulangan hingga user mengetikkan nilai -1 pada src dan dest.
  while(1) {
    // Meminta user untuk memasukkan edge setiap vertex melalui input.
    scanf("%d %d", &src, &dest);
    
    // Perulangan akan berhenti ketika src dan dest bernilai -1.
    if(src == -1 && dest == -1) {
      break;
    }
    
    // Memanggil fungsi tambahEdge() untuk menambahkan edge di antara vertex src dan dest.
    tambahEdge(graph, src, dest);
  }

  // Perulangan dilakukan untuk memeriksa apakah seseorang termasuk wibu nolep atau bukan.
  for(int i = 0; i < jumlah_orang; i++) {
    // Jika ada seseorang (vertex) memiliki banyak tetangga (edge) yang lebih dari 
    // aturan yang telah ditetapkan, maka seseorang (vertex) tersebut merupakan wibu nolep.
    if(graph[i].jumlah_tetangga < banyak_tetangga) {
      printf("Vertex %d adalah wibu nolep", i); 
    }
  }

  // Menghapus atau membebaskan memori graph secara keseluruhan.
  for (int i = 0; i < jumlah_orang; i++) {
    free(graph[i].tetangga);
  }
  free(graph);

  return 0;
}
