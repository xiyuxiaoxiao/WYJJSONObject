//
//  SeconderVC.m
//  WYJJsonModel
//
//  Created by ZSXJ on 2017/1/16.
//  Copyright © 2017年 WYJ. All rights reserved.
//

#import "SeconderVC.h"

@interface SeconderVC ()
@property (weak, nonatomic) IBOutlet UITextView *textView;

@end

@implementation SeconderVC

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self readJson];
    
    self.textView.editable = NO;
}

-(void)readJson {
    NSString *path = [[NSBundle mainBundle] pathForResource:@"jsontext" ofType:@"json"];
    NSData *data = [NSData dataWithContentsOfFile:path];
    NSError *error;
    NSDictionary * jsonObject = [NSJSONSerialization JSONObjectWithData:data options:(NSJSONReadingAllowFragments) error:&error];
    
    NSString *str = [NSString stringWithFormat:@"%@",jsonObject];
    
    self.textView.text = str;
}

@end
