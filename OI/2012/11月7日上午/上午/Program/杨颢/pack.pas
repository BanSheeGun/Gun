var v1,a1,v2,a2:array[1..100000] of longint;
    i,j,maxn,n,m,t,now,now2,v,aa,bb,a,b,c:longint;
    f:array[0..10000] of longint;
procedure beibao(v,val:longint);
var i,j,t,s,k,max:longint;
begin
s:=val;
for i:=0 to v do
    begin
    for j:=1 to now do
       begin
       max:=0;
       if (i-a1[j]>0) and (f[i-a1[j]]+v1[j]>max) then max:=f[i-a1[j]]+v1[j];
       for k:=1 to now2 do
           if (i-a2[k]>0) and (f[i-a2[k]]+v2[k]>max) then max:=f[i-a2[k]]+v2[k];
       end;
      f[i]:=max;
    end;
for i:=0 to v do
    if f[v]>max then max:=f[v];
s:=s+max;
if s>maxn then maxn:=s;
end;
begin
assign(input,'pack.in');
reset(input);
assign(output,'pack.out');
rewrite(output);
readln(n,v);
for i:=1 to n do
   begin
   read(t);
   if t=1 then readln(aa,bb);
   if t=2 then
       begin
       readln(a,b,c);
       for j:=now+1 to now+c do
           begin
           v1[j]:=a;
           a1[j]:=b;
           end;
       inc(now,c);
       end;
   if t=3 then
      begin
      readln(a,b);
      inc(now2);
      v2[now2]:=a;
      a2[now2]:=b;
      end;
   end;
maxn:=0;
if (aa<>0) and (bb<>0) then
    begin
    for i:=0 to v do
       begin
       beibao(v-i,aa*i*i-bb*i);
       end;
    end
    else beibao(v,0);
writeln(maxn);
close(input);
close(output);
end.