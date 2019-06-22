# Git Notes

[TOC]



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

##  02 基础操作
### 2.1 创建版本库

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

 

 

### 2.2  把文件添加到版本库

在 learngit目录下新建 readme.txt文件，把readme.txt文件添加到 learngit目录：

（1）第一步，用命令git add告诉Git，把文件添加到仓库：

```
$ git add readme.txt
```

 

（2）第二步，用命令git commit告诉Git，把文件提交到仓库：

```
$ git commit -m "wrote a readme file"

[master (root-**commit**) eaadf4e] wrote a readme file 

1 file changed, 2 insertions(+) 

**create** mode 100644 readme.txt

# git commit命令，-m后面输入的是本次提交的说明，可以输入任意内容，最好是有意义的，这样你就能从历史记录里方便地找到改动记录。

# git commit命令执行成功后会告诉你，1 file changed：1个文件被改动（我们新添加的readme.txt文件）；2 insertions：插入了两行内容（readme.txt有两行内容）。
```

 

commit可以一次提交很多文件，所以你可以多次add不同的文件，比如：

```
$ git add file1.txt

$ git add file2.txt file3.txt

$ git commit -m "add 3 files."
```

 

 

### 2.3 随时掌握工作区的状态

· 要随时掌握工作区的状态，使用git status命令。

· 如果git status告诉你有文件被修改过，用git diff可以查看修改内容。



```
$ git status

On branch master

Changes not staged for commit:

  (use "git add <file>..." to **update** what will be committed)

  (use "git checkout -- <file>..." **to** discard changes **in** working directory)

 

	modified:   readme.txt

 

**no** changes added **to** **commit** (use "git add" **and**/**or** "git commit -a")

# 上面的命令输出告诉我们，readme.txt被修改过了，但还没有准备提交的修改。
```

 

 

用git diff命令查看具体修改了什么内容：

```
$ git diff readme.txt 

diff --git a/readme.txt b/readme.txt

index 46d49bf..9247db6 100644

--- a/readme.txt

+++ b/readme.txt

@@ -1,2 +1,2 @@

-Git **is** a version control system.

+Git **is** a distributed version control system.

 Git **is** free software.
```

 

### 2.4 版本回退

用git log命令查看历史记录：

```
$ git log

commit 1094adb7b9b3807259d8cb349e7df1d4d6477073 (HEAD -> master)

Author: Michael Liao <askxuefeng@gmail.com>

Date:   Fri May 18 21:06:15 2018 +0800

     append GPL

...

commit eaadf4e385e865d25c48e7ca9c8395c3f7dfaef0

Author: Michael Liao <askxuefeng@gmail.com>

Date:   Fri May 18 20:59:18 2018 +0800

     wrote a readme file

# git log命令显示从最近到最远的提交日志，我们可以看到3次提交，最近的一次是append GPL，上一次是add distributed，最早的一次是wrote a readme file。
```

 

如果嫌输出信息太多，看得眼花缭乱的，可以试试加上--pretty=oneline参数：

```
$ git log --pretty=oneline

1094adb7b9b3807259d8cb349e7df1d4d6477073 (HEAD -> master) append GPL

e475afc93c209a690c39c13a46716e8fa000c366 add distributed

eaadf4e385e865d25c48e7ca9c8395c3f7dfaef0 wrote a readme file
# 类似1094adb...的是commit id（版本号）
```



每提交一个新版本，实际上Git就会把它们自动串成一条时间线。如果使用可视化工具查看Git历史，就可以更清楚地看到提交历史的时间线。

 

在Git中，**用HEAD表示当前版本**，也就是最新的提交1094adb...，上一个版本就是HEAD^，上上一个版本就是HEAD^^，当然往上100个版本写100个^比较容易数不过来，所以写成HEAD~100。

**使用git reset命令回退版本**：

```
$ git reset --hard HEAD^

HEAD is now at e475afc add distributed

# 这样就退回到上一个版本了

#也可以用git reset --hard+版本号（版本号只需要前面几位就行）
```

**用git reflog查看命令历史**

### 2.5 工作区和暂存区

工作区（Working Directory）: 就是你在电脑里能看到的目录

版本库（Repository）: 工作区有一个隐藏目录.git，这个不算工作区，而是Git的版本库。

Git的版本库里存了很多东西，其中最重要的就是称为stage（或者叫index）的暂存区，还有Git为我们自动创建的第一个分支master，以及指向master的一个指针叫HEAD。

 

往Git版本库里添加的时候，是分两步执行的：

第一步是用git add把文件添加进去，实际上就是把文件修改添加到暂存区；

第二步是用git commit提交更改，实际上就是把暂存区的所有内容提交到当前分支。

 

\# 每次修改，如果不用git add到暂存区，那就不会加入到commit中。

### 2.6 撤销修改



场景1：当你改乱了**工作区**某个文件的内容，想直接丢弃工作区的修改时，用命令`git checkout -- file`。

```
$ git checkout -- readme.txt
# 命令git checkout -- readme.txt意思就是，把readme.txt文件在工作区的修改全部撤销
```

场景2：当你不但改乱了工作区某个文件的内容，还添加到了暂存区时，想丢弃修改，分两步，第一步用命令`git reset HEAD <file>`，就回到了场景1，第二步按场景1操作。

```
$ git reset HEAD readme.txt
Unstaged changes after reset:
M	readme.txt

$ git checkout -- readme.txt
```

**git reset命令既可以回退版本，也可以把暂存区的修改回退到工作区。**当我们用HEAD时，表示最新的版本



场景3：已经提交了不合适的修改到版本库时，想要撤销本次提交，参考 [05 版本回退] 一节，不过前提是没有推送到远程库。



### 2.7 删除文件

git rm <file>  从版本库中删除文件, 删除后需要commit

