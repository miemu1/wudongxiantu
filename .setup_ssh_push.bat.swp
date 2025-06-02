@echo off
setlocal

set "EMAIL=1334785643@qq.com"
set "REPO_SSH=git@github.com:miemu1/wudongxiantu.git"
set "PROJECT_PATH=E:\yuanma\wudongxiantu"

if not exist "%PROJECT_PATH%" (
    echo ❌ 错误：项目路径不存在，请检查是否拼写或位置错误。
    pause
    exit /b
)

cd /d "%PROJECT_PATH%"

REM 初始化 Git（如果没初始化）
if not exist ".git" (
    git init
    git remote add origin %REPO_SSH%
)

REM 生成 SSH 密钥
if not exist "%USERPROFILE%\.ssh\id_rsa" (
    echo 正在生成 SSH 密钥...
    ssh-keygen -t rsa -C "%EMAIL%" -f "%USERPROFILE%\.ssh\id_rsa" -N ""
)

start https://github.com/settings/keys
echo ===== 你的 SSH 公钥如下，请复制粘贴到 GitHub 上 =====
type %USERPROFILE%\.ssh\id_rsa.pub
echo ========================================================
pause

REM 设置远程地址为 SSH
git remote set-url origin %REPO_SSH%

REM 添加文件、提交、推送
git add .
git commit -m "首次提交 武动仙途项目"
git branch -M main
git push -u origin main

pause
