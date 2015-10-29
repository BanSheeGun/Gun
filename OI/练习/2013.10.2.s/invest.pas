var now,de:array[1..100000] of longint;
    m,cm,dm,dcm:array[1..400000] of longint;
    n,e,i,x,y,j:longint;
    st:string;

function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;

procedure change(x:longint);
var k,z:longint;
begin
 k:=e+x-1;
 while k<>1 do begin
  k:=k div 2;
  m[k]:=max(m[k*2],m[k*2+1]);
  if m[k]=m[k*2] then z:=1
                 else z:=0;
  dm[k]:=dm[2*k+1-z];
  if z=1 then begin
   cm[k]:=max(cm[k*2],m[k*2+1]);
   if (cm[k]=cm[k*2])and(dcm[k*2]<>dm[k*2]) then dcm[k]:=dcm[k*2]
                                            else dcm[k]:=dm[k*2+1];
  end
  else begin
   cm[k]:=max(cm[k*2+1],m[k*2]);
   if (cm[k]=cm[k*2+1])and(dcm[k*2+1]<>dm[k*2+1]) then dcm[k]:=dcm[k*2+1]
                                            else dcm[k]:=dm[k*2];
  end;
 end;
end;

begin
 assign(input,'invest.in');reset(input);
 assign(output,'invest.out');rewrite(output);
 readln(n);
 e:=1;
 while e<n do e:=e*2;
 for i:=e+n-1 to e*2-1 do begin
  m[i]:=-maxlongint;cm[i]:=-maxlongint;
 end;
 for i:=e to e*2-1 do begin
  dm[i]:=i-e+1;
  dcm[i]:=dm[i];
  change(i-e+1);
 end;
 for i:=1 to n do readln(now[i]);
 repeat
  readln(st);
  if st[1]='E' then begin end
  else if st[1]='R' then writeln(dm[1],' ',dcm[1])
        else begin
         j:=pos(' ',st);
         val(copy(st,1,j-1),x);
         val(copy(st,j+1,length(st)-j),y);
         de[x]:=y-now[x];
         now[x]:=y;
         m[x+e-1]:=de[x];
         change(x);
        end;
 until st[1]='E';
 close(input);close(output);
end.
