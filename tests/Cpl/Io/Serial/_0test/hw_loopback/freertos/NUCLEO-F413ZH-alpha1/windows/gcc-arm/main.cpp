#include "Bsp/Api.h"
#include "Bsp/ST/NUCLEO-F413ZH/alpha1/console/Output.h"
#include "Cpl/System/Api.h"
#include "Cpl/System/Trace.h"
#include "Cpl/Io/Null.h"


extern void loopback_test( Cpl::Io::InputOutput& fd );

/*-----------------------------------------------------------*/
int main( void )
{
    // Initialize the board
    Bsp_Api_initialize();

    // Initialize CPL
    Cpl::System::Api::initialize();

    // Go run the test(s) (Note: This method should never return)
    loopback_test( g_bspConsoleStream );

    // I should never get here!
    for ( ;; );
    return 0;
}



/*-----------------------------------------------------------*/
/// Trace output
static Cpl::Io::Null nullfd_;

Cpl::Io::Output* Cpl::System::Trace::getDefaultOutputStream_( void ) throw()
{
    return &nullfd_;
}
