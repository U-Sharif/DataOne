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

#ifndef _TETON_TAGREPORT_H_
#define _TETON_TAGREPORT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup core */
    /// <summary>
    /// This class contains information for a tag report 
    /// </summary>
    /// <remarks>
    /// Tag reports are returned through the OctaneSDK library 
    /// via the SpeedwayReader class 
    /// SpeedwayReader.QueryTagReport,
    /// SpeedwayReader.QueryTags,
    /// and indirectly through the SpeedwayReader.OnTagsReported
    /// methods.  The tag report is a wrapped array of Tags.
    /// </remarks>
    class TagReport
    {
      public:
        /// <summary> The timestamp the report was generated </summary>
        Time Timestamp;
        /// <summary> This is the value set by the application. It may be used as
        /// a back pointer to application specific data. The default is a hex
        /// string with the readers unique identity (see
        /// FeatureSet.ReaderIdentity ).
        /// </summary>
        void * ReaderIdentity;

        /// <summary> The number of tags in the report </summary>
        int nTags;
        
        /// <summary> An array of nTags Tag objects </summary>
        Tag * Tags;

        /// <summary> Default constructor </summary>
        TagReport();
        /// <summary> Copy constructor </summary>
        TagReport(const TagReport &tagReport);
        /// <summary> Default destructor </summary>
        ~TagReport();
        /// <summary> Assignment operators </summary>
        TagReport& operator=(const TagReport &tagReport);

        /// <summary> Used to set the number of available spaces
        /// in a tag report before filling in the tag report</summary>
        /// <remarks> Used when making a tag report.  This reduces
        /// the overhead by allocating the space for the reports only
        /// a single time rather than re-allocing every time a new
        /// tag is added to the report
        /// </remarks>
        /// <param name="Count"> The number of tags to pre-alloc</param>
        void NotifyTagCount(int Count);

        /// <summary> Adds a tag to a tag report </summary>
        /// <remarks> Allocates space as needed </remarks>
        /// <param name="tag">The tag to add to the report </param>
        int AddTag(Tag * tag);

      private:
        int TagCapacity;
        void copy(const TagReport &tagReport);
    };
}

#endif /* _TETON_TAGREPORT_H_ */
