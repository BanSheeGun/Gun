var a,b:array['A'..'Z'] of char;
    x,y,ans:string;
    ch:char;
    n,i:longint;
    ok:boolean;
begin
 readln(x);
 readln(y);
 n:=length(x);
 ok:=true;
 for ch:='A' to 'Z' do begin
  a[ch]:=' ';
  b[ch]:=' ';
 end;


 for i:=1 to n do begin
  if a[x[i]]=' ' then begin
   if b[y[i]]=' ' then begin
    a[x[i]]:=y[i];
    b[y[i]]:=x[i];
   end

   else begin
    ok:=false;
    break;
   end;
  end
  else begin
   if a[x[i]]=y[i] then begin
     if b[y[i]]<>x[i] then begin
      ok:=false;
      break;
     end;
   end
   else begin
    ok:=false;
    break;
   end;
  end;
 end;
 for ch:='A' to 'Z' do
  if b[ch]=' ' then ok:=false;
 if ok then begin
  ans:='';
  readln(x);
  for i:=1 to length(x) do
   if b[x[i]]<>' ' then ans:=ans+a[x[i]]
                   else begin ok:=false;break;end;
 end;
 if ok then writeln(ans)
 else writeln('Failed');
end.
