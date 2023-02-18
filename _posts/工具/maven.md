---
title: maven配置
tags:
	- maven
categories:
	- 工具
---





下载地址：[官网](http://maven.apache.org/download.cgi)

```
http://maven.apache.org/download.cgi
```

## idea配置



idea使用高版本maven可能会导致失败

idea2021可以使用maven3.8以及以前的版本
idea 2020 可以使用3.6左右以及以前的版本
如果不匹配建议降低maven版本，通常maven3.6版本即可





备注：

配置阿里云镜像（在setting.xml文件中配置）

```xml
<!--  配置阿里云  -->
<mirror>
    <id>nexus-aliyun</id>
    <mirrorOf>*</mirrorOf>
    <name>Nexus aliyun</name>
    <url>http://maven.aliyun.com/nexus/content/groups/public</url>
</mirror>
```





配置默认JDK版本（在setting.xml文件中配置）

```xml
<profile>
    <id>jdk-1.8</id>
    <activation>
        <activeByDefault>true</activeByDefault>
        <jdk>1.8</jdk>
    </activation>
    <properties>
        <maven.compiler.source>1.8</maven.compiler.source>
        <maven.compiler.target>1.8</maven.compiler.target>
        <maven.compiler.compilerVersion>1.8</maven.compiler.compilerVersion>
    </properties>
</profile>
```



## maven的jar包位置

从[Maven](https://so.csdn.net/so/search?q=Maven&spm=1001.2101.3001.7020)中心仓库下载到本地的jar包的默认存放在”${user.home}/.m2/repository”中，${user.home}表示当前登录系统的用户目录(如"C:\Users\gacl")，

　　点击进入repository文件夹，

　　Jar包存放在这个位置不太好，我们希望能够自己定义下载下来的jar包的存放位置，因此我们可以自己设置下载到本地时的jar包的存放目录。
　　在“E:\”目录下创建一个“repository”文件夹，

　　找到apache-maven-3.2.3\conf目录下的settings.xml文件，

　　编辑setting.xml文件，

　　加上下面的代码，
　　<localRepository>E:/repository</localRepository>

　　这样就可以把jar包下载到我们指定的E:/repository目录中了，

　　把jar包下载到本地的好处就是，当编译时，会优先从本地的jar包去找，如果本地存在，就直接拿来用，如果不存在，就从Maven的中心仓库去下载，如下图所示：

　　第一次执行"mvn compile"和"mvn clean"这两个命令时，Maven会去中央仓库下载需要的jar包，而第二次执行这两个命令时，由于所需的jar包已经在本地的仓库中存储，所以就可以直接拿来用了，这样就省去了去中央仓库下载jar包的时间。

