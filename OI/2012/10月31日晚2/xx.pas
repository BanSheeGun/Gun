var n,l,r,mid:qword;
    k:extended;
begin
 assign(input,'xx.in');reset(input);
 assign(output,'xx.out');rewrite(output);
 read(n);
 l:=1;r:=n+1;
 while l<r-1 do begin
  mid:=(l+r) div 2;
  k:=1+mid*ln(mid)/ln(10);
  if k>=n then r:=mid
            else l:=mid;
 end;
 if n=1 then writeln(1) else
 writeln(r);
 close(input);close(output);
end.
