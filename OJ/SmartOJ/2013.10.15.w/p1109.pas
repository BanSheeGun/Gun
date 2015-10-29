var a,b,c:int64;
    ans:boolean;
function pan(a,b,c:int64):boolean;
begin
 if a+b>c then exit(true);
 exit(false);
end;
begin
 read(a,b,c);
 ans:=true;
 ans:=ans and pan(a,b,c);
 ans:=ans and pan(c,a,b);
 ans:=ans and pan(c,b,a);
 if ans then writeln('Yes')
        else writeln('No');
end.
