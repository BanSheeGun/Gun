const  maxn=100;
var n,i,j,k:longint;
    x,y:longint;
    g,tg:array[0..maxn,0..maxn]of longint;
    flag:boolean;
begin
assign(input,'tournament.in');
reset(input);
assign(output,'tournament.out');
rewrite(output);
readln(n);
for i:=1 to n*(n-1)div 2-1 do
    begin
    readln(x,y);
    g[x][y]:=1;
    end;
tg:=g;
for k:=1 to n do
    for i:=1 to n do
        for j:=1 to n do
            begin
            if (i<>k)and(k<>j)and(i<>j) then
               begin
               if (g[i][k]=1)and(g[k][j]=1) then
                  g[i][j]:=1;
               end;
            end;
for i:=1 to n do
    begin
    for j:=1 to n do
        begin
        if (i<>j)and(g[i][j]=1)and(tg[i][j]=0) then
           begin
           writeln(i,' ',j);
           flag:=true;
           break;
           end;
        end;
    if flag then break;
    end;
close(input);
close(output);
end.
