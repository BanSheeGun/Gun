program tournament;
Var h,g:array[0..100,0..100] of boolean;
    n,i,j,x,y:longint;
    Flag:boolean;
Procedure Floyd;
Var i,j,k:longint;
Begin
     For k:=1 to n do
       For i:=1 to n do
         For j:=1 to n do
         g[i][j]:=g[i][j] or (g[i][k] and g[k][j]);
End;

Begin
Assign(input,'tournament.in');
Reset(input);
Assign(output,'tournament.out');
Rewrite(output);

  Readln(n);
  Fillchar(h,sizeof(h),false);
  Fillchar(g,sizeof(g),false);
  For i:=1 to n*(n-1) div 2 - 1 do
  Begin
       Readln(x,y);
       h[x][y]:=true;
       h[y][x]:=true;
       g[x][y]:=true;
  End;
  Floyd;
  Flag:=false;
  For i:=1 to n-1 do
  If not(Flag) then
    For j:=i+1 to n do
    If (h[i][j]=false) and (Flag=false)
    then Begin
              If g[i][j]
              then Begin
                        Writeln(i,' ',j);
                        Flag:=true;
                   End
              else Begin
                        If g[j][i]
                        then Begin
                                  Writeln(j,' ',i);
                                  Flag:=true;
                             End;
                   End;
         End;

Close(input);
Close(output);
End.


