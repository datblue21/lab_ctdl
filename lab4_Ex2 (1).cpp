#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;
 
struct SinhVien {
    char id[12];
    char ten[30];
    float diemToan;
    float diemLy;
    float diemTB ;
};
 
typedef SinhVien SV;
 
void printLine(int n);
void nhapThongTinSV(SV &sv);
void nhapSV(SV a[], int n);
void timKiemTheoID(SV a[], char ten[], int n);
void tinhDTB(SV &sv);
void sapxepTheoDTB(SV a[], int n);
void showStudent(SV a[], int n);
void pressAnyKey();
 
int main() {
    int key;
    SV arraySV[MAX];
    int soluongSV = 0;
    int idCount = 0;
     
 
    while(true) {
        cout << "CHUONG TRINH QUAN LY SINH VIEN C/C++\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Them sinh vien.                               **\n";
        cout << "**  2. Tim kiem sinh vien theo ten.                  **\n";
        cout << "**  3. Sap xep sinh vien theo diem trung binh (GPA). **\n";
        cout << "**  4. Hien thi danh sach sinh vien.                 **\n";
        cout << "**  0. Thoat                                         **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch(key){
            case 1:
                cout << "\n1. Them sinh vien.";
                idCount++;
                nhapSV(arraySV, soluongSV);
                printf("\nThem sinh vien thanh cong!");
                soluongSV++;
                pressAnyKey();
                break;
        
            case 2:
                if(soluongSV > 0) {
                    cout << "\n4. Tim kiem sinh vien theo id.";
                    char strID[30];
                    cout << "\nNhap id de tim kiem: "; fflush(stdin); gets(strID);
                    timKiemTheoID(arraySV, strID, soluongSV);
                }else{
                    cout << "\nSanh sach sinh vien trong!";
                }
                pressAnyKey();
                break;
            case 3:
                if(soluongSV > 0) {
                    cout << "\n5. Sap xep sinh vien theo diem trung binh (GPA).";
                    sapxepTheoDTB(arraySV, soluongSV);
                    showStudent(arraySV, soluongSV);
                }else{
                    cout << "\nSanh sach sinh vien trong!";
                }
                pressAnyKey();
                break;
            case 4:
                if(soluongSV > 0){
                    cout << "\n7. Hien thi danh sach sinh vien.";
                    showStudent(arraySV, soluongSV);
                }else{
                    cout << "\nSanh sach sinh vien trong!";
                }
                pressAnyKey();
                break;
            case 0:
                cout << "\nBan da chon thoat chuong trinh!";
                getch();
                return 0;
            default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                pressAnyKey();
                break;
        }
    }
}
  
void tinhDTB(SV &sv) {
    sv.diemTB = (sv.diemToan + sv.diemLy) / 2;    
}
 
  
void nhapThongTinSV(SV &sv) {
	cout << "\n Nhap ID: "; fflush(stdin); gets(sv.id);
    cout << "\n Nhap ten: "; fflush(stdin); gets(sv.ten);
    cout << " Nhap diem Toan: "; cin >> sv.diemToan;
    cout << " Nhap diem Ly: "; cin >> sv.diemLy;
    tinhDTB(sv);
}
 
void nhapSV(SV a[], int n) {
    printLine(40);
    printf("\n Nhap sinh vien thu %d:", n + 1);
    nhapThongTinSV(a[n]);
    printLine(40);
}
 
void timKiemTheoID(SV a[], char id[], int n) {
    SV arrayFound[MAX];
    char IDSV[30];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(IDSV, a[i].id);
        if(strstr(strupr(IDSV), strupr(id))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    showStudent(arrayFound, found);
}
 
void showStudent(SV a[], int n) {
    printLine(100);
    cout <<"\nSTT\tID\tHo va ten\tGioi tinh\tTuoi\tToan\tLy\tDiem TB\tHoc luc";
    for(int i = 0; i < n; i++) {
        // in sinh vien thu i ra man hinh
        printf("\n %d", i + 1);
        printf("\t%d", a[i].id);
        printf("\t%s", a[i].ten);
        printf("\t%.2f\t%.2f\t%.2f", a[i].diemToan, a[i].diemLy);
        printf("\t%.2f", a[i].diemTB);
    }
    printLine(100);
}
  
void sapxepTheoDTB(SV a[], int n) {
    //Sap xep theo DTB tang dan
    SV tmp;
    for(int i = 0;i < n;i++) {
        for(int j = i+1; j < n;j++) {
            if(a[i].diemTB > a[j].diemTB) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
 
 
void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}
 
void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}
