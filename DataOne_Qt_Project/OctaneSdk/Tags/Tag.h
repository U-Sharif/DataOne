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

#ifndef _TETON_TAG_H_
#define _TETON_TAG_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup core */
    /// <summary>
    /// This class contains information for tag reads from a single EPC
    /// </summary>
    class Tag
    {
      public:
        /// <summary> Default constructor </summary>
        Tag();
        /// <summary> Copy constructor </summary>
        Tag(const Tag & t);
        /// <summary> Assignment operator </summary>
        Tag operator=(const Tag & t);
        /// <summary> Equals operator </summary>
        bool operator==(const Tag & t);
        /// <summary> Resets tag values to defaults </summary>
        void Reset();
        /// <summary>Copy a tag into a tag reference</summary>
        void Copy(const Tag & t);

        /// <summary>
        /// Formats an ascii string version of tag information
        /// to buffer
        /// </summary>
        /// <param name="buf">buffer to write to</param>
        /// <param name="nBuf">size of buffer</param>
        /// <returns>Pointer to the buffer for use in printf</returns>
        const char *
        Formatter (
          char *                buf,
          int                   nBuf);

        /// <summary>
        /// The order (index) of the tag within the report list
        /// </summary>
        int Rank;

        /// <summary>
        /// The reader identity. See
        /// <see cref="SpeedwayReader.ReaderIdentity"/>
        /// </summary>
        void * ReaderIdentity;

        /// <summary>
        /// The Electronic Product Code (EPC) backscattered by
        /// the tag
        /// </summary>
        char Epc[Constants::MaxEpcStringLength+1];

        /// <summary>
        /// Value denoting whether an antenna port number is present in
        /// this instance
        /// </summary>
        bool IsAntennaPortNumberPresent;
        /// <summary>
        /// The antenna port number if <see cref="IsAntennaPortNumberPresent"/>
        /// is true.
        /// </summary>
        int AntennaPortNumber;

        // peak rssi
        /// <summary>
        /// Value denoting whether an peak rssi is present in the instance
        /// </summary>
        bool IsPeakRssiInDbmPresent;
        /// <summary>
        /// The largest RSSI (least negative) value represented by the
        /// tag reads conveyed in this report if
        /// <see cref="IsPeakRssiInDbmPresent"/> is true
        /// </summary>
        double PeakRssiInDbm;

        // tag seen count
        /// <summary>
        /// Value denoting whether the <see cref="SeenCount"/>
        /// attribute is valid.
        /// </summary>
        bool IsSeenCountPresent;
        /// <summary>
        /// The number of tag reads of this EPC conveyed in this
        /// tag report if <see cref="IsSeenCountPresent"/> is true
        /// </summary>
        int SeenCount;

        // serialized tid
        /// <summary>
        ///  Value denoting whether the <see cref="SerializedTid"/>
        ///  attribute is valid.
        /// </summary>
        bool IsSerializedTidPresent;
        /// <summary>
        /// The serialized TID for the EPC conveyed in this instance if
        /// <see cref="IsSerializedTidPresent"/> is true
        /// </summary>
        char SerializedTid[Constants::MaxTidStringLength+1];

        /// Value denotes whether <see cref="FirstSeenTime"/>
        /// attribute is valid
        /// </summary>
        bool IsFirstSeenTimePresent;
        /// <summary>
        /// The time of the first tag read for the EPC conveyed in
        /// this instance if <see cref="IsFirstSeenTimePresent"/> is true
        /// </summary>
        Time FirstSeenTime;

        /// <summary>
        /// Value denotes whether <see cref="LastSeenTime"/>
        /// attribute is valid
        /// </summary>
        bool IsLastSeenTimePresent;
        /// <summary>
        /// The time of the last tag read for the EPC conveyed in
        /// this instance if <see cref="IsLastSeenTimePresent"/> is true
        /// </summary>
        Time LastSeenTime;

        /// <summary>
        /// Value denotes whether <see cref="ChannelInMhz"/>
        /// attribute is valid
        /// </summary>
        bool IsChannelInMhzPresent;
        /// <summary>
        /// The channel of the tag read for the EPC conveyed in this instance
        /// if <see cref="IsChannelInMhzPresent"/>
        /// </summary>
        double ChannelInMhz;

        /// <summary>
        /// Value denotes whether <see cref="PhaseAngleInRadians"/>
        /// attribute is valild
        /// </summary>
        bool IsPhaseAngleInRadiansPresent;
        /// <summary>
        /// The RF phase angle
        /// in radians (relative to the transmit carrier) of
        /// the tag read for the EPC conveyed in this instance if
        /// <see cref="IsPhaseAngleInRadiansPresent"/>
        /// </summary>
        double PhaseAngleInRadians;
    };
}

#endif /* _TETON_TAG_H_ */
