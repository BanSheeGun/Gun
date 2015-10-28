var i,n,m:longint;
    ans,t:extended;
begin
 while not seekeof do begin
  ans:=0;
  read(n,m);
  t:=n;
  for i:=1 to m do begin
   ans:=ans+t;
   t:=sqrt(t);
  end;
  writeln(ans:0:2);
 end;
end.