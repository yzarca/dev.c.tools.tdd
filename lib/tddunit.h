// File: TDDunit.h

#ifndef TDDUNIT_H
#define TDDUNIT_H

#define TDDunit_Assert( Message , Test )                              \
do {                                                                  \
    if ( !( Test ) ) {                                                \
        printf( "Failure :\n" ) ;                                     \
        printf( "    - %s() [ Line : %d ]\n", __func__ , __LINE__ ) ; \
        printf( "    - Message : %s\n" , Message ) ;                  \
        return Message ;                                              \
    }                                                                 \
} while ( 0 )

typedef char* ( *FN_ASSERT )()  ;
//typedef struct _tddunit TDDunit ;
typedef struct _tddunit
{   //
    int    CurAssert    ;
    int    NumAsserts   ;
    int    TestExecuted ;
    int    TestFailed   ;
    FN_ASSERT Asserts[] ;
}   TDDunit ;


TDDunit* TDDunit_New( size_t ) ;
void TDDunit_AddAssert( TDDunit* , FN_ASSERT ) ;
void TDDunit_RunAssertions( TDDunit* ) ;
void TDDunit_ShowResult( TDDunit* ) ;

#endif