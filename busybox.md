# dd

```
二进制文件, 文件很大, 如果要替换指定偏移处的特定字节. 又不希望产生新文件. 可以用下面的命令实现

printf "\x00" | dd of=big_binary.dat bs=1 count=1 conv=notrunc bs=1 count=1 seek=2

管道前的printf 命令用来产生一个字节的二进制数据, 故意用NUL字符, 以示可以替换为任意内容.
if 没有指定时, 从标准输入读取内容
of指定的是要修改的文件, bs=1 count=1确定要改的字节数, conv=notrunc很重要, 确保修改完这一个字节, 文件的其它部分保持不变.
seek=2 是跳过前面的2个字节. 注意skip是用于指定读取文件时跳过的字节, seek指定写文件时跳过的字节.

用这种办法, 只能把2个字节的内容替换为2个字节, 少一字多一字都不行.

＝＝＝
今天，我又在脚本中重新实现了一次替换二进制文件的内容。
函数如下，这次，指定了可以替换的源和目标串。稍加修改，也可以替换二进制的内容。

这个函数不需要指定偏移，自动通过 grep -P 的PCRE 正则表达式引擎来搜索。

需要注意的一个地方是od 的-v 参数，如果没有它，一些重复的数据可能不会输出出来。

 the target binary file
# arg 2: the source data
# arg 3: the dest data to subsititute [arg 2], should be same length as [arg 2]
function replace_data()
{
    prog="$1"
    from="$2"
    to="$3"
    len=${#from}
    if [ $len != "${#to}" ]; then
        echo "len[$from] != len[$to]" >&2
        return 1;
    fi
    from_re="$(echo -n $from | od -v -t x1 -w$len | cut -d ' ' -f2- | head -1 | tr ' ' '.' )"
    echo -n "$to" > to_file
    line_no="$(od -v -t x1 -w1 $prog | cut -d ' ' -f2 | grep -nP '(?s)'$from_re)"
    if [ $? != 0 ]; then
        echo "Fail to find [$line_no] '(?s)$from_re'" >&2
        return 1;
    fi
    line_no="${line_no%:*}"

    dd if=to_file of=$prog conv=notrunc count=${len} seek=$((line_no-1)) bs=1c
}
```



# cmp

```
#对比字节差异
cmp libdisplay_layer.so libdisplay_layer.so.test -l
```

# tar

```
[root@linux ~]# tar -cvf /tmp/etc.tar /etc <==仅打包，不压缩！
[root@linux ~]# tar -zcvf /tmp/etc.tar.gz /etc <==打包后，以 gzip 压缩
[root@linux ~]# tar -jcvf /tmp/etc.tar.bz2 /etc <==打包后，以 bzip2 压缩
```

