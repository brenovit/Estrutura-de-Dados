#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");
    int fat, n;
    printf("Insira um valor para o qual deseja calcular seu fatorial: ");
    scanf("%d", &n);

    /*for(fat = 1; n > 1; n = n - 1){
        printf("%d * %d = %d\n", fat, n, fat * n);
        fat = fat * n;
    }*/
    fat = fatorial(n);
    printf("\nFatorial calculado: %d", fat);
    return 0;
}

int fatorial(int n){
    if(n){
        printf("%d * %d = %d\n", n, (n-1), (n * (n-1)));
        return n * fatorial(n-1);
    }else{
        return 1;
    }
}
