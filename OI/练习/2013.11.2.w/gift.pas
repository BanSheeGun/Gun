var f:array[0..300,0..2,0..550] of longint;
    a,b,n,i,j,l,w,v,d,ans:longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
begin
 assign(input,'gift.in');reset(input);
 assign(output,'gift.out');rewrite(output);
 read(a,b,n);
 fillchar(f,sizeof(f),0);
 l:=0;
 for i:=1 to n do begin
  read(w,v,d);
  for j:=a+b downto w do begin
   f[i][1][j]:=max(f[i][1][j],f[i-1][1][j-w]+v);
   f[i][1][j]:=max(f[i][1][j],f[i-1][2][j-w]+v);
   f[i][2][j]:=max(f[i][2][j],f[i-1][1][j-w]+v);
   f[i][2][j]:=max(f[i][2][j],f[i-1][2][j-w]+v);
   f[i][0][j]:=max(f[i][0][j],f[i-1][1][j-w]);
   f[i][0][j]:=max(f[i][0][j],f[i-1][2][j-w]);
  end;
  if l=0 then begin
   f[i][1][j]:=max(f[i][1][j],f[i-1][0][j-w]+v);
   f[i][2][j]:=max(f[i][2][j],f[i-1][0][j-w]+v);
   f[i][0][j]:=max(f[i][0][j],f[i-1][0][j-w]);
  end;
  l:=d;
 end;
 ans:=max(f[n][1][a],f[n][2][b]);
 writeln(ans);
 close(input);close(output);
end.
