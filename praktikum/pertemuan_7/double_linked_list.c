#include <stdio.h>
#include <stdlib.h>

// Deklarasi node dengan double linked list.
typedef struct DoubleLinkedList {
  struct DoubleLinkedList *prev;
  int data;
  struct DoubleLinkedList *next;
} node;

node *head = NULL;

// alokasiNodeBaru() => digunakan untuk membuat node baru.
node *alokasiNodeBaru() {
  node *new_node = NULL;
  new_node = (node*)malloc(sizeof(node));
  return new_node;
}

// insertFirst() => digunakan untuk memasukkan sebuah node ke awal list.
void insertFirst(node *new_node) {
  printf("Masukkan bilangan: ");
  scanf("%d", &new_node->data);

  if(head == NULL) {
    new_node->prev = head;
    new_node->next = head;
    head = new_node;
  } else {
    new_node->prev = head;
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
  }
}

// insertLast() => digunakan untuk memasukkan sebuah node ke akhir list.
void insertLast(node *new_node) {
  node *tail = head;

  printf("Masukkan bilangan: ");
  scanf("%d", &new_node->data);

  while(tail->next != NULL) {
    tail = tail->next;
  }

  tail->next = new_node;
  new_node->prev = tail;
  new_node->next = NULL;
}

// inseertAfter() => digunakan untuk menyisipkan sebuah node setelah node yang ditentukan.
void insertAfter(node *new_node) {
  node *cari = head;
  int sisip;

  printf("Masukkan bilangan: ");
  scanf("%d", &new_node->data);

  printf("Data disisipkan setelah nilai: ");
  scanf("%d", &sisip);

  while(cari != NULL && cari->data != sisip) {
    cari = cari->next;
  }

  if(cari == NULL) {
    printf("Data tidak ditemukan!");
  } else if(cari->data == sisip) {
    new_node->next = cari->next;
    cari->next->prev = new_node;
    cari->next = new_node;
    new_node->prev = cari;
  } else {
    while(cari->next != NULL) {
      cari = cari->next;
    }
    cari->next = new_node;
    new_node->prev = cari;
    new_node->next = NULL;
  }
}

// deleteFirst() => digunakan untuk menghapus node pertama dalam list.
void deleteFirst() {
  node *hapus;

  if(head->next == NULL) {
    head = NULL;
  } else {
    hapus = head;
    head = head->next;
    head->prev = NULL;
    free(hapus);
  }
}

// deleteLast() => digunakan untuk menghapus node terakhir dalam list.
void deleteLast() {
  node *tail = head;
  
  if(head->next == NULL) {
    head = NULL;
  } else {
    while(tail->next != NULL) {
      tail = tail->next;
    }
    tail->prev->next = NULL;
    free(tail);
  }
}

// deleteAfter() => digunakan untuk menghapus sebuah node setelah node tertentu.
void deleteAfter() {
  node *cari;
  int hapus;
  cari = head;
  
  printf("Masukkan bilangan: ");
  scanf("%d", &hapus);

  while(cari != NULL && cari->data != hapus) {
    cari = cari->next;
    printf("%d", cari->data);
  }
  system("pause");
  if(cari == NULL) {
    printf("Data tidak ditemukan!");
  } else if(head->next == NULL) {
    head = NULL;
  } else if(cari == head) {
    cari = head;
    head = head->next;
    head->prev = NULL;
    free(cari);
  } else if(cari->next == NULL) {
    cari->prev->next = NULL;
    free(cari);
  } else {
    cari->prev->next = cari->next;
    cari->next->prev = cari->prev;
    free(cari);
  }
}

// view() => digunakan untuk melihat seluruh isi list.
void view() {
  node *curr = head;
  
  if(curr == NULL) {
    printf("Data Kosong!");
  } else {
    printf("\n");
    while(curr != NULL) {
      printf("[%d]", curr->data);
      curr = curr->next;
    }
  }
}

// cariData() => digunakan untuk mencari data yang diinputkan oleh user.
void cariData() {
  node *curr = head;
  int cari;

  printf("Data yang dicari: ");
  scanf("%d", &cari);

  while(curr != NULL && curr->data != cari) {
    curr = curr->next;
  }

  if(curr == NULL) {
    printf("Data tidak ditemukan\n");
  } else {
    printf("Data ditemukan\n");
  }
  system("pause");
}

int main()
{
  node *pNew;
  int pilih, bil;

  do{
    system("cls");
    view();
    printf("\n\n");
    printf("------------ MENU ------------");
    printf("\n1. Insert First");
    printf("\n2. Insert Last");
    printf("\n3. Insert After");
    printf("\n4. Delete First");
    printf("\n5. Delete Last");
    printf("\n6. Delete After");
    printf("\n7. Cari Data");
    printf("\n8. Exit");

    printf("\nPilihan: ");
    scanf("%d", &pilih);

    if(pilih == 1) {
      pNew = alokasiNodeBaru();
      insertFirst(pNew);
    } else if(pilih == 2) {
      pNew = alokasiNodeBaru();
      insertLast(pNew);
    } else if(pilih == 3) {
      pNew = alokasiNodeBaru();
      insertAfter(pNew);
    } else if(pilih == 4) {
      deleteFirst();
    } else if(pilih == 5) {
      deleteLast();
    } else if(pilih == 6) {
      deleteAfter();
    } else if(pilih == 7) {
      cariData();
    }
  } while (pilih != 8);

  printf("\n");
  return 0;
}
