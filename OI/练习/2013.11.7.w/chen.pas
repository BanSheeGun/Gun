var a,c,b:array[0..10000] of qword;
    i,tmp,j:longint;
    aa,bb:ansistring;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
begin
 assign(input,'chen.in');reset(input);
 assign(output,'chen.out');rewrite(output);
 fillchar(a,sizeof(a),0);
 fillchar(b,sizeof(b),0);
 fillchar(c,sizeof(c),0);
 readln(aa);
 readln(bb);
 tmp:=length(aa) mod 7;
 case tmp of
  1:aa:='000000'+aa;
  2:aa:='00000'+aa;
  3:aa:='0000'+aa;
  4:aa:='000'+aa;
  5:aa:='00'+aa;
  6:aa:='0'+aa;
 end;
 a[0]:=length(aa) div 7;
 for i:=1 to length(aa) do begin
  tmp:=(length(aa)-i) div 7+1;
  a[tmp]:=a[tmp]*10+(ord(aa[i])-48);
 end;

 tmp:=length(bb) mod 7;
 case tmp of
  1:bb:='000000'+bb;
  2:bb:='00000'+bb;
  3:bb:='0000'+bb;
  4:bb:='000'+bb;
  5:bb:='00'+bb;
  6:bb:='0'+bb;
 end;
 b[0]:=length(bb) div 7;
 for i:=1 to length(bb) do begin
  tmp:=(length(bb)-i) div 7+1;
  b[tmp]:=b[tmp]*10+(ord(bb[i])-48);
 end;



 c[0]:=a[0]+b[0]-1;
 for i:=1 to a[0] do
  for j:=1 to b[0] do begin
   tmp:=i+j-1;
   c[tmp]:=a[i]*b[j]+c[tmp];
   while c[tmp] div 10000000>0 do begin
    c[tmp+1]:=c[tmp+1] + c[tmp] div 10000000;
    c[tmp]:=c[tmp] mod 10000000;
    inc(tmp);
   end;
  end;
 if (a[0]=1)and(a[1]=0) then writeln(0)
 else if (b[0]=1)and(b[1]=0) then writeln(0) else
 begin
  while c[c[0]+1]<>0 do inc(c[0]);
  write(c[c[0]]);
  for i:=c[0]-1 downto 1 do begin
   write(c[i] div 1000000 mod 10);
   write(c[i] div 100000 mod 10);
   write(c[i] div 10000 mod 10);
   write(c[i] div 1000 mod 10);
   write(c[i] div 100 mod 10);
   write(c[i] div 10 mod 10);
   write(c[i] mod 10);
  end;
  writeln;
 end;
 close(input);close(output);
end.
