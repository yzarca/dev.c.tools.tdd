// File: tddtest.h

#include <stdio.h>
#include "lib/tddunit.h"

int bar = 5 ;
int foo = 7 ;
int poo = 1 ;
int snu = 8 ;
int tar = 6 ;

static char* test_bar() { TDDU_Assert( "error, bar != 5" , bar == 10 ) ; return NULL ; }
static char* test_foo() { TDDU_Assert( "error, foo != 7" , foo == 10 ) ; return NULL ; }
static char* test_poo() { TDDU_Assert( "error, poo != 1" , poo == 10 ) ; return NULL ; }
static char* test_snu() { TDDU_Assert( "error, snu != 8" , snu == 10 ) ; return NULL ; }
static char* test_tar() { TDDU_Assert( "error, tar != 6" , tar == 10 ) ; return NULL ; }

int main(int argc, char **argv)
{   //
    TDDUnit* tddu = TDDUnit_New( 5 ) ;
    //
    TDDUnit_AddAssert( tddu , &test_bar ) ;
    TDDUnit_AddAssert( tddu , &test_foo ) ;
    TDDUnit_AddAssert( tddu , &test_poo ) ;
    TDDUnit_AddAssert( tddu , &test_snu ) ;
    TDDUnit_AddAssert( tddu , &test_tar ) ;
    //TDDUnit_AddAssert( tddu , &test_bar ) ;
    //
    TDDUnit_RunAssertions( tddu ) ;
    TDDUnit_ShowResult( tddu ) ;
    //
    return tddu->TestFailed != 0 ;
}   //