var f:array[1..5000] of longint;
    n,m,i,p,x,y:longint;
function find(x:longint):longint;
begin
 if x=f[x] then exit(x);
 f[x]:=find(f[x]);
 exit(f[x]);
end;
begin
 read(n,m,p);
 for i:=1 to n do f[i]:=i;
 for i:=1 to m do begin
  read(x,y);
  f[find(x)]:=find(y);
 end;

 for i:=1 to p do begin
  read(x,y);
  if find(x)=find(y) then writeln('Yes')
                     else writeln('No');
 end;
end.