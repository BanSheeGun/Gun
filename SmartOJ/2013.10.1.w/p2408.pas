var a:array[0..1000000] of int64;
    n,i,j,k,top:longint;
begin
 read(n);
 top:=1;
 a[top]:=1;

 for j:=2 to n do begin
  k:=4*j-2;
  for i:=1 to top do a[i]:=a[i]*k;
  for i:=1 to top do begin
   a[i+1]:=a[i+1]+a[i] div 1000000;
   a[i]:=a[i] mod 1000000;
  end;
  while a[top+1]<>0 do inc(top);
  k:=j+1;
  for i:=top downto 1 do begin
   a[i-1]:=a[i-1]+a[i] mod k*1000000;
   a[i]:=a[i] div k;
  end;
  while a[top]=0 do dec(top);
 end;

 write(a[top]);
 for i:=top-1 downto 1 do begin
  write(a[i] div 100000 mod 10);
  write(a[i] div 10000 mod 10);
  write(a[i] div 1000 mod 10);
  write(a[i] div 100 mod 10);
  write(a[i] div 10 mod 10);
  write(a[i] mod 10);
 end;
 writeln;
end.
