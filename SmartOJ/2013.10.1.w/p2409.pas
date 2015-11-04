var dc:array[1..32] of string=('negative','zero','one','two','three','four','five',
'six','seven','eight','nine','ten','eleven','twelve','thirteen','fourteen',
'fifteen','sixteen','seventeen','eighteen',
'nineteen','twenty','thirty','forty','fifty','sixty','seventy',
'eighty','ninety','hundred','thousand','million');
    a:ansistring;
    now:string;
    fh,k:longint;
    ans:int64;
procedure work(now:string);
var k,m:longint;
begin
 for k:=1 to 32 do begin
  if now=dc[k] then break;
 end;
 if k=1 then begin
  fh:=-1;
  exit;
 end;
 if (k>=2)and(k<=21) then begin
  ans:=ans+k-2;
 end;
 if (22<=k)and(k<=29) then begin
  ans:=ans+(k-20)*10;
 end;
 if k=30 then begin
  m:=ans mod 10;
  ans:=ans-m+(m*100);
  exit;
 end;
 if k=31 then begin
  m:=ans mod 1000;
  ans:=ans-m+(m*1000);
  exit;
 end;
 if k=32 then begin
  ans:=ans*1000000;
  exit;
 end;
end;

begin
 readln(a);
 ans:=0;
 fh:=1;
 while pos(' ',a)<>0 do begin
  k:=pos(' ',a);
  now:=copy(a,1,k-1);
  delete(a,1,k);
  work(now);
 end;
 work(a);
 writeln(fh*ans);
end.
