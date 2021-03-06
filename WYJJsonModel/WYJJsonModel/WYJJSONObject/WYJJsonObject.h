//
//  WYJJsonObject.h
//  OmniChannelClient
//
//  Created by ZSXJ on 2017/1/16.
//  Copyright © 2017年 ZSXJ. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WYJJsonObject : NSObject

+(instancetype)creatWithDict:(NSDictionary *)dict;
-(void)creatWithDict:(NSDictionary *)dict;

//不解析的属性
-(NSArray *)getOutArray;
//表明当前属性是数组的里面的类型
-(NSDictionary *)classOfArrayProperty;
//返回 属性名在服务器对应的字段  用于在属性名与后台无法一致的时候
-(NSDictionary *)propertyNameMacthServer;
@end
