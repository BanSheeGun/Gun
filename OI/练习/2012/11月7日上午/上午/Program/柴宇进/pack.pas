program pack;
Var cnt,tv,tc,a,b,cc,i,j,top,n,m,x:longint;
    mono:array[0..400000] of Record v,c,mark:longint; End;
    aa,bb,f:array[0..2003] of longint;
    g:array[0..101,0..2003] of longint;
    
Procedure GetA;
Begin
     Readln(a,b);
     If a=0 then Exit;
     Inc(cnt);
     aa[cnt]:=a; bb[cnt]:=b;
End;

Procedure GetB;
Var k,i,j,tm:longint;
Begin
     k:=0;  tm:=cc;
     While 1 shl (k+1)<=cc do Inc(k); dec(k);
     For i:=0 to k do
     Begin
          Inc(top); mono[top].v:=a*(1 shl i);
                    mono[top].c:=b*(1 shl i);
          tm:=tm-(1 shl i);
     End;
     Inc(top);
     mono[top].v:=a*tm;
     mono[top].c:=b*tm;
     mono[top].mark:=2;
End;

Begin
Assign(input,'pack.in');
Reset(input);
Assign(output,'pack.out');
Rewrite(output);

  Readln(n,m);
  top:=0;
  Fillchar(mono,sizeof(mono),0);
  For i:=1 to n do
  Begin
       Read(x);
       Case x of
       1:GetA;
       2:Begin Readln(a,b,cc); GetB; End;
       3:Begin Readln(a,b); cc:=m div b; GetB; End;
       End;
  End;
  Fillchar(f,sizeof(f),128);
  f[0]:=0;
  For i:=1 to top do
  Begin
            For j:=m downto mono[i].c do
            If f[j-mono[i].c]+mono[i].v>f[j]
            then f[j]:=f[j-mono[i].c]+mono[i].v;
  End;
  Fillchar(g,sizeof(g),128);
  g[0]:=f;
  For i:=1 to cnt do
  Begin
       For x:=trunc(bb[i]/aa[i]) to m do
       Begin
            tc:=x;
            tv:=aa[i]*x*x-bb[i]*x;
            If tv>0
            then Begin
                      For j:=m downto tc do
                      Begin
                           If g[i-1][j-tc]+tv>g[i][j]
                           then g[i][j]:=g[i-1][j-tc]+tv;
                           If g[i-1][j]>g[i][j] then g[i][j]:=g[i-1][j];
                      End;
                 End;
       End;
  End;

  Writeln(g[cnt][m]);

Close(input);
Close(output);
End.


