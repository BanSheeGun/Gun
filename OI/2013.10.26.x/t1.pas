var a,b:array[1..100000] of longint;
    n,m,l,r,mi,sum,i:longint;
function min(a,b:longint):longint;
begin
 if a>b then exit(b);
 exit(a);
end;
function max(a,b:longint):longint;
begin
 if a<b then exit(b);
 exit(a);
end;

function check(x:longint):boolean;
var top,i:longint;
begin
 top:=1;
 fillchar(b,sizeof(b),0);
 for i:=1 to n do begin
  if b[top]+a[i]>x then inc(top);
  inc(b[top],a[i]);
  if top>m then exit(false);
 end;
 exit(true);
end;
function find(l,r:longint):longint;
var mid:longint;
begin
 if l=r then exit(l);
 mid:=(l+r)>>1;
 if check(mid) then exit(find(l,mid))
               else exit(find(mid+1,r));
end;

begin
 read(n,m);
 mi:=0;
 sum:=0;
 for i:=1 to n do begin
  read(a[i]);
  mi:=max(mi,a[i]);
  inc(sum,a[i])
 end;
 l:=mi;r:=sum;
 writeln(find(l,r));
end.
