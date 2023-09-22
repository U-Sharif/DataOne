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

#ifndef _TETON_CONSTATNTS_H_
#define _TETON_CONSTATNTS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup core */
    /// <summary>
    /// Fixed OctaneSDK constants
    /// </summary>
    /// <remarks>
    /// This class contains fixed OctaneSDK constants for use by the 
    /// application.
    /// </remarks>
    class Constants
    {
      public:
        /// <summary> 
        /// The version of the OctaneSDK library as a C-String 
        /// </summary>
        static const char * Version;

        /// <summary> 
        /// the minimum antenna number supported by the OctaneSDK library 
        /// </summary>
        /// <remarks>
        /// See the SpeedwayReader SpeedwayReader.QueryFeatureSet method
        /// to obtain the actual number of antenna ports supported by the reader
        /// </remarks>
        static const int MinAntennaPortNumber = 1;
        /// <summary> 
        /// the maximum antenna number supported by the OctaneSDK library 
        /// </summary>
        /// <remarks>
        ///  See the SpeedwayReader SpeedwayReader.QueryFeatureSet method
        /// to obtain the actual number of antenna ports supported by the reader
        /// </remarks>
        static const int MaxAntennaPortNumber = 4;

        /// <summary> 
        /// the minimum GPI port number supported by the OctaneSDK library 
        /// </summary>
        /// <remarks>
        /// See the SpeedwayReader SpeedwayReader.QueryFeatureSet method
        /// to obtain the actual number of GPI ports supported by the reader 
        /// </remarks>
        static const int MinGpiPortNumber = 1;
        /// <summary> 
        /// the maximum GPI port number supported by the OctaneSDK library 
        /// </summary>
        /// <remarks>
        /// See the SpeedwayReader SpeedwayReader.QueryFeatureSet method
        /// to obtain the actual number of GPI ports supported by the reader 
        /// </remarks>
        static const int MaxGpiPortNumber = 4;
   
        /// <summary> 
        /// The default debounce time for GPI ports on the reader.
        /// This is only the default.  The value can be adjusted using
        /// the GpiSettings class. 
        /// </summary>
        static const int DefaultGpiDebounceInMs = 20;

        /// <summary> 
        /// the minimum GPO port number supported by the OctaneSDK library 
        /// </summary>
        /// <remarks>
        /// See the SpeedwayReader SpeedwayReader.QueryFeatureSet method
        /// to obtain the actual number of GPO ports supported by the reader 
        /// </remarks>
        static const int MinGpoPortNumber = 1;
        /// <summary> 
        /// the minimum GPO port number supported by the OctaneSDK library. 
        /// </summary>
        /// <remarks>
        /// See the SpeedwayReader SpeedwayReader.QueryFeatureSet method
        /// to obtain the actual number of GPO ports supported by the reader
        /// </remarks>
        static const int MaxGpoPortNumber = 8;

        /// <summary> 
        /// The ROSpecID of the underlying LLRP ROSpec used by OctaneSDK
        /// </summary>
        /// <remarks>
        /// This constant me be useful for debugging purposes.  With this
        /// ID, you can examine the detailed LLRP ROSpec on the reader 
        /// </remarks>
        static const int ROSpecID     = 101;

        /// <summary> 
        /// The AccessSpecID of the underlying LLRP AcecssSpec used by OctaneSDK
        /// </summary>
        /// <remarks>
        /// This constant me be useful for debugging purposes.  With this
        /// ID, you can examine the detailed LLRP AccessSpec on the reader 
        /// </remarks>
        static const int AccessSpecID = 1000;
        /// <summary> 
        /// The maximum allowable retryCount for the CommonAccessParams class
        /// RetryCount property 
        /// </summary>
        static const int MaxRetryCount = 10;
        /// <summary> 
        /// The minimum allowable timeout for the CommonAccessParams class
        /// TimeoutInMs property 
        /// </summary>
        static const int MinTimeoutInMs = 100;
        /// <summary> 
        /// The maximum allowable timeout for the CommonAccessParams class
        /// TimeoutInMs property 
        /// </summary>
        static const int MaxTimeoutInMs = 60000;
        /// <summary> 
        /// The maximum allowable WordCount in the ReadTidMemoryParams and
        /// ReadUserMemoryParams classes WordCount property
        /// </summary>
        static const int MaxReadWordCount  = 32;
        /// <summary> 
        /// The maximum allowable WordCount in the ReadTidMemoryParams and
        /// ReadUserMemoryParams classes WordCount property
        /// </summary>
        static const int MaxWriteWordCount = 32;
        /// <summary> 
        /// maximum size of EPC handled by library in 16-bit words. 
        /// e.g. 31 words is 31*16 = 496 bits 
        /// </summary>
        static const int MaxEpcWordCount   = 31; 
        /// <summary> 
        /// The maximum allowable WordCount in the 
        /// PrimitiveGetBlockPermalockParams class 
        /// </summary>
        static const int MaxBlockPermalockWordCount = 1;

        /// <summary> 
        /// max ECP string length. 
        /// allow 64 bytes, 32 16-bit words
        /// </summary>
        static const int MaxEpcStringLength = 128;

        /// <summary> 
        /// max TID string length. 
        /// </summary>
        static const int MaxTidStringLength = 128;

        /// <summary> 
        /// allow 64 bytes, 32 16-bit words
        /// </summary>
        static const int TagFilterMaskSizeInBytes = 128;

        /// <summary> 
        /// initial capacity in Tag ports,  tmp hack. need better solution
        /// </summary>
        static const int InitTagCapacity = 256;

        /// <summary> 
        /// unused -- can be ignored 
        /// </summary>
        static const int ReaderIdentityStringLength = 4;

    };
}

#endif /* _TETON_CONSTATNTS_H_ */
