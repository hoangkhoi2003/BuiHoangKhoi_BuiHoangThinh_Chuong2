#include <stdio.h>

int findPosition(char arr[], int size, char x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i + 1;  
        }
    }
    return -1;  
}

int main() {
    char arr[] = { 'Z', 'R', 'L', 'K', 'H', 'F', 'E', 'C', 'A' };
    int size = sizeof(arr) / sizeof(arr[0]);

    char x1 = 'R';
    char x2 = 'C';
    char x3 = 'D';
    char x4 = 'Q';

    int pos1 = findPosition(arr, size, x1);
    int pos2 = findPosition(arr, size, x2);
    int pos3 = findPosition(arr, size, x3);
    int pos4 = findPosition(arr, size, x4);

    printf("Vi tri cua x = %c : %d\n", x1, pos1);
    printf("Vi tri cua x = %c : %d\n", x2, pos2);
    printf("Vi tri cua x = %c : %d\n", x3, pos3 == -1 ? -1 : pos3);
    printf("Vi tri cua x = %c : %d\n", x4, pos4 == -1 ? -1 : pos4);

    return 0;
}
