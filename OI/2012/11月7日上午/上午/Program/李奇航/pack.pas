program pack;

var f:array[0..10000] of longint;
    x,n,m,a,b,c,i,j,k:longint;

procedure setup;
begin
assign(input,'pack.in'); assign(output,'pack.out');
reset(input); rewrite(output);
end;

procedure endit;
begin
close(input); close(output);
end;

begin
setup;
readln(n,m);
f[0]:=0;
for i:=1 to n do
    begin
    read(x);
    if x=1 then begin
                read(a,b); readln;
                end;
    if x=2 then begin
                read(a,b,c); readln;
                for j:=m-b downto 0 do
                    for k:=1 to c do
                        if f[j+k*b]<f[j]+k*a then f[j+k*b]:=f[j]+k*a;
                end;
    if x=3 then begin
                read(a,b); readln;
                j:=0;
                while j+b<=m do
                      begin
                      if f[j+b]<f[j]+a then f[j+b]:=f[j]+a;
                      inc(j);
                      end;
                end;
    end;
writeln(f[m]);
endit;
end.

