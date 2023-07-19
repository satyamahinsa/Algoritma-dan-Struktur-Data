#include <stdio.h>

int faktorial(int num, int hasil) {
  if(num <= 1) {
    return hasil;
  } else {
    return faktorial(num - 1, num * hasil);
  }
}

int main() {
  printf("%d", faktorial(5, 1));

  return 0;
}