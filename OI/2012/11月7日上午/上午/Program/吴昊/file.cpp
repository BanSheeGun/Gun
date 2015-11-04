#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int root=0;
char s[2555],ch;
string tmps;
int n,tot,cnt;
struct Orz_
{
	string s;
	int num,nxt[555];
}p[555];
bool cmp(int a,int b)
{
	string s1=p[a].s;
	string s2=p[b].s;
	int l1=s1.size(),l2=s2.size();
	for (int p=0;p<max(l1,l2);p++)
	{
		if (s1[p]>s2[p]) return false;
		if (s1[p]<s2[p]) return true;
	}
	return true;
}
void print(int q,int pos)
{
	for (int j=1;j<q;j++)
		printf("|    ");
	if (q!=0) printf("|----");
	cout<<p[pos].s<<endl;
	sort(p[pos].nxt+1,p[pos].nxt+1+p[pos].num,cmp);
	for (int i=1;i<=p[pos].num;i++) print(q+1,p[pos].nxt[i]);
}
int main()
{
	freopen("file.in","r",stdin);
	freopen("file.out","w",stdout);
	scanf("%d%c",&n,&ch);
	tot=0;
	for (int i=1;i<=n;i++)
	{
		cnt=0;
		memset(s,0,sizeof s);
		gets(s);
		int ll=strlen(s),pos=root;
		s[ll]='/';ll++;
		for (int j=0;j<ll;j++)
			if (s[j]!='/') tmps+=s[j];
			else
			{
				cnt++;
				int t=0;
				for (int k=1;k<=p[pos].num;k++)
					if (p[p[pos].nxt[k]].s==tmps)
					{
						t=1;
						pos=p[pos].nxt[k];
						break;
					}
				if (!t)
				{
					p[pos].num++;
					tot++;
					p[tot].s=tmps;
					p[pos].nxt[p[pos].num]=tot;
					pos=tot;
				}
				tmps="";
			}
	}
	print(0,p[0].nxt[1]);
	return 0;
}
