const nn:array[1..15] of longint=(4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536);
var a,b:array[1..65536] of longint;
    c,s,r,i,n,x,y,z,k:longint;


procedure ec(a:longint; var b:longint);
begin
 if a<b then b:=a;
end;

function min(a,b:longint):longint;
begin
 if a>b then exit(b);
 exit(a);
end;

function find(l,r:longint):longint;
var ans,ll,rr,d:longint;
begin
 ll:=l;rr:=r;
 ans:=a[l];
 while rr-ll<>1 do begin
  if ll mod 2=0 then begin
   ec(a[ll+1],ans);
  end;
  if rr mod 2=1 then begin
   ec(a[rr-1],ans);
  end;
  ll:=ll div 2;
  rr:=rr div 2;
 end;

 d:=0;
 ll:=ll div 2;
 while ll<>0 do begin
  ll:=ll div 2;
  if ll<>0 then d:=d+b[ll];
 end;
 exit(ans-d);
end;

procedure de(l,r,x:longint);
var ll,rr:longint;
begin
 ll:=l;rr:=r;
 while rr-ll<>1 do begin
  if ll mod 2=0 then begin
   inc(b[ll+1],x);
   a[ll div 2]:=min(a[ll div 2],a[ll+1]-b[ll+1]);
  end;
  if rr mod 2=1 then begin
   inc(b[rr-1],x);
   a[rr div 2]:=min(a[rr div 2],a[rr-1]-b[rr-1]);
  end;
  ll:=ll div 2;
  rr:=rr div 2;
  a[ll div 2]:=min(a[ll div 2],a[ll+1]-b[ll+1]);
  a[rr div 2]:=min(a[rr div 2],a[rr-1]-b[rr-1]);
 end;
 while ll<>0 do begin
  ll:=ll div 2;
  if ll<>0 then
  a[ll]:=min(a[ll*2]-b[ll*2],a[ll*2+1]-b[ll*2+1]);
 end;
end;

begin
//// assign(input,'railway.in');reset(input);
// assign(output,'railway.out');rewrite(output);
 read(c,s,r);
 for i:=1 to 15 do
  if nn[i]>c+1 then begin
   n:=nn[i];
   break;
  end;

 fillchar(a,sizeof(a),63);
 for i:=1 to c do a[i+n]:=s;
 for i:=1 to n-1 do a[i]:=s;

 for i:=1 to r do begin
  read(x,y,z);
  k:=find(n+x-1,n+y);
  if k<z then writeln('NO')
  else begin
   writeln('YES');
   de(n+x-1,n+y,z);
  end;
 end;
 close(input);close(output);
end.
