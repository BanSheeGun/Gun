var a:array[0..10000] of longint;
    i,m,n,top,j,k:longint;
begin
 fillchar(a,sizeof(a),0);
 a[1]:=1;top:=1;
 read(m,n);
 for i:=m+1 to m+n do begin
  for j:=top downto 1 do begin
   a[j]:=a[j]*i;
   k:=j;
   while a[k] div 10000>0 do begin
    a[k+1]:=a[k] div 10000+a[k+1];
    a[k]:=a[k] mod 10000;
    inc(k);
   end;
  end;

  while a[top+1]<>0 do inc(top);
 end;
 for i:=1 to n do begin
  for j:=top downto 1 do begin
   a[j-1]:=a[j-1]+a[j] mod i*10000;
   a[j]:=a[j] div i;
  end;
  while a[top]=0 do dec(top);
 end;

 write(a[top]);
 for i:=top-1 downto 1 do begin
  write(a[i] div 1000 mod 10);
  write(a[i] div 100 mod 10);
  write(a[i] div 10 mod 10);
  write(a[i] mod 10);
 end;
 writeln;
end.
