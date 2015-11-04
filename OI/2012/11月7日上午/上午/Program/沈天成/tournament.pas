var a,b:array[0..100]of longint;
    i,j,m,n,t1,t2,p,q:longint;
begin
assign(input,'tournament.in');reset(input);
assign(output,'tournament.out');rewrite(output);
readln(n);
for i:=1 to n*(n-1)div 2-1 do
 begin readln(t1,t2);inc(a[t1]);inc(a[t2]);inc(b[t1]);end;

for i:=1 to n do if a[i]<n-1 then
 if p=0 then p:=i else q:=i;
if b[p]>b[q] then writeln(p,' ',q) else writeln(q,' ',p);
close(input);close(output);
end.