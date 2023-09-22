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

#ifndef _TETON_SEARCHMODE_H_
#define _TETON_SEARCHMODE_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// Control how the reader selects tags.
    /// </summary>
    /// <remarks>
    /// The search mode controls whether the reader tries
    /// to singulate tags repeatedly or just once.
    /// On a per-session basis each tag has an A/B state.
    /// Sessions have different persistance of the A/B state
    /// ranging from a fraction of a second to tens of seconds.
    /// Sometimes applications need to singulate each tag just
    /// once, and sometimes applications need to repeatedly
    /// singulate tags.
    /// </remarks>
    /// <seealso cref="Settings.SearchMode"/>
    enum SearchMode
    {
        /// <summary>
        /// The reader selects the search mode
        /// based on the session.
        /// </summary>
        SearchMode_ReaderSelected,
        /// <summary>
        /// The reader selects tags in the A state and
        /// moves them to the B state.
        /// Once there are no more tags found in the A
        /// state the reader selects tags in the B state
        /// and moves them to the A state.
        /// Once there are no more tags found in the B
        /// state, the reader starts over selecting tags
        /// in the A state.
        /// Use this search mode when the application needs
        /// accurate information about when tags both
        /// enter and leave the field of view.
        /// </summary>
        SearchMode_DualTarget,
        /// <summary>
        /// The reader selects tags in the A state and
        /// moves them to the B state.
        /// It never selects tags in the B state, though
        /// due to session persistance a tag might "fall back"
        /// to the A state.
        /// Use this search mode when a great many tags
        /// will continuosly pass through the field of view.
        /// </summary>
        SearchMode_SingleTarget,
        /// <summary>
        /// The reader selects tags in the A state and
        /// moves them to the B state.
        /// It never selects tags in the B state, though
        /// due to session persistance a tag might "fall back"
        /// to the A state.
        /// This search mode mitigates how many tags "fall back".
        /// Use this search mode when a great many tags
        /// will continuosly and quickly pass through
        /// the field of view.
        /// </summary>
        SearchMode_SingleTargetWithSuppression,
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    SearchModeEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
    extern const char *
    SearchModeToString (
      SearchMode                    value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TrySearchModeFromString (
      char *                        str,
      SearchMode *                  outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsSearchModeValid (
      SearchMode                    value);

} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_SEARCHMODE_H_ */
