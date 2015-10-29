var f:array[1..10000000] of boolean;
    s,t,i,j:longint;
function pan(k:longint):boolean;
var a:array[1..7] of longint;
    top,sum,i:longint;
begin
 top:=0;
 sum:=k;
 while sum<>0 do begin
  inc(top);
  a[top]:=sum mod 10;
  sum:=sum div 10;
 end;
 f[1]:=false;
 for i:=1 to top do
  if a[i]<>a[top+1-i] then exit(false);
 exit(true);
end;
begin
 fillchar(f,sizeof(f),true);
 read(s,t);
 if t>=10000000 then t:=10000000;
 for i:=2 to t do
  if f[i] then
   for j:=2 to t div i do
    f[j*i]:=false;

 for i:=s to t do
  if f[i] then
  if pan(i) then writeln(i);
end.
