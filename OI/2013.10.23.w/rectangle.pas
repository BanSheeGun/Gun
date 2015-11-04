type cw=array[0..1000] of longint;

var n1,n2,m1,m2,ans,n11,n22,m11,m22,a,b,c:cw;
    st:ansistring;
    i:longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a);exit(b);
end;
function min(a,b:longint):longint;
begin
 if a<b then exit(a);exit(b);
end;

procedure plus(var b,a:cw);
var i,j,l:longint;
begin
 l:=max(a[0],b[0]);
 a[0]:=l;
 for i:=1 to l do begin
  a[i]:=a[i]+b[i];
  a[i+1]:=a[i+1]+a[i] div 10;
  a[i]:=a[i] mod 10;
 end;
 while a[a[0]+1]<>0 do inc(a[0]);
end;


procedure decs(var b,a:cw);
var i,j,l:longint;
begin
 l:=b[0];
 for i:=1 to l do begin
  a[i]:=a[i]-b[i];
  j:=i;
  while a[j]<0 do begin
   a[j]:=a[j]+10;
   a[j+1]:=a[j+1]-1;
   inc(j);
  end;
 end;
 while a[a[0]]=0 do dec(a[0]);
end;

procedure chen(var a,b,c:cw);
var i,j,l:longint;
begin
 for i:=1 to a[0] do
  for j:=1 to b[0] do begin
   c[i+j-1]:=c[i+j-1]+a[i]*b[j];
   c[i+j]:=c[i+j]+c[i+j-1] div 10;
   c[i+j-1]:=c[i+j-1] mod 10;
  end;
 c[0]:=a[0]+b[0]-1;
 while c[c[0]+1]<>0 do inc(c[0]);
end;

procedure solve;
var i:longint;
begin
 for i:=ans[0] downto 2 do begin
  ans[i-1]:=ans[i] mod 4*10+ans[i-1];
  ans[i]:=ans[i] div 4;
 end;
 ans[1]:=ans[1] div 4;
 while ans[ans[0]]=0 do dec(ans[0]);
end;

begin
 assign(input,'rectangle.in');reset(input);
 assign(output,'rectangle.out');rewrite(output);
 readln(st);
 n1[0]:=length(st);
 for i:=1 to n1[0] do n1[i]:=ord(st[n1[0]-i+1])-48;
 readln(st);
 m1[0]:=length(st);
 for i:=1 to m1[0] do m1[i]:=ord(st[m1[0]-i+1])-48;
 readln(st);
 n2[0]:=length(st);
 for i:=1 to n2[0] do n2[i]:=ord(st[n2[0]-i+1])-48;
 readln(st);
 m2[0]:=length(st);
 for i:=1 to m2[0] do m2[i]:=ord(st[m2[0]-i+1])-48;

 fillchar(a,sizeof(a),0);
 fillchar(b,sizeof(b),0);
 fillchar(ans,sizeof(ans),0);
 chen(n1,m1,a);
 fillchar(c,sizeof(c),0);
 c[1]:=1;c[0]:=1;
 n11:=n1;m11:=m1;
 plus(c,n11);
 plus(c,m11);
 chen(n11,m11,b);
 fillchar(c,sizeof(c),0);
 chen(a,b,c);
 plus(c,ans);

 fillchar(a,sizeof(a),0);
 fillchar(b,sizeof(b),0);
 chen(n2,m2,a);
 fillchar(c,sizeof(c),0);
 c[1]:=1;c[0]:=1;
 n22:=n2;m22:=m2;
 plus(c,n22);
 plus(c,m22);
 chen(n22,m22,b);
 fillchar(c,sizeof(c),0);
 chen(a,b,c);
 plus(c,ans);


 fillchar(a,sizeof(a),0);
 fillchar(b,sizeof(b),0);
 fillchar(c,sizeof(c),0);
 chen(n1,m2,a);
 chen(n11,m22,b);
 chen(a,b,c);
 decs(c,ans);

 solve;
 for i:=ans[0] downto 1 do write(ans[i]);
 writeln;
 close(input);close(output);
end.
