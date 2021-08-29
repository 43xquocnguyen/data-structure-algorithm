#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct DoVat
{
    float trongLuong;
    float giaTri;
    float donGia;
    int soLuongDuocChon;
    string tenDoVat;
};

void DocFile(DoVat *&dsDoVat, int &n, float &trongLuongBalo) {
    ifstream fileIn(".greedy.txt", ios_base::in);
    if (fileIn.fail()) {
        return;
    }
    string temp;
    getline(fileIn, temp);
    getline(fileIn, temp, ':');
    fileIn >> trongLuongBalo;
    getline(fileIn, temp, ':');
    fileIn >> n;
    getline(fileIn, temp);
    dsDoVat = new DoVat[n];
    getline(fileIn, temp);

    int a;

    for (int i = 0; i < n; i++)
    {
        fileIn >> dsDoVat[i].trongLuong;
        getline(fileIn, temp, '|');
        fileIn >> dsDoVat[i].giaTri;
        getline(fileIn, temp, '|');
        getline(fileIn, dsDoVat[i].tenDoVat);
        dsDoVat[i].donGia = dsDoVat[i].giaTri / dsDoVat[i].trongLuong;
        dsDoVat[i].soLuongDuocChon = 0;
    }
    fileIn.close();
}
void SortDonGia(DoVat *&dsDoVat, int n) {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (dsDoVat[i].donGia < dsDoVat[j].donGia) {
                swap(dsDoVat[i], dsDoVat[j]);
            }
        }
        
    }
}
void InDanhSach(DoVat *dsDoVat, int n) {
    cout << "TL" << "\t"<< "GT" << "\t" << " T" << "\t\t"<< "DG" << "\t" << "SLDC" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << dsDoVat[i].trongLuong << "\t"
             << dsDoVat[i].giaTri << "\t" 
             << dsDoVat[i].tenDoVat << "\t"
             << dsDoVat[i].donGia << "\t" 
             << dsDoVat[i].soLuongDuocChon << endl;
    }
}

void Greedy(DoVat *dsDoVat, int n, int trongLuongBaLo) {
    for (int i = 0; i < n; i++)
    {
        if (trongLuongBaLo <= 0)
            break;
        int soLuong = (trongLuongBaLo / dsDoVat[i].trongLuong);
        trongLuongBaLo -= soLuong * dsDoVat[i].trongLuong;
        dsDoVat[i].soLuongDuocChon += soLuong;
    }
}

int main() {
    DoVat *dsDoVat;
    float trongLuongBalo;
    int n = -1;

    // Đọc file vào và sort theo đơn giá
    DocFile(dsDoVat, n, trongLuongBalo);
    SortDonGia(dsDoVat, n);

    // Greedy
    Greedy(dsDoVat, n, trongLuongBalo);
    InDanhSach(dsDoVat, n);

    return 0;
}