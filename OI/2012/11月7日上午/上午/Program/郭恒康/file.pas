const tp:array[1..8] of string=('','|----','|    |----','|    |    |----','|    |    |    |----','|    |    |    |    |----','|    |    |    |    |    |----','|    |    |    |    |    |    |----');
var i,j,k,l,n,m,topl:longint;
    p:array[0..500] of ansistring;
    q:array[0..500,0..500] of ansistring;
    top:array[0..10000] of longint;
    al:array[0..10000] of ansistring;
    aldeep:array[0..10000] of longint;
    st:string;
    pan:boolean;
procedure sort(l,r: longint);
var   i,j:longint;
      x,y:ansistring;
begin
     i:=l;
     j:=r;
     x:=p[(l+r)>>1];
     repeat
       while p[i]<x do
        inc(i);
       while x<p[j] do
        dec(j);
       if not(i>j) then
         begin
            y:=p[i];
            p[i]:=p[j];
            p[j]:=y;
            inc(i);
            dec(j);
         end;
     until i>j;
   if l<j then
     sort(l,j);
   if i<r then
     sort(i,r);
end;
procedure startput;
const filename='file';
begin
  assign(input,filename+'.in');
  reset(input);
  assign(output,filename+'.out');
  rewrite(output);
end;
procedure overput;
begin
  close(input);
  close(output);
end;
begin
  startput;
  readln(n);
  for i:=1 to n do readln(p[i]);
  sort(1,n);
  for i:=1 to n do
  begin
    st:=p[i];
    k:=pos('/',st);
    while k<>0 do
    begin
      inc(top[i]);
      q[i][top[i]]:=copy(st,1,k-1);
      delete(st,1,k);
      k:=pos('/',st);
    end;
    inc(top[i]);
    q[i][top[i]]:=st;
  end;


  for i:=1 to n do
  begin
    for k:=1 to top[i] do
    begin
      pan:=true;
      for j:=1 to topl do
      if (al[j]=q[i][k])and(aldeep[j]=k) then
      begin
        pan:=false;
        break;
      end;
      if not pan then continue;
      writeln(tp[k],q[i][k]);
      inc(topl);
      al[topl]:=q[i][k];
      aldeep[topl]:=k;
    end;
  end;
  overput;
end.
