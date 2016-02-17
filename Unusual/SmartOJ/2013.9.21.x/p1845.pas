var i,j,k,t,cnt,top,x,ans:longint;
    st:string;

begin
  read(t);
  for i:=1 to t do
  begin
    top:=0;
    read(x);
    for cnt:=666 to maxlongint do
    begin
      str(cnt,st);
      if top<x then ans:=cnt;
      if pos('666',st)<>0 then
      begin
        inc(top);
        if top>x then break;
      end;
    end;
    writeln(ans);
  end;
end.
