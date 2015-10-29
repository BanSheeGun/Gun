var t,p,n,k,i,j,l:longint;
    a:array[1..51]of string;
    h:array[1..51000]of string;
    s,temp:string;
function search(m:string):boolean;
var i:longint;
begin
  search:=true;
  for i:=1 to k do
    if h[i]=m then begin search:=false; exit;end;
  inc(k);
  h[k]:=m;
end;
begin
assign(input,'file.in');
reset(input);
assign(output,'file.out');
rewrite(output);
  readln(n);
  for i:=1 to n do
    begin
      readln(a[i]);
      a[i]:=a[i]+'/';
      for j:=1 to i-1 do
        if a[j]>a[i] then begin
                            temp:=a[i];
                            for l:=i-1 downto j do
                              a[l+1]:=a[l];
                            a[j]:=temp;
                            break;
                          end;
    end;
  s:='';
  for i:=1 to length(a[1]) do
    begin
      if a[1][i]<>'/' then s:=s+a[1][i]
                      else break;
    end;
  p:=i;
  writeln(s);
  h[1]:=s;
  k:=1;
  s:='';
  t:=-1;
  for i:=1 to n do
    begin
      for j:=p+1 to length(a[i]) do
        begin

          if a[i][j]<>'/' then s:=s+a[i][j]
                          else begin
                                 inc(t);
                                 if search(s) then
                                   begin
                                     for l:=1 to t do
                                        write('|    ');
                                     writeln('|----',s);
                                   end;
                                 s:='';
                               end;
        end;
      t:=-1;
    end;
close(input);
close(output);
end.
