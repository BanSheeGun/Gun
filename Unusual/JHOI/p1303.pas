var n1:string;
    a,f:array[0..20]of longint;
    n,k,i,j,max,len:longint;
procedure sort(l,r: longint);
var i,j,x,y: longint;
begin
 i:=l; j:=r;
 x:=a[(l+r) div 2];
 repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if not(i>j) then begin
    y:=a[i];a[i]:=a[j];
    a[j]:=y;inc(i);dec(j);
   end;
 until i>j;
 if l<j then sort(l,j);
 if i<r then sort(i,r);
end;
begin
 readln(n1);
 k:=pos(',',n1);
 while k<>0 do
  begin
   inc(n);
   val(copy(n1,1,k-1),a[n]);
   delete(n1,1,k);
   k:=pos(',',n1);
  end;
  inc(n);
  val(n1,a[n]);
 max:=0;
 for i:=1 to n do
  begin
   f[i]:=1;
   for j:=1 to n-1 do
    if (a[i]<a[j])and(f[i]<f[j]+1) then f[i]:=f[j]+1;
   if f[i]>max then max:=f[i];
  end;
 write(max,',');

 max:=1;
 f:=a;
 fillchar(a,sizeof(a),0);
 a[1]:=f[1];
 for i:=2 to n do
  begin
   if f[i]>=a[max] then
    begin
     inc(max);
     a[max]:=f[i];
    end
   else
    begin
     len:=max;
     while (a[len]>f[i])and(len>=1) do dec(len);
      a[len+1]:=f[i];
     sort(1,len+1);
    end;
   end;
 writeln(max-1);
end.
