/*-----------------------------------------------------------------------------
* This file is part of the Colony.Core Project.  The Colony.Core Project is an
* open source project with a BSD type of licensing agreement.  See the license
* agreement (license.txt) in the top/ directory or on the Internet at
* http://integerfox.com/colony.core/license.txt
*
* Copyright (c) 2014-2020  John T. Taylor
*
* Redistributions of the source code must retain the above copyright notice.
*----------------------------------------------------------------------------*/

#include "Cpl/System/Mutex.h"


//////////////////////////////////////////////////////////////////////////////
Cpl::System::Mutex::Mutex( void )
{
}


Cpl::System::Mutex::~Mutex( void )
{
}

//////////////////////////////////////////////////////////////////////////////
void Cpl::System::Mutex::lock( void )
{
    m_mutex.lock();
}


void Cpl::System::Mutex::unlock( void )
{
    m_mutex.unlock();
}




