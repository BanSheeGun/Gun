var a:array[1..300000] of longint;
    n,m,i,max,l,r,mid:longint;
function check(k:longint):boolean;
var i,sum:longint;
begin
 sum:=0;
 for i:=1 to m do
  inc(sum,(a[i]-1) div k+1);
 if sum<=n then exit(true)
           else exit(false);
end;
begin
 assign(input,'ljubomora.in');reset(input);
 assign(output,'ljubomora.out');rewrite(output);
 read(n,m);
 for i:=1 to m do begin
  read(a[i]);
  if a[i]>max then max:=a[i];
 end;

 l:=1;r:=max;
 while l<r-1 do begin
  mid:=(l+r)>>1;
  if check(mid) then r:=mid
                else l:=mid;
 end;

 if check(l) then writeln(l)
             else writeln(r);
 close(output);close(output);
end.
