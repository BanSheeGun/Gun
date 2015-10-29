type arr=array[0..20] of string;
var a:array[0..100] of arr;
    n,i,j,k,t:longint;
    ts:arr;
    s:string;
function l(a,b:arr):boolean;
var i:longint;
begin
i:=1;
while a[i]=b[i] do inc(i);
if a[i]>b[i] then l:=true
             else l:=false;
end;
begin
assign(input,'file.in');
reset(input);
assign(output,'file.out');
rewrite(output);
readln(n);
for i:=1 to n do
    begin
    readln(s);
    t:=0;
    j:=1;
    for k:=1 to length(s) do
        if s[k]='/'
           then begin
                inc(t);
                a[i,t]:=copy(s,j,k-j);
                j:=k+1;
                end;
    inc(t);
    a[i,t]:=copy(s,j,k-j+1);
    end;
for i:=1 to n-1 do
    for j:=i+1 to n do
        if l(a[i],a[j]) then begin
                             ts:=a[i];
                             a[i]:=a[j];
                             a[j]:=ts;
                             end;
for i:=1 to n do
    begin
    j:=1;
    while a[i,j]=a[i-1,j] do inc(j);
    while a[i,j]<>'' do
        begin
        if j=1 then write(a[i,j])
               else begin
                    for k:=1 to j-2 do
                        write('|    ');
                    write('|----',a[i,j]);
                    end;
        writeln;
        inc(j);
        end;
    end;
close(input);
close(output);
end.