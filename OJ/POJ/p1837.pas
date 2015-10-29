var fl,f:array[-8000..8000] of longint;
    a:array[1..100] of longint;
    n,m,i,j,k,ww,w:longint;
begin
 read(n,m);
 for i:=1 to n do
  read(a[i]);
 fillchar(f,sizeof(f),0);
 f[0]:=1;
 for i:=1 to m do begin
  fl:=f;
  fillchar(f,sizeof(f),0);
  read(w);
  for j:=1 to n do begin
   ww:=w*a[j];
   for k:=-7500 to 7500 do
    inc(f[k],fl[k-ww]);
  end;
 end;
 writeln(f[0]);
end.
