var l,r:array[0..50] of longint;
    st:string;
    n,zsum,fsum,num,i,t1,t2,j,rad:longint;
    t,tl:array[0..360] of boolean;
    ans,c,rr,s,aa:extended;
begin
 assign(input,'ship.in');reset(input);
 assign(output,'ship.out');rewrite(output);
 readln(n);
 t1:=0;t2:=0;
 zsum:=0;
 fsum:=0;
 for i:=1 to n do begin
  readln(st);
  val(copy(st,pos(' ',st)+1,length(st)-pos(' ',st)),num);
  case st[1] of
   'l':begin
    inc(t1);
    l[t1]:=num mod 360;
   end;
   'r':begin
    inc(t2);
    r[t2]:=num mod 360;
   end;
   'f':begin
    inc(zsum,num);
   end;
   'b':begin
    inc(fsum,num);
   end;
  end;
 end;

 fillchar(t,sizeof(t),false);
 t[0]:=true;
 for i:=1 to t2 do  begin
  tl:=t;
  for j:=0 to 359 do
   if  tl[j] then t[(360+j-r[i]) mod 360]:=true;
 end;
 for i:=0 to t1 do  begin
  tl:=t;
  for j:=0 to 359 do
   if  tl[j] then t[(j+l[i]) mod 360]:=true;
 end;
 aa:=0;
 for rad:=0 to 360 do if t[rad] then begin
  c:=cos(rad/180*pi);
  ans:=zsum*zsum+fsum*fsum-2*zsum*fsum*c;
  ans:=sqrt(ans);
  if ans>aa then aa:=ans;
 end;
 writeln(aa:0:6);
 close(input);close(output);
end.
