#include <stdio.h>
#include <math.h>

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

int laSoNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int toanSoNguyenTo(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (!laSoNguyenTo(a[i])) return 0;
    }
    return 1;
}

int main() {
    int a[MAX_SIZE], n;

    nhapMang(a, &n);

    printf("Mang vua nhap: ");
    xuatMang(a, n);

    if (toanSoNguyenTo(a, n)) {
        printf("Mang chua toan bo so nguyen to.\n");
    }
    else {
        printf("Mang khong chua toan bo so nguyen to.\n");
    }

    return 0;
}