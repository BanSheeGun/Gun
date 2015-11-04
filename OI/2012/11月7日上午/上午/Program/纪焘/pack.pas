var  x,n,m,i,j,k,t,a,b,c:longint;
     d:array[1..100]of longint;
     f:array[0..2000]of longint;

begin
assign(input,'pack.in');reset(input);
assign(output,'pack.out');rewrite(output);
  read(n,m);
  for i:=1 to n do
    begin
      read(x);
      if x=2 then begin
                    read(a,b,c);
                    if b<m then begin
                                  j:=1;
                                  k:=1;
                                  if b*c>m then c:=m div b;
                                  repeat
                                    c:=c-j;
                                    d[k]:=j;
                                    j:=j*2;
                                    inc(k);
                                    until c<j;
                                   d[k]:=c;
                                   for j:=1 to k do
                                     for t:=m downto d[j]*b do
                                     if f[t-d[j]*b]+d[j]*a>f[t] then f[t]:=f[t-d[j]*b]+d[j]*a;
                                 end;
                  end;
      if x=3 then begin
                    read(a,b);
                    for j:=b to m do
                      if f[j-b]+a>f[j] then f[j]:=f[j-b]+a;
                  end;
      if x=1 then begin
                    read(a,b);
                    for j:=m downto 1 do
                      for t:=1 to j do
                        if f[j]<f[j-t]+a*sqr(t)-b*t then f[j]:=f[j-t]+a*sqr(t)-b*t;
                  end;
    end;
  writeln(f[m]);
close(input);
close(output);
end.
