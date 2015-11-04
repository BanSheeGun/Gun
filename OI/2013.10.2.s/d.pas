var a,b,head,ans:array[0..777] of longint;
    e,next,l:array[1..3333] of longint;
    t:array[0..777] of boolean;
    d:array[0..1000000] of longint;
    f,p,x,y,z,m,n,i,k:longint;
function dj(t,i:longint):longint;
begin
 if (i=n)or(i=0) then exit(t);
 if t mod (a[i]+b[i])>a[i] then exit((t div (a[i]+b[i])+1) *(a[i]+b[i])+1);
end;
begin
 assign(input,'d.in');reset(input);
 assign(output,'d.out');rewrite(output);
 read(n);
 for i:=1 to n do
  read(a[i],b[i]);
 read(m);
 for i:=1 to m do begin
  read(x,y,z);
  e[i*2-1]:=y;
  next[i*2-1]:=head[x];
  head[x]:=i*2-1;
  l[i*2-1]:=z;
  e[i*2]:=x;
  next[i*2]:=head[y];
  head[y]:=i*2;
  l[i*2]:=z;
 end;
 fillchar(ans,sizeof(ans),63);
 d[1]:=0;
 fillchar(t,sizeof(t),true);
 t[0]:=false;
 f:=1;p:=1;
 ans[0]:=0;
 repeat
  k:=head[d[f]];
  while k<>0 do begin
   if ans[e[k]]>dj(l[k]+ans[d[f]],e[k]) then begin
    ans[e[k]]:=dj(l[k]+ans[d[f]],e[k]);
    if t[e[k]] then begin
     t[e[k]]:=false;
     inc(p);
     d[p]:=e[k];
    end;
   end;
   k:=next[k];
  end;
  t[d[f]]:=true;
  inc(f);
 until f>p;
 writeln(ans[n]);
 close(input);close(output);
end.
