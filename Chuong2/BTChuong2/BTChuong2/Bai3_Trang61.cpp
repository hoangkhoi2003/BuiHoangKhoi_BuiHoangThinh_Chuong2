#include <stdio.h>

#define MAX_SIZE 1000

void nhapMang(int a[], int* n) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void xuatMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int kiemTraTangGiam(int a[], int n) {
    int tang = 1, giam = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) giam = 0;
        if (a[i] < a[i - 1]) tang = 0;
    }
    if (tang) return 1;  
    if (giam) return -1; 
    return 0;  
}

int main() {
    int a[MAX_SIZE], n;

    nhapMang(a, &n);

    printf("Mang vua nhap: ");
    xuatMang(a, n);

    int ketQua = kiemTraTangGiam(a, n);
    if (ketQua == 1) {
        printf("Mang tang dan.\n");
    }
    else if (ketQua == -1) {
        printf("Mang giam dan.\n");
    }
    else {
        printf("Mang khong tang khong giam.\n");
    }

    return 0;
}