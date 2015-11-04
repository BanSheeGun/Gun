var n,i,j,t,nn,mm,aa1,aa2,bb1,bb2:longint;
    x,a,b,a1,a2,b1,b2:array[1..3000] of longint;
    p:boolean;
begin
assign(input,'tournament.in');
reset(input);
assign(output,'tournament.out');
rewrite(output);
readln(n);
for i:=1 to n*(n-1) div 2-1 do
    begin
    readln(a[i],b[i]);
    inc(x[a[i]]);
    inc(x[b[i]]);
    end;
t:=0;
for i:=1 to n do
    begin
    if x[i]<n-1 then
       begin
       if t=0 then begin nn:=i; inc(t); end
              else mm:=i;
       end;
    end;
for i:=1 to n*(n-1)div 2-1 do
    begin
    if a[i]=nn then
      begin
      inc(aa1);
      a1[aa1]:=b[i];
      end;
    if b[i]=nn then
      begin
      inc(aa2);
      a2[aa2]:=a[i];
      end;
    if a[i]=mm then
      begin
      inc(bb1);
      b1[bb1]:=b[i];
      end;
    if b[i]=mm then
      begin
      inc(bb2);
      b2[bb2]:=a[i];
      end;
    end;
p:=false;
for i:=1 to aa2 do
    begin
    if p then break;
    for j:=1 to bb1 do
        if a2[i]=b1[j] then
            begin
            t:=nn;
            nn:=mm;
            mm:=t;
            p:=true;
            break;
            end;
    end;
writeln(nn,' ',mm);
close(input);
close(output);
end.