var t:array[1..3000000] of boolean;
    ans:array[1..3000000] of longint;
    n,i,j,top:longint;
begin
 assign(input,'prime.in');reset(input);
 assign(output,'prime.out');rewrite(output);
 read(n);
 fillchar(t,sizeof(t),true);
 top:=0;
 for i:=2 to n-1 do
  if t[i] then begin
   if (i mod 7=1)or(i mod 7=6) then begin
    for j:=2 to n div i do t[i*j]:=false;
    if n mod i=0 then begin
     inc(top);
     ans[top]:=i;
    end;
   end
   else t[i]:=false;
  end;
 if top=0 then writeln(-1)
 else begin
  write(n,':');
  for i:=1 to top do write(' ',ans[i]);
  writeln;
 end;
 close(input);close(output);
end.
