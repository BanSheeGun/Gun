#include<fstream>
#include<string>
using namespace std;
ifstream cin("file.in");
ofstream cout("file.out");
struct node_{
	int ch;
	string name;
	int id[16];
	node_():ch(0){}
}node[100];
int tot=1;
string path;
void trie(int v,int pos){
	int tmp=path.find('/',pos);
	if(tmp==-1){
		string file=path.substr(pos);
		int ch=++node[v].ch;
		node[v].id[ch]=++tot;//child is a file
		node[tot].name=file;
	}else{
		string dir=path.substr(pos,tmp-pos);
		int ch=node[v].ch;
		for(int i=1;i<=ch;i++)
			if(node[node[v].id[i]].name==dir){
				trie(node[v].id[i],tmp+1);
				return;
			}
		ch=++node[v].ch;
		node[v].id[ch]=++tot;//child is a dir
		node[tot].name=dir;
		trie(tot,tmp+1);
	}
}
void dfs(int deep,int v){
	for(int i=1;i<deep;i++){
		cout<<'|';
		for(int j=0;j<4;j++){
			if(i==deep-1)cout<<'-';
			else cout<<' ';
		}
	}
	node_ &t=node[v];
	cout<<t.name<<endl;
	for(int i=1;i<t.ch;i++)
		for(int j=i+1;j<=t.ch;j++)
			if(node[t.id[j]].name<node[t.id[i]].name)
				swap(t.id[j],t.id[i]);
	for(int i=1;i<=node[v].ch;i++)
		dfs(deep+1,node[v].id[i]);
}
int main(){
	int n,tot=0;cin>>n;
	for(int i=0;i<n;i++){
		cin>>path;
		int pos=path.find('/');
		node[1].name=path.substr(0,pos);
		trie(1,pos+1);
	}
	dfs(1,1);
}
