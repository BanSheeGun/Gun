var k,i,n:longint;
    b,hash,x,y:array[1..10000]of longint;
    a:array[1..10000,1..10000]of longint;
begin
assign(input,'tournament.in');
reset(input);
assign(output,'tournament.out');
rewrite(output);
readln(n);
for i:=1 to n do
  a[i,i]:=0;
for i:=1 to n*(n-1) div 2-1 do
begin
 readln(x[i],y[i]);
 inc(hash[x[i]]);inc(hash[y[i]]);
 a[x[i],y[i]]:=1;
 a[y[i],x[i]]:=-1;

end;
k:=0;
for i:=1 to n do
  if hash[i]<>n-1 then begin inc(k);b[k]:=i;end;
for i:=1 to n do
   begin
    if (a[b[1],i]=1)and(a[i,b[2]]=1) then begin
    writeln(b[1],' ',b[2]);close(input);close(output);exit;end;
    if (a[b[1],i]=-1)and(a[i,b[2]]=-1) then begin
    writeln(b[2],' ',b[1]);close(input);close(output);exit;end;
   end;
writeln(b[1],' ',b[2]);
close(input);
close(output);
end.
