var f:array[1..100,0..100] of longint;
    v,fa,ma,son:array[0..100] of longint;
    ans,i,n,k,j:longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
function min(a,b:longint):longint;
begin
 if a<b then exit(a);
 exit(b);
end;
procedure dfs(x:longint);
var i,j:longint;
begin
 if (fa[x]=0)and(ma[x]=0) then begin
  son[x]:=1;
  f[x][0]:=0;
  f[x][1]:=v[x];
  exit;
 end;
 if (fa[x]<>0)and(ma[x]=0) then begin
  dfs(fa[x]);
  son[x]:=son[fa[x]]+1;
  f[x][0]:=0;
  for i:=0 to min(son[x]-1,k) do
   f[x][i+1]:=v[x]+f[fa[x]][i];
  exit;
 end;
 if (ma[x]<>0)and(fa[x]=0) then begin
  f[x][0]:=0;
  dfs(ma[x]);
  son[x]:=son[ma[x]]+1;
  for i:=0 to min(son[x]-1,k) do
   f[x][i+1]:=v[x]+f[ma[x]][i];
  exit;
 end;
 dfs(fa[x]);
 dfs(ma[x]);
 f[x][0]:=0;
 son[x]:=son[fa[x]]+son[ma[x]]+1;
 for i:=0 to min(son[x]-1,k) do begin
  j:=0;
  f[x][i+1]:=f[fa[x]][j]+f[ma[x]][i-j];
  for j:=0 to i do
   f[x][i+1]:=max(f[x][i+1],f[fa[x]][j]+f[ma[x]][i-j]);
  f[x,i+1]:=f[x][i+1]+v[x];
 end;
end;
begin
 assign(input,'rpwt.in');reset(input);
 assign(output,'rpwt.out');rewrite(output);
 read(n,k);
 for i:=1 to n-1 do read(v[i+1]);
 for i:=1 to n do
  read(fa[i],ma[i]);
 fillchar(son,sizeof(son),0);
 for i:=1 to n do
  for j:=1 to k+1 do f[i][j]:=-maxlongint div 2;
 dfs(1);
 writeln(f[1][k+1]);
 close(input);close(output);
end.
