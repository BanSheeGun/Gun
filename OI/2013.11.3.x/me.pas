type fs=record
      x,y:qword;
     end;
var a:array[0..100000] of longint;
    now,ans:fs;
    sum,t:qword;
    n,i,de:longint;
procedure sort(ll,rr:longint);
var i,j,x,t:longint;
begin
 i:=ll;j:=rr;
 x:=a[(ll+rr) div 2];
 repeat
  while (a[i]<x) do inc(i);
  while (x<a[j]) do dec(j);
  if not(i>j) then begin
   t:=a[i];a[i]:=a[j];a[j]:=t;
   inc(i);dec(j);
  end;
 until i>j;
 if ll<j then sort(ll,j);
 if i<rr then sort(i,rr);
end;

function gcd(a,b:qword):qword;
begin
 if a mod b=0 then exit(b);
 exit(gcd(b,a mod b));
end;
begin
 assign(input,'me.in');reset(input);
 assign(output,'me.out');rewrite(output);
 read(n);
 for i:=1 to n do
  read(a[i]);
 sort(1,n);
 sum:=0;
 for i:=2 to n do sum:=sum+a[i]-a[1];
 t:=gcd(sum,n);
 ans.x:=sum div t;ans.y:=n div t;
 for i:=2 to n do begin
  de:=a[i]-a[i-1];
  sum:=sum+(i-1)*de-(n-i+1)*de;
  t:=gcd(sum,n);
  now.x:=sum div t;now.y:=n div t;
  t:=gcd(now.y,ans.y);
  ans.x:=(ans.x*now.y+now.x*ans.y) div t;
  ans.y:=now.y*ans.y div t;
  t:=gcd(ans.x,ans.y);
  ans.x:=ans.x div t;
  ans.y:=ans.y div t;
 end;
 sum:=0;
 for i:=1 to n do sum:=sum+abs(a[i]);
 t:=gcd(sum,n);
 now.x:=sum div t;now.y:=n div t;
 t:=gcd(now.y,ans.y);
 ans.x:=(ans.x*now.y+now.x*ans.y) div t;
 ans.y:=now.y*ans.y div t;
 t:=gcd(ans.x,ans.y);
 ans.x:=ans.x div t;
 ans.y:=ans.y div t;

 writeln(ans.x,' ',ans.y);
 close(input);close(output);
end.
