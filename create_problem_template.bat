@echo off
cd /d %~dp0
chcp 65001

set path=

echo 请选择OJ:
echo 1.洛谷
set /p oj=

echo 请输入题号:
set /p pid=

if %oj% == 1 ( 
  echo OJ洛谷 
  set path=luogu\P%pid%
) ^
else if %oj% == 2 ( 
  echo not oj
  pause
  exit
) ^
else if %oj% == 3 ( 
  echo not oj
  pause
  exit 
) ^
else ( 
  echo not oj
  pause
  exit
)

echo 生成路径... :%path%
mkdir %path%

echo 生成模板... 
C:\Windows\System32\xcopy template %path% /s /e /y
echo 创建成功.
pause