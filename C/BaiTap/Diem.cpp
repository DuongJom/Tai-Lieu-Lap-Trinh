#include <stdio.h>
#include <math.h>

// Khai bao kieu DIEM
typedef struct
{
	int x;	// tung do
	int y;	// hoanh do
} DIEM;

// Nguyen mau ham
void Nhap(DIEM &d);
void Xuat(DIEM d, char *thongbao);
float TinhKhoangCach(DIEM d1, DIEM d2);
DIEM TimDoiXungQuaGoc(DIEM d);
DIEM TimDoiXungQuaOx(DIEM d);
DIEM TimDoiXungQuaOy(DIEM d);

void main()
{
	DIEM d1, d2;
	
	Nhap(d1);
	Xuat(d1, "Toa do Diem 1: ");
	
	Nhap(d2);
	Xuat(d2, "Toa do Diem 2: ");

	printf("Khoang cach giua 2 diem = %.2f\n", TinhKhoangCach(d1, d2));

	Xuat(TimDoiXungQuaGoc(d1), "Toa do diem doi xung qua goc cua Diem 1: ");
	Xuat(TimDoiXungQuaOx(d1), "Toa do diem doi xung qua Ox cua Diem 1: ");
	Xuat(TimDoiXungQuaOy(d1), "Toa do diem doi xung qua Oy cua Diem 1: ");
}

// Dinh nghia ham
void Nhap(DIEM &d)
{
	printf("Nhap tung do x: ");
	scanf("%d", &d.x);
	printf("Nhap hoanh do y: ");
	scanf("%d", &d.y);
}

void Xuat(DIEM d, char *thongbao)
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

DIEM TimDoiXungQuaGoc(DIEM d)
{
	DIEM kq;
	
	kq.x = -d.x;
	kq.y = -d.y;

	return kq;
}

DIEM TimDoiXungQuaOx(DIEM d)
{
	DIEM kq;
	
	kq.x = d.x;
	kq.y = -d.y;

	return kq;
}

DIEM TimDoiXungQuaOy(DIEM d)
{
	DIEM kq;
	
	kq.x = -d.x;
	kq.y = d.y;

	return kq;
}