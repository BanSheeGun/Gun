var sum,n,i,a,b,c:longint;
    ans:extended;
begin
 while not seekeof do begin
  read(n);
  read(a);
  b:=a;c:=a;
  sum:=a;
  for i:=2 to n do begin
   read(a);
   sum:=sum+a;
   if a>b then b:=a;
   if a<c then c:=a;
  end;
  sum:=sum-b-c;
  ans:=sum/(n-2);
  writeln(ans:0:2);
 end;
end.
