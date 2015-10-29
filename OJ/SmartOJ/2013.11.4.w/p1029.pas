var a:array[' '..'z'] of longint;
    st:ansistring;
    i,ans:longint;
begin
 readln(st);
 ans:=0;
 a[' ']:=1;
 a['a']:=1;
 a['b']:=2;
 a['c']:=3;
 a['d']:=1;
 a['e']:=2;
 a['f']:=3;
 a['g']:=1;
 a['h']:=2;
 a['i']:=3;
 a['j']:=1;
 a['k']:=2;
 a['l']:=3;
 a['m']:=1;
 a['n']:=2;
 a['o']:=3;
 a['p']:=1;
 a['q']:=2;
 a['r']:=3;
 a['s']:=4;
 a['t']:=1;
 a['u']:=2;
 a['v']:=3;
 a['w']:=1;
 a['x']:=2;
 a['y']:=3;
 a['z']:=4;
 for i:=1 to length(st) do
  inc(ans,a[st[i]]);
 writeln(ans);
end.