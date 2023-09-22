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

#ifndef _TETON_STRING_H_
#define _TETON_STRING_H_

#define TETON_STRING_MAX_LENGTH         256

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// A simple string class for used in the OctaneSDK
    /// </summary>
    class String
    {
      public:
        /// <summary>
        /// Default constructor
        /// </summary>
        String();
        /// <summary>
        /// Copy constructor
        /// </summary>
        String(const char * string);
        /// <summary>
        /// Construct a string from a C-style format string and argument list
        /// </summary>
        /// <param name="format">sprintf style format</param>
        /// <param name="args">argument array</param>
        String(const char * format, void * args[]);
        /// <summary>
        /// Assignment operator
        /// </summary>
        String& operator=(const char * str);
        /// <summary>
        /// Maximum length of a string
        /// </summary>
        static const int MaxLength = TETON_STRING_MAX_LENGTH;
        /// <summary>
        /// Array where string is stored witin the object
        /// </summary>
        char Value[TETON_STRING_MAX_LENGTH+1];
    };
}

#endif /* _TETON_STRING_H_ */
