var n1,n2,m1,m2:longint;
    ans:qword;
begin
 assign(input,'rectangle.in');reset(input);
 assign(output,'rectangle_1.out');rewrite(output);
 read(n1,m1,n2,m2);
 ans:=n1*(n1+1)*m1*(m1+1);
 ans:=ans+(n2*(n2+1)*m2*(m2+1));
 ans:=ans-(n1*(n1+1)*m2*(m2+1));
 writeln(ans div 4);
 close(input);close(output);
end.
