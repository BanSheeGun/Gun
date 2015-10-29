var f:array[0..1000,0..1000]of longint;
    v,t:array[1..1000]of longint;
    x1,x2,k,n,m,i,j,temp,x,r:longint;
function max(a,b:longint):longint;
begin
      if a>b then max:=a
             else max:=b;
end;
begin
     assign(input,'pack.in');
     reset(input);
     assign(output,'pack.out');
     rewrite(output);
     readln(n,m);
     for i:=1 to n do
       begin
         read(x);
         if x=2 then  begin
                 readln(x1,x2,k);
                 if m div x2<k then begin
                 for j:=r+1 to r+k do
                     begin
                     v[j]:=x1;t[j]:=m div x2;
                     end;
                     r:=r+k;
                      end
                 else begin
                 for j:=r+1 to r+k do
                     begin
                     v[j]:=x1;t[j]:=x2;
                     end;
                     r:=r+k;
                      end;
                 end;
         if x=3 then begin
         readln(x1,x2);
         temp:=m div x2;
         for j:=r+1 to r+temp do
             begin
              v[j]:=x1;t[j]:=x2;
             end;
         r:=r+temp;
         end;
       end;
     for i:=1 to r do
         for j:=m downto 1 do
         begin
              if j<t[i] then f[i,j]:=f[i-1,j]
              else
              f[i,j]:=max(f[i-1,j],f[i-1,j-t[i]]+v[i]);
         end;
     writeln(f[r,m]);
     close(input);
     close(output);
end.
