var a:array[1..1250] of longint;
    t,c,win,lose,k,i,j,x,y,n,ans:longint;
    ansx1,ansy1:array[1..1250] of longint;
    b:array[1..1250,1..2] of longint;

begin
  assign(input,'tournament.in');
  assign(output,'tournament.out');
  reset(input);
  rewrite(output);
  read(n);
  fillchar(a,sizeof(a),0);
  k:=n*(n-1) div 2-1;
  for i:=1 to k do
   begin
    read(x,y);
    a[x]:=a[x]+1;
    a[y]:=a[y]+1;
    b[i,1]:=x;
    b[i,2]:=y;
   end;
   for i:=1 to n do
    if (a[i]=n-2) and (ans=0) then
     begin
      x:=i;
      ans:=1;
     end
    else if (a[i]=n-2) and (ans=1) then
     begin
      y:=i;
      ans:=2;
     break;
     end;
  for i:=1 to k do
   begin
    if (b[i,1]=x) and (b[i,2]=y) then begin win:=x; lose:=y; break; end
     else if (b[i,1]=y) and (b[i,2]=x) then begin win:=y; lose:=x; break; end;
   end;
   if (win=0) and (lose=0) then
    begin
      for i:=1 to k do
       begin
        if b[i,1]=x then begin inc(t); ansx1[t]:=b[i,2]; end;
        if b[i,2]=y then begin inc(c); ansy1[c]:=b[i,1]; end;
       end;
       for i:=1 to t do
        begin
         for j:=1 to c do
          if ansx1[i]=ansy1[j] then begin win:=x; lose:=y; break; end;
        end;
    end;
   if (win=0) and (lose=0) then begin win:=y; lose:=x; end;
   writeln(win,' ',lose);
   close(input);close(output);
end.