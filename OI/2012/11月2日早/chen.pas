var a,b:array[1..10000] of longint;
    ans:array[1..100000] of qword;
    a1,b1:ansistring;
    t1,t2,i,j,max:longint;
begin
 assign(input,'chen.in');reset(input);
 assign(output,'chen.out');rewrite(output);
 readln(a1);
 readln(b1);
 t1:=length(a1);
 t2:=length(b1);

 case t1 mod 4 of
  1:a1:='000'+a1;
  2:a1:='00'+a1;
  3:a1:='0'+a1;
 end;

 case t2 mod 4 of
  1:b1:='000'+b1;
  2:b1:='00'+b1;
  3:b1:='0'+b1;
 end;

 t1:=length(a1);
 t2:=length(b1);


 for i:=1 to t1 div 4 do
  val(copy(a1,t1+1-i*4,4),a[i]);
 for i:=1 to t2 div 4 do
  val(copy(b1,t2+1-i*4,4),b[i]);
 max:=0;
 for i:=1 to t2 div 4 do begin
  for j:=1 to t1 div 4 do begin
   ans[i+j-1]:=qword(b[i]*a[j]+ans[i+j-1]);
  end;
  for max:=1 to i+j-1 do begin
   ans[max+1]:=ans[max+1]+ans[max] div 10000;
   ans[max]:=ans[max] mod 10000;
  end;

  while ans[max+1]<>0 do begin
   inc(max);
   ans[max+1]:=ans[max+1]+ans[max] div 10000;
   ans[max]:=ans[max] mod 10000;
  end;

 end;
 while (ans[max]=0)and(max>1) do dec(max);
 write(ans[max]);
 for i:=max-1 downto 1 do begin
  write(ans[i] div 1000 mod 10);
  write(ans[i] div 100 mod 10);
  write(ans[i] div 10 mod 10);
  write(ans[i] mod 10);
 end;
 writeln;
 close(input);close(output);
end.
