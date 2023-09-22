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

#ifndef _TETON_PRIMITIVEWRITEPARAMS_H_
#define _TETON_PRIMITIVEWRITEPARAMS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    /// The low level access primitive for writing
    /// data to a tag
    /// </summary>
    class PrimitiveWriteParams : public PrimitiveParams
    {
      public:
        /// <summary>
        /// The memory bank to write
        /// </summary>
        enum MemoryBank MemoryBank;

        /// <summary>
        /// The offset of the first word in the memory bank to start the write
        /// </summary>
        /// <remarks>Must be greater than zero</remarks>
        int WordPointer;

        /// <summary>
        /// The write data as a hex string
        /// </summary>
        /// <remarks>The hex string mst be a multiple of 4 hex characters
        /// (16 bits). </remarks>
        string WriteData;

        /// <summary>
        /// Use block write to write the data (rather than single word write)
        /// </summary>
        bool IsBlockWriteUsed;

        /// <summary>
        /// If using block write, use a block size specified here
        /// </summary>
        /// <remarks>Currently supported values are 1 and 2 words</remarks>
        int BlockWriteWordCount;

        /// <summary>
        /// Construct a PrimitiveWriteParams instance
        /// </summary>
        PrimitiveWriteParams();

        /// <summary>
        /// Construct a PrimitiveWriteParams instance
        /// (copy constructor)
        /// </summary>
        PrimitiveWriteParams(const PrimitiveWriteParams & primitiveWriteParams);

        /// <summary>
        /// Duplicate the instance
        /// </summary>
        /// <returns>PrimitiveParams</returns>
        PrimitiveParams * Clone();
    };

}
#endif /* _TETON_PRIMITIVEWRITEPARAMS_H_ */
