var x,y:array[1..5000] of longint;
    head:array[1..150] of longint;
    next,e:array[1..10000] of longint;
    t:array[1..150] of boolean;
    a,b,n,m,i,temp:longint;
    ok:boolean;
procedure sort(ll,rr:longint);
var i,j,a,b,t:longint;
begin
 i:=ll;j:=rr;
 a:=x[(ll+rr) div 2];
 b:=y[(ll+rr) div 2];
 repeat
  while (x[i]<a)or((x[i]=a)and(y[i]<b)) do inc(i);
  while (a<x[j])or((x[i]=a)and(b<y[j])) do dec(j);
  if not(i>j) then begin
   t:=x[i];x[i]:=x[j];x[j]:=t;
   t:=y[i];y[i]:=y[j];y[j]:=t;
   inc(i);dec(j);
  end;
 until i>j;
 if ll<j then sort(ll,j);
 if i<rr then sort(i,rr);
end;

procedure dfs(x,xx,yy:longint);
var k:longint;
begin
 if x=yy then ok:=false;
 if not ok then exit;
 k:=head[x];
 while k<>0 do begin
  if not ((x=xx)and(e[k]=yy)) then
   if t[e[k]] then begin
    t[e[k]]:=false;
    dfs(e[k],xx,yy);
   end;
  if not ok then exit;
  k:=next[k];
 end;
end;

begin
 assign(input,'danger.in');reset(input);
 assign(output,'danger.out');rewrite(output);
 read(n,m);
 for i:=1 to m do begin
  read(a,b);
  if a>b then begin
   temp:=a;a:=b;b:=temp;
  end;
  x[i]:=a;
  y[i]:=b;
  next[i*2-1]:=head[a];
  head[a]:=i*2-1;
  e[i*2-1]:=b;
  next[i*2]:=head[b];
  head[b]:=i*2;
  e[i*2]:=a;
 end;
 sort(1,m);
 for i:=1 to m do begin
  ok:=true;
  fillchar(t,sizeof(t),true);
  t[x[i]]:=false;
  dfs(x[i],x[i],y[i]);
  if ok then writeln(x[i],' ',y[i]);
 end;
 close(input);close(output);
end.
