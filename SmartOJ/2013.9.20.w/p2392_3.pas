var a:array[0..10000] of longint;
    q:array[0..20000] of longint;
    i,m,n,top,j,k,d:longint;

function gcd(a,b:longint):longint;
begin
 if a mod b= 0 then exit(b)
               else exit(gcd(b,a mod b));
end;

begin
 fillchar(a,sizeof(a),0);
 read(m,n);
 for i:=m+1 to m+n do
  q[i]:=i;


 for i:=2 to n do begin
  k:=i;
  for j:=m+n downto m+1 do begin
   d:=gcd(k,q[j]);
   k:=k div d;
   q[j]:=q[j] div d;
   if k=1 then break;
  end;
 end;

 a[1]:=1;top:=1;
 for i:=m+1 to m+n do begin
  for j:=top downto 1 do begin
   a[j]:=a[j]*q[i];
   k:=j;
   while a[k] div 100000>0 do begin
    a[k+1]:=a[k] div 100000+a[k+1];
    a[k]:=a[k] mod 100000;
    inc(k);
   end;
  end;
  while a[top+1]<>0 do inc(top);
 end;

 write(a[top]);
 for i:=top-1 downto 1 do begin
  write(a[i] div 100000 mod 10);
  write(a[i] div 10000 mod 10);
  write(a[i] div 1000 mod 10);
  write(a[i] mod 100 mod 10);
  write(a[i] mod 10);
 end;
 writeln;
end.
