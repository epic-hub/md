1、安装工具

```cobol
sudo apt install device-tree-compiler
```

2、dtb_name[反编译](https://so.csdn.net/so/search?q=反编译&spm=1001.2101.3001.7020)成dts_name

```bash
dtc -I dtb -O dts dtb_name.dtb -o dts_name.dts
```