//
//  StudentModel.m
//  WYJJsonModel
//
//  Created by ZSXJ on 2017/1/16.
//  Copyright © 2017年 WYJ. All rights reserved.
//

#import "StudentModel.h"

@implementation StudentModel
-(NSString *)description {
    return [NSString stringWithFormat:@"name:%@ -- age:%@", self.name,self.age];
}
@end