```
$ rm test.txt			

# 在工作区（即当前文件夹）删除text.txt文件,这不是git命令

# 工作区和版本库就不一致了，工作区没有text.txt，而版本库里还有这个文件
# 现在有两个选择：		
# (1) 从版本库中删除该文件，那就用命令git rm删掉，并且git commit：
$ git rm test.txt
rm 'test.txt'

$ git commit -m "remove test.txt"
...

# (2) 另一种情况是删错了，因为版本库里还有，所以可以git checkout命令撤销修改：
$ git checkout -- test.txt 

#git checkout其实是用版本库里的版本替换工作区的版本，无论工作区是修改还是删除，都可以“一键还原”。
```



## 03 推送至远程仓库

### 3.1 设置ssh key

由于你的本地Git仓库和GitHub仓库之间的传输是通过SSH加密的，所以，需要一点设置：

第1步：创建SSH Key。在用户主目录下，看看有没有.ssh目录，如果有，再看看这个目录下有没有`id_rsa`和`id_rsa.pub`这两个文件(这两个是隐藏文件)，如果已经有了，可直接跳到下一步。如果没有，打开Shell（Windows下打开Git Bash），创建SSH Key：

```
$ ssh-keygen -t rsa -C "youremail@example.com"
```

你需要把邮件地址换成你自己的邮件地址，然后一路回车，使用默认值即可.

第2步：登陆GitHub，打开“Account settings”，“SSH Keys”页面：

然后，点“Add SSH Key”，填上任意Title，在Key文本框里粘贴`id_rsa.pub`文件的内容.

### 3.2 添加远程库

**git remote add ----添加远程仓库**

**git push ----推送至远程仓库**

```
$ git remote add origin git@github.com:yourname/the_respository.git

# 添加后，远程库的名字就是origin，这是Git默认的叫法，也可以改成别的，但是origin这个名字一看就知道是远程库.

$ git push -u origin master

# 由于远程库是空的，我们第一次推送master分支时，加上了-u参数，Git不但会把本地的master分支内容推送的远程新的master分支，还会把本地的master分支和远程的master分支关联起来.
# 后面推送只要使用命令: git push origin master

```

### 3.2 从远程仓库获取

**git clone ----获取远程仓库**

**git pull ----获取最新的远程仓库分支**

要克隆一个仓库，首先必须知道仓库的地址，然后使用`git clone`命令克隆。Git支持多种协议，包括`https`，但通过`ssh`支持的原生`git`协议速度最快。

```
$ git clone git@github.com:SongChongyong/Learn_git.git

# 克隆git@github.com:SongChongyong/Learn_git.git 下所有文件到工作区(工作区会新建一个Learn_git文件夹保存所有文件)

$ git pull origin master

# 假设github远程库的master分支文件有修改,使用git pull origin master可以将本地仓库中的master分支更新到github库master分支状态

```



## 04 分支----待整理

### 4.1 创建与合并分支

查看分支：git branch

创建分支：git branch <name>

切换分支：git checkout <name>

创建+切换分支：git checkout -b <name>

合并某分支到当前分支：git merge <name>

删除分支：git branch -d <name>

```
$ git branch
* master

# ===================(1)创建切换分支到terence_thinkpad分支
$ git checkout -b terence_thinkpad
Switched to a new branch 'terence_thinkpad'

$ git branch
  master
* terence_thinkpad

# ====================(2)然后在terence_thinkpad分支做各种操作,完成后需要add+commit
# ====================(3)然后要切换回"master"分支
# ====================(4)切换回master分支后,在把terence_thinkpad分支合并到master分支
$ git merge terence_thinkpad 

$ git branch
* master
  terence_thinkpad
# ====================(5)现在可以删除不需要的分支了
$ git branch -b terence_thinkpad


```



### 4.2 解决冲突
当Git无法自动合并分支时，解决冲突就是把Git合并失败的文件手动编辑为我们希望的内容，再提交。

用git log --graph命令可以看到分支合并图。

### 4.3 分支管理策略
Git分支十分强大，在团队开发中应该充分应用。

合并分支时，加上--no-ff参数就可以用普通模式合并，合并后的历史有分支，能看出来曾经做过合并，而fast forward合并就看不出来曾经做过合并。

### 4.4 Bug分支
修复bug时，我们会通过创建新的bug分支进行修复，然后合并，最后删除；

当手头工作没有完成时，先把工作现场git stash一下，然后去修复bug，修复后，再git stash pop，回到工作现场。

### 4.5 Feature分支
开发一个新feature，最好新建一个分支；

如果要丢弃一个没有被合并过的分支，可以通过git branch -D <name>强行删除。

### 4.6 多人协作
因此，多人协作的工作模式通常是这样：

1.首先，可以试图用git push origin <branch-name>推送自己的修改；

2.如果推送失败，则因为远程分支比你的本地更新，需要先用git pull试图合并；

3.如果合并有冲突，则解决冲突，并在本地提交；

4.没有冲突或者解决掉冲突后，再用git push origin <branch-name>推送就能成功！

如果git pull提示no tracking information，则说明本地分支和远程分支的链接关系没有创建，用命令git branch --set-upstream-to <branch-name> origin/<branch-name>。

--小结
查看远程库信息，使用git remote -v；

本地新建的分支如果不推送到远程，对其他人就是不可见的；

从本地推送分支，使用git push origin branch-name，如果推送失败，先用git pull抓取远程的新提交；

在本地创建和远程分支对应的分支，使用git checkout -b branch-name origin/branch-name，本地和远程分支的名称最好一致；

建立本地分支和远程分支的关联，使用git branch --set-upstream branch-name origin/branch-name；

从远程抓取分支，使用git pull，如果有冲突，要先处理冲突。