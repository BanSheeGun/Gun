const oo=1000000000;
var t,l,r,lc,rc:array[1..2000000] of longint;
    c:array[1..2000000] of boolean;
    st:string;
    n,i,a,b,top:longint;

procedure change(k,x:longint);
var mid:longint;
begin
 c[k]:=true;
 if l[k]=r[k] then begin
  inc(t[k]);
  exit;
 end;
 mid:=(l[k]+r[k])>>1;
 if x<=mid then begin
  if lc[k]=0 then begin
   inc(top);
   lc[k]:=top;
   l[lc[k]]:=l[k];
   r[lc[k]]:=mid;
  end;
  change(lc[k],x);
  inc(t[k]);
 end
 else begin
  if rc[k]=0 then begin
   inc(top);
   rc[k]:=top;
   l[rc[k]]:=mid+1;
   r[rc[k]]:=r[k];
  end;
  change(rc[k],x);
  inc(t[k]);
 end;
end;

function find(k,ll,rr:longint):longint;
var mid,ans:longint;
begin
 if (ll<=l[k])and(r[k]<=rr) then exit(t[k]);
 ans:=0;
 mid:=(l[k]+r[k])>>1;
 if ll<=mid then begin
  if lc[k]=0 then ans:=0
  else ans:=find(lc[k],ll,rr);
 end;
 if mid+1<=rr then begin
  if rc[k]=0 then ans:=ans
  else ans:=ans+find(rc[k],ll,rr);
 end;
 exit(ans);
end;

begin
 assign(input,'HistoryOfTheMoon.in');reset(input);
 assign(output,'HistoryOfTheMoon.out');rewrite(output);
 readln(n);
 top:=1;
 l[1]:=1;r[1]:=oo;
 fillchar(t,sizeof(t),0);
 fillchar(c,sizeof(c),false);
 c[1]:=true;
 for i:=1 to n do begin
  readln(st);
  if pos(' ',st)=0 then begin
   val(st,a);
   change(1,a);
  end
  else begin
   val(copy(st,1,pos(' ',st)-1),a);
   delete(st,1,pos(' ',st));
   val(st,b);
   writeln(find(1,a,b));
  end;
 end;
 close(input);close(output);
end.
