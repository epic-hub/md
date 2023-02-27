查看位数

getconf LONG_BIT	



linux版本  

uname -a	



du -sh *	当前目录大小

```
find . -name ".git" -exec rm -rf {} \;
.:当前目录
"*.pyc":目标文件
-exec:选项
rm -rf:强制删除文件，包括目录
{} \;:固定写法，一对大括号+空格+\;
```

# 删除指定文件（夹）之外的所有文件呢？
方法1，复制需要保留的文件到其他文件夹，然后将该目录删除， 然后将需要保留的移回来。
mv keep …/ #保留文件（夹）keep
rm -rf * #删除当前文件夹里的所有文件
mv …/keep ./ #将原来的东西移动回来

方法2，当前文件夹中结合使用grep和xargs来处理文件名：
ls | grep -v keep | xargs rm #删除keep文件之外的所有文件
说明： ls先得到当前的所有文件和文件夹的名字， grep -v keep，进行grep正则匹配查找keep，-v参数决定了结果为匹配之外的结果，也就是的到了keep之外的所有文件名，然后 xargs用于从标准输入获得参数 并且传递给后面的命令，这里使用的命令是 rm，然后由rm删除前面选择的文件。
好处：使用了grep来正则表达式来匹配文件名字，可以一次保留多个文件，从而进行更加准确的处理。

方法3，使用find命令代替ls，改进方法3从而能够处理指定文件夹的文件：
find ./test/ | grep -v keep | xargs rm #删除当前test文件夹中keep文件之外的所有文件
说明，用grep而不用find -name选取名字，因为find选取名字时比较麻烦，对正则表达式支持不够，无法排除指定文件名。

5、方法4，直接使用find命令删除其他文件：
find ./ -name ‘[k][e][e][p]’ -exec rm -rf {} ; #删除keep以外的其他文件。
find ./ -name '[k][e][e][p]’ | xargs rm -rf #删除keep以外的其他文件。推荐！
说明：上面第二行的代码效率高些，原因在于删除多个文件时 -exec会启动多个进程来处理，而xargs会启动一个rm进程来处理。







```
md5sum	#文件
```

