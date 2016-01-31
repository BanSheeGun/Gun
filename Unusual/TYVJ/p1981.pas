var a:array[0..1000000] of longint;
    head,ans:array[1..1000] of longint;
    e,next,w:array[1..2000000] of longint;
    d:array[1..4000000] of longint;
    t:array[1..1000] of boolean;
    nc:boolean;
    n,m,kk,i,l,r,oo,f,p,x,y,z:longint;
procedure sort(l,r:longint);
var i,j,q,y:longint;
begin
 i:=l;j:=r;
 q:=a[(l+r) div 2];
 repeat
  while (a[i]<q) do inc(i);
  while (q<a[j]) do dec(j);
  if not(i>j) then begin
   y:=a[i];a[i]:=a[j];a[j]:=y;
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then sort(l,j);
 if i<r then sort(i,r);
end;

function check(ma:longint):boolean;
var k,l:longint;
begin
 fillchar(ans,sizeof(ans),63);
 fillchar(t,sizeof(t),true);
 t[1]:=true;
 oo:=ans[1];
 ans[1]:=0;
 f:=1;p:=1;d[1]:=1;
 repeat
  k:=head[d[f]];
  while k<>0 do begin
   l:=ord(w[k]>ma);
   if ans[e[k]]>ans[d[f]]+l then begin
    ans[e[k]]:=ans[d[f]]+l;
    if t[e[k]] then begin
     t[e[k]]:=false;
     inc(p);
     d[p]:=e[k];
    end;
   end;
   k:=next[k];
  end;
  t[d[f]]:=true;
  inc(f);
 until f>p;
 if ans[n]=oo then begin
  nc:=true;
  exit;
 end;
 if ans[n]<=kk then exit(true);
 exit(false);
end;

procedure find(l,r:longint);
var mid:longint;
    tt:boolean;
begin
 mid:=(l+r)>>1;
 if l=r then begin
  writeln(a[l]);
  exit;
 end;
 tt:=check(a[mid]);
 if nc then begin
  writeln(-1);
  exit;
 end;
 if tt then r:=mid
       else l:=mid+1;
 find(l,r);
end;

begin
 read(n,m,kk);
 for i:=1 to m do begin
  read(x,y,z);
  a[i]:=z;
  next[i*2-1]:=head[x];
  e[i*2-1]:=y;
  head[x]:=i*2-1;
  w[i*2-1]:=z;
  next[i*2]:=head[y];
  e[i*2]:=x;
  head [y]:=i*2;
  w[i*2]:=z;
 end;
 sort(1,m);
 nc:=false;
 l:=0;r:=m;
 find(l,r);
end.
