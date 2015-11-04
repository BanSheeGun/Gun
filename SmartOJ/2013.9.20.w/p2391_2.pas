var n,i,w,ans,k:int64;
function max(a,b:int64):int64;
begin
 if a>b then exit(a);
 exit(b);
end;
begin
 read(n,w);
 read(ans);
 while ans=w do read(ans);
 while not seekeof do begin
  read(k);
  if abs(w-ans)>abs(w-k) then ans:=k
  else  if abs(w-ans)=abs(w-k) then ans:=max(ans,k)
 end;
 writeln(ans);
end.
