#include <stdio.h>

int main()
{
    int x = 100;
    int *ptr = &x;
    int **ptr2 = &ptr;

    printf("x      = %d\n", x); // berisi nilai dari variabel x
    printf("&x     = %d\n", &x); // berisi alamat memori dari variabel x
    printf("\n");
    printf("ptr    = %d\n", ptr); // berisi nilai dari variable ptr, yaitu alamat memori dari variabel x
    printf("*ptr   = %d\n", *ptr); // berisi nilai dari variabel x
    printf("&ptr   = %d\n", &ptr); // berisi alamat memori dari variabel ptr
    printf("\n");
    printf("ptr2   = %d\n", ptr2); // berisi nilai dari variabel ptr2, yaitu alamat memori dari variabel ptr
    printf("*ptr2  = %d\n", *ptr2); // berisi alamat memori dari variabel x
    printf("**ptr2 = %d\n", **ptr2); // berisi nilai dari variabel x
}
