#include <stdio.h>
#include <math.h>

// Khai bao kieu DIEM & TAMGIAC
typedef struct
{
	int x;	// tung do
	int y;	// hoanh do
} DIEM;

typedef struct
{
	DIEM dA;
	DIEM dB;
	DIEM dC;
} TAMGIAC;

// Nguyen mau ham
void NhapDiem(DIEM &d);
void XuatDiem(DIEM d, char *thongbao);
float TinhKhoangCach(DIEM d1, DIEM d2);

void NhapTamGiac(TAMGIAC &tg);
void XuatTamGiac(TAMGIAC tg, char *thongbao);
float TinhChuVi(TAMGIAC tg);
float TinhDienTich(TAMGIAC tg);

void main()
{
	TAMGIAC tg;
	
	NhapTamGiac(tg);
	XuatTamGiac(tg, "Toa do ba diem cua Tam giac:\n");

	printf("Chu vi Tam giac = %.2f\n", TinhChuVi(tg));
	printf("Dien tich Tam giac = %.2f\n", TinhDienTich(tg));
}

// Dinh nghia ham
void NhapDiem(DIEM &d)
{
	printf("Nhap tung do x: ");
	scanf("%d", &d.x);
	printf("Nhap hoanh do y: ");
	scanf("%d", &d.y);
}

void XuatDiem(DIEM d, char *thongbao)
{
	printf("%s", thongbao);
	printf("(%d, %d)\n", d.x, d.y);
}

float TinhKhoangCach(DIEM d1, DIEM d2)
{
	float kq;

	int dx = d1.x - d2.x;
	int dy = d1.y - d2.y;

	kq = sqrt(float(dx*dx + dy*dy));

	return kq;
}

void NhapTamGiac(TAMGIAC &tg)
{
	printf("Nhap toa do Diem A:\n");
	NhapDiem(tg.dA);
	printf("Nhap toa do Diem B:\n");
	NhapDiem(tg.dB);
	printf("Nhap toa do Diem C:\n");
	NhapDiem(tg.dC);
}

void XuatTamGiac(TAMGIAC tg, char *thongbao)
{
	printf("%s", thongbao);
	XuatDiem(tg.dA, "- Toa do Diem A: ");
	XuatDiem(tg.dB, "- Toa do Diem B: ");
	XuatDiem(tg.dC, "- Toa do Diem C: ");
}

float TinhChuVi(TAMGIAC tg)
{
	float P, AB, AC, BC;

	AB = TinhKhoangCach(tg.dA, tg.dB);
	AC = TinhKhoangCach(tg.dA, tg.dC);
	BC = TinhKhoangCach(tg.dB, tg.dC);
	P = AB + AC + BC;

	return P;
}

float TinhDienTich(TAMGIAC tg)
{
	float S, p, AB, AC, BC;

	AB = TinhKhoangCach(tg.dA, tg.dB);
	AC = TinhKhoangCach(tg.dA, tg.dC);
	BC = TinhKhoangCach(tg.dB, tg.dC);

	p = (AB + AC + BC) / 2;
	S = sqrt(p * (p - AB) * (p - AC) * (p - BC));

	return S;
}