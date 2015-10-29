var ans,l,r,mid,n:longint;
function check(x:longint):boolean;
var k:extended;
begin
 k:=x*ln(x)/ln(10);
 if k>=n-1 then exit(true);
 exit(false);
end;
begin
 read(n);
 l:=1;
 r:=maxlongint-1;
 while l+1<r do begin
  mid:=(l+r) div 2;
  if check(mid) then r:=mid
                else l:=mid;
 end;
 if check(l) then ans:=l
             else ans:=r;
 writeln(ans);
end.
