```powershell
# 开/关 风扇自动调节，当最后一个16进制数为0x00时为关闭，0x01时为开启
ipmitool.exe -I lanplus -H 192.168.1.200 -U root -P  calvin raw 0x30 0x30 0x01 0x00
```

```powershell
#设置风扇转速，最后一个16进制数为转速的百分比，0x14对应20%，0x0f对应15%，0x0a对应10%
ipmitool.exe -I lanplus -H 192.168.1.200 -U root -P  calvin raw 0x30 0x30 0x02 0xff 0x05
```

https://www.dell.com/support/home/zh-cn/drivers/DriversDetails?productCode=poweredge-r720xd&driverId=9NGFJ