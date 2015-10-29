var a,b,c:array[0..2000] of longint;
    a1,b1:ansistring;
    i,j:longint;
begin
 assign(input,'jian.in');reset(input);
 assign(output,'jian.out');rewrite(output);
 readln(a1);
 readln(b1);

 case length(a1) mod 4 of
  1:a1:='000'+a1;
  2:a1:='00'+a1;
  3:a1:='0'+a1;
 end;
 a[0]:=length(a1) div 4;
 for i:=1 to a[0] do
  val(copy(a1,(a[0]-i)*4+1,4),a[i]);


 case length(b1) mod 4 of
  1:b1:='000'+b1;
  2:b1:='00'+b1;
  3:b1:='0'+b1;
 end;
 b[0]:=length(b1) div 4;
 for i:=1 to b[0] do
  val(copy(b1,(b[0]-i)*4+1,4),b[i]);

 for i:=1 to a[0] do begin
  c[i]:=a[i]-b[i]+c[i];
  if c[i]<0 then begin
   dec(a[i+1]);
   c[i]:=c[i]+10000;
  end;
 end;
 c[0]:=a[0];
 while (c[c[0]]=0)and(c[0]>0) do dec(c[0]);

 write(c[c[0]]);
 for i:=c[0]-1 downto 1 do begin
  write(c[i] div 1000);
  write(c[i] div 100 mod 10);
  write(c[i] div 10 mod 10);
  write(c[i] mod 10);
 end;
 writeln;
 close(input);close(output);
end.
