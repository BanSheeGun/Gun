var m,ans,i,j,n:longint;
begin
 read(n);
 m:=1;read(ans);
 for i:=2 to n do begin
  read(j);
  if j>ans then begin
   ans:=j;
   m:=i;
  end;
 end;
 writeln(ans,' ',m);
end.