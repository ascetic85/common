//
//  StringMgr.h
//  Tetris
//
//  Created by ascetic85 on 11/27/12.
//  Copyright (c) 2012 ascetic85. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "cocos2d.h"

// here MUST be langes.plist

#define tr(x) [[StringMgr sharedMgr] value:x]

@interface StringMgr : NSObject
{
@private
    NSMutableDictionary *m_dict;
    NSDictionary *m_langes;
}

+(id) sharedMgr;

-(NSString*) value:(NSString*) key;

@end
