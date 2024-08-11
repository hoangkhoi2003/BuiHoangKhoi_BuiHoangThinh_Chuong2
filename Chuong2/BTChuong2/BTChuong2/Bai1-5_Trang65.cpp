//Bai 1-5 trang 65
#include <iostream>
#include <cstdlib> // abs

using namespace std;

// Khai báo cấu trúc PhanSo
struct PhanSo {
	int tuSo;
	int mauSo;
};

// Hàm tự định nghĩa tính GCD
int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return abs(a);
}

// Hàm nhập phân số
void nhapPhanSo(PhanSo& ps) {
	cout << "Nhap tu so: ";
	cin >> ps.tuSo;
	do {
		cout << "Nhap mau so: ";
		cin >> ps.mauSo;
		if (ps.mauSo == 0) {
			cout << "Mau so khong the bang 0. Vui long thu lai!!" << endl;
		}
	} while (ps.mauSo == 0);
}

// Hàm xuất phân số
void xuatPhanSo(const PhanSo& ps) {
	cout << ps.tuSo << "/" << ps.mauSo;
}

// Hàm tối giản phân số
void toiGianPhanSo(PhanSo& ps) {
	int gcdValue = gcd(abs(ps.tuSo), abs(ps.mauSo));
	ps.tuSo /= gcdValue;
	ps.mauSo /= gcdValue;
	// Đảm bảo mẫu số dương
	if (ps.mauSo < 0) {
		ps.tuSo = -ps.tuSo;
		ps.mauSo = -ps.mauSo;
	}
}

// Hàm cộng hai phân số
PhanSo tongPhanSo(const PhanSo& ps1, const PhanSo& ps2) {
	PhanSo kq;
	kq.tuSo = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
	kq.mauSo = ps1.mauSo * ps2.mauSo;
	toiGianPhanSo(kq);
	return kq;
}

// Hàm trừ hai phân số
PhanSo hieuPhanSo(const PhanSo& ps1, const PhanSo& ps2) {
	PhanSo kq;
	kq.tuSo = ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;
	kq.mauSo = ps1.mauSo * ps2.mauSo;
	toiGianPhanSo(kq);
	return kq;
}

// Hàm nhân hai phân số
PhanSo tichPhanSo(const PhanSo& ps1, const PhanSo& ps2) {
	PhanSo kq;
	kq.tuSo = ps1.tuSo * ps2.tuSo;
	kq.mauSo = ps1.mauSo * ps2.mauSo;
	toiGianPhanSo(kq);
	return kq;
}

// Hàm chia hai phân số
PhanSo thuongPhanSo(const PhanSo& ps1, const PhanSo& ps2) {
	PhanSo kq;
	kq.tuSo = ps1.tuSo * ps2.mauSo;
	kq.mauSo = ps1.mauSo * ps2.tuSo;
	toiGianPhanSo(kq);
	return kq;
}

int main() {
	PhanSo ps1, ps2;

	cout << "Nhap phan so thu nhat" << endl;
	nhapPhanSo(ps1);
	cout << "Nhap phan so thu hai " << endl;
	nhapPhanSo(ps2);

	cout << "Phan so thu nhat: ";
	xuatPhanSo(ps1);
	cout << "\nPhan so thu hai: ";
	xuatPhanSo(ps2);
	cout << endl;

	PhanSo tong = tongPhanSo(ps1, ps2);
	cout << "Tong: ";
	xuatPhanSo(tong);
	cout << endl;

	PhanSo hieu = hieuPhanSo(ps1, ps2);
	cout << "Hieu: ";
	xuatPhanSo(hieu);
	cout << endl;

	PhanSo tich = tichPhanSo(ps1, ps2);
	cout << "Tich: ";
	xuatPhanSo(tich);
	cout << endl;

	PhanSo thuong = thuongPhanSo(ps1, ps2);
	cout << "Thuong: ";
	xuatPhanSo(thuong);
	cout << endl;

	return 0;
}