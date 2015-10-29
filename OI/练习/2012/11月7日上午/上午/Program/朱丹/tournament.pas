type atype=record
      id:longint;
      win,lose:array[1..52] of boolean;
     end;
var yes,no:array[1..2500] of longint;
    times:array[1..55] of longint;
    n,t,winner,loser,x,y,i,j:longint;
    finish:boolean;
    absent1,absent2:atype;

begin
 assign(input,'tournament.in');
 reset(input);
 assign(output,'tournament.out');
 rewrite(output);
 read(n);
 fillchar(absent1.win,sizeof(absent1.win),false);
 fillchar(absent2.win,sizeof(absent2.win),false);
 fillchar(absent1.lose,sizeof(absent1.lose),false);
 fillchar(absent1.lose,sizeof(absent1.lose),false);
 for i:=1 to n*(n-1) div 2-1 do
  begin
   read(x,y);
   inc(t);
   yes[t]:=x;
   no[t]:=y;
   inc(times[x]);
   inc(times[y]);
  end;
 for i:=1 to n do
  if times[i]<>n-1 then
   if  absent1.id=0 then absent1.id:=i
                    else absent2.id:=i;
 for i:=1 to n*(n-1) div 2-1 do
  begin
   if yes[i]=absent1.id then absent1.win[no[i]]:=true;
   if yes[i]=absent2.id then absent2.win[no[i]]:=true;
   if no[i]=absent1.id then absent1.lose[yes[i]]:=true;
   if no[i]=absent2.id then absent2.lose[yes[i]]:=true;
  end;
 finish:=false;
 for i:=1 to n do
  if not finish then
   begin
    if (absent1.win[i]) and (absent2.lose[i]) then
     begin
      winner:=absent1.id;
      loser:=absent2.id;
      finish:=true;
     end;
    if (absent2.win[i]) and (absent1.lose[i]) then
     begin
      winner:=absent2.id;
      loser:=absent1.id;
     end;
   end;
 if not finish then
  begin
   winner:=absent2.id;
   loser:=absent1.id;
  end;
 writeln(winner,' ',loser);
 close(input);
 close(output);
end.


