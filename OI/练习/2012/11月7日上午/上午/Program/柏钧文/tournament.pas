var n,i,j,k,tot:longint;
        f:array[0..100,0..100]of boolean;
        ci,a,b:array[0..100000]of longint;
        aa:array[0..100]of longint;
begin
assign(input,'tournament.in');
reset(input);
assign(output,'tournament.out');
rewrite(output);
readln(n);
fillchar(f,sizeof(f),false);
for i:=1 to (n*(n-1) div 2)-1 do
        begin
        readln(a[i],b[i]);
        f[a[i],b[i]]:=true;
        inc(ci[a[i]]);inc(ci[b[i]]);
        end;
for k:=1 to n do
    for i:=1 to n do
        for j:=1 to n do
            if (i<>j)and(j<>k)and(i<>k) then
            if (f[i,k])and(f[k,j])and(not f[i,j]) then
            f[i,j]:=true;
tot:=0;
for i:=1 to n do
        if ci[i]<n-1 then
        begin
        inc(tot);
        aa[tot]:=i;
        end;
if f[aa[1],aa[2]] then writeln(aa[1],' ',aa[2])
                else if f[aa[2],aa[1]] then writeln(aa[2],' ',aa[1])
                                else writeln(aa[1],' ',aa[2]);
close(input);close(output);
end.