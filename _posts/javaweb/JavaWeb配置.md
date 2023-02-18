---
title: JavaWeb配置
tags: 
	- JavaWeb
categories: 
	- web
---

# 项目目录分析

JavaWeb

```
--.idea:idea的项目系统文件
--out是当前项目执行之后生成的一个缓存文件夹，里面存放的是项目的字节码文件
--src:存放java代码的地方
--Web:存放前端文件(Html css jsp)
	--WEB-INF:项目的配置文件
		--web.xml:里面能够设置servlet的版本,设置当前项目的版本,程序默认的启动页面等
	--index.jsp:是一个默认的前端启动页面

```



# 概念

## javaweb学习之前的前置知识:

* java基础语法

* 面向对象

* 数据库和数据库变成

* web前端

* java高级

## JavaWeb开发环境:

* 安装jdk

* idea编程软件

* mysql数据库

* web容器(web服务器)

## 服务器  

Web服务器之Tomcat

http服务器和web服务器

http服务器(静态资源)

http服务器一般只提供静态资源访问的能力(比如:CDN),不提供对于程序的解析,转换等处理。典型的http服务器：

Nginx

Apache

lamp = linux + apache + mysql + php

web服务器(动态资源)

web容器称之为web服务器,提供了对于web应用程序(javaWeb)的运行环境,内部能够对一些特殊的网页模板(jsp)进行解析,编译等操作,提供了动态资源的访问能力,典型的web服务器:

* Tomcat

* JBOSS

* WebLogic

* Jetty
  

## JavaWeb技术
javaweb是一个庞大的知识体系,内部综合了各项web开发相关的技术,常见的有以下:

Servlet:服务端小程序

jsp:动态网页

JSTL/EL表达式:表达式语言

Fileter:过滤器

Listener:监听器

WebSocket:服务端消息主动推送技术

MVC:软件架构方式
