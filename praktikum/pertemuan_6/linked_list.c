#include <stdio.h>

// Deklarasi pointer dengan tipe data struct node
typedef struct node *address;
// Isi dari struct
struct node{
	int isi;
	address next;
};
//fungsi membuat simpul baru
address createNode(int nilai){
  address p;
  //alokasi node
  p = (address)malloc(sizeof(struct node));
  p->isi = nilai;
  p->next = NULL;
  return (p);
}

address insertFirst(address head, int nilai){
  address new_node = createNode(nilai);
  new_node->next = head;
  head = new_node;
  return(head);
}

address insertLast(address head, int nilai){
  //iterasi mencari node terakhir
  address tail = head;
  while(tail->next != NULL){
    tail = tail->next;
  }
  //buat simpul baru
  address new_node = createNode(nilai);
  tail->next = new_node;
  return(head);
}

address insertAfter(address head, int nilai, int prev_nilai){
//mencari simpul sebelumnya, mulai dari simpul pertama
  address cursor = head;
  while (cursor->isi != prev_nilai){
      cursor = cursor->next;
  }
  address new_node = createNode(nilai);
  new_node->next = cursor->next;
  cursor->next = new_node;
  return(head);
}

address insertBefore(address head, int nilai, int next_nilai){
  if(head->isi == next_nilai){
    head = insertFirst(head, nilai);
  } else {
    address cursor, prevcursor;
    cursor = head;
    do {
      prevcursor = cursor;
      cursor = cursor->next;
    } while (cursor->isi != next_nilai);

    address new_node = createNode(nilai);
    new_node->next = cursor;
    prevcursor->next = new_node;
  } 
  return(head);
}

address deleteFirst(address head){
  if(head==NULL){
      return;
  }
  address first = head;
  head = head->next;
  first->next = NULL;
  free(first);
  return(head);
}

address deleteLast(address head){
  if (head==NULL){
    return;
  }
  address tail = head;
  address prevtail = NULL;
  while (tail->next != NULL){
    prevtail = tail;
    tail = tail->next;
  }
  prevtail->next = NULL;
  free(tail);
  return(head);
}

address deleteAfter(address head, int nilai){
  address cursor = head;
  while (cursor != NULL){
    if(cursor->next->isi == nilai){
      break; //keluar dari iterasi
    } cursor = cursor->next;
  }
  if (cursor != NULL){
    address tmp = cursor->next;
    cursor->next = tmp->next;
    tmp->next = NULL;
    free(tmp);
  }
  return(head);
}

void tampilnilai(address head){
  address n = head;
  printf("Daftar nilai linked list : \n");

  while (n != NULL){
    printf("[%d] ", n->isi);
    n = n->next;
  };
  printf("\n");
}

//menghitung jumlah node
address count(address head){
  int count = 0;
  struct node *p;
  p = head;
  while (p != NULL){
    p = p->next;
    count++;
  }
  printf("Jumlah node adalah : %d\n", count);
  return(head);
}

address dispose(address head){
  if(head == NULL){
    return;
  }
  while(head != NULL){
    address tmp = head;
    head = head->next;
    tmp->next = NULL;
    free(tmp);
  }
  printf("Semua node (simpul) telah dihapus\n");
  return(head);
}

int main()
{
  int pilih, val, val1;
  address head = NULL;
  while(1){
  system("cls");
  tampilnilai(head);
  printf("\n======================== SINGLE LINKED LIST ========================\n");
  printf("1. Insert First\n");
  printf("2. Insert Last\n");
  printf("3. Insert After\n");
  printf("4. Insert Before\n");
  printf("5. Delete First\n");
  printf("6. Delete Last\n");
  printf("7. Delete After\n");
  printf("8. Hitung Jumlah Node\n");
  printf("9. Hapus Keseluruhan Node\n");
  printf("10. Keluar\n");
  printf("Pilihan Anda = ");
  scanf("%d", &pilih);
  switch (pilih){
  case 1:
    {
      printf("Masukkan nilai = ");
      scanf("%d", &val);
      head = insertFirst(head, val);
      system("cls");
      break;
    }
  case 2 :
    {
      printf("Masukkan nilai = ");
      scanf("%d", &val);
      head = insertLast(head, val);
      system("cls");
      break;
    }
  case 3 :
    {
      printf("Masukkan nilai = ");
      scanf("%d", &val);
      printf("Masukkan nilai tersebut setelah = ");
      scanf("%d", &val1);
      head = insertAfter(head, val, val1);
      system("cls");
      break;
    }
  case 4 :
    {
      printf("Masukkan nilai = ");
      scanf("%d", &val);
      printf("Masukkan nilai tersebut sebelum = ");
      scanf("%d", &val1);
      head = insertBefore(head, val, val1);
      system("cls");
      break;
    }
  case 5 :
    {
      head = deleteFirst(head);
      system ("cls");
      break;
    }
  case 6 :
    {
      head = deleteLast(head);
      system ("cls");
      break;
    }
  case 7 :
    {
      printf("Masukkan nilai yang ingin dihapus = ");
      scanf("%d", &val);
      head = deleteAfter(head, val);
      system ("cls");
      break;
    }
  case 8 :
    {
      head = count(head);
      system ("Pause");
      break;
    }
  case 9 :
    {
      head = dispose(head);
      system ("Pause");
      break;
    }
  case 10 :
    {
      exit(1);
    }
  default :
    {
      printf("Pilihan tersebut tidak ada");
      break;
    }
  }
  }
  return 0;
}