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

// Hàm tìm max
int timMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

// Hàm tìm min
int timMin(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

// Hàm đếm số phần tử chẵn
int demChan(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

// Hàm đếm số phần tử lẻ
int demLe(int a[], int n) {
    return n - demChan(a, n);
}

// Hàm tìm kiếm tuyến tính
int timKiemTuyenTinh(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

// Hàm tìm kiếm nhị phân (mảng phải được sắp xếp tăng dần)
int timKiemNhiPhan(int a[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return mid;
        }
        if (a[mid] > x) {
            return timKiemNhiPhan(a, left, mid - 1, x);
        }
        return timKiemNhiPhan(a, mid + 1, right, x);
    }
    return -1;
}

// Hàm đếm số lần xuất hiện của x trong mảng
int demPhanTu(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            count++;
        }
    }
    return count;
}

// Hàm đếm số phần tử lớn hơn x
int demLonHonX(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            count++;
        }
    }
    return count;
}

// Hàm tính tổng các phần tử
int tinhTong(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

// Hàm kiểm tra số nguyên tố
int laSoNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Hàm xuất các số nguyên tố
void xuatSoNguyenTo(int a[], int n) {
    printf("Cac so nguyen to trong mang: ");
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// Hàm kiểm tra số hoàn thiện
int laSoHoanThien(int n) {
    int sum = 1;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return (sum == n && n != 1);
}

// Hàm xuất các số hoàn thiện
void xuatSoHoanThien(int a[], int n) {
    printf("Cac so hoan thien trong mang: ");
    for (int i = 0; i < n; i++) {
        if (laSoHoanThien(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// Hàm xuất các phần tử ở vị trí chẵn
void xuatViTriChan(int a[], int n) {
    printf("Cac phan tu o vi tri chan: ");
    for (int i = 0; i < n; i += 2) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Hàm xuất các phần tử ở vị trí lẻ
void xuatViTriLe(int a[], int n) {
    printf("Cac phan tu o vi tri le: ");
    for (int i = 1; i < n; i += 2) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Hàm xuất giá trị max và vị trí
void xuatMaxVaViTri(int a[], int n) {
    int max = timMax(a, n);
    printf("Gia tri max = %d, vi tri: ", max);
    for (int i = 0; i < n; i++) {
        if (a[i] == max) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Hàm xuất giá trị min và vị trí
void xuatMinVaViTri(int a[], int n) {
    int min = timMin(a, n);
    printf("Gia tri min = %d, vi tri: ", min);
    for (int i = 0; i < n; i++) {
        if (a[i] == min) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Hàm ghép hai mảng tăng dần
void ghepMangTangDan(int a[], int b[], int c[], int m, int n) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (b[i] <= c[j]) {
            a[k++] = b[i++];
        }
        else {
            a[k++] = c[j++];
        }
    }
    while (i < m) {
        a[k++] = b[i++];
    }
    while (j < n) {
        a[k++] = c[j++];
    }
}

int main() {
    int a[MAX_SIZE], n, x;
    nhapMang(a, &n);

    printf("Mang vua nhap: ");
    xuatMang(a, n);

    printf("Max = %d\n", timMax(a, n));
    printf("Min = %d\n", timMin(a, n));

    printf("So phan tu chan: %d\n", demChan(a, n));
    printf("So phan tu le: %d\n", demLe(a, n));

    printf("Nhap x can tim: ");
    scanf("%d", &x);

    int viTri = timKiemTuyenTinh(a, n, x);
    if (viTri != -1) {
        printf("Tim thay %d tai vi tri %d\n", x, viTri);
    }
    else {
        printf("Khong tim thay %d trong mang\n", x);
    }

    printf("So lan xuat hien cua %d: %d\n", x, demPhanTu(a, n, x));
    printf("So phan tu lon hon %d: %d\n", x, demLonHonX(a, n, x));

    printf("Tong cac phan tu: %d\n", tinhTong(a, n));

    xuatSoNguyenTo(a, n);
    xuatSoHoanThien(a, n);

    xuatViTriChan(a, n);
    xuatViTriLe(a, n);

    xuatMaxVaViTri(a, n);
    xuatMinVaViTri(a, n);

    // Ghép hai mảng tăng dần
    int b[MAX_SIZE], c[MAX_SIZE], m;
    printf("Nhap mang b (tang dan):\n");
    nhapMang(b, &m);
    printf("Nhap mang c (tang dan):\n");
    nhapMang(c, &n);

    ghepMangTangDan(a, b, c, m, n);
    printf("Mang a sau khi ghep b va c: ");
    xuatMang(a, m + n);

    return 0;
}