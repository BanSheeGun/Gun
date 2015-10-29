var l,r,w,v:array[1..200000] of longint;
    mi,ma,i,n,m:longint;
    ans,s:int64;
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

function check(ww:longint):int64;
var sum,sum0:int64;
    i,j,ss:longint;
begin
 sum:=0;
 for i:=1 to m do begin
  ss:=0;sum0:=0;
  for j:=l[i] to r[i] do
   if w[j]>=ww then begin
    ss:=ss+1;
    sum0:=sum0+v[i];
   end;
   sum:=sum+sum0*ss;
 end;
 exit(sum);
end;

function find(ll,rr:longint):int64;
var mid:longint;
    ans:int64;
begin
 if ll=rr then exit(abs(check(ll)-s));
 if ll=rr-1 then begin
  ans:=maxlongint;
  ans:=min(ans,abs(check(ll)-s));
  ans:=min(ans,abs(check(rr)-s));
  exit(ans);
 end;
 mid:=(ll+rr)>>1;
 ans:=check(mid);
 if ans=0 then exit(0);
 if ans<=0 then exit(find(ll,mid));
 exit(find(mid,rr));
end;
begin
 assign(input,'qc.in');reset(input);
 assign(output,'qc.out');rewrite(output);
 read(n,m,s);
 ma:=0;mi:=maxlongint;
 for i:=1 to n do begin
  read(w[i],v[i]);
  ma:=max(ma,w[i]);
  mi:=min(mi,w[i]);
 end;
 for i:=1 to m do
  read(l[i],r[i]);

 ans:=find(mi,ma);
 writeln(ans);
 close(input);close(output);
end.
