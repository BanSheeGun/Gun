var a:array[1..1500001] of longint;
    n,i,j,x:longint;
    ans:qword;

function find(l,r,x:longint):longint;
var mid:longint;
begin
 mid:=(l+r) div 2;
 if l=r then exit(l);
 if x<a[mid] then exit(find(l,mid,x))
 else exit(find(mid+1,r,x));
end;

begin
 assign(input,'a.in');reset(input);
 assign(output,'a.out');rewrite(output);
 read(n);
 ans:=0;
 for i:=1 to n do read(a[i]);
 a[n+1]:=maxlongint;
 for i:=1 to n do begin
  read(x);
  ans:=ans+n+1-find(1,n+1,x);
 end;
 writeln(ans);
 close(input);close(output);
end.
