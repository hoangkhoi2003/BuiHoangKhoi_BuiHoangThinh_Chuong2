#include <iostream>
#include <string>

using namespace std;

// Hàm cắt chuỗi họ tên thành chuỗi họ lót và chuỗi tên
void splitName(const string& fullName, string& middleName, string& lastName) {
    size_t lastSpace = fullName.find_last_of(' ');

    // Nếu không tìm thấy khoảng trắng, tức là chỉ có tên
    if (lastSpace == string::npos) {
        middleName = "";
        lastName = fullName;
    }
    else {
        middleName = fullName.substr(0, lastSpace);
        lastName = fullName.substr(lastSpace + 1);
    }

    // Xóa khoảng trắng trong chuỗi họ lót
    middleName.erase(remove(middleName.begin(), middleName.end(), ' '), middleName.end());
}

int main() {
    string fullName = "Nguyen Van A";
    string middleName, lastName;

    // Cắt chuỗi họ tên
    splitName(fullName, middleName, lastName);

    // In kết quả
    cout << "Chuoi ho lot: " << middleName << endl;
    cout << "Chuoi ten: " << lastName << endl;

    return 0;
}
