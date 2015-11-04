var ans,i,m,n,rest,x:longint;
    a,b,c:array[1..3000] of longint;
    rate:array[1..3000] of double;

procedure sortr(l,r:longint);

var i,j,temp:longint;
    m,temper:double;

begin
     i:=l;
     j:=r;
     m:=rate[(i+j) div 2];
     repeat
           while rate[i]>m do
                 i:=i+1;
           while rate[j]<m do
                 j:=j-1;
           if not(i>j) then begin
                                 temper:=rate[i];
                                 rate[i]:=rate[j];
                                 rate[j]:=temper;
                                 temp:=a[i];
                                 a[i]:=a[j];
                                 a[j]:=temp;
                                 temp:=b[i];
                                 b[i]:=b[j];
                                 b[j]:=temp;
                                 temp:=c[i];
                                 c[i]:=c[j];
                                 c[j]:=temp;
                                 i:=i+1;
                                 j:=j-1;
                            end;
     until i>j;
     if l<j then sortr(l,j);
     if i<r then sortr(i,r);
end;

begin
     assign(input,'pack.in');
     reset(input);
     assign(output,'pack.out');
     rewrite(output);
     readln(n,m);
     for i:=1 to n do
     begin
          read(x);
          if x=2 then readln(a[i],b[i],c[i]);
          if x=3 then readln(a[i],b[i]);
          rate[i]:=a[i]/b[i];
     end;
     sortr(1,n);
     rest:=m;
     ans:=0;
     for i:=1 to n do
     begin
          if c[i]=0 then begin
                              ans:=ans+rest div b[i]*a[i];
                              break;
                         end;
          if c[i]<>0 then begin
                               if rest-c[i]*b[i]>=0 then begin
                                                              ans:=ans+c[i]*a[i];
                                                              rest:=rest-c[i]*b[i];
                                                              continue;
                                                         end;
                               if rest-c[i]*b[i]<0 then begin
                                                             ans:=ans+a[i]*rest div b[i];
                                                             break;
                                                        end;
                          end;
     end;
     writeln(ans);
     close(input);
     close(output);
end.
     
