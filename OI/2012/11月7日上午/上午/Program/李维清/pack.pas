var n,m,i,j,x,a,b,c,ans:longint;
    t:array[0..10001]of longint;
    z,jz:array[1..3,0..10001]of longint;
    f:array[0..3001]of longint;
begin
assign(input,'pack.in');
assign(output,'pack.out');
reset(input);
rewrite(output);
readln(n,m);
for i:=1 to n do
    begin
    read(x);
    if x=1 then readln(a,b)
           else if x=2 then begin readln(a,b,c);for j:=1 to c do
                                  begin inc(t[x]);jz[x,t[x]]:=a;
                                  z[x,t[x]]:=b;
                                  end
                            end
                       else begin
                            readln(a,b);inc(t[x]);jz[x,t[x]]:=a;
                            z[x,t[x]]:=b;
                            end;
    end;
for j:=1 to t[3] do
    for i:=z[3,j] to m do
        if i>=z[3,j] then if f[i-z[3,j]]+jz[3,j]>f[i] then
                         f[i]:=f[i-z[3,j]]+jz[3,j];
for j:=1 to t[2] do
        for i:=m downto z[2,j] do
        if i>=z[2,j] then if f[i-z[2,j]]+jz[2,j]>f[i] then
                            f[i]:=f[i-z[2,j]]+jz[2,j];
ans:=0;
for i:=1 to m do if f[i]>ans then ans:=f[i];
writeln(ans);
close(input);
close(output);
end.
