```

nginx 强制https
1、使用nginx的rewrite方法
server {
            listen 80;
            server_name  xxx.com;
            rewrite ^(.*)$   https://$host$1 permanent;
}
2、使用nginx的301状态码
server {
    listen 80;
    listen 443;
    server_name xxx.com;
    ssl   on;
    ssl_certificate    /data/www-key/xxx.pem;
    ssl_certificate_key    /data/www-key/xxx.key;
    if ($scheme = http) {
    return 301 https://$server_name$request_uri;
    }
}
```

```
server {
        listen       80;
        server_name  XXX.com;   // 你的域名

        #charset koi8-r;

        #access_log  logs/host.access.log  main;

        location / {
            root   /home/hanstore;
            index  index.html index.htm;
        }

    location /music/ {    // 跟在域名后的路径，匹配到会进行反向代理，指向proxy_pass
        proxy_set_header X-Real-IP $remote_addr;
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
        proxy_set_header Host $http_host;
        proxy_set_header X-NginX-Proxy true;
        proxy_pass http://127.0.0.1:8080/;   // 服务器上启的本地服务，监听对应的端口
    }

    location /2048/ {
        proxy_set_header X-Real-IP $remote_addr;
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
        proxy_set_header Host $http_host;
        proxy_set_header X-NginX-Proxy true;
        proxy_pass http://127.0.0.1:2048/;
    }
}
```

配置

```

server {
    listen 80;
    listen  [::]:80;
    listen 443 ssl;
    listen  [::]:443 ssl;

    server_name djw0.tk;
    server_name 991105.xyz;

    ssl_certificate /etc/nginx/conf.d/server.crt;
    ssl_certificate_key /etc/nginx/conf.d/server.key;
    ssl_session_cache shared:SSL:1m;
    ssl_session_timeout 5m;
    ssl_ciphers HIGH:!aNULL:!MD5;
    ssl_prefer_server_ciphers on;

    if ($scheme = http) {
    return 301 https://$server_name$request_uri;
    }

    location /p/ {
        proxy_set_header Host $host;
        proxy_pass http://127.0.0.1:8880/;
    }
}


```

```bash
openssl genrsa -out server.key 4096
/*openssl genrsa 生成 RSA 私有秘钥，不会生成公钥，因为公钥提取自私钥。生成时是可以指定私钥长度和密码保护生成了一个4096字节的文件server.key,生成证书签署请求CSR*/
openssl req -new -key server.key -out server.csr
/*生成签署申请
其中，Country Name:两个字母的国家代号 
State or Province Name:省份名称
 Locality Name:城市名称 
Organization Name:公司名称 
Organizational Unit Name:部门名称 
Common Name:你的姓名 
Email Address:地址 此时生成签署文件server.csr.*/
openssl x509 -req -days 90 -in server.csr -signkey server.key -out server.crt
```

```

curl https://gitcode.net/cert/cn-acme.sh/-/raw/master/install.sh?inline=false | sh -s email=1161061620@qq.com

acme.sh --install-cert -d djw0.tk -d *.djw0.tk -d 991105.xyz -d *.991105.xyz \
--key-file       /home/docker/nginx/conf/conf.d/key.pem  \
--fullchain-file /home/docker/nginx/conf/conf.d/cert.pem 

acme.sh --install-cert -d djw0.tk -d *.djw0.tk \
--key-file       /home/docker/nginx/conf/conf.d/key.pem  \
--fullchain-file /home/docker/nginx/conf/conf.d/cert.pem 
```

```
curl https://get.acme.sh | sh

export DP_Id="390654"
export DP_Key="95c8f18944e557de589409b77ec9a622"
acme.sh  --issue --dns dns_dp -d djw0.tk -d *.djw0.tk


export CF_Key="1YkWjG-Pva5BY94Tzrifo3KLXlY1ZVNmB9F8Q0JL"
export CF_Email="epicfor1024@gmail.com"
acme.sh  --issue --dns dns_cf -d 991105.xyz -d *.991105.xyz


# domain自行替换成自己的域名
server {
    server_name xx.domain.com;
    listen 443 http2 ssl;
    ssl_certificate /path/.acme.sh/domain/fullchain.cer;
    ssl_certificate_key /path/.acme.sh/domain/domain.key;
    ssl_trusted_certificate  /path/.acme.sh/domain/ca.cer;

    location / {
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
        proxy_set_header Host $host;
        proxy_pass http://127.0.0.1:10086;
    }
}



	ssl_certificate /etc/nginx/conf.d/djw0.tk_ecc/fullchain.cer;
    ssl_certificate_key /etc/nginx/conf.d/djw0.tk_ecc/djw0.tk.key;
    ssl_trusted_certificate  /etc/nginx/conf.d/djw0.tk_ecc/ca.cer;
    
    /*.991105.xyz_ecc
    
    
    
server {
    listen 80;
    listen  [::]:80;
    listen 443 ssl;
    listen  [::]:443 ssl;

    server_name djw0.tk;
    ssl_certificate /etc/nginx/conf.d/djw0.tk_ecc/fullchain.cer;
    ssl_certificate_key /etc/nginx/conf.d/djw0.tk_ecc/djw0.tk.key;
    ssl_trusted_certificate  /etc/nginx/conf.d/djw0.tk_ecc/ca.cer;

    if ($scheme = http) {
        return 301 https://$server_name$request_uri;
    }
    
    location / {
        proxy_set_header Host $host;
        proxy_pass http://127.0.0.1:4433;
    }

}

server {
    listen 80;
    listen  [::]:80;
    listen 443 ssl;
    listen  [::]:443 ssl;

    server_name g.djw0.tk;
    ssl_certificate /etc/nginx/conf.d/*.djw0.tk_ecc/fullchain.cer;
    ssl_certificate_key /etc/nginx/conf.d/*.djw0.tk_ecc/*.djw0.tk.key;
    ssl_trusted_certificate  /etc/nginx/conf.d/*.djw0.tk_ecc/ca.cer;

    if ($scheme = http) {
        return 301 https://$server_name$request_uri;
    }
    
    location / {
        proxy_set_header Host $host;
        proxy_pass http://127.0.0.1:8080;
    }

}
```

# 模板

```
server {
    listen 80;
    listen  [::]:80;
    listen 443 ssl;
    listen  [::]:443 ssl;

    server_name f.djw0.tk;
    ssl_certificate /etc/nginx/conf.d/*.djw0.tk_ecc/fullchain.cer;
    ssl_certificate_key /etc/nginx/conf.d/*.djw0.tk_ecc/*.djw0.tk.key;
    ssl_trusted_certificate  /etc/nginx/conf.d/*.djw0.tk_ecc/ca.cer;

    if ($scheme = http) {
        return 301 https://$server_name$request_uri;
    }

    location / {
        proxy_set_header Host $host;
        proxy_pass http://127.0.0.1:2052;
    }

}

```

