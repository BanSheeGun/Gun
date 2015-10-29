var i,j,k,jj,a,b,c,n,m,t,maxx:longint;
    f:array[0..100,0..500] of longint;

procedure setup;
begin
assign(input,'pack.in');
reset(input);
assign(output,'pack.out');
rewrite(output);
end;

procedure endit;
begin
close(input);
close(output);
end;

function max(x,y:longint):longint;
begin
if x>y then max:=x else max:=y;
end;

begin
setup;
  readln(n,m);
  read(t);
  case t of
  1:read(a,b);
  2:read(a,b,c);
  3:read(a,b);
  end;
  for i:=0 to 1 do for j:=0 to m do f[i,j]:=0;
  if t=1
     then for i:=1 to m do f[1,i]:=a*i*i-b*i
     else if t=2 then for i:=1 to c do
                          f[1,b*i]:=a*i
                 else begin i:=1; while i*b<=m do begin f[1,i*b]:=i*a; inc(i); end; end;

  for k:=2 to n do
      begin
      read(t);
      case t of
      1:begin
        read(a,b);
        for i:=1 to m do
            begin
            f[k,i]:=a*i*i-b*i; if f[k,i]<0 then f[k,i]:=0;
            for j:=1 to i do
                f[k,i]:=max(f[k-1,j]+a*(i-j)*(i-j)-b*(i-j),f[k,i]);
            end;
        end;
      2:begin
        read(a,b,c);
        for i:=1 to m do f[k,i]:=f[k-1,i];
        for i:=b to m do
            begin
            j:=1;
            while (j<=c)and((i-j*b)>=0) do
                  begin
                  f[k,i]:=max(f[k,i],f[k-1,i-j*b]+j*a);
                  inc(j);
                  end;
            end;
        end;
      3:begin
        read(a,b);
        for i:=1 to m do
            begin
            j:=i; jj:=0;
            while j>=0 do
                  begin
                  f[k,i]:=max(f[k,i],f[k-1,j]+jj*a);
                  j:=j-b; inc(jj);
                  end;
            end;
        end;
      end;
      end;
  maxx:=0;
  for i:=1 to m do  if f[n,i]>maxx then maxx:=f[n,i];
  writeln(maxx);
endit;
end.