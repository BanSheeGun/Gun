var a,b,c:array[0..2000] of qword;
    a1,b1:ansistring;
    i,j:longint;
begin
 assign(input,'chen.in');reset(input);
 assign(output,'chen.out');rewrite(output);
 readln(a1);
 readln(b1);

 case length(a1) mod 6 of
  1:a1:='00000'+a1;
  2:a1:='0000'+a1;
  3:a1:='000'+a1;
  4:a1:='00'+a1;
  5:a1:='0'+a1;
 end;
 a[0]:=length(a1) div 6;
 for i:=1 to a[0] do
  val(copy(a1,(a[0]-i)*6+1,6),a[i]);


 case length(b1) mod 6 of
  1:b1:='00000'+b1;
  2:b1:='0000'+b1;
  3:b1:='000'+b1;
  4:b1:='00'+b1;
  5:b1:='0'+b1;
 end;
 b[0]:=length(b1) div 6;
 for i:=1 to b[0] do
  val(copy(b1,(b[0]-i)*6+1,6),b[i]);

 for i:=1 to a[0] do
  for j:=1 to b[0] do begin
   c[i+j-1]:=c[i+j-1]+a[i]*b[j];
   c[i+j]:=qword(c[i+j]+c[i+j-1] div 1000000);
   c[i+j-1]:=qword(c[i+j-1] mod 1000000);
  end;

 c[0]:=a[0]+b[0]-1;
 while c[c[0]+1]<>0 do inc(c[0]);

 if (b[0]=1)and(b[1]=0) then c[0]:=1;
 write(c[c[0]]);
 for i:=c[0]-1 downto 1 do begin
  write(c[i] div 100000);
  write(c[i] div 10000 mod 10);
  write(c[i] div 1000 mod 10);
  write(c[i] div 100 mod 10);
  write(c[i] div 10 mod 10);
  write(c[i] mod 10);
 end;
 writeln;
 close(input);close(output);
end.
