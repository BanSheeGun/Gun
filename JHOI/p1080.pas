var a,b,c:longint;
    f:array[0..20,0..20,0..20] of longint;
function d(a,b,c:longint):longint;
begin
 if (a<=0)or(b<=0)or(c<=0) then exit(1);
 if (a>20)or(b>20)or(c>20) then exit(d(20,20,20));
 if f[a][b][c]>0 then exit(f[a][b][c]);
 if (a<b)and(b<c) then f[a][b][c]:=d(a,b,c-1)+d(a,b-1,c-1)-d(a,b-1,c)
  else f[a][b][c]:=d(a-1,b,c)+d(a-1,b-1,c)+d(a-1,b,c-1)-d(a-1,b-1,c-1);
 exit(f[a][b][c]);
end;
begin
 read(a,b,c);
 fillchar(f,sizeof(f),0);
 while not((a=-1)and(b=-1)and(c=-1)) do
  begin
   writeln('w(',a,', ',b,', ',c,') = ',d(a,b,c));
   read(a,b,c);
  end;
end.
