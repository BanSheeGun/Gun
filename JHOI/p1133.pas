var f:array[0..20000] of longint;
    tt:array[0..20000] of boolean;
    x,y,t,m,i,j:longint;
begin
 fillchar(f,sizeof(f),0);
 fillchar(tt,sizeof(tt),false);
 tt[0]:=true;
 read(t,m);
 for i:=1 to m do
  begin
   read(x);
   y:=1;
   for j:=t downto x do
    if tt[j-x] then 
    if f[j]<f[j-x]+y then  begin f[j]:=f[j-x]+y; tt[j]:=true;end;
  end;
  m:=t;
  while f[t]=0 do dec(t);
  writeln(m-t);
end.
