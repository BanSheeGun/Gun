program ex;
var a:array[1..500,1..500] of longint;
b,c,p:array[1..500] of longint;
n,x,i,f,r,y,j:longint;

begin
assign(input,'tournament.in'); reset(input);
assign(output,'tournament.out'); rewrite(output);
read(n);
j:=trunc(n*(n-1)div 2)-1;
for i:=1 to j do begin read(x,y); inc(a[x,y]); inc(b[x]); inc(b[y]); end;
for i:=1 to n do if b[i]<>n-1 then begin y:=x; x:=i; end;
fillchar(b,sizeof(b),0);
b[1]:=x;
c[x]:=1;
p[x]:=0;
f:=0;
r:=1;
while f<r do
  begin
  inc(f);
  for i:=1 to n do if a[b[f],i]=1 then
    begin
    if p[i]>p[b[f]]-1 then p[i]:=p[b[f]]-1;
    if c[i]=0 then begin inc(r); b[r]:=i; c[i]:=1; end;
    end;
  end;
if p[x]>p[y] then writeln(x,' ',y) else writeln(y,' ',x);
close(input); close(output);
end.