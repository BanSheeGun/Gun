//Gobble Restaurant!!

var m,n,i,j,k,rc,fc,cs,ans:longint;
    a,b,c,d,f,g,u:array[0..40000] of longint;

function max(a,b:longint):longint;
  begin
    if a>b then exit(a) else exit(b);
  end;

function slope(j,k:longint):extended;
  var ct:extended;
  begin
    ct:=(g[j]+b[i]*j*j+c[i]*j-g[k]-b[i]*k*k-c[i]*k)/(j-k);
    exit(ct);
  end;

begin

  assign(input,'pack.in');
  assign(output,'pack.out');
  reset(input);
  rewrite(output);

  readln(n,m);
  for i:=1 to m do f[i]:=-maxlongint;
  f[0]:=0;
  for i:=1 to n do
    begin
      read(a[i]);
      if a[i]=2 then readln(b[i],c[i],d[i])
                else readln(b[i],c[i]);
    end;
  for i:=1 to n do
    if a[i]=3 then
      for j:=c[i] to m do
        if (f[j-c[i]]<>-maxlongint) and
           (f[j-c[i]]+b[i]>f[j]) then
              f[j]:=f[j-c[i]]+b[i];
  for i:=1 to n do
    if a[i]=2 then
      for j:=1 to d[i] do
        for k:=m downto c[i] do
          if (f[k-c[i]]<>-maxlongint) and
             (f[k-c[i]]+b[i]>f[k]) then
                f[k]:=f[k-c[i]]+b[i];
  for i:=1 to n do
    if a[i]=1 then
      begin
        g:=f;
        rc:=1;
        fc:=1;
        u[rc]:=0;
        for j:=1 to m do
          begin
            while (rc<fc) and (slope(u[rc],u[rc+1])>2*b[i]*j) do inc(rc);
            f[j]:=max(f[j],g[u[rc]]+b[i]*(j-u[rc])*(j-u[rc])-c[i]*(j-u[rc]));
            if g[j]<>-maxlongint then
              begin
                while (rc<fc) and (slope(u[fc],j)>slope(u[fc-1],u[fc])) do dec(fc);
                inc(fc);
                u[fc]:=j;
              end;
          end;
      end;
  ans:=0;
  for i:=0 to m do
    if f[i]>ans then ans:=f[i];
  writeln(ans);

  close(input);
  close(output);
end.

