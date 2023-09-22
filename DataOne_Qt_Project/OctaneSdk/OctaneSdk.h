
// NULL, memset
#include <string.h>
#include <stdexcept>

/* Constats */
#include "Constants.h"

/* Platform */
#include "Platform/Time.h"
#include "Platform/String.h"
#include "Platform/Thread.h"
#include "Platform/Lock.h"

/* Enums */
#include "Enums/EnumString.h"
#include "Enums/AccessResult.h"
#include "Enums/AntennaConnectionState.h"
#include "Enums/ApplicationConnectionState.h"
#include "Enums/AutoStartMode.h"
#include "Enums/AutoStopMode.h"
#include "Enums/GpioState.h"
#include "Enums/LockType.h"
#include "Enums/LogLevel.h"
#include "Enums/LogOrigin.h"
#include "Enums/MemoryBank.h"
#include "Enums/OperationalState.h"
#include "Enums/QtAccessRange.h"
#include "Enums/QtDataProfile.h"
#include "Enums/QtPersistence.h"
#include "Enums/ReaderMode.h"
#include "Enums/ReportMode.h"
#include "Enums/SearchMode.h"
#include "Enums/StatusRefresh.h"
#include "Enums/TagFilterMode.h"
#include "Enums/TagFilterOp.h"

/* Tags */
#include "Tags/Tag.h"
#include "Tags/TagReport.h"

/* Access */
#include "Access/PrimitiveParams.h"
#include "Access/PrimitiveResult.h"
#include "Access/CommonAccessParams.h"
#include "Access/CommonAccessResult.h"
#include "Access/PrimitiveGetBlockPermalockParams.h"
#include "Access/PrimitiveGetBlockPermalockResult.h"
#include "Access/PrimitiveGetQtConfigParams.h"
#include "Access/PrimitiveGetQtConfigResult.h"
#include "Access/PrimitiveKillParams.h"
#include "Access/PrimitiveKillResult.h"
#include "Access/PrimitiveLockParams.h"
#include "Access/PrimitiveLockResult.h"
#include "Access/PrimitiveReadParams.h"
#include "Access/PrimitiveReadResult.h"
#include "Access/PrimitiveSetBlockPermalockParams.h"
#include "Access/PrimitiveSetBlockPermalockResult.h"
#include "Access/PrimitiveSetQtConfigParams.h"
#include "Access/PrimitiveSetQtConfigResult.h"
#include "Access/PrimitiveWriteParams.h"
#include "Access/PrimitiveWriteResult.h"
#include "Access/ProgramEpcParams.h"
#include "Access/ProgramEpcResult.h"
#include "Access/ProgramAccessPasswordParams.h"
#include "Access/ProgramAccessPasswordResult.h"
#include "Access/ProgramKillPasswordParams.h"
#include "Access/ProgramKillPasswordResult.h"
#include "Access/ProgramUserBlockParams.h"
#include "Access/ProgramUserBlockResult.h"
#include "Access/ProgramUserMemoryParams.h"
#include "Access/KillTagParams.h"
#include "Access/KillTagResult.h"
#include "Access/LockTagParams.h"
#include "Access/LockTagResult.h"
#include "Access/ProgramUserMemoryResult.h"
#include "Access/ReadAccessPasswordParams.h"
#include "Access/ReadAccessPasswordResult.h"
#include "Access/ReadKillPasswordParams.h"
#include "Access/ReadKillPasswordResult.h"
#include "Access/ReadTidMemoryParams.h"
#include "Access/ReadTidMemoryResult.h"
#include "Access/ReadUserMemoryParams.h"
#include "Access/ReadUserMemoryResult.h"
#include "Access/RunPrimitiveSequenceParams.h"
#include "Access/RunPrimitiveSequenceResult.h"

/* Log */
#include "Log/LogEntry.h"

/* Settings
 * precedes FeatureSet because FeatureSet contains FactorySettings */
#include "Settings/AntennaSettings.h"
#include "Settings/AutoStartSettings.h"
#include "Settings/AutoStopSettings.h"
#include "Settings/FilterSettings.h"
#include "Settings/GpiSettings.h"
#include "Settings/KeepAliveSettings.h"
#include "Settings/LowDutyCycleSettings.h"
#include "Settings/ReportSettings.h"
#include "Settings/LowDutyCycleSettings.h"
#include "Settings/ListOfAntennaSettings.h"
#include "Settings/ListOfGpiSettings.h"
#include "Settings/Settings.h"

/* Features */
#include "FeatureSet/ReaderModeEntry.h"
#include "FeatureSet/ReaderModeFeatures.h"
#include "FeatureSet/RxSensitivityEntry.h"
#include "FeatureSet/RxSensitivityFeatures.h"
#include "FeatureSet/SearchModeEntry.h"
#include "FeatureSet/SearchModeFeatures.h"
#include "FeatureSet/TxFrequencyEntry.h"
#include "FeatureSet/TxFrequencyFeatures.h"
#include "FeatureSet/TxPowerEntry.h"
#include "FeatureSet/TxPowerFeatures.h"
#include "FeatureSet/FeatureSet.h"

