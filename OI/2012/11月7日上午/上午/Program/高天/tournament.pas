program ex1_1(input,output);
var a,f:array[0..10000,0..10000] of longint;
    i,j,n,x,y:longint;
begin
assign(input,'tournament.in');
reset(input);
assign(output,'tournament.out');
rewrite(output);
  fillchar(f,sizeof(f),0);
  read(n);
   for i:=1 to n*(n-1)div 2-1 do
     begin
      read(x,y);
      f[x,y]:=1;
      f[y,x]:=1;
    end;

for i:=1 to n do
 for j:=1 to n do
  if (i<>j)and(f[i,j]=0) then begin
                                writeln(i,' ',j);
                                halt;
                              end;
  close(input);close(output);
  end.



