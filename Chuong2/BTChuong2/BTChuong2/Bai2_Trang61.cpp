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

int mangDoiXung(int a[], int n) {
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - 1 - i]) return 0;
    }
    return 1;
}

int main() {
    int a[MAX_SIZE], n;

    nhapMang(a, &n);

    printf("Mang vua nhap: ");
    xuatMang(a, n);

    if (mangDoiXung(a, n)) {
        printf("Mang doi xung.\n");
    }
    else {
        printf("Mang khong doi xung.\n");
    }

    return 0;
}