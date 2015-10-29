var x,y,z,ans,kind,i,j,k,n,m,num:longint;
    p,v:array [0..200000] of longint;
    h:array [0..200000] of boolean;
    f:array [0..3000] of longint;

begin
  assign(input,'pack.in');
  assign(output,'pack.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  fillchar(v,sizeof(v),0);
  fillchar(p,sizeof(p),0);
  fillchar(h,sizeof(h),0);
  num:=0;
  for i:=1 to n do
    begin
      read(kind);
      if (kind=1) then begin
                         inc(num);
                         h[num]:=true;
                         read(x);
                         readln(y);
                         p[num]:=x;
                         v[num]:=y;
                       end;
      if (kind=2) then begin
                         read(x);
                         read(y);
                         readln(z);
                         for j:=1 to z do
                           begin
                             inc(num);
                             p[num]:=x;
                             v[num]:=y;
                           end;
                       end;
      if (kind=3) then begin
                         read(x);
                         readln(y);
                         z:=m div y;
                         for j:=1 to z do
                           begin
                             inc(num);
                             p[num]:=x;
                             v[num]:=y;
                           end;
                       end;
    end;
  ans:=0;
  fillchar(f,sizeof(f),0);
  for i:=1 to num do
    if not(h[i]) then begin
                        for j:=m downto v[i] do
                          begin
                            if f[j-v[i]]+p[i]>f[j] then f[j]:=f[j-v[i]]+p[i];
                            if f[j]>ans then ans:=f[j];
                          end;
                      end
                 else begin
                        for k:=m downto 1 do
                          begin
                            x:=p[i]*sqr(k)-v[i]*k;
                            for j:=m downto k do
                              begin
                                if f[j-k]+x>f[j] then f[j]:=f[j-k]+x;
                                if f[j]>ans then ans:=f[j];
                              end;
                          end;
                      end;
  writeln(ans);
  close(input);
  close(output);
end.