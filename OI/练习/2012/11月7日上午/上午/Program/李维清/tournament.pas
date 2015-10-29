var n,i,j,x,y:longint;
    v:array[0..51,0..51]of boolean;
begin
assign(input,'tournament.in');
assign(output,'tournament.out');
reset(input);
rewrite(output);
fillchar(v,sizeof(v),false);
readln(n);
for i:=1 to n*(n-1)div 2-1 do
    begin
    readln(x,y);
    v[x,y]:=true;
    v[y,x]:=true;
    end;
for i:=n downto 2 do
    for j:=i-1 downto 1 do
        if not v[i,j] then begin writeln(i,' ',j);close(input);close(output);halt;end;
end.
