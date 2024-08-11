#include <iostream>
#include <cmath>


using namespace std;

//Bai 2_Trang 28
int power(int m, int n) {
    int result = 1;
    for (int i = 0; i < n; i++) {
        result *= m;
    }
    return result;
}

//Bai 3 trang 28
int UCLN(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    return a; // or return b, since a == b at this point
}

//Bai 4 trang 28
int CapSoCongN(int a, int r, int n) {
    if (n == 1) {
        return a;
    }
    else {
        return CapSoCongN(a, r, n - 1) + r;
    }
}

//Bai 5 trang 28
double CapSoNhanN(double a, double q, int n) {
    return a * pow(q, n - 1);
}

//Bai 6 trang 28
int U(int n) {

    if (n < 6) {
        return n;
    }
    else {

        return U(n - 5) + U(n - 4) + U(n - 3) + U(n - 2) + U(n - 1);
    }
}

//Bai 8 trang 28
int f(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n % 2 == 0) { // n là số chẵn
        return 2 * f(n / 2);
    }
    else { //  n là số lẻ
        return 2 * f(n / 2) + 3 * f(n / 2 + 1);
    }
}
int main() {

    int chon = -1;
    while (chon != 0) {
        cout << "2. Viet ham tinh m^n";
        cout << "\n3. Viet ham tim UCLN:";
        cout << "\n4. Tim gia tri phan tu thu n cua cap so cong";
        cout << "\n5. Tim gia tri phan tu thu n cua cap so nhan";
        cout << "\n6. Tinh gia tri bieu thuc U(n)";
        cout << "\n8. ";
        cout << "\nChon bai tap: ";
        cin >> chon;
        switch (chon) {
        case 1:
            break;

        case 2: {
            cout << "2. Viet ham tinh m^n\n";
            int m, n;
            cout << " m: ";
            cin >> m;
            cout << " n: ";
            cin >> n;

            if (n < 0) {
                cout << "n phai la so nguyen duong!" << endl;
            }
            else {
                int result = power(m, n);
                cout << m << " ^ " << n << " = " << result << endl;

            }
            break;
        }case 3: {
            cout << "\n3. Viet ham tim UCLN:\n";
            int a, b;
            cout << " a: ";
            cin >> a;
            cout << " b: ";
            cin >> b;

            if (a <= 0 || b <= 0) {
                cout << "a va b phai la so nguyen duong!" << endl;
            }
            else {
                int gcd = UCLN(a, b);
                cout << "UCLN " << a << " va " << b << " la: " << gcd << endl;
            }
            break;
        }case 4: {
            cout << "\n4. Tim gia tri phan tu thu n cua cap so cong\n";
            int r, a, n;
            cout << "Nhap a: ";
            cin >> a;
            cout << "Nhap r: ";
            cin >> r;
            cout << "Nhap n: ";
            cin >> n;

            if (n <= 0) {
                cout << "n phai la so nguyen duong!" << endl;
            }
            else {
                int result = CapSoCongN(a, r, n);
                cout << "Gia tri phan tu thu " << n << " la: " << result << endl;
            }
            break;

        }case 5: {

            double  q;
            int n, a;
            cout << "\n5. Tim gia tri phan tu thu n cua cap so nhan\n";

            cout << "Nhap gia tri cua hang dau (a): ";
            cin >> a;

            cout << "Nhap gia tri cua cong boi (q): ";
            cin >> q;

            cout << "Nhap vi tri phan tu can tim (n): ";
            cin >> n;


            double ketQua = CapSoNhanN(a, q, n);
            cout << "Gia tri phan tu thu " << n << " cua cap so nhan la: " << ketQua << endl;
            break;

        }case 6: {
            cout << "\n6. Tinh gia tri bieu thuc U(n)";
            int n;
            cout << "Nhap vao gia tri n: ";
            cin >> n;

            int kq = U(n);
            cout << "U(" << n << ") = " << kq << endl;
            break;

        }case 7: {
            break;

        }case 8: {
            cout << "8. \n";
            int n;
            cout << "Nhap vao gia tri n: ";
            cin >> n;

            int ket_qua = f(n);
            cout << "f(" << n << ") = " << ket_qua << endl;

            break;
        }
        }

    }


    return 0;
}
