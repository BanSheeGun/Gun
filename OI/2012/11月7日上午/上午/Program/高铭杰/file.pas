type  t=^node;
      node=record
           name:string;
           son:array[0..30]of t;
           num,step:longint;
           end;
var tree,now,p:t;
    n,i,j,k,start:longint;
    a,ming:string;
    pd:boolean;

procedure kai;
begin
assign(input,'file.in');reset(input);
assign(output,'file.out');rewrite(output);
end;
procedure guan;
begin
close(input);close(output);
end;

procedure sort(now:t);
var i,j:longint;
    p:t;
begin
for i:=1 to now^.num-1 do
    for j:=i+1 to now^.num do
        if now^.son[i]^.name>now^.son[j]^.name
           then begin p:=now^.son[i];
                      now^.son[i]:=now^.son[j];
                      now^.son[j]:=p;
                      end;
end;

procedure wri(now:t);
var i:longint;
begin
if now^.step=1 then begin writeln(now^.name);end
else

begin
write('|');
for i:=1 to now^.step-2  do
    write('    ','|');
writeln('----',now^.name);
end;

if now^.num<>0 then begin
                   sort(now);
                   for i:=1 to now^.num do
                       wri(now^.son[i]);
                   end;
end;

function copy(a:string;x,y:longint):string;
var i:longint;
begin
copy:='';
for i:=x to y do
    copy:=copy+a[i];
end;

begin
kai;
readln(n);
new(tree);
tree^.step:=0;tree^.num:=0;
for k:=1 to n do
    begin
    now:=tree;
    readln(a);
    start:=1;
    for i:=1 to length(a)do
        if a[i]='/'then begin
                        ming:=copy(a,start,i-1);
                        start:=i+1;
                        pd:=false;
                        for j:=1 to now^.num do
                            if now^.son[j]^.name=ming
                               then begin pd:=true;now:=now^.son[j];break;end;
                        if pd=false then begin
                                         inc(now^.num);
                                         new(p);
                                         now^.son[now^.num]:=p;
                                         now^.son[now^.num]^.name:=ming;
                                         now^.son[now^.num]^.step:=now^.step+1;
                                         now:=now^.son[now^.num];
                                         end;
                        end;
    ming:=copy(a,start,length(a));
                        pd:=false;
                        for j:=1 to now^.num do
                            if now^.son[j]^.name=ming
                               then begin pd:=true;now:=now^.son[j];break;end;
                        if pd=false then begin
                                         inc(now^.num);
                                         new(p);
                                         now^.son[now^.num]:=p;
                                         now^.son[now^.num]^.name:=ming;
                                         now^.son[now^.num]^.step:=now^.step+1;
                                         now:=now^.son[now^.num];
                                         end;
    end;

{write}
wri(tree^.son[1]);
guan;
end.
