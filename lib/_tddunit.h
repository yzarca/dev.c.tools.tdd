// File: tddunit.h

#ifndef TDDUNIT_H
#define TDDUNIT_H

#include <stdio.h>
#include <stdlib.h>

#define TDDU_Assert( message , test )                                 \
do {                                                                  \
    if ( !( test ) ) {                                                \
        printf( "Failure :\n" ) ;                                     \
        printf( "    - %s() [ Line : %d ]\n", __func__ , __LINE__ ) ; \
        printf( "    - Message : %s\n" , message ) ;                  \
        return message ;                                              \
    }                                                                 \
} while ( 0 )
#define TDDU_RunTest( test , tddunit ) \
do {                                   \
    char* message = test()  ;          \
    ++tddunit->TestExecuted ;          \
    if ( message ) {                   \
        ++tddunit->TestFailed ;        \
    }                                  \
} while ( 0 )

typedef char* ( *FN_ASSERT )() ;
typedef struct _tddunit
{   //
    int    CurAssert    ;
    int    NumAsserts   ;
    int    TestExecuted ;
    int    TestFailed   ;
    FN_ASSERT Asserts[] ;
}   TDDUnit ;

static TDDUnit* TDDUnit_New( size_t NumFNs )
{   //
    TDDUnit* tdd = ( TDDUnit* )malloc( sizeof( TDDUnit ) + sizeof( FN_ASSERT ) * NumFNs ) ;
    //
    if ( tdd == NULL ) {}
    //
    tdd->CurAssert    = 0 ;
    tdd->NumAsserts   = NumFNs ;
    tdd->TestExecuted = 0 ;
    tdd->TestFailed   = 0 ;
    //
    return tdd ;
}   //

static void TDDUnit_AddAssert( TDDUnit* Tunit , FN_ASSERT Fn )
{   //
    if ( Tunit->CurAssert < Tunit->NumAsserts ) {
        Tunit->Asserts[ Tunit->CurAssert++ ] = Fn ;
    } else {
        printf( "Reached the maximum number of assertions: %d\n" , Tunit->NumAsserts ) ;
    }   //
}   //

static void TDDUnit_RunAssertions( TDDUnit* Tunit )
{   //
    for ( int i = 0 ; i < Tunit->NumAsserts ; ++i ) {
        TDDU_RunTest( Tunit->Asserts[ i ] , Tunit ) ;
    }   //
}   //

static void TDDUnit_ShowResult( TDDUnit* Tunit )
{   //
    printf( "###\n" ) ;
    printf( "Tests Passed   : %d\n" , Tunit->TestExecuted - Tunit->TestFailed  ) ;
    printf( "Tests Failed   : %d\n" , Tunit->TestFailed   ) ;
    printf( "Tests Executed : %d\n" , Tunit->TestExecuted ) ;
    printf( "###\n" ) ;
    //
    if ( Tunit->TestFailed != 0 ) {
        printf( "%d TESTS FAILED\n" , Tunit->TestFailed ) ; 
    } else { 
        printf("ALL TESTS PASSED\n")  ;
    }   //
}   //

#endif