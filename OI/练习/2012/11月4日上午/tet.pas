var x1,x2,y1,y2,h:array[0..20001] of longint;
    max,d,s,n,w,x,y,i,j:longint;
begin
 assign(input,'tet.in');reset(input);
 assign(output,'tet.out');rewrite(output);
 read(d,s,n);     max:=0;
 for i:=1 to n do begin
  read(d,s,w,x,y);
  x1[i]:=x;y1[i]:=y;
  x2[i]:=x+d;y2[i]:=y+s;
  h[i]:=w;
  for j:=1 to i-1 do begin
   if not( (x1[j]>=x2[i]) or (x2[j]<=x1[i]) or (y1[j]>=y2[i]) or (y2[j]<=y1[i])) and(h[j]+w>h[i]) then h[i]:=h[j]+w;
  end;
  if max<h[i] then max:=h[i];
 end;
 writeln(max);
 close(input);close(output);
end.
