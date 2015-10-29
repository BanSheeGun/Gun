//file pro3-test20111023 Syc 20111023
#include <iostream>
using namespace std;

string s[51],a[1000],b[1000];

int main()
{
	freopen("file.in","r",stdin);
	freopen("file.out","w",stdout);
	int n,i,j,k,p;
	cin>>n;
	for (i=1;i<=n;i++)
		cin>>s[i];
	for (i=1;i<=n-1;i++)
		for (j=i+1;j<=n;j++)
			if (s[i]>s[j])
				swap(s[i],s[j]);
	p=s[1].find("/")+1;
	if (p==1)
		p=s[1].size();

	cout<<s[1].substr(0,p-1)<<endl;
	for (i=1;i<=n;i++)
		s[i].erase(0,p);
	int m=0;
	string s1,s2;
	for (i=1;i<=n;i++)
	{
		p=s[i].find('/');
		s2="";
		if (p<0)
		{
			cout<<s2<<"|----"<<s[i]<<endl;
			continue;
		}
		while(p>0)
		{
			bool flag=true;
			s1=s[i].substr(0,p);
			s[i].erase(0,p+1);
			for (j=1;j<=m;j++)
				if (a[j]==s1)
				{
					flag=0;
					s2="|    "+s2;
					break;
				}
			if (flag)
			{
				a[++m]=s1;
				b[m]="|    ";
				cout<<s2<<"|----"<<a[m]<<endl;
				s2="|    "+s2;
			}
			p=s[i].find('/');
		}
		cout<<s2<<"|----"<<s[i]<<endl;
	}	
//	system("pause");
	return 0;
}
