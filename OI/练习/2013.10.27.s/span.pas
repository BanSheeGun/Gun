type cw=record
      x,y,w:longint;
     end;
var a:array[1..3000] of cw;
    f,ff:array[1..100] of longint;
    ma,top,n,m,i,j,x,y,ans:longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
function min(a,b:longint):longint;
begin
 if a<b then exit(a);
 exit(b);
end;
procedure sort(l,r:longint);
var i,j:longint;
    q,y:cw;
begin
 i:=l;j:=r;
 q:=a[(l+r) div 2];
 repeat
  while (a[i].w<q.w) do inc(i);
  while (q.w<a[j].w) do dec(j);
  if not(i>j) then begin
   y:=a[i];a[i]:=a[j];a[j]:=y;
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then sort(l,j);
 if i<r then sort(i,r);
end;

function find(x:longint):longint;
begin
 if f[x]<>x then f[x]:=find(f[x]);
 exit(f[x]);
end;

begin
 assign(input,'span.in');reset(input);
 assign(output,'span.out');rewrite(output);
 read(n,m);
 ans:=maxlongint;
 for i:=1 to m do
  read(a[i].x,a[i].y,a[i].w);
 sort(1,m);
 for i:=1 to n do ff[i]:=i;
 for i:=1 to m-n+1 do begin
  f:=ff;
  top:=0;
  j:=i;
  ma:=0;
  while (j<=m)and(top<n-1) do begin
   x:=find(a[j].x);
   y:=find(a[j].y);
   if x<>y then inc(top);
   f[x]:=f[y];
   ma:=a[j].w;
   inc(j);
   if top=n-1 then break;
  end;
  if top<>n-1 then break;
  ans:=min(ans,ma-a[i].w);
 end;
 if ans=maxlongint then writeln(-1)
                   else writeln(ans);
 close(input);close(output);
end.
