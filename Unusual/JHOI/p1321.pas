var head,next:array[1..100000] of longint;
    e:array[1..2,1..100000] of longint;
    t:array[1..50000] of boolean;
    d:array[1..50000] of longint;
    n,i,j,m,f,p,x,y,z,k,lp:longint;
begin
 read(n,j,m);
 for i:=1 to m do begin
  read(x,y,z);
  e[1][i*2-1]:=x;
  e[2][i*2-1]:=y;
  next[i*2-1]:=head[z];
  head[z]:=i*2-1;
  e[1][i*2]:=y;
  e[2][i*2]:=x;
  next[i*2]:=head[z];
  head[z]:=i*2;
 end;

 fillchar(t,sizeof(t),false);
 t[j]:=true;
 f:=1;p:=1;
 d[1]:=j;
 repeat
 f:=1;
 lp:=p;
 repeat
  k:=head[d[f]];
  while k<>0 do begin
   if t[e[1][k]] and (not t[e[2][k]]) then begin
    t[e[2][k]]:=true;
    inc(p);
    d[p]:=e[2][k];
   end;
   k:=next[k];
  end;
  inc(f);
 until f>p;
 until lp=p;
 for i:=1 to n do begin
  write(i,':');
  if t[i] then writeln('Yes')
          else writeln('No');
 end;
end.