/* Status */
#include "Status/AntennaStatus.h"
#include "Status/GpiStatus.h"
#include "Status/GpoStatus.h"
#include "Status/ListOfAntennaStatus.h"
#include "Status/ListOfGpiStatus.h"
#include "Status/ListOfGpoStatus.h"
#include "Status/Status.h"

/* Events  */
#include "Events/AntennaChangedEvent.h"
#include "Events/ConnectionAttemptedEvent.h"
#include "Events/ConnectionChangedEvent.h"
#include "Events/GpiChangedEvent.h"
#include "Events/LoggingEvent.h"
#include "Events/ReaderExceptionOccuredEvent.h"
#include "Events/ReportBufferOverflowedEvent.h"
#include "Events/ReportBufferWarnedEvent.h"
#include "Events/StartedEvent.h"
#include "Events/StoppedEvent.h"
#include "Events/TagsReportedEvent.h"

/* Exceptions  */
#include "Exceptions/OctaneSdkException.h"
#include "Exceptions/ConnectException.h"
#include "Exceptions/SettingsFileException.h"

/* SpeedwayReader */
#include "SpeedwayReader/SpeedwayReader.h"

#ifndef __IMPINJ_OCTANESDK_H__
#define __IMPINJ_OCTANESDK_H__


/*! @brief The namespace for the OctaneSDK library classes and functions
 *
 * This namespace contains the class, methods, constants, and enums
 * for the OctaneSDk reader interface library. 
 */
namespace Impinj_OctaneSdk
{
    /*! @mainpage
     *  
     * @section Introduction
     * Welcome to the OctaneSDK Doxygen help files for the C++ language.  
     * These files contain
     * reference information for the classes, methods, and attributes of
     * the OctaneSDK API.  This document is not a tutorial document.  Please
     * visit http://support.impinj.com to download the OctaneSDK tutorial
     * for C++.  
     *
     * @section Basic Usage
     * All elements within the OctaneSDK are contained in the Impinj_OctaneSdk
     * namespace. Include the following code in 
     * programs to access members of the Impinj_OctaneSdk or access them with
     * a full namespace like Impinj_OctaneSdk::SpeedwayReader.  
     * @code
     * #include <stdio.h>
     * #include <exception>
     *  
     * #include "OctaneSdk.h"
     *
     * using namespace std; // exceptions
     * using namespace Impinj_OctaneSdk;
     * @endcode
     *
     * A program will need to create one SpeedwayReader object for
     * each reader it intends to control.  Once created, a program can peform
     * some of these operations (and more):
     * <ul>
     *  <li>SpeedwayReader.Connect or SpeedwayReader.Disconnect 
     *      to a physical reader via hostname
     *      or IP address</li>
     *  <li>SpeedwayReader.QuerySettings and SpeedwayReader.ApplySettings
     *      to get and set the settings on the reader </li>
     *  <li>SpeedwayReader.QueryFeatureSet to learn the specific
     *      features of this reader make and model</li>
     *  <li>SpeedwayReader.QueryTags to poll the reader for tags it sees</li>
     *  <li>SpeedwayReader.QueryStatus to poll current status of the reader</li>
     * </ul>
     * See the SpeedwayReader, 
     * Settings, Status, Features, TagReport, and Tag classes for more
     * details on controlling the reader through the OctaneSDK
     */
   
    /*! @defgroup core Octane SDK Core Classes
     *
     * @brief A Collection of core classes for the Octane SDK
     *
     * These classes contain the core functionality of the OctaneSDK
     */
    
    /*! @defgroup events Reader Event Classes
     *
     * @brief OctaneSDK reader event classes
     *
     * These classes contain event information that is passed back
     * to the application through the OnXXX methods of the SpeedwayReader
     * class. NOTE: The callback associated with these events are called
     * through a separate thread. Use appropriate thread safe programming
     * where neccessary.  NOTE2: The virtual functions associated with
     * these events are not implemented in the SpeedwayReader class. You
     * must override this class and implement these methods to receive
     * these events.   
     */

    /*! @defgroup exceptions Octane SDK Exception Classes
     *
     * @brief The OctaneSDK specific exception classes
     *
     * OctaneSDK exceptions
     */

    /*! @defgroup status Reader Status Classes
     *
     * @brief Classes containing reader status
     *
     * These classes contain the real time status information obtained from 
     * the SpeedwayReader.QueryStatus method
     */

    /*! @defgroup settings Reader Setting Classes
     *
     * @brief Classes containing reader specific settings
     *
     * These classes contain the settings that are configurable on the 
     * reader via the OctaneSDK. 
     */

    /*! @defgroup features Reader Feature Classes
     *
     * @brief Classes containing reader specific features
     * 
     * These classes describe the feature that differentiate one reader
     * from another.
     */

    /*! @defgroup simpleaccess Simple Access Classes
     *
     * @brief Classes used for simple tag access operations
     *
     * These classes describe the configuration and respones for simple
     * tag access operations accessed via the SpeedwayReader class methods
     */

    /*! @defgroup primitiveaccess Primitive Access Classes
     *
     * @brief Classes used for primitive tag access operations
     *
     * These classes describe the configuration and respones for primitive
     * tag access operations supporeted by C1G2 standard and Impinj custom
     * access operations. They are accessed via the SpeedwayReader class
     * SpeedwayReader.RunPrimitiveSequence method.
     */
}

#endif // __IMPINJ_OCTANESDK_H__

