@echo off
cd /d %~dp0
chcp 65001

echo 请输入路径:
set /p path=
mkdir %path%
C:\Windows\System32\xcopy template %path% /s /e /y
echo 创建成功
pause