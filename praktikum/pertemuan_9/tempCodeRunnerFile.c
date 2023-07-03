// viewData() => digunakan untuk melihat seluruh data di dalam list.
void viewData(node head) {
  // Inisialisasi node curr yang merujuk ke head.
  node curr = head;

  // Perulangan berikut dilakukan hingga bertemu dengan node terakhir di dalam list.
  while(curr->next != head) {
    // Menampilkan data pada node saat ini.
    printf("Elemen %d ", curr->data);
    // Mengubah node curr menjadi node selanjutnya. 
    curr = curr->next;
  }
  // Menampilkan data pada node saat ini.
  printf("Elemen %d\n", curr->data);
}

int main() {
  // Inisialisasi node head dengan nilai awal, yaitu NULL.
  node head = NULL;
  // Deklarasi variabel input bertipe data char.
  char input;

  // Lakukan perulangan berikut hingga user melakukan input 'n'.
  do {
    // Update node head dengan memanggil fungsi insertLast().
    head = insertLast(head, createNode());
    // Meminta user untuk memasukkan input dalam melanjutkan perulangan.
    printf("Tambah data lagi? (y/n): ");
    fflush(stdin);
    scanf("%c", &input);
  } while(input != 'n');

  // Menampilkan seluruh data yang ada di dalam list sebelum diurutkan.
  printf("List sebelum diurutkan: ");
  viewData(head);

  head = ascendingData(head);

  // Menampilkan seluruh data yang ada di dalam list sebelum diurutkan.
  printf("List setelah diurutkan: ");
  viewData(head);

  return 0;
}