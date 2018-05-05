//
//  multi_free.h
//
//  Created by Dmitriy Gonchar on 05.05.18.
//  Copyright © 2018 Dmitriy Gonchar. All rights reserved.
//

#ifndef multi_free_h
#define multi_free_h

#include <stdlib.h>
#include <stdarg.h>

#define FREE(...) multi_free(__VA_ARGS__, NULL);

void multi_free(void *first, ...)
{
	void *cleaned_mem = first;
	va_list aList;
	va_start(aList, first);
	do
	{
		free(cleaned_mem);
		cleaned_mem = va_arg(aList, void *);
	} while (cleaned_mem);
	va_end(aList);
}

#define free FREE

#endif /* multi_free_h */
