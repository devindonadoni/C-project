#include <stdio.h>

int main() {
    int n = 0;

    printf("inserisci numero positivo\n");
    scanf("%d", &n);

    for (int i = 2; i<=n; i++){
        int bool = 1;

        for(int k = 2; k < i; k++){
            if(i%k == 0){
                bool = 0;
            }
        }

        if(bool){
            printf("%d ", i);
        }
    }
    return 0;
}


