var n,m,i,j,k,sum:longint;
        f:array[0..10000]of longint;
        a,b,c,tip:array[0..10000]of longint;
begin
assign(input,'pack.in');
reset(input);
assign(output,'pack.out');
rewrite(output);
readln(n,m);
for i:=1 to n do
        begin
        read(tip[i]);
        if tip[i]=1 then readln(a[i],b[i]);
        if tip[i]=2 then readln(a[i],b[i],c[i]);
        if tip[i]=3 then readln(a[i],b[i]);
        end;
f[0]:=0;
for i:=1 to n do
        begin
        if tip[i]=1 then
           for j:=m downto 0 do
                begin
                for k:=0 to m do
                if j-k<0 then break
                        else
                        if f[j-k]+a[i]*k*k-b[i]*k>f[j] then
                        f[j]:=f[j-k]+a[i]*k*k-b[i]*k;
                end;
        if tip[i]=2 then
                for j:=m downto 0 do
                    for k:=0 to c[i] do
                    if j-k*b[i]<0 then break
                        else
                    if f[j-k*b[i]]+k*a[i]>f[j] then
                    f[j]:=f[j-k*b[i]]+k*a[i];
        if tip[i]=3 then
                for j:=0 to m do
                    if j-b[i]>=0 then
                    if f[j-b[i]]+a[i]>f[j] then
                    f[j]:=f[j-b[i]]+a[i];
        end;
sum:=0;
for i:=0 to m do
        if f[i]>sum then sum:=f[i];
writeln(sum);
close(input);close(output);
end.
