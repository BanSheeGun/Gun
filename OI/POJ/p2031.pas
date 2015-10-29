var x,y,z,r:array[1..100] of extended;
    f,lc,rc:array[1..10000] of longint;
    ll:array[1..10000] of extended;
    n,i,top,xx,yy,m,j:longint;
    ans:extended;
procedure sort(l,r:longint);
var i,j,p:longint;
    y,q:extended;
begin
 i:=l;j:=r;
 q:=ll[(l+r) div 2];
 repeat
  while (ll[i]<q) do inc(i);
  while (q<ll[j]) do dec(j);
  if not(i>j) then begin
   y:=ll[i];ll[i]:=ll[j];ll[j]:=y;
   p:=lc[i];lc[i]:=lc[j];lc[j]:=p;
   p:=rc[i];rc[i]:=rc[j];rc[j]:=p;
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then sort(l,j);
 if i<r then sort(i,r);
end;


function find(x:longint):longint;
begin
 if x<>f[x] then f[x]:=find(f[x]);
 exit(f[x]);
end;

begin
  read(n);
  while n<>0 do begin
  for i:=1 to n do
   read(x[i],y[i],z[i],r[i]);
  top:=0;
  for i:=1 to n-1 do
   for j:=i+1 to n do begin
     inc(top);
     lc[top]:=i;
     rc[top]:=j;
     ll[top]:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j])+sqr(z[i]-z[j]));
     ll[top]:=ll[top]-r[i]-r[j];
     if ll[top]<0 then ll[top]:=0;
    end;
  sort(1,top);
  for i:=1 to n do f[i]:=i;
  ans:=0;m:=0;
  for i:=1 to top do begin
   xx:=find(lc[i]);
   yy:=find(rc[i]);
   if xx<>yy then begin
    inc(m);
    ans:=ans+ll[i];
    f[xx]:=f[yy];
   end;
   if m=n-1 then break;
  end;
  writeln(ans:0:3);
  read(n);
 end;
end.
