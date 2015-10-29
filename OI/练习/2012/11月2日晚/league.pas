var a,b:array[0..50] of longint;
    ch:char;
    k,i,n,j,max:longint;
procedure sort(l,r:longint);
var i,j,x,y,z:longint;
begin
 i:=l;j:=r;
 x:=a[(l+r) div 2];
 z:=b[(l+r) div 2];
 repeat
  while (a[i]>x)or(b[i]<z)and(a[i]=x) do inc(i);
  while (x>a[j])or(z<b[j])and(a[j]=x) do dec(j);
  if i<=j then begin
   y:=a[i];a[i]:=a[j];a[j]:=y;
   y:=b[i];b[i]:=b[j];b[j]:=y;
   inc(i);dec(j);
  end;
 until i>j;
 if i<r then sort(i,r);
 if l<j then sort(l,j);
end;
begin
 assign(input,'league.in');reset(input);
 assign(output,'league.out');rewrite(output);
 readln(n);
 for i:=1 to n do begin
  for j:=1 to n do begin
   read(ch);
   if ch='W' then inc(a[i],3);
   if ch='D' then inc(a[i],1);
   if ch='D' then inc(a[j],1);
   if ch='L' then inc(a[j],3);
  end;
  readln;
  b[i]:=i;
 end;

 sort(1,n);
 write(b[1]);k:=2;
 while (a[k]=a[1])and(k<=n) do begin write(' ',b[k]);inc(k);end;
 writeln;
 close(input);close(output);
end.
