#include<stdio.h>

void nhapmang(int a[], int b)
{
	printf("nhap mang voi %d phan tu",b);
	for (int i=0; i<b; i++)
	{
		printf("nhap phan tu thu %d ",i);
		scanf("%d",&a[i]);
	}
}
 void xuatmang(int a[],int b)
 {
 		for (int i=0; i<b; i++)
	{
		printf("nhap phan tu thu a[%d]= %d\n ",i, a[i]);
	}
 }
 void daolaide(int a[], int b, int c)
 {
 	int tam=a[b];
 	a[b]=a[c];
 	a[c]=tam;
 }
 void sapxepmangmotchieu(int a[],int d,int b)
 {
 	int x=a[d];
 	int dem;
 	for (int i=1;i<b;i++)
 	{
 		if (a[i]=>x)
 		{
 			dem++;
 		}
 	}
 	int xchuan=d+dem;
 	daolaide
 	
 }
 int main()
 {
 	int n;
 	printf("nhap so luong phan tu trong mang\n");
 	scanf ("%d",&n);
 	int c[n];
 	nhapmang(c,n);
 	xuatmang(c,n);
 	timthaythidung(c,n);
 }
