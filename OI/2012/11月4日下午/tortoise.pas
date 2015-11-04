var a1:array[1..350] of longint;
    dl:array[1..4,1..1000000] of longint;
    ps:array[1..4] of longint;
    ans:array[0..40,0..40,0..40,0..40] of longint;
    t:array[0..40,0..40,0..40,0..40] of boolean;
    f,p,n,m,i,j,k,a,b,c,d,aa,bb,cc,dd:longint;
begin
 assign(input,'tortoise.in');reset(input);
 assign(output,'tortoise.out');rewrite(output);
 read(n,m);
 for i:=1 to n do
  read(a1[i]);
 for i:=1 to m do begin
  read(k);
  inc(ps[k]);
 end;
 fillchar(t,sizeof(t),true);
 t[0][0][0][0]:=false;
 ans[0][0][0][0]:=a1[1];
 f:=1;p:=1;
 repeat
  a:=dl[1][f];
  b:=dl[2][f];
  c:=dl[3][f];
  d:=dl[4][f];
  for i:=1 to 4 do begin
   if dl[i][f]+1<=ps[i] then begin
    inc(p);
    dl[1][p]:=a;
    dl[2][p]:=b;
    dl[3][p]:=c;
    dl[4][p]:=d;
    inc(dl[i][p]);
    aa:=dl[1][p];
    bb:=dl[2][p];
    cc:=dl[3][p];
    dd:=dl[4][p];
    if ans[a][b][c][d]+a1[aa*1+bb*2+cc*3+dd*4+1]>ans[aa][bb][cc][dd] then begin
     ans[aa][bb][cc][dd]:=ans[a][b][c][d]+a1[aa*1+bb*2+cc*3+dd*4+1];
     if t[aa][bb][cc][dd] then t[aa][bb][cc][dd]:=false
                          else dec(p);
    end
    else dec(p);
   end;
  end;
  t[a][b][c][d]:=true;
  inc(f);
 until f>p;
 writeln(ans[ps[1]][ps[2]][ps[3]][ps[4]]);
 close(input);close(output);
end.
