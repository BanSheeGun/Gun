var d,head,ans:array[0..200] of longint;
    e,next,v:array[1..40000] of longint;
    q:array[1..10000] of longint;
    t:array[0..200] of boolean;
    n,m,x,y,z,f,p,k,i,mm,oo:longint;
begin
 assign(input,'findpath.in');reset(input);
 assign(output,'findpath.out');rewrite(output);
 read(n,m);
 for i:=0 to n-1 do read(d[i]);
 for i:=1 to m do begin
  read(x,y,z);
  e[i*2-1]:=y;
  v[i*2-1]:=z;
  next[i*2-1]:=head[x];
  head[x]:=i*2-1;
  e[i*2]:=x;
  v[i*2]:=z;
  next[i*2]:=head[y];
  head[y]:=i*2;
 end;

 read(m);
 for z:=1 to m do begin
  read(x,y,mm);
  fillchar(ans,sizeof(ans),63);
  oo:=ans[x];
  ans[x]:=0;
  f:=1;p:=1;
  q[1]:=x;
  fillchar(t,sizeof(t),true);t[x]:=false;
  repeat
   k:=head[q[f]];
   while k<>0 do begin
    if (d[e[k]]<=mm)or(e[k]=y)then begin
     if ans[e[k]]>ans[q[f]]+v[k] then begin
      ans[e[k]]:=ans[q[f]]+v[k];
      if t[e[k]] then begin
       t[e[k]]:=false;
       inc(p);
       q[p]:=e[k];
      end;
     end;
    end;
    k:=next[k];
   end;
   t[q[f]]:=true;
   inc(f);
  until f>p;
  if ans[y]=oo then writeln(-1)
               else writeln(ans[y]);
 end;
 close(input);close(output);
end.
