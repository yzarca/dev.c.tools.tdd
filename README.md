# dev.c.tools.tdd

## Use Example  

``` c
#include <stdio.h>
#include <string.h>
#include "../lib/TDDunit.h"

int main(int argc, char **argv)
{   //
    int bar = 5 ;
    int foo = 7 ;
    int poo = 1 ;
    //
    char* A = "AAA" ;
    char* B = "BBB" ;
    //
    int FNs = 0 ;
    //
    ++FNs ; char* test_bar() { TDDunit_Assert( "Error: bar != 5" , bar ==  5 ) ; return NULL ; } // Pass
    ++FNs ; char* test_foo() { TDDunit_Assert( "Error: foo != 7" , foo ==  7 ) ; return NULL ; } // Pass
    ++FNs ; char* test_poo() { TDDunit_Assert( "Error: poo != 1" , poo == 10 ) ; return NULL ; } // Fail
    ++FNs ; char* test_A() { TDDunit_Assert( "Error: A != \"AAA\"" , strcmp( A , "AAA_" ) == 0 ) ; return NULL ; } // Fail
    ++FNs ; char* test_B() { TDDunit_Assert( "Error: B != \"AAA\"" , strcmp( B , "BBB"  ) == 0 ) ; return NULL ; } // Pass
    //
    TDDunit* tddu = TDDunit_New( FNs ) ;
    //
    TDDunit_AddAssert( tddu , &test_bar ) ;
    TDDunit_AddAssert( tddu , &test_foo ) ;
    TDDunit_AddAssert( tddu , &test_poo ) ;
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
./Run.TesT
```

---

## Tree  

```
.
├── Makefile
├── README.md
├── Run.TesT
├── bin
│   └── Run.TesT.a
├── lib
│   ├── TDDunit.c
│   └── TDDunit.h
├── obj
└── src
    └── TesT.c
```