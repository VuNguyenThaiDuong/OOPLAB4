#include <iostream>
#include <cstdlib>  // Để sử dụng rand()
#include <ctime>    // Để sử dụng time() cho việc khởi tạo seed ngẫu nhiên
#include <vector>   // Để sử dụng vector

using namespace std;

class GiaSuc {
public:
    virtual float ChoSua() = 0; // Phương thức ảo cho sữa
    virtual void PhatTiengKeu() = 0; // Phương thức ảo phát tiếng kêu
    virtual int SinhCon() = 0; // Phương thức ảo sinh con
    virtual ~GiaSuc() {} // Destructor ảo để đảm bảo hủy đúng kiểu
};

class De : public GiaSuc {
public:
    float ChoSua() override {
        return rand() % 6; // Lượng sữa cho từ 0 đến 5 lít
    }

    void PhatTiengKeu() override {
        cout << "Dee dee" << endl;
    }

    int SinhCon() override {
        return rand() % 6; // Số con sinh từ 0 đến 5
    }
};

class Cuu : public GiaSuc {
public:
    float ChoSua() override {
        return rand() % 11; // Lượng sữa cho từ 0 đến 10 lít
    }

    void PhatTiengKeu() override {
        cout << "Bee bee" << endl;
    }

    int SinhCon() override {
        return rand() % 6; // Số con sinh từ 0 đến 5
    }
};

class Bo : public GiaSuc {
public:
    float ChoSua() override {
        return rand() % 21; // Lượng sữa cho từ 0 đến 20 lít
    }

    void PhatTiengKeu() override {
        cout << "Um um" << endl;
    }

    int SinhCon() override {
        return rand() % 6; // Số con sinh từ 0 đến 5
    }
};

class ChanNuoi {
private:
    vector<Bo> DanhSachBo;
    vector<Cuu> DanhSachCuu;
    vector<De> DanhSachDe;

public:
    // Nhập số lượng gia súc
    void NhapSoLuong() {
        int soLuongBo, soLuongCuu, soLuongDe;
        cout << "Nhap so luong Bo: ";
        cin >> soLuongBo;
        cout << "Nhap so luong Cuu: ";
        cin >> soLuongCuu;
        cout << "Nhap so luong De: ";
        cin >> soLuongDe;

        // Tạo đối tượng gia súc và thêm vào danh sách
        for (int i = 0; i < soLuongBo; ++i) {
            DanhSachBo.push_back(Bo());
        }

        for (int i = 0; i < soLuongCuu; ++i) {
            DanhSachCuu.push_back(Cuu());
        }

        for (int i = 0; i < soLuongDe; ++i) {
            DanhSachDe.push_back(De());
        }
    }

    // Chức năng cho tất cả gia súc sinh con
    void SinhCon() {
        int totalBo = 0, totalCuu = 0, totalDe = 0;

        for (auto &bo : DanhSachBo) {
            totalBo += bo.SinhCon();
        }
        for (int i = 0; i < totalBo; ++i) {
            DanhSachBo.push_back(Bo());
        }

        for (auto &cuu : DanhSachCuu) {
            totalCuu += cuu.SinhCon();
        }
        for (int i = 0; i < totalCuu; ++i) {
            DanhSachCuu.push_back(Cuu());
        }

        for (auto &de : DanhSachDe) {
            totalDe += de.SinhCon();
        }
        for (int i = 0; i < totalDe; ++i) {
            DanhSachDe.push_back(De());
        }

        cout << "So con sinh ra: Bo: " << totalBo << ", Cuu: " << totalCuu << ", De: " << totalDe << endl;
    }

    // Chức năng cho tất cả gia súc cho sữa
    void ChoSua() {
        float totalSuaBo = 0, totalSuaCuu = 0, totalSuaDe = 0;

        for (auto &bo : DanhSachBo) {
            totalSuaBo += bo.ChoSua();
        }

        for (auto &cuu : DanhSachCuu) {
            totalSuaCuu += cuu.ChoSua();
        }

        for (auto &de : DanhSachDe) {
            totalSuaDe += de.ChoSua();
        }

        int totalL;
        totalL = totalSuaBo + totalSuaCuu + totalSuaDe;
        cout << "Tong so sua: Bo: " << totalSuaBo << " l, Cuu: " << totalSuaCuu << " l, De: " << totalSuaDe << " l" << endl;
        cout << "Tong so lit sua ca nong trai : "<< totalL <<"l" << endl;
    }

    // Hiển thị tiếng kêu của các gia súc khi đói
    void HomDiVang(){
        cout << "Vao mot hom bac nong dan di vang thi tieng keu trong nong trai la : "<< endl;
        if (DanhSachBo.size() != 0){
            Bo bo;
            bo.PhatTiengKeu();
        }
        if (DanhSachCuu.size() != 0){
            Cuu cuu;
            cuu.PhatTiengKeu();

        }
        if (DanhSachDe.size() != 0){
            De de;
            de.PhatTiengKeu();
        }
    }

    // Thống kê thông tin
    void ThongKe() {
        cout << "Thong tin nong trai hien tai la:" << endl;
        cout << "So luong Bo: " << DanhSachBo.size() << endl;
        cout << "So luong Cuu: " << DanhSachCuu.size() << endl;
        cout << "So luong De: " << DanhSachDe.size() << endl;
    }
};

int main() {
    srand(time(0)); // Khởi tạo seed ngẫu nhiên

    ChanNuoi chanNuoi;
    chanNuoi.NhapSoLuong(); // Nhập số lượng gia súc ban đầu

    // Hiển thị tiếng kêu của các gia súc khi đói
    chanNuoi.HomDiVang();

    int n;
    cout << "Nhap so lua sinh san : ";
    cin >> n;
    for( int i = 0; i< n; i++){
        cout <<"Day la lua thu : " << i+1 << endl;
        chanNuoi.ChoSua();
        chanNuoi.SinhCon();
        chanNuoi.ThongKe();


    }



    return 0;
}
