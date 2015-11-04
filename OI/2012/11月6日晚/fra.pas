var ans,an:array[1..30000] of qword;
    a,b,e,dee,i:longint;
    t:boolean;
function gcd(a,b:qword):qword;
begin
 if a mod b=0 then exit(b);
 exit(gcd(b,a mod b));
end;
procedure jian(var a,b,e:longint);
var lcm:qword;
begin
 lcm:=qword(b*e div gcd(b,e));
 a:=qword(a*lcm div b-1*lcm div e);
 b:=lcm;
 lcm:=gcd(a,b);
 a:=a div lcm;
 b:=b div lcm;
end;
procedure dfs(e,deep,a,b:longint);
var i,x,y:longint;
begin
 ans[deep]:=e;
 x:=a;y:=b;
 jian(x,y,e);
 if deep=dee then exit;
 if deep=dee-1 then begin
  if x=1 then begin
   t:=true;
   ans[dee]:=y;
   if an[dee]>ans[dee] then an:=ans;
  end;
 end
 else begin
  for i:=e+1 to 30000 do begin
   if (1/i*2.5>x/y) then
   if x/y>=1/i then dfs(i,deep+1,x,y);
  end;
 end;
end;
begin
 assign(input,'fra.in');reset(input);
 assign(output,'fra.out');rewrite(output);
 read(a,b);
 dee:=gcd(a,b);
 t:=false;
 if a<>dee then begin
  dee:=1;
 repeat
  inc(dee);
  an[dee]:=maxlongint;
  for e:=2 to 30000 do
   if (1/e*2.5>a/b) then
   if a/b>=1/e then  begin
    dfs(e,1,a,b);
   end;
 until t;

 write(a,'/',b,' = ');
 for i:=1 to dee-1 do
  write('1/',an[i],' + ');
 writeln('1/',an[dee]);
 end
 else begin
  writeln(a,'/',b,' = ',1,'/',b div dee);
 end;
 close(input);close(output);
end.
