//
//  ClassModel.m
//  WYJJsonModel
//
//  Created by ZSXJ on 2017/1/16.
//  Copyright © 2017年 WYJ. All rights reserved.
//

#import "ClassModel.h"

@implementation ClassModel

-(NSDictionary *)classOfArrayProperty {
    return @{@"student":@"StudentModel"};
}

-(NSArray *)getOutArray {
    return @[@"classId"];
}
@end
