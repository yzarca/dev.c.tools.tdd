// File: tddtest.h

#include <stdio.h>
#include <string.h>
#include "../lib/TDDunit.h"


int bar = 5 ;
int foo = 7 ;
int poo = 1 ;
int snu = 8 ;
int tar = 6 ;
static char* test_bar() { TDDunit_Assert( "Error: bar != 5" , bar == 10 ) ; return NULL ; } // Fail
static char* test_foo() { TDDunit_Assert( "Error: foo != 7" , foo == 10 ) ; return NULL ; } // Fail
static char* test_poo() { TDDunit_Assert( "Error: poo != 1" , poo == 10 ) ; return NULL ; } // Fail
static char* test_snu() { TDDunit_Assert( "Error: snu != 8" , snu ==  8 ) ; return NULL ; } // Pass
static char* test_tar() { TDDunit_Assert( "Error: tar != 6" , tar ==  6 ) ; return NULL ; } // Pass
//
char* A = "AAA" ;
char* B = "BBB" ;
static char* test_A() { TDDunit_Assert( "Error: A != \"AAA\"" , strcmp( A , "AAA_" ) == 0 ) ; return NULL ; } // Fail
static char* test_B() { TDDunit_Assert( "Error: B != \"AAA\"" , strcmp( B , "BBB" ) == 0 ) ; return NULL ; } // Pass

int main(int argc, char **argv)
{   //
    TDDunit* tddu = TDDunit_New( 7 ) ;
    //
    TDDunit_AddAssert( tddu , &test_bar ) ;
    TDDunit_AddAssert( tddu , &test_foo ) ;
    TDDunit_AddAssert( tddu , &test_poo ) ;
    TDDunit_AddAssert( tddu , &test_snu ) ;
    TDDunit_AddAssert( tddu , &test_tar ) ;
    TDDunit_AddAssert( tddu , &test_A ) ;
    TDDunit_AddAssert( tddu , &test_B ) ;
    //
    TDDunit_RunAssertions( tddu ) ;
    TDDunit_ShowResult( tddu ) ;
    //
    return tddu->TestFailed != 0 ;
}   //
