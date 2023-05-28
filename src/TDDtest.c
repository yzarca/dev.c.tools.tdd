// File: tddtest.h

#include <stdio.h>
#include "../lib/TDDunit.h"

int bar = 5 ;
int foo = 7 ;
int poo = 1 ;
int snu = 8 ;
int tar = 6 ;

static char* test_bar() { TDDunit_Assert( "error, bar != 5" , bar == 10 ) ; return NULL ; }
static char* test_foo() { TDDunit_Assert( "error, foo != 7" , foo == 10 ) ; return NULL ; }
static char* test_poo() { TDDunit_Assert( "error, poo != 1" , poo == 10 ) ; return NULL ; }
static char* test_snu() { TDDunit_Assert( "error, snu != 8" , snu == 10 ) ; return NULL ; }
static char* test_tar() { TDDunit_Assert( "error, tar != 6" , tar == 10 ) ; return NULL ; }
/*
*/
int main(int argc, char **argv)
{   //
    TDDunit* tddu = TDDunit_New( 5 ) ;
    //
    TDDunit_AddAssert( tddu , &test_bar ) ;
    TDDunit_AddAssert( tddu , &test_foo ) ;
    TDDunit_AddAssert( tddu , &test_poo ) ;
    TDDunit_AddAssert( tddu , &test_snu ) ;
    TDDunit_AddAssert( tddu , &test_tar ) ;
    //TDDUnit_AddAssert( tddu , &test_bar ) ;
    //
    TDDunit_RunAssertions( tddu ) ;
    TDDunit_ShowResult( tddu ) ;
    //
    return tddu->TestFailed != 0 ;
}   //
