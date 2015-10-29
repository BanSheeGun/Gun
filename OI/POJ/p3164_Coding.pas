var f:array[1..200] of longint;
    x,xx,yy,y:array[1..20000] of longint;
    l:array[1..20000] of extended;
    a:array[1..200,1..2] of longint;
    ans:extended;
    n,m,i,xxx,yyy,tot:longint;
    ok:boolean;
procedure sort(ll,rr:longint);
var i,j,p:longint;
    q,z:extended;
begin
 i:=ll;j:=rr;
 q:=l[(ll+rr) div 2];
 repeat
  while (l[i]<q) do inc(i);
  while (q<l[j]) do dec(j);
  if not(i>j) then begin
   p:=x[i];x[i]:=x[j];x[j]:=p;
   p:=y[i];y[i]:=y[j];y[j]:=p;
   z:=l[i];l[i]:=l[j];l[j]:=z;
   inc(i);dec(j);
  end;
 until i>j;
 if ll<j then sort(ll,j);
 if i<rr then sort(i,rr);
end;
function find(x:longint):longint;
begin
 if f[x]<>x then f[x]:=find(f[x]);
 exit(f[x]);
end;
begin
 while not seekeof do begin
  readln(n,m);
  for i:=1 to n do
   read(xx[i],yy[i]);
  for i:=1 to m do begin
   readln(xxx,yyy);
   l[i]:=sqrt(sqr(xx[xxx]-xx[yyy])+sqr(yy[xxx]-yy[yyy]));
   x[i]:=xxx;
   y[i]:=yyy+n;
  end;
  for i:=1 to n do begin
   inc(m);
   x[m]:=i;
   y[m]:=i+n;
   l[m]:=0;
  end;
  sort(1,m);
  ok:=false;
  tot:=0;
  ans:=0;
  for i:=1 to n*2 do f[i]:=i;
  for i:=1 to m do begin
   xxx:=find(x[i]);
   yyy:=find(y[i]);
   if xxx<>yyy then begin
    f[xxx]:=f[yyy];
    inc(tot);
    ans:=ans+l[i];
   end;
   if tot=n*2-1 then begin
    ok:=true;
    break;
   end;
  end;
  if ok then writeln(ans:0:2)
  else writeln('poor snoopy');
 end;
end.
