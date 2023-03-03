# portainer/portainer

docker run -d -p 9000:9000 -v /var/run/docker.sock:/var/run/docker.sock --name portainer portainer/portainer





# filebrowser/filebrowser

```
sudo docker run -d -v /home/epic/公共的:/srv -v /home/epic/公共的/filebrowserconfig.json:/etc/config.json -v /home/epic/公共的/database.db:/etc/database.db -p 2052:80 filebrowser/filebrowser
```





# ddns-go

- 挂载主机目录, 使用docker host模式。可把 `/opt/ddns-go` 替换为你主机任意目录, 配置文件为隐藏文件

  ```bash
  docker run -d --name ddns-go --restart=always --net=host -v /opt/ddns-go:/root jeessy/ddns-go
  ```

- 在浏览器中打开`http://主机IP:9876`，修改你的配置，成功

- [可选] 支持启动带参数 `-l`监听地址 `-f`间隔时间(秒)

  ```bash
  docker run -d --name ddns-go --restart=always --net=host -v /opt/ddns-go:/root jeessy/ddns-go -l :9877 -f 600
  ```

- [可选] 不使用docker host模式

  ```bash
  docker run -d --name ddns-go --restart=always -p 9876:9876 -v /opt/ddns-go:/root jeessy/ddns-go
  ```





# psharkey/webssh2

- docker run --restart=always -it -d --name webssh2 -p 2082:2222 psharkey/webssh2





# browser

sudo docker run --rm -it -d --shm-size=512m -p 9999:6901 -e VNC_PW=password kasmweb/chrome:1.12.0

- User : kasm_user
- Password: password



```shell
docker run -d \
    --name=firefox \
    -p 9999:5800 \
    -e ENABLE_CJK_FONT=1 \
    -e VNC_PASSWORD=123 \
    -e KEEP_APP_RUNNING=1 \
    -v $(pwd)/config/firefox:/config:rw \
    -v $(pwd)/share/download/firefox:/config/downloads:rw \
    jlesage/firefox
```

#  google/cadvisor

docker run -d --name cadvisor -p 8080:8080 -v /:/rootfs:ro -v /var/run/:/var/run/:rw -v /sys/:/sys/:ro -v /var/lib/docker/:/var/lib/docker/:ro -v /dev/disk/:/dev/disk/:ro google/cadvisor



sudo docker run -itd -p 8888:80 openwrtorg/rootfs:x86_64-snapshot



docker run --rm guacamole/guacamole /opt/guacamole/bin/initdb.sh --mysql > initdb.sql



docker run --name guacamole --restart=always  --link guacd:guacd --link mysql:mysql -e MYSQL_DATABASE='guacamole' -e MYSQL_USER='guacamole' -e MYSQL_PASSWORD='guacamole' -d -p 8080:8080 guacamole/guacamole













# guacamole

拉取Guacamole服务器、Guacamole客户端和MySQL的Docker镜像
拉取以上镜像 （黑窗口）；
docker pull guacamole/guacamole
docker pull guacamole/guacd
docker pull mysql/mysql-server
运行Mysql并配置
镜像拉取完成后，创建数据库初始化脚本以创建数据表 ；
docker run --rm guacamole/guacamole /opt/guacamole/bin/initdb.sh --mysql > initdb.sql

启动mysql-server ；
docker run --name mysqltest -e MYSQL_RANDOM_ROOT_PASSWORD=yes -e MYSQL_ONETIME_PASSWORD=yes -d mysql/mysql-server

查看日志，获取密码（二者选其一） ；
docker logs mysqltest
上方的命令执行后查找 [Entrypoint] GENERATED ROOT PASSWORD: 这个字段冒号后面是密码牢记，登录mysql时需要
docker logs mysqltest|grep GENERATED
上方命令密码会在下面显示

重命名脚本并转移到已经运行的sql容器以便生成表 ；
docker cp initdb.sql mysqltest:/guac_db.sql

打开mysql终端 ；
docker exec -it mysqltest bash

登录mysql ；
mysql -uroot -p（紧接记录的密码直接连接）
mysql -u root -p （需要输入密码）

重新设定root用户密码 ；
ALTER USER ‘root’@‘localhost’ IDENTIFIED BY ‘123456’;
用户密码和路径可以自定义

创建数据库以及创建用户 ；
CREATE DATABASE guacamole_db;（创建数据库）
CREATE USER ‘root’@‘%’ IDENTIFIED BY ‘123456’; （创建用户）
GRANT SELECT,INSERT,UPDATE,DELETE ON guacamole_db.* TO ‘root’@‘%’;
FLUSH PRIVILEGES;（创建用户权限）
创建完成后输入quit退去

使用脚本创建数据表 ；
cat guac_db.sql | mysql -u root -p guacamole_db
需要输入9里面创建用户的密码

验证数据库操作是否成功 ；
mysql -uroot -p123456（连接数据库）
USE guacamole_db;(选择数据库)
SHOW TABLES;(查看所有的表)



## 配置Guacamole服务器，Guacamole客户端

**1.启动guacd** ；
docker run --name myguacd -d -p 4822:4822 guacamole/guacd

**2.启动guacamole，并连接guacd，mysql** ；

docker run --name myguacamole \
--link myguacd:guacd \
--link mysqltest:mysql \
-e MYSQL_DATABASE=guacamole_db \
-e MYSQL_USER=root \
-e MYSQL_PASSWORD=123456 \
-d -p 8080:8080 \
guacamole/guacamole







docker run -d \
-e TZ=Asia/Shanghai \
--name jellyfin \
--restart always \
-v /opt/jellyfin/config:/config \
-v /opt/jellyfin/cache:/cache \
-v /opt/jellyfin/Music:/Music \
-v /opt/jellyfin/Movies:/Movies \
-v /opt/jellyfin/Photo:/Photo \
-p 8099:8096 \
jellyfin/jellyfin







mkdir -p ./plex/config
mkdir -p ./plex/transcode
mkdir -p ./plex/data
mkdir -p ./plex/video
mkdir -p ./plex/photo
mkdir -p ./plex/music

docker run \
-d \
-p 32400:32400 \
-p 32400:32400/udp \
--name plex \
--network=host \
--restart=always \
-e TZ="Asia/Shanghai" \
-e PLEX_CLAIM="claim-zJTKwdyy1nmoFZpx5job" \
-e PUID=1000 \
-e PGID=1000 \
-v $(pwd)/plex/config:/config \
-v $(pwd)/plex/transcode:/transcode \
-v $(pwd)/plex/data:/data \
-v $(pwd)/plex/video:/video \
-v $(pwd)/plex/photo:/photo \
-v $(pwd)/plex/music:/music \
linuxserver/plex





docker run -v /:/rootfs:ro -v /var/run:/var/run:rw -v /sys:/sys:ro -v /var/lib/docker/:/var/lib/docker:ro -p 7777:8080 --detach=true --privileged=true --name=cadvisor --restart=always google/cadvisor:latest




```console
docker run --name some-wordpress -p 6666:80 -d wordpress
```

docker run -dit -p 3333:8080 -p 6080:6080 -p 5999:5901 -v $(pwd):/root/下载 --name ubuntu1 ljdyw/ubuntu-novnc:latest

```
docker run -d \
    --name aria2-pro \
    --restart unless-stopped \
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
    -v $PWD/config/aria2-config:/config \
    -v $PWD/share/download/aria2-downloads:/downloads \
    p3terx/aria2-pro
```



docker run -d --restart=always -v $(pwd)/alist:/opt/alist/data -p 5244:5244 --name="alist" xhofe/alist:latest



```
docker run -d \
    --name ariang \
    --log-opt max-size=1m \
    --restart unless-stopped \
    --network host \
    p3terx/ariang --port 6880 --ipv6
```



```cmd
docker run  -d -h mail.ewomail.com --restart=always \
  -p 25:25 \
  -p 109:109 \
  -p 110:110 \
  -p 143:143 \
  -p 465:465 \
  -p 587:587 \
  -p 993:993 \
  -p 995:995  \
  -p 801:80 \
  -p 8888:8080 \
  -v `pwd`/mysql/:/ewomail/mysql/data/ \
  -v `pwd`/vmail/:/ewomail/mail/ \
  -v `pwd`/ssl/certs/:/etc/ssl/certs/ \
  -v `pwd`/ssl/private/:/etc/ssl/private/ \
  -v `pwd`/rainloop:/ewomail/www/rainloop/data \
  -v `pwd`/ssl/dkim/:/ewomail/dkim/ \
  --name ewomail bestwu/ewomailserver
```







```bash
docker run --name zabbix-appliance -t  -d \
      -e PHP_TZ="Asia/Shanghai" \
      -v /etc/timezone:/etc/timezone \
      -v /etc/localtime:/etc/localtime \
      -p 7051:10051  -p 7080:80  \
      zabbix/zabbix-appliance:latest

```

docker run --name mysql-server -t \
      -e MYSQL_DATABASE="zabbix" \
      -e MYSQL_USER="zabbixadmin" \
      -e MYSQL_PASSWORD="zabbixpwd" \
      -e MYSQL_ROOT_PASSWORD="zabbixroot" \
      -v /usr/local/docker/mysql:/var/lib/mysql \
      -v /etc/localtime:/etc/localtime \
      -d mysql:5.7 \
      --character-set-server=utf8 \
      --collation-server=utf8_bin 





docker run --name zabbix-server-mysql -t \
      -e DB_SERVER_HOST="mysql-server" \
      -e MYSQL_DATABASE="zabbix" \
      -e MYSQL_USER="zabbixadmin" \
      -e MYSQL_PASSWORD="zabbixpwd" \
      -e MYSQL_ROOT_PASSWORD="zabbixroot" \
      -v /etc/localtime:/etc/localtime \
      --link mysql-server:mysql \
      -p 10051:10051 \
      -d zabbix/zabbix-server-mysql:centos-5.4.0

docker run --name zabbix-web-nginx-mysql -t \
      -e DB_SERVER_HOST="mysql-server" \
      -e MYSQL_DATABASE="zabbix" \
      -e MYSQL_USER="zabbixadmin" \
      -e MYSQL_PASSWORD="zabbixpwd" \
      -e MYSQL_ROOT_PASSWORD="zabbixroot" \
      -v /etc/localtime:/etc/localtime \
      --link mysql-server:mysql \
      --link zabbix-server-mysql:zabbix-server \
      -p 5080:8080 \
      -d zabbix/zabbix-web-nginx-mysql:centos-5.4.0

```shell
docker run -td \
  --restart=always \
  --network=host \
  -v /config:/config \
  oznu/guacamole
```

docker run --name zabbix-agent \
	  --restart=always \
	  --network=host \
      -e ZBX_HOSTNAME="Tomcat1V3_agent" \
      -e ZBX_SERVER_HOST="10.0.1.17" \
      -e ZBX_METADATA="Tomcat1V3_agent" \
      --privileged \
      -d zabbix/zabbix-agent:alpine-4.0.24




```
docker run -p 4080:80 -h icinga2 -t jordan/icinga2:latest
```

# 失败

```
docker run --rm  -it  \
  -v "$DOCKER/nginx/conf/conf.d/acme":/acme.sh  \
  -e DP_Id="390654" \
  -e DP_Key="95c8f18944e557de589409b77ec9a622" \
  neilpang/acme.sh  --issue --dns dns_dp -d djw0.tk -d *.djw0.tk 
  
  
  
  --register-account -m 872218780@qq.com
  epicfor1024@gmail.com
  https://console.dnspod.cn/account/token/token
  https://github.com/acmesh-official/acme.sh/wiki/dnsapi
```



