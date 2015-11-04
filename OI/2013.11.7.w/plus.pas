var a,c,b:array[0..10000] of longint;
    i,tmp:longint;
    aa,bb:ansistring;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
begin
 assign(input,'plus.in');reset(input);
 assign(output,'plus.out');rewrite(output);
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
 c[0]:=max(a[0],b[0]);
 for i:=1 to c[0] do begin
  c[i]:=c[i]+a[i]+b[i];
  c[i+1]:=c[i+1]+c[i] div 10000;
  c[i]:=c[i] mod 10000;
 end;
 while c[c[0]+1]<>0 do inc(c[0]);

 write(c[c[0]]);
 for i:=c[0]-1 downto 1 do begin
  write(c[i] div 1000 mod 10);
  write(c[i] div 100 mod 10);
  write(c[i] div 10 mod 10);
  write(c[i] mod 10);
 end;
 writeln;
 close(input);close(output);
end.
