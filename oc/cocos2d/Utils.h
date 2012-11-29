//
//  Utils.h
//  Tetris
//
//  Created by ascetic85 on 11/28/12.
//  Copyright (c) 2012 ascetic85. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "cocos2d.h"

#define gUtils [Utils sharedUtils]

@interface Utils : NSObject {
@private
	NSString *m_platform;
}

+(Utils*) sharedUtils;

-(NSString*) lang;

-(NSString*) countryCode;

-(NSString*) platform;

-(NSString*) platformString;

@end
