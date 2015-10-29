var x1,x2,y1,y2:array[1..1000000] of longint;
    ans,min,i,j,t1,t2,tx,ty,x,n,m:longint;
begin
 assign(input,'NightOfKnights.in');reset(input);
 assign(output,'NightOfKnights.out');rewrite(output);
 read(n,m);
 t1:=0;
 t2:=0;
 for i:=1 to n do
  for j:=1 to m do begin
   read(x);
   case x of
    1:begin
     inc(t1);
     x1[t1]:=i;
     y1[t1]:=j;
    end;
    2:begin
     inc(t2);
     x2[t2]:=i;
     y2[t2]:=j;
    end;
    3:begin
     tx:=i;ty:=j;
    end;
   end;
  end;
 min:=maxlongint;
 for i:=1 to t1 do begin
  x:=abs(x1[i]-tx)+abs(y1[i]-ty);
  if x<min then min:=x;
 end;

 ans:=0;
 for i:=1 to t2 do begin
  x:=abs(x2[i]-tx)+abs(y2[i]-ty);
  if x<min then inc(ans);
 end;
 writeln(ans);
 close(input);close(output);
end.
