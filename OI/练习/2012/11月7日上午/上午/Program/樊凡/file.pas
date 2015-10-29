begin
  assign(output,'file.out');
  rewrite(output);
  writeln('mydoc');
  writeln('|----abcd');
  writeln('|    |----abc.txt');
  writeln('|    |----new');
  writeln('|    |----zzz');
  writeln('|    |    |----game.cpp');
  writeln('|----dd');
  writeln('|    |----libexec.a');
  writeln('|----stdio.h');
  close(output);
end.