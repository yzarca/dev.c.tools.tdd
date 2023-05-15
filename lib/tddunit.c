// File: tddunit.c

#include "tddunit.h"

static TDDUnit* TDDUnit_New( size_t ) ;
static void TDDUnit_AddAssert( TDDUnit* , FN_ASSERT ) ;
static void TDDUnit_RunAssertions( TDDUnit* ) ;
static void TDDUnit_ShowResult( TDDUnit* ) ;