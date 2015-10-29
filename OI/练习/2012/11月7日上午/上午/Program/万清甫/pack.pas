const inf=1844674407370955166;
      maxn=120; maxm=2020;
var n,m,cnt,i,x,a,b,c,j:longint;
    ans:int64;
    f:array[0..maxn,0..maxm]of int64;
function calc(x,a,b:longint):int64;
begin
exit(int64(a)*int64(x)*int64(x)-int64(b)*int64(x));
end;
function max(x,y:int64):int64;
begin
if x>y then exit(x) else exit(y);
end;
begin
assign(input,'pack.in');
reset(input);
assign(output,'pack.out');
rewrite(output);
readln(n,m);
for i:=1 to n do
    for j:=0 to m do
        f[i][j]:=-inf;
for cnt:=1 to n do
    begin
    read(x);
    if x=1 then
       begin
       read(a,b);
       for i:=0 to m do
           begin
           f[cnt][i]:=f[cnt-1][i];
           for j:=1 to i do
               begin
               f[cnt][i]:=max(f[cnt][i],int64(f[cnt-1][i-j])+int64(calc(j,a,b)));
               end;
           end;
       end
    else
       if x=2 then
          begin
          read(a,b,c);
          for i:=0 to m do
              begin
              f[cnt][i]:=f[cnt-1][i];
              for j:=0 to c do
                  begin
                  if i-j*b>=0 then
                     begin
                     f[cnt][i]:=max(f[cnt][i],f[cnt-1][i-j*b]+j*a);
                     end
                  else
                     break;
                  end;
              end;
          end
       else
          begin
          read(a,b);
          for i:=0 to m do
              begin
              f[cnt][i]:=f[cnt-1][i];
              if i-b>=0 then
                 f[cnt][i]:=max(f[cnt][i],int64(f[cnt][i-b])+int64(a));
              end;
          end;
    end;
ans:=-inf;
for i:=0 to m do
    if f[n][i]>ans then ans:=f[n][i];
writeln(ans);
close(input);
close(output);
end.