type cw=array[0..10000] of longint;
var a,b,ans:cw;
    n,i:longint;

procedure chen(var a:cw;b:cw);
var c:cw;
    i,j:longint;
begin
 fillchar(c,sizeof(c),0);
 c[0]:=a[0]+b[0]-1;
 for i:=1 to a[0] do
  for j:=1 to b[0] do begin
   c[i+j-1]:=c[i+j-1]+a[i]*b[j];
   c[i+j]:=c[i+j]+c[i+j-1] div 10000;
   c[i+j-1]:=c[i+j-1] mod 10000;
  end;
 while c[c[0]+1]>0 do inc(c[0]);
 a:=c;
end;


procedure ef(n:longint);
begin
 if n=0 then exit;
 if n=1 then begin
  b:=a;
  exit;
 end;
 ef(n div 2);
 chen(b,b);
 if n mod 2=1 then chen(b,a);
end;
begin
 assign(input,'equation.in');reset(input);
 assign(output,'equation.out');rewrite(output);
 read(n);
 while n<>0 do begin
  fillchar(a,sizeof(a),0);
  a[0]:=1;
  a[1]:=3;
  fillchar(b,sizeof(b),0);
  b[0]:=1;
  b[1]:=1;
  ef((n-1) div 3+(n-1) mod 3);
  ans:=b;
  fillchar(a,sizeof(a),0);
  a[0]:=1;
  a[1]:=7;
  fillchar(b,sizeof(b),0);
  b[0]:=1;
  b[1]:=1;
  ef((n+2) div 3-1);
  chen(ans,b);
  write(ans[ans[0]]);
  for i:=ans[0]-1 downto 1 do begin
   write(ans[i] div 1000 mod 10);
   write(ans[i] div 100 mod 10);
   write(ans[i] div 10 mod 10);
   write(ans[i] mod 10);
  end;
  writeln;
  readln(n);
 end;
 close(input);close(output);
end.
