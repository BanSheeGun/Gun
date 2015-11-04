var a:array[-100..200,-100..200] of boolean;
    x,y,w,c:array[1..2000000] of longint;
    t:array[1..100,1..100,0..100] of boolean;
    n,m,d,f,p,ans,xx,yy,i,j:longint;
    st:string;
    ok:boolean;
    fx:array[1..4] of longint=(1,0,-1,0);
    fy:array[1..4] of longint=(0,1,0,-1);
begin
 assign(input,'escape.in');reset(input);
 assign(output,'escape.out');rewrite(output);
 readln(n,m,d);
 fillchar(a,sizeof(a),false);
 for i:=1 to n do begin
  readln(st);
  for j:=1 to m do
   if st[j]='P' then a[i][j]:=true;
 end;
 fillchar(t,sizeof(t),true);
 f:=1;
 x[1]:=1;
 y[1]:=1;
 w[1]:=0;
 c[1]:=d;
 f:=1;p:=1;
 fillchar(t,sizeof(t),true);
 t[1][1][d]:=false;
 ok:=false;
 repeat
  for i:=1 to 4 do begin
   j:=1;
   xx:=x[f]+fx[i]*j;
   yy:=y[f]+fy[i]*j;
   if (a[xx][yy])and(t[xx][yy][c[f]]) then begin
    inc(p);
    w[p]:=w[f]+1;
    x[p]:=xx;y[p]:=yy;c[p]:=c[f];
    t[xx][yy][c[p]]:=false;
    if (xx=n)and(yy=m) then begin
     ok:=true;
     ans:=w[p];
     break;
    end;
   end;

   for j:=2 to c[f] do begin
    xx:=x[f]+fx[i]*j;
    yy:=y[f]+fy[i]*j;
    if (a[xx][yy])and(t[xx][yy][c[f]-j]) then begin
     inc(p);
     w[p]:=w[f]+1;
     x[p]:=xx;y[p]:=yy;c[p]:=c[f]-j;
    t[xx][yy][c[p]]:=false;
     if (xx=n)and(yy=m) then begin
      ok:=true;
      ans:=w[p];
      break;
     end;
    end;
   end;
  if ok then break;
  end;
  inc(f);
  if ok then break;
 until f>p;
 if ok then writeln(ans)
       else writeln('impossible');
 close(input);close(output);
end.
