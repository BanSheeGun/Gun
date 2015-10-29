var n,i,j,k,p,q,y:longint;
    a,temp:string;
    s:array[1..100] of string;
    c:array[1..100,1..100] of string;
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
procedure ch(w:string; g,dep,x:longint);
var i:longint;
begin
  for i:=x to length(w) do
    begin
      if w[i]<>'/' then c[g,dep]:=c[g,dep]+w[i]
                   else begin if w[i+1]<>'' then ch(w,g,dep+1,i+1)
                                            else exit;
                                                        break;
                        end;

    end;
end;
begin
  setup;
  readln(n);
  for i:=1 to n do
    readln(s[i]);
  k:=0;
  while s[1][k+1]<>'/' do
    begin
      inc(k);
      a:=a+s[1][k];
    end;
  writeln(a);
  for i:=1 to n do
    ch(s[i],i,2,k+2);
  for y:=2 to 5 do
    begin
      for i:=1 to n-1 do
        for j:=i+1 to n do
          for p:=1 to length(c[i,y]) do
            if (c[i,y-1]=c[j,y-1]) and (ord(c[i,y][p])>ord(c[j,y][p]))
              then begin
                     for q:=y to 5 do
                       begin
                         temp:=c[i,q];
                         c[i,q]:=c[j,q];
                         c[j,q]:=temp;
                       end;
                     break;
                   end;
       break;
    end;
  for i:=1 to n do
    for j:=2 to 5 do
    begin
      if (c[i,j]<>'') then
        begin
          if c[i,j]<>c[i-1,j] then
            begin
              for p:=1 to j-2 do
                write('|    ');
              writeln('|----',c[i,j]);
            end
        end;
    end;
  endit;
end.
