type cw=array[0..200000] of longint;
var a:cw;
    s:ansistring;
    k,i,b,ans:longint;
begin
 assign(input,'binary.in');reset(input);
 assign(output,'binary.out');rewrite(output);
 readln(s);
 k:=length(s);
 for i:=1 to k do
  a[i]:=ord(s[i])-48;
 a[0]:=k;
 readln(s);
 b:=0;
 for i:=1 to length(s) do
  b:=b*2+ord(s[i])-48;

 for i:=1 to a[0] do
  ans:=(ans*2) mod b+a[i] mod b;
 ans:=ans mod b;
 if ans=0 then writeln(0)
 else writeln(binstr(ans,trunc(ln(ans)/ln(2))+1));
 close(input);close(output);
end.
