var f,b:array[1..100086] of longint;
    test,testnum,m,i,n,x,y,l,r:longint;
    ch:char;
function find(x:longint):longint;
var temp:longint;
begin
 if x=f[x] then exit(x);
 temp:=find(f[x]);
 b[x]:=b[x]+b[f[x]];
 b[x]:=b[x] mod 2;
 f[x]:=temp;
 exit(f[x]);
end;
begin
 readln(test);
 for testnum:=1 to test do begin
  readln(n,m);
  for i:=1 to n do begin
   f[i]:=i;
   b[i]:=0;
  end;
  for i:=1 to m do begin
   read(ch);
   case ch of
    'A':begin
     read(ch);
     readln(x,y);
     l:=find(x);
     r:=find(y);
     if l<>r then writeln('Not sure yet.')
     else begin
      if b[x]<>b[y] then writeln('In different gangs.')
      else writeln('In the same gang.');
     end;
    end;
    'D':begin
     read(ch);
     readln(x,y);
     l:=find(x);
     r:=find(y);
     f[l]:=r;
     b[l]:=b[y]-b[x]+1;
     b[l]:=b[l] mod 2;
    end;
   end;
  end;
 end;
end.
