var i,n,s,t,j,a,b,k:longint;
   map:array[1..50,1..50] of longint;
   pd:array[1..50,1..50] of boolean;
procedure enter;
begin
assign(input,'tournament.in');
assign(output,'tournament.out');
reset(input);
rewrite(output);
end;
procedure endit;
begin
close(input);
close(output);
end;
begin
enter;
readln(n);
fillchar(pd,sizeof(pd),false);
fillchar(map,sizeof(map),0) ;
for i:=1 to n*(n-1) div 2 -1 do
        begin
        readln(a,b);
        map[a,b]:=1;
        pd[a,b]:=true;
        pd[b,a]:=true;
        end;
for i:=1 to n do
        for j:=i+1 to n do
                if pd[i,j]=false then begin
                                      s:=i;
                                      t:=j;
                                      end;
for i:=1 to n do
        for j:=1 to n do
                for k:=1 to n do
                        begin
                        if (map[i,j]=1) and (map[j,k]=1) then map[i,k]:=1;
                        end;
if map[s,t]=1 then writeln(s,' ',t)
              else writeln(t,' ',s);
endit;
end.
