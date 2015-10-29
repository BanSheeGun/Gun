var n,k,i,ls,t,j,y,d,e,x,lts:longint;
    s1,s2,s,ts,tems:string;
    a:array[1..250]of shortstring;
begin
assign(input,'file.in');
reset(input);
assign(output,'file.out');
rewrite(output);
  readln(n);
  s1:='|----';
  s2:='|    ';
  k:=0;
  for i:=1 to n do
      begin
        readln(s);
        ls:=length(s);
        t:=0;
        ts:='';
        for j:=1 to ls do
            begin
              if s[j]='/' then begin
                                 y:=j;
                                 for d:=j-1 downto 1 do
                                     ts:=s[d]+ts;
                                 x:=1;
                                 for e:=1 to k do
                                     if a[e]=ts then x:=0;
                                 if x=1 then begin
                                               k:=k+1;
                                               a[k]:=ts;
                                             end;
                                 ts:='';
                               end;
            end;
        for d:=y+1 to ls do
            ts:=s[d]+ts;
             x:=1;
             for e:=1 to k do
             if a[e]=ts then x:=0;
             if x=1 then begin
             k:=k+1;
             a[k]:=ts;
             end;
      end;
  writeln(a[1]);
  for y:=2 to k-1 do
      begin
      for j:=y+1 to k do
          begin
            x:=0;
            s:=a[y];
            ts:=a[j];
            ls:=length(s);
            lts:=length(ts);
            for i:= 1 to ls do
                begin
                  if s[i]>ts[i] then begin
                                       x:=1;
                                       break;
                                     end;
                  if s[i]<ts[i] then break;
                end;
            if (x=0)and(ls>lts) then x:=1;
            if x=1 then begin
                          tems:=ts;
                          ts:=s;
                          s:=tems;
                        end;
          end;
      end;
  for i:=2 to k do
      writeln(s1,a[i]);
close(input);
close(output);
end.