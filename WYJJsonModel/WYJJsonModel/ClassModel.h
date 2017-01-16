//
//  ClassModel.h
//  WYJJsonModel
//
//  Created by ZSXJ on 2017/1/16.
//  Copyright © 2017年 WYJ. All rights reserved.
//

#import "WYJJsonObject.h"
#import "StudentModel.h"
#import "Teacher.h"
@interface ClassModel : WYJJsonObject
@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) NSArray *student;
@property (nonatomic, strong) Teacher *teacher;

@property (nonatomic, assign) NSNumber *classId;

@end
