查看位数

getconf LONG_BIT

linux版本

uname -a

du -sh * 当前目录大小

```
find . -name ".git" -exec rm -rf {} \;
.:当前目录
"*.pyc":目标文件
-exec:选项
rm -rf:强制删除文件，包括目录
{} \;:固定写法，一对大括号+空格+\;
```

# 删除指定文件（夹）之外的所有文件呢？

方法1，复制需要保留的文件到其他文件夹，然后将该目录删除， 然后将需要保留的移回来。 mv keep …/ #保留文件（夹）keep rm -rf * #删除当前文件夹里的所有文件 mv …/keep ./ #将原来的东西移动回来

方法2，当前文件夹中结合使用grep和xargs来处理文件名： ls | grep -v keep | xargs rm #删除keep文件之外的所有文件 说明： ls先得到当前的所有文件和文件夹的名字， grep -v keep，进行grep正则匹配查找keep，-v参数决定了结果为匹配之外的结果，也就是的到了keep之外的所有文件名，然后 xargs用于从标准输入获得参数 并且传递给后面的命令，这里使用的命令是 rm，然后由rm删除前面选择的文件。 好处：使用了grep来正则表达式来匹配文件名字，可以一次保留多个文件，从而进行更加准确的处理。

方法3，使用find命令代替ls，改进方法3从而能够处理指定文件夹的文件： find ./test/ | grep -v keep | xargs rm #删除当前test文件夹中keep文件之外的所有文件 说明，用grep而不用find -name选取名字，因为find选取名字时比较麻烦，对正则表达式支持不够，无法排除指定文件名。

5、方法4，直接使用find命令删除其他文件： find ./ -name ‘[k][e][e][p]’ -exec rm -rf {} ; #删除keep以外的其他文件。 find ./ -name '[k][e][e][p]’ | xargs rm -rf #删除keep以外的其他文件。推荐！ 说明：上面第二行的代码效率高些，原因在于删除多个文件时 -exec会启动多个进程来处理，而xargs会启动一个rm进程来处理。

```
md5sum	#文件
```



Linux进入nano模式,出现如下样子:

G Get Help      ^O Write Out     ^W Where Is      ^K Cut Text      ^J Justify       ^C Cur Pos       M-U Undo         M-A Mark Text    M-] To Bracket   M-Q Previous
^X Exit          ^R Read File     ^\ Replace       ^U Uncut Text    ^T To Spell      ^_ Go To Line    M-E Redo         M-6 Copy Text    ^Q Where Was     M-W Next


这个时候按crtl+x，选择yes即可退出。




定时任务

```
1，定时任务命令及主要参数

       crond 是linux用来定期执行程序的命令。当安装完成操作系统之后，默认便会启动此任务调度命令。crond命令每分锺会定期检查是否有要执行的工作，如果有要执行的工作便会自动执行该工作。

命令：crontab

参数：

（1）-u: 指定一个用户。

（2）-e: 编辑crontab 的工作内容;

（3）-l: 列出某个用户的任务计划，查阅crontab的工作内容;

（4）-r: 删除所有的crontab的工作内容，若仅要删除一项，请用-e去编辑。
2，crontab -e

进入vi的编辑界面，每个命令是一行，有6个参数内容

内容含义：

（1）分：0~59。

（2）时：0~23。

（3）日：1~31。

（4）月：1~12。

（5）周：0~7，0或7，都代表“星期天”的意思。

（6）命令：需要定时运行的任务命令。

特殊字符：定时的参数字符可以用特殊字符代替。可以代替的字符有：

（1）*(星号)：代表该参数含义所有范围任何时刻都需要运行。

（2）,(逗号)：代表分隔时刻的意思，例如如果要执行的工作是2：00与7：00时，命令为：0 2,7 * * * command

（3）-(减号)： 代表一段时间范围内需要执行，例如如果要执行的工作是2：00到7：00执行，命令为：0 2-7 * * * command

（4）/n(斜线)： 那个n代表数字，即是每隔n单位间隔的意思，例如每八分钟进行一次，命令为：*/8 * * * * command
3，开启定时任务

命令：crontab /weblogic/tools/task.crontab
4，停止定时任务

命令：crontab /weblogic/tools/task.null.crontab     //task.null.crontab是一个没有内容的空文件
```

| $#   | 传递到脚本的参数个数                                         |
| ---- | ------------------------------------------------------------ |
| $*   | 以一个单字符串显示所有向脚本传递的参数。  如"$*"用「"」括起来的情况、以"$1 $2 … $n"的形式输出所有参数。 |
| $$   | 脚本运行的当前进程ID号                                       |
| $!   | 后台运行的最后一个进程的ID号                                 |
| $@   | 与$*相同，但是使用时加引号，并在引号中返回每个参数。  如"$@"用「"」括起来的情况、以"$1" "$2" … "$n" 的形式输出所有参数。 |
| $-   | 显示Shell使用的当前选项，与[set命令](https://www.runoob.com/linux/linux-comm-set.html)功能相同。 |
| $?   | 显示最后命令的退出状态。0表示没有错误，其他任何值表明有错误。 |

# ssh

```
ssh-keygen -t ed25519 -C "xxxxx@xxxxx.com"  
cat ~/.ssh/id_ed25519.pub
```

