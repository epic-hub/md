---
title: java-api
tags: 
	- api
	- java
categories: 
	- api
---

# 数据结构

| 类/接口       | 描述     | 方法                                                         |
| ------------- | -------- | ------------------------------------------------------------ |
| String        | 字符串   | charAt toCharArray split substring indexOf lastIndexOf replace length |
| List          | 列表     | add remove get size subList                                  |
| Stack         | 栈       | push pop peek isEmpty size                                   |
| Queue         | 队列     | offer poll peek isEmpty size                                 |
| Deque         | 双向队列 | offerFirst offerLast pollFirst pollLast peekFirst peekLast isEmpty size |
| PriorityQueue | 优先队列 | offer poll peek isEmpty size                                 |
| Set           |          | add remove contains isEmpty size first(TreeSet) last(TreeSet) |
| Map           |          | put get getOrDefault containsKey containsValue keySet values isEmpty size |



# 创建

```java
        String s;

        List<Integer> list = new ArrayList<>();

        Deque<Integer> stack = new LinkedList<>();

        Queue<Integer> queue = new LinkedList<>();

        Deque<Integer> q = new ArrayDeque<>();

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        Set<Integer> set = new HashSet<>();
        
        Map<Integer, Integer> map = new HashMap();
```

