var x,y,i,n,k,j:longint;
    a:array[1..100,1..100]of longint;
begin
assign(input,'tournament.in');
assign(output,'tournament.out');
reset(input);
rewrite(output);
readln(n);
for i:=1 to n-1 do
    begin
    readln(x,y);
    a[x,y]:=1;
    end;
for i:=1 to n do
    for j:=1 to n do
        for k:=1 to n do
            if (a[i,j]=1)and(a[j,k]=1)and(a[i,k]=0)then writeln(i,'',k);
close(input);
close(output);
end.