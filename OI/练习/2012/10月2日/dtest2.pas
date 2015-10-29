var a,b,f:array[0..100000] of longint;
    z,y,i,j,n,max,ans:longint;
begin
 assign(input,'dtest2.in');reset(input);
 assign(output,'dtest2.out');rewrite(output);
 read(z);
 for y:=1 to z do
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
    for j:=1 to i-1 do
      begin
      if a[j]<a[i] then
       if f[j]>f[max] then
        begin
         max:=j;
         b[i]:=b[max];
        end
        else
       if f[j]=f[max] then
        begin
         inc(b[i],b[j]);
        end;
       end;
     f[i]:=f[max]+1;
     if b[i]=0 then inc(b[i]);
    end;

   max:=1;ans:=1;
   for i:=2 to n do
    begin
     if f[i]=f[max] then begin inc(ans,b[i]); end;
     if f[i]>f[max] then begin max:=i;ans:=b[i] end;
    end;
   writeln(f[max],' ',ans);
  end;
  close(input);close(output);
end.
