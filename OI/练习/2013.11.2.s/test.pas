var n,k,p,i:longint;
begin
 assign(output,'hotel.in');rewrite(output);
 randomize;
 n:=random(10000)+1;
 p:=random(100)+1;
 k:=random(50)+1;
 writeln(n,' ',k,' ',p);
 for i:=1 to n do begin
  writeln(random(k),' ',random(100)+1);
 end;
 close(input);close(output);
end.
