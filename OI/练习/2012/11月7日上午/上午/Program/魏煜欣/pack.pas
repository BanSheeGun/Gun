var ans,n,tolv,vv,i,k,temp:longint;
    x,v,w,sum:Array[0..3000] of longint;
    f:array[0..100,0..3000] of longint;
function max(a,b:longint):longint;
begin
if a>b then exit(a)
       else exit(b);
end;
procedure enter;
begin
assign(input,'pack.in');
assign(output,'pack.out');
reset(input);
rewrite(output);
end;
procedure endit;
begin
close(input);
close(output);
end;
begin
enter;
readln(n,tolv);
for i:=1 to n do
        begin
        read(x[i],w[i],v[i]);

        if x[i]=2 then read(sum[i])
            else sum[i]:=1000000;
        end;
for i:=1 to n do
        for vv:=1 to tolv do
        begin
        if x[i]=1 then begin
                       for k:=0 to vv do
                        f[i,vv]:=max(f[i,k]+w[i]*w[i]*(vv-k)-v[i]*(vv-k),f[i,vv]);
                       end
                  else
        begin
        for k:=0 to sum[i] do
                begin
                temp:=vv-k*v[i];
                if temp<0 then break;
                f[i,vv]:=max(f[i-1,temp]+k*w[i],f[i,vv]);
                end;
        end
        end;
for i:=1 to tolv do
        if f[n,i]>ans then ans:=f[n,i];
writeln(ans);
endit;
end.
