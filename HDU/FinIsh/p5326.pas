var e,next,head,f:array[1..1000] of longint;
    n,i,k,a,b,ans:longint;
procedure dfs(n:longint);
var k:longint;
begin
 k:=head[n];
 f[n]:=1;
 while k<>0 do begin
  dfs(e[k]);
  f[n]:=f[n]+f[e[k]];
  k:=next[k];
 end;
end;
begin
 while not seekeof do begin
  read(n,k);
  fillchar(head,sizeof(head),0);
  fillchar(next,sizeof(next),0);
  fillchar(e,sizeof(e),0);
  fillchar(f,sizeof(f),0);
  for i:= 1 to n-1 do begin
   read(a,b);
   e[i]:=b;
   next[i]:=head[a];
   head[a]:=i;
  end;

  fillchar(f,sizeof(f),0);
  for i:=1 to n do dfs(i);

  ans:=0;
  for i:=1 to n do
   if f[i]=k+1 then inc(ans);
  writeln(ans);
 end;
end.
