#include<cstdio>
#include<cstring>
int n,len,num;
char s[100],ns[12];
struct tree{int l,num,next[20]; char name[12];}a[1111];

void insert(int t,int p){
    if (p>=len) return;
    int j=0;
    bool ok;
    while (p+j<len && s[p+j]!='/')
      {
        ns[j]=s[p+j];
        j++;
      }
    ok=false;
    for (int i=1; i<=a[t].num; i++)
        if (j==a[a[t].next[i]].l)
          {
            ok=true;
            for (int x=0; x<j; x++)
                if (a[a[t].next[i]].name[x]!=ns[x])
                  {
                    ok=false; break;
                  }
            if (ok) {
                      insert(a[t].next[i],p+j+1);
                      break;
                    }
          }
    if (ok==false) {
                     num++;
                     a[t].num++;
                     a[t].next[a[t].num]=num;
                     a[num].l=j;
                     for (int i=0; i<j; i++)
                         a[num].name[i]=ns[i];
                     insert(num,p+j+1);
                   }
}

void check(int t){
    bool ok;
    int x,y,tx,ty;
    for (int i=1; i<=a[t].num; i++)
        for (int j=i+1; j<=a[t].num; j++)
          {
            ok=true;
            x=0; y=0; tx=a[t].next[i]; ty=a[t].next[j];
            while (x<a[tx].l && y<a[ty].l && a[tx].name[x]==a[ty].name[y])
              {
                  x++; y++;
              }
            if (x==a[tx].l) ok=true;
                       else if (y==a[ty].l) ok=false;
                                       else ok=a[tx].name[x]<a[ty].name[y];
            if (ok==false) {
                             a[t].next[i]=ty;
                             a[t].next[j]=tx;
                           }
          }
    for (int i=1; i<=a[t].num; i++)
        check(a[t].next[i]);
}

void print(int t,int dep){
     for (int i=1; i<=dep-2; i++)
         printf("|    ");
     if (dep>1) printf("|----");
     if (dep>0) printf("%s\n",a[t].name);
     for (int i=1; i<=a[t].num; i++)
         print(a[t].next[i],dep+1);
}

int main(){
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
      {
        scanf("%s",s);
        len=strlen(s);
        insert(0,0);
      }
    check(0);
    print(0,0);
    return 0;
}
