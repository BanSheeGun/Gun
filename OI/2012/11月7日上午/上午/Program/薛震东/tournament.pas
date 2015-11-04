var a,b,i,n,x,y:longint;g:array[0..1000,0..1000]of longint;
    f:array[0..1000]of longint;
begin
     assign(input,'tournament.in');
     assign(output,'tournament.out');
     reset(input);
     rewrite(output);
     readln(n);
     for i:=1 to n*(n-1) div 2-1 do
         begin
              readln(x,y);
              g[x,y]:=1;
              g[y,x]:=-1;
              f[x]:=f[x]+1;
              f[y]:=f[y]+1;
         end;
     for i:=1 to n do
         if f[i]<>n-1 then begin a:=i;break;end;
     for i:=a+1 to n do
         if f[i]<>n-1 then begin b:=i;break;end;
     for i:=1 to n do
         if g[a,i]=g[i,b] then begin g[a,b]:=g[a,i];break;end;
     if g[a,b]=1 then writeln(a,' ',b)
	         else writeln(b,' ',a);
     close(input);
     close(output);
end.
