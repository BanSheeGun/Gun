var n,j,i,f1,k,i1:longint;
    f:array[0..50,0..10]of string;
    s:array[1..50]of string;
    s1:string;
procedure getfather(s:string;i1:longint);
var l,i,j:longint;
begin
i:=1;
j:=1;
l:=length(s);
while l>=i do
      begin
      if s[i]='/' then begin f[i1][j]:=copy(s,1,i-1);delete(s,1,i);l:=l-i;inc(j);i:=0;end;
      inc(i);
      end;
f[i1][j]:=s;
f1:=j;
end;
begin
assign(input,'file.in');
assign(output,'file.out');
reset(input);
rewrite(output);
readln(n);
j:=1;
for i:=1 to n do
    begin
    readln(s[i]);
    if i=1 then begin
                while s[i][j]<>'/' do inc(j);
                writeln(copy(s[i],1,j-1));
                end;
    delete(s[i],1,j);
    end;
for i:=1 to n-1 do
    for j:=i to n do
        if s[i]>s[j] then begin s1:=s[i];s[i]:=s[j];s[j]:=s1;end;
i:=1;
while i<=n do
    begin
    f1:=0;
    getfather(s[i],i);
    j:=1;
    while f[i,j]=f[i1,j] do
          begin
          inc(j);
          end;
    for i1:=j to f1 do
        begin
        for k:=1 to i1-1 do
            begin
            write('|    ');
            end;
        {if i1=f1 then write('|    '); }
        writeln('|----',f[i][i1]);
        end;
    i1:=i;
    inc(i);
    end;
close(input);
close(output);

end.
