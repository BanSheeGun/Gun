program ex;
var m,n,i,j,x,y,max,k,z,s,tot:longint;
a,w,g:array[1..100] of longint;
f:array[0..2000] of longint;
t:boolean;

 begin
assign(input,'pack.in'); reset(input);
assign(output,'pack.out'); rewrite(output);
read(m,n);
if n=0 then writeln(0)
else
begin
i:=0;
while i<m do
  begin
  read(k);
  case k of
    1:begin read(x,y);  dec(m); end;
    2:begin read(x,y,z); inc(i); w[i]:=x; a[i]:=y; g[i]:=z; end;
    3:begin read(x,y); inc(i); w[i]:=x; a[i]:=y; g[i]:=-1; end;
    end;
  end;
for i:=1 to n do
  begin
  t:=false;
  max:=f[i-1];
  s:=0;
  tot:=0;
  for j:=1 to m do
    if g[j]=-1 then
      begin
      if i>=a[j] then
        if f[i-a[j]]+w[j]>max then begin max:=f[i-a[j]]+w[j]; t:=false; end;
        end
   else
    for k:=1 to g[j] do
      if i>=a[j]*k then
        if f[i-a[j]*k]+w[j]*k>max then  begin max:=f[i-a[j]*k]+w[j]*k; t:=true; s:=k; tot:=j; end;
  f[i]:=max;
  if t then g[tot]:=g[tot]-s;
  end;
writeln(f[n]);
end;
close(input); close(output);
end.
