var f:array[1..100,0..100] of longint;
    head,e,next,v:array[1..100] of longint;
    n,m,i,x,y:longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;

function qf(x,tot:longint):longint;
var ans,k:longint;

function dfs(x,n:longint):longint;
var i,ans,k:longint;
begin
 ans:=0;
 if x=0 then exit(0);
 if n=0 then exit(0);
 for i:=0 to n do begin
  ans:=max(ans,qf(e[x],i)+dfs(next[x],n-i));
 end;
 exit(ans);
end;

begin
 if f[x][tot]<>0 then exit(f[x][tot]);
 if tot=0 then exit(0);
 ans:=0;
 k:=head[x];
 while k<>0 do begin
  ans:=max(ans,qf(e[k],tot));
  k:=next[k];
 end;
 ans:=max(ans,dfs(head[x],tot-1)+v[x]);
 f[x][tot]:=ans;
 exit(f[x][tot]);
end;


begin
 assign(input,'seek.in');reset(input);
 assign(output,'seek.out');rewrite(output);
 read(n,m);
 for i:=1 to n do
  read(v[i]);
 for i:=1 to n-1 do begin
  read(x,y);
  next[i]:=head[x];
  head[x]:=i;
  e[i]:=y;
 end;

 writeln(qf(1,m));
 close(input);close(output);
end.
