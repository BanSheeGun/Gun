#include<cstdio>
#include<algorithm>
using namespace std;
struct trie{
    int l,r,cnt;
    char sc[12];
};
trie v[500];
int tot;
bool spcmp(char *a,char *b){
    int i;
    for (i=0;a[i];i++)
        if (a[i]!=b[i]) return false;
    return (b[i]==0 || b[i]=='/');
}
void putin(char *s,int &root){
    if (!s[0]) return;
    int i;
    for (i=1;s[i] && s[i]!='/';i++);
    if (root==-1){
        root=++tot;
        for (i=1;s[i] && s[i]!='/';i++) v[tot].sc[i-1]=s[i];
        v[tot].sc[i-1]=0;
        v[tot].l=v[tot].r=-1;
        putin(s+i,v[tot].l);
    } else
    if (spcmp(v[root].sc,s+1)) putin(s+i,v[root].l); else putin(s,v[root].r);
}
bool comp(int a,int b){
    for (int i=0;v[a].sc[i];i++){
        if (v[a].sc[i]<v[b].sc[i]) return true;
        if (v[a].sc[i]>v[b].sc[i]) return false;
    }
    return true;
}
void printree(int now,int h){
    if (now==-1) return;
    if (h){
        putchar('|');
        for (int i=1;i<h;i++) printf("    |");
        printf("----");
    }
    puts(v[now].sc);
    int i,pre=0,que[20];
    for (i=v[now].l;i!=-1;i=v[i].r) que[pre++]=i;
    sort(que,que+pre,comp);
    for (i=0;i<pre;i++) printree(que[i],h+1);
}
int main(){
    int n,root,i;
    char s[100];
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);
    scanf("%d",&n);
    root=tot=-1;
    for (i=0;i<n;i++){
        s[0]='/';
        scanf("%s",s+1);
        putin(s,root);
    }
    printree(root,0);
    return 0;
}
