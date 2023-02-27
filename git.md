### （1）git clean -f `默认删除当前目录，且不删除目录`

### （2）无脑操作到根目录 git clean -fd `删除文件和目录`

```
git init
git remote add origin ssh://...
git add -Af .
git reset --hard ...

git format-patch f71d0....	#生成patch
git apply -R *.patch	#反向patch
git am *.patch
```



