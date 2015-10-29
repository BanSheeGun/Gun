program pack(input,output);
var total:array[0..4] of longint;
    v,c:array[0..100000] of longint;
    f:array[0..5000000] of longint;
    n,i,j,k,t,p,q,x,l:longint;

procedure filein;
begin
  assign(input,'pack.in');
  assign(output,'pack.out');
  reset(input);
  rewrite(output);
end;

procedure fileout;
begin
  close(input);
  close(output);
end;

function max(a,b:longint):longint;
begin
  max:=a;
  if a<b then exit(b);
end;

function get(x,a,b:longint):longint;
begin
  exit(a*x*x-b*x);
end;

procedure chafen(p,q,x:longint);
var s:longint;
begin
  t:=0;
  s:=1;
  while x>s do
    begin
      inc(t);
      v[t]:=q*s;
      c[t]:=p*s;
      x:=x-s;
      s:=s shl 1;
    end;
  inc(t);
  v[t]:=q*x;
  c[t]:=p*x;
end;

begin
  filein;

  read(n,total[0]);
  for i:=1 to n do
    begin
      read(k,p,q);
      if k=1 then
        begin
          for l:=0 to total[0] do
            for j:=total[0] downto l do
              f[j]:=max(f[j],f[j-l]+get(l,p,q));
          continue;
        end;
      if k=2 then read(x);
      if k=3 then x:=total[0] div q;
      chafen(p,q,x);
      for p:=1 to t do
        for q:=total[0] downto v[p] do
          f[q]:=max(f[q],f[q-v[p]]+c[p]);
    end;
  writeln(f[total[0]]);

  fileout;
end.
