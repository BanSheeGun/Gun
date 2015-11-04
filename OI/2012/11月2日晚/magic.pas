var s1,n2,s2,n3,n:int64;
begin
 assign(input,'magic.in');reset(input);
 assign(output,'magic.out');rewrite(output);
 read(n);
 if n=1 then writeln(1)
 else begin
  n2:=(n-1) div 2;
  s1:=n2*(n2+1) div 2;
  n3:=(n+1) div 2;
  s2:=n3*n2;
  s2:=s2+(n2+1)*(n2-2) div 2;
  writeln(s1+s2);
 end;
 close(input);close(output);
end.
