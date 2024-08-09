#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

// Hàm nhập mảng
void nhapMang(int a[], int* n) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

// Hàm xuất mảng
void xuatMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Hàm kiểm tra số nguyên tố
int laSoNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// 1. Đếm số phần tử có giá trị là số nguyên tố trong mảng a
int demSoNguyenTo(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(a[i])) {
            count++;
        }
    }
    return count;
}

// 2. Kiểm tra xem một số có toàn chữ số lẻ hay không
int toanChuSoLe(int num) {
    if (num < 0) num = -num;
    while (num > 0) {
        if ((num % 10) % 2 == 0) return 0;
        num /= 10;
    }
    return 1;
}

// Xuất các phần tử mà từng chữ số của nó là số lẻ
void xuatPhanTuToanLe(int a[], int n) {
    printf("Cac phan tu co toan chu so le: ");
    for (int i = 0; i < n; i++) {
        if (toanChuSoLe(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// 3. Tìm vị trí số lớn nhất cuối cùng của mảng
int viTriMaxCuoiCung(int a[], int n) {
    int max = a[0];
    int viTri = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] >= max) {
            max = a[i];
            viTri = i;
        }
    }
    return viTri;
}

// 4. Kiểm tra mảng có toàn là số chẵn không
int toanSoChan(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) return 0;
    }
    return 1;
}

// 5. Kiểm tra mảng có phải là dãy số chẵn lẻ xen kẻ không
int chanLeXenKe(int a[], int n) {
    if (n < 2) return 1;  // Mảng có 0 hoặc 1 phần tử luôn xen kẽ
    int parity = a[0] % 2;
    for (int i = 1; i < n; i++) {
        if ((a[i] % 2) == parity) return 0;
        parity = !parity;
    }
    return 1;
}

int main() {
    int a[MAX_SIZE], n;

    nhapMang(a, &n);

    printf("Mang vua nhap: ");
    xuatMang(a, n);

    printf("1. So phan tu la so nguyen to trong mang: %d\n", demSoNguyenTo(a, n));

    printf("2. ");
    xuatPhanTuToanLe(a, n);

    printf("3. Vi tri so lon nhat cuoi cung: %d\n", viTriMaxCuoiCung(a, n));

    printf("4. ");
    if (toanSoChan(a, n)) {
        printf("Mang toan so chan\n");
    }
    else {
        printf("Mang khong toan so chan\n");
    }

    printf("5. ");
    if (chanLeXenKe(a, n)) {
        printf("Mang la day so chan le xen ke\n");
    }
    else {
        printf("Mang khong phai la day so chan le xen ke\n");
    }

    return 0;
}