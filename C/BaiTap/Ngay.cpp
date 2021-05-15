#include <stdio.h>

// Khai bao kieu NGAY
typedef struct
{
	int ngay;
	int thang;
	int nam;
} NGAY;

// Nguyen mau ham
int KiemTraNamNhuan(int nam);
int TinhSoNgayTrongThang(int thang, int nam);
int KiemTraHopLe(NGAY ng);

void Nhap(NGAY &ng);
void Xuat(NGAY ng, char *thongbao);
int TinhSTTNgayTrongNam(NGAY ng);
int TinhSTTNgay(NGAY ng);
NGAY TinhNgayHomTruoc(NGAY ng);
NGAY TinhNgayHomSau(NGAY ng);
NGAY TinhNgayTruoc(NGAY ng, int k);
NGAY TinhNgaySau(NGAY ng, int k);
int TinhKhoangCach(NGAY ng1, NGAY ng2);
int SoSanh(NGAY ng1, NGAY ng2);

void main()
{
	NGAY ng1, ng2;

	Nhap(ng1);
	Xuat(ng1, "Ngay 1: ");

	//Nhap(ng2);
	//Xuat(ng2, "Ngay 2: ");

	if (KiemTraNamNhuan(ng1.nam) == 1)
		printf("Nam %d la nam nhuan\n", ng1.nam);
	else
		printf("Nam %d khong la nam nhuan\n", ng1.nam);

	printf("Ngay 1 la ngay thu %d trong nam %d\n", TinhSTTNgayTrongNam(ng1), ng1.nam);
	printf("Ngay 1 la ngay thu %d ke tu 1/1/1\n", TinhSTTNgay(ng1));

	Xuat(TinhNgayHomTruoc(ng1), "Ngay hom truoc cua Ngay 1 la: ");
	Xuat(TinhNgayHomSau(ng1), "Ngay hom sau cua Ngay 1 la: ");

	int k;
	printf("Nhap k: ");
	scanf("%d", &k);

	Xuat(TinhNgayTruoc(ng1, k), "Ngay truoc k ngay cua Ngay 1 la: ");
	Xuat(TinhNgaySau(ng1, k), "Ngay sau k ngay cua Ngay 1 la: ");
}

// Dinh nghia ham
int KiemTraNamNhuan(int nam)
{
	if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
		return 1;

	return 0;
}

int TinhSoNgayTrongThang(int thang, int nam)
{
	int songay;

	switch (thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		songay = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		songay = 30;
		break;
	case 2:
		if (KiemTraNamNhuan(nam) == 1)
			songay = 29;
		else
			songay = 28;
		break;
	default:
		songay = 0;
	}

	return songay;
}


int KiemTraHopLe(NGAY ng)
{
	int hople = 1;

	if (ng.nam < 0)
		hople = 0;
	else
		if (ng.thang < 1 || ng.thang > 12)
			hople = 0;
		else
			if (ng.ngay < 1 || ng.ngay > TinhSoNgayTrongThang(ng.thang, ng.nam))
				hople = 0;

	return hople;
}

void Nhap(NGAY &ng)
{
	int hople;

	do
	{
		printf("Nhap ngay: ");
		scanf("%d", &ng.ngay);
		
		printf("Nhap thang: ");
		scanf("%d", &ng.thang);
		
		printf("Nhap nam: ");
		scanf("%d", &ng.nam);

		hople = KiemTraHopLe(ng);
		if (!hople)
			printf("Nhap lai! Ngay khong hop le.\n");
	}
	while(!hople);
}

void Xuat(NGAY ng, char *thongbao)
{
	printf("%s", thongbao);
	printf("%d/%d/%d\n", ng.ngay, ng.thang, ng.nam);
}

int TinhSTTNgayTrongNam(NGAY ng)
{
	int stt = 0;

	// Tinh tong so ngay cac thang truoc do
	for (int i=1; i<ng.thang; i++)
		stt = stt + TinhSoNgayTrongThang(i, ng.nam);

	stt = stt + ng.ngay;

	return stt;
}

int TinhSTTNgay(NGAY ng)
{
	int stt = 0;

	// Tinh tong so ngay cac nam truoc do
	for (int i=1; i<ng.nam; i++)
		if (KiemTraNamNhuan(i) == 1)
			stt = stt + 366;
		else
			stt = stt + 365;

	stt = stt + TinhSTTNgayTrongNam(ng);

	return stt;
}

NGAY TinhNgayHomTruoc(NGAY ng)
{
	NGAY kq;

	if (ng.ngay == 1)	// Ngay dau tien cua thang (1/?/?)
	{
		if (ng.thang == 1)	// Thang dau tien cua nam (1/1/?)
		{
			kq.nam = ng.nam - 1;
			kq.thang = 12;
			kq.ngay = 31;
		}
		else
		{
			kq.nam = ng.nam;
			kq.thang = ng.thang - 1;
			kq.ngay = TinhSoNgayTrongThang(kq.thang, kq.nam);
		}
	}
	else
	{
		kq.ngay = ng.ngay - 1;
		kq.thang = ng.thang;
		kq.nam = ng.nam;
	}

	return kq;
}

NGAY TinhNgayHomSau(NGAY ng)
{
	NGAY kq;

	int max = TinhSoNgayTrongThang(ng.thang, ng.nam);

	if (ng.ngay == max)	// Ngay cuoi cung cua thang
	{
		if (ng.thang == 12)	// Thang cuoi cung cua nam
		{
			kq.nam = ng.nam + 1;
			kq.thang = 1;
			kq.ngay = 1;
		}
		else
		{
			kq.nam = ng.nam;
			kq.thang = ng.thang + 1;
			kq.ngay = 1;
		}
	}
	else
	{
		kq.ngay = ng.ngay + 1;
		kq.thang = ng.thang;
		kq.nam = ng.nam;
	}

	return kq;
}

NGAY TinhNgayTruoc(NGAY ng, int k)
{
	NGAY kq = ng;

	for (int i=0; i<k; i++)
		kq = TinhNgayHomTruoc(kq);

	return kq;
}

NGAY TinhNgaySau(NGAY ng, int k)
{
	NGAY kq = ng;

	for (int i=0; i<k; i++)
		kq = TinhNgayHomSau(kq);

	return kq;
}

int TinhKhoangCach(NGAY ng1, NGAY ng2)
{
	return TinhSTTNgay(ng1) - TinhSTTNgay(ng2);
}

int SoSanh(NGAY ng1, NGAY ng2)
{
	int kc = TinhKhoangCach(ng1, ng2);

	if (kc > 0)
		return 1;
	else
		if (kc < 0)
			return -1;
		else
			return 0;
}