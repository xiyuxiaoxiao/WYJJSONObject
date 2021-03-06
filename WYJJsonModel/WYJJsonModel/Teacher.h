//
//  Teacher.h
//  WYJJsonModel
//
//  Created by ZSXJ on 2017/1/16.
//  Copyright © 2017年 WYJ. All rights reserved.
//

#import "WYJJsonObject.h"
@class ClassModel;
@interface Teacher : WYJJsonObject
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *sex;
@property (nonatomic, copy) NSString *cource;
@property (nonatomic, strong) ClassModel *classM;
@end
