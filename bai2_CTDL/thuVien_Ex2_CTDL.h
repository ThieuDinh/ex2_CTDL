#include <iostream>
using namespace std;

const int Max = 100;
struct contiguousList
{
	int n;
	int list[Max];
};
typedef contiguousList CL;

void inputCL(CL &m);
void outputCL(CL m);
void init(CL &m);
bool isEmpty(CL m);
int insert(CL &m, int index, int k);
int remove(CL &m, int index);
int max(CL m);
void sortDescending(CL &m);
bool kiemTraSoChan(CL m);
int demViTriDoiBangNhau(CL m);
int lietKeUocSo(CL m);
int capNhatGiaTri(CL &m, int x, int y);
int xoaGiaTriTimDuoc(CL &m, CL &n, int x);
int themGiaTriTimDuoc(CL &m, CL &n, int x,int k);
int tachMang(CL &m, CL &a, CL &b);
int tachMangChanLe(CL &m, CL &a, CL &b);

void init(CL &m);
int doDaiCuaDanhSach(CL x);
int themAVaoX(CL &x, int a);
int xoaADauTien(CL &x, int a);
int tachDanhSachChanLe(CL &x, CL &a, CL &b);