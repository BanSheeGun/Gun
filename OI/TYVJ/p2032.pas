var fx:array[1..20] of longint;
    ans:array[1..1000,1..20] of longint;
    t:array[1..1000,1..20] of boolean;
    d:array[1..2,1..600000] of longint;
    f,p,i,ze,n,m,a,b,a1,b1,an,na:longint;
begin
 read(n,m);
 for i:=1 to m do begin
  read(fx[i]);
  if fx[i]=0 then ze:=i;
 end;
 fillchar(t,sizeof(t),true);
 fillchar(ans,sizeof(ans),63);
 na:=ans[1][1];
 f:=1;p:=1;
 d[1][1]:=1;d[2][1]:=ze;
 ans[1][ze]:=0;
 t[1][ze]:=false;
 repeat
  a1:=d[1][f];b1:=d[2][f];

  for i:=1 to m do
   if (fx[i]+a1>0)and(fx[i]+a1<=n) then begin
   a:=fx[i]+a1;b:=i;
   if ans[a][b]>ans[a1][b1]+abs(a1-a)*2+abs(b1-b) then begin
    ans[a][b]:=ans[a1][b1]+abs(a1-a)*2+abs(b1-b);
    if t[a][b] then begin
     inc(p);
     d[1][p]:=a;
     d[2][p]:=b;
     t[a][b]:=false;
    end;
   end;
  end;

  t[a1][b1]:=true;
  inc(f);
 until f>p;
 an:=na;
 for i:=1 to m do
  if ans[n][i]<an then an:=ans[n][i];
 if an=na then writeln(-1)
          else writeln(an);
end.
