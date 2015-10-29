var a,ans,b,a4,x:extended;
begin
 assign(input,'tennis.in');reset(input);
 assign(output,'tennis.out');rewrite(output);
 while not eof do begin
  readln(a);
  b:=1-a;
  a4:=a*a*a*a;
  ans:=a4;
  ans:=ans+4*a4*b;
  ans:=ans+10*a4*b*b;
  a4:=a*a*a;
  x:=a*a*(1+b)/(1-a*b);
  ans:=ans+20*a4*b*b*b*x;
  write(ans:0:11,' ');
  writeln;
 end;
 close(input);close(output);
end.
