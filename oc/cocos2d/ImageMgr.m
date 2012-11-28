//
//  ImageMgr.m
//  Tetris
//
//  Created by ascetic85 on 11/27/12.
//  Copyright 2012 ascetic85. All rights reserved.
//

#import "ImageMgr.h"
#import "macro.h"
#import "cocos2d.h"

@implementation ImageMgr

+(id) sharedMgr
{
    static ImageMgr *mgr = nil;
    if (!mgr) {
        mgr = [[ImageMgr alloc] init];
    }
    return mgr;
}

-(id) init
{
    if ((self = [super init])) {
        m_dict = [NSMutableDictionary dictionaryWithContentsOfFile:F(@"images.plist")];
        [m_dict retain];
    }
    return self;
}

-(void) setImagePlist:(NSString *)plist
{
    if (m_dict) {
        [m_dict release];
        m_dict = nil;
    }
    
    m_dict = [[NSMutableDictionary dictionaryWithContentsOfFile:F(plist)] retain];
}

-(NSString*) value:(NSString *)key
{
    if (m_dict) {
        return [m_dict valueForKey:key];
    }
    return nil;
}

-(void) dealloc
{
    [m_dict release];
    [super dealloc];
}

@end
