//
//  Teacher.m
//  WYJJsonModel
//
//  Created by ZSXJ on 2017/1/16.
//  Copyright © 2017年 WYJ. All rights reserved.
//

#import "Teacher.h"

@implementation Teacher
-(NSString *)description {
    return [NSString stringWithFormat:@" name:%@\n sex:%@\n cource:%@\n", self.name,self.sex,self.cource];
}
@end
