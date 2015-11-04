var i,j,n,x,y,zuo,you:longint;
    a:array[1..50,1..50] of longint;
    chu:array[1..50] of longint;
procedure kai;
begin
assign(input,'tournament.in');
assign(output,'tournament.out');
reset(input);
rewrite(output);
end;
procedure guan;
begin
close(input);
close(output);
end;
procedure try(shu:longint);
var i,j:longint;
begin
for i:=1 to n do
if a[shu,i]<>shu then if a[shu,i]=you then begin writeln(you,' ',zuo);guan;halt;end
                                      else try(a[shu,i]);
end;
begin
kai;
readln(n);
for i:=1 to n*(n-1) div 2-1 do
begin
readln(x,y);
a[x,y]:=x;
a[y,x]:=x;
inc(chu[x]);inc(chu[y]);
end;
for i:=1 to n do
if chu[i]=n-2 then begin zuo:=i;break;end;
for j:=i+1 to n do
if chu[j]=n-2 then begin you:=j;break;end;
for i:=1 to n do
if a[zuo,i]<>i then try(a[zuo,i]);
writeln(zuo,' ',you);
guan;
end.
