var sum,n,i,k:longint;
begin
 assign(input,'seq.in');reset(input);
 assign(output,'seq.out');rewrite(output);
 read(n);
 for i:=1 to n do begin
  read(k);
  sum:=trunc(sqrt((k-1)*2));
  if (k-1)=(sum*sum+sum)/2 then writeln(1)
                      else writeln(0);
 end;
 close(input);close(output);
end.
