var a:array[-1..10000] of longint;
    b:array[-1..10000] of extended;
    n,i,v,c,top,k:longint;
    s:string;
begin
 assign(input,'simulator.in');reset(input);
 assign(output,'simulator.out');rewrite(output);
 readln(a[0],c);
 b[0]:=a[0]*c/100;
 readln(n);

 top:=0;
 for i:=1 to n do begin
  readln(s);
  if s[1]='Z'
  then begin if top>0 then dec(top) end
  else begin
   s[2]:='.';
   k:=pos(' ',s);
   val(copy(s,3,k-3),v);
   val(copy(s,k+1,length(s)-k+1),c);
   inc(top);
   a[top]:=a[top-1]+v;
   b[top]:=b[top-1]+v*c/100;
  end;
  if a[top]=0 then writeln('0 0.00000') else
  writeln(a[top],' ',b[top]/a[top]*100:0:5);
 end;
 close(input);close(output);
end.
