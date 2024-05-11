#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#include"string.h"

 struct Sinhvien
{
	char Ten [40];
	char MSSV [10];
	int Tuoi;
};
struct Node
{
	Sinhvien info;
	struct	Node* next;
};
 struct Danhsach
{
	Node* head;
	Node* tail;
};
Node* createnode(Sinhvien x)
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
void nhap (Sinhvien &x)
{
	printf("Nhap ten sinh vien \n");fflush(stdin); gets(x.Ten);
	printf("Nhap MSSV sinh vien \n");fflush(stdin); gets(x.MSSV);
	printf("Nhap tuoi sinh vien \n");fflush(stdin); scanf("%d",&x.Tuoi);
}
void nhapcuoi(Danhsach &d,Node *p)
{
	if(d.head=NULL)
	{
		d.head=d.tail=p;
	}
	else
	{
		d.tail->next=p;
		d.tail=p;
	}
}
void nhaplieu(Danhsach &d)
{
	Sinhvien x;
	char t;
	printf(" Nhap phim bat ki de tiep tuc.\n");
	printf("Nhap 0 de thoat.\n");
	do
	{
		if (t='0')
		{
			break;
		}
		nhap(x);
		Node*p=createnode(x);
		nhapcuoi(d,p);
	}
	while(1);	
}
void in (Sinhvien x)
{
	printf("40%s10%s2%d",x.Ten,x.MSSV,x.Tuoi);
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
void deleter (Danhsach &d)
{
	Node *p,*q;
	char a[10];
	p=d.head;
	q=NULL;
	int dem;
	printf("\nNhap ma so sinh vien can xoa\n");
	fflush(stdin);
	scanf("%s",&a);
	while(p!=NULL)
	{
	if(strcmp(a,p->info.MSSV)==0)
	{
		dem++;
		break;
	}
	q=p;
	p=p->next;
	}
	if(dem==0)
	{
		printf("\n MSSV KHONG CO TRONG DANH SACH\n");
	}
	if(q!=NULL)
	{
		if(p!=NULL)
		{
			q->next=p->next;
			delete(p);
			if(p==d.tail)
			{
				d.tail=q;
				delete(p);
			}
		}
	}
	else 
	{
		d.head=p->next;
		delete(p);
		if(d.head=NULL)
		{
			d.tail==NULL;
		}
	}
}
void menu()
{
	Danhsach d;
	Node *p,*q,*moi;
	Sinhvien x;
	char r;
	createlish(d);
	do
	{
		printf("**Chon mot lua chon");
		printf("\n1. Nhap danh sach\n");
		printf("2. In danh sach\n");
		printf("3. Xoa sinh vien ra khoi danh sach\n");
		scanf("%d",r);
		switch(r)
		{
			case 1:
				{
					nhaplieu(d);
					break;
				}
			case 2:
				{
					indanhsach(d);
					break;
				}
			case 3:
				{
					deleter(d);
					printf("\nDanh sach sau khi xoa ...\n");
					indanhsach(d);
					break;
				}
			case 0:
					{
						exit(1);
					}
			default : printf("Vui long nhap lai!!!");
		}
	}while(r!=0);
}
int main()
{
	menu();
}
