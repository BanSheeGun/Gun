var head:array[1..1000] of longint;
    e,w,next:array[1..200000] of longint;
    t:array[1..1000] of boolean;
    ans,n,m,x,y,z,i:longint;
procedure dfs(z,s:longint);
var k:longint;
begin
 if s>ans then ans:=s;
 k:=head[z];
 while k<>0 do begin
  if t[e[k]] then begin
   t[e[k]]:=false;
   dfs(e[k],s+w[k]);
   t[e[k]]:=true;
  end;
  k:=next[k];
 end;
end;
begin
 assign(input,'longest.in');reset(input);
 assign(output,'longest.out');rewrite(output);
 read(n,m);
 ans:=0;
 for i:=1 to m do begin
  read(x,y,z);
  e[i*2-1]:=y;
  next[i*2-1]:=head[x];
  head[x]:=i*2-1;
  w[i*2-1]:=z;
  e[i*2]:=x;
  next[i*2]:=head[y];
  head[y]:=i*2;
  w[i*2]:=z;
 end;
  i:=1;
  fillchar(t,sizeof(t),true);
  t[i]:=false;
  dfs(i,0);
 writeln(ans);
 close(input);close(output);
end.
