var fs,fx:array[1..100] of longint;
    x,y,z,i,n,m,ans:longint;
begin
 assign(input,'par.in');reset(input);
 assign(output,'par.out');rewrite(output);
 read(n);
 fillchar(fs,sizeof(fs),0);

 for z:=1 to n do begin
  read(m);
  fillchar(fx,sizeof(fx),63);
  for i:=1 to m do begin
   read(x);
   while x<>0 do begin
    read(y);
    if fs[x]+y<fx[i] then fx[i]:=fs[x]+y;
    read(x);
   end;
  end;
  fs:=fx;
 end;
 ans:=maxlongint;
 for i:=1 to m do
  if fx[i]<ans then ans:=fx[i];
 writeln(ans);
 close(input);close(output);
end.
