#ifndef _H_ASSERT_H_
#define _H_ASSERT_H_

#ifdef _DEBUG
#	include <assert.h>
#else
#   undef assert
#	define	assert(expression)
#endif

#endif
