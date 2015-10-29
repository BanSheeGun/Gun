var a:array[1..51]of longint;
    h:array[1..51]of longint;
    t,t1,t2,xi,yi,n,i:longint;
begin
assign(input,'tournament.in');
reset(input);
assign(output,'tournament.out');
rewrite(output);
  readln(n);
  fillchar(a,sizeof(a),0);
  fillchar(h,sizeof(h),0);
  for i:=1 to (n-1)*n div 2-1 do
    begin
      readln(xi,yi);
      inc(h[xi]); inc(h[yi]);
      inc(a[xi]);
    end;
  t:=0;
  for i:=1 to n do
    if h[i]<>(n-1)  then
                      begin
                        if (t=0) then begin inc(t);t1:=i; end
                                 else begin t2:=i;break;  end;
                      end;
  if a[t1]>a[t2] then writeln(t1,' ',t2)
                 else writeln(t2,' ',t1);
close(input);
close(output);
end.