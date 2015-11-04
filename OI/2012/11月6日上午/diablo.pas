var f:array[0..5000] of longint;
    a:array[0..5000,1..100] of longint;
    c:longint;
    w:array[1..500] of longint;
    m,p,n,i,j,k:longint;
begin
 assign(input,'diablo.in');reset(input);
 assign(output,'diablo.out');rewrite(output);
 read(n,m);
 for i:=1 to n do begin
  read(c,p);
  for j:=1 to p do read(w[j]);

  for j:=m downto c do
   for k:=1 to p do
    if j-k*c>=0 then
     if f[j]<f[j-k*c]+w[k] then begin
      f[j]:=f[j-k*c]+w[k];
      a[j]:=a[j-k*c];
      a[j][i]:=k;
     end;
 end;

 writeln(f[m]);
 for c:=1 to m do if f[c]=f[m] then break;
 for i:=1 to n do writeln(a[m][i]);
 close(input);close(output);
end.
