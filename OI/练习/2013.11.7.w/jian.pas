var a,c,b:array[0..10000] of longint;
    i,tmp:longint;
    aa,bb:ansistring;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
begin
 assign(input,'jian.in');reset(input);
 assign(output,'jian.out');rewrite(output);
 readln(aa);
 readln(bb);
 tmp:=length(aa) mod 4;
 case tmp of
  1:aa:='000'+aa;
  2:aa:='00'+aa;
  3:aa:='0'+aa;
 end;
 a[0]:=length(aa) div 4;
 for i:=1 to length(aa) do begin
  tmp:=(length(aa)-i) div 4+1;
  a[tmp]:=a[tmp]*10+(ord(aa[i])-48);
 end;
 case length(bb) mod 4 of
  1:bb:='000'+bb;
  2:bb:='00'+bb;
  3:bb:='0'+bb;
 end;
 b[0]:=length(bb) div 4;
 for i:=1 to length(bb) do begin
  tmp:=(length(bb)-i) div 4+1;
  b[tmp]:=b[tmp]*10+ord(bb[i])-48;
 end;

 c:=a;
 for i:=1 to b[0] do begin
  c[i]:=c[i]-b[i];
  tmp:=i;
  while c[tmp]<0 do begin
   c[tmp]:=c[tmp]+10000;
   inc(tmp);
   c[tmp]:=c[tmp]-1;
  end;
 end;
 while (c[c[0]]=0)and(c[0]>1)do dec(c[0]);
 write(c[c[0]]);
 for i:=c[0]-1 downto 1 do begin
  write(c[i] div 1000 mod 10);
  write(c[i] div 100 mod 10);
  write(c[i] div 10 mod 10);
  write(c[i] mod 10);
 end;
 if c[0]=0 then writeln(0);
 writeln;
 close(input);close(output);
end.
