# Linux  命令行

此项目是学习<Linux命令行大全>练习笔记.

![Linux命令行大全](./pictures/01_Linux命令行大全.jpg)


## 第二章 导航--文件系统

**pwd**: 查看当前工作目录

**ls**: 列出目录

**cd**: 改变目录

绝对路径名: 从根目录开始,其后紧接着一个又一个树分支,直到到达目标目录或文件.

```
$ pwd
/home/terence
# 其中第一个"/"表示根目录/, "/home/terence"表示就是绝对路径,表示"根目录下的home文件夹下的terence"
```

绝对路径名:  从工作目录开始. 有一些特殊符号来表示文件系统树中的相对位置: 符号"."表示工作目录, 符号".."表示工作目录的父目录.

**Linux文件命名中不要嵌入空格,以免命令行出现错误**



## 第三章 Linux系统

**ls**: 列出目录

**file**: 确定文件类型

**less**: 参看文件内容

### 3.1 ls 命令列出目录

ls命令,可以查看当前目录中包含的一系列文件和子目录

```
$ ls
Git_Notes.md  Linux_command_line.md  pictures
```

ls命令还可以制定要显示的目录

```
$ ls /usr
bin  games  include  lib  local  locale  sbin  share  src
# ls /usr列出了主目录下usr目录的所有文件和目录
```

ls还可以制定多个目录

```
$ ls ~ /usr
/home/terence:
AI_programs  Desktop    Downloads         exercise01  Pictures  Templates
anaconda3    Documents  examples.desktop  Music       Public    Videos

/usr:
bin  games  include  lib  local  locale  sbin  share  src
# ~表示用户主目录
```

| 选项 | 长选项           | 描述                                                         |
| :--- | :--------------- | :----------------------------------------------------------- |
| -a   | --all            | 列出所有文件(包括隐藏文件)                                   |
| -h   | --human-readable | 当以长格式列出时，以人们可读的格式，而不是以字节数来显示文件的大小。 |
| -l   |                  | 以长格式显示结果--文件大小用字节表示                         |

```
$ ls -alh
total 32K
drwxrwxr-x 4 terence terence 4.0K Jun 14 03:50 .
drwxrwxr-x 6 terence terence 4.0K Jun 12 16:42 ..
drwxrwxr-x 8 terence terence 4.0K Jun 14 03:52 .git
-rw-rw-r-- 1 terence terence  12K Jun 12 16:30 Git_Notes.md
-rw-rw-r-- 1 terence terence  802 Jun 14 03:50 Linux_command_line.md
drwxrwxr-x 2 terence terence 4.0K Jun 14 03:47 pictures
```

### 3.2 file 命令确定文件类型

file 命令会打印出文件内容的简短说明.

```
$ file Git_Notes.md 
Git_Notes.md: UTF-8 Unicode text
```



### 3.3 less 命令参看文件内容

less filename查看文本文件,一旦文件运行,按'q'键退出less程序.



## 第十四章 软件包管理

