type maojin=^node;
        node=record
        s:string;
        son:array[1..15] of maojin;
        sum:longint;
        end;
var head,p,q:maojin;
    s,temp:string;
    j, i,n,pp:longint;
    pd:boolean;
    ss:array[1..15] of string;
procedure enter;
begin
assign(input,'file.in');
assign(output,'file.out');
reset(input);
rewrite(output);
end;
procedure endit;
begin
close(input);
close(output);
end;
function judge(a,b:string):boolean;
var la,lb,i,l:longint;
begin
la:=length(a);
lb:=length(b);
if la>lb then l:=lb
         else l:=la;
for i:=1 to l do
        if a[i]<b[i] then exit(false)
                     else if a[i]>b[i] then exit(true);
if la>lb then exit(true)
         else exit(false);
end;
procedure print(p:maojin;deep:longint);
var i,j,k,t:longint;
    tt:string;
    mark:array[1..15] of longint;
begin
if p^.sum=0 then begin
                 if deep=0 then writeln(p^.s)
                           else begin
                                for i:=1 to deep-1 do
                                     write('|    ');
                                writeln('|----',p^.s);
                                end;
                 end
            else begin
                  if deep=0 then writeln(p^.s)
                           else begin
                                for i:=1 to deep-1 do
                                     write('|    ');
                                writeln('|----',p^.s);
                                end;
                 for i:=1 to p^.sum do
                        //print(p^.son[i],s+' '+p^.son[i]^.s);
                     begin
                     mark[i]:=i;
                     ss[i]:=p^.son[i]^.s;
                     end;
                 for i:=1 to p^.sum do
                        for j:=i+1 to p^.sum do
                                if judge(ss[i],ss[j])
                                        then begin
                                             t:=mark[i];
                                             mark[i]:=mark[j];
                                             mark[j]:=t;
                                             tt:=ss[i];
                                             ss[i]:=ss[j];
                                             ss[j]:=tt;
                                             end;
                 for i:=1 to p^.sum do
                        begin
                        j:=mark[i];
                        print(p^.son[j],deep+1);
                        end;
                 end;
end;
begin
enter;
readln(n);
readln(s);
s:=s+'/';
pp:=pos('/',s);
new(head);
head^.s:=copy(s,1,pp-1);
head^.sum:=0;
delete(s,1,pp);
p:=head;
while length(s)>0 do
        begin
        pp:=pos('/',s);
        temp:=copy(s,1,pp-1);
        delete(s,1,pp);
        pd:=false;
        for i:=1 to p^.sum do
            if p^.son[i]^.s=temp then begin
                                         pd:=true;
                                         p:=p^.son[i];
                                         break;
                                         end;
        if not pd then begin
                       inc(p^.sum);
                       new(q);
                       q^.sum:=0;
                       q^.s:=temp;
                       p^.son[p^.sum]:=q;
                       p:=q;
                       end;
        end;
for j:=2 to n do
    begin
    readln(s);
    s:=s+'/';
    pp:=pos('/',s);
    delete(s,1,pp);
    p:=head;
    while length(s)>0 do
        begin
        pp:=pos('/',s);
        temp:=copy(s,1,pp-1);
        delete(s,1,pp);
        pd:=false;
        for i:=1 to p^.sum do
            if p^.son[i]^.s=temp then begin
                                         pd:=true;
                                         p:=p^.son[i];
                                         break;
                                         end;
        if not pd then begin
                       inc(p^.sum);
                       new(q);
                       q^.sum:=0;
                       q^.s:=temp;
                       p^.son[p^.sum]:=q;
                       p:=q;
                       end;
        end;
    end;
p:=head;
print(p,0);
endit;
end.
