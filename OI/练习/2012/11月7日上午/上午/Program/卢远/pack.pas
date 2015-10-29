var f:array[0..4000]of longint;
    va:array[1..200,1..2]of longint;
    vb,vc,wb,wc,nb:array[1..200]of longint;
    m,n,i,a,b,c,j,k,x:longint;

function min(a,b:longint):longint;
begin
  if a<b then exit(a) else exit(b);
end;

begin
 assign(input,'pack.in');reset(input);
 assign(output,'pack.out');rewrite(output);
  read(n,m);
  i:=0;
  while i<n do
   begin
    inc(i);
    read(x);
    case x of
    1:begin read(a,b);va[i,1]:=a;va[i,2]:=b;end;
    2:begin read(a,b,c);vb[i]:=b;wb[i]:=a;while c>1 do begin dec(c);inc(n);inc(i);vb[i]:=b;wb[i]:=a;end;end;
    3:begin read(a,b);vc[i]:=b;wc[i]:=a;end;
    end;
   end;
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    if vb[i]<>0 then
     for j:=m downto vb[i] do
       if f[j]<f[j-vb[i]]+wb[i] then
        f[j]:=f[j-vb[i]]+wb[i];

  for i:=1 to n do
    if (va[i,1]<>0)or(va[i,2]<>0) then
     for j:=m downto 1 do
      for k:=1 to j do
       if f[j]<f[j-k]+va[i,1]*k*k-va[i,2]*k then
        f[j]:=f[j-k]+va[i,1]*k*k-va[i,2]*k;

   for i:=1 to n do
    if vc[i]<>0 then
     for j:=vc[i] to m do
       if f[j]<f[j-vc[i]]+wc[i] then
        f[j]:=f[j-vc[i]]+wc[i];

  writeln(f[m]);
 close(input);close(output);
end.
