var names:array[1..100]of string;
    root,st:string;
    i,n,j:longint;

  procedure sort(l,r: longint);
      var
         i,j: longint;
         x,y: string;
      begin
         i:=l;
         j:=r;
         x:=names[(l+r) div 2];
         repeat
           while names[i]<x do
            inc(i);
           while x<names[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=names[i];
                names[i]:=names[j];
                names[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

begin
 assign(input,'file.in');reset(input);
 assign(output,'file.out');rewrite(output);
  readln(n);
  for i:=1 to n do
   begin
    readln(st);
    for j:=1 to length(st) do
     if st[j]='/' then break;
    names[i]:=copy(st,j+1,length(st)-j);
   end;
  root:=copy(st,1,j-1);
  sort(1,n);
  writeln(root);
  for i:=1 to n do
   writeln('|----',names[i]);
 close(input);close(output);
end.
