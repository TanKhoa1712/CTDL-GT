#include<stdio.h>

void hoandoi (int a[], int b, int c)
{
	int tam =a[b];
	a[b]=a[c];
	a[c]=tam;
}

int phanhoach ( int a[], int b, int c)
{
	int moc= a[b];
	int dem=0;
	for ( int i =b+1; i<=c; i++)
	{
		if( moc>=a[i])
		{
			dem++;
		}
	}
	int gocchuan = b+dem;
	hoandoi (a,gocchuan,b);
	int d=b;
	int e=c;
	while( d< gocchuan && gocchuan < e)
	{
		while (a[d]<=moc)
		
		{
			d++;
		}
		while ( a[e]>=moc)
		{
			e--;
		}if( a[d]> a[e])
		{
			hoandoi(a,d,e);
			d++;e--;
		}
	}
	return gocchuan; 
}

void sapxepnhanh ( int a[], int b, int c)
{	
	int moc = phanhoach (a,b,c);
	if (b<=c)
	{
	sapxepnhanh(a,b,moc-1);
	sapxepnhanh(a,moc+1,c);
	}
	else
	{
	return;
	}
	
}	

void nhapgiatri( int &b)
{
	printf("nhap so phan tu trong mang ");
	scanf("%d",&b);
}

void nhapmang( int a[], int b)
{
	for (int i=0; i<b; i++)
	{
		printf(" nhap phan tu a[%d]",i);
		scanf("%d",&a[i]);
	}
}


void xuatmang( int a[], int b)
{
	for (int i=0; i<b; i++)
	{
		printf(" \n phan tu a[%d]: %d",i, a[i]);
	}
}

void Quicksort(int a[],int l,int r)
{
	int i,j;
	int x;
	// gan gia trij x la moc o giua
	x=a[(l+r)/2];
	i=l;j=r;
	do
	{
		while(a[i]<x i++;
		while(a[j]>x) j--;
		if(i<=j)
		{
			hoandoi(a,i,j);
			i++;j--;
		}
	}while(i<j);
	if(l<j)
	Quicksort(a,l,j);
	if(i<r)
	Quicksort(a,i,r);

}


int main()
{
	int n;
	nhapgiatri(n);
	int a[n];
	nhapmang(a,n);
	xuatmang(a,n);
	sapxepnhanh(a,0,n);
//	Quicksort(a,0,n);
	xuatmang(a,n);
}
