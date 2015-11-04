var a:array[1..1440] of longint;
    f:array[0..1440] of longint;
    st:string;
    k,n,s,t,c,i,j:longint;
    tt:boolean;
begin
 assign(input,'exercise.in');reset(input);
 assign(output,'exercise.out');rewrite(output);
 readln(f[0],n);
 for i:=1 to n do begin
  readln(st);
  k:=pos(' ',st);
  delete(st,1,k);
  k:=pos(' ',st);
  val(copy(st,1,k-1),s);
  delete(st,1,k);
  k:=pos(' ',st);
  val(copy(st,1,k-1),t);
  delete(st,1,k);
  val(st,c);
  for j:=s to t do inc(a[j],c);
 end;
 tt:=true;
 for i:=1 to 1440 do begin
  f[i]:=f[i-1]+1;
  f[i]:=f[i]-a[i];
  if f[i]<=0 then begin
   tt:=false;
   break;
  end;
 end;

 if tt then begin
  writeln('Accepted');
  writeln(f[1440]);
 end
 else begin
  writeln('Runtime Error');
  writeln(i);
 end;
 close(input);close(output);
end.
