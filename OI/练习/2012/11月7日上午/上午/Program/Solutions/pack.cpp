#include<fstream>
using namespace std;
ifstream cin("pack.in");
ofstream cout("pack.out");
int N,M;

void Init()
{
	cin>>N>>M; 
}

int F[2005];

inline void CompletePack(int V,int W)
{
	for(int i=W;i<=M;i++)
		F[i]>?=F[i-W]+V;
}

inline void ZeroOnePack(int V,int W)
{
	for(int i=M;i>=W;i--)
		F[i]>?=F[i-W]+V;
}

inline void MultiPack(int V,int W,int Num)
{
	for(int i=1,t=0;;i<<=1,t++)
	{
		if((i<<1)-1>Num)
		{
			t=Num-i+1;
			ZeroOnePack(V*t,W*t);
			return;
		}
		
		ZeroOnePack(V<<t,W<<t);
		
		if((i<<1)-1==Num)
			return;
	}
}

inline void GeneralizationPack(int A,int B)
{
	for(int i=M;i>=1;i--)
		for(int x=1;x<=i;x++)
			F[i]>?=F[i-x]+A*x*x-B*x;
}

void Work()
{
	char Tpye;
	int A,B,C;
	
	for(int i=1;i<=N;i++)
	{
		cin>>Tpye;
		switch(Tpye)
		{
			case '3':
				cin>>A>>B;
				CompletePack(A,B);
				break;
			case '2':
				cin>>A>>B>>C;
				MultiPack(A,B,C);
				break;
			case '1':
				cin>>A>>B;
				GeneralizationPack(A,B);
		}
	}
}
void Output()
{
	cout<<F[M]<<"\n";
}

int main()
{
	Init();
	Work();
	Output();
	system("pause");
	return 0;
}
