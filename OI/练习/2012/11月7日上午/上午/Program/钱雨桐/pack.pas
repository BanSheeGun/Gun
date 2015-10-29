var r,p,i,j,t,k,t1,t2,m,n,a,b,c:longint;
    w,v,x,y:array[0..10000] of longint;
    f:array[0..10000,0..500] of boolean;
    q:array[0..500,1..2] of longint;
function search(n:longint):longint;
var i:longint;
begin
for i:=1 to p do
    if (n>=q[i,1]) and (n<=q[i,2]) then begin search:=i; exit; end;
search:=0;
end;
begin
assign(input,'pack.in');
reset(input);
assign(output,'pack.out');
rewrite(output);
read(n,m);
t:=0;
p:=0;
fillchar(a,sizeof(a),0);
fillchar(b,sizeof(b),0);
fillchar(f,sizeof(f),true);
for i:=1 to n do
    begin
    read(k);
    if k=1 then begin
                read(a,b);
                for j:=1 to m do
                    begin
                    w[t+j]:=j;
                    v[t+j]:=a*j*j-b*j;
                    end;
                t:=t+m;
                inc(p);
                q[p,1]:=a;
                q[p,2]:=b;
                end;
    if k=2 then begin
                read(a,b,c);
                for j:=1 to c do
                    begin
                    w[t+j]:=b;
                    v[t+j]:=a;
                    end;
                t:=t+c;
                end;
    if k=3 then begin
                read(a,b);
                for j:=1 to (m div b) do
                    begin
                    w[t+j]:=b;
                    v[t+j]:=a;
                    end;
                t:=t+m div b;
                end;
    end;
r:=search(1);
for j:=1 to m do
    if j>=w[i] then begin x[j]:=v[1]; if r<>0 then f[j,r]:=false;end
               else x[j]:=0;
for i:=2 to t do
    begin
    r:=search(i);
    if r=0 then
                    begin
                    for j:=1 to m do
                        begin
                        if j>=w[i] then t1:=x[j-w[i]]+v[i]
                                  else t1:=0;
                        t2:=x[j];
                        if t1>t2 then begin y[j]:=t1;f[j]:=f[j-w[i]];end
                                 else begin y[j]:=t2;f[j]:=f[j]; end;
                        end;
                     end
               else begin
                    for j:=1 to m do
                        begin
                        if f[j,r]=false then continue;
                        if j>=w[i] then t1:=x[j-w[i]]+v[i]
                                  else t1:=0;
                        t2:=x[j];
                        if t1>t2 then begin y[j]:=t1;f[j,r]:=false; end
                                 else begin y[j]:=t2;f[j]:=f[j]; end;
                        end;
                    end;
    x:=y;
    end;
writeln(y[m]);
close(input);
close(output);
end.

