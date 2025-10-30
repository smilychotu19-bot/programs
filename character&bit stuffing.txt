#include <stdio.h>
#include <string.h>

void char_count(char *data) {
    printf("\n[Character Count]\nFrame: %d%s\n", (int)strlen(data), data);
}

void char_stuff(char *data) {
    char res[200]; int i, j = 0;
    res[j++] = 'F';
    for (i = 0; data[i]; i++) {
        if (data[i] == 'F' || data[i] == 'E') res[j++] = 'E';
        res[j++] = data[i];
    }
    res[j++] = 'F'; res[j] = '\0';
    printf("\n[Character Stuffing]\nFrame: %s\n", res);
}

void bit_stuff(char *data) {
    char res[200], flag[] = "01111110";
    int i, j = 0, count = 0;
    strcpy(res, flag); j = strlen(flag);
    for (i = 0; data[i]; i++) {
        res[j++] = data[i];
        if (data[i] == '1') {
            count++;
            if (count == 5) { res[j++] = '0'; count = 0; }
        } else count = 0;
    }
    strcat(res, flag);
    printf("\n[Bit Stuffing]\nFrame: %s\n", res);
}

int main() {
    char data[100];
    int choice = 0;

    while (choice != 4) {
        printf("\n=== Framing Methods ===\n");
        printf("1. Character Count\n2. Character Stuffing\n3. Bit Stuffing\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear buffer

        if (choice == 4) {
            printf("\nExiting...\n");
            break;
        }

        printf("Enter data: ");
        fgets(data, sizeof(data), stdin);
        data[strcspn(data, "\n")] = '\0';

        switch (choice) {
            case 1: char_count(data); break;
            case 2: char_stuff(data); break;
            case 3: bit_stuff(data); break;
            default: printf("\nInvalid choice!\n");
        }
    }
    return 0;
}
  

ouput:


=== Framing Methods ===
1. Character Count
2. Character Stuffing
3. Bit Stuffing
4. Exit
Enter your choice: 1
Enter data: HEYYA

[Character Count]
Frame: 5HEYYA


=== Framing Methods ===
1. Character Count
2. Character Stuffing
3. Bit Stuffing
4. Exit
Enter your choice: 2
Enter data: ABCECFA

[Character Stuffing]
Frame: FABCECEFAF


=== Framing Methods ===
1. Character Count
2. Character Stuffing
3. Bit Stuffing
4. Exit
Enter your choice: 3
Enter data: 0111111110

[Bit Stuffing]
Frame: 011111100111110111001111110


=== Framing Methods ===
1. Character Count
2. Character Stuffing
3. Bit Stuffing
4. Exit
Enter your choice: 4

Exiting...
