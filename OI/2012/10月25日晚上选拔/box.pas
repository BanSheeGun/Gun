const pi=3.1415926;
var a:array[1..6] of extended;
    i,x1,x2,y1,y2,z1,z2,n,j:longint;
    ans,zt,bb:extended;
    zx,zy,zz:array[1..6] of longint;
    t:array[1..6] of boolean;
function min(a,b:extended):extended;
begin
 if a>b then exit(b);
 exit(a);
end;
function jl(c,d:longint):extended;
begin
 jl:=sqrt(sqr(zx[c]-zx[d])+sqr(zy[c]-zy[d])+sqr(zz[c]-zz[d]));
end;
function qk(k:longint):extended;
var i:longint;
    q,l:extended;
begin
 q:=abs(zx[k]-x1);
 q:=min(q,abs(zx[k]-x2));
 q:=min(q,abs(zy[k]-y1));
 q:=min(q,abs(zy[k]-y2));
 q:=min(q,abs(zz[k]-z1));
 q:=min(q,abs(zz[k]-z2));

 for i:=1 to n do
  if i<>k then
  if not t[i] then
   begin
   l:=jl(k,i)-a[i];
   q:=min(q,l);
   end;
 exit(q);
end;
procedure dfs(k,deep:longint);
var i:longint;
    lzt:extended;
begin
 a[k]:=qk(k);
 if a[k]<0 then a[k]:=0;
 zt:=zt-4/3*pi*a[k]*a[k]*a[k];
 if deep<n then begin
  for i:=1 to n do
  if t[i] then  begin
   t[i]:=false;lzt:=zt;
   dfs(i,deep+1);
   t[i]:=true;zt:=lzt;
  end;
 end
 else begin
  if zt<ans then ans:=zt;
 end;
 a[k]:=0;
end;
begin
 assign(input,'box.in');reset(input);
 assign(output,'box.out');rewrite(output);
 read(n);
 read(x1,y1,z1,x2,y2,z2);
 for i:=1 to n do read(zx[i],zy[i],zz[i]);

 zt:=ans; bb:=0;
 for i:=1 to n do begin
  zt:=bb;
  fillchar(t,sizeof(t),true);
  for j:=1 to n do a[j]:=0;
  t[i]:=false;
  dfs(i,1);
 end;

 ans:=(abs(y1-y2)*abs(z1-z2)+ans/abs(x1-x2))*abs(x1-x2);

 writeln(ans:0:0);
 close(input);close(output);
end.
