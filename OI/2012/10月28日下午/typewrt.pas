type cw=array[0..251] of longint;
var a:array[1..1000] of cw;
    ss,s2,s10,s9,s0:cw;
    i,n:longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
procedure ch(var c:cw;a,b:cw);
var i,j,l:longint;
begin
 for i:=1 to a[0] do
  for j:=1 to b[0] do
   c[i+j-1]:=a[i]*b[j];

 for i:=1 to a[0]*b[0] do begin
  c[i+1]:=c[i+1]+c[i] div 10000;
  c[i]:=c[i] mod 10000;
 end;
 if c[a[0]*b[0]+1]=0 then c[0]:=a[0]*b[0]
                     else c[0]:=a[0]*b[0]+1;
end;

procedure plus(var a,b:cw);
var i,l:longint;
begin
 l:=max(a[0],b[0]);
 for i:=1 to l do begin
  a[i]:=a[i]+b[i];
  a[i+1]:=a[i+1]+a[i] div 10000;
  a[i]:=a[i] mod 10000;
 end;

 if a[l+1]<>0 then a[0]:=l+1
              else a[0]:=l;
end;
begin
 assign(input,'typewrt.in');reset(input);
 assign(output,'typewrt.out');rewrite(output);
 read(n);
 a[1][0]:=1;a[1][1]:=1;
 s10[0]:=1;s10[1]:=10;
 s9[0]:=1;s9[1]:=9;
 ss[0]:=1;ss[1]:=1;
 for i:=2 to n do begin
  s2:=ss;
  ss:=s0;
  ch(ss,s2,s10);
  ch(a[i],a[i-1],s9);
  plus(a[i],ss);
 end;

 write(a[n][a[n][0]]);
 for i:=a[n][0]-1 downto 1 do begin
  write(a[n][i] div 1000);
  write(a[n][i] div 100 mod 10);
  write(a[n][i] div 10 mod 10);
  write(a[n][i] mod 10);
 end;
 writeln;
 close(input);close(output);
end.
