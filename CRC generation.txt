#include <stdio.h>
#include <string.h>

// Function to perform Modulo-2 division
void computeCRC(char data[], char poly[], char crc[]) {
    int dataLen = strlen(data);
    int polyLen = strlen(poly);
    char temp[256];

    strcpy(temp, data);
    for (int i = 0; i < polyLen - 1; i++)
        strcat(temp, "0");

    char remainder[256];
    strcpy(remainder, temp);

    for (int i = 0; i < dataLen; i++) {
        if (remainder[i] == '1') {
            for (int j = 0; j < polyLen; j++) {
                remainder[i + j] = (remainder[i + j] == poly[j]) ? '0' : '1';
            }
        }
    }

    strncpy(crc, &remainder[dataLen], polyLen - 1);
    crc[polyLen - 1] = '\0';
}

int main() {
    char data[128];
    char crc[128], codeword[256];

    // Standard Polynomials
    char poly12[]   = "1100000001111";      // CRC-12
    char poly16[]   = "11000000000000101";  // CRC-16
    char polyCCITT[] = "10001000000100001"; // CRC-CCITT

    printf("\n=== CRC Computation for All Polynomials ===\n");
    printf("Enter data bits: ");
    scanf("%s", data);

    printf("\nData bits: %s\n", data);

    // --- CRC-12 ---
    computeCRC(data, poly12, crc);
    strcpy(codeword, data);
    strcat(codeword, crc);
    printf("\n[CRC-12]");
    printf("\nGenerator Polynomial: %s", poly12);
    printf("\nCRC bits: %s", crc);
    printf("\nTransmitted Codeword: %s\n", codeword);

    // --- CRC-16 ---
    computeCRC(data, poly16, crc);
    strcpy(codeword, data);
    strcat(codeword, crc);
    printf("\n[CRC-16]");
    printf("\nGenerator Polynomial: %s", poly16);
    printf("\nCRC bits: %s", crc);
    printf("\nTransmitted Codeword: %s\n", codeword);

    // --- CRC-CCITT ---
    computeCRC(data, polyCCITT, crc);
    strcpy(codeword, data);
    strcat(codeword, crc);
    printf("\n[CRC-CCITT]");
    printf("\nGenerator Polynomial: %s", polyCCITT);
    printf("\nCRC bits: %s", crc);
    printf("\nTransmitted Codeword: %s\n", codeword);

    return 0;
}
  

output:


=== CRC Computation for All Polynomials ===
Enter data bits: 1100111011

Data bits: 1100111011

[CRC-12]
Generator Polynomial: 1100000001111
CRC bits: 111110100100
Transmitted Codeword: 1100111011111110100100

[CRC-16]
Generator Polynomial: 11000000000000101
CRC bits: 100010101001001
Transmitted Codeword: 1100111011100010101001001

[CRC-CCITT]
Generator Polynomial: 10001000000100001
CRC bits: 10100100101011
Transmitted Codeword: 110011101110100100101011

Process returned 0 (0x0)   execution time : 8.901 s
Press any key to continue.
