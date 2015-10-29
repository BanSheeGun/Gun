
var head,head2,a,b,c:array[0..100000] of longint;
    e,next,e2,next2:array[1..1000000] of longint;
    d:array[1..2000000] of longint;
    t:array[1..100000] of boolean;
    f,p,x,y,z,i,j,m,m1,n,k,ans:longint;
function min(a,b:longint):longint;
begin
 if a<b then exit(a);
 exit(b);
end;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
begin

 assign(input,'trade.in');reset(input);
 assign(output,'trade.out');rewrite(output);

 read(n,m1);
 for i:=1 to n do begin
  read(c[i]);
 end;
 for i:=1 to m1 do begin
  read(x,y,z);
  inc(m);
  e[m]:=y;
  next[m]:=head[x];
  head[x]:=m;
  e2[m]:=x;
  next2[m]:=head2[y];
  head2[y]:=m;
  if z=2 then begin
   inc(m);
   e[m]:=x;
   next[m]:=head[y];
   head[y]:=m;
   e2[m]:=y;
   next2[m]:=head2[x];
   head2[x]:=m;
  end;
 end;

 fillchar(t,sizeof(t),true);
 fillchar(a,sizeof(a),63);
 f:=1;p:=1;
 d[1]:=1;a[1]:=c[1];
 t[1]:=false;
 repeat
  k:=head[d[f]];
  while k<>0 do begin
   if (a[e[k]]>c[e[k]])or(a[e[k]]>a[d[f]]) then begin
   a[e[k]]:=min(c[e[k]],a[d[f]]);
   if t[e[k]] then begin
    inc(p);
    t[e[k]]:=false;
    d[p]:=e[k];
   end;
   end;
   k:=next[k];
  end;
  t[d[f]]:=true;
  inc(f);
 until f>p;

 fillchar(d,sizeof(d),0);
 fillchar(t,sizeof(t),true);
 fillchar(b,sizeof(b),0);
 f:=1;p:=1;
 d[1]:=n;b[n]:=c[n];
 t[n]:=false;
 repeat
  k:=head2[d[f]];
  while k<>0 do begin
   if (b[e2[k]]<c[e2[k]])or(b[e2[k]]<b[d[f]]) then begin
   b[e2[k]]:=max(c[e2[k]],b[d[f]]);
   if t[e2[k]] then begin
    inc(p);
    t[e2[k]]:=false;
    d[p]:=e2[k];
   end;
   end;
   k:=next2[k];
  end;
  t[d[f]]:=true;
  inc(f);
 until f>p;

 ans:=0;
 for i:=1 to n do
  if (b[i]<>0)and(a[0]<>a[i]) then
  ans:=max(ans,b[i]-a[i]);
 writeln(ans);

 close(input);close(output);
end.
