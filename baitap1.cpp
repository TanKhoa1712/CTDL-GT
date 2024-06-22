#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
 struct Tamgiac
{
	int a;
	int b;
	int c;
};
struct Node
{
	Tamgiac info;
	struct	Node* next;
};
 struct Danhsach
{
	Node* head;
	Node* tail;
};
Node* createnode(Tamgiac x)
{
	Node* p;
	p= new Node;
	if (p==NULL)
	{
		exit(1);
	}
	p->info=x;
	p->next=NULL;
	return p;
}
void createlish(Danhsach &d)
{
	d.head=d.tail=NULL;
}
void nhaptamgiac( int &o, int &p, int &q)
{
	printf(" nhap vao chieu dai canh a: \n");
	fflush(stdin);
	scanf("%d",&o);
	printf(" nhap vao chieu dai canh b: \n");
	fflush(stdin);
	scanf("%d",&p);
	printf(" nhap vao chieu dai canh c: \n");
	fflush(stdin);
	scanf("%d",&q);
}
int kiemtratamgiac( int &o, int &p, int &q)
{
	if(o+p>q&&o+q>p&&p+q>o)
	{
		return 1;
	}
	return 0;
}
void luutamgiac( Tamgiac &x, int o, int p, int q)
{
	x.a=o;
	x.b=p;
	x.c=q;
}
int tinhchuvi(Tamgiac x)
{
	int tam;
	tam = x.a +x.b + x.c;
	return tam;
}
double tinhdientich(Tamgiac x)
{
	float p=tinhchuvi(x)/2;
	double s = p *sqrt((p-x.a)*(p-x.b)*(p-x.c));
	return s;
}
void in ( Tamgiac x)
{
	printf("Day la ba canh cua mot tam giac\n");
	printf("Chu vi tam giac la: %d\n", tinhchuvi(x));
	printf("Dien tich tam giac la: %lf\n",tinhdientich(x));
		
}
void indanhsach(Danhsach d)
{
	Node*p;
	while ( p!=NULL)
	{
		in(p->info);
		p=p->next;
	}
}
int main ()
{
	int o,p,q,n;
	nhaptamgiac(o,p,q);
	Tamgiac x;
	Danhsach d;
	do
	{
	createlish(d);
	printf("nhap so khac 0 de tiep tuc\n");
	printf("nhap so 0 de thoat\n");
	scanf("%d",&n);
	if(kiemtratamgiac(o,p,q)!=1)
	{
	printf("Day khong phai la ba canh cua tam giac tam giac");
	}
	else
	{	
	luutamgiac(x,o,p,q);
	indanhsach(d);
	}		
	}while(n!=0);
}
	
