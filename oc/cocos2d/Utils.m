//
//  Utils.m
//  Tetris
//
//  Created by ascetic85 on 11/28/12.
//  Copyright (c) 2012 ascetic85. All rights reserved.
//

#import "Utils.h"

@implementation Utils

#include <sys/types.h>
#include <sys/sysctl.h>

-(id) init
{
	if ((self = [super init])) {
	}
	return self;
}

-(void) dealloc
{
	[m_platform release];
	[super release];
}

+ (Utils*) sharedUtils
{
	static Utils *util = NULL;
	if (!util)
	  util = [[Utils alloc] init];
	return util;
}

- (NSString *)lang
{
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSArray *languages = [defaults objectForKey:@"AppleLanguages"];
    return [languages objectAtIndex:0];
}

- (NSString *)countryCode
{
    NSLocale *locale = [NSLocale currentLocale];
    NSString *countryCode = [locale objectForKey:NSLocaleCountryCode];
    return countryCode;
}

// www.diwublog.com/archives/119
- (NSString*) platform
{
    size_t size;
    
    sysctlbyname("hw.machine", NULL, &size, NULL, 0);
    char *machine = malloc(size);
    
    sysctlbyname("hw.machine", machine, &size, NULL, 0);
    NSString *platform = [NSString stringWithUTF8String:machine];
    
    free(machine);
    
    return platform;
}

// www.diwublog.com/archives/209
- (NSString*) platformString
{
    NSString *platform = [Utils platform];
    
//    NSLog(@"The platform is %@", platform);
    
    if ([platform isEqualToString:@"iPhone1,1"])    return @"iPhone 1G";
    
    if ([platform isEqualToString:@"iPhone1,2"])    return @"iPhone 3G";
    
    if ([platform isEqualToString:@"iPhone2,1"])    return @"iPhone 3GS";
    
    if ([platform isEqualToString:@"iPhone3,1"])    return @"iPhone 4";
    
    if ([platform isEqualToString:@"iPhone3,2"])    return @"iPhone 4"; // Verizon
    
    if ([platform isEqualToString:@"iPod1,1"])      return @"iPod Touch 1G";
    
    if ([platform isEqualToString:@"iPod2,1"])      return @"iPod Touch 2G";
    
    if ([platform isEqualToString:@"iPod3,1"])      return @"iPod Touch 3G";
    
    if ([platform isEqualToString:@"iPod4,1"])      return @"iPod Touch 4G";
    
    if ([platform isEqualToString:@"iPad1,1"])      return @"iPad";
    
    if ([platform isEqualToString:@"iPad2,1"])      return @"iPad 2";   // Wifi
    
    if ([platform isEqualToString:@"iPad2,2"])      return @"iPad 2";   // GSM
    
    if ([platform isEqualToString:@"iPad2,3"])      return @"iPad 2";   // CDMA
    
    if ([platform isEqualToString:@"i386"])         return @"Simulator";
    
    return platform;
    
}

@end
