/*
  Name: file.cpp
  Copyright: Zpc
  Author: Zpc
  Date: 23-10-11 10:55
  Description: ºÚ÷± «≤Ÿµ∞ test 3 
*/

#include <iostream>
using namespace std;

#define s1 "|    "
#define s2 "|----"

struct file
{
	int len;
	file* f[21];
	string s,sout;
};

int n,m;
file *tree,*p,*q;
string s,t;

file* tree_find(file* p,string s)
{
	file *q;
	for(int i=1;i<=p->len;i++)
		if(p->f[i]->s==s)
			return p->f[i];
	(p->len)++;
//	p->f[p->len].s=s;
//	p->f[p->len].f=new file[51];
//	memset(p->f[p->len].f,0,51*sizeof(file));
	q=p->f[p->len];
	q->s=s;
	for(int j=0;j<=20;j++)
	{
		q->f[j]=new file;
		q->f[j]->len=0;
		q->f[j]->s="";
		q->f[j]->sout="";
	}
	return q;
}

void q_sort(file* f[],int l,int r)
{
	int i=l,j=r;
	string mid=f[(l+r)]->s;
	while(i<=j)
	{
		while(f[i]->s<mid)	i++;
		while(f[j]->s>mid)	j--;
		if(i<=j)
			swap(f[i++],f[j--]);
	}
	if(i<r)
		q_sort(f,i,r);
	if(l<j)
		q_sort(f,l,j);
}

void prints(file* p)
{
	cout<<p->sout<<endl;
//	q_sort(p->f,1,p->len);
	int l=p->len;
	for(int i=1;i<l;i++)
		for(int j=i+1;j<=l;j++)
			if(p->f[i]->s > p->f[j]->s)
				swap(p->f[i],p->f[j]);
	for(int i=1;i<=p->len;i++)
		prints(p->f[i]);
}

int main()
{
	freopen("file.in","r",stdin);
	freopen("file.out","w",stdout);
	
	int i,j,k,fr,en;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		s+='/';
		k=s.find('/');
		t=s.substr(0,k);
		if(NULL==tree)
		{
			p=new file;
			p->len=0;
//			p->f=new file[51];
//			memset(p->f,0,51*sizeof(file));
			for(j=0;j<=20;j++)
			{
				p->f[j]=new file;
				p->f[j]->len=0;
				p->f[j]->s="";
				p->f[j]->sout="";
			}
			p->s=t;
			p->sout=t;
			tree=p;
		}
		p=tree;
		s.erase(0,k+1);
		k=s.find('/');
		m=1;
		while(k>0)
		{
			t=s.substr(0,k);
			p=tree_find(p,t);
			if(m>0)
				t=s2+t;
			for(j=1;j<=m-1;j++)
				t=s1+t;
			p->sout=t;
			s.erase(0,k+1);
			k=s.find('/');
			m++;
		}
	}
	prints(tree);
	
//	system("pause");
	return 0;
}
