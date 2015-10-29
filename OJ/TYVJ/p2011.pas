var n,m,f,r,i,j,k,now:longint;
    t:longint;
    e,next:array[1..50000]of integer;
    dist,head:array[1..10000] of integer;
    q:array[1..100000]of integer;
    v:array[1..1000]of boolean;
    ch:char;
    p:boolean;
begin
 randomize;
 readln(n);
 p:=true;
 for i:=1 to n do
  begin
   for j:=1 to n do
    begin
     read(ch);
     if ch='1' then
      begin
       if t=50000 then begin t:=random(50000); p:=false; end
                  else inc(t);
       e[t]:=j;
       next[t]:=head[i];
       head[i]:=t;
      end;
    end;
   readln;
  end;
 if p=false then t:=50000;
 for i:=1 to n do dist[i]:=10000;
 v[1]:=true;
 dist[1]:=0;
 f:=1;
 r:=1;
 q[1]:=1;
 while f<=r do
  begin
   now:=q[f];
   k:=head[now];
   while k<>0 do
    begin
     if dist[e[k]]>=dist[now]+1 then
      begin
       dist[e[k]]:=dist[now]+1;
       if not(v[e[k]]) then
        begin
         inc(r);
         q[r]:=e[k];
         v[e[k]]:=true;
        end;
      end;
     k:=next[k];
    end;
   inc(f);
   v[now]:=false;
  end;
 writeln(dist[n]);
end.
