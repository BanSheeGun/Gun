var a:array[0..2,1..600] of longint;
    c,v,fa:array[1..600] of longint;
    f:array[0..32000] of longint;
    n,m,i,j,k:longint;
procedure ff(x,y,z:longint);
begin
 if x<y then exit;
 if f[x]<f[x-y]+z then f[x]:=f[x-y]+z;
end;
begin
 fillchar(a,sizeof(a),0);
 read(m,n);
 for i:=1 to n do
  begin
   read(c[i],v[i],k);
   v[i]:=v[i]*c[i];
   if k<>0 then
    begin
     inc(a[0][k]);
     a[a[0][k]][k]:=i;
    end;
   fa[i]:=k;
  end;

 fillchar(f,sizeof(f),0);
 for i:=1 to n do
  if fa[i]=0 then
   begin
    if a[0][i]=0 then
     for j:=m downto c[i] do
       ff(j,c[i],v[i]);


    if a[0][i]=1 then
     for j:=m downto c[i] do
      begin
       ff(j,c[i],v[i]);
       ff(j,c[i]+c[a[1][i]],v[i]+v[a[1][i]]);
      end;

    if a[0][i]=2 then
     for j:=m downto c[i] do
     begin
       ff(j,c[i],v[i]);
       ff(j,c[i]+c[a[1][i]],v[i]+v[a[1][i]]);
       ff(j,c[i]+c[a[2][i]],v[i]+v[a[2][i]]);
       ff(j,c[i]+c[a[1][i]]+c[a[2][i]],v[i]+v[a[1][i]]+v[a[2][i]]);
     end;
   end;
 writeln(f[m]);
end.
