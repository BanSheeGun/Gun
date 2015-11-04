var a:array[1..20000] of longint;
    x,y,z,i,m,n,l,top:longint;
procedure sort1(l,r:longint);
var i,j,m,t:longint;
begin
 i:=l;j:=r;
 m:=a[(l+r) div 2];
 repeat
  while a[i]<m do inc(i);
  while m<a[j] do dec(j);
  if i<=j then begin
   t:=a[i];a[i]:=a[j];a[j]:=t;
   inc(i);dec(j);
  end;
 until i>j;
 if i<r then sort1(i,r);
 if l<j then sort1(l,j);
end;
begin
 assign(input,'minval.in');reset(input);
 assign(output,'minval.out');rewrite(output);
 read(n,m);
 read(x,y,z);
 l:=-(y div (2*x));
 if l<=0 then l:=1;
 top:=0;
 for i:=max(1,l-m div 2) to l+m do begin
  inc(top);
  a[top]:=x*i*i+y*i+z;
  if top=m then break;
 end;
 sort1(1,m);

 for i:=1 to n-1 do begin
  read(x,y,z);
  doit(x,y,z);
 end;

 for i:=1 to m-1 do
  write(a[i],' ');
 writeln(a[m]);

 close(input);close(output);
end.
