var f:array[0..100000,-1..100] of boolean;
    j,m,ans,i,n:longint;
    k:array[1..100] of longint;
begin
 m:=0;
 read(ans,n);
 fillchar(f,sizeof(f),false);
 f[0][0]:=true;
 for i:=1 to n do begin
  read(k[i]);
  for j:=m downto 0 do
   if f[j][0] then begin
    case f[j][-1] of
     true:begin
      f[j+k[i]][-1]:=true;
     end;
     false:begin
      if f[j+k[i]][0] then begin
       f[j+k[i]][-1]:=true;
      end
      else begin
       f[j+k[i]]:=f[j];
       f[j+k[i]][i]:=true;
      end;
     end;
    end;
   end;
  inc(m,k[i]);
 end;

 if f[ans][-1] then writeln(-1)
 else if not f[ans][0] then writeln(0)
 else begin
  for i:=1 to n do
   if not f[ans][i] then write(i,' ');
  writeln;
 end;
end.

