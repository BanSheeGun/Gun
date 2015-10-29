#include<stdio.h>
struct node
{
   char c;
   int  son[50];
   int  cnt;
};
node tree[1000];
char a[100][10000],temp[100]={'\0'};
int count=0;
void maketree (int x,int y,int z)
{
   char tc=a[x][y];
   int tn=tc-'a'+1;
   if(tc=='\0')
      return ;
   if(tc=='/')
      tn=28;
   if(tc=='.')
      tn=27;
   if(tree[z].son[tn]==0)
   {
      tree[++count].c=tc;
      tree[z].son[tn]=count;
   }
   maketree(x,y+1,tree[z].son[tn]);
}
void dfs(int x,int y)
{
    int i,ty=y;
    bool f=false;
    //if(tree[x].c!='/')
         //printf("%c",tree[x].c);
    printf("tree[%d]\nc=%c,y=%d\n",x,tree[x].c,y);
    if(tree[x].c=='/')
      temp[0]=0;
    else
      temp[0]++,temp[temp[0]]=tree[x].c;
    for(i=0;i<=29;i++)
    {
       if(tree[x].son[i]!=0)
       { 
          
         if(tree[x].c=='/'||f)
         {
          if(y>1)
            for(i=1;i<=y;i++)
               printf("|    ");
          if(y>=1)
            printf("|----");
          if(tree[x].c=='/')
            ty=y+1;
         }
       else if(f)
         {
             for(i=1;i<=temp[0];i++);
              //printf("%c");
         }
       dfs(tree[x].son[i],ty);
         f=true;
       }  
    }
}
int main()
{
    int i,j,n;
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
       scanf("%s",a[i]);
    for(i=1;i<=n;i++)
        maketree(i,0,0);
    for(i=0;i<=29;i++)
    {
       temp[0]=0;
       if(tree[0].son[i]!=0)
       {
          dfs(tree[0].son[i],0);
       }
    }
    fclose(stdin);
    fclose(stdout);
}
