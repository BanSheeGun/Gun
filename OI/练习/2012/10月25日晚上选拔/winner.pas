var n,num,ans:int64;
begin
 assign(input,'winner.in');reset(input);
 assign(output,'winner.out');rewrite(output);
 read(n);
 num:=1;
 ans:=0;
 while num<n do begin
  inc(ans);
  if ans mod 2=1 then num:=num*9
                 else num:=num*2;
 end;

 if (ans mod 2=1)or(num=1) then writeln('Nic')
                else writeln('Susan');
 close(input);close(output);
end.
