var a,b,c:extended;
    x:longint;
    ans:boolean;
begin
 read(x);
 a:=a+x/100*7.5;
 b:=b+x/100*0.75;
 c:=c+x/100*78;
 read(x);
 a:=a+x/100*10;
 b:=b+x/100*1.25;
 c:=c+x/100*75;
 read(x);
 a:=a+x/100*1.5;
 b:=b+x/100*0.19;
 c:=c+x/100*4.28;
 read(x);
 a:=a+x/100*35;
 b:=b+x/100*18;
 c:=c+x/100*42;
 read(x);
 a:=a+x/100*5.0;
 b:=b+x/100*5.0;
 c:=c+x/100*0.6;
 read(x);
 a:=a+x/100*16.5;
 b:=b+x/100*28.8;
 c:=c+x/100*1.05;
 read(x);
 a:=a+x/100*17.7;
 b:=b+x/100*20.33;
 c:=c+x/100*4.06;
 read(x);
 a:=a+x/100*14.9;
 b:=b+x/100*0.8;
 c:=c+x/100*0.93;
 read(x);
 a:=a+x/100*0;
 b:=b+x/100*100;
 c:=c+x/100*0;
 read(x);
 a:=a+x/100*0.85;
 b:=b+x/100*0.5;
 c:=c+x/100*8;
 a:=a*4.1;
 b:=b*9.3;
 c:=c*4.1;
 if (a=0.000000000)or(b=0.000000000)or(c=0.000000000) then ans:=false
 else begin
 ans:=true;
 ans:=ans and (0.1400000<(a/(a+b+c)));
 ans:=ans and (a/(a+b+c)<0.16000000);
 ans:=ans and((0.3000000<b/(a+b+c))and(b/(a+b+c)<0.35000000));
 ans:=ans and((0.4900000<c/(a+b+c))and(c/(a+b+c)<0.56000000));
 end;
 if ans then writeln('yes')
 else writeln('no');
end.
