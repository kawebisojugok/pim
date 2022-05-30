#ifndef Cpl_Dm_Mp_Bool_h_
#define Cpl_Dm_Mp_Bool_h_
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
/** @file */


#include "Cpl/Dm/ModelPointCommon_.h"

///
namespace Cpl {
///
namespace Dm {
///
namespace Mp {


/** This class provides a concrete implementation for a Point who's data is a
    bool.

 	The toJSON()/fromJSON format is:
	\code
	
	{ name:"<mpname>", type:"<mptypestring>", valid:true|false, seqnum:nnnn, locked:true|false, val:true|false }
	
	\endcode
	
	NOTE: All methods in this class ARE thread Safe unless explicitly
          documented otherwise.
 */
class Bool : public ModelPointCommon_
{
public:
    /// Constructor. Invalid MP. 
    Bool( Cpl::Dm::ModelDatabase& myModelBase, const char* symbolicName )
        :Cpl::Dm::ModelPointCommon_( myModelBase, symbolicName, &m_data, sizeof( m_data ), false )
    {
    }

    /// Constructor. Valid MP.  Requires an initial value
    Bool( Cpl::Dm::ModelDatabase& myModelBase, const char* symbolicName, bool initialValue )
        :Cpl::Dm::ModelPointCommon_( myModelBase, symbolicName, &m_data, sizeof( m_data ), true )
    {
        m_data = initialValue;
    }

public:
    /// Type safe read. See Cpl::Dm::ModelPoint
    inline bool read( bool& dstData, uint16_t* seqNumPtr=0 ) const noexcept
    {
        return Cpl::Dm::ModelPointCommon_::read( &dstData, sizeof( m_data ), seqNumPtr );
    }

    /// Type safe write. See Cpl::Dm::ModelPoint
    inline uint16_t write( bool newValue, LockRequest_T lockRequest = eNO_REQUEST ) noexcept
    {
        return Cpl::Dm::ModelPointCommon_::write( &newValue, sizeof( m_data ), lockRequest );
    }

    /// Updates the MP with the valid-state/data from 'src'. Note: the src.lock state is NOT copied
    inline uint16_t copyFrom( const Bool& src, LockRequest_T lockRequest = eNO_REQUEST ) noexcept
    {
        return Cpl::Dm::ModelPointCommon_::copyFrom( src, lockRequest );
    }

    ///  See Cpl::Dm::ModelPoint.
    const char* getTypeAsText() const noexcept;

public:
    /// Type safe subscriber
    typedef Cpl::Dm::Subscriber<Bool> Observer;

    /// Type safe register observer
    void attach( Observer& observer, uint16_t initialSeqNumber=SEQUENCE_NUMBER_UNKNOWN ) noexcept;

    /// Type safe un-register observer
    void detach( Observer& observer ) noexcept;

    /// See Cpl::Dm::Point.  
    bool fromJSON_( JsonVariant& src, LockRequest_T lockRequest, uint16_t& retSequenceNumber, Cpl::Text::String* errorMsg ) noexcept;


protected:
    /// See Cpl::Dm::Point.  
    void setJSONVal( JsonDocument& doc ) noexcept;


protected:
    /// My data
    bool m_data;
};



};      // end namespaces
};
};
#endif  // end header latch
