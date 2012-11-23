/***********************************************************************
	filename: 	common.h
	created:	2012-11-23
	author:		ascetic85
*************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H

// MY_PROPERTY_**: u must complete the get##funName
// and set##funName(varType var)

#define MY_PROPERTY_READONLY(varType, varName, funName)\
	protected: varType varName;\
	public: virtual varType get##funName(void);

#define MY_PROPERTY_READONLY_PASS_BY_REF(varType, varName, funName)\
	protected: varType varName;\
	public: virtual const varType& get##funName(void);


#define MY_PROPERTY(varType, varName, funName)\
	protected: varType varName;\
	public: virtual varType get##funName(void);\
	public: virtual void set##funName(varType var);

#define MY_PROPERTY_PASS_BY_REF(varType, varName, funName)\
	protected: varType varName;\
	public: virtual const varType& get##funName(void);\
	public: virtual void set##funName(const varType& var);


// MY_SYNTHESIZE_**: just use it

#define MY_SYNTHESIZE_READONLY(varType, varName, funName)\
	protected: varType varName;\
	public: virtual varType get##funName(void) const { return varName; }


#define MY_SYNTHESIZE_READONLY_PASS_BY_REF(varType, varName, funName)\
	protected: varType varName;\
	public: virtual const varType& get##funName(void) const { return varName; }

#define MY_SYNTHESIZE(varType, varName, funName)\
	protected: varType varName;\
	public: virtual varType get##funName(void) const { return varName; }\
	public: virtual void set##funName(varType var){ varName = var; }

#define MY_SYNTHESIZE_PASS_BY_REF(varType, varName, funName)\
	protected: varType varName;\
	public: virtual const varType& get##funName(void) const { return varName; }\
	public: virtual void set##funName(const varType& var){ varName = var; }

#define MY_SAFE_DELETE(p)            \
	do { if(p) { delete (p); (p) = 0; } } while(0)

#define MY_SAFE_DELETE_ARRAY(p)     \
	do { if(p) { delete[] (p); (p) = 0; } } while(0)

#define MY_SAFE_FREE(p)                \
	do { if(p) { free(p); (p) = 0; } } while(0)

#define MY_SAFE_RELEASE(p)            \
	do { if(p) { (p)->release(); } } while(0)

#define MY_SAFE_RELEASE_NULL(p)        \
	do { if(p) { (p)->release(); (p) = 0; } } while(0)

#define MY_SAFE_RETAIN(p)            \
	do { if(p) { (p)->retain(); } } while(0)

#define MY_BREAK_IF(cond)            if(cond) break

#endif // _COMMON_H END
