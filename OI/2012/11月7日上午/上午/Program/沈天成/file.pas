var a:array[0..100]of string;
    c:array[0..100,0..10]of string;
    b:array[1..100]of longint;
    i,j,m,n,k,t1,t2,l,f:longint;t:string;
begin
assign(input,'file.in');reset(input);
assign(output,'file.out');rewrite(output);
readln(n);
for i:=1 to n do begin readln(a[i]);a[i]:=a[i]+'/';end;
for i:=1 to n do for j:=1 to n-i do
 if a[j]>a[j+1] then begin t:=a[j];a[j]:=a[j+1];a[j+1]:=t;end;

for i:=1 to n do begin  k:=0;f:=0;t1:=0;t2:=0;
 for j:=1 to length(a[i]) do if a[i][j]='/' then
 begin if t2=0 then t2:=j else  begin t1:=t2;t2:=j;end;
  inc(k);t:=copy(a[i],t1+1,t2-t1-1);
  c[i,k]:=t;if (c[i,k]<>c[i-1,k])or(f=1)  then begin
   for l:=1 to k-2 do write('|    ');if k>1 then write('|----');
       writeln(t);f:=1;end;end;
 end;
close(input);close(output);
end.
