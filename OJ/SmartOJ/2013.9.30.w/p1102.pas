var n,k,i,z,j:longint;
    ans,t:int64;
begin
 read(n);
 for z:=1 to n do begin
  read(k);
  ans:=0;
  t:=1;
  while k<>0 do begin
   if k mod 2=1 then ans:=ans+t;
   t:=t*3;
   k:=k div 2;
  end;
  writeln(ans);
 end;
end.
