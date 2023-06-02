#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
  char nama[100];
  char nomor[20];
  struct Contact *next;
} contact;

typedef struct listContact {
  contact *head;
} list_contact;

void add_contact(list_contact *list, char *nama, char *nomor) {
  contact *new_contact = (contact*)malloc(sizeof(contact));
  strcpy(new_contact->nama, nama);
  strcpy(new_contact->nomor, nomor);
  new_contact->next = NULL;

  if(list->head == NULL) {
    list->head = new_contact;
    printf("Contact added successfully!\n");
  } else { 
    contact *tail = list->head;
    while(tail->next != NULL) {
      tail = tail->next;
    }
    
    tail->next = new_contact;
    printf("Contact added successfully!\n");
  }
}

contact *search_contact(list_contact *list, char *cari) {
  contact *contact = list->head;

  while(contact != NULL) {
    if(strcmp(contact->nama, cari) == 0) {
      return contact;
    }
    contact = contact->next;
  }
  
  return NULL;
}

void print_list_contact(list_contact *list) {
  contact *contact = list->head;

  printf("Daftar Kontak Telepon: \n");
  while(contact != NULL) {
    printf("Nama: %s\n", contact->nama);
    printf("Nomor Telepon: %s\n", contact->nomor);
    contact = contact->next;
  }
}


int main() {
  list_contact list;
  list.head = NULL;

  int choice;
  char input_nama[100], input_nomor[20];
  while(1) {
    system("cls");
    printf("Menu:\n");
    printf("1. Tambah Kontak\n");
    printf("2. Cari Kontak\n");
    printf("3. Cetak Daftar Kontak\n");
    printf("4. Keluar\n");
    printf("Pilih Menu: ");
    scanf("%d", &choice);

    printf("\n");
    switch(choice) {
      case 1:
        printf("Nama: ");
        scanf("%s", &input_nama);
        printf("Nomor Telepon: ");
        scanf("%s", &input_nomor);
        add_contact(&list, input_nama, input_nomor);
        break;
      case 2:
        if(list.head == NULL) {
          printf("Empty Data!\n");
        } else {
          printf("Nama: ");
          scanf("%s", &input_nama);
          contact *found_contact = search_contact(&list, input_nama);
          if(found_contact != NULL) {
            printf("Contact found!\n");
            printf("Nama: %s\n", found_contact->nama);
            printf("Nomor Telepon: %s\n", found_contact->nomor);
          } else {
            printf("Contact not found!\n");
          }
        }
        break;
      case 3:
        print_list_contact(&list);
        break;
      case 4:
        exit(1);
      default:
        printf("Please type valid input!\n");
        break;
    }
    getchar();
    printf("Press any key to continue...");
    getchar();
  }

  return 0;
}