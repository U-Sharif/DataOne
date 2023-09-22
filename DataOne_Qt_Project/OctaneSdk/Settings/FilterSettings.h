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

#ifndef _TETON_FILTERSETTINGS_H_
#define _TETON_FILTERSETTINGS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup settings */
    /// <summary>
    /// This class contains the settings for a single inventory
    /// filter.
    /// </summary>
    class TagFilter
    {
      public:
        /// <summary>
        /// Maximum length of TagMask string
        /// </summary>
        static const int                DimTagMask = 128;

        /// <summary>
        /// The memory bank on which the filter is applied. Filters
        /// may be configured to search for content in the Epc, Tid,
        /// and User memory banks. Filters may not match against the
        /// Reserved memory bank.
        /// </summary>
        enum MemoryBank                 MemoryBank;

        /// <summary>
        /// The bit offset in the specified memory bank at which the
        /// tag mask begins. It is important to note that this is a
        /// bit offset and need not be word or even byte-aligned.
        /// </summary>
        int                             BitPointer;

        /// <summary>
        /// The number of bits contained within the tag mask. This
        /// value is typically calculated by using the following:
        /// <c>filter.BitCount = filter.TagMask.Length * 4;</c>.
        /// However, if the desired tag mask is not nibble-aligned
        /// this value can be used to shorten the filter in a way
        /// that cannot be expressed using the tag mask hex string.
        /// </summary>
        int                             BitCount;

        /// <summary>
        /// The tag mask to apply the filter beginning at the bit
        /// offset. This string is specified in hexidecimal
        /// characters (i.e. [0-9a-fA-F]) and may be dressed or
        /// delimited by a space ( ), dot (.), dash (-), or
        /// underscore (_). The length of this string must match
        /// the bit count number of bits unless the desired mask is
        /// shortened by 1-3 bits using the bit count property. If the
        /// mask is shortened, the bits masked off this string must be
        /// set to 0.
        /// </summary>
        //char                            TagMask[DimTagMask];
        string                            TagMask;

        /// <summary>
        /// The filter operation to perform. When tags are seen and
        /// compared against the filter, the match criterion for the
        /// tag to be included in the inventory is determined by this
        /// property.
        /// </summary>
        enum TagFilterOp                FilterOp;

	/// <summary>
	/// TODO: Research what this function does.
	/// </summary>
        void Reset();

        /// <summary>
        /// Initializes a new instance of the TagFilter class.
        /// </summary>
        TagFilter();

	/// <summary>
        /// Initializes a new instance of the TagFilter class
        /// (copy constructor).
        /// </summary>
        /// <param name="tagFilter">
        /// The object instance to copy.
        /// </param>
        TagFilter(const TagFilter & tagFilter);
	
	/// <summary>
	/// Destructor for the current instance of the TagFilter class
	/// </summary>
        ~TagFilter();
    };

    /// <summary>
    /// This class contains all the filtering information for the
    /// reader. Readers support up to two individual filters that may
    /// be combined to isolate a tag population.
    /// </summary>
    /// <remarks>
    /// When the reader is scanning for tags, that scan can be
    /// optimized by the use of inventory filteres. These filters
    /// can be used to either include or exclude a specified tag
    /// population based on memory content.
    /// </remarks>
    class FilterSettings
    {
      public:
        /// <summary>
        /// Because readers support two distinct filters, those
        /// filters must be combined using logical operations. This
        /// property defines how TagFilter1 and TagFilter2 are
        /// combined.
        /// </summary>
        enum TagFilterMode              Mode;

        /// <summary>
        /// The first tag filter object.
        /// </summary>
	TagFilter                       TagFilter1;

	/// <summary>
        /// The second tag filter object.
        /// </summary>
        TagFilter                       TagFilter2;

        /// <summary>
        /// Initializes a new instance of the FilterSettings class.
        /// </summary>
        FilterSettings();
	
	/// <summary>
	/// Initializes a new instance of the FilterSettings class.
	/// (copy constructor)
	/// </summary>
        FilterSettings(const FilterSettings & filterSettings);
	
	/// <summary>
	/// Destroys the current instance of the FilterSettings class
	/// </summary>
        ~FilterSettings();
    };
}

#endif /* _TETON_FILTERSETTINGS_H_ */
