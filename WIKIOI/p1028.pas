var a:array[1..100,1..100] of longint;
    ta,tb:array[1..100] of boolean;
    c,pa,pb:array[1..100] of longint;
    i,j,n,m,y,k,d,ans:longint;

function find(u:longint):boolean;
var i,ret:longint;
begin
 ta[u]:=true;
 for i:=1 to m do
  if (tb[i]=false) then begin
   ret:=pa[u]+pb[i]-a[u][i];
   if ret=0 then begin
    tb[i]:=true;
    if (c[i]=0) or (find(c[i])) then begin
     c[i]:=u;
     exit(true);
    end;
   end
   else if (ret<d) then d:=ret;
  end;
 exit(false);
end;

begin
 read(n,m);
 for i:=1 to n do
  for j:=1 to m do
   read(a[i][j]);

 for i:=1 to n do
  for j:=1 to m do
   if a[i][j]>pa[i] then pa[i]:=a[i][j];

 for i:=1 to n do
  while true do begin
  fillchar(ta,sizeof(ta),false);
  fillchar(tb,sizeof(tb),false);
  d:=maxlongint;
  if find(i) then break;

  for j:=1 to n do
   if ta[j] then dec(pa[j],d);
  for j:=1 to m do
   if tb[j] then inc(pb[j],d);
 end;

 ans:=0;
 for i:=1 to m do
  if c[i]<>0 then ans:=ans+a[c[i]][i];
 writeln(ans);
end.
