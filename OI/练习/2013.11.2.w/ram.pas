var ll,rr,mi,lc,rc:array[1..60000] of longint;
    st:string;
    time,top,x,loop:longint;
    ok:boolean;
function min(a,b:longint):longint;
begin
 if a<b then exit(a);
 exit(b);
end;

procedure build(now,l,r:longint);
var mid:longint;
begin
 ll[now]:=l;
 rr[now]:=r;
 mi[now]:=0;
 mid:=(l+r)>>1;
 if l=r then begin
  lc[now]:=0;
  rc[now]:=0;
 end
 else begin
  inc(top);
  lc[now]:=top;
  build(top,l,mid);
  inc(top);
  rc[now]:=top;
  build(top,mid+1,r);
 end;
end;

function find(root,ma:longint):longint;
begin
 if ll[root]=rr[root] then exit(ll[root]);
 if mi[lc[root]]<ma then exit(find(lc[root],ma));
 exit(find(rc[root],ma))
end;

procedure change(x,e,du,xian:longint);
var mid,next:longint;
begin
 if ll[x]=rr[x] then begin
  if xian=1 then begin
   if mi[x]<du then begin
    ok:=false;
    exit;
   end;
  end;
  mi[x]:=du+600-1;
  exit;
 end;
 mid:=(ll[x]+rr[x])>>1;
 if e<=mid then next:=lc[x]
           else next:=rc[x];
 change(next,e,du,xian);
 mi[x]:=min(mi[rc[x]],mi[lc[x]]);
end;

begin
 assign(input,'ram.in');reset(input);
 assign(output,'ram.out');rewrite(output);
 top:=1;
 build(top,1,30000);
 while not eof do begin
  readln(st);
  val(copy(st,1,pos(' ',st)-1),time);
  delete(st,1,pos(' ',st));
  case st[1] of
   '+':begin
    x:=find(1,time);
    change(1,x,time,0);
    writeln(x);
   end;
   '.':begin
    ok:=true;
    delete(st,1,pos(' ',st));
    val(st,loop);
    change(1,loop,time,1);
    if ok then writeln('+')
          else writeln('-');
   end;
  end;
 end;
 close(input);close(output);
end.
