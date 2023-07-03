#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct elemen *address;

struct elemen {
  int info;
  address next;
  address prev;
};

typedef struct {
  address first;
  address last;
} list_integer;

void createlist(list_integer *l) {
  l->first = NULL; //Elemen Pertama 
  l->last = NULL; //Elemen Terakhir
}

address createlm(int isi) {
  address p = (address)malloc(sizeof(struct elemen));
  p->info = isi; //Angka Baru
  p->next = NULL; //Pointer Next pada Angka Baru
  p->prev = NULL; //Pointer Prev pada Angka Baru
  return p;
}

void insertFirst(list_integer *l, address p){
  if((l->first == NULL) && (l->last == NULL)) {
    l->first = p;
    l->last = p;
    p->next = l->first;
    p->prev = l->last;
  } else {
    p->next = l->first;
    l->first->prev = p;
    l->first = p;
    l->first->prev = l->last;
    l->last->next = l->first;
  }
}

void insertLast(list_integer *l, address p){
  if((l->first == NULL) && (l->last == NULL)) {
    l->first = p;
    l->last = p;
    p->next = l->first;
    p->prev = l->last;
  } else {
    p->prev = l->last;
    l->last->next = p;
    l->last = p;
    l->first->prev = l->last;
    l->last->next = l->first;
  }
}

void insertAfter(list_integer *l, address p, int cari) {
  if((l->first == NULL) && (l->last == NULL)){
    l->first = p;
    l->last = p;
    p->next = l->first;
    p->prev = l->last;
  } else {
    address q = l->first;
    while ((q->next != NULL) && (q->info != cari)) {
      q = q->next;
    }
    if(q->info == cari) {
      p->next = q->next;
      p->prev = q;
      q->next->prev = p;
      q->next = p;
    }
  }
}

void deleteFirst(list_integer *l, address p) {
  p = l->first;
  if((l->first != NULL) && (l->last != NULL)) {
    if(l->first == l->last) {
      l->first = NULL;
      l->last = NULL;
      p->next = NULL;
      p->prev = NULL;
    } else {
      l->first = p->next;
      l->first->prev = l->last;
      l->last->next = l->first;
    }
  }
}

void deleteLast(list_integer *l, address p) {
  p = l->last;
  if((l->first != NULL) && (l->last != NULL)) {
    if(l->first == l->last) {
      l->first = NULL;
      l->last = NULL;
      p->next = NULL;
      p->prev = NULL;
    } else {
      l->last = p->prev;
      l->last->next = l->first;
    }
  }
}

void deleteAfter(list_integer *l, address p, int cari) {
  p = l->first;
  if((l->first != NULL) && (l->last != NULL)) {
    if((l->first == l->last) && (l->first->info == cari)) {
      l->first = NULL;
      l->last = NULL;
      p->next = NULL;
      p->prev = NULL;
    } else {
      address q;
      while((p->next != NULL) && (p->info != cari)) {
        q = p;
        p = p->next;
      }
      if(p->info == cari) {
        if(p == l->first) {
          deleteFirst(l,p);
        } else if(p == l->last) {
          deleteLast(l,p);
        } else {
          q->next = p->next;
          p->next->prev = q;
        }
      }
    }
  }
}

void cetak_list(list_integer l) {
    printf("Isi List : ");
    
    if(l.first == NULL) {
      printf("[]");
    } else {
      address curent = l.first;
      while(curent->next != l.first) {
        printf("[%d] ", curent->info);
        curent = curent->next;
      }
      printf("[%d] ",curent->info);
    }
}

int main(){
  list_integer l;
  createlist(&l);

  int isi, pilihan;
  address p;
  bool stop = false;

  while(!stop){
    system("cls");
    printf("---------- Program Circular List ----------\n\n");
    cetak_list(l);
    printf("\n\n1. Insert First");
    printf("\n2. Insert Last");
    printf("\n3. Insert After");
    printf("\n4. Delete First");
    printf("\n5. Delete Last");
    printf("\n6. Delete After");
    printf("\n7. Traversal");
    printf("\n8. Keluar");
    printf("\n\nMasukkan Pilihan : ");
    scanf("%d", &pilihan);
    if(pilihan == 1) {
      printf("Masukkan Angka : ");
      scanf("%d", &isi);
      p = createlm(isi);
      insertFirst(&l, p);
    } else if(pilihan == 2) {
      printf("Masukkan Angka : ");
      scanf("%d", &isi);
      p = createlm(isi);
      insertLast(&l, p);
    } else if(pilihan == 3) {
      printf("Masukkan Angka : ");
      scanf("%d", &isi);
      int sebelum;
      printf("Masukkan Angka Sebelumnya : ");
      scanf("%d", &sebelum);
      p = createlm(isi);
      insertAfter(&l, p, sebelum);
    } else if (pilihan == 4) {
      deleteFirst(&l, p);
    } else if (pilihan == 5) {
      deleteLast(&l, p);
    } else if (pilihan == 6) {
      int cari;
      printf("Masukkan angka yang ingin dihapus : ");
      scanf("%d", &cari);
      deleteAfter(&l, p, cari);
    } else if (pilihan == 7) {
      printf("\nTraversal List : ");

      if(l.first == NULL) {
        printf("[ ]");
      } else {
        address curent = l.last;
        while(curent->prev != l.last) {
            printf("[%d] ", curent->info);
            curent = curent->prev;
        }
        printf("[%d] ", curent->info);
      }
      printf("\n\n");
      system("pause");
    } else if(pilihan == 8) {
      stop = true;
    }
  }
  return 0;
}