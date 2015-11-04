var f:array[0..3,1..1000] of longint;
    head,next,e,l:array[1..2000] of longint;
    n,ans,i,x,y,z:longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);
 exit(b);
end;
function d(t,k,f1:longint):longint;
var te,z,m1,m2:longint;
begin
 if f[t][k]<>0 then exit(f[t][k]);

 case t of
  0:begin
     z:=head[k];
     while z<>0 do begin
      if e[z]<>f1 then
      f[t][k]:=max(f[t][k],d(0,e[z],k)+l[z]);
      z:=next[z];
     end;
    end;
  1:begin
     z:=head[k];
     m1:=0;m2:=0;
     while z<>0 do begin
      if e[z]<>f1 then begin
      te:=d(0,e[z],k)+l[z];
      if te>m1 then begin m2:=m1;m1:=te;end
      else m2:=max(m2,te);  end;
      z:=next[z];
     end;
     f[t][k]:=m1+m2;
    end;
  2:begin
     z:=head[k];
     while z<>0 do begin
      if e[z]<>f1 then begin
       f[t][k]:=max(f[t][k],d(0,e[z],k));
       f[t][k]:=max(f[t][k],d(1,e[z],k));
       f[t][k]:=max(f[t][k],d(2,e[z],k));
      end;
      z:=next[z];
     end;
    end;
 end;
  exit(f[t][k]);
end;
begin
 assign(input,'longest.in');reset(input);
 assign(output,'longest.out');rewrite(output);
 read(n);
 for i:=1 to n-1 do begin
  read(x,y,z);
  e[i*2-1]:=y;
  next[i*2-1]:=head[x];
  head[x]:=i*2-1;
  l[i*2-1]:=z;

  e[i*2]:=x;
  next[i*2]:=head[y];
  head[y]:=i*2;
  l[i*2]:=z;
 end;
 ans:=d(0,1,0);
 ans:=max(ans,d(1,1,0));
 ans:=max(ans,d(2,1,0));
 writeln(ans);
 close(input);close(output);
end.
