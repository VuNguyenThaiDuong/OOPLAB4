#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class NhanVien {
protected:
    string masoNV;
    string tenNV;
    long long luongCoBan;

public:
    NhanVien() : masoNV(""), tenNV(""), luongCoBan(0) {}
    NhanVien(string MSNV, string Ten, int Luong) : masoNV(MSNV), tenNV(Ten), luongCoBan(Luong) {}
    void Nhap();
    void Xuat();
};



class KySu:public NhanVien{
private:
    float sogioLamThem;
public:
    double TienThuong();
    void Xuat();

};

class QuanLy:public NhanVien{
private:
    float tyleTienThuong;
public:
    double TienThuong();
    void Xuat();

};


// Ham nhap cua Nhan Vien
void NhanVien::Nhap() {
    cout << "Nhap Ma So Nhan Vien: ";
    cin >> masoNV; // Assigning input to masoNV
    cout << "Nhap Ho Ten Nhan Vien: ";
    cin.ignore();  // To clear the input buffer before reading a string with spaces
    getline(cin, tenNV); // Reading the full name (including spaces)
    cout << "Nhap Luong Co Ban Nhan Vien: ";
    cin >> luongCoBan; // Assigning input to luongCoBan
}


// Ham xuat cua nhan vien
void NhanVien::Xuat() {
    cout << "Ma So NV: " << masoNV << ", Ho Ten: " << tenNV << ", Luong Co Ban: " << luongCoBan << endl;
}

// Ham tien thuong cua quan ly
double QuanLy::TienThuong(){
    long long tienthuong;
    cout << "Nhap ti le tien thuong : ";
    cin >> tyleTienThuong;
    tienthuong = (tyleTienThuong / 100)*luongCoBan;
    return tienthuong;
}

// Ham xuat cua quan
void QuanLy::Xuat(){
    cout << "Ma So NV: " << masoNV << ", Ho Ten: " << tenNV << ", Luong Co Ban: " << luongCoBan << " Tien thuong: " << fixed << setprecision(0) << TienThuong()<<endl;
}


// Ham tien thuong cua ki su
double KySu::TienThuong(){
    long long tienthuong;
    cout << "Nhap so gio lam them : ";
    cin >> sogioLamThem;
    tienthuong =  sogioLamThem*100000 ;
    return tienthuong;
}

// Ham xuat cua ky su
void KySu::Xuat(){
    cout << "Ma So NV: " << masoNV << ", Ho Ten: " << tenNV << ", Luong Co Ban: " << luongCoBan << " Tien thuong: " << fixed << setprecision(0) << TienThuong()<<endl;
}

// Ham main chinh
int main() {
    KySu a;
    QuanLy b;

    cout << "Nhap thong tin cua Quan Ly" << endl;
    a.Nhap();
    a.Xuat();

    cout << "Nhap thong tin cua Ky Su" << endl;
    b.Nhap();
    b.Xuat();
    return 0;
}



