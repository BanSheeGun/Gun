var f:array[0..1000,0..1000] of longint;
    s:ansistring;    
    n,m,i,j:longint;
fucntion min(a,b:longint):longint;
begin
 if a<b then exit(a);
 exit(b);
end;
begin
 readln(n,m);
 fillchar(f,sizeof(f),0);
 for i:=1 to n do begin 
  readln(s);
  for j:=1 to m do 
   if s[i*2-1]='F' then begin
    f[i][j]:=min(f[i-1][j-1],f[i-1][j]);
    f[i][j]:=min(f[i][j][f[i][j-1]);
    inc(f[i][j]);
  end;
 end;
 writeln(f[i][j]*f[i][j]*3);
end.