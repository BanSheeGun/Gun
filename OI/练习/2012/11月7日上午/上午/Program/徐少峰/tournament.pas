var n,m,i,j,a,b,k:longint;
    g:array[1..50,1..50]of boolean;
    d:array[1..50]of longint;

begin
assign(input,'tournament.in');reset(input);
assign(output,'tournament.out');rewrite(output);
fillchar(g,sizeof(g),0);
fillchar(d,sizeof(d),0);
read(n);
for i:=1 to n*(n-1)shr 1-1 do
 begin
  read(a,b);
  g[a,b]:=true;
  inc(d[a]);inc(d[b]);
 end;

for i:=1 to n do
 if d[i]=n-2 then
  begin
   a:=i;
   break;
  end;

for j:=i+1 to n do
 if d[j]=n-2 then
  begin
   b:=j;
   break;
  end;

for k:=1 to n do
 for i:=1 to n do
  for j:=1 to n do
   begin
    if (i=j)or(i=k)or(j=k) then continue;
    g[i,j]:=g[i,j] or g[i,k] and g[k,j];
   end;

if g[a,b] then writeln(a,' ',b)
          else writeln(b,' ',a);
close(input);close(output);
end.
