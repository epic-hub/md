# 安装

环境ubuntu18.04

使用国内 daocloud 一键安装命令：

```bash
curl -sSL https://get.daocloud.io/docker | sh
```



# 换源

**创建或修改 /etc/docker/daemon.json 文件，修改：**

```bash
vim /etc/docker/daemon.json
```


```bash
{
    "registry-mirrors" : [
    "https://registry.docker-cn.com",
    "http://hub-mirror.c.163.com",
    "https://docker.mirrors.ustc.edu.cn",
    "https://cr.console.aliyun.com",
    "https://mirror.ccs.tencentyun.com"
  ]
}
```

**重启docker服务使配置生效：**

```bash
systemctl daemon-reload
systemctl restart docker.service
```

**查看配置是否成功：**


```bash
docker info
```





```
export DOCKER=/home/docker/
```

​	

# 容器

```bash
docker run -d -p 8880:9000 --restart=always -v /var/run/docker.sock:/var/run/docker.sock --name portainer portainer/portainer
```

```bash
docker run -d --name ddns-go --restart=always --net=host -v $DOCKER/ddns-go:/root jeessy/ddns-go -l :9876 -f 600
```

```bash
docker run -d --name ddns-go-2 --restart=always --net=host -v $DOCKER/ddns-go-2:/root jeessy/ddns-go -l :9877 -f 600
```

```bash
docker run -d --name cadvisor -p 2082:8080 -v /:/rootfs:ro -v /var/run/:/var/run/:rw -v /sys/:/sys/:ro -v /var/lib/docker/:/var/lib/docker/:ro -v /dev/disk/:/dev/disk/:ro google/cadvisor
```

```bash
docker run -td \
  --restart=always \
  -p 8080:8080 \
  -v $DOCKER/guacamole:/config \
  oznu/guacamole
```

```bash
docker run -d \
  --name=heimdall \
  -e PUID=1000 \
  -e PGID=1000 \
  -e TZ=Etc/UTC \
  -p 2095:80 \
  -p 4433:443 \
  -v $DOCKER/heimdall:/config \
  --restart=always \
  lscr.io/linuxserver/heimdall:latest
```

