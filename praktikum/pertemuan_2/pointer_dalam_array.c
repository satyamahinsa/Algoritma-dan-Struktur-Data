#include <stdio.h>

int main()
{
    int angka[5] = {1, 2, 3, 4, 5};
    printf("*angka   = %d\n", *angka);
    printf("angka[0] = %d\n", angka[0]);

    printf("*angka   = %d\n", *(angka + 3));
    printf("angka[3] = %d\n", angka[3]);
}