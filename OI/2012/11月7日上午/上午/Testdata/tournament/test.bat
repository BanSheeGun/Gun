@echo off
if "%1"=="" goto loop
copy tournament%1.in tournament.in >nul
echo Problem Test
echo Data %1
time<enter
tournament.exe
time<enter
fc tournament.out tournament%1.out
del tournament.in
del tournament.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
