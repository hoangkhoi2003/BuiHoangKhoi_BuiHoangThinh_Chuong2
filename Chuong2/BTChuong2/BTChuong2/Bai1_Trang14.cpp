#include <stdio.h>

int findPosition(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = { 7, 9, 13, 17, 27, 30, 31, 35, 38, 40 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int x1 = 17;
    int x2 = 35;
    int x3 = 40;
    int x4 = 23;
    int x5 = 10;
    int x6 = 36;

    int pos1 = findPosition(arr, size, x1);
    int pos2 = findPosition(arr, size, x2);
    int pos3 = findPosition(arr, size, x3);
    int pos4 = findPosition(arr, size, x4);
    int pos5 = findPosition(arr, size, x5);
    int pos6 = findPosition(arr, size, x6);

    printf("Vi tri cua x = %d : %d\n", x1, pos1);
    printf("Vi tri cua x = %d : %d\n", x2, pos2);
    printf("Vi tri cua x = %d : %d\n", x3, pos3);
    printf("Vi tri cua x = %d : %d\n", x4, pos4 == -1 ? -1 : pos4);
    printf("Vi tri cua x = %d : %d\n", x5, pos5 == -1 ? -1 : pos5);
    printf("Vi tri cua x = %d : %d\n", x6, pos6 == -1 ? -1 : pos6);

    return 0;
}
