void listAntrian() {
  pasien *curr = head;
  int i = 0;
  
  printf("Daftar Pasien dalam Antrian: \n");
  if(curr == NULL) {
    printf("Data Kosong!");
  } else {
    while(curr != NULL) {
      i++;
      printf("[%d] Nama: %s\n", i, curr->nama);
      curr = curr->next;
    }
  }
}