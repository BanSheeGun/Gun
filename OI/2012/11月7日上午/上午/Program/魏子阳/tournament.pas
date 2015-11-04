var n,m,x,y,i,j,targetx,targety:longint;
    compare:array[1..100,1..100]of boolean;
    line:array[1..100,0..100]of longint;
procedure dfs(now:longint);
var i:longint;
begin
if now=targety then begin
                    writeln(targetx,' ',targety);
                    close(input);
                    close(output);
                    halt;
                    end;
for i:=1 to line[now,0] do
    begin
    dfs(line[now,i]);
    end;
end;
begin
assign(input,'tournament.in');
assign(output,'tournament.out');
reset(input);
rewrite(output);
readln(n);
m:=(n*(n-1)) div 2;
m:=m-1;
fillchar(line,sizeof(line),0);
fillchar(compare,sizeof(compare),false);
for i:=1 to m do
    begin
    readln(x,y);
    inc(line[x,0]);
    line[x,line[x,0]]:=y;
    compare[x,y]:=true;
    compare[y,x]:=true;
    end;
targetx:=0;targety:=0;
for i:=1 to n do
    begin
    for j:=1 to n do
        if i<>j then if compare[i,j]=false then begin
                                                targetx:=i;
                                                targety:=j;
                                                break;
                                                end;
    if targetx<>0 then break;
    end;
dfs(targetx);
writeln(targety,' ',targetx);
close(input);
close(output);
end.