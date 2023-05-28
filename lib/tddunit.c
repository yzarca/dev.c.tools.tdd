// File: TDDunit.c

#include <stdio.h>
#include <stdlib.h>
#include "TDDunit.h"

TDDunit* TDDunit_New( size_t NumFNs )
{   //
    TDDunit* tdd = ( TDDunit* )malloc( sizeof( TDDunit ) + sizeof( FN_ASSERT ) * NumFNs ) ;
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

void TDDunit_AddAssert( TDDunit* Tunit , FN_ASSERT Fn )
{   //
    if ( Tunit->CurAssert < Tunit->NumAsserts )
    {   //
        Tunit->Asserts[ Tunit->CurAssert++ ] = Fn ;
    }   //
    else 
    {   //
        printf( "Reached the maximum number of assertions: %d\n" , Tunit->NumAsserts ) ;
    }   //
}   //

void TDDunit_RunAssertion( FN_ASSERT Assertion , TDDunit* Tunit ) \
{   //
    char* message = Assertion() ;
    ++Tunit->TestExecuted ;
    if ( message )
    {   //
        ++Tunit->TestFailed ;
    }   //
}   //

void TDDunit_RunAssertions( TDDunit* Tunit )
{   //
    for ( int i = 0 ; i < Tunit->NumAsserts ; ++i ) 
    {   //
        //TDDunit_RunTest( Tunit->Asserts[ i ] , Tunit ) ;
        TDDunit_RunAssertion( Tunit->Asserts[ i ] , Tunit ) ;
    }   //
}   //

void TDDunit_ShowResult( TDDunit* Tunit )
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

