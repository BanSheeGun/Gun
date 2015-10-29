var son,a,head,e,next,q,b:array[0..6000] of longint;
    root,x,y,n,m,i:longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;

procedure dfs(x:longint);
var zsum,csum,k:longint;
begin
 zsum:=0;
 csum:=0;
 k:=head[x];
 while k<>0 do begin
  dfs(e[k]);
  zsum:=zsum+b[e[k]];
  csum:=csum+max(b[e[k]],q[e[k]]);
  k:=next[k];
 end;
 b[x]:=csum;
 q[x]:=zsum+a[x];
end;

begin
 read(n);
 for i:=1 to n do read(a[i]);
 read(y,x);
 m:=0;
 while not((x=0)and(y=0)) do begin
  inc(son[y]);
  inc(m);
  e[m]:=y;
  next[m]:=head[x];
  head[x]:=m;
  read(y,x);
 end;
 for i:=1 to n do
  if son[i]=0 then root:=i;
 fillchar(q,sizeof(q),0);
 fillchar(b,sizeof(b),0);

 dfs(root);

 writeln(max(q[root],b[root]));
end.
