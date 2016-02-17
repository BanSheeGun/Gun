var a,b:array[0..1000,0..1000] of longint;
    mx,n,m,i,j:longint;
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
begin
 read(n,m);
 for i:=1 to n do
  for j:=1 to m do
   read(a[i][j]);
 mx:=0;
 for i:=1 to n do
  for j:=1 to m do
   if a[i][j]=1 then  begin
   b[i][j]:=min(b[i-1][j],b[i][j-1]);
   b[i][j]:=min(b[i][j],b[i-1][j-1]);
   inc(b[i][j]);
   mx:=max(mx,b[i][j]);
  end;
 writeln(mx);
end.
