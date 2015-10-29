const maxn=2020; maxlen=52;
type rec=record nxt:array[0..maxlen]of longint; ch:string[20]; end;
var n,i,t,tot,last,num,tt,tmp,j,k,cnt,q:longint;
    flag:boolean;
    s,ts,a,b:string;
    tree:array[0..maxn]of rec;
procedure dfs(now,dep:longint);
var i:longint;
begin
for i:=1 to dep-1 do write('|    ');
if dep<>0 then write('|----');
write(tree[now].ch);
writeln;
for i:=1 to tree[now].nxt[0] do
    begin
    dfs(tree[now].nxt[i],dep+1);
    end;
end;
begin
assign(input,'file.in');
reset(input);
assign(output,'file.out');
rewrite(output);
readln(n);
for q:=1 to n do
    begin
    readln(s);
    t:=pos('/',s);
    if (t=0) then
       begin
       if tot=0 then
          begin
          tot:=1;
          tree[1].ch:=s;
          end;
       continue;
       end;
    if (t<>0) then
       begin
       if tot=0 then
          begin
          ts:=copy(s,1,t-1);
          tot:=1; tree[1].ch:=ts;
          end;
       delete(s,1,t);
       last:=1;
       t:=pos('/',s);
       while length(s)>0 do
         begin
         tt:=0;
         if t=0 then begin t:=length(s)+1;tt:=1; end;
         ts:=copy(s,1,t-1);
         flag:=false;
         num:=0;
         for i:=1 to tree[last].nxt[0] do
             begin
             if ts=tree[tree[last].nxt[i]].ch then
                begin
                flag:=true;
                num:=tree[last].nxt[i];
                break;
                end;
             end;
         if not flag then
            begin
            inc(tot); cnt:=tree[last].nxt[0]+1; inc(tree[last].nxt[0]);
            tree[last].nxt[cnt]:=tot;
            tree[tot].ch:=ts;
            last:=tot;
            end
         else last:=num;
         if tt=1 then
            begin
            break;
            end;
         delete(s,1,t);
         t:=pos('/',s);
         end;
       end;
    end;
for i:=1 to tot do
    begin
    for j:=1 to tree[i].nxt[0]-1 do
        begin
        for k:=j+1 to tree[i].nxt[0] do
            begin
            a:=tree[tree[i].nxt[j]].ch; b:=tree[tree[i].nxt[k]].ch;
            if a>b then
               begin
               tmp:=tree[i].nxt[j];
               tree[i].nxt[j]:=tree[i].nxt[k];
               tree[i].nxt[k]:=tmp;
               end;
            end;
        end;
    end;
dfs(1,0);
close(input);
close(output);
end.