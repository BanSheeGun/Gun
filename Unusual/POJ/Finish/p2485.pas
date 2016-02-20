var l,r,w:array[1..250000] of longint;
    f:array[1..500] of longint;
    tot,x,y,test,testnum,n,m,i,j,ans:longint;
procedure sort(ll,rr:longint);
var i,j,q,y:longint;
begin
 i:=ll;j:=rr;
 q:=w[(ll+rr) div 2];
 repeat
  while (w[i]<q) do inc(i);
  while (q<w[j]) do dec(j);
  if not(i>j) then begin
   y:=w[i];w[i]:=w[j];w[j]:=y;
   y:=l[i];l[i]:=l[j];l[j]:=y;
   y:=r[i];r[i]:=r[j];r[j]:=y;
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
 read(test);
 for testnum:=1 to test do begin
  read(n);
  m:=0;
  for i:=1 to n do
   for j:=1 to n do begin
    read(x);
    if j>i then begin
     inc(m);
     w[m]:=x;
     l[m]:=i;
     r[m]:=j;
    end;
   end;
   sort(1,m);
  ans:=0;
  for i:=1 to n do f[i]:=i;
  tot:=0;
  for i:=1 to m do begin
   x:=find(l[i]);
   y:=find(r[i]);
   if x<>y then begin
    f[x]:=f[y];
    inc(tot);
    ans:=w[i];
    if tot=n-1 then break;
   end;
  end;

  writeln(ans);
 end;
end.
