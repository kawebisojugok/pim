#ifndef Cpl_TShell_Cmd_Win32_Threads_h
#define Cpl_TShell_Cmd_Win32_Threads_h
/*-----------------------------------------------------------------------------
* This file is part of the Colony.Core Project.  The Colony.Core Project is an
* open source project with a BSD type of licensing agreement.  See the license
* agreement (license.txt) in the top/ directory or on the Internet at
* http://integerfox.com/colony.core/license.txt
*
* Copyright (c) 2014-2022  John T. Taylor
*
* Redistributions of the source code must retain the above copyright notice.
*----------------------------------------------------------------------------*/
/** @file */


#include "Cpl/TShell/Cmd/Threads.h"


///
namespace Cpl {
///
namespace TShell {
///
namespace Cmd {
///
namespace Win32 {



/** This class implements a TShell command
 */
class Threads : public Cpl::TShell::Cmd::Threads
{
public:
	/// Constructor
	Threads( Cpl::Container::Map<Cpl::TShell::Command>& commandList,
			 Security::Permission_T                     minPermLevel=OPTION_TSHELL_CMD_COMMAND_DEFAULT_PERMISSION_LEVEL ) noexcept;


protected:
	/// See Cpl::TShell::Cmd::Threads
	void hookHeader1( Cpl::Text::String& text );

	/// See Cpl::TShell::Cmd::Threads
	void hookHeader2( Cpl::Text::String& text );

	/// See Cpl::TShell::Cmd::Threads
	void hookThreadEntry( Cpl::Text::String& text, Cpl::System::Thread& currentThread );


};

};      // end namespaces
};
};
};
#endif  // end header latch
