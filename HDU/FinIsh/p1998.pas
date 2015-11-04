var a:array[1..20,1..20] of longint;
    x,y,i,j,n,z,zz:longint;
procedure w(k:longint);
begin
 if k<10 then write('   ',k)
 else if k<100 then write('  ',k)
 else write(' ',k)	
end;
begin
 read(z);
 for zz:=1 to z do begin
  read(n);
  fillchar(a,sizeof(a),0);
  x:=1; y:=(n+1) div 2;a[x][y]:=1;
  for i:=2 to n*n do begin
   dec(x); inc(y);
   if (x=0) then
    if y=n+1 then begin
     x:=2;y:=n;
    end
    else x:=n;
   if y=n+1 then y:=1;
   if a[x][y]<>0 then begin inc(x,2);dec(y); end;
   a[x][y]:=i;
  end;

  for i:=1 to n do begin
   for j:=1 to n do w(a[i][j]);
   writeln;
  end;
 end;
end.
