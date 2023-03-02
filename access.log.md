## 查看日志中访问次数最多的前30个IP

```
cat access.log | rev |cut -d ' ' -f 1 | rev |  sort |uniq -c | sort -nr | awk '{print $0 }' | head -n 30 | less
```

## 从日志里查看该ip在干嘛

```
cat access.log | grep 2409:8a55:927d:efe0:80ba:527b:6ccd:ab54 | awk '{print $1"\t"$7}' | sort | uniq -c | sort -nr | less
```





"`date +%d`/`date -R | awk  '{print $3}' `"

生成昨天访问记录

```
cat access.log |grep "`date -d last-day +%d`/`date -R | awk  '{print $3}' `" | rev |cut -d ' ' -f 1 | rev |  sort |uniq -c | sort -nr | awk '{print $0 }' | head -n 50 | less

cat access.log |grep "`date -d last-day +%d`/`date -R | awk  '{print $3}' `" | grep -v 2400:cb00 |cut -d ' ' -f 1 | sort |uniq -c | sort -nr | awk '{print $0 }' | head -n 30 | less
```

