#include <stdio.h>

// Khai bao kieu PHANSO
typedef struct
{
	int tu;
	int mau;
} PHANSO;

// Nguyen mau ham
PHANSO ChuanHoa(PHANSO ps);
void Nhap(PHANSO &ps);
void Xuat(PHANSO ps, char thongbao[]);
int TimUSCLN(int x, int y);
PHANSO RutGon(PHANSO ps);
void QuyDong(PHANSO &ps1, PHANSO &ps2);
PHANSO Tong(PHANSO ps1, PHANSO ps2);
PHANSO Hieu(PHANSO ps1, PHANSO ps2);
PHANSO Tich(PHANSO ps1, PHANSO ps2);
PHANSO Thuong(PHANSO ps1, PHANSO ps2);
int KiemTraToiGian(PHANSO ps);
int KiemTraAmDuong(PHANSO ps);
int SoSanh(PHANSO ps1, PHANSO ps2);

// Mang phan so
void NhapMang(PHANSO a[], int &n);
void XuatMang(PHANSO a[], int n, char *thongbao);
void RutGonMang(PHANSO a[], int n);
int TimViTriPhanSoDuongDauTien(PHANSO a[], int n);
PHANSO TimPhanSoMin(PHANSO a[], int n);
void SapXepTang(PHANSO a[], int n);


void main()
{
	/*PHANSO ps1, ps2;
	
	Nhap(ps1);
	Xuat(ps1, "Phan so 1: ");
	
	Nhap(ps2);
	Xuat(ps2, "Phan so 2: ");
	
	ps1 = RutGon(ps1);
	Xuat(ps1, "Phan so 1 (rut gon): ");
	ps2 = RutGon(ps2);
	Xuat(ps2, "Phan so 2 (rut gon): ");
	
	QuyDong(ps1, ps2);
	Xuat(ps1, "Phan so 1 (quy dong): ");
	Xuat(ps2, "Phan so 2 (quy dong): ");
	
	Xuat(Tong(ps1, ps2), "Phan so 1 + Phan so 2 = ");
	Xuat(Hieu(ps1, ps2), "Phan so 1 - Phan so 2 = ");
	Xuat(Tich(ps1, ps2), "Phan so 1 * Phan so 2 = ");
	Xuat(Thuong(ps1, ps2), "Phan so 1 / Phan so 2 = ");

	if (KiemTraToiGian(ps1) == 1)
		printf("Phan so 1 da toi gian.\n");
	else
		printf("Phan so 1 chua toi gian.\n");
	
	int kq = SoSanh(ps1, ps2);
	if (kq > 0)
		printf("Phan so 1 > Phan so 2\n");
	else
		if (kq < 0)
			printf("Phan so 1 < Phan so 2\n");
		else
			printf("Phan so 1 = Phan so 2\n");*/

	// Mang PhanSo
	PHANSO a[100];
	int n;

	NhapMang(a, n);
	XuatMang(a, n, "Noi dung mang vua nhap: ");
	RutGonMang(a, n);
	XuatMang(a, n, "Noi dung mang sau khi rut gon: ");

	int vt = TimViTriPhanSoDuongDauTien(a, n);
	if (vt >= 0)
		Xuat(a[vt], "Phan so duong dau tien la: ");
	else
		printf("Khong co so duong nao trong mang\n");

	PHANSO psmin = TimPhanSoMin(a, n);
	Xuat(psmin, "Phan so nho nhat la: ");

	SapXepTang(a, n);
	XuatMang(a, n, "Mang sau khi sap xep tang: ");
}

// Dinh nghia ham
PHANSO ChuanHoa(PHANSO ps)
{
	PHANSO kq = ps;
	
	if (kq.mau < 0)
	{
		kq.tu = -kq.tu;
		kq.mau = -kq.mau;
	}

	return kq;
}

void Nhap(PHANSO &ps)
{
	printf("Nhap tu so: ");
	scanf("%d", &ps.tu);
	
	do
	{
		printf("Nhap tu mau: ");
		scanf("%d", &ps.mau);
	}
	while (ps.mau == 0);

	ps = ChuanHoa(ps);
}

void Xuat(PHANSO ps, char *thongbao)
{
	printf("%s", thongbao);
	
	if (ps.tu == 0)
		printf("0\n");
	else
		printf("%d/%d\n", ps.tu, ps.mau);
}

int TimUSCLN(int x, int y)
{
	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;

	if (x == 0)
		return y;

	if (y == 0)
		return x;

	while (x != y)
	{
		if (x > y)
			x = x - y;
		else
			y = y - x;
	}

	return x;
}

PHANSO RutGon(PHANSO ps)
{
	PHANSO kq;
	
	int uscln = TimUSCLN(ps.tu, ps.mau);
	kq.tu = ps.tu / uscln;
	kq.mau = ps.mau / uscln;

	return kq;
}

void QuyDong(PHANSO &ps1, PHANSO &ps2)
{
	if (ps1.mau != ps2.mau)
	{
		ps1.tu = ps1.tu * ps2.mau;
		ps2.tu = ps2.tu * ps1.mau;
	
		int msc = ps1.mau * ps2.mau;
		ps1.mau = msc;
		ps2.mau = msc;
	}
}

PHANSO Tong(PHANSO ps1, PHANSO ps2)
{
	PHANSO kq;
	
	QuyDong(ps1, ps2);
	kq.tu = ps1.tu + ps2.tu;
	kq.mau = ps1.mau;

	return kq;
}

PHANSO Hieu(PHANSO ps1, PHANSO ps2)
{
	PHANSO kq;
	
	QuyDong(ps1, ps2);
	kq.tu = ps1.tu - ps2.tu;
	kq.mau = ps1.mau;

	return kq;
}

PHANSO Tich(PHANSO ps1, PHANSO ps2)
{
	PHANSO kq;
	
	kq.tu = ps1.tu * ps2.tu;
	kq.mau = ps1.mau * ps2.mau;

	return kq;
}

PHANSO Thuong(PHANSO ps1, PHANSO ps2)
{
	PHANSO kq;
	
	kq.tu = ps1.tu * ps2.mau;
	kq.mau = ps1.mau * ps2.tu;

	kq = ChuanHoa(kq);

	return kq;
}

int KiemTraToiGian(PHANSO ps)
{
	if (TimUSCLN(ps.tu, ps.mau) == 1)
		return 1;
	else
		return 0;
}

int KiemTraAmDuong(PHANSO ps)
{
	ps = ChuanHoa(ps);
	if (ps.tu > 0)
		return 1;
	else
		if (ps.tu < 0)
			return -1;
		else
			return 0;
}

int SoSanh(PHANSO ps1, PHANSO ps2)
{
	ps1 = ChuanHoa(ps1);
	ps2 = ChuanHoa(ps2);
	QuyDong(ps1, ps2);
	
	if (ps1.tu > ps2.tu)
		return 1;
	else
		if (ps1.tu < ps2.tu)
			return -1;
		else
			return 0;
}

void NhapMang(PHANSO a[], int &n)
{
	printf("Nhap so luong phan so: ");
	scanf("%d", &n);

	for (int i=0; i<n; i++)
	{
		printf("Nhap phan so thu %d:\n", i + 1);
		Nhap(a[i]);
	}
}

void XuatMang(PHANSO a[], int n, char *thongbao)
{
	printf("%s\n", thongbao);
	for (int i=0; i<n; i++)
		Xuat(a[i], "-> ");
}

void RutGonMang(PHANSO a[], int n)
{
	for (int i=0; i<n; i++)
		a[i] = RutGon(a[i]);
}

int TimViTriPhanSoDuongDauTien(PHANSO a[], int n)
{
	for (int i=0; i<n; i++)
		if (KiemTraAmDuong(a[i]) > 0)
			return i;

	return -1;
}

PHANSO TimPhanSoMin(PHANSO a[], int n)
{
	PHANSO psmin = a[0];

	for (int i=1; i<n; i++)
		if (SoSanh(a[i], psmin) < 0)
			psmin = a[i];

	return psmin;
}

void HoanVi(PHANSO &ps1, PHANSO &ps2)
{
	PHANSO tam = ps1;
	ps1 = ps2;
	ps2 = tam;
}

void SapXepTang(PHANSO a[], int n)
{
	for (int i=0; i<n-1; i++)
		for (int j=i+1; j<n; j++)
			if (SoSanh(a[i], a[j]) > 0)
				HoanVi(a[i], a[j]);
}