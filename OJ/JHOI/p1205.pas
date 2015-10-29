var a,f:array[0..5000] of longint;
    b:array[0..5000] of qword;
    n,i,j,ans,max:longint;
    sum:qword;
    t:boolean;
    c:array[1..65536] of boolean;
begin
 read(n);
 for i:=1 to n do
  read(a[i]);
   f[0]:=0;
   f[1]:=1;
   b[1]:=1;

   for i:=2 to n do
    begin
      b[i]:=0;
    t:=true;
      max:=0;
    fillchar(c,sizeof(c),true);
    for j:=i-1 downto 1 do
      begin
      if a[j]>a[i] then
       if f[j]>f[max] then
        begin
        t:=false;
         max:=j;
         b[i]:=b[max];
         fillchar(c,sizeof(c),true);
         c[a[j]]:=false;
        end
        else
       if f[j]=f[max] then
        begin
        t:=false;
        if c[a[j]] then
         begin
         c[a[j]]:=false;
         inc(b[i],b[j]);
        end;
        end;
       end;
      f[i]:=f[max]+1;
     if t then inc(b[i]);
     b[i]:=b[i] mod 10000;
    end;
    ans:=0;
    sum:=0;
    fillchar(c,sizeof(c),true);
    for j:=n downto 1 do
      begin
       if f[j]>ans then
        begin
         ans:=f[j];
         sum:=b[j];
         fillchar(c,sizeof(c),true);
         c[a[j]]:=false;
        end
        else
       if f[j]=ans then
        begin
        if c[a[j]] then
         begin
         c[a[j]]:=false;
         inc(sum,b[j]);
         sum:=sum mod 10000;
        end;
        end;
       end;
 writeln(ans,' ',sum mod 10000);
end.
