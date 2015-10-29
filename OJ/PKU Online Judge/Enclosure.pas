var n,l,r,mid:qword;
begin
 while not seekeof do begin
  read(n);
  l:=trunc(sqrt(n)*2)-1;
  r:=trunc(sqrt(n)*2)+10;
  while l+1<r do begin
   mid:=(l+r)>>1;
   if mid*mid<=n*4 then l:=mid
   else r:=mid;
  end;
  if l*l>=n*4 then writeln(2*l)
  else writeln(2*r);
 end;
end.
