var n,i,j,x,y,k:longint;
    a:array[1..5000,1..5000]of longint;
    pd:boolean;
begin
  assign(input,'tournament.in');
  reset(input);
  assign(output,'tournament.out');
  rewrite(output);
  read(n);
  fillchar(a,sizeof(a),0);
  for i:=1 to (n*(n-1)div 2-1) do
      begin
        read(x,y);
        a[x,y]:=1;
        a[y,x]:=-1;
      end;
  for i:=1 to n-1 do
      for j:=i+1 to n do
          if a[i,j]=0 then begin
                             pd:=true;
                             for k:=1 to n do
                                 if (j<>k)and(a[j,k]=1) then if a[i,k]=-1 then begin pd:=false;break;end;
                             if pd=true then writeln(i,' ',j)
                                        else writeln(j,' ',i);
                             close(input);
                             close(output);
                             exit;
                           end;
end.