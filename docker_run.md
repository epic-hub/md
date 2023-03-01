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
export DATA=/home/sdb
export DOWNLOAD=/home/sdb/share/download
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

```bash
docker run --restart=always -d -v $DATA:/srv -v $DOCKER/filebrowser/filebrowserconfig.json:/etc/config.json -v $DOCKER/filebrowser/database.db:/etc/database.db -p 2052:80 filebrowser/filebrowser
```

```bash
docker run -d \
    --name aria2-pro \
    --restart=always \
    --log-opt max-size=1m \
    -e PUID=$UID \
    -e PGID=$GID \
    -e UMASK_SET=022 \
    -e RPC_SECRET=password \
    -e RPC_PORT=6800 \
    -p 6800:6800 \
    -e LISTEN_PORT=6888 \
    -p 6888:6888 \
    -p 6888:6888/udp \
    -v $DOCKER/aria2-pro:/config \
    -v $DOWNLOAD:/downloads \
    p3terx/aria2-pro
```

```bash
docker run -d \
    --name ariang \
    --log-opt max-size=1m \
    --restart=always \
    --network host \
    p3terx/ariang --port 6880 --ipv6
```

```bash
docker run -d --restart=always -v $DOCKER/alist:/opt/alist/data -p 5244:5244 --name="alist" xhofe/alist:latest
```

```bash
docker run --restart=always --name filetash -d -p 8334:8334 machines/filestash
```

```bash

docker run --name nginx  -d nginx


# 将容器nginx.conf文件复制到宿主机
docker cp nginx:/etc/nginx/nginx.conf $DOCKER/nginx/conf/nginx.conf
# 将容器conf.d文件夹下内容复制到宿主机
docker cp nginx:/etc/nginx/conf.d $DOCKER/nginx/conf/
# 将容器中的html文件夹复制到宿主机
docker cp nginx:/usr/share/nginx/html $DOCKER/nginx/

docker rm -f nginx

docker run  --name nginx -d --restart=always --net=host -v $DOCKER/nginx/html:/usr/share/nginx/html -v $DOCKER/nginx/conf/nginx.conf:/etc/nginx/nginx.conf -v $DOCKER/nginx/conf/conf.d:/etc/nginx/conf.d  -v $DOCKER/nginx/logs:/var/log/nginx nginx
```

```bash
docker run -dit \
   -v $DOCKER/ql/config:/ql/config \
   -v $DOCKER/ql/log:/ql/log \
   -v $DOCKER/ql/db:/ql/db \
   -p 5700:5700 \
   --name qinglong \
   --hostname qinglong \
   --restart always \
   whyour/qinglong:latest
```





# 说明

## filebrowser/filebrowser

user：admin

password：admin

## oznu/guacamole

user: guacadmin

password: guacadmin

## xhofe/alist

如果您是站点的所有者，您可以通过在终端中运行 `./alist admin` 来获取管理员账号信息。

https://alist.nn.ci/zh/guide/drivers/baidu.html