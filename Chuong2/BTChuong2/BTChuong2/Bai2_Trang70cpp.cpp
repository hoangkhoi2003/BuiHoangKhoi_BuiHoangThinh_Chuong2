#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

struct SinhVien {
    int stt;
    char mssv[20];
    char hoTen[MAX_NAME_LENGTH];
    float diemTieuLuan;
    float diemThiKetThuc;
    float diemTongKet;
    float diemHe4;
    char xepLoai[3];
};

void nhapSinhVien(struct SinhVien* sv, int stt) {
    sv->stt = stt;
    printf("Nhap MSSV: ");
    scanf("%s", sv->mssv);
    printf("Nhap ho ten: ");
    getchar(); 
    fgets(sv->hoTen, MAX_NAME_LENGTH, stdin);
    sv->hoTen[strcspn(sv->hoTen, "\n")] = 0; 
    printf("Nhap diem tieu luan: ");
    scanf("%f", &sv->diemTieuLuan);
    printf("Nhap diem thi ket thuc: ");
    scanf("%f", &sv->diemThiKetThuc);
}

void tinhDiemTongKet(struct SinhVien* sv) {
    sv->diemTongKet = 0.3 * sv->diemTieuLuan + 0.7 * sv->diemThiKetThuc;
}

void quiDoiDiem(struct SinhVien* sv) {
    if (sv->diemTongKet >= 8.5) {
        sv->diemHe4 = 4.0;
        strcpy(sv->xepLoai, "A");
    }
    else if (sv->diemTongKet >= 7.0) {
        sv->diemHe4 = 3.0;
        strcpy(sv->xepLoai, "B");
    }
    else if (sv->diemTongKet >= 5.5) {
        sv->diemHe4 = 2.0;
        strcpy(sv->xepLoai, "C");
    }
    else if (sv->diemTongKet >= 4.0) {
        sv->diemHe4 = 1.0;
        strcpy(sv->xepLoai, "D");
    }
    else {
        sv->diemHe4 = 0.0;
        strcpy(sv->xepLoai, "F");
    }
}

void xuatSinhVien(struct SinhVien sv) {
    printf("%-5d %-10s %-30s %-10.2f %-10.2f %-10.2f %-10.2f %s\n",
        sv.stt, sv.mssv, sv.hoTen, sv.diemTieuLuan, sv.diemThiKetThuc,
        sv.diemTongKet, sv.diemHe4, sv.xepLoai);
}

void nhapDanhSach(struct SinhVien dsSV[], int* n) {
    printf("Nhap so luong sinh vien: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        nhapSinhVien(&dsSV[i], i + 1);
        tinhDiemTongKet(&dsSV[i]);
        quiDoiDiem(&dsSV[i]);
    }
}

void xuatDanhSach(struct SinhVien dsSV[], int n) {
    printf("%-5s %-10s %-30s %-10s %-10s %-10s %-10s %s\n",
        "STT", "MSSV", "Ho Ten", "Tieu Luan", "Thi", "Tong Ket", "He 4", "Xep Loai");
    for (int i = 0; i < n; i++) {
        xuatSinhVien(dsSV[i]);
    }
}

void timDiemCaoThapNhat(struct SinhVien dsSV[], int n) {
    int maxIndex = 0, minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (dsSV[i].diemTongKet > dsSV[maxIndex].diemTongKet) maxIndex = i;
        if (dsSV[i].diemTongKet < dsSV[minIndex].diemTongKet) minIndex = i;
    }
    printf("Sinh vien co diem cao nhat:\n");
    xuatSinhVien(dsSV[maxIndex]);
    printf("Sinh vien co diem thap nhat:\n");
    xuatSinhVien(dsSV[minIndex]);
}

void demSinhVienDatKhongDat(struct SinhVien dsSV[], int n) {
    int dat = 0, khongDat = 0;
    for (int i = 0; i < n; i++) {
        if (dsSV[i].diemTongKet >= 4.0) dat++;
        else khongDat++;
    }
    printf("So sinh vien dat: %d\n", dat);
    printf("So sinh vien khong dat: %d\n", khongDat);
}

void sapXepTheoTongKet(struct SinhVien dsSV[], int n, int tangDan) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((tangDan && dsSV[j].diemTongKet > dsSV[j + 1].diemTongKet) ||
                (!tangDan && dsSV[j].diemTongKet < dsSV[j + 1].diemTongKet)) {
                struct SinhVien temp = dsSV[j];
                dsSV[j] = dsSV[j + 1];
                dsSV[j + 1] = temp;
            }
        }
    }
}

float tinhDiemTrungBinh(struct SinhVien dsSV[], int n) {
    float tong = 0;
    for (int i = 0; i < n; i++) {
        tong += dsSV[i].diemTongKet;
    }
    return tong / n;
}

void luuFile(struct SinhVien dsSV[], int n, const char* tenFile) {
    FILE* f = fopen(tenFile, "w");
    if (f == NULL) {
        printf("Khong the mo file de ghi.\n");
        return;
    }
    fprintf(f, "%-5s %-10s %-30s %-10s %-10s %-10s %-10s %s\n",
        "STT", "MSSV", "Ho Ten", "Tieu Luan", "Thi", "Tong Ket", "He 4", "Xep Loai");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%-5d %-10s %-30s %-10.2f %-10.2f %-10.2f %-10.2f %s\n",
            dsSV[i].stt, dsSV[i].mssv, dsSV[i].hoTen, dsSV[i].diemTieuLuan,
            dsSV[i].diemThiKetThuc, dsSV[i].diemTongKet, dsSV[i].diemHe4, dsSV[i].xepLoai);
    }
    fclose(f);
    printf("Da luu thong tin vao file %s\n", tenFile);
}

void docFile(struct SinhVien dsSV[], int* n, const char* tenFile) {
    FILE* f = fopen(tenFile, "r");
    if (f == NULL) {
        printf("Khong the mo file de doc.\n");
        return;
    }
    char line[200];
    fgets(line, sizeof(line), f); 
    *n = 0;
    while (fscanf(f, "%d %s %[^0-9] %f %f %f %f %s\n",
        &dsSV[*n].stt, dsSV[*n].mssv, dsSV[*n].hoTen,
        &dsSV[*n].diemTieuLuan, &dsSV[*n].diemThiKetThuc,
        &dsSV[*n].diemTongKet, &dsSV[*n].diemHe4, dsSV[*n].xepLoai) == 8) {
        (*n)++;
    }
    fclose(f);
    printf("Da doc thong tin tu file %s\n", tenFile);
}

int main() {
    struct SinhVien dsSV[MAX_STUDENTS];
    int n, choice;

    do {
        printf("\nMENU:\n");
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. Xuat danh sach sinh vien\n");
        printf("3. Tim sinh vien diem cao nhat va thap nhat\n");
        printf("4. Dem so sinh vien dat va khong dat\n");
        printf("5. Sap xep danh sach theo diem tong ket\n");
        printf("6. Tinh diem trung binh cua tat ca sinh vien\n");
        printf("7. Luu danh sach vao file\n");
        printf("8. Doc danh sach tu file\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            nhapDanhSach(dsSV, &n);
            break;
        case 2:
            xuatDanhSach(dsSV, n);
            break;
        case 3:
            timDiemCaoThapNhat(dsSV, n);
            break;
        case 4:
            demSinhVienDatKhongDat(dsSV, n);
            break;
        case 5:
        {
            int tangDan;
            printf("Sap xep tang dan (1) hay giam dan (0)? ");
            scanf("%d", &tangDan);
            sapXepTheoTongKet(dsSV, n, tangDan);
            printf("Da sap xep danh sach.\n");
        }
        break;
        case 6:
            printf("Diem trung binh cua tat ca sinh vien: %.2f\n", tinhDiemTrungBinh(dsSV, n));
            break;
        case 7:
            luuFile(dsSV, n, "danhsachsinhvien.txt");
            break;
        case 8:
            docFile(dsSV, &n, "danhsachsinhvien.txt");
            break;
        case 0:
            printf("Tam biet!\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}