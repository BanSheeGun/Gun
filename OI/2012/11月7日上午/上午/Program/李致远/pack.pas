var f:array[0..10000] of longint;
    xx,i,vt,top,n,a,b,c,v:longint;
    x:array[0..1000] of longint;

procedure cf(m:longint);
var k,sum:longint;
begin
 k:=1;
 sum:=v;
 top:=0;
 while sum>0 do
  begin
   inc(top);
   x[top]:=k;
   sum:=sum-k;
   k:=k*2;
  end;
 top:=top+1;
 x[top]:=sum;
end;

procedure blei(v,c,m:longint);
var j,k,c1,v1:longint;
begin
  cf(m);
  for j:=1 to top do
   begin
    v1:=v*x[j];
    c1:=c*x[j];
   for k:=c downto 0 do
    begin
     if f[k+c1]>f[k]+v1 then
      f[k+c1]:=f[k]+v1;
    end;
   end;
end;

procedure clei(v,c:longint);
var i:longint;
begin
  for i:=vt downto 0 do
   if f[i]<f[i-c]+v then f[i]:=f[i-c]+v;
end;

begin
 assign(input,'pack.in');
 assign(output,'pack.out');
 reset(input);
 rewrite(output);
 read(n,vt);
  fillchar(f,sizeof(f),63);
  f[0]:=0;
  for i:=1 to n do
  begin
   read(xx);
   if xx=2 then
    begin
      read(a,b,c);
      blei(a,b,c);
    end;
  if xx=3 then
   begin
    read(a,b);
    clei(a,b);
  end;
  end;
  writeln(f[vt]);
  close(input);close(output);
end.