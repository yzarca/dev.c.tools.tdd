# dev.c.tools.tdd

## Use Example  

``` c
#include <stdio.h>
#include "../lib/TDDunit.h"


int bar = 5 ;
int foo = 7 ;
int poo = 1 ;
int snu = 8 ;
int tar = 6 ;
static char* test_bar() { TDDunit_Assert( "Error: bar != 5" , bar == 10 ) ; return NULL ; }
static char* test_foo() { TDDunit_Assert( "Error: foo != 7" , foo == 10 ) ; return NULL ; }
static char* test_poo() { TDDunit_Assert( "Error: poo != 1" , poo == 10 ) ; return NULL ; }
static char* test_snu() { TDDunit_Assert( "Error: snu != 8" , snu == 10 ) ; return NULL ; }
static char* test_tar() { TDDunit_Assert( "Error: tar != 6" , tar == 10 ) ; return NULL ; }
//
char* A = "AAA" ;
char* B = "BBB" ;
static char* test_A() { TDDunit_Assert( "Error: A != \"AAA\"" , A == "AAA" ) ; return NULL ; }
static char* test_B() { TDDunit_Assert( "Error: B != \"AAA\"" , B == "BBB" ) ; return NULL ; }

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
```

## Execute Test  

``` sh
./RunTEST
```