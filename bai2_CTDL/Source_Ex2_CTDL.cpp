#include "thuVien_Ex2_CTDL.h"


void inputCL(CL &m)
{
	cout << "Enter number of CL: ";
	cin >> m.n;
	for (int i = 0; i < m.n; i++)
	{
		cout << "Enter element [" << i << "]: ";
		cin >> m.list[i];
	}
}

void outputCL(CL m)
{
	//cout << "\nList" << endl;
	for (int i = 0; i < m.n; i++)
	{
		cout << m.list[i] << "  ";
	}
}

bool isEmpty(CL m)
{
	return m.n == 0;
}

bool isFull(CL m)
{
	return m.n >= Max;
}

int insert(CL &m, int index, int k)
{
	if (isFull(m) || index < 0 || index >= m.n)
		throw"Error";
	for (int i = m.n; i > index; i--)
		m.list[i] = m.list[i - 1];
	m.list[index] = k;
	//m.n += 1;
	m.n++;
	return 1;
}

int remove(CL &m, int index)
{
	if (isEmpty(m) || index < 0 || index >= m.n)
		throw("Error");
	for (int i = index; i < m.n; i++)
		m.list[i] = m.list[i + 1];
	m.n--;
	return 1;
}

int max(CL m)
{
	int max = 0;
	for (int i = 1; i < m.n; i++)
		if (m.list[i] > m.list[max])
			max = i;
	return max;
}
void sortDescending(CL &m)
{
	for (int i = 0; i < m.n - 1; i++)
	{
		int max = i;
		for (int j = i + 1; j < m.n; j++)
			if (m.list[j] > m.list[max])
				max = j;
		int temp = m.list[i];
		m.list[i] = m.list[max];
		m.list[max] = temp;
	}
}
//11. Kiem tra nua cuoi mang ben phai co toan so chan
bool kiemTraSoChan(CL m)
{
	for (int i = m.n / 2; i < m.n; i++)
		if (m.list[i] % 2 != 0)
			return false;
	return true;
}

//12. Dem cac vi tri doi nhau trong mang co gia tri bang nhau.
int demViTriDoiBangNhau(CL m)
{
	int count = 0;
	for (int i = 0; i < m.n / 2; i++)
		if (m.list[i] == m.list[m.n - 1 - i])
			count++;
	return count;
}

//13. Liet ke tat ca cac uoc so cua phan tu giua mang.
int lietKeUocSo(CL m)
{
	if (m.n % 2 != 0)
	{
		int giua = m.n / 2;
		//cout << "Cac uoc so cua phan tu giua mang la: ";
		for (int i = 1; i <= m.list[giua]; i++)
			if (m.list[giua] % i == 0)
				cout << i << " ";
	}
	return 1;
}

//16. Cap nhat lai gia tri x tim duoc thanh gia tri y
int capNhatGiaTri(CL &m, int x, int y)
{
	for (int i = 0; i < m.n; i++)
		if (m.list[i] == x)
			m.list[i] = y;
	return 1;
}

//17. Xoa mot gia tri tim duoc
int xoaGiaTriTimDuoc(CL &m, CL &n, int x)
{
	int count = 0;
	if (isEmpty(m))
		return 0;
	for (int i = 0; i < m.n; i++)
		if (m.list[i] == x)
		{
			n.n++;
			n.list[n.n - 1] = i;
		}
	for (int i = 0; i < n.n; i++)
	{
		for (int j = n.list[i]; j < m.n; j++)
			m.list[j] = m.list[j + 1];
		m.n--;
		count++;
		n.list[i + 1] -= count;
	}
	return 1;
}

//18. Them mot gia tri vao vi tri tim duoc
int themGiaTriTimDuoc(CL &m, CL &n, int x, int k)
{
	int count = 0;
	for (int i = 0; i < m.n; i++)
		if (m.list[i] == x)
		{
			n.n++;
			n.list[n.n - 1] = i;
		}
	for (int i = n.n; i > 0; i--)
	{
		for (int j = m.n; j > n.list[i - 1]; j--)
			m.list[j] = m.list[j - 1];
		m.list[n.list[i - 1]] = k;
		m.n++;
	}
	return 1;
}

//19. Tach mot mang thanh 2 mang
int tachMang(CL &m, CL &a, CL &b)
{
	int giua = m.n / 2;
	for (int i = 0; i < giua; i++)
	{
		++a.n;
		a.list[i] = m.list[i];
	}
	for (int i = 0; i < a.n; i++)
	{
		for (int j = 0; j < m.n; j++)
			m.list[j] = m.list[j + 1];
		m.n--;
	}
	for (int i = 0; i < m.n; i++)
	{
		++b.n;
		b.list[i] = m.list[i];
	}
	for (int i = 0; i < b.n; i++)
	{
		for (int j = 0; j < m.n; j++)
			m.list[j] = m.list[j + 1];
		m.n--;
	}
	return 1;
}

//20. Tach cac mang le rieng mang chan rieng
int tachMangChanLe(CL &m, CL &a, CL &b)
{
	for (int i = 0; i < m.n; i++)
	{
		if (m.list[i] % 2 != 0)
		{
			++a.n;
			a.list[a.n - 1] = m.list[i];
		}
		else
		{
			++b.n;
			b.list[b.n - 1] = m.list[i];
		}
	}
	for (int i = 0; i < a.n + b.n; i++)
	{
		for (int j = 0; j < m.n; j++)
			m.list[j] = m.list[j + 1];
		m.n--;
	}
	return 1;
}

// BAI TAP DANH SACH DAC
//1. Khoi tao danh sach so nguuyen rong
void init(CL &m)
{
	m.n = 0;
}

//2. Tra ve do dai cua danh sach so nguyen
int doDaiCuaDanhSach(CL x)
{
	return x.n;
}

//3. Them so nguyen a vao cuoi danh sach so nguyen x
int themAVaoX(CL &x, int a)
{
	for (int i = x.n; i > 0; i--)
	{
		x.list[i] = a;
		x.n++;
		return 1;
	}
}

//4. Xoa so a dau tien duoc tim thay trong x
int xoaADauTien(CL &x, int a)
{
	for (int i = 0; i < x.n; i++)
	{
		if (x.list[i] == a)
		{
			for (int j = i; j < x.n; j++)
				x.list[j] = x.list[j + 1];
			x.n--;
			return 1;
		}
	}
}

//5. Tach danh sach so nguyen thanh danh sach chan va le
int tachDanhSachChanLe(CL &x, CL &a, CL &b)
{
	for (int i = 0; i < x.n; i++)
	{
		if (x.list[i] % 2 != 0)
		{
			++a.n;
			a.list[a.n - 1] = x.list[i];
		}
		else
		{
			++b.n;
			b.list[b.n - 1] = x.list[i];
		}
	}
	for (int i = 0; i < a.n + b.n; i++)
	{
		for (int j = 0; j < x.n; j++)
			x.list[j] = x.list[j + 1];
		x.n--;
	}
	return 1;
}