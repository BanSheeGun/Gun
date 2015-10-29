type ch=
  record
  fa,sn:longint;
  n:string;
  s:array[1..20] of longint;
  end;
var a:array[1..100] of ch;
    c:char;
    ss:string;
    p:boolean;
    i,ii,j,t,tt,now,num,l:longint;
procedure print(now,dep:longint);
var i,j:longint;
begin
if dep>=1 then write('|');
for i:=1 to dep-1 do
    write('    |');
if dep>=1 then write('----');
writeln(a[now].n);
for i:=1 to a[now].sn do
    print(a[now].s[i],dep+1);
end;
procedure sort(now:longint);
var i,j,t:longint;
begin
if a[now].sn=0 then exit;
for i:=1 to a[now].sn do
    for j:=i+1 to a[now].sn do
    if a[a[now].s[i]].n>a[a[now].s[j]].n then
       begin
       t:=a[now].s[j];
       a[now].s[j]:=a[now].s[i];
       a[now].s[i]:=t;
       end;
for i:=1 to a[now].sn do
    sort(a[now].s[i]);
end;
begin
assign(input,'file.in');
reset(input);
assign(output,'file.out');
rewrite(output);
readln(num);
ss:='';
now:=1;
for ii:=1 to num do
    begin
    while not eoln do
       begin
       read(c);
       if c='/' then
             begin
              inc(t);
              if t=1 then
                begin
                a[1].n:=ss;
                l:=1;
                end;
              if t>1 then
                begin
                p:=false;
                for i:=1 to now do
                   if a[i].n=ss then begin p:=true; l:=i; end;
                if not p then
                   begin
                   inc(now);
                   a[now].n:=ss;
                   a[now].fa:=l;
                   inc(a[l].sn);
                   tt:=a[l].sn;
                   a[l].s[tt]:=now;
                   l:=now;
                   end;
                end;
                ss:='';
             end;
       if c<>'/' then ss:=ss+c;
       end;
       inc(now);
       a[now].n:=ss;
       a[now].fa:=l;
       inc(a[l].sn);
       tt:=a[l].sn;
       a[l].s[tt]:=now;
       l:=now;
       ss:='';
       readln;
       t:=0;
    end;
sort(1);
print(1,0);
close(input);
close(output);
end.
