var a:array[1..500000] of longint;
    i,n,k,m,x,y:longint;
    ans:qword;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
 i:=l;j:=r;
 x:=a[(l+r) div 2];
 repeat
  while a[i]<x do inc(i);
  while x<a[j] do dec(j);
  if i<=j then begin
   y:=a[i];a[i]:=a[j];a[j]:=y;
   inc(i);dec(j);
  end;
 until i>j;
 if i<r then sort(i,r);
 if l<j then sort(l,j);
end;
begin
 assign(input,'box.in');reset(input);
 assign(output,'box.out');rewrite(output);
 read(n,k,m);
 for i:=1 to k do begin
  read(x,y);
  if (y=0) then inc(m);

  if y=0 then a[i]:=n-x
         else a[i]:=n+x-2;
 end;
 sort(1,k);

 ans:=int64((m-1) div k)*(2*(n-1));
 ans:=ans+a[m-(m-1) div k*k];
 writeln(ans);
 close(input);close(output);
end.
