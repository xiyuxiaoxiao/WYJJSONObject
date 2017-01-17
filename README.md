# WYJJSONObject
    一个用于解析json 转换模型的类
    使用：直接将WYJJSONObject 拖出 继承WYJJSONObject类即可

#优点：
        对于后台数据结构错误的时候 ，不会崩溃 
        可以将数组中的模型转化 只要重写-(NSDictionary *)classOfArrayProperty;

#例子：
```
    返回数组类型的属性与对应的模型名
    -(NSDictionary *)classOfArrayProperty {
        return @{@"student":@"StudentModel"};
    }

    创建的类：
        ClassModel:
            NSString *name
            Teacher  *teacher
            NSArray  *student
```
![Image](https://github.com/xiyuxiaoxiao/WYJJSONObject/blob/master/images/testData.png)   
