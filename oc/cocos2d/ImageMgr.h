//
//  ImageMgr.h
//  Tetris
//
//  Created by ascetic85 on 11/27/12.
//  Copyright 2012 ascetic85. All rights reserved.
//

#import <Foundation/Foundation.h>

// here MUST be images.plist

#define I(x) [[ImageMgr sharedMgr] value:(x)]

@interface ImageMgr : NSObject {
@private
    NSMutableDictionary *m_dict;
}

+(id) sharedMgr;

-(NSString*) value:(NSString*) key;

@end
