var f:array[-1..20010] of longint;
    t1:array[0..20010] of boolean;
    a:array[0..101] of longint;
    l,min,s,t,m,k,i,j:longint;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
 i:=l;j:=r;
 x:=a[(l+r)div 2];
 repeat
  while a[i]<x do inc(i);
  while x<a[j] do dec(j);
  if i<=j then begin
   y:=a[i];a[i]:=a[j];a[j]:=y;
   inc(i);dec(j);
  end;
 until i>j;
 if i<r then sort(i,r);
 if j>l then sort(l,j);
end;
begin
 fillchar(f,sizeof(f),63);
 read(l);
 read(s,t,m);
 for i:=1 to m do
  read(a[i]);
 a[0]:=0;
 a[m+1]:=l;
 fillchar(t1,sizeof(t1),false);
 if s=t then begin
  min:=0;
  for i:=1 to m do
   if a[i] mod s=0 then inc(min);
 end
 else begin
  sort(0,m+1);
  for i:=0 to m do
   if a[i+1]-a[i]>200 then begin
    k:=a[i+1]-a[i]-200;
    for j:=i+1 to m+1 do dec(a[j],k);
   end;
  f[0]:=0;
  for i:=1 to m do t1[a[i]]:=true;
  for i:=0 to a[m+1] do
   if f[i]<>f[-1] then
    for j:=s to t do
     if t1[i+j] then    begin
     if f[i]+1<f[i+j] then f[i+j]:=f[i]+1;
     end
     else begin
     if f[i]<f[i+j] then f[i+j]:=f[i];
     end;

 min:=maxlongint;
 for i:=a[m+1] to a[m+1] + t do
  if min>f[i] then min:=f[i];
 end;
 writeln(min);
end.
