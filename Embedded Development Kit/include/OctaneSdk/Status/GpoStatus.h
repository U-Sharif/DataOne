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

#ifndef _TETON_GPOSTATUS_H_
#define _TETON_GPOSTATUS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup status */
    /// <summary>
    /// The status information for a general purpose output (GPO) port.
    /// </summary>
    class GpoStatus
    {
      public:
        /// <summary>
        /// The GPO port number, 1-8.
        /// </summary>
        /// <remarks>
        /// This is advisory so the port number is known
        /// when using foreach, or when passing a
        /// single GPO status as an argument.
        /// </remarks>
        int PortNumber;

	/// <summary>
        /// The current input level of the GPO port.
        /// </summary>
        GpioState State;

	/// <summary>
        /// Initializes a new instance of the GpoStatus class.
        /// </summary>
        GpoStatus();

	/// <summary>
        /// Initializes a new instance of the GpoStatus class (copy
        /// constructor).
        /// </summary>
        /// <param name="gpoStatus">
        /// The object instance to copy.
        /// </param>
        GpoStatus(const GpoStatus &gpoStatus);

	/// <summary>
        /// Initializes a new instance of the GpoStatus class
        /// (assignment constructor).
        /// </summary>
        /// <param name="gpoStatus">
        /// The object instance to copy.
        /// </param>
        GpoStatus& operator=(const GpoStatus &gpoStatus);
    };
}

#endif /* _TETON_GPOSTATUS_H_ */
