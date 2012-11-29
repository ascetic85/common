//
//  macro.h
//  Tetris
//
//  Created by ascetic85 on 11/27/12.
//  Copyright (c) 2012 ascetic85. All rights reserved.
//

#ifndef jr_macro_h
#define jr_macro_h

//#include "cocos2d.h"

// macro for cocos2d
#define gDirector       [CCDirector  sharedDirector]

#define gEventDispatch  [[CCDirector sharedDirector] touchDispatcher]

#define gTextureCache   [CCTextureCache sharedTextureCache]

#define gFrameCache     [CCSpriteFrameCache sharedSpriteFrameCache]

#define gFileUtils      [CCFileUtils sharedFileUtils]

#define gAnimationCache [CCAnimationCache sharedAnimationCache]

#define gShader         [CCShaderCache sharedShaderCache]

#define gConfig         [CCConfiguration sharedConfiguration]


// macro for special function
#define F(x)            [gFileUtils fullPathFromRelativePath:(x)]

static inline ccVertex3F
ccVertex3FMaker(GLfloat x, GLfloat y, GLfloat z)
{
	ccVertex3F v = {x,y,z};
	return v;
}
#define vertex3(x,y,z) ccVertex3FMaker((x), (y), (z))

static inline ccVertex2F
ccVertex2FMaker(GLfloat x, GLfloat y, GLfloat z)
{
	ccVertex2F v = {x, y};
	return v;
}
#define vertex2(x,y) ccVertex2FMaker((x), (y))

#endif
