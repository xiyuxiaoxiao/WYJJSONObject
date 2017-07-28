//
//  NullOptimizationScheme.h
//  WYJJsonModel
//
//  Created by ZSXJ on 2017/7/17.
//  Copyright © 2017年 WYJ. All rights reserved.
//


/*
 
 NSNull 优化方案   主要推荐 4，5 （4需要强制指定类型）
 ios解决有关null闪退及json解析数据中null的问题
 http://blog.csdn.net/yidu_blog/article/details/52410823
 
 
 
 1、最开始的解决方法就是为了应付当前遇到的崩溃，看看哪个字段可能为空，那么就对该字段使用前进行判断，通过崩溃时的错误提示可以看出，这样的字段解析成的对象是 NSNull 类型的，所以可以直接判断是不是此类型：
 
 if (![isKindOfClass:[NSNull class]]){xxxxxxx;}
 因为字段实在太多，就找一个补一个。
 
 =================================================================================
 
 2、后来想彻底解决这问题，就打算从数据源下手，其实应该可以用正则表达式匹配这个null ，然后进行替换，奈何正则是我的硬伤啊。于是就相出了一个山寨方法：字符串匹配。在获取到服务器返回的Json时，返回结果时string对象，于是就先替换 null 为 为空字符””，然后再解析。
 
 json = [jsonStr  stringByReplacingOccurrencesOfString:@":null" withString:@":\"\""];
 这个方法本来很奏效，但是我这里的服务器返回极不简洁，各种垃圾数据（不吐槽这了）。。。反正这样会导致json无法解析了。
 
 =================================================================================
 
 3、最后没有办法，只能在解析的时候下手，把是NSNull 类型的值替换成nil。 一般就写个tool方法，然后解析时调用。但是嫌太麻烦，就想弄写个宏，通过搜索惊奇的发现宏也是可以有返回值的，结果如下：
 
 #define VerifyValue(value)\
 ({id tmp;\
 if ([value isKindOfClass:[NSNull class]])\
 tmp = nil;\
 else\
 tmp = value;\
 tmp;\
 })\
 宏里的最后一句语句便是返回值。然后在解析数据时调用宏：
 
 =================================================================================
 
 4、如果你使用AFNetwork 这个库做网络请求的话，可以用以下代码，自动帮你去掉这个讨厌的空值
 
 如果你使用的类是AFHTTPSessionManager那么有：
 
 AFHTTPSessionManager *manager = [[AFHTTPSessionManager alloc]initWithBaseURL:url sessionConfiguration:config];
 AFJSONResponseSerializer *serializer = [AFJSONResponseSerializer serializer];
 [serializer setRemovesKeysWithNullValues:YES];
 [manager setResponseSerializer:serializer];
 
 
 AFHTTPRequestOperation：
 AFHTTPRequestOperation *op = [[AFHTTPRequestOperation alloc] initWithRequest:request];
 AFJSONResponseSerializer *serializer = [AFJSONResponseSerializer serializer];
 serializer.removesKeysWithNullValues = YES;
 op.responseSerializer = serializer;
 
 =================================================================================
 
 5、终极方案
 终于找到了一劳永逸的方案，牛逼的老外写了一个Category，叫做NullSafe ，在运行时操作，把这个讨厌的空值置为nil，而nil是安全的，可以向nil对象发送任何message而不会奔溃。这个category使用起来非常方便，只要加入到了工程中就可以了，你其他的什么都不用做，对，就是这么简单。详细的请去Github上查看；
 https://github.com/nicklockwood/NullSafe
 
 
 */
