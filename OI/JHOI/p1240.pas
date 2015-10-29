var a,f,b:array[0..5000] of longint;
    n,i,j,sum,ans,max:longint;
    c:array[1..65536] of boolean;
begin
 read(n);
 for i:=1 to n do
  read(a[i]);
   fillchar(f,sizeof(f),0);
   fillchar(b,sizeof(b),0);
   f[0]:=0;
   f[1]:=1;
   b[1]:=1;

   for i:=2 to n do
    begin
      b[i]:=0;
      max:=0;
    fillchar(c,sizeof(c),true);
    for j:=i-1 downto 1 do
      begin
      if a[j]>a[i] then
       if f[j]>f[max] then
        begin
         max:=j;
         b[i]:=b[max];
         fillchar(c,sizeof(c),true);
         c[a[j]]:=false;
        end
        else
       if f[j]=f[max] then
        begin
        if c[a[j]] then
         begin
         c[a[j]]:=false;
         inc(b[i],b[j]);
        end;
        end;
       end;
     f[i]:=f[max]+1;
     if b[i]=0 then inc(b[i]);
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
        end;
        end;
       end;
 writeln(ans,' ',sum);
end.
