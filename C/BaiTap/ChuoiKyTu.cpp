#include <stdio.h>
#include <string.h>
#include <malloc.h>

unsigned int mystrlen(char *s);
char* mystrupr(char *s);
char* mystrlwr(char *s);
char* mystrrev(char *s);
char* proper(char *s);
char* XoaKyTu(char *s, int vt);
char* standard(char *s);
char* XoaTatCaKhoangTrang(char *s);
int DemSoLuongVaLietKeTu(char *s);
char* TimTuDaiNhat(char *s);
void LietKeCacTuDaiNhat(char *s);

int main()
{
	char s[100];

	printf("Nhap mot chuoi: ");
	gets(s);
	printf("Chuoi vua nhap la: ");
	puts(s);
	printf("\"%s\"\n", s);

	//mystrupr(s);
	//puts(s);
	/*char *s2 = mystrupr(s);
	puts(s2); // Cach 2
	puts(s);

	//mystrrev(s);
	//puts(s);
	puts(mystrrev(s)); // Cach 2*/

	/*puts(proper(s));

	standard(s);
	printf("Chuoi sau khi duoc chuan hoa: ");
	//puts(s);
	printf("\"%s\"\n", s);

	XoaTatCaKhoangTrang(s);
	printf("Chuoi sau khi xoa tat ca khoang trang: ");
	//puts(s);
	printf("\"%s\"\n", s);*/

	int soluong = DemSoLuongVaLietKeTu(s);
	printf("Co tong cong %d tu\n", soluong);

	printf("Mot trong cac tu dai nhat la: %s\n", TimTuDaiNhat(s));
	
	LietKeCacTuDaiNhat(s);
	return 0;

}

unsigned int mystrlen(char *s)
{
	unsigned int len = 0;
	
	while (s[len] != '\0')
		len++;

	return len;
}

char* mystrupr(char *s)
{
	for (int i=0; i<strlen(s); i++)
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;

	return s;
}

char* mystrlwr(char *s)
{
	int n = strlen(s);
	
	for (int i=0; i<n; i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;

	return s;
}

char* mystrrev(char *s)
{
	int n = strlen(s);
	
	// 01234 -> 43210
	for (int i=0; i<n/2; i++)
	{
		char t = s[i];
		s[i] = s[n-1-i];
		s[n-1-i] = t;
	}

	return s;
}

char* proper(char *s)
{
	strlwr(s);

	if (strlen(s) > 0)
	{
		if (s[0] >= 'a' && s[0] <= 'z')
			s[0] = s[0] - 32;

		for (int i=0; i<strlen(s); i++)
			if (s[i] >= 'a' && s[i] <= 'z' && s[i-1] == ' ')
				s[i] = s[i] - 32;
	}

	return s;
}


char* XoaKyTu(char *s, int vt)
{
	if (vt>=0 && vt<strlen(s))
	{
		// Cach 1
		//for (int i=vt; i<strlen(s)-1; i++)
		//	s[i] = s[i+1];

		//s[strlen(s)-1] = '\0';

		// Cach 2
		for (int i=vt; i<strlen(s); i++)
			s[i] = s[i+1];
	}

	return s;
}

char* standard(char *s)
{
	// Xoa khoang trang du dau chuoi
	while (s[0] == ' ')
		XoaKyTu(s, 0);

	// Xoa khoang trang du cuoi chuoi
	while (s[strlen(s)-1] == ' ')
		XoaKyTu(s, strlen(s)-1);

	// Xoa khoang trang du giua chuoi
	for (int i=1; i<strlen(s)-2; )
		if (s[i] == ' ' && s[i+1] == ' ')
			XoaKyTu(s, i);
		else
			i++;

	return s;
}

char* XoaTatCaKhoangTrang(char *s)
{
	// Cach 1
	/*for (int i=0; i<strlen(s); i++)
		if (s[i] == ' ')
		{
			XoaKyTu(s, i);
			i--;
		}*/

	// Cach 2
	/*for (int i=0; i<strlen(s); )
		if (s[i] == ' ')
			XoaKyTu(s, i);
		else
			i++;*/

	// Cach 3
	for (int i=strlen(s)-1; i>=0; i--)
		if (s[i] == ' ')
			XoaKyTu(s, i);

	return s;
}

int DemSoLuongVaLietKeTu(char *s)
{
	char *s2 = strdup(s); // hoac s = strdup(s);

	char *p;
	int dem = 0;
	
	p = strtok(s2, " "); // Luu y, sau khi su dung strtok thi chuoi s bi thay doi
	
	while (p != NULL)
	{
		dem++;
		printf("Tu thu %d: %s\n", dem, p);

		p = strtok(NULL, " ");
	}

	return dem;
}

char* TimTuDaiNhat(char *s)
{
	char *s2 = strdup(s);

	char *p, *pmax;
	int lmax = 0;

	p = strtok(s2, " ");
	
	while (p != NULL)
	{
		if (strlen(p) > lmax)
		{
			pmax = p;
			lmax = strlen(p);
		}

		p = strtok(NULL, " ");
	}

	return pmax;
}

void LietKeCacTuDaiNhat(char *s)
{
	char *s2 = strdup(s);

	int lmax = strlen(TimTuDaiNhat(s2));

	char *p;

	printf("Cac tu dai nhat la:\n");
	p = strtok(s2, " "); // Luu y, sau khi su dung strtok thi chuoi s bi thay doi
	
	while (p != NULL)
	{
		if (strlen(p) == lmax)
			puts(p);

		p = strtok(NULL, " ");
	}
}