var a:array[1..500000] of longint;
    head:array[1..500000] of longint;
    e,next:array[1..1000000] of longint;
    ans,n,m,x,y,i,ans2,k:longint;
procedure qj(x,f,s:longint);
var k:longint;
begin
 if (s>ans)or((ans=s)and(x<ans2)) then begin ans:=s; ans2:=x; end;

 k:=head[x];
 while k<>0 do begin
  if e[k]<>f then begin
   qj(e[k],x,s-a[e[k]]+(n-a[e[k]]-1)-1);
  end;
  k:=next[k];
 end;

end;
procedure dfs(x,f,deep:longint);
var k:longint;
begin
 a[x]:=0;
 inc(ans,deep);

 k:=head[x];
 while k<>0 do begin
  if e[k]<>f then begin
   dfs(e[k],x,deep+1);
   a[x]:=a[x]+1+a[e[k]];
  end;
  k:=next[k];
 end;

end;
begin
 assign(input,'road.in');reset(input);
 assign(output,'road.out');rewrite(output);
 read(n,m);
 for i:=1 to m do begin
  read(x,y);
  e[i*2-1]:=y;
  next[i*2-1]:=head[x];
  head[x]:=i*2-1;
  e[i*2]:=x;
  next[i*2]:=head[y];
  head[y]:=i*2;
 end;
 randomize;
 k:=random(n)+1;
 ans:=0;
 dfs(k,0,0);
 ans2:=k;
 qj(k,0,ans);
 writeln(ans2);
 close(input);close(output);
end.
