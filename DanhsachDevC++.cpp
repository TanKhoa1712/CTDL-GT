#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct
{
	char Ma[10];
	char HoTen[40];
} Sinhvien;
void writefile(char *tenfile)
{
	FILE *f;
	int n,i;
	Sinhvien sv;
	f=fopen(tenfile,"ab");
	printf("Nhap bao nhieu sinh vien?");
	scanf("%d",&n);
	fflush(stdin);
	for( int i=1; i<=n;i++)
	{
	printf("Sinh vien thu %i\n",i);
	printf("-MSSV: "); gets(sv.Ma);
	printf("-Ho ten: "); gets(sv.HoTen);
	fwrite(&sv,sizeof(sv),1,f);
	fflush(stdin);
	}
	fclose(f);
	printf("Bam phim bat ki de tiep tuc");
	getch();
}
void docfile(char *tenfile)
{
	FILE *f;
	Sinhvien sv;
	f=fopen(tenfile,"rb");
	printf("MSSV | Ho va ten\n");
	fread(&sv,sizeof(sv),1,f);
	while (!feof(f))
	{
		printf("%s | %s\n",sv.Ma,sv.HoTen);
		fread(&sv,sizeof(sv),1,f);
	}
	fclose(f);
	printf("Bam phim bat ki de tiep tuc");
	getch();
}
void tim(char*tenfile)
{
	char MSSV[10];
	FILE *f;
	int Found=0;
	Sinhvien sv;
	fflush(stdin);
	printf("Ma so sinh vien can tim: ");
	gets(MSSV);
	f=fopen(tenfile,"rb");
	while(!feof(f)&& Found==0)
	{
		fread(&sv,sizeof(sv),1,f);
		if(strcmp(sv.Ma,MSSV)==0)Found=1;
	}
	fclose(f);
	if(Found=1)
		{
			printf("Tim thay sinh vien cos ma %s. Ho ten la %s",sv.Ma,sv.HoTen);
		}
	else
	{
		printf("Tim khong thay ssinh vien co ma %s",MSSV);
		
	}
		printf("Bam phim bat ki de tiep tuc");
	getch();
}
int main()
{
	int c;
	for(;;)
{
	printf("1.Nhap danh sach sinh vien\n");
	printf("2.In danh sach sinh vien\n");
	printf("3.Tim kiem\n");
	printf("4.Thoat\n");
	
	printf("Bam chon 1,2,3,4:");
	scanf("%d",&c);
	if(c==1)
	{
		writefile("d:\\Sinhvien.Dat");
	}
	else if(c==2)
		{
			docfile("d:\\Sinhvien.Dat");
		}
		else if(c==3)
		{
			tim("d:\\Sinhvien.Dat");
		}
		else break;
}
	return 0;
}

