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

sudo docker run --rm -it -d --shm-size=512m -p 2053:6901 -e VNC_PW=password kasmweb/chrome:1.12.0

- User : kasm_user
- Password: password





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

