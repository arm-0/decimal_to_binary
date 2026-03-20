#include <stdio.h>

int main() {
    int decimal = 0;
    printf("Enter a decimal number (0-255): ");
    scanf("%d", &decimal);

    if(decimal > 255 || decimal < 0){
        printf("Invalid input!");
        return 0;
    }

    printf("Binary equivalent of %d is: ", decimal);

    // We iterate from the most significant bit (2^7 = 128) 
    // down to the least significant bit (2^0 = 1).
    for (int i = 7; i >= 0; i--) {
        printf("%d", (decimal >> i) & 1);
    }

    printf("\n");
    return 0;
}
