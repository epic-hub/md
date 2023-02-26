查看日志中访问次数最多的前10个IP
```
cat access.log | rev |cut -d ' ' -f 1 | rev |  sort |uniq -c | sort -nr | awk '{print $0 }' | head -n 30 | less
```

