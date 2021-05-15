#include <stdio.h>
#include <math.h>

// Khai bao kieu DONTHUC
typedef struct
{
	float a;
	int n;
} DONTHUC;

// Nguyen mau ham
void Nhap(DONTHUC &dt);
void Xuat(DONTHUC dt, char thongbao[]);
DONTHUC Tich(DONTHUC dt1, DONTHUC dt2);
DONTHUC Thuong(DONTHUC dt1, DONTHUC dt2);
DONTHUC DaoHamCap1(DONTHUC dt);
DONTHUC DaoHamCapk(DONTHUC dt, int k);
float TinhGiaTri(DONTHUC dt, float x0);

void main()
{
	DONTHUC dt1, dt2;
	
	Nhap(dt1);
	Xuat(dt1, "Don thuc 1 la: ");
	
	Nhap(dt2);
	Xuat(dt2, "Don thuc 2 la: ");

	DONTHUC tich = Tich(dt1, dt2);
	Xuat(tich, "Don thuc 1 * Don thuc 2 = ");
	Xuat(Thuong(dt1, dt2), "Don thuc 1 / Don thuc 2 = ");

	Xuat(DaoHamCap1(dt1), "Dao ham cap 1 cua Don thuc 1 = ");
	
	int k;
	printf("Nhap k: ");
	scanf("%d", &k);
	Xuat(DaoHamCapk(dt1, k), "Dao ham cap k cua Don thuc 1 = ");

	float x0;
	printf("Nhap x0: ");
	scanf("%f", &x0);
	printf("Gia tri cua don thuc 1 tai x0 = %.2f la %.2f\n", x0, TinhGiaTri(dt1, x0));
}

// Dinh nghia ham
void Nhap(DONTHUC &dt)
{
	float temp;
	printf("Nhap he so a: ");
	scanf("%f", &temp);
	dt.a = temp;
	
	printf("Nhap so mu n: ");
	scanf("%d", &dt.n);
}

void Xuat(DONTHUC dt, char *thongbao)
{
	printf("%s", thongbao);
	printf("%.2fx^%d\n", dt.a, dt.n);

	/*if (dt.a != 0)
	{
		if (dt.a != 1)
			if (dt.a == -1)
				printf("-");
			else
				printf("%.2f", dt.a);

		if (dt.n != 0)
			if (dt.n == 1)
				printf("x\n");
			else
				printf("x^%d\n", dt.n);
		else
			printf("\n");
	}
	else
		printf("0\n");*/
}

DONTHUC Tich(DONTHUC dt1, DONTHUC dt2)
{
	DONTHUC kq;

	kq.a = dt1.a * dt2.a;
	kq.n = dt1.n + dt2.n;

	return kq;
}

DONTHUC Thuong(DONTHUC dt1, DONTHUC dt2)
{
	DONTHUC kq;

	kq.a = dt1.a / dt2.a;
	kq.n = dt1.n - dt2.n;

	return kq;
}

DONTHUC DaoHamCap1(DONTHUC dt)
{
	DONTHUC kq;
	
	kq.a = dt.a * dt.n;
	kq.n = dt.n - 1;

	return kq;
}

DONTHUC DaoHamCapk(DONTHUC dt, int k)
{
	DONTHUC kq = dt;

	for (int i=0; i<k; i++)
		kq = DaoHamCap1(kq);
	
	return kq;
}

float TinhGiaTri(DONTHUC dt, float x0)
{
	float kq;
	
	kq = dt.a * pow(x0, dt.n);

	return kq;
}