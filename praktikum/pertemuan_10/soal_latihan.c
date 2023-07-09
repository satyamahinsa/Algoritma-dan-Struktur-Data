#include <stdio.h>

int pangkat(int x, int y) {
  if(y == 0) {
    return 1;
  } else {
    return x * pangkat(x, y - 1);
  }
}

int main() {
  int x, y;
  scanf("%d %d", &x, &y);

  printf("%d", pangkat(x, y));
  return 0;
}