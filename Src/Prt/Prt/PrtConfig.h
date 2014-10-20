/**
* \file PrtConfig.h
* \brief Defines available runtime configurations.
* The runtime can be configured to compile on different platforms
* and with different concurrency models.

*/

#ifndef PRTCONFIG_H
#define PRTCONFIG_H


#ifndef PRT_DEBUG
/**
* Expands to PrtAssert if PRT_DEBUG is defined.
*/
#define PRT_DBG_ASSERT(condition, message) 

/**
* Marks the beginning of a region of code that may allocate memory,
* but will deallocate all such memory by the end of the region.
* @see PRT_DBG_END_MEM_BALANCED_REGION
*/
#define PRT_DBG_START_MEM_BALANCED_REGION

/**
* Marks the end of a region of code that may have allocated memory,
* but must have deallocate all such memory be now. An exception is thrown
* if memory was not returned to the starting state.
* @see PRT_DBG_START_MEM_BALANCED_REGION
*/
#define PRT_DBG_END_MEM_BALANCED_REGION
#endif

#if defined(PRT_PLAT_WINUSER)
#include "PrtWinUser.h"
#elif defined(PRT_PLAT_WINKMDF)
#include "PrtWinKMDF.h"
#elif defined(PRT_PLAT_WINDIST)
#include "PrtWinDist.h"
#else
#error An invalid platform was specified (see PrtConfig.h for details)
#endif

#endif