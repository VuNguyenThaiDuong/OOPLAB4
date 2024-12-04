#include <iostream>
#include <string>
using namespace std;

// Lớp cơ sở KhachSan
class KhachSan {
protected:
    long long soDem;        // Số đêm
    long long doanhsoPhong; // Doanh thu phòng
public:
    KhachSan() : soDem(0), doanhsoPhong(0) {}
    KhachSan(int sodem) : soDem(sodem), doanhsoPhong(0) {}
    virtual void TinhDoanhSoPhong() = 0;  // Phương thức ảo thuần để tính doanh thu
    long long layDoanhSo() {
        return doanhsoPhong;
    }
    void Nhap() {
        cout << "Nhap so dem: ";
        cin >> soDem;
    }
};

// Lớp Business kế thừa từ KhachSan
class Business : public KhachSan {
public:
    Business(int sodem) : KhachSan(sodem) {}
    void TinhDoanhSoPhong() override {
        doanhsoPhong = soDem * 300000;  // Doanh thu Business = Số đêm * 300000
    }
};

// Lớp Premium kế thừa từ Business
class Premium : public Business {
public:
    Premium(int sodem) : Business(sodem) {}
    void TinhDoanhSoPhong() override {
        long long phidichVu;
        cout << "Nhap phi dich vu cho phong Premium: ";
        cin >> phidichVu;
        doanhsoPhong = soDem * 500000 + phidichVu;  // Doanh thu Premium = Số đêm * 500000 + Phí dịch vụ
    }
};

// Lớp Deluxe kế thừa từ Premium
class Deluxe : public Premium {
public:
    Deluxe(int sodem) : Premium(sodem) {}
    void TinhDoanhSoPhong() override {
        long long phidichVu, phiphucVu;
        cout << "Nhap phi dich vu cho phong Deluxe: ";
        cin >> phidichVu;
        cout << "Nhap phi phuc vu cho phong Deluxe: ";
        cin >> phiphucVu;
        doanhsoPhong = soDem * 750000 + phidichVu + phiphucVu;  // Doanh thu Deluxe = Số đêm * 750000 + Phí dịch vụ + Phí phục vụ
    }
};

int main() {
    // Khởi tạo các phòng
    Deluxe a(3);    // Phòng Deluxe a, 3 đêm
    Deluxe b(5);    // Phòng Deluxe b, 5 đêm
    Premium c(4);   // Phòng Premium c, 4 đêm
    Premium d(2);   // Phòng Premium d, 2 đêm
    Business e(6);  // Phòng Business e, 6 đêm

    // Nhập và tính doanh thu cho từng phòng
    cout << "Nhap phong a (Deluxe): " << endl;
    a.Nhap();
    a.TinhDoanhSoPhong();

    cout << "Nhap phong b (Deluxe): " << endl;
    b.Nhap();
    b.TinhDoanhSoPhong();

    cout << "Nhap phong c (Premium): " << endl;
    c.Nhap();
    c.TinhDoanhSoPhong();

    cout << "Nhap phong d (Premium): " << endl;
    d.Nhap();
    d.TinhDoanhSoPhong();

    cout << "Nhap phong e (Business): " << endl;
    e.Nhap();
    e.TinhDoanhSoPhong();

    // So sánh doanh thu các phòng và tìm ra phòng có doanh thu cao nhất
    long long doanhThuMax = a.layDoanhSo();
    string loaiPhongMax = "Deluxe a";

    if (b.layDoanhSo() > doanhThuMax) {
        doanhThuMax = b.layDoanhSo();
        loaiPhongMax = "Deluxe b";
    }
    if (c.layDoanhSo() > doanhThuMax) {
        doanhThuMax = c.layDoanhSo();
        loaiPhongMax = "Premium c";
    }
    if (d.layDoanhSo() > doanhThuMax) {
        doanhThuMax = d.layDoanhSo();
        loaiPhongMax = "Premium d";
    }
    if (e.layDoanhSo() > doanhThuMax) {
        doanhThuMax = e.layDoanhSo();
        loaiPhongMax = "Business e";
    }

    // In kết quả
    cout << "Loai phong co doanh thu cao nhat la: " << loaiPhongMax << " voi doanh thu: " << doanhThuMax << endl;

    return 0;
}


