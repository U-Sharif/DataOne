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

#ifndef _TETON_SEARCHMODEENTRY_H_
#define _TETON_SEARCHMODEENTRY_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup features */
    /// <summary>
    /// Describes a single search mode that is available on the reader.
    /// </summary>	
    class SearchModeEntry
    {
      public:
        /// <summary>
        /// Initializes a new instance of the SearchModeEntry class.
        /// </summary>	      
        SearchModeEntry (void);
      
	/// <summary>
	/// Destroys the current instance of the SearchModeEntry class
	/// </summary>
        ~SearchModeEntry ();

        /// <summary>
        /// The LLRP code used to select the reader mode.
        /// Applications should not need this.
        /// </summary>      
        int                     LlrpCode;
      
        /// <summary>
        /// The reader mode as used in <see cref="Settings"/>.
        /// </summary>      
        SearchMode              Mode;

        /// <summary>
        /// The preferred description for the mode, provided
        /// for use in GUI dialogs, reports, and other
        /// human readable forms.
        /// </summary>
	const char *            Description;
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_SEARCHMODEENTRY_H_ */
