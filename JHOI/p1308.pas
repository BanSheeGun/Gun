var x,y:array[0..30000] of qword;
    i,deep:longint;
    f:boolean;
    a,b:qword;
function gcd(m,n:qword):qword;
begin
 if m mod n=0 then exit(n);
 exit(gcd(n,m mod n));
end;
procedure jia(j:longint);
var gcm:qword;
begin
 gcm:=b*j div gcd(b,j);
 a:=(gcm div b)*a-1*gcm div j;
 b:=gcm;

 gcm:=gcd(a,b);
 a:=a div gcm;
 b:=b div gcm;
end;

procedure try(k:longint);
var i:longint;
    a1,a2:qword;
begin
 if (k=deep)and(b mod a=0)and(b div a>x[k-1])
  then
   begin
    f:=false;
    x[k]:=b div a;
    if x[k]<y[k] then
      y:=x;
    exit;
   end
  else
   if k<deep then
   begin
    for i:=x[k-1]+1 to 30000 do
     if (1/i<a/b) then
     begin
      if (1/i*2.5<(a/b)) then exit;
      a1:=a;
      a2:=b;
      x[k]:=i;
      jia(i);
      try(k+1);
      a:=a1;
      b:=a2;
     end;
   end;
end;
begin
 read(a,b);

 fillchar(x,sizeof(x),0);
 fillchar(y,sizeof(y),63);
 deep:=0;
 f:=true;
 while f do
  begin
   inc(deep);
   try(1);
  end;

 for i:=1 to deep-1 do
  write(y[i],' ');
 writeln(y[deep]);
end.
