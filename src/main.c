#include <stdio.h>


int main() {
    long num = 0;
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

    printf("Enter a decimal number (%lli to %lli): ", -max, max-1);

    if(scanf("%ld%c", &num, &check) != 2 || check != '\n'){
        printf("Error: Invalid input. Please enter a whole number only.\n");
        
        while (getchar() != '\n');
        return 1;
    }

    if(num >= max){
        printf("Invalid input!");
        return 1;
    }

    printf("Binary equivalent of %ld is: ", num);

    // We iterate from the most significant bit (2^7 = 128) 
    // down to the least significant bit (2^0 = 1).
    for (int i = bits - 1; i >= 0; i--) {
        printf("%ld", (num >> i) & 1);

        if(i % 4 == 0 && i != 0) printf(" ");
    }

    printf("\n");
    return 0;
}
