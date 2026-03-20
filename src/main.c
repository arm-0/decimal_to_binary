#include <stdio.h>


int main() {
    long long num = 0;
    int bits = 0;
    long long max = 0;
    char check;

    printf("How many bits? E.g., 2, 8, 16, ... , 31.\n");
    if(scanf("%d%c", &bits, &check) != 2 || check != '\n' || bits <= 0 || bits >= 32){
        printf("Error: Invalid bit selection!\n");
        while(check != '\n' && getchar() != '\n');
        return 1;
    } 

    max = 1LL << (bits - 1);

    while(1){
    check = 0;
    printf("Enter a whole number (%lld to %lld): \n", -max, max-1);
        if(scanf("%lld%c", &num, &check) == 2 && check == '\n'){
            if(num < max && num >= -max) break;
            else{
                printf("Error: Number is out of range!\n");
                continue;
            }
        }
        printf("Error! Invalid input.\n");
        if(check != '\n'){
            int c;
            while((c = getchar()) != '\n' && c != EOF);
        }
    }

    printf("Binary equivalent of %lld is: ", num);

    for (int i = bits - 1; i >= 0; i--) {
        printf("%lld", (num >> i) & 1);

        if(i % 4 == 0 && i != 0) printf(" ");
    }

    printf("\n");
    return 0;
}
