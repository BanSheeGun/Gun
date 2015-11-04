var i,j,x,y,n:longint;
    t:array[0..100] of longint;
    a:array[0..100,0..100] of boolean;
procedure endit;
begin
close(input);
close(output);
halt;
end;
begin
assign(input,'tournament.in');
reset(input);
assign(output,'tournament.out');
rewrite(output);
read(n);
for i:=1 to (n-1)*n div 2-1 do
    begin
    read(x,y);
    a[x,y]:=true;
    a[y,x]:=false;
    inc(t[x]);
    inc(t[y]);
    end;
for i:=1 to n do
    if t[i]=n-2 then break;
for j:=i+1 to n do
    if t[j]=n-2 then break;
x:=i;
y:=j;
for i:=1 to n do
    begin
    if (i=x)or(i=y) then continue;
    if (a[x,i]=true)and(a[i,y]=true) then begin
                                    writeln(x,' ',y);
                                    endit;
                                    end;
    if (a[x,i]=false)and(a[i,y]=false) then begin
                                     writeln(y,' ',x);
                                     endit;
                                     end;
    end;
writeln(x,' ',y);
endit;
end.