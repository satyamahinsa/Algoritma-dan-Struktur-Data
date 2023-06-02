#include <stdio.h>
#include <string.h>

// Inisialisasi struct dengan nama stack menggunakan typedef.
// stack berisi variabel str bertipe data char dengan ukuran 100
// dan variabel top bertipe data int.
typedef struct Stack {
  char str[100];
  int top;
} stack;

// createEmptyStack() => digunakan untuk membuat stack kosong.
void createEmptyStack(stack *stack) {
  stack->top = -1;
}

// push() => digunakan untuk memasukkan sebuah karakter (value) ke dalam stack.
void push(stack *stack, char value) {
  stack->top++;
  stack->str[stack->top] = value;
}

// pop() => digunakan untuk menghapus sebuah karakter (value) paling atas dalam stack
// dan mengembalikan karakter yang dihapus.
char pop(stack *stack) {
  char value = stack->str[stack->top];
  stack->top--;
  return value;
}

// peek() => digunakan untuk mengembalikan sebuah karakter (value) paling atas dalam stack
char peek(stack *stack) {
  return stack->str[stack->top];
}

// priority() => digunakan untuk menentukan prioritas sebuah operator dalam operasi.
int priority(char ch) {
  if(ch == '^') {
    return 3;
  } else if(ch == '*' || ch == '/') {
    return 2;
  } else if(ch == '+' || ch == '-') {
    return 1;
  } else {
    return 0;
  }
}

// infix_to_postfix() => digunakan untuk mengubah sebuah operasi infix menjadi operasi postfix.
void infix_to_postfix(char *infix) {
  // Deklarasi variabel postfix bertipe data char dengan ukuran 100.
  char postfix[100];
  // Deklarasi variabel temp_operator bertipe data stack.
  // temp_operator digunakan untuk menyimpan seluruh operator dalam operasi infix.
  stack temp_operator;
  // Menginisialisasi stack kosong di dalam variabel temp_operator.
  createEmptyStack(&temp_operator);
  // Lakukan push '(' dalam stack sebagai elemen pertama. 
  push(&temp_operator, '(');
  // Sisipkan ')' ke dalam indeks terakhir variabel infix.
  infix[strlen(infix)] = ')';

  // Perulangan yang digunakan untuk melihat karakter di dalam operasi infix.
  for(int i = 0, j = -1; i < strlen(infix); i++) {
    // Mengecek apakah karakter infix dengan indeks ke-i merupakan sebuah operator.
    if(infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-' || infix[i] == '^') {
      // Jika iya, maka lakukan pengecekan prioritas operator di dalam temp_operator dengan operator di variabel infix.
      if(priority(peek(&temp_operator)) >= priority(infix[i])) {
        // Jika operator di dalam temp_operator memiliki prioritas yang lebih tinggi, maka masukkan elemen top ke dalam variabel postfix dengan indeks ke-j.
        j++;
        postfix[j] = pop(&temp_operator);
      }
      // Lakukan push untuk menyimpan karakter infix dengan indeks ke-i ke dalam stack temp_operator.
      push(&temp_operator, infix[i]);
    // Mengecek apakah karakter infix dengan indeks ke-i merupakan '('.
    } else if(infix[i] == '(') {
      // Jika iya, maka lakukan push untuk menyimpan karakter '(' ke dalam temp_operator.
      push(&temp_operator, infix[i]);
    // Mengecek apakah karakter infix dengan indeks ke-i merupakan ')'.
    } else if(infix[i] == ')') {
      // Jika iya, maka lakukan perulangan selama elemen top dari temp_operator bukan '('. 
      while(peek(&temp_operator) != '(') {
        // Memasukkan elemen top ke dalam variabel postfix dengan indeks ke-j.
        j++;
        postfix[j] = pop(&temp_operator);
      }
      // Menghapus karakter '(' saat tidak digunakan.
      pop(&temp_operator);
    // Jika karakter infix dengan indeks ke-i merupakan sebuah huruf, maka masukkan huruf ke dalam variabel postfix dengan indeks ke-j.
    } else {
      j++;
      postfix[j] = infix[i];
    }
  }

  // Tampilkan hasil akhir dari operasi postfix.
  printf("%s\n", postfix);
  
}

int main(void) {
  // Membuat sebuah variabel input dengan ukuran 100 untuk menampung operasi infix.
  char input[100];

  // Meminta kepada user untuk melakukan input operasi infix.
  // Input dari user dimasukkan ke dalam variabel input.
  printf("Ekspresi Infix: ");
  fgets(input, sizeof(input), stdin);
  // fgets di atas membuat index terakhir dari input berisi '\n',
  // maka diganti dengan '\0' agar tidak ada baris baru.
  input[strlen(input) - 1] = '\0';

  // Menampilkan hasil konversi dari operasi infix menjadi operasi postfix.
  printf("Ekspresi Postfix: ");
  infix_to_postfix(input);
  return 0;
}
