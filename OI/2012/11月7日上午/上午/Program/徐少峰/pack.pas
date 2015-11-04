var n,m,i,j,k:longint;
    mark,t,c,num:array[1..100]of longint;
    f:array[0..1000]of longint;

function max(a,b:longint):longint;
 begin
  if a>b then max:=a else max:=b;
 end;

begin
assign(input,'pack.in');reset(input);
assign(output,'pack.out');rewrite(output);
read(n,m);
for i:=1 to n do
 begin
  read(mark[i]);
  if mark[i]=2 then read(c[i],t[i],num[i])
               else read(c[i],t[i]);
 end;

fillchar(f,sizeof(f),255);
f[0]:=0;
for i:=1 to n do
 if mark[i]=1 then
  begin
   for j:=m downto 0 do
    if f[j]>=0 then f[j]:=max(f[j],f[j]+c[i]*j*j-t[i]*j)
  end else
 if mark[i]=2 then
  begin
  for k:=1 to num[i] do
   for j:=m downto t[i] do
    if f[j-t[i]]>=0 then f[j]:=max(f[j],f[j-t[i]]+c[i]);
  end else
  for j:=t[i] to m do if f[j-t[i]]>=0 then f[j]:=max(f[j],f[j-t[i]]+c[i]);

writeln(f[m]);
close(input);close(output);
end.
