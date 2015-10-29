var n,s,i,x,y,j,t:longint;
    h,l:array[0..55]of longint;
    a:array[1..50,1..50]of longint;

procedure kai;
begin
assign(input,'tournament.in');reset(input);
assign(output,'tournament.out');rewrite(output);
end;
procedure guan;
begin
close(input);close(output);
end;

begin
kai;
readln(n);
for i:=1 to n*(n-1)div 2-1 do
    begin
    readln(x,y);
    inc(h[x]);inc(h[y]);
    a[x,y]:=x;
    a[y,x]:=x;
    end;
for i:=1 to n do
    begin
    if h[i]<>n-1 then begin y:=x;x:=i;end;
    l[i]:=i;
    end;
a[x,y]:=-1;
for i:=1 to n-1 do
    for j:=i+1 to n do
        if a[l[i],l[j]]<>-1
           then if a[l[i],l[j]]=l[j]
                   then begin t:=l[i];l[i]:=l[j];l[j]:=t;end;

for i:=1 to n do
    begin
    if l[i]=x then begin writeln(x,' ',y);guan;exit;end;
    if l[i]=y then begin writeln(y,' ',x);guan;exit;end;
    end;
writeln(x,' ',y);
guan;
end.
