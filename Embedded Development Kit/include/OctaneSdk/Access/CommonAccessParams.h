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
#ifndef _TETON_COMMONACCESSPARAMS_H_
#define _TETON_COMMONACCESSPARAMS_H_
#include <string>
using namespace std;

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// This class contains all the common parameters for tag access.
    /// </summary>
    /// <remarks>
    /// Several properties required for tag access are shared between
    /// the various methods. To avoid duplicating these properties in
    /// the parameters class of each individual method, this class is
    /// used to encapsulate them. As this class should always be a
    /// base class, it is declared abstract.
    /// </remarks>
    class CommonAccessParams
    {
      public:
        /// <summary> Default Constructor </summary>
        CommonAccessParams();

        /// <summary>
        /// The tag on which the access operation is to be performed.
        /// When set to null, the operation is performed on the next
        /// tag singulated by the reader. When set to a string, the
        /// string consists of hexidecimal characters (i.e.
        /// [0-9a-fA-F]) and may optionally include 'x' or 'X' as
        /// don't-care values. The string must be word aligned, so it
        /// must be a multiple of 4 characters long. The PC-bits of
        /// target tag are inferred from the length of the string.
        /// </summary>
        string TargetTag;

        /// <summary>
        /// The antenna port on which the tag access should occur.
        /// When set to 0, all enabled antennas in the current
        /// Settings object.
        /// </summary>
        int AntennaPortNumber;

        /// <summary>
        /// The access password used to transition the tag to the
        /// secured state prior to executing the tag access. If set to
        /// null, no access password is used and the tag access will
        /// occur with the tag in the open state.
        /// </summary>
        string AccessPassword;

        /// <summary>
        /// The number of times the reader should retry the access.
        /// The reader automatically adjusts the retry mechanism based
        /// on the type of operation and type of failure. This value
        /// is merely an indication of the number of retries that
        /// should occur before failure is declared.
        /// </summary>
        int RetryCount;

        /// <summary>
        /// How long the reader should search for the target tag
        /// before timing out. The value is specified in milliseconds.
        /// </summary>
        int TimeoutInMs;

      protected:
        /// <summary>
        /// This protected routine is called from the various copy
        /// constructors to assign the common properties from one
        /// object instance to another.
        /// </summary>
        /// <param name="commonAccessParams">
        /// The object instance to copy.
        /// </param>
        void assignCommonParams(const CommonAccessParams & commonAccessParams);
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_COMMONACCESSPARAMS_H_ */
