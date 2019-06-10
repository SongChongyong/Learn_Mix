# Git Notes

##  01 安装Git

```
$ git
The program 'git' is currently not installed. You can install it by typing:
sudo apt-get install git
```

如果你碰巧用Debian或Ubuntu Linux，通过一条sudo apt-get install git就可以直接完成Git的安装, 非常简单. 安装完成后，还需要最后一步设置，在命令行输入：

```
$ git config --global user.name "Your Name"
$ git config --global user.email email@example.com
```

## 02 创建版本库

版本库又名仓库，英文名**repository**，你可以简单理解成一个目录，这个目录里面的所有文件都可以被Git管理起来，每个文件的修改、删除，Git都能跟踪，以便任何时刻都 可以追踪历史，或者在将来某个时刻可以“还原”。所以，创建一个版本库非常简单:

(1) 首先，选择一个合适的地方，创建一个空目录：

```
$ mkdir learngit

$ cd learngit

$ pwd

/Users/michael/learngit
```

 

(2) 第二步，通过git init命令把这个目录变成Git可以管理的仓库：

```
$ git init
Initialized empty Git repository **in** /Users/michael/learngit/.git/
```

 

 

## 03 把文件添加到版本库

在 learngit目录下新建 readme.txt文件，把readme.txt文件添加到 learngit目录：

（1）第一步，用命令git add告诉Git，把文件添加到仓库：

$ git add readme.txt

 

（2）第二步，用命令git commit告诉Git，把文件提交到仓库：

```
$ git commit -m "wrote a readme file"

[master (root-**commit**) eaadf4e] wrote a readme file 

1 file changed, 2 insertions(+) 

**create** mode 100644 readme.txt
```

 

\# git commit命令，-m后面输入的是本次提交的说明，可以输入任意内容，最好是有意义的，这样你就能从历史记录里方便地找到改动记录。

\# git commit命令执行成功后会告诉你，1 file changed：1个文件被改动（我们新添加的readme.txt文件）；2 insertions：插入了两行内容（readme.txt有两行内容）。

 

\# commit可以一次提交很多文件，所以你可以多次add不同的文件，比如：

\# $ git add file1.txt

\# $ git add file2.txt file3.txt

\# $ git commit -m "add 3 files."

 

 

## 04 随时掌握工作区的状态

· 要随时掌握工作区的状态，使用git status命令。

· 如果git status告诉你有文件被修改过，用git diff可以查看修改内容。

如，修改readme.txt文件为：

Git **is** a distributed version control system.

Git **is** free software.

运行git status命令看看结果：

$ git status

On branch master

Changes not staged for commit:

  (use "git add <file>..." to **update** what will be committed)

  (use "git checkout -- <file>..." **to** discard changes **in** working directory)

 

​	modified:   readme.txt

 

**no** changes added **to** **commit** (use "git add" **and**/**or** "git commit -a")

\# 上面的命令输出告诉我们，readme.txt被修改过了，但还没有准备提交的修改。

 

 

用git diff命令查看具体修改了什么内容：

$ git diff readme.txt 

diff --git a/readme.txt b/readme.txt

index 46d49bf..9247db6 100644

--- a/readme.txt

+++ b/readme.txt

@@ -1,2 +1,2 @@

-Git **is** a version control system.

+Git **is** a distributed version control system.

 Git **is** free software.

 

## 05版本回退

用git log命令查看历史记录：

$ git log

commit 1094adb7b9b3807259d8cb349e7df1d4d6477073 (HEAD -> master)

Author: Michael Liao <askxuefeng@gmail.com>

Date:   Fri May 18 21:06:15 2018 +0800

​    append GPL

commit e475afc93c209a690c39c13a46716e8fa000c366

Author: Michael Liao <askxuefeng@gmail.com>

Date:   Fri May 18 21:03:36 2018 +0800

​    add distributed

commit eaadf4e385e865d25c48e7ca9c8395c3f7dfaef0

Author: Michael Liao <askxuefeng@gmail.com>

Date:   Fri May 18 20:59:18 2018 +0800

​    wrote a readme file

git log命令显示从最近到最远的提交日志，我们可以看到3次提交，最近的一次是append GPL，上一次是add distributed，最早的一次是wrote a readme file。

 

如果嫌输出信息太多，看得眼花缭乱的，可以试试加上--pretty=oneline参数：

$ git log --pretty=oneline

1094adb7b9b3807259d8cb349e7df1d4d6477073 (HEAD -> master) append GPL

e475afc93c209a690c39c13a46716e8fa000c366 add distributed

eaadf4e385e865d25c48e7ca9c8395c3f7dfaef0 wrote a readme file

类似1094adb...的是commit id（版本号）

每提交一个新版本，实际上Git就会把它们自动串成一条时间线。如果使用可视化工具查看Git历史，就可以更清楚地看到提交历史的时间线。

 

在Git中，用HEAD表示当前版本，也就是最新的提交1094adb...，上一个版本就是HEAD^，上上一个版本就是HEAD^^，当然往上100个版本写100个^比较容易数不过来，所以写成HEAD~100。

使用git reset命令回退版本：

$ git re**set** --hard HEAD^

HEAD **is** now **at** e475afc **add** distributed

\# 这样就退回到上一个版本了

\#也可以用git re**set** –hard+版本号（版本号只需要前面几位就行）

 

 

用git reflog查看命令历史