program tournament;

var i,j,tot,n,p,q,t1,t2:longint;
    pd:array[0..100,0..100] of boolean;
    x,y:array[0..100] of longint;

procedure setup;
begin
assign(input,'tournament.in'); assign(output,'tournament.out');
reset(input); rewrite(output);
end;

procedure endit;
begin
close(input); close(output);
end;

begin
setup;
readln(n);
tot:=(n*(n-1)) div 2;
fillchar(pd,sizeof(pd),false);
for i:=1 to tot-1 do
    begin
    readln(x[i],y[i]);
    pd[x[i],y[i]]:=true; pd[y[i],x[i]]:=true;
    end;
for i:=1 to n do
    for j:=i+1 to n do
        if not pd[i,j] then begin p:=i; q:=j; break; end;
for i:=1 to tot-1 do
    begin
    if x[i]=p then inc(t1);
    if x[i]=q then inc(t2);
    end;
if t1>t2 then writeln(p,' ',q)
         else writeln(q,' ',p);
endit;
end.

