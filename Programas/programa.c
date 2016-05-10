#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (){
    typedef int breno;

    int a = 5;
    int b = 10;

    breno c;

    c = a + b;

    printf("C = %d\n",c);

    system("pause");
    return 0;
}
