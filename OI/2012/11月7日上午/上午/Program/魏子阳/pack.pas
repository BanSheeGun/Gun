var n,m:longint;
    i,kind:longint;
    sum,a,b,c:longint;

begin
assign(input,'pack.in');
assign(output,'pack.out');
reset(input);
rewrite(output);
readln(n,m);
sum:=0;
for i:=1 to n do
    begin
    read(kind);
    if kind=1 then readln;
    if kind=2 then begin read(a,b,c);if a<>1 then sum:=sum+a*c;readln;end;
    if kind=3 then begin read(a,b);if a<>1 then sum:=sum+a*b;readln;end;
    end;
writeln(sum);
close(input);
close(output);
end.
