var n,t,i,j,k,m,l,la,lb:longint;
    s,ss:string;
    tf:array[1..50] of longint;
    f:array[1..50,1..5] of string;
    a:array[1..5] of string;

procedure setup;
begin
assign(input,'file.in');
reset(input);
assign(output,'file.out');
rewrite(output);
end;

procedure endit;
begin
close(input);
close(output);
end;

begin
setup;
  readln(n);
  readln(s);
  t:=1; l:=length(s); ss:='';
  while (s[t]<>'/')and(t<=l) do
        begin
        ss:=ss+s[t];
        inc(t);
        end;
  for i:=1 to n do for j:=1 to 5 do f[i,j]:='';
  for i:=1 to n do
      begin
      j:=t+1; k:=1; l:=length(s);
      while j<=l do
            begin
            if s[j]='/' then inc(k) else f[i,k]:=f[i,k]+s[j];
            inc(j);
            tf[i]:=k;
            end;
      readln(s);
      end;
  for i:=1 to n-1 do
      for j:=i+1 to n do
          begin
          k:=1;
          while (k<=tf[i])and(k<=tf[j])and(f[i,k]=f[j,k]) do inc(k);
          if k>tf[j] then begin a:=f[j]; f[j]:=f[i]; f[i]:=a; t:=tf[j]; tf[j]:=tf[i]; tf[i]:=t; end
                     else begin
                          m:=1; la:=length(f[i,k]); lb:=length(f[j,k]);
                          while (m<=la)and(m<=lb)and(f[i,k,m]=f[j,k,m]) do inc(m);
                          if m>lb then begin a:=f[j]; f[j]:=f[i]; f[i]:=a; t:=tf[j]; tf[j]:=tf[i]; tf[i]:=t; end
                                  else if f[i,k,m]>f[j,k,m] then begin a:=f[j]; f[j]:=f[i]; f[i]:=a; t:=tf[j]; tf[j]:=tf[i]; tf[i]:=t; end;
                          end;
          end;
  writeln(ss);
  for k:=1 to tf[1] do
      begin
      for j:=1 to k-1 do write('|    ');
      writeln('|----',f[1,k]);
      end;
  for i:=2 to n do
      begin
      k:=1;
      while (k<=tf[i-1])and(f[i,k]=f[i-1,k]) do inc(k);
      for m:=k to tf[i] do
          begin
          for j:=1 to m-1 do write('|    ');
          writeln('|----',f[i,m]);
          end;
      end;
endit;
end.
