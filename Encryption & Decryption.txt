#include <stdio.h>
#include <string.h>

void encrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = 'A' + (text[i] - 'A' + key) % 26;
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = 'a' + (text[i] - 'a' + key) % 26;
        }
    }
}

void decrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = 'A' + (text[i] - 'A' - key + 26) % 26;
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = 'a' + (text[i] - 'a' - key + 26) % 26;
        }
    }
}

int main() {
    char text[100];
    int key;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter key (number): ");
    scanf("%d", &key);

    printf("\nOriginal text: %s\n", text);

    encrypt(text, key);
    printf("Encrypted text: %s\n", text);

    decrypt(text, key);
    printf("Decrypted text: %s\n", text);

    return 0;
}




output:


Enter text: Hello Computer
Enter key (number): 2

Original text: Hello Computer
Encrypted text: Jgnnq Eqorwvgt
Decrypted text: Hello Computer

