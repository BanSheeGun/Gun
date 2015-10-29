var l,r,a,f:array[1..1000010] of longint;
    x,y,ans,tot,i,n,m,k:longint;
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
   t:=l[i];l[i]:=l[j];l[j]:=t;
   t:=r[i];r[i]:=r[j];r[j]:=t;
   inc(i);dec(j);
  end;
 until i>j;
 if ll<j then sort(ll,j);
 if i<rr then sort(i,rr);
end;
function find(x:longint):longint;
begin
 if x<>f[x] then f[x]:=find(f[x]);
 exit(f[x]);
end;
begin
 assign(input,'room.in');reset(input);
 assign(output,'room.out');rewrite(output);
 read(n,m,k);
 for i:=1 to m do
  read(l[i],r[i],a[i]);
 sort(1,m);
 tot:=0;
 ans:=0;
 for i:=1 to n do f[i]:=i;
 for i:=1 to m do begin
  if tot=n-k then break;
  x:=find(l[i]);
  y:=find(r[i]);
  if x<>y then begin
   f[x]:=f[y];
   inc(tot);
   ans:=ans+a[i];
  end;
 end;
 if tot=n-k then writeln(ans)
 else writeln(-1);
 close(input);close(output);
end.
