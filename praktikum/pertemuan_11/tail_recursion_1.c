#include <stdio.h>

int faktorial(int num) {
  if(num <= 1) {
    return 1;
  } else {
    return num * faktorial(num - 1);
  }
}

int main() {
  printf("%d", faktorial(5));

  return 0;
}