var a:array['a'..'z'] of longint;
    ans:array[1..200] of char;
    s:string;
    n,i:longint;
procedure dfs(k:longint);
var ch:char;
begin
 for ch:='a' to 'z' do
  if a[ch]>0 then begin
    ans[k]:=ch;
    dec(a[ch]);
    if k=n then begin
     for i:=1 to n do write(ans[i]);
     writeln;
    end
    else dfs(k+1);
    inc(a[ch]);
  end;
end;
begin
 assign(input,'orders.in');reset(input);
 assign(output,'orders.out');rewrite(output);
 readln(s);
 n:=length(s);
 for i:=1 to n do
  inc(a[s[i]]);

 dfs(1);
 close(input);close(output);
end.
