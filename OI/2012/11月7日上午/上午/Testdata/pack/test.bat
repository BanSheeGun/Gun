@echo off
if "%1"=="" goto loop
copy pack%1.in pack.in >nul
echo Problem Test
echo Data %1
time<enter
pack.exe
time<enter
fc pack.out pack%1.out
del pack.in
del pack.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
