var d:array[1..10000] of longint;
    t:array[0..1000] of boolean;
    k,n,m,i,f,p,ans:longint;
begin
 assign(input,'translate.in');reset(input);
 assign(output,'translate.out');rewrite(output);
 read(m,n);
 f:=1;p:=0;
 ans:=0;
 fillchar(t,sizeof(t),false);
 for i:=1 to n do begin
  read(k);
  if not t[k] then begin
   inc(ans);
   if p-f+1=m then begin
    t[d[f]]:=false;
    inc(f);
    inc(p);
    d[p]:=k;
    t[k]:=true;
   end
   else begin
    inc(p);
    d[p]:=k;
    t[k]:=true;
   end;
  end;
 end;
 writeln(ans);
 close(input);close(output);
end.
