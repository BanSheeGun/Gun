type cw=record
      root:array[1..10] of string;
      a0:longint;
     end;
var a:array[1..50] of string;
    fl:array[0..50] of cw;
    n,i,k,j:longint;
procedure sort(l,r:longint);
var i,j:longint;
    x,y:string;
begin
 i:=l;j:=r;
 x:=a[(l+r)>>1];
 repeat
  while a[i]<x do inc(i);
  while x<a[j] do dec(j);
  if i<=j then begin
   y:=a[i];a[i]:=a[j];a[j]:=y;
   inc(i);dec(j);
  end;
 until i>j;
 if i<r then sort(i,r);
 if l<j then sort(l,j);
end;
function min(a,b:longint):longint;
begin
 if a<b then exit(a);
 exit(b);
end;
procedure print(n,deep:longint);
var i:longint;
begin
 if (deep=1)and(fl[n-1].root[1]<>fl[n].root[deep]) then writeln(fl[n].root[deep])
 else begin
  for i:=1 to deep-2 do
   write('|    ');
  writeln('|----',fl[n].root[deep]);
 end;
end;
begin
 assign(input,'file.in');reset(input);
 assign(output,'file.out');rewrite(output);
 readln(n);
 for i:=1 to n do
  readln(a[i]);

 sort(1,n);
 fl[0].a0:=0;
 for i:=1 to n do begin
  fl[i].a0:=0;
  k:=pos('/',a[i]);
  while k<>0 do begin
   inc(fl[i].a0);
   fl[i].root[fl[i].a0]:=copy(a[i],1,k-1);
   delete(a[i],1,k);
   k:=pos('/',a[i]);
  end;
  inc(fl[i].a0);
  fl[i].root[fl[i].a0]:=a[i];
 end;

 for i:=1 to n do begin
  for j:=1 to min(fl[i].a0,fl[i-1].a0) do
   if fl[i].root[j]<>fl[i-1].root[j] then break;

  for k:=j to fl[i].a0 do
   print(i,k);
 end;
 close(input);close(output);
end.
