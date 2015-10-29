var v,t,num:array[0..1000]of longint;
    f:array[-10000..10000]of longint;
    n,m,i,j,typ,which,temp:longint;

procedure kai;
begin
assign(input,'pack.in');reset(input);
assign(output,'pack.out');rewrite(output);
end;
procedure guan;
begin
close(input);close(output);
end;

begin
kai;
readln(n,m);
temp:=n;
while i<=n do
    begin
    read(typ);
    if typ=1 then begin readln(v[0],t[0]);dec(temp);inc(i)end;
    if typ=2 then readln(v[i],t[i],num[i]);
    if typ=3 then begin readln(v[i],t[i]);num[i]:=maxlongint;end;
    inc(i);
    end;
n:=temp;
f[0]:=0;
for i:=1 to m do
    begin
    f[i]:=f[i-1];
    for j:=1 to n do
        if(num[j]>=1)and(i-t[j]>=0)and(f[i-t[j]]+v[j]>f[i])
          then begin f[i]:=f[i-t[j]]+v[j];which:=j;end;
    dec(num[which]);
    end;
writeln(f[m]);
guan;
end.
