program  Ffile;

var k,l1,l2,ll,t,last,n,i,j,len:longint;
    str:string;
    lq:array[0..51] of longint;
    s:array[0..51] of string;
    pro:array[0..51,0..51] of string;
    pd:boolean;

procedure setup;
begin
assign(input,'file.in'); assign(output,'file.out');
reset(input); rewrite(output);
end;

procedure endit;
begin
close(input); close(output);
end;

procedure test;
var i,j:longint;
begin
for i:=1 to n do
    begin
    for j:=1 to lq[i] do
        write(pro[i][j]);
    writeln;
    end;
end;

procedure sort(l,r: longint);
var i,j,temp:longint;
    mid,tmp:string;
begin
i:=l; j:=r;
mid:=s[(l+r) div 2];
repeat
while s[i]<mid do
      inc(i);
while mid<s[j] do
      dec(j);
if not(i>j) then begin
                 tmp:=s[i]; s[i]:=s[j]; s[j]:=tmp;
                 temp:=lq[i]; lq[i]:=lq[j]; lq[j]:=temp;
                 inc(i); dec(j);
                 end;
until i>j;
if l<j then sort(l,j);
if i<r then sort(i,r);
end;

begin
setup;
readln(n);
readln(s[1]);
lq[1]:=length(s[1]);
for i:=1 to lq[1] do
    if s[1][i]='/' then begin len:=i; break; end;
str:=copy(s[1],1,len-1); writeln(str);
for i:=2 to n do
    readln(s[i]);
for i:=1 to n do
    begin
    delete(s[i],1,len);
    lq[i]:=length(s[i]);
    end;
sort(1,n);
for i:=1 to n do
    begin
    t:=0; last:=1;
    for j:=1 to lq[i] do
        if s[i][j]='/' then begin
                            inc(t);
                            pro[i][t]:=copy(s[i],last,j-last);
                            last:=j+1;
                            end;
    inc(t);
    pro[i][t]:=copy(s[i],last,lq[i]-last+1);
    lq[i]:=t;
    end;
t:=1;
for i:=0 to 51 do
    s[i]:='';
for i:=1 to n do
    begin
    for j:=1 to lq[i] do
        begin
        if s[j]<>pro[i][j] then begin
                                write('|----'); writeln(pro[i][j]);
                                s[j]:=pro[i][j];
                                if j<>lq[i] then for k:=1 to j do
                                                     write('|    ');
                                end
                           else write('|    ');
        end;
    end;
endit;
end.
