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
procedure sort(l,r:longint);
var t:longint;
begin
 if a[l]>a[r] then begin t:=a[l];a[l]:=a[r];a[r]:=t; end;
end;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
function jy(x,y,z,a:longint):longint;
begin
 jy:=x*a*a+y*a+z;
end;
procedure fh(var a,b,c,l,r:longint);
procedure doit(x,y,z:longint);
var k,l,sum,wz,s2:longint;
begin
 l:=-(y div (2*x));
 sum:=0;
 if l<=0 then l:=1;
 k:=x*sqr(l)+y*(l)+z;
 if k>a[m] then exit;
 a[m]:=k;
 wz:=m-1; s2:=1;
 sort(wz,wz+1);
 while (a[wz]=k)and(wz>1) do
  begin dec(wz); sort(wz,wz+1);end;
 sum:=-1;
 while (jy(x,y,z,l+sum)<a[m]) do begin
  if (sum+l=0)or(s2=m div 2) then break;
  k:=jy(x,y,z,l+sum);
  if k>a[m] then exit;
  a[m]:=k;
  wz:=m-1;
  sort(wz,wz+1);
  while (a[wz]=k)and(wz>1) do begin sort(wz,wz+1);dec(wz);end;
  dec(sum);
  inc(s2);
 end;

 sum:=1;
 while (jy(x,y,z,l+sum)<a[m])and(sum<=m div 2) do begin
  k:=jy(x,y,z,l+sum);
 if k>a[m] then exit;
  a[m]:=k;
  wz:=m-1;
  sort(wz,wz+1);
  while (a[wz]=k)and(wz>1) do
   begin dec(wz);sort(wz,wz+1);end;
  inc(sum);
  inc(s2);
  if (s2=m) then break;
 end;
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
