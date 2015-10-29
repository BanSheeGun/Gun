var n,x,y,i,j,max:longint;
    f,p,w:array[0..200] of longint;
    a:array[1..200,1..200] of longint;
procedure pr(k:longint);
begin
 if p[k]=0 then write(k)
        else
          begin
           pr(p[k]);
           write(' ',k);
          end;
end;
begin
 assign(input,'work5.in');reset(input);
 assign(output,'work5.out');rewrite(output);
 read(n);
 for i:=1 to n do
  read(w[i]);

 fillchar(a,sizeof(a),0);
 read(x,y);
 while (x<>0)and(y<>0) do
  begin
   a[y][x]:=1;
   read(x,y);
  end;

 f[0]:=0;
 fillchar(f,sizeof(f),0);
 for i:=1 to n do
  begin
   max:=0;
   for j:=1 to n do
    if a[i][j]=1 then
     if f[j]>f[max] then
       begin
        max:=j;
       end;
   p[i]:=max;
   f[i]:=f[max]+w[i];
  end;

 max:=1;
 for i:=2 to n do
  if f[i]>f[max] then max:=i;

 pr(max);
 writeln;
 writeln(f[max]);
 close(input);close(output);
end.
