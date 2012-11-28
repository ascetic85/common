//
//  macro.h
//  Tetris
//
//  Created by Xu Jun on 11/27/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef jr_macro_h
#define jr_macro_h

//#include "cocos2d.h"

// macro for cocos2d
#define gDirector       [[CCDirector  sharedDirector]

#define gEventDispatch  [[CCDirector sharedDirector] touchDispatcher]

#define gTextureCache   [CCTextureCache sharedTextureCache]

#define gFrameCache     [CCSpriteFrameCache sharedSpriteFrameCache]

#define gFileUtils      [CCFileUtils sharedFileUtils]

#define gAnimationCache [CCAnimationCache sharedAnimationCache]

#define gShader         [CCShaderCache sharedShaderCache]

#define gConfig         [CCConfiguration sharedConfiguration]


// macro for special function
#define F(x)            [gFileUtils fullPathFromRelativePath:(x)]

#endif
