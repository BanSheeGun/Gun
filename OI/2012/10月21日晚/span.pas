type cw=record
      x,y,z:longint;
     end;
var a:array[1..3000] of cw;
    i,n,k,m,ans:longint;

procedure sort(l,r: longint);
var i,j: longint;
    x,y:cw;
begin
 i:=l; j:=r;
 x:=a[(l+r) div 2];
 repeat
    while a[i].z<x.z do inc(i);
    while x.z<a[j].z do dec(j);
    if not(i>j) then begin
    y:=a[i];a[i]:=a[j];
    a[j]:=y;inc(i);dec(j);
   end;
 until i>j;
 if l<j then sort(l,j);
 if i<r then sort(i,r);
end;

function check(p:longint):longint;
var  jh:array[1..100] of longint;
     i,k1,k2,sum,an:longint;
function find(k:longint):longint;
begin
 if k<>jh[k] then jh[k]:=find(jh[k]);
 exit(jh[k]);
end;

begin
 for i:=1 to n do jh[i]:=i;
 sum:=0;an:=maxlongint;
 for i:=p to m do begin
  k1:=find(a[i].x);
  k2:=find(a[i].y);
  jh[k1]:=jh[k2];
  if k1<>k2 then begin
   inc(sum);
  end;
  if (sum=n-1) then begin  an:=a[i].z-a[p].z;break; end;
 end;
 exit(an);
end;


begin
// assign(input,'span.in');reset(input);
// assign(output,'span.out');rewrite(output);
 read(n,m);
 for i:=1 to m do
  read(a[i].x,a[i].y,a[i].z);
 sort(1,m);

 ans:=maxlongint;
 for i:=1 to m-n+1 do begin
  k:=check(i);
  if k<ans then ans:=k;
 end;
 if ans=maxlongint then writeln(-1)
  else  writeln(ans);

 close(input);close(output);
end.
