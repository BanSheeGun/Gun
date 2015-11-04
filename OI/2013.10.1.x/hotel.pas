var size,room,num,price:array[1..50] of longint;
    name:array[1..50] of string;
    a:array[1..50] of char;
    c,cha:char;
    x,y,n,m,i,z,ch,ans,r,sj,co:longint;
    ok:boolean;

function min(a,b:longint):longint;
begin
 if a<b then exit(a);
 exit(b);
end;

begin
 assign(input,'hotel.in');reset(input);
 assign(output,'hotel.out');rewrite(output);
 read(n,m);
 for i:=1 to n do begin
  read(size[i],room[i],num[i],price[i]);
  if (20<=size[i])and(size[i]<=35) then a[i]:='A';
  if (36<=size[i])and(size[i]<=48) then a[i]:='B';
  if (49<=size[i])and(size[i]<=62) then a[i]:='C';
  read(cha);
  readln(name[i]);
 end;

 for z:=1 to m do begin
  read(c);
  read(cha);
  readln(x,y);
  ok:=false;
  for i:=1 to n do
   if a[i]=c then begin
    sj:=min(y,room[i]);
    co:=x div sj;
    if x mod sj<>0 then inc(co);
    if co<=num[i] then begin
     if not ok then begin
      ok:=true;
      ans:=co*price[i];
      ch:=i;
     end
     else begin
      if co*price[i]<ans then begin
       ans:=co*price[i];
       ch:=i;
      end
      else if co*price[i]=ans then begin
       if size[i]>size[ch] then begin
        ans:=co*price[i];
        ch:=i;
       end
      end;
     end;
    end;
   end;
  if ok then writeln(ans,' ',name[ch])
        else writeln('no-hotel');
 end;
 close(input);close(output);
end.
