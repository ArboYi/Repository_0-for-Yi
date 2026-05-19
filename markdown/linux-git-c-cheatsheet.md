# 🚀 C语言 + Linux + Git + GitHub 完整指令流程（速查版）

适用于：Ubuntu / Linux / UTM / Mac虚拟机环境

---

# =========================
# 一、C语言编译运行流程
# =========================

## 1. 进入项目目录
cd ~/code/项目名

## （第一次使用时创建目录）
mkdir -p ~/code/c-learning
cd ~/code/c-learning

---

## 2. 创建文件
touch main.c

或用 VS Code：
code .

---

## 3. 示例代码（main.c）
#include <stdio.h>

int main() {
    printf("Hello Linux\n");
    return 0;
}

---

## 4. 编译
gcc main.c -o main

---

## 5. 运行
./main

---

# =========================
# 二、Git 本地版本控制
# =========================

## 1. 初始化仓库（第一次）
git init

---

## 2. 查看状态
git status

---

## 3. 添加文件到暂存区
git add .

---

## 4. 提交版本
git commit -m "first commit"

---

## 5.回溯版本
回溯上一个版本


git restore 文件名
或
git restore .


回溯到特定版本：  

git checkout 8838aa2 -- c-learning/
homework_6.c  

可用git log --oneline -3查看日志
# =========================
# 三、连接 GitHub（只做一次）
# =========================

## 1. 添加远程仓库
git remote add origin git@github.com:用户名/仓库名.git

---

## 2. 查看远程
git remote -v

---

# =========================
# 四、推送到 GitHub
# =========================

## 第一次推送
git branch -M main
git push -u origin main

---

## 以后每次更新（简化版）
git add .
git commit -m "update"
git push

---

# =========================
# 五、常见问题修复
# =========================

## 1. pull 冲突 / 历史不一致
git pull origin main --allow-unrelated-histories

---

## 2. 分支不是 main
git branch -M main

---

## 3. 没有 remote
git remote add origin <url>

---

## 4. 强制同步（慎用）
git push -f

---

# =========================
# 六、完整开发流程（核心记忆）
# =========================

写代码
↓
gcc 编译
↓
运行测试
↓
git add .
↓
git commit -m "xxx"
↓
git push

---

# =========================
# 七、核心一句话总结
# =========================

写代码 → 提交(commit) → 推送(push)
