var x1,x2,y1,y2,r1,r2:longint;
    ans:extended;
begin
 assign(input,'chord.in');reset(input);
 assign(output,'chord.out');rewrite(output);
 read(x1,y1,r1,x2,y2,r2);
 ans:=sqrt(sqr(x1-x2)+sqr(y1-y2))*2;
 writeln(ans:0:6);
 close(input);close(output);
end.
