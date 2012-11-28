//
//  StringMgr.m
//  Tetris
//
//  Created by ascetic85 on 11/27/12.
//  Copyright (c) 2012 ascetic85. All rights reserved.
//

#import "StringMgr.h"
#import "macro.h"

@implementation StringMgr

+(id) sharedMgr
{
    static StringMgr *mgr = nil;
    
    if (!mgr) {
        mgr = [[StringMgr alloc] init];
    }
    return mgr;
}


-(id) init
{
    if ((self = [super init])) {
        m_langes = [NSDictionary dictionaryWithContentsOfFile:F(@"langes.plist")];
        
        // set the language
        //        NSLocale *locale = [NSLocale currentLocale];
        //        NSString *countryCode = [locale objectForKey:NSLocaleCountryCode];
        
        NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
        NSArray *languages = [defaults objectForKey:@"AppleLanguages"];
        NSString *lang = [m_langes valueForKey:[languages objectAtIndex:0]];

        m_dict = [[NSDictionary dictionaryWithContentsOfFile:F(lang)] retain];
        assert(m_dict);
    }
    return self;
}

-(void) dealloc
{
    [m_dict release];
    [super dealloc];
}

//////

-(NSString*) value:(NSString *)key
{
    if (m_dict) {
        return [m_dict valueForKey:key];
    }
    
    return nil;
}

@end
