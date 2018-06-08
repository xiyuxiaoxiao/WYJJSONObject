//
//  FirstVC.m
//  WYJJsonModel
//
//  Created by ZSXJ on 2017/1/16.
//  Copyright © 2017年 WYJ. All rights reserved.
//

#import "FirstVC.h"
#import "ClassModel.h"
@interface FirstVC ()
@property (weak, nonatomic) IBOutlet UITextView *textView;

@end

@implementation FirstVC

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.textView.editable = NO;
    
    [self creatModel];
}
- (void)creatModel {

    NSString *path = [[NSBundle mainBundle] pathForResource:@"jsontext" ofType:@"json"];
    NSData *data = [NSData dataWithContentsOfFile:path];
    NSError *error;
    NSDictionary * jsonObject = [NSJSONSerialization JSONObjectWithData:data options:(NSJSONReadingAllowFragments) error:&error];
    
    NSLog(@"%@",jsonObject);
    
    ClassModel *model = [ClassModel creatWithDict:jsonObject];
    NSLog(@"%@",model);
    
    NSString *str = [NSString stringWithFormat:@"%@",model];
    self.textView.text = str;
}

@end
