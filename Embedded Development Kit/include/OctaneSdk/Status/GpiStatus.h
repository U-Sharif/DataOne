/*
 *****************************************************************************
 *                                                                           *
 *                 IMPINJ CONFIDENTIAL AND PROPRIETARY                       *
 *                                                                           *
 * This source code is the sole property of Impinj, Inc.  Reproduction or    *
 * utilization of this source code in whole or in part is forbidden without  *
 * the prior written consent of Impinj, Inc.                                 *
 *                                                                           *
 * (c) Copyright Impinj, Inc. 2010. All rights reserved.                     *
 *                                                                           *
 *****************************************************************************
 */

#ifndef _TETON_GPISTATUS_H_
#define _TETON_GPISTATUS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup status */
    /// <summary>
    /// The status information for a general purpose input (GPI) port.
    /// </summary>	
    class GpiStatus
    {
      public:
	/// <summary>
        /// The antenna port number, 1-4.
        /// </summary>
        /// <remarks>
        /// This is advisory so the port number is known
        /// when using foreach, or when passing a
        /// single GPI status as an argument.
        /// </remarks>
        int PortNumber;
      
	/// <summary>
        /// The current input level of the GPI port.
        /// </summary>
        GpioState State;
        
	/// <summary>
        /// Whether the application enabled this GPI.
        /// If so the reader sends change notifications.
        /// </summary>
	bool IsEnabled;

        /// <summary>
        /// Initializes a new instance of the GpiStatus class.
        /// </summary>
        GpiStatus();

        /// <summary>
        /// Initializes a new instance of the GpiStatus class (copy
        /// constructor).
        /// </summary>
        /// <param name="gpiStatus">
        /// The object instance to copy.
        /// </param>
	GpiStatus(const GpiStatus &gpiStatus);

        /// <summary>
        /// Initializes a new instance of the GpiStatus class
        /// (assignment constructor).
        /// </summary>
        /// <param name="gpiStatus">
        /// The object instance to copy.
        /// </param>
	GpiStatus& operator=(const GpiStatus &gpiStatus);
    };
}

#endif /* _TETON_GPISTATUS_H_ */
