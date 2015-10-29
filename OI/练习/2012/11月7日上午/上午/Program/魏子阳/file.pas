type str=record
     st:string;
     next:array[0..20]of longint;
     end;
var  leng,n,i,j,k,nowdep:longint;
     shu:array[0..100]of longint;
     depstr:array[0..20,1..50]of str;
     now:str;
     depnum,last:array[0..20]of longint;
     ipt:array[1..100]of string;
procedure dfs(nowdep,k:longint);
var i,j,t:longint;
    use:array[1..20]of boolean;
    s:string;
    op:longint;
begin
for i:=1 to shu[0] do
    begin
    if i=1 then write('|');
    if i>1 then begin for j:=1 to shu[i]-shu[i-1]-1 do write(' ');write('|');end;
    end;
if shu[0]<>0 then for i:=1 to 4 do write('-');
writeln(depstr[nowdep][k].st);
fillchar(use,sizeof(use),false);
for t:=1 to depstr[nowdep][k].next[0] do
    begin
    s:='';
    for i:=1 to depstr[nowdep][k].next[0] do
    begin
    if use[i]=false then
       begin
       if s='' then begin s:=depstr[nowdep+1][depstr[nowdep][k].next[i]].st;op:=i;end;
       if s<>'' then if depstr[nowdep+1][depstr[nowdep][k].next[i]].st<s then begin s:=depstr[nowdep+1][depstr[nowdep][k].next[i]].st;op:=i;end;
       end;
    end;
    use[op]:=true;
    inc(shu[0]);shu[shu[0]]:=shu[shu[0]-1]+5;
    dfs(nowdep+1,depstr[nowdep][k].next[op]);
    dec(shu[0]);
    end;
end;
procedure check(now:str;nowdep:longint);
var i:longint;
    pd:boolean;
begin
pd:=false;
for i:=1 to depnum[nowdep] do
    begin
    if depstr[nowdep][i].st=now.st then begin pd:=true;last[nowdep]:=i;end;
    end;
if pd=false then begin inc(depnum[nowdep]);depstr[nowdep][depnum[nowdep]]:=now;last[nowdep]:=depnum[nowdep];end;
end;

procedure add(now:str);
var i:longint;
    pd:boolean;
begin
pd:=false;
for i:=1 to depstr[nowdep-1][last[nowdep-1]].next[0] do
    begin
    if depstr[nowdep][depstr[nowdep-1][last[nowdep-1]].next[i]].st=now.st then pd:=true;
    end;
if  pd=false then begin inc(depstr[nowdep-1][last[nowdep-1]].next[0]);depstr[nowdep-1][last[nowdep-1]].next[depstr[nowdep-1][last[nowdep-1]].next[0]]:=last[nowdep];end;
end;

begin
assign(input,'file.in');
assign(output,'file.out');
reset(input);
rewrite(output);
readln(n);
for i:=0 to 20 do
    begin
    for j:=1 to 50 do
        begin
        depstr[i,j].st:='';
        fillchar(depstr[i,j].next,sizeof(depstr[i,j].next),0);
        end;
    end;
for i:=1 to n do
    begin
    readln(ipt[i]);
    end;
for k:=1 to n do
    begin
    nowdep:=0;
    fillchar(last,sizeof(last),0);
    now.st:='';
    fillchar(now.next,sizeof(now.next),0);
    leng:=length(ipt[k]);
    for i:=1 to leng do
        begin
        if ipt[k][i]='/' then begin check(now,nowdep);if nowdep>0 then begin add(now);end;inc(nowdep);now.st:='';fillchar(now.next,sizeof(now.next),0);end;
        if ipt[k][i]<>'/' then now.st:=now.st+ipt[k][i];
        end;
    check(now,nowdep);if nowdep>0 then begin add(now);end;inc(nowdep);now.st:='';fillchar(now.next,sizeof(now.next),0);
    end;
fillchar(shu,sizeof(shu),0);
nowdep:=0;
dfs(nowdep,1);
close(input);
close(output);
end.
