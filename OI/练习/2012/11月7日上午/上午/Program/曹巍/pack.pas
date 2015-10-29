var f:array[0..2000] of longint;
    aa:array[0..2000] of longint;
    cf:array[1..16] of longint;
    n,a,b,c,x,m,i:longint;
procedure pack1;
var i:longint;
begin
 read(a,b);
 for i:=b div a to m do
  if i*i*a-i*b>0 then
    if aa[i]<i*i*a-i*b then
  aa[i]:=i*i*a-i*b;
end;
procedure pack2;
var k,i,mm,j:longint;
begin
 read(a,b,c);
 mm:=0;
 k:=1;
 while c>k do begin
  inc(mm);
  cf[mm]:=k;
  c:=c-k;
  k:=k*2;
 end;
 inc(mm);
 cf[mm]:=c;

 for i:=1 to mm do
  for j:=m downto cf[i]*b do
   if f[j]<f[j-cf[i]*b]+cf[i]*a then f[j]:=f[j-cf[i]*b]+cf[i]*a;
end;
procedure pack3;
var k,i,mm,j:longint;
begin
 read(a,b);
 mm:=0;
 k:=1;
 c:=m;
 while c>k do begin
  inc(mm);
  cf[mm]:=k;
  c:=c-k;
  k:=k*2;
 end;
 inc(mm);
 cf[mm]:=c;

 for i:=1 to mm do
  for j:=cf[i]*b to m do
   if f[j]<f[j-cf[i]*b]+cf[i]*a then f[j]:=f[j-cf[i]*b]+cf[i]*a;
end;
begin
 assign(input,'pack.in');reset(input);
 assign(output,'pack.out');rewrite(output);
 read(n,m);
 fillchar(aa,sizeof(aa),0);
 for i:=1 to n do begin
  read(x);
  case x of
   1:pack1;
   2:pack2;
   3:pack3;
  end;
 end;

 for i:=m downto 0 do
  if f[m]<f[m-i]+aa[i] then f[m]:=f[m-i]+aa[i];

 writeln(f[m]);
 close(input);close(output);
end.
