//
//  Utils.m
//  Tetris
//
//  Created by ascetic85 on 11/28/12.
//  Copyright (c) 2012 ascetic85. All rights reserved.
//

#import "Utils.h"

@implementation Utils

+ (NSString *)lang
{
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSArray *languages = [defaults objectForKey:@"AppleLanguages"];
    return [languages objectAtIndex:0];
}

+ (NSString *)countryCode
{
    NSLocale *locale = [NSLocale currentLocale];
    NSString *countryCode = [locale objectForKey:NSLocaleCountryCode];
    return countryCode;
}

@end
