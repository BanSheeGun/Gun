var a:array[1..100000] of longint;
    n,i,j,ans,k:longint;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
 i:=l;j:=r;
 x:=a[(l+r) div 2];
 repeat
  while (a[i]>x) do inc(i);
  while (x>a[j]) do dec(j);
  if not(i>j) then begin
   y:=a[i];a[i]:=a[j];a[j]:=y;
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then sort(l,j);
 if i<r then sort(i,r);
end;

function get(x,l:longint):longint;
begin
 exit((x>>(l-1)) mod 2);
end;

function dd(l,r,step:longint):longint;
var now,ll,rr,mid,q,w:longint;
begin
 if l=r then exit(l);
 if step=0 then exit(l);
 now:=get(a[i],step);
 q:=get(a[l],step);
 w:=get(a[r],step);
 if q=w then begin
  if step=1 then exit(l)
  else exit(dd(l,r,step-1));
 end
 else begin
  ll:=l;
  rr:=r;
  while ll<rr-1 do begin
   mid:=(ll+rr) div 2;
   q:=get(a[mid],step);
   if q=1 then ll:=mid
          else rr:=mid;
   end;
   q:=get(a[ll],step);
   w:=get(a[rr],step);
  if w=0 then rr:=ll;
 end;
 if step=1 then exit(l)
 else if now=1 then exit(dd(rr+1,r,step-1))
               else exit(dd(l,rr,step-1));
end;

function work(z:longint):longint;
var l,zz:longint;
begin
 l:=0;zz:=a[z];
 while zz<>0 do begin inc(l); zz:=zz >> 1; end;
 zz:=get(a[z],l);
 exit(dd(z+1,n,l));
end;

begin
 assign(input,'c.in');reset(input);
 assign(output,'c.out');rewrite(output);
 read(n);
 for i:=1 to n do read(a[i]);
 sort(1,n);
 for i:=1 to n-1 do begin
  k:=work(i);
  if a[i] xor a[k]>ans then
   ans:=a[i] xor a[k];
 end;
 writeln(ans);
 close(input);close(output);
end.
