# WYJJSONObject ：一个用于将json 转换模型的类
#使用：
    直接将WYJJSONObject 拖出 继承WYJJSONObject类即可
     *** 使用的时候 需要使用对象类型的属性 不能用基本类型 ***

#优点：
        对于后台数据结构错误的时候 ，不会崩溃 （例如 本该是数组 结果返回了一个字典格式）
        可以将属性为数组类型的模型转化 只要重写-(NSDictionary *)classOfArrayProperty;
        可以将属性中对象类型也全部转换

#例子：
```
    ClassModel   Teacher   StudentModel  都继承WYJJSONObject
    返回数组类型的属性与对应的模型名
    -(NSDictionary *)classOfArrayProperty {
        return @{@"student":@"StudentModel"};
    }

    ClassModel:
            NSString *name
            Teacher  *teacher
            NSArray  *student
```
![Image](https://github.com/xiyuxiaoxiao/WYJJSONObject/blob/master/images/testData.png)   
