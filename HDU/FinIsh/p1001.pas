var ans,n:int64;
begin
 while not eof do begin
  readln(n);
  if n mod 2=1 then begin
    ans:=(n+1) div 2;
    ans:=ans*n;
  end;
  if n mod 2=0 then begin
    ans:=n div 2;
    ans:=ans*(n+1);
  end;
  writeln(ans);
  writeln;
 end;
end.
