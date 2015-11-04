var n,i,w,ans,k:longint;
begin
 read(n,w);
 read(ans);
 for i:=2 to n do begin
  read(k);
  if abs(w-ans)>abs(w-k) then ans:=k;
 end;
 writeln(ans);
end.
