var a:array[1..500,1..500]of integer;
    h:array[1..500]of longint;
    n,x,y,i,j,k:longint;
begin
     assign(input,'tournament.in');
     reset(input);
     assign(output,'tournament.out');
     rewrite(output);
     readln(n);
     for i:=1 to n*(n-1) div 2-1 do
       begin
         readln(x,y);
         inc(h[x]);
         inc(h[y]);
         a[x,y]:=1;
       end;
     for k:=1 to n do
         for i:=1 to n do
             for j:=1 to n do
                 if(i=k)or(i=j)or(k=j) then
                 continue
             else if(a[i,k]=1)and(a[k,j]=1) then
                        a[i,j]:=1;
     for i:=1 to n do
         if h[i]=n-2 then begin x:=i;break;end;
     for j:=i+1 to n do
         if h[j]=n-2 then begin y:=j;break;end;
     if a[x,y]=1 then writeln(x,' ',y)
                 else writeln(y,' ',x);
     close(input);
     close(output);
end.