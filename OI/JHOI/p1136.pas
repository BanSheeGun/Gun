const n1=1500001;
var f:array[0..1500001,0..5] of int64;
    p:array[1..17] of longint;
    n,i,j,ls:longint;
procedure plus(a,b:longint);
var l,i:longint;
begin
 if f[a][0]>f[b][0] then l:=f[a][0] else l:=f[b][0];

 for i:=1 to l do begin
  f[a][i]:=f[a][i]+f[b][i];
  f[a][i+1]:=f[a][i+1]+f[a][i] div 100000000000000000;
  f[a][i]:=f[a][i] mod 100000000000000000;
 end;

 if f[a][l+1]<>0 then f[a][0]:=l+1
                 else f[a][0]:=l;
end;
begin
 ls:=0;
 while not seekeof do
  begin
 readln(n);
 f[0][1]:=1;f[0][0]:=1;
 n:=n div 2;
 for i:=ls+1 to n do
  begin
   plus(i,i-1);
   plus(i,i div 2);
  end;
 f[n1]:=f[n];
 write(f[n1][f[n1][0]]);
 for i:=f[n1][0]-1 downto 1 do begin
  for j:=17 downto 1 do begin
   p[j]:=f[n1][i] mod 10;
   f[n1][i]:=f[n1][i] div 10;
  end;
  for j:=1 to 17 do write(p[j]);
 end;
 writeln;
 if n>ls then ls:=n;
 end;
end.
