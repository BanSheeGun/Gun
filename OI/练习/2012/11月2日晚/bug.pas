var l,next,e:array[1..1000000] of longint;
    head:array[1..200000] of longint;
    ans:array[0..1,1..200000] of longint;
    d:array[1..2,1..4000000] of longint;
    t:array[0..1,1..200000] of boolean;
    x,y,z,i,n,m,f,p,k,ml,jo,fd:longint;
begin
 assign(input,'bug.in');reset(input);
 assign(output,'bug.out');rewrite(output);
 read(n,m);
 for i:=1 to m do begin
  read(x,y,z);
  e[i*2-1]:=y;
  l[i*2-1]:=z;
  next[i*2-1]:=head[x];
  head[x]:=i*2-1;
  e[i*2]:=x;
  l[i*2]:=z;
  next[i*2]:=head[y];
  head[y]:=i*2;
 end;

 fillchar(ans,sizeof(ans),63);
 fillchar(t,sizeof(t),true);
 ml:=ans[1][1];
 f:=1;p:=1;
 ans[0][1]:=0;
 d[1][1]:=1;d[2][1]:=0;
 t[0][1]:=false;
 repeat
  fd:=d[1][f];
  k:=head[fd];
  while k<>0 do begin
   jo:=(d[2][f]+l[k]) mod 2;
   if ans[d[2][f]][fd]+l[k]<ans[jo][e[k]] then begin
    ans[jo][e[k]]:=ans[d[2][f]][fd]+l[k];
    if t[jo][e[k]] then begin
     inc(p);
     d[1][p]:=e[k];
     d[2][p]:=jo;
     t[jo][e[k]]:=false;
    end;
   end;
   k:=next[k];
  end;
  t[d[2][f]][d[1][f]]:=true;
  inc(f);
 until f>p;
 if ans[1][n]=ml then writeln(0)
                 else writeln(ans[1][n]);
 close(input);close(output);
end.
