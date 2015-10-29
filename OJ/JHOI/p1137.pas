var t:array[1..50000] of boolean;
    a:array[1..25000] of longint;
    n,m,i,j,x,y,l,k,w,z:longint;
function gcd(m,n:longint):longint;
begin
 if m mod n=0 then exit(n);
 exit(gcd(n,m mod n));
end;
begin
 read(n,m);
 
 fillchar(t,sizeof(t),true);
 for i:=2 to n do
  if t[i] then 
   for j:=2 to n div i do
    t[j]:=false;

 x:=n-m;
 if x>m then y:=m
  else begin
   y:=x;
   x:=m;
  end;

 for i:=x+1 to n do
  a[i-x]:=i;
 l:=n-x;

 for i:=2 to y do begin
  k:=i;w:=1;
  while k<>1 do begin
   z:=gcd(a[w],k);
   k:=k div z;
   a[w]:=a[w] div z;
   inc(w);
  end; 
 end;
end.