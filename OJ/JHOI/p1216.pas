var i,ans,s1,s2,n:longint;
    sum,sum2:int64;
begin
 ans:=0;
 read(s1,s2);
 for n:=s1 to s2 do begin
 sum:=-n;
  for i:=1 to trunc(sqrt(n)) do
   if n mod i=0 then sum:=sum+i+n div i;
  if trunc(sqrt(n))=sqrt(n) then sum:=sum-trunc(sqrt(n));

 if (sum>n) then begin
  sum2:=-sum;
  for i:=1 to trunc(sqrt(sum)) do
   if sum mod i=0 then sum2:=sum2+i+sum div i;
  if trunc(sqrt(sum))=sqrt(sum) then sum2:=sum2-trunc(sqrt(sum));
  if sum2=n then inc(ans);
 end;
 end;
 writeln(ans);
end.
