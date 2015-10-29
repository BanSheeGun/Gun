type cw=record
      s:array[1..60] of longint;
      l:longint;
     end;
var f:array[1..101,0..100] of cw;
    n,i,k,j:longint;
    ans,s0,s1,s3:cw;


function max(a,b:longint):longint;
begin
 if a>b then exit(a);
  exit(b);
end;

procedure p(var a:cw;b:cw);
var i,len:longint;
begin
 for i:=1 to max(b.l,a.l) do
  begin
   a.s[i]:=a.s[i]+b.s[i];
   a.s[i+1]:=a.s[i+1]+a.s[i] div 10;
   a.s[i]:=a.s[i] mod 10;
  end;
 len:=max(a.l,b.l);
 if a.s[len+1]<>0 then len:=len+1;
 a.l:=len;
end;




begin
 assign(input,'diagrams.in');reset(input);
 assign(output,'diagrams.out');rewrite(output);
 read(n);
 fillchar(ans.s,sizeof(ans.s),0);
 fillchar(s1.s,sizeof(s1.s),0);
 fillchar(s0.s,sizeof(s0.s),0);
 fillchar(f,sizeof(f),0);
 s0.l:=0;s1.l:=1;
 s1.s[1]:=1;

 for i:=n downto 1 do begin
  f[i][0]:=s1;
  p(f[i][1],s1);
  p(f[i][1],f[i+1][1]);
 end;

 for i:=n-1 downto 1 do
  for j:=2 to n-i+1 do begin
   p(f[i][j],f[i+1][j]);
   p(f[i][j],f[i][j-1]);
  end;

 for i:=1 to n do
  p(ans,f[1][i]);
 for i:=ans.l downto 1 do
  write(ans.s[i]);
 writeln;
 close(input);close(output);
end.
