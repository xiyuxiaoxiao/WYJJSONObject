//
//  StudentModel.h
//  WYJJsonModel
//
//  Created by ZSXJ on 2017/1/16.
//  Copyright © 2017年 WYJ. All rights reserved.
//

#import "WYJJsonObject.h"

@interface StudentModel : WYJJsonObject
@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) NSNumber *age;
@end
