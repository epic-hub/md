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

- docker run --rm -it -d --name webssh2 -p 2082:2222 psharkey/webssh2









docker run --rm guacamole/guacamole /opt/guacamole/bin/initdb.sh --mysql > initdb.sql



docker run --name guacamole --restart=always  --link guacd:guacd --link mysql:mysql -e MYSQL_DATABASE='guacamole' -e MYSQL_USER='guacamole' -e MYSQL_PASSWORD='guacamole' -d -p 8080:8080 guacamole/guacamole
