var b:array[1..100] of string;
    y,st1,st2:string;
    n,i,j:longint;

begin
 assign(input,'file.in');
 assign(output,'file.out');
 reset(input);
 rewrite(output);
 readln(n);
 for i:=1 to n do
  begin
   readln(st1);
   st2:=copy(st1,1,pos('/',st1)-1);
   delete(st1,1,pos('/',st1));
   b[i]:=copy(st1,1,length(st1));
  end;
  for i:=1 to n-1 do
   for j:=i+1 to n do
    if b[i]>b[j] then
     begin
      y:=b[i];
      b[i]:=b[j];
      b[j]:=y;
     end;
    writeln(st2);
    for i:=1 to n do
     writeln('|----',b[i]);
  close(input);close(output);
end.