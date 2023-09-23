
/*
 * Generated file - DO NOT EDIT
 *
 * This is the header file for the LLRP Tool Kit (LTK)
 * C++ (aka cpp) implementation. It is generated into a .inc file
 * that is included by a platform specific .h header file.
 * That .h file takes care of prerequisites needed by this file.
 */




/*
 * Message classes - forward decls
 */


/* Custom messages */

struct LLRP_SIMPINJ_ENABLE_EXTENSIONS;
typedef struct LLRP_SIMPINJ_ENABLE_EXTENSIONS
    LLRP_tSIMPINJ_ENABLE_EXTENSIONS;

struct LLRP_SIMPINJ_ENABLE_EXTENSIONS_RESPONSE;
typedef struct LLRP_SIMPINJ_ENABLE_EXTENSIONS_RESPONSE
    LLRP_tSIMPINJ_ENABLE_EXTENSIONS_RESPONSE;

struct LLRP_SIMPINJ_SAVE_SETTINGS;
typedef struct LLRP_SIMPINJ_SAVE_SETTINGS
    LLRP_tSIMPINJ_SAVE_SETTINGS;

struct LLRP_SIMPINJ_SAVE_SETTINGS_RESPONSE;
typedef struct LLRP_SIMPINJ_SAVE_SETTINGS_RESPONSE
    LLRP_tSIMPINJ_SAVE_SETTINGS_RESPONSE;

struct LLRP_SIMPINJ_ADD_ENCODE_DATA_CACHE;
typedef struct LLRP_SIMPINJ_ADD_ENCODE_DATA_CACHE
    LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE;

struct LLRP_SIMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE;
typedef struct LLRP_SIMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE
    LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE;

struct LLRP_SIMPINJ_DELETE_ENCODE_DATA_CACHE;
typedef struct LLRP_SIMPINJ_DELETE_ENCODE_DATA_CACHE
    LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE;

struct LLRP_SIMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE;
typedef struct LLRP_SIMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE
    LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE;

struct LLRP_SIMPINJ_GET_ENCODE_DATA_CACHES;
typedef struct LLRP_SIMPINJ_GET_ENCODE_DATA_CACHES
    LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES;

struct LLRP_SIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE;
typedef struct LLRP_SIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE
    LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE;

struct LLRP_SIMPINJ_ADD_ENCODE_DATA;
typedef struct LLRP_SIMPINJ_ADD_ENCODE_DATA
    LLRP_tSIMPINJ_ADD_ENCODE_DATA;

struct LLRP_SIMPINJ_ADD_ENCODE_DATA_RESPONSE;
typedef struct LLRP_SIMPINJ_ADD_ENCODE_DATA_RESPONSE
    LLRP_tSIMPINJ_ADD_ENCODE_DATA_RESPONSE;


/*
 * Parameter classes - forward decls
 */


/* Custom parameters */

struct LLRP_SImpinjRequestedData;
typedef struct LLRP_SImpinjRequestedData
    LLRP_tSImpinjRequestedData;

struct LLRP_SImpinjSubRegulatoryRegion;
typedef struct LLRP_SImpinjSubRegulatoryRegion
    LLRP_tSImpinjSubRegulatoryRegion;

struct LLRP_SImpinjInventorySearchMode;
typedef struct LLRP_SImpinjInventorySearchMode
    LLRP_tSImpinjInventorySearchMode;

struct LLRP_SImpinjTagDirectionReporting;
typedef struct LLRP_SImpinjTagDirectionReporting
    LLRP_tSImpinjTagDirectionReporting;

struct LLRP_SImpinjTagDirection;
typedef struct LLRP_SImpinjTagDirection
    LLRP_tSImpinjTagDirection;

struct LLRP_SImpinjFixedFrequencyList;
typedef struct LLRP_SImpinjFixedFrequencyList
    LLRP_tSImpinjFixedFrequencyList;

struct LLRP_SImpinjReducedPowerFrequencyList;
typedef struct LLRP_SImpinjReducedPowerFrequencyList
    LLRP_tSImpinjReducedPowerFrequencyList;

struct LLRP_SImpinjLowDutyCycle;
typedef struct LLRP_SImpinjLowDutyCycle
    LLRP_tSImpinjLowDutyCycle;

struct LLRP_SImpinjDetailedVersion;
typedef struct LLRP_SImpinjDetailedVersion
    LLRP_tSImpinjDetailedVersion;

struct LLRP_SImpinjFrequencyCapabilities;
typedef struct LLRP_SImpinjFrequencyCapabilities
    LLRP_tSImpinjFrequencyCapabilities;

struct LLRP_SImpinjTagInformation;
typedef struct LLRP_SImpinjTagInformation
    LLRP_tSImpinjTagInformation;

struct LLRP_SImpinjForkliftConfiguration;
typedef struct LLRP_SImpinjForkliftConfiguration
    LLRP_tSImpinjForkliftConfiguration;

struct LLRP_SImpinjForkliftHeightThreshold;
typedef struct LLRP_SImpinjForkliftHeightThreshold
    LLRP_tSImpinjForkliftHeightThreshold;

struct LLRP_SImpinjForkliftZeroMotionTimeThreshold;
typedef struct LLRP_SImpinjForkliftZeroMotionTimeThreshold
    LLRP_tSImpinjForkliftZeroMotionTimeThreshold;

struct LLRP_SImpinjForkliftCompanionBoardInfo;
typedef struct LLRP_SImpinjForkliftCompanionBoardInfo
    LLRP_tSImpinjForkliftCompanionBoardInfo;

struct LLRP_SImpinjGPIDebounceConfiguration;
typedef struct LLRP_SImpinjGPIDebounceConfiguration
    LLRP_tSImpinjGPIDebounceConfiguration;

struct LLRP_SImpinjReaderTemperature;
typedef struct LLRP_SImpinjReaderTemperature
    LLRP_tSImpinjReaderTemperature;

struct LLRP_SImpinjLinkMonitorConfiguration;
typedef struct LLRP_SImpinjLinkMonitorConfiguration
    LLRP_tSImpinjLinkMonitorConfiguration;

struct LLRP_SImpinjReportBufferConfiguration;
typedef struct LLRP_SImpinjReportBufferConfiguration
    LLRP_tSImpinjReportBufferConfiguration;

struct LLRP_SImpinjAccessSpecConfiguration;
typedef struct LLRP_SImpinjAccessSpecConfiguration
    LLRP_tSImpinjAccessSpecConfiguration;

struct LLRP_SImpinjBlockWriteWordCount;
typedef struct LLRP_SImpinjBlockWriteWordCount
    LLRP_tSImpinjBlockWriteWordCount;

struct LLRP_SImpinjBlockPermalock;
typedef struct LLRP_SImpinjBlockPermalock
    LLRP_tSImpinjBlockPermalock;

struct LLRP_SImpinjBlockPermalockOpSpecResult;
typedef struct LLRP_SImpinjBlockPermalockOpSpecResult
    LLRP_tSImpinjBlockPermalockOpSpecResult;

struct LLRP_SImpinjGetBlockPermalockStatus;
typedef struct LLRP_SImpinjGetBlockPermalockStatus
    LLRP_tSImpinjGetBlockPermalockStatus;

struct LLRP_SImpinjGetBlockPermalockStatusOpSpecResult;
typedef struct LLRP_SImpinjGetBlockPermalockStatusOpSpecResult
    LLRP_tSImpinjGetBlockPermalockStatusOpSpecResult;

struct LLRP_SImpinjSetQTConfig;
typedef struct LLRP_SImpinjSetQTConfig
    LLRP_tSImpinjSetQTConfig;

struct LLRP_SImpinjSetQTConfigOpSpecResult;
typedef struct LLRP_SImpinjSetQTConfigOpSpecResult
    LLRP_tSImpinjSetQTConfigOpSpecResult;

struct LLRP_SImpinjGetQTConfig;
typedef struct LLRP_SImpinjGetQTConfig
    LLRP_tSImpinjGetQTConfig;

struct LLRP_SImpinjGetQTConfigOpSpecResult;
typedef struct LLRP_SImpinjGetQTConfigOpSpecResult
    LLRP_tSImpinjGetQTConfigOpSpecResult;

struct LLRP_SImpinjTagReportContentSelector;
typedef struct LLRP_SImpinjTagReportContentSelector
    LLRP_tSImpinjTagReportContentSelector;

struct LLRP_SImpinjEnableSerializedTID;
typedef struct LLRP_SImpinjEnableSerializedTID
    LLRP_tSImpinjEnableSerializedTID;

struct LLRP_SImpinjEnableRFPhaseAngle;
typedef struct LLRP_SImpinjEnableRFPhaseAngle
    LLRP_tSImpinjEnableRFPhaseAngle;

struct LLRP_SImpinjEnablePeakRSSI;
typedef struct LLRP_SImpinjEnablePeakRSSI
    LLRP_tSImpinjEnablePeakRSSI;

struct LLRP_SImpinjEnableGPSCoordinates;
typedef struct LLRP_SImpinjEnableGPSCoordinates
    LLRP_tSImpinjEnableGPSCoordinates;

struct LLRP_SImpinjSerializedTID;
typedef struct LLRP_SImpinjSerializedTID
    LLRP_tSImpinjSerializedTID;

struct LLRP_SImpinjRFPhaseAngle;
typedef struct LLRP_SImpinjRFPhaseAngle
    LLRP_tSImpinjRFPhaseAngle;

struct LLRP_SImpinjPeakRSSI;
typedef struct LLRP_SImpinjPeakRSSI
    LLRP_tSImpinjPeakRSSI;

struct LLRP_SImpinjGPSCoordinates;
typedef struct LLRP_SImpinjGPSCoordinates
    LLRP_tSImpinjGPSCoordinates;

struct LLRP_SImpinjLoopSpec;
typedef struct LLRP_SImpinjLoopSpec
    LLRP_tSImpinjLoopSpec;

struct LLRP_SImpinjGPSNMEASentences;
typedef struct LLRP_SImpinjGPSNMEASentences
    LLRP_tSImpinjGPSNMEASentences;

struct LLRP_SImpinjGGASentence;
typedef struct LLRP_SImpinjGGASentence
    LLRP_tSImpinjGGASentence;

struct LLRP_SImpinjRMCSentence;
typedef struct LLRP_SImpinjRMCSentence
    LLRP_tSImpinjRMCSentence;

struct LLRP_SImpinjOpSpecRetryCount;
typedef struct LLRP_SImpinjOpSpecRetryCount
    LLRP_tSImpinjOpSpecRetryCount;

struct LLRP_SImpinjAdvancedGPOConfiguration;
typedef struct LLRP_SImpinjAdvancedGPOConfiguration
    LLRP_tSImpinjAdvancedGPOConfiguration;

struct LLRP_SImpinjEnableOptimizedRead;
typedef struct LLRP_SImpinjEnableOptimizedRead
    LLRP_tSImpinjEnableOptimizedRead;

struct LLRP_SImpinjAccessSpecOrdering;
typedef struct LLRP_SImpinjAccessSpecOrdering
    LLRP_tSImpinjAccessSpecOrdering;

struct LLRP_SImpinjEnableRFDopplerFrequency;
typedef struct LLRP_SImpinjEnableRFDopplerFrequency
    LLRP_tSImpinjEnableRFDopplerFrequency;

struct LLRP_SImpinjRFDopplerFrequency;
typedef struct LLRP_SImpinjRFDopplerFrequency
    LLRP_tSImpinjRFDopplerFrequency;

struct LLRP_SImpinjSTPCapabilities;
typedef struct LLRP_SImpinjSTPCapabilities
    LLRP_tSImpinjSTPCapabilities;

struct LLRP_SImpinjTagIC;
typedef struct LLRP_SImpinjTagIC
    LLRP_tSImpinjTagIC;

struct LLRP_SImpinjEncodeDataCache;
typedef struct LLRP_SImpinjEncodeDataCache
    LLRP_tSImpinjEncodeDataCache;

struct LLRP_SImpinjEncodeDataDefaults;
typedef struct LLRP_SImpinjEncodeDataDefaults
    LLRP_tSImpinjEncodeDataDefaults;

struct LLRP_SImpinjEncodeData;
typedef struct LLRP_SImpinjEncodeData
    LLRP_tSImpinjEncodeData;

struct LLRP_SImpinjEncodeDataPCBits;
typedef struct LLRP_SImpinjEncodeDataPCBits
    LLRP_tSImpinjEncodeDataPCBits;

struct LLRP_SImpinjEncodeDataAccessPassword;
typedef struct LLRP_SImpinjEncodeDataAccessPassword
    LLRP_tSImpinjEncodeDataAccessPassword;

struct LLRP_SImpinjEncodeDataKillPassword;
typedef struct LLRP_SImpinjEncodeDataKillPassword
    LLRP_tSImpinjEncodeDataKillPassword;

struct LLRP_SImpinjEncodeDataUserMemory;
typedef struct LLRP_SImpinjEncodeDataUserMemory
    LLRP_tSImpinjEncodeDataUserMemory;

struct LLRP_SImpinjEncodeDataAlternateEPC;
typedef struct LLRP_SImpinjEncodeDataAlternateEPC
    LLRP_tSImpinjEncodeDataAlternateEPC;

struct LLRP_SImpinjEncodeDataQTConfig;
typedef struct LLRP_SImpinjEncodeDataQTConfig
    LLRP_tSImpinjEncodeDataQTConfig;

struct LLRP_SImpinjEncodeDataLockConfig;
typedef struct LLRP_SImpinjEncodeDataLockConfig
    LLRP_tSImpinjEncodeDataLockConfig;

struct LLRP_SImpinjLowEncodeDataThresholdEvent;
typedef struct LLRP_SImpinjLowEncodeDataThresholdEvent
    LLRP_tSImpinjLowEncodeDataThresholdEvent;

struct LLRP_SImpinjEncodeOpSpec;
typedef struct LLRP_SImpinjEncodeOpSpec
    LLRP_tSImpinjEncodeOpSpec;

struct LLRP_SImpinjOpSpecGPOPulse;
typedef struct LLRP_SImpinjOpSpecGPOPulse
    LLRP_tSImpinjOpSpecGPOPulse;

struct LLRP_SImpinjEncodeReportData;
typedef struct LLRP_SImpinjEncodeReportData
    LLRP_tSImpinjEncodeReportData;

struct LLRP_SImpinjEncodeOpSpecResult;
typedef struct LLRP_SImpinjEncodeOpSpecResult
    LLRP_tSImpinjEncodeOpSpecResult;

struct LLRP_SImpinjEncodeDataResult;
typedef struct LLRP_SImpinjEncodeDataResult
    LLRP_tSImpinjEncodeDataResult;

struct LLRP_SImpinjEncodeDataDetailedResult;
typedef struct LLRP_SImpinjEncodeDataDetailedResult
    LLRP_tSImpinjEncodeDataDetailedResult;


/*
 * Vendor descriptor declarations.
 */

extern const LLRP_tSVendorDescriptor
LLRP_vdescImpinj;


/*
 * Namespace descriptor declarations.
 */

extern const LLRP_tSNamespaceDescriptor
LLRP_nsdescImpinj;


/*
 * Enumeration definitions and declarations of
 * enumeration string tables.
 */


enum LLRP_EImpinjRequestedDataType
{

    LLRP_ImpinjRequestedDataType_All_Capabilities = 1000,
    LLRP_ImpinjRequestedDataType_Impinj_Detailed_Version = 1001,
    LLRP_ImpinjRequestedDataType_Impinj_Frequency_Capabilities = 1002,
    LLRP_ImpinjRequestedDataType_All_Configuration = 2000,
    LLRP_ImpinjRequestedDataType_Impinj_Sub_Regulatory_Region = 2001,
    LLRP_ImpinjRequestedDataType_Impinj_Forklift_Configuration = 2002,
    LLRP_ImpinjRequestedDataType_Impinj_GPI_Debounce_Configuration = 2003,
    LLRP_ImpinjRequestedDataType_Impinj_Reader_Temperature = 2004,
    LLRP_ImpinjRequestedDataType_Impinj_Link_Monitor_Configuration = 2005,
    LLRP_ImpinjRequestedDataType_Impinj_Report_Buffer_Configuration = 2006,
    LLRP_ImpinjRequestedDataType_Impinj_Access_Spec_Configuration = 2007,
    LLRP_ImpinjRequestedDataType_Impinj_GPS_NMEA_Sentences = 2008,
    LLRP_ImpinjRequestedDataType_Impinj_Advanced_GPO_Configuration = 2009,
};

typedef enum LLRP_EImpinjRequestedDataType
    LLRP_tEImpinjRequestedDataType;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjRequestedDataType[];


enum LLRP_EImpinjRegulatoryRegion
{

    LLRP_ImpinjRegulatoryRegion_FCC_Part_15_247 = 0,
    LLRP_ImpinjRegulatoryRegion_ETSI_EN_300_220 = 1,
    LLRP_ImpinjRegulatoryRegion_ETSI_EN_302_208_With_LBT = 2,
    LLRP_ImpinjRegulatoryRegion_Hong_Kong_920_925_MHz = 3,
    LLRP_ImpinjRegulatoryRegion_Taiwan_922_928_MHz = 4,
    LLRP_ImpinjRegulatoryRegion_Japan_952_954_MHz = 5,
    LLRP_ImpinjRegulatoryRegion_Japan_952_954_MHz_Low_Power = 6,
    LLRP_ImpinjRegulatoryRegion_ETSI_EN_302_208_v1_2_1 = 7,
    LLRP_ImpinjRegulatoryRegion_Korea_917_921_MHz = 8,
    LLRP_ImpinjRegulatoryRegion_Malaysia_919_923_MHz = 9,
    LLRP_ImpinjRegulatoryRegion_China_920_925_MHz = 10,
    LLRP_ImpinjRegulatoryRegion_Japan_952_956_MHz_Without_LBT = 11,
    LLRP_ImpinjRegulatoryRegion_South_Africa_915_919_MHz = 12,
    LLRP_ImpinjRegulatoryRegion_Brazil_902_907_and_915_928_MHz = 13,
    LLRP_ImpinjRegulatoryRegion_Thailand_920_925_MHz = 14,
    LLRP_ImpinjRegulatoryRegion_Singapore_920_925_MHz = 15,
    LLRP_ImpinjRegulatoryRegion_Australia_920_926_MHz = 16,
    LLRP_ImpinjRegulatoryRegion_India_865_867_MHz = 17,
    LLRP_ImpinjRegulatoryRegion_Uruguay_916_928_MHz = 18,
    LLRP_ImpinjRegulatoryRegion_Vietnam_920_925_MHz = 19,
    LLRP_ImpinjRegulatoryRegion_Israel_915_917_MHz = 20,
    LLRP_ImpinjRegulatoryRegion_Philippines_918_920_MHz = 21,
    LLRP_ImpinjRegulatoryRegion_Canada_Post = 22,
    LLRP_ImpinjRegulatoryRegion_Indonesia_923_925_MHz = 23,
    LLRP_ImpinjRegulatoryRegion_New_Zealand_921p5_928_MHz = 24,
};

typedef enum LLRP_EImpinjRegulatoryRegion
    LLRP_tEImpinjRegulatoryRegion;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjRegulatoryRegion[];


enum LLRP_EImpinjInventorySearchType
{

    LLRP_ImpinjInventorySearchType_Reader_Selected = 0,
    LLRP_ImpinjInventorySearchType_Single_Target = 1,
    LLRP_ImpinjInventorySearchType_Dual_Target = 2,
    LLRP_ImpinjInventorySearchType_Single_Target_With_Suppression = 3,
};

typedef enum LLRP_EImpinjInventorySearchType
    LLRP_tEImpinjInventorySearchType;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjInventorySearchType[];


enum LLRP_EImpinjTagDirectionAntennaConfiguration
{

    LLRP_ImpinjTagDirectionAntennaConfiguration_Dual_Antenna = 1,
    LLRP_ImpinjTagDirectionAntennaConfiguration_Quad_Antenna = 2,
};

typedef enum LLRP_EImpinjTagDirectionAntennaConfiguration
    LLRP_tEImpinjTagDirectionAntennaConfiguration;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjTagDirectionAntennaConfiguration[];


enum LLRP_EImpinjDirection
{

    LLRP_ImpinjDirection_Indeterminate = 0,
    LLRP_ImpinjDirection_From_Side2_To_Side1 = 1,
    LLRP_ImpinjDirection_From_Side1_To_Side2 = 2,
};

typedef enum LLRP_EImpinjDirection
    LLRP_tEImpinjDirection;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjDirection[];


enum LLRP_EImpinjFixedFrequencyMode
{

    LLRP_ImpinjFixedFrequencyMode_Disabled = 0,
    LLRP_ImpinjFixedFrequencyMode_Auto_Select = 1,
    LLRP_ImpinjFixedFrequencyMode_Channel_List = 2,
};

typedef enum LLRP_EImpinjFixedFrequencyMode
    LLRP_tEImpinjFixedFrequencyMode;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjFixedFrequencyMode[];


enum LLRP_EImpinjReducedPowerMode
{

    LLRP_ImpinjReducedPowerMode_Disabled = 0,
    LLRP_ImpinjReducedPowerMode_Enabled = 1,
};

typedef enum LLRP_EImpinjReducedPowerMode
    LLRP_tEImpinjReducedPowerMode;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjReducedPowerMode[];


enum LLRP_EImpinjLowDutyCycleMode
{

    LLRP_ImpinjLowDutyCycleMode_Disabled = 0,
    LLRP_ImpinjLowDutyCycleMode_Enabled = 1,
};

typedef enum LLRP_EImpinjLowDutyCycleMode
    LLRP_tEImpinjLowDutyCycleMode;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjLowDutyCycleMode[];


enum LLRP_EImpinjLinkMonitorMode
{

    LLRP_ImpinjLinkMonitorMode_Disabled = 0,
    LLRP_ImpinjLinkMonitorMode_Enabled = 1,
};

typedef enum LLRP_EImpinjLinkMonitorMode
    LLRP_tEImpinjLinkMonitorMode;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjLinkMonitorMode[];


enum LLRP_EImpinjReportBufferMode
{

    LLRP_ImpinjReportBufferMode_Normal = 0,
    LLRP_ImpinjReportBufferMode_Low_Latency = 1,
};

typedef enum LLRP_EImpinjReportBufferMode
    LLRP_tEImpinjReportBufferMode;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjReportBufferMode[];


enum LLRP_EImpinjBlockPermalockResultType
{

    LLRP_ImpinjBlockPermalockResultType_Success = 0,
    LLRP_ImpinjBlockPermalockResultType_Insufficient_Power = 1,
    LLRP_ImpinjBlockPermalockResultType_Nonspecific_Tag_Error = 2,
    LLRP_ImpinjBlockPermalockResultType_No_Response_From_Tag = 3,
    LLRP_ImpinjBlockPermalockResultType_Nonspecific_Reader_Error = 4,
    LLRP_ImpinjBlockPermalockResultType_Incorrect_Password_Error = 5,
    LLRP_ImpinjBlockPermalockResultType_Tag_Memory_Overrun_Error = 6,
};

typedef enum LLRP_EImpinjBlockPermalockResultType
    LLRP_tEImpinjBlockPermalockResultType;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjBlockPermalockResultType[];


enum LLRP_EImpinjGetBlockPermalockStatusResultType
{

    LLRP_ImpinjGetBlockPermalockStatusResultType_Success = 0,
    LLRP_ImpinjGetBlockPermalockStatusResultType_Nonspecific_Tag_Error = 1,
    LLRP_ImpinjGetBlockPermalockStatusResultType_No_Response_From_Tag = 2,
    LLRP_ImpinjGetBlockPermalockStatusResultType_Nonspecific_Reader_Error = 3,
    LLRP_ImpinjGetBlockPermalockStatusResultType_Incorrect_Password_Error = 4,
    LLRP_ImpinjGetBlockPermalockStatusResultType_Tag_Memory_Overrun_Error = 5,
};

typedef enum LLRP_EImpinjGetBlockPermalockStatusResultType
    LLRP_tEImpinjGetBlockPermalockStatusResultType;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjGetBlockPermalockStatusResultType[];


enum LLRP_EImpinjQTDataProfile
{

    LLRP_ImpinjQTDataProfile_Unknown = 0,
    LLRP_ImpinjQTDataProfile_Private = 1,
    LLRP_ImpinjQTDataProfile_Public = 2,
};

typedef enum LLRP_EImpinjQTDataProfile
    LLRP_tEImpinjQTDataProfile;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjQTDataProfile[];


enum LLRP_EImpinjQTAccessRange
{

    LLRP_ImpinjQTAccessRange_Unknown = 0,
    LLRP_ImpinjQTAccessRange_Normal_Range = 1,
    LLRP_ImpinjQTAccessRange_Short_Range = 2,
};

typedef enum LLRP_EImpinjQTAccessRange
    LLRP_tEImpinjQTAccessRange;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjQTAccessRange[];


enum LLRP_EImpinjQTPersistence
{

    LLRP_ImpinjQTPersistence_Unknown = 0,
    LLRP_ImpinjQTPersistence_Temporary = 1,
    LLRP_ImpinjQTPersistence_Permanent = 2,
};

typedef enum LLRP_EImpinjQTPersistence
    LLRP_tEImpinjQTPersistence;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjQTPersistence[];


enum LLRP_EImpinjSetQTConfigResultType
{

    LLRP_ImpinjSetQTConfigResultType_Success = 0,
    LLRP_ImpinjSetQTConfigResultType_Insufficient_Power = 1,
    LLRP_ImpinjSetQTConfigResultType_Nonspecific_Tag_Error = 2,
    LLRP_ImpinjSetQTConfigResultType_No_Response_From_Tag = 3,
    LLRP_ImpinjSetQTConfigResultType_Nonspecific_Reader_Error = 4,
    LLRP_ImpinjSetQTConfigResultType_Incorrect_Password_Error = 5,
};

typedef enum LLRP_EImpinjSetQTConfigResultType
    LLRP_tEImpinjSetQTConfigResultType;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjSetQTConfigResultType[];


enum LLRP_EImpinjGetQTConfigResultType
{

    LLRP_ImpinjGetQTConfigResultType_Success = 0,
    LLRP_ImpinjGetQTConfigResultType_Nonspecific_Tag_Error = 1,
    LLRP_ImpinjGetQTConfigResultType_No_Response_From_Tag = 2,
    LLRP_ImpinjGetQTConfigResultType_Nonspecific_Reader_Error = 3,
    LLRP_ImpinjGetQTConfigResultType_Incorrect_Password_Error = 4,
};

typedef enum LLRP_EImpinjGetQTConfigResultType
    LLRP_tEImpinjGetQTConfigResultType;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjGetQTConfigResultType[];


enum LLRP_EImpinjSerializedTIDMode
{

    LLRP_ImpinjSerializedTIDMode_Disabled = 0,
    LLRP_ImpinjSerializedTIDMode_Enabled = 1,
};

typedef enum LLRP_EImpinjSerializedTIDMode
    LLRP_tEImpinjSerializedTIDMode;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjSerializedTIDMode[];


enum LLRP_EImpinjRFPhaseAngleMode
{

    LLRP_ImpinjRFPhaseAngleMode_Disabled = 0,
    LLRP_ImpinjRFPhaseAngleMode_Enabled = 1,
};

typedef enum LLRP_EImpinjRFPhaseAngleMode
    LLRP_tEImpinjRFPhaseAngleMode;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjRFPhaseAngleMode[];


enum LLRP_EImpinjPeakRSSIMode
{

    LLRP_ImpinjPeakRSSIMode_Disabled = 0,
    LLRP_ImpinjPeakRSSIMode_Enabled = 1,
};

typedef enum LLRP_EImpinjPeakRSSIMode
    LLRP_tEImpinjPeakRSSIMode;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjPeakRSSIMode[];


enum LLRP_EImpinjGPSCoordinatesMode
{

    LLRP_ImpinjGPSCoordinatesMode_Disabled = 0,
    LLRP_ImpinjGPSCoordinatesMode_Enabled = 1,
};

typedef enum LLRP_EImpinjGPSCoordinatesMode
    LLRP_tEImpinjGPSCoordinatesMode;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjGPSCoordinatesMode[];


enum LLRP_EImpinjAdvancedGPOMode
{

    LLRP_ImpinjAdvancedGPOMode_Normal = 0,
    LLRP_ImpinjAdvancedGPOMode_Pulsed = 1,
    LLRP_ImpinjAdvancedGPOMode_Reader_Operational_Status = 2,
    LLRP_ImpinjAdvancedGPOMode_LLRP_Connection_Status = 3,
    LLRP_ImpinjAdvancedGPOMode_Reader_Inventory_Status = 4,
    LLRP_ImpinjAdvancedGPOMode_Network_Connection_Status = 5,
    LLRP_ImpinjAdvancedGPOMode_Reader_Inventory_Tags_Status = 6,
};

typedef enum LLRP_EImpinjAdvancedGPOMode
    LLRP_tEImpinjAdvancedGPOMode;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjAdvancedGPOMode[];


enum LLRP_EImpinjOptimizedReadMode
{

    LLRP_ImpinjOptimizedReadMode_Disabled = 0,
    LLRP_ImpinjOptimizedReadMode_Enabled = 1,
};

typedef enum LLRP_EImpinjOptimizedReadMode
    LLRP_tEImpinjOptimizedReadMode;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjOptimizedReadMode[];


enum LLRP_EImpinjAccessSpecOrderingMode
{

    LLRP_ImpinjAccessSpecOrderingMode_FIFO = 0,
    LLRP_ImpinjAccessSpecOrderingMode_Ascending = 1,
};

typedef enum LLRP_EImpinjAccessSpecOrderingMode
    LLRP_tEImpinjAccessSpecOrderingMode;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjAccessSpecOrderingMode[];


enum LLRP_EImpinjRFDopplerFrequencyMode
{

    LLRP_ImpinjRFDopplerFrequencyMode_Disabled = 0,
    LLRP_ImpinjRFDopplerFrequencyMode_Enabled = 1,
};

typedef enum LLRP_EImpinjRFDopplerFrequencyMode
    LLRP_tEImpinjRFDopplerFrequencyMode;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjRFDopplerFrequencyMode[];


enum LLRP_EImpinjEncodeStatus
{

    LLRP_ImpinjEncodeStatus_Disabled = 0,
    LLRP_ImpinjEncodeStatus_Enabled = 1,
};

typedef enum LLRP_EImpinjEncodeStatus
    LLRP_tEImpinjEncodeStatus;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjEncodeStatus[];


enum LLRP_EImpinjLockPrivilege
{

    LLRP_ImpinjLockPrivilege_No_Action = 0,
    LLRP_ImpinjLockPrivilege_Unlock = 1,
    LLRP_ImpinjLockPrivilege_Lock = 2,
    LLRP_ImpinjLockPrivilege_Perma_Lock = 3,
    LLRP_ImpinjLockPrivilege_Perma_Unlock = 4,
};

typedef enum LLRP_EImpinjLockPrivilege
    LLRP_tEImpinjLockPrivilege;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjLockPrivilege[];


enum LLRP_EImpinjEncodeMode
{

    LLRP_ImpinjEncodeMode_Batch = 1,
    LLRP_ImpinjEncodeMode_Continuous = 2,
};

typedef enum LLRP_EImpinjEncodeMode
    LLRP_tEImpinjEncodeMode;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjEncodeMode[];


enum LLRP_EImpinjTagICType
{

    LLRP_ImpinjTagICType_Monza3 = 1,
    LLRP_ImpinjTagICType_Monza4 = 2,
    LLRP_ImpinjTagICType_Monza5 = 3,
    LLRP_ImpinjTagICType_AnyGen2 = 100,
};

typedef enum LLRP_EImpinjTagICType
    LLRP_tEImpinjTagICType;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjTagICType[];


enum LLRP_EImpinjOpSpecAction
{

    LLRP_ImpinjOpSpecAction_Op_Spec_Started = 1,
    LLRP_ImpinjOpSpecAction_Op_Spec_Finished = 2,
    LLRP_ImpinjOpSpecAction_Op_Spec_Success = 3,
    LLRP_ImpinjOpSpecAction_Op_Spec_Failure = 4,
    LLRP_ImpinjOpSpecAction_Op_Spec_SingleSuccess = 5,
    LLRP_ImpinjOpSpecAction_Op_Spec_SingleFailure = 6,
};

typedef enum LLRP_EImpinjOpSpecAction
    LLRP_tEImpinjOpSpecAction;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjOpSpecAction[];


enum LLRP_EImpinjEncodeResultType
{

    LLRP_ImpinjEncodeResultType_Success = 0,
    LLRP_ImpinjEncodeResultType_Success_With_Degraded_Performance = 1,
    LLRP_ImpinjEncodeResultType_Encode_Timeout = 2,
    LLRP_ImpinjEncodeResultType_Encode_Data_Cache_Empty = 3,
    LLRP_ImpinjEncodeResultType_Wrong_Tag_IC_Detected = 4,
};

typedef enum LLRP_EImpinjEncodeResultType
    LLRP_tEImpinjEncodeResultType;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjEncodeResultType[];


enum LLRP_EImpinjEncodeDataResultType
{

    LLRP_ImpinjEncodeDataResultType_Success = 0,
    LLRP_ImpinjEncodeDataResultType_Failure = 1,
    LLRP_ImpinjEncodeDataResultType_Timeout = 2,
    LLRP_ImpinjEncodeDataResultType_Not_Attempted = 3,
    LLRP_ImpinjEncodeDataResultType_Insufficient_Power = 4,
    LLRP_ImpinjEncodeDataResultType_No_Response_From_Tag = 5,
    LLRP_ImpinjEncodeDataResultType_Incorrect_Password_Error = 6,
    LLRP_ImpinjEncodeDataResultType_Tag_Memory_Locked_Error = 7,
    LLRP_ImpinjEncodeDataResultType_Nonspecific_Tag_Error = 8,
    LLRP_ImpinjEncodeDataResultType_Nonspecific_Reader_Error = 9,
};

typedef enum LLRP_EImpinjEncodeDataResultType
    LLRP_tEImpinjEncodeDataResultType;

extern const LLRP_tSEnumTableEntry
LLRP_estImpinjEncodeDataResultType[];


  
struct LLRP_SIMPINJ_ENABLE_EXTENSIONS
{
    LLRP_tSMessage hdr;
  
  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdIMPINJ_ENABLE_EXTENSIONS;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdIMPINJ_ENABLE_EXTENSIONS[];

extern LLRP_tSIMPINJ_ENABLE_EXTENSIONS *
LLRP_IMPINJ_ENABLE_EXTENSIONS_construct (void);

extern void
LLRP_IMPINJ_ENABLE_EXTENSIONS_destruct (
 LLRP_tSIMPINJ_ENABLE_EXTENSIONS * pThis);

extern void
LLRP_IMPINJ_ENABLE_EXTENSIONS_decodeFields (
 LLRP_tSIMPINJ_ENABLE_EXTENSIONS * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_IMPINJ_ENABLE_EXTENSIONS_assimilateSubParameters (
 LLRP_tSIMPINJ_ENABLE_EXTENSIONS * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_IMPINJ_ENABLE_EXTENSIONS_encode (
  const LLRP_tSIMPINJ_ENABLE_EXTENSIONS *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  

  
  
extern LLRP_tSParameter *
LLRP_IMPINJ_ENABLE_EXTENSIONS_beginCustom (
  LLRP_tSIMPINJ_ENABLE_EXTENSIONS *pThis);

extern LLRP_tSParameter *
LLRP_IMPINJ_ENABLE_EXTENSIONS_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_IMPINJ_ENABLE_EXTENSIONS_clearCustom (
  LLRP_tSIMPINJ_ENABLE_EXTENSIONS *pThis);

extern int
LLRP_IMPINJ_ENABLE_EXTENSIONS_countCustom (
  LLRP_tSIMPINJ_ENABLE_EXTENSIONS *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_ENABLE_EXTENSIONS_addCustom (
  LLRP_tSIMPINJ_ENABLE_EXTENSIONS *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SIMPINJ_ENABLE_EXTENSIONS_RESPONSE
{
    LLRP_tSMessage hdr;
  
  
    LLRP_tSLLRPStatus * pLLRPStatus;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdIMPINJ_ENABLE_EXTENSIONS_RESPONSE;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdIMPINJ_ENABLE_EXTENSIONS_RESPONSE[];

extern LLRP_tSIMPINJ_ENABLE_EXTENSIONS_RESPONSE *
LLRP_IMPINJ_ENABLE_EXTENSIONS_RESPONSE_construct (void);

extern void
LLRP_IMPINJ_ENABLE_EXTENSIONS_RESPONSE_destruct (
 LLRP_tSIMPINJ_ENABLE_EXTENSIONS_RESPONSE * pThis);

extern void
LLRP_IMPINJ_ENABLE_EXTENSIONS_RESPONSE_decodeFields (
 LLRP_tSIMPINJ_ENABLE_EXTENSIONS_RESPONSE * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_IMPINJ_ENABLE_EXTENSIONS_RESPONSE_assimilateSubParameters (
 LLRP_tSIMPINJ_ENABLE_EXTENSIONS_RESPONSE * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_IMPINJ_ENABLE_EXTENSIONS_RESPONSE_encode (
  const LLRP_tSIMPINJ_ENABLE_EXTENSIONS_RESPONSE *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  

  
  
extern LLRP_tSLLRPStatus *
LLRP_IMPINJ_ENABLE_EXTENSIONS_RESPONSE_getLLRPStatus (
  LLRP_tSIMPINJ_ENABLE_EXTENSIONS_RESPONSE *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_ENABLE_EXTENSIONS_RESPONSE_setLLRPStatus (
  LLRP_tSIMPINJ_ENABLE_EXTENSIONS_RESPONSE *pThis,
  LLRP_tSLLRPStatus *pValue);

extern LLRP_tSParameter *
LLRP_IMPINJ_ENABLE_EXTENSIONS_RESPONSE_beginCustom (
  LLRP_tSIMPINJ_ENABLE_EXTENSIONS_RESPONSE *pThis);

extern LLRP_tSParameter *
LLRP_IMPINJ_ENABLE_EXTENSIONS_RESPONSE_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_IMPINJ_ENABLE_EXTENSIONS_RESPONSE_clearCustom (
  LLRP_tSIMPINJ_ENABLE_EXTENSIONS_RESPONSE *pThis);

extern int
LLRP_IMPINJ_ENABLE_EXTENSIONS_RESPONSE_countCustom (
  LLRP_tSIMPINJ_ENABLE_EXTENSIONS_RESPONSE *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_ENABLE_EXTENSIONS_RESPONSE_addCustom (
  LLRP_tSIMPINJ_ENABLE_EXTENSIONS_RESPONSE *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SIMPINJ_SAVE_SETTINGS
{
    LLRP_tSMessage hdr;
  
    llrp_u1_t SaveConfiguration;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdIMPINJ_SAVE_SETTINGS;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdIMPINJ_SAVE_SETTINGS[];

extern LLRP_tSIMPINJ_SAVE_SETTINGS *
LLRP_IMPINJ_SAVE_SETTINGS_construct (void);

extern void
LLRP_IMPINJ_SAVE_SETTINGS_destruct (
 LLRP_tSIMPINJ_SAVE_SETTINGS * pThis);

extern void
LLRP_IMPINJ_SAVE_SETTINGS_decodeFields (
 LLRP_tSIMPINJ_SAVE_SETTINGS * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_IMPINJ_SAVE_SETTINGS_assimilateSubParameters (
 LLRP_tSIMPINJ_SAVE_SETTINGS * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_IMPINJ_SAVE_SETTINGS_encode (
  const LLRP_tSIMPINJ_SAVE_SETTINGS *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdIMPINJ_SAVE_SETTINGS_SaveConfiguration;

extern llrp_u1_t
LLRP_IMPINJ_SAVE_SETTINGS_getSaveConfiguration (
  LLRP_tSIMPINJ_SAVE_SETTINGS *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_SAVE_SETTINGS_setSaveConfiguration (
  LLRP_tSIMPINJ_SAVE_SETTINGS *pThis,
  llrp_u1_t Value);

  
extern LLRP_tSParameter *
LLRP_IMPINJ_SAVE_SETTINGS_beginCustom (
  LLRP_tSIMPINJ_SAVE_SETTINGS *pThis);

extern LLRP_tSParameter *
LLRP_IMPINJ_SAVE_SETTINGS_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_IMPINJ_SAVE_SETTINGS_clearCustom (
  LLRP_tSIMPINJ_SAVE_SETTINGS *pThis);

extern int
LLRP_IMPINJ_SAVE_SETTINGS_countCustom (
  LLRP_tSIMPINJ_SAVE_SETTINGS *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_SAVE_SETTINGS_addCustom (
  LLRP_tSIMPINJ_SAVE_SETTINGS *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SIMPINJ_SAVE_SETTINGS_RESPONSE
{
    LLRP_tSMessage hdr;
  
  
    LLRP_tSLLRPStatus * pLLRPStatus;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdIMPINJ_SAVE_SETTINGS_RESPONSE;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdIMPINJ_SAVE_SETTINGS_RESPONSE[];

extern LLRP_tSIMPINJ_SAVE_SETTINGS_RESPONSE *
LLRP_IMPINJ_SAVE_SETTINGS_RESPONSE_construct (void);

extern void
LLRP_IMPINJ_SAVE_SETTINGS_RESPONSE_destruct (
 LLRP_tSIMPINJ_SAVE_SETTINGS_RESPONSE * pThis);

extern void
LLRP_IMPINJ_SAVE_SETTINGS_RESPONSE_decodeFields (
 LLRP_tSIMPINJ_SAVE_SETTINGS_RESPONSE * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_IMPINJ_SAVE_SETTINGS_RESPONSE_assimilateSubParameters (
 LLRP_tSIMPINJ_SAVE_SETTINGS_RESPONSE * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_IMPINJ_SAVE_SETTINGS_RESPONSE_encode (
  const LLRP_tSIMPINJ_SAVE_SETTINGS_RESPONSE *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  

  
  
extern LLRP_tSLLRPStatus *
LLRP_IMPINJ_SAVE_SETTINGS_RESPONSE_getLLRPStatus (
  LLRP_tSIMPINJ_SAVE_SETTINGS_RESPONSE *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_SAVE_SETTINGS_RESPONSE_setLLRPStatus (
  LLRP_tSIMPINJ_SAVE_SETTINGS_RESPONSE *pThis,
  LLRP_tSLLRPStatus *pValue);

extern LLRP_tSParameter *
LLRP_IMPINJ_SAVE_SETTINGS_RESPONSE_beginCustom (
  LLRP_tSIMPINJ_SAVE_SETTINGS_RESPONSE *pThis);

extern LLRP_tSParameter *
LLRP_IMPINJ_SAVE_SETTINGS_RESPONSE_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_IMPINJ_SAVE_SETTINGS_RESPONSE_clearCustom (
  LLRP_tSIMPINJ_SAVE_SETTINGS_RESPONSE *pThis);

extern int
LLRP_IMPINJ_SAVE_SETTINGS_RESPONSE_countCustom (
  LLRP_tSIMPINJ_SAVE_SETTINGS_RESPONSE *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_SAVE_SETTINGS_RESPONSE_addCustom (
  LLRP_tSIMPINJ_SAVE_SETTINGS_RESPONSE *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SIMPINJ_ADD_ENCODE_DATA_CACHE
{
    LLRP_tSMessage hdr;
  
  
    LLRP_tSImpinjEncodeDataCache * pImpinjEncodeDataCache;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdIMPINJ_ADD_ENCODE_DATA_CACHE;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdIMPINJ_ADD_ENCODE_DATA_CACHE[];

extern LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE *
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_construct (void);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_destruct (
 LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE * pThis);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_decodeFields (
 LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_assimilateSubParameters (
 LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_encode (
  const LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  

  
  
extern LLRP_tSImpinjEncodeDataCache *
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_getImpinjEncodeDataCache (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_setImpinjEncodeDataCache (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE *pThis,
  LLRP_tSImpinjEncodeDataCache *pValue);

extern LLRP_tSParameter *
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_beginCustom (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE *pThis);

extern LLRP_tSParameter *
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_clearCustom (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE *pThis);

extern int
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_countCustom (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_addCustom (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SIMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE
{
    LLRP_tSMessage hdr;
  
  
    LLRP_tSLLRPStatus * pLLRPStatus;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdIMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdIMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE[];

extern LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE *
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE_construct (void);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE_destruct (
 LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE * pThis);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE_decodeFields (
 LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE_assimilateSubParameters (
 LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE_encode (
  const LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  

  
  
extern LLRP_tSLLRPStatus *
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE_getLLRPStatus (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE_setLLRPStatus (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE *pThis,
  LLRP_tSLLRPStatus *pValue);

extern LLRP_tSParameter *
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE_beginCustom (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE *pThis);

extern LLRP_tSParameter *
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE_clearCustom (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE *pThis);

extern int
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE_countCustom (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE_addCustom (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA_CACHE_RESPONSE *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SIMPINJ_DELETE_ENCODE_DATA_CACHE
{
    LLRP_tSMessage hdr;
  
    llrp_u32_t EncodeDataCacheID;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdIMPINJ_DELETE_ENCODE_DATA_CACHE;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdIMPINJ_DELETE_ENCODE_DATA_CACHE[];

extern LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE *
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_construct (void);

extern void
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_destruct (
 LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE * pThis);

extern void
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_decodeFields (
 LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_assimilateSubParameters (
 LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_encode (
  const LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdIMPINJ_DELETE_ENCODE_DATA_CACHE_EncodeDataCacheID;

extern llrp_u32_t
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_getEncodeDataCacheID (
  LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_setEncodeDataCacheID (
  LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE *pThis,
  llrp_u32_t Value);

  
extern LLRP_tSParameter *
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_beginCustom (
  LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE *pThis);

extern LLRP_tSParameter *
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_clearCustom (
  LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE *pThis);

extern int
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_countCustom (
  LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_addCustom (
  LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SIMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE
{
    LLRP_tSMessage hdr;
  
  
    LLRP_tSLLRPStatus * pLLRPStatus;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdIMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdIMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE[];

extern LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE *
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE_construct (void);

extern void
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE_destruct (
 LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE * pThis);

extern void
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE_decodeFields (
 LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE_assimilateSubParameters (
 LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE_encode (
  const LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  

  
  
extern LLRP_tSLLRPStatus *
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE_getLLRPStatus (
  LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE_setLLRPStatus (
  LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE *pThis,
  LLRP_tSLLRPStatus *pValue);

extern LLRP_tSParameter *
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE_beginCustom (
  LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE *pThis);

extern LLRP_tSParameter *
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE_clearCustom (
  LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE *pThis);

extern int
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE_countCustom (
  LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE_addCustom (
  LLRP_tSIMPINJ_DELETE_ENCODE_DATA_CACHE_RESPONSE *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SIMPINJ_GET_ENCODE_DATA_CACHES
{
    LLRP_tSMessage hdr;
  
  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdIMPINJ_GET_ENCODE_DATA_CACHES;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdIMPINJ_GET_ENCODE_DATA_CACHES[];

extern LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES *
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_construct (void);

extern void
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_destruct (
 LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES * pThis);

extern void
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_decodeFields (
 LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_assimilateSubParameters (
 LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_encode (
  const LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  

  
  
extern LLRP_tSParameter *
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_beginCustom (
  LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES *pThis);

extern LLRP_tSParameter *
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_clearCustom (
  LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES *pThis);

extern int
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_countCustom (
  LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_addCustom (
  LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE
{
    LLRP_tSMessage hdr;
  
  
    LLRP_tSLLRPStatus * pLLRPStatus;

    LLRP_tSImpinjEncodeDataCache * listImpinjEncodeDataCache;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE[];

extern LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE *
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE_construct (void);

extern void
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE_destruct (
 LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE * pThis);

extern void
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE_decodeFields (
 LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE_assimilateSubParameters (
 LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE_encode (
  const LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  

  
  
extern LLRP_tSLLRPStatus *
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE_getLLRPStatus (
  LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE_setLLRPStatus (
  LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE *pThis,
  LLRP_tSLLRPStatus *pValue);

extern LLRP_tSImpinjEncodeDataCache *
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE_beginImpinjEncodeDataCache (
  LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE *pThis);

extern LLRP_tSImpinjEncodeDataCache *
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE_nextImpinjEncodeDataCache (
  LLRP_tSImpinjEncodeDataCache *pCurrent);

extern void
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE_clearImpinjEncodeDataCache (
  LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE *pThis);

extern int
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE_countImpinjEncodeDataCache (
  LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE_addImpinjEncodeDataCache (
  LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE *pThis,
  LLRP_tSImpinjEncodeDataCache *pValue);


extern LLRP_tSParameter *
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE_beginCustom (
  LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE *pThis);

extern LLRP_tSParameter *
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE_clearCustom (
  LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE *pThis);

extern int
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE_countCustom (
  LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE_addCustom (
  LLRP_tSIMPINJ_GET_ENCODE_DATA_CACHES_RESPONSE *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SIMPINJ_ADD_ENCODE_DATA
{
    LLRP_tSMessage hdr;
  
    llrp_u32_t EncodeDataCacheID;

  
    LLRP_tSImpinjEncodeData * listImpinjEncodeData;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdIMPINJ_ADD_ENCODE_DATA;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdIMPINJ_ADD_ENCODE_DATA[];

extern LLRP_tSIMPINJ_ADD_ENCODE_DATA *
LLRP_IMPINJ_ADD_ENCODE_DATA_construct (void);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_destruct (
 LLRP_tSIMPINJ_ADD_ENCODE_DATA * pThis);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_decodeFields (
 LLRP_tSIMPINJ_ADD_ENCODE_DATA * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_assimilateSubParameters (
 LLRP_tSIMPINJ_ADD_ENCODE_DATA * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_encode (
  const LLRP_tSIMPINJ_ADD_ENCODE_DATA *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdIMPINJ_ADD_ENCODE_DATA_EncodeDataCacheID;

extern llrp_u32_t
LLRP_IMPINJ_ADD_ENCODE_DATA_getEncodeDataCacheID (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_ADD_ENCODE_DATA_setEncodeDataCacheID (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA *pThis,
  llrp_u32_t Value);

  
extern LLRP_tSImpinjEncodeData *
LLRP_IMPINJ_ADD_ENCODE_DATA_beginImpinjEncodeData (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA *pThis);

extern LLRP_tSImpinjEncodeData *
LLRP_IMPINJ_ADD_ENCODE_DATA_nextImpinjEncodeData (
  LLRP_tSImpinjEncodeData *pCurrent);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_clearImpinjEncodeData (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA *pThis);

extern int
LLRP_IMPINJ_ADD_ENCODE_DATA_countImpinjEncodeData (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_ADD_ENCODE_DATA_addImpinjEncodeData (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA *pThis,
  LLRP_tSImpinjEncodeData *pValue);


extern LLRP_tSParameter *
LLRP_IMPINJ_ADD_ENCODE_DATA_beginCustom (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA *pThis);

extern LLRP_tSParameter *
LLRP_IMPINJ_ADD_ENCODE_DATA_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_clearCustom (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA *pThis);

extern int
LLRP_IMPINJ_ADD_ENCODE_DATA_countCustom (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_ADD_ENCODE_DATA_addCustom (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SIMPINJ_ADD_ENCODE_DATA_RESPONSE
{
    LLRP_tSMessage hdr;
  
  
    LLRP_tSLLRPStatus * pLLRPStatus;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdIMPINJ_ADD_ENCODE_DATA_RESPONSE;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdIMPINJ_ADD_ENCODE_DATA_RESPONSE[];

extern LLRP_tSIMPINJ_ADD_ENCODE_DATA_RESPONSE *
LLRP_IMPINJ_ADD_ENCODE_DATA_RESPONSE_construct (void);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_RESPONSE_destruct (
 LLRP_tSIMPINJ_ADD_ENCODE_DATA_RESPONSE * pThis);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_RESPONSE_decodeFields (
 LLRP_tSIMPINJ_ADD_ENCODE_DATA_RESPONSE * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_RESPONSE_assimilateSubParameters (
 LLRP_tSIMPINJ_ADD_ENCODE_DATA_RESPONSE * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_RESPONSE_encode (
  const LLRP_tSIMPINJ_ADD_ENCODE_DATA_RESPONSE *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  

  
  
extern LLRP_tSLLRPStatus *
LLRP_IMPINJ_ADD_ENCODE_DATA_RESPONSE_getLLRPStatus (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA_RESPONSE *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_ADD_ENCODE_DATA_RESPONSE_setLLRPStatus (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA_RESPONSE *pThis,
  LLRP_tSLLRPStatus *pValue);

extern LLRP_tSParameter *
LLRP_IMPINJ_ADD_ENCODE_DATA_RESPONSE_beginCustom (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA_RESPONSE *pThis);

extern LLRP_tSParameter *
LLRP_IMPINJ_ADD_ENCODE_DATA_RESPONSE_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_IMPINJ_ADD_ENCODE_DATA_RESPONSE_clearCustom (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA_RESPONSE *pThis);

extern int
LLRP_IMPINJ_ADD_ENCODE_DATA_RESPONSE_countCustom (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA_RESPONSE *pThis);

extern LLRP_tResultCode
LLRP_IMPINJ_ADD_ENCODE_DATA_RESPONSE_addCustom (
  LLRP_tSIMPINJ_ADD_ENCODE_DATA_RESPONSE *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjRequestedData
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjRequestedDataType eRequestedData;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjRequestedData;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjRequestedData[];

extern LLRP_tSImpinjRequestedData *
LLRP_ImpinjRequestedData_construct (void);

extern void
LLRP_ImpinjRequestedData_destruct (
 LLRP_tSImpinjRequestedData * pThis);

extern void
LLRP_ImpinjRequestedData_decodeFields (
 LLRP_tSImpinjRequestedData * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjRequestedData_assimilateSubParameters (
 LLRP_tSImpinjRequestedData * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjRequestedData_encode (
  const LLRP_tSImpinjRequestedData *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjRequestedData_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjRequestedData_RequestedData;

extern LLRP_tEImpinjRequestedDataType
LLRP_ImpinjRequestedData_getRequestedData (
  LLRP_tSImpinjRequestedData *pThis);

extern LLRP_tResultCode
LLRP_ImpinjRequestedData_setRequestedData (
  LLRP_tSImpinjRequestedData *pThis,
  LLRP_tEImpinjRequestedDataType Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjRequestedData_beginCustom (
  LLRP_tSImpinjRequestedData *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjRequestedData_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjRequestedData_clearCustom (
  LLRP_tSImpinjRequestedData *pThis);

extern int
LLRP_ImpinjRequestedData_countCustom (
  LLRP_tSImpinjRequestedData *pThis);

extern LLRP_tResultCode
LLRP_ImpinjRequestedData_addCustom (
  LLRP_tSImpinjRequestedData *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjSubRegulatoryRegion
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjRegulatoryRegion eRegulatoryRegion;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjSubRegulatoryRegion;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjSubRegulatoryRegion[];

extern LLRP_tSImpinjSubRegulatoryRegion *
LLRP_ImpinjSubRegulatoryRegion_construct (void);

extern void
LLRP_ImpinjSubRegulatoryRegion_destruct (
 LLRP_tSImpinjSubRegulatoryRegion * pThis);

extern void
LLRP_ImpinjSubRegulatoryRegion_decodeFields (
 LLRP_tSImpinjSubRegulatoryRegion * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjSubRegulatoryRegion_assimilateSubParameters (
 LLRP_tSImpinjSubRegulatoryRegion * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjSubRegulatoryRegion_encode (
  const LLRP_tSImpinjSubRegulatoryRegion *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjSubRegulatoryRegion_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjSubRegulatoryRegion_RegulatoryRegion;

extern LLRP_tEImpinjRegulatoryRegion
LLRP_ImpinjSubRegulatoryRegion_getRegulatoryRegion (
  LLRP_tSImpinjSubRegulatoryRegion *pThis);

extern LLRP_tResultCode
LLRP_ImpinjSubRegulatoryRegion_setRegulatoryRegion (
  LLRP_tSImpinjSubRegulatoryRegion *pThis,
  LLRP_tEImpinjRegulatoryRegion Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjSubRegulatoryRegion_beginCustom (
  LLRP_tSImpinjSubRegulatoryRegion *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjSubRegulatoryRegion_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjSubRegulatoryRegion_clearCustom (
  LLRP_tSImpinjSubRegulatoryRegion *pThis);

extern int
LLRP_ImpinjSubRegulatoryRegion_countCustom (
  LLRP_tSImpinjSubRegulatoryRegion *pThis);

extern LLRP_tResultCode
LLRP_ImpinjSubRegulatoryRegion_addCustom (
  LLRP_tSImpinjSubRegulatoryRegion *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjInventorySearchMode
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjInventorySearchType eInventorySearchMode;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjInventorySearchMode;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjInventorySearchMode[];

extern LLRP_tSImpinjInventorySearchMode *
LLRP_ImpinjInventorySearchMode_construct (void);

extern void
LLRP_ImpinjInventorySearchMode_destruct (
 LLRP_tSImpinjInventorySearchMode * pThis);

extern void
LLRP_ImpinjInventorySearchMode_decodeFields (
 LLRP_tSImpinjInventorySearchMode * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjInventorySearchMode_assimilateSubParameters (
 LLRP_tSImpinjInventorySearchMode * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjInventorySearchMode_encode (
  const LLRP_tSImpinjInventorySearchMode *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjInventorySearchMode_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjInventorySearchMode_InventorySearchMode;

extern LLRP_tEImpinjInventorySearchType
LLRP_ImpinjInventorySearchMode_getInventorySearchMode (
  LLRP_tSImpinjInventorySearchMode *pThis);

extern LLRP_tResultCode
LLRP_ImpinjInventorySearchMode_setInventorySearchMode (
  LLRP_tSImpinjInventorySearchMode *pThis,
  LLRP_tEImpinjInventorySearchType Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjInventorySearchMode_beginCustom (
  LLRP_tSImpinjInventorySearchMode *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjInventorySearchMode_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjInventorySearchMode_clearCustom (
  LLRP_tSImpinjInventorySearchMode *pThis);

extern int
LLRP_ImpinjInventorySearchMode_countCustom (
  LLRP_tSImpinjInventorySearchMode *pThis);

extern LLRP_tResultCode
LLRP_ImpinjInventorySearchMode_addCustom (
  LLRP_tSImpinjInventorySearchMode *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjTagDirectionReporting
{
    LLRP_tSParameter hdr;
  
    llrp_u1_t EnableTagDirection;

    LLRP_tEImpinjTagDirectionAntennaConfiguration eAntennaConfiguration;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjTagDirectionReporting;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjTagDirectionReporting[];

extern LLRP_tSImpinjTagDirectionReporting *
LLRP_ImpinjTagDirectionReporting_construct (void);

extern void
LLRP_ImpinjTagDirectionReporting_destruct (
 LLRP_tSImpinjTagDirectionReporting * pThis);

extern void
LLRP_ImpinjTagDirectionReporting_decodeFields (
 LLRP_tSImpinjTagDirectionReporting * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjTagDirectionReporting_assimilateSubParameters (
 LLRP_tSImpinjTagDirectionReporting * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjTagDirectionReporting_encode (
  const LLRP_tSImpinjTagDirectionReporting *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjTagDirectionReporting_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjTagDirectionReporting_EnableTagDirection;

extern llrp_u1_t
LLRP_ImpinjTagDirectionReporting_getEnableTagDirection (
  LLRP_tSImpinjTagDirectionReporting *pThis);

extern LLRP_tResultCode
LLRP_ImpinjTagDirectionReporting_setEnableTagDirection (
  LLRP_tSImpinjTagDirectionReporting *pThis,
  llrp_u1_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjTagDirectionReporting_AntennaConfiguration;

extern LLRP_tEImpinjTagDirectionAntennaConfiguration
LLRP_ImpinjTagDirectionReporting_getAntennaConfiguration (
  LLRP_tSImpinjTagDirectionReporting *pThis);

extern LLRP_tResultCode
LLRP_ImpinjTagDirectionReporting_setAntennaConfiguration (
  LLRP_tSImpinjTagDirectionReporting *pThis,
  LLRP_tEImpinjTagDirectionAntennaConfiguration Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjTagDirectionReporting_beginCustom (
  LLRP_tSImpinjTagDirectionReporting *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjTagDirectionReporting_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjTagDirectionReporting_clearCustom (
  LLRP_tSImpinjTagDirectionReporting *pThis);

extern int
LLRP_ImpinjTagDirectionReporting_countCustom (
  LLRP_tSImpinjTagDirectionReporting *pThis);

extern LLRP_tResultCode
LLRP_ImpinjTagDirectionReporting_addCustom (
  LLRP_tSImpinjTagDirectionReporting *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjTagDirection
{
    LLRP_tSParameter hdr;
  
    llrp_u64_t DecisionTimestamp;

    LLRP_tEImpinjDirection eTagDirection;

    llrp_u16_t Confidence;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjTagDirection;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjTagDirection[];

extern LLRP_tSImpinjTagDirection *
LLRP_ImpinjTagDirection_construct (void);

extern void
LLRP_ImpinjTagDirection_destruct (
 LLRP_tSImpinjTagDirection * pThis);

extern void
LLRP_ImpinjTagDirection_decodeFields (
 LLRP_tSImpinjTagDirection * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjTagDirection_assimilateSubParameters (
 LLRP_tSImpinjTagDirection * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjTagDirection_encode (
  const LLRP_tSImpinjTagDirection *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjTagDirection_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjTagDirection_DecisionTimestamp;

extern llrp_u64_t
LLRP_ImpinjTagDirection_getDecisionTimestamp (
  LLRP_tSImpinjTagDirection *pThis);

extern LLRP_tResultCode
LLRP_ImpinjTagDirection_setDecisionTimestamp (
  LLRP_tSImpinjTagDirection *pThis,
  llrp_u64_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjTagDirection_TagDirection;

extern LLRP_tEImpinjDirection
LLRP_ImpinjTagDirection_getTagDirection (
  LLRP_tSImpinjTagDirection *pThis);

extern LLRP_tResultCode
LLRP_ImpinjTagDirection_setTagDirection (
  LLRP_tSImpinjTagDirection *pThis,
  LLRP_tEImpinjDirection Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjTagDirection_Confidence;

extern llrp_u16_t
LLRP_ImpinjTagDirection_getConfidence (
  LLRP_tSImpinjTagDirection *pThis);

extern LLRP_tResultCode
LLRP_ImpinjTagDirection_setConfidence (
  LLRP_tSImpinjTagDirection *pThis,
  llrp_u16_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjTagDirection_beginCustom (
  LLRP_tSImpinjTagDirection *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjTagDirection_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjTagDirection_clearCustom (
  LLRP_tSImpinjTagDirection *pThis);

extern int
LLRP_ImpinjTagDirection_countCustom (
  LLRP_tSImpinjTagDirection *pThis);

extern LLRP_tResultCode
LLRP_ImpinjTagDirection_addCustom (
  LLRP_tSImpinjTagDirection *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjFixedFrequencyList
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjFixedFrequencyMode eFixedFrequencyMode;

    llrp_u16v_t ChannelList;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjFixedFrequencyList;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjFixedFrequencyList[];

extern LLRP_tSImpinjFixedFrequencyList *
LLRP_ImpinjFixedFrequencyList_construct (void);

extern void
LLRP_ImpinjFixedFrequencyList_destruct (
 LLRP_tSImpinjFixedFrequencyList * pThis);

extern void
LLRP_ImpinjFixedFrequencyList_decodeFields (
 LLRP_tSImpinjFixedFrequencyList * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjFixedFrequencyList_assimilateSubParameters (
 LLRP_tSImpinjFixedFrequencyList * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjFixedFrequencyList_encode (
  const LLRP_tSImpinjFixedFrequencyList *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjFixedFrequencyList_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjFixedFrequencyList_FixedFrequencyMode;

extern LLRP_tEImpinjFixedFrequencyMode
LLRP_ImpinjFixedFrequencyList_getFixedFrequencyMode (
  LLRP_tSImpinjFixedFrequencyList *pThis);

extern LLRP_tResultCode
LLRP_ImpinjFixedFrequencyList_setFixedFrequencyMode (
  LLRP_tSImpinjFixedFrequencyList *pThis,
  LLRP_tEImpinjFixedFrequencyMode Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjFixedFrequencyList_ChannelList;

extern llrp_u16v_t
LLRP_ImpinjFixedFrequencyList_getChannelList (
  LLRP_tSImpinjFixedFrequencyList *pThis);

extern LLRP_tResultCode
LLRP_ImpinjFixedFrequencyList_setChannelList (
  LLRP_tSImpinjFixedFrequencyList *pThis,
  llrp_u16v_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjFixedFrequencyList_beginCustom (
  LLRP_tSImpinjFixedFrequencyList *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjFixedFrequencyList_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjFixedFrequencyList_clearCustom (
  LLRP_tSImpinjFixedFrequencyList *pThis);

extern int
LLRP_ImpinjFixedFrequencyList_countCustom (
  LLRP_tSImpinjFixedFrequencyList *pThis);

extern LLRP_tResultCode
LLRP_ImpinjFixedFrequencyList_addCustom (
  LLRP_tSImpinjFixedFrequencyList *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjReducedPowerFrequencyList
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjReducedPowerMode eReducedPowerMode;

    llrp_u16v_t ChannelList;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjReducedPowerFrequencyList;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjReducedPowerFrequencyList[];

extern LLRP_tSImpinjReducedPowerFrequencyList *
LLRP_ImpinjReducedPowerFrequencyList_construct (void);

extern void
LLRP_ImpinjReducedPowerFrequencyList_destruct (
 LLRP_tSImpinjReducedPowerFrequencyList * pThis);

extern void
LLRP_ImpinjReducedPowerFrequencyList_decodeFields (
 LLRP_tSImpinjReducedPowerFrequencyList * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjReducedPowerFrequencyList_assimilateSubParameters (
 LLRP_tSImpinjReducedPowerFrequencyList * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjReducedPowerFrequencyList_encode (
  const LLRP_tSImpinjReducedPowerFrequencyList *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjReducedPowerFrequencyList_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjReducedPowerFrequencyList_ReducedPowerMode;

extern LLRP_tEImpinjReducedPowerMode
LLRP_ImpinjReducedPowerFrequencyList_getReducedPowerMode (
  LLRP_tSImpinjReducedPowerFrequencyList *pThis);

extern LLRP_tResultCode
LLRP_ImpinjReducedPowerFrequencyList_setReducedPowerMode (
  LLRP_tSImpinjReducedPowerFrequencyList *pThis,
  LLRP_tEImpinjReducedPowerMode Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjReducedPowerFrequencyList_ChannelList;

extern llrp_u16v_t
LLRP_ImpinjReducedPowerFrequencyList_getChannelList (
  LLRP_tSImpinjReducedPowerFrequencyList *pThis);

extern LLRP_tResultCode
LLRP_ImpinjReducedPowerFrequencyList_setChannelList (
  LLRP_tSImpinjReducedPowerFrequencyList *pThis,
  llrp_u16v_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjReducedPowerFrequencyList_beginCustom (
  LLRP_tSImpinjReducedPowerFrequencyList *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjReducedPowerFrequencyList_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjReducedPowerFrequencyList_clearCustom (
  LLRP_tSImpinjReducedPowerFrequencyList *pThis);

extern int
LLRP_ImpinjReducedPowerFrequencyList_countCustom (
  LLRP_tSImpinjReducedPowerFrequencyList *pThis);

extern LLRP_tResultCode
LLRP_ImpinjReducedPowerFrequencyList_addCustom (
  LLRP_tSImpinjReducedPowerFrequencyList *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjLowDutyCycle
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjLowDutyCycleMode eLowDutyCycleMode;

    llrp_u16_t EmptyFieldTimeout;

    llrp_u16_t FieldPingInterval;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjLowDutyCycle;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjLowDutyCycle[];

extern LLRP_tSImpinjLowDutyCycle *
LLRP_ImpinjLowDutyCycle_construct (void);

extern void
LLRP_ImpinjLowDutyCycle_destruct (
 LLRP_tSImpinjLowDutyCycle * pThis);

extern void
LLRP_ImpinjLowDutyCycle_decodeFields (
 LLRP_tSImpinjLowDutyCycle * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjLowDutyCycle_assimilateSubParameters (
 LLRP_tSImpinjLowDutyCycle * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjLowDutyCycle_encode (
  const LLRP_tSImpinjLowDutyCycle *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjLowDutyCycle_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjLowDutyCycle_LowDutyCycleMode;

extern LLRP_tEImpinjLowDutyCycleMode
LLRP_ImpinjLowDutyCycle_getLowDutyCycleMode (
  LLRP_tSImpinjLowDutyCycle *pThis);

extern LLRP_tResultCode
LLRP_ImpinjLowDutyCycle_setLowDutyCycleMode (
  LLRP_tSImpinjLowDutyCycle *pThis,
  LLRP_tEImpinjLowDutyCycleMode Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjLowDutyCycle_EmptyFieldTimeout;

extern llrp_u16_t
LLRP_ImpinjLowDutyCycle_getEmptyFieldTimeout (
  LLRP_tSImpinjLowDutyCycle *pThis);

extern LLRP_tResultCode
LLRP_ImpinjLowDutyCycle_setEmptyFieldTimeout (
  LLRP_tSImpinjLowDutyCycle *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjLowDutyCycle_FieldPingInterval;

extern llrp_u16_t
LLRP_ImpinjLowDutyCycle_getFieldPingInterval (
  LLRP_tSImpinjLowDutyCycle *pThis);

extern LLRP_tResultCode
LLRP_ImpinjLowDutyCycle_setFieldPingInterval (
  LLRP_tSImpinjLowDutyCycle *pThis,
  llrp_u16_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjLowDutyCycle_beginCustom (
  LLRP_tSImpinjLowDutyCycle *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjLowDutyCycle_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjLowDutyCycle_clearCustom (
  LLRP_tSImpinjLowDutyCycle *pThis);

extern int
LLRP_ImpinjLowDutyCycle_countCustom (
  LLRP_tSImpinjLowDutyCycle *pThis);

extern LLRP_tResultCode
LLRP_ImpinjLowDutyCycle_addCustom (
  LLRP_tSImpinjLowDutyCycle *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjDetailedVersion
{
    LLRP_tSParameter hdr;
  
    llrp_utf8v_t ModelName;

    llrp_utf8v_t SerialNumber;

    llrp_utf8v_t SoftwareVersion;

    llrp_utf8v_t FirmwareVersion;

    llrp_utf8v_t FPGAVersion;

    llrp_utf8v_t PCBAVersion;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjDetailedVersion;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjDetailedVersion[];

extern LLRP_tSImpinjDetailedVersion *
LLRP_ImpinjDetailedVersion_construct (void);

extern void
LLRP_ImpinjDetailedVersion_destruct (
 LLRP_tSImpinjDetailedVersion * pThis);

extern void
LLRP_ImpinjDetailedVersion_decodeFields (
 LLRP_tSImpinjDetailedVersion * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjDetailedVersion_assimilateSubParameters (
 LLRP_tSImpinjDetailedVersion * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjDetailedVersion_encode (
  const LLRP_tSImpinjDetailedVersion *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjDetailedVersion_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjDetailedVersion_ModelName;

extern llrp_utf8v_t
LLRP_ImpinjDetailedVersion_getModelName (
  LLRP_tSImpinjDetailedVersion *pThis);

extern LLRP_tResultCode
LLRP_ImpinjDetailedVersion_setModelName (
  LLRP_tSImpinjDetailedVersion *pThis,
  llrp_utf8v_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjDetailedVersion_SerialNumber;

extern llrp_utf8v_t
LLRP_ImpinjDetailedVersion_getSerialNumber (
  LLRP_tSImpinjDetailedVersion *pThis);

extern LLRP_tResultCode
LLRP_ImpinjDetailedVersion_setSerialNumber (
  LLRP_tSImpinjDetailedVersion *pThis,
  llrp_utf8v_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjDetailedVersion_SoftwareVersion;

extern llrp_utf8v_t
LLRP_ImpinjDetailedVersion_getSoftwareVersion (
  LLRP_tSImpinjDetailedVersion *pThis);

extern LLRP_tResultCode
LLRP_ImpinjDetailedVersion_setSoftwareVersion (
  LLRP_tSImpinjDetailedVersion *pThis,
  llrp_utf8v_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjDetailedVersion_FirmwareVersion;

extern llrp_utf8v_t
LLRP_ImpinjDetailedVersion_getFirmwareVersion (
  LLRP_tSImpinjDetailedVersion *pThis);

extern LLRP_tResultCode
LLRP_ImpinjDetailedVersion_setFirmwareVersion (
  LLRP_tSImpinjDetailedVersion *pThis,
  llrp_utf8v_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjDetailedVersion_FPGAVersion;

extern llrp_utf8v_t
LLRP_ImpinjDetailedVersion_getFPGAVersion (
  LLRP_tSImpinjDetailedVersion *pThis);

extern LLRP_tResultCode
LLRP_ImpinjDetailedVersion_setFPGAVersion (
  LLRP_tSImpinjDetailedVersion *pThis,
  llrp_utf8v_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjDetailedVersion_PCBAVersion;

extern llrp_utf8v_t
LLRP_ImpinjDetailedVersion_getPCBAVersion (
  LLRP_tSImpinjDetailedVersion *pThis);

extern LLRP_tResultCode
LLRP_ImpinjDetailedVersion_setPCBAVersion (
  LLRP_tSImpinjDetailedVersion *pThis,
  llrp_utf8v_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjDetailedVersion_beginCustom (
  LLRP_tSImpinjDetailedVersion *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjDetailedVersion_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjDetailedVersion_clearCustom (
  LLRP_tSImpinjDetailedVersion *pThis);

extern int
LLRP_ImpinjDetailedVersion_countCustom (
  LLRP_tSImpinjDetailedVersion *pThis);

extern LLRP_tResultCode
LLRP_ImpinjDetailedVersion_addCustom (
  LLRP_tSImpinjDetailedVersion *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjFrequencyCapabilities
{
    LLRP_tSParameter hdr;
  
    llrp_u32v_t FrequencyList;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjFrequencyCapabilities;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjFrequencyCapabilities[];

extern LLRP_tSImpinjFrequencyCapabilities *
LLRP_ImpinjFrequencyCapabilities_construct (void);

extern void
LLRP_ImpinjFrequencyCapabilities_destruct (
 LLRP_tSImpinjFrequencyCapabilities * pThis);

extern void
LLRP_ImpinjFrequencyCapabilities_decodeFields (
 LLRP_tSImpinjFrequencyCapabilities * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjFrequencyCapabilities_assimilateSubParameters (
 LLRP_tSImpinjFrequencyCapabilities * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjFrequencyCapabilities_encode (
  const LLRP_tSImpinjFrequencyCapabilities *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjFrequencyCapabilities_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjFrequencyCapabilities_FrequencyList;

extern llrp_u32v_t
LLRP_ImpinjFrequencyCapabilities_getFrequencyList (
  LLRP_tSImpinjFrequencyCapabilities *pThis);

extern LLRP_tResultCode
LLRP_ImpinjFrequencyCapabilities_setFrequencyList (
  LLRP_tSImpinjFrequencyCapabilities *pThis,
  llrp_u32v_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjFrequencyCapabilities_beginCustom (
  LLRP_tSImpinjFrequencyCapabilities *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjFrequencyCapabilities_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjFrequencyCapabilities_clearCustom (
  LLRP_tSImpinjFrequencyCapabilities *pThis);

extern int
LLRP_ImpinjFrequencyCapabilities_countCustom (
  LLRP_tSImpinjFrequencyCapabilities *pThis);

extern LLRP_tResultCode
LLRP_ImpinjFrequencyCapabilities_addCustom (
  LLRP_tSImpinjFrequencyCapabilities *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjTagInformation
{
    LLRP_tSParameter hdr;
  
  
    LLRP_tSEPCData * pEPCData;

    LLRP_tSImpinjTagDirection * pImpinjTagDirection;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjTagInformation;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjTagInformation[];

extern LLRP_tSImpinjTagInformation *
LLRP_ImpinjTagInformation_construct (void);

extern void
LLRP_ImpinjTagInformation_destruct (
 LLRP_tSImpinjTagInformation * pThis);

extern void
LLRP_ImpinjTagInformation_decodeFields (
 LLRP_tSImpinjTagInformation * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjTagInformation_assimilateSubParameters (
 LLRP_tSImpinjTagInformation * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjTagInformation_encode (
  const LLRP_tSImpinjTagInformation *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjTagInformation_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
  
extern LLRP_tSEPCData *
LLRP_ImpinjTagInformation_getEPCData (
  LLRP_tSImpinjTagInformation *pThis);

extern LLRP_tResultCode
LLRP_ImpinjTagInformation_setEPCData (
  LLRP_tSImpinjTagInformation *pThis,
  LLRP_tSEPCData *pValue);

extern LLRP_tSImpinjTagDirection *
LLRP_ImpinjTagInformation_getImpinjTagDirection (
  LLRP_tSImpinjTagInformation *pThis);

extern LLRP_tResultCode
LLRP_ImpinjTagInformation_setImpinjTagDirection (
  LLRP_tSImpinjTagInformation *pThis,
  LLRP_tSImpinjTagDirection *pValue);

extern LLRP_tSParameter *
LLRP_ImpinjTagInformation_beginCustom (
  LLRP_tSImpinjTagInformation *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjTagInformation_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjTagInformation_clearCustom (
  LLRP_tSImpinjTagInformation *pThis);

extern int
LLRP_ImpinjTagInformation_countCustom (
  LLRP_tSImpinjTagInformation *pThis);

extern LLRP_tResultCode
LLRP_ImpinjTagInformation_addCustom (
  LLRP_tSImpinjTagInformation *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjForkliftConfiguration
{
    LLRP_tSParameter hdr;
  
  
    LLRP_tSImpinjForkliftHeightThreshold * pImpinjForkliftHeightThreshold;

    LLRP_tSImpinjForkliftZeroMotionTimeThreshold * pImpinjForkliftZeroMotionTimeThreshold;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjForkliftConfiguration;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjForkliftConfiguration[];

extern LLRP_tSImpinjForkliftConfiguration *
LLRP_ImpinjForkliftConfiguration_construct (void);

extern void
LLRP_ImpinjForkliftConfiguration_destruct (
 LLRP_tSImpinjForkliftConfiguration * pThis);

extern void
LLRP_ImpinjForkliftConfiguration_decodeFields (
 LLRP_tSImpinjForkliftConfiguration * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjForkliftConfiguration_assimilateSubParameters (
 LLRP_tSImpinjForkliftConfiguration * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjForkliftConfiguration_encode (
  const LLRP_tSImpinjForkliftConfiguration *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjForkliftConfiguration_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
  
extern LLRP_tSImpinjForkliftHeightThreshold *
LLRP_ImpinjForkliftConfiguration_getImpinjForkliftHeightThreshold (
  LLRP_tSImpinjForkliftConfiguration *pThis);

extern LLRP_tResultCode
LLRP_ImpinjForkliftConfiguration_setImpinjForkliftHeightThreshold (
  LLRP_tSImpinjForkliftConfiguration *pThis,
  LLRP_tSImpinjForkliftHeightThreshold *pValue);

extern LLRP_tSImpinjForkliftZeroMotionTimeThreshold *
LLRP_ImpinjForkliftConfiguration_getImpinjForkliftZeroMotionTimeThreshold (
  LLRP_tSImpinjForkliftConfiguration *pThis);

extern LLRP_tResultCode
LLRP_ImpinjForkliftConfiguration_setImpinjForkliftZeroMotionTimeThreshold (
  LLRP_tSImpinjForkliftConfiguration *pThis,
  LLRP_tSImpinjForkliftZeroMotionTimeThreshold *pValue);

extern LLRP_tSParameter *
LLRP_ImpinjForkliftConfiguration_beginCustom (
  LLRP_tSImpinjForkliftConfiguration *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjForkliftConfiguration_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjForkliftConfiguration_clearCustom (
  LLRP_tSImpinjForkliftConfiguration *pThis);

extern int
LLRP_ImpinjForkliftConfiguration_countCustom (
  LLRP_tSImpinjForkliftConfiguration *pThis);

extern LLRP_tResultCode
LLRP_ImpinjForkliftConfiguration_addCustom (
  LLRP_tSImpinjForkliftConfiguration *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjForkliftHeightThreshold
{
    LLRP_tSParameter hdr;
  
    llrp_u16_t HeightThreshold;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjForkliftHeightThreshold;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjForkliftHeightThreshold[];

extern LLRP_tSImpinjForkliftHeightThreshold *
LLRP_ImpinjForkliftHeightThreshold_construct (void);

extern void
LLRP_ImpinjForkliftHeightThreshold_destruct (
 LLRP_tSImpinjForkliftHeightThreshold * pThis);

extern void
LLRP_ImpinjForkliftHeightThreshold_decodeFields (
 LLRP_tSImpinjForkliftHeightThreshold * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjForkliftHeightThreshold_assimilateSubParameters (
 LLRP_tSImpinjForkliftHeightThreshold * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjForkliftHeightThreshold_encode (
  const LLRP_tSImpinjForkliftHeightThreshold *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjForkliftHeightThreshold_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjForkliftHeightThreshold_HeightThreshold;

extern llrp_u16_t
LLRP_ImpinjForkliftHeightThreshold_getHeightThreshold (
  LLRP_tSImpinjForkliftHeightThreshold *pThis);

extern LLRP_tResultCode
LLRP_ImpinjForkliftHeightThreshold_setHeightThreshold (
  LLRP_tSImpinjForkliftHeightThreshold *pThis,
  llrp_u16_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjForkliftHeightThreshold_beginCustom (
  LLRP_tSImpinjForkliftHeightThreshold *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjForkliftHeightThreshold_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjForkliftHeightThreshold_clearCustom (
  LLRP_tSImpinjForkliftHeightThreshold *pThis);

extern int
LLRP_ImpinjForkliftHeightThreshold_countCustom (
  LLRP_tSImpinjForkliftHeightThreshold *pThis);

extern LLRP_tResultCode
LLRP_ImpinjForkliftHeightThreshold_addCustom (
  LLRP_tSImpinjForkliftHeightThreshold *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjForkliftZeroMotionTimeThreshold
{
    LLRP_tSParameter hdr;
  
    llrp_u16_t ZeroMotionTimeThreshold;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjForkliftZeroMotionTimeThreshold;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjForkliftZeroMotionTimeThreshold[];

extern LLRP_tSImpinjForkliftZeroMotionTimeThreshold *
LLRP_ImpinjForkliftZeroMotionTimeThreshold_construct (void);

extern void
LLRP_ImpinjForkliftZeroMotionTimeThreshold_destruct (
 LLRP_tSImpinjForkliftZeroMotionTimeThreshold * pThis);

extern void
LLRP_ImpinjForkliftZeroMotionTimeThreshold_decodeFields (
 LLRP_tSImpinjForkliftZeroMotionTimeThreshold * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjForkliftZeroMotionTimeThreshold_assimilateSubParameters (
 LLRP_tSImpinjForkliftZeroMotionTimeThreshold * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjForkliftZeroMotionTimeThreshold_encode (
  const LLRP_tSImpinjForkliftZeroMotionTimeThreshold *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjForkliftZeroMotionTimeThreshold_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjForkliftZeroMotionTimeThreshold_ZeroMotionTimeThreshold;

extern llrp_u16_t
LLRP_ImpinjForkliftZeroMotionTimeThreshold_getZeroMotionTimeThreshold (
  LLRP_tSImpinjForkliftZeroMotionTimeThreshold *pThis);

extern LLRP_tResultCode
LLRP_ImpinjForkliftZeroMotionTimeThreshold_setZeroMotionTimeThreshold (
  LLRP_tSImpinjForkliftZeroMotionTimeThreshold *pThis,
  llrp_u16_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjForkliftZeroMotionTimeThreshold_beginCustom (
  LLRP_tSImpinjForkliftZeroMotionTimeThreshold *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjForkliftZeroMotionTimeThreshold_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjForkliftZeroMotionTimeThreshold_clearCustom (
  LLRP_tSImpinjForkliftZeroMotionTimeThreshold *pThis);

extern int
LLRP_ImpinjForkliftZeroMotionTimeThreshold_countCustom (
  LLRP_tSImpinjForkliftZeroMotionTimeThreshold *pThis);

extern LLRP_tResultCode
LLRP_ImpinjForkliftZeroMotionTimeThreshold_addCustom (
  LLRP_tSImpinjForkliftZeroMotionTimeThreshold *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjForkliftCompanionBoardInfo
{
    LLRP_tSParameter hdr;
  
    llrp_utf8v_t BoardManufacturer;

    llrp_u8v_t FirmwareVersion;

    llrp_u8v_t HardwareVersion;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjForkliftCompanionBoardInfo;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjForkliftCompanionBoardInfo[];

extern LLRP_tSImpinjForkliftCompanionBoardInfo *
LLRP_ImpinjForkliftCompanionBoardInfo_construct (void);

extern void
LLRP_ImpinjForkliftCompanionBoardInfo_destruct (
 LLRP_tSImpinjForkliftCompanionBoardInfo * pThis);

extern void
LLRP_ImpinjForkliftCompanionBoardInfo_decodeFields (
 LLRP_tSImpinjForkliftCompanionBoardInfo * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjForkliftCompanionBoardInfo_assimilateSubParameters (
 LLRP_tSImpinjForkliftCompanionBoardInfo * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjForkliftCompanionBoardInfo_encode (
  const LLRP_tSImpinjForkliftCompanionBoardInfo *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjForkliftCompanionBoardInfo_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjForkliftCompanionBoardInfo_BoardManufacturer;

extern llrp_utf8v_t
LLRP_ImpinjForkliftCompanionBoardInfo_getBoardManufacturer (
  LLRP_tSImpinjForkliftCompanionBoardInfo *pThis);

extern LLRP_tResultCode
LLRP_ImpinjForkliftCompanionBoardInfo_setBoardManufacturer (
  LLRP_tSImpinjForkliftCompanionBoardInfo *pThis,
  llrp_utf8v_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjForkliftCompanionBoardInfo_FirmwareVersion;

extern llrp_u8v_t
LLRP_ImpinjForkliftCompanionBoardInfo_getFirmwareVersion (
  LLRP_tSImpinjForkliftCompanionBoardInfo *pThis);

extern LLRP_tResultCode
LLRP_ImpinjForkliftCompanionBoardInfo_setFirmwareVersion (
  LLRP_tSImpinjForkliftCompanionBoardInfo *pThis,
  llrp_u8v_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjForkliftCompanionBoardInfo_HardwareVersion;

extern llrp_u8v_t
LLRP_ImpinjForkliftCompanionBoardInfo_getHardwareVersion (
  LLRP_tSImpinjForkliftCompanionBoardInfo *pThis);

extern LLRP_tResultCode
LLRP_ImpinjForkliftCompanionBoardInfo_setHardwareVersion (
  LLRP_tSImpinjForkliftCompanionBoardInfo *pThis,
  llrp_u8v_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjForkliftCompanionBoardInfo_beginCustom (
  LLRP_tSImpinjForkliftCompanionBoardInfo *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjForkliftCompanionBoardInfo_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjForkliftCompanionBoardInfo_clearCustom (
  LLRP_tSImpinjForkliftCompanionBoardInfo *pThis);

extern int
LLRP_ImpinjForkliftCompanionBoardInfo_countCustom (
  LLRP_tSImpinjForkliftCompanionBoardInfo *pThis);

extern LLRP_tResultCode
LLRP_ImpinjForkliftCompanionBoardInfo_addCustom (
  LLRP_tSImpinjForkliftCompanionBoardInfo *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjGPIDebounceConfiguration
{
    LLRP_tSParameter hdr;
  
    llrp_u16_t GPIPortNum;

    llrp_u32_t GPIDebounceTimerMSec;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjGPIDebounceConfiguration;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjGPIDebounceConfiguration[];

extern LLRP_tSImpinjGPIDebounceConfiguration *
LLRP_ImpinjGPIDebounceConfiguration_construct (void);

extern void
LLRP_ImpinjGPIDebounceConfiguration_destruct (
 LLRP_tSImpinjGPIDebounceConfiguration * pThis);

extern void
LLRP_ImpinjGPIDebounceConfiguration_decodeFields (
 LLRP_tSImpinjGPIDebounceConfiguration * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjGPIDebounceConfiguration_assimilateSubParameters (
 LLRP_tSImpinjGPIDebounceConfiguration * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjGPIDebounceConfiguration_encode (
  const LLRP_tSImpinjGPIDebounceConfiguration *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjGPIDebounceConfiguration_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjGPIDebounceConfiguration_GPIPortNum;

extern llrp_u16_t
LLRP_ImpinjGPIDebounceConfiguration_getGPIPortNum (
  LLRP_tSImpinjGPIDebounceConfiguration *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGPIDebounceConfiguration_setGPIPortNum (
  LLRP_tSImpinjGPIDebounceConfiguration *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjGPIDebounceConfiguration_GPIDebounceTimerMSec;

extern llrp_u32_t
LLRP_ImpinjGPIDebounceConfiguration_getGPIDebounceTimerMSec (
  LLRP_tSImpinjGPIDebounceConfiguration *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGPIDebounceConfiguration_setGPIDebounceTimerMSec (
  LLRP_tSImpinjGPIDebounceConfiguration *pThis,
  llrp_u32_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjGPIDebounceConfiguration_beginCustom (
  LLRP_tSImpinjGPIDebounceConfiguration *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjGPIDebounceConfiguration_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjGPIDebounceConfiguration_clearCustom (
  LLRP_tSImpinjGPIDebounceConfiguration *pThis);

extern int
LLRP_ImpinjGPIDebounceConfiguration_countCustom (
  LLRP_tSImpinjGPIDebounceConfiguration *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGPIDebounceConfiguration_addCustom (
  LLRP_tSImpinjGPIDebounceConfiguration *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjReaderTemperature
{
    LLRP_tSParameter hdr;
  
    llrp_s16_t Temperature;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjReaderTemperature;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjReaderTemperature[];

extern LLRP_tSImpinjReaderTemperature *
LLRP_ImpinjReaderTemperature_construct (void);

extern void
LLRP_ImpinjReaderTemperature_destruct (
 LLRP_tSImpinjReaderTemperature * pThis);

extern void
LLRP_ImpinjReaderTemperature_decodeFields (
 LLRP_tSImpinjReaderTemperature * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjReaderTemperature_assimilateSubParameters (
 LLRP_tSImpinjReaderTemperature * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjReaderTemperature_encode (
  const LLRP_tSImpinjReaderTemperature *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjReaderTemperature_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjReaderTemperature_Temperature;

extern llrp_s16_t
LLRP_ImpinjReaderTemperature_getTemperature (
  LLRP_tSImpinjReaderTemperature *pThis);

extern LLRP_tResultCode
LLRP_ImpinjReaderTemperature_setTemperature (
  LLRP_tSImpinjReaderTemperature *pThis,
  llrp_s16_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjReaderTemperature_beginCustom (
  LLRP_tSImpinjReaderTemperature *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjReaderTemperature_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjReaderTemperature_clearCustom (
  LLRP_tSImpinjReaderTemperature *pThis);

extern int
LLRP_ImpinjReaderTemperature_countCustom (
  LLRP_tSImpinjReaderTemperature *pThis);

extern LLRP_tResultCode
LLRP_ImpinjReaderTemperature_addCustom (
  LLRP_tSImpinjReaderTemperature *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjLinkMonitorConfiguration
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjLinkMonitorMode eLinkMonitorMode;

    llrp_u16_t LinkDownThreshold;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjLinkMonitorConfiguration;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjLinkMonitorConfiguration[];

extern LLRP_tSImpinjLinkMonitorConfiguration *
LLRP_ImpinjLinkMonitorConfiguration_construct (void);

extern void
LLRP_ImpinjLinkMonitorConfiguration_destruct (
 LLRP_tSImpinjLinkMonitorConfiguration * pThis);

extern void
LLRP_ImpinjLinkMonitorConfiguration_decodeFields (
 LLRP_tSImpinjLinkMonitorConfiguration * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjLinkMonitorConfiguration_assimilateSubParameters (
 LLRP_tSImpinjLinkMonitorConfiguration * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjLinkMonitorConfiguration_encode (
  const LLRP_tSImpinjLinkMonitorConfiguration *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjLinkMonitorConfiguration_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjLinkMonitorConfiguration_LinkMonitorMode;

extern LLRP_tEImpinjLinkMonitorMode
LLRP_ImpinjLinkMonitorConfiguration_getLinkMonitorMode (
  LLRP_tSImpinjLinkMonitorConfiguration *pThis);

extern LLRP_tResultCode
LLRP_ImpinjLinkMonitorConfiguration_setLinkMonitorMode (
  LLRP_tSImpinjLinkMonitorConfiguration *pThis,
  LLRP_tEImpinjLinkMonitorMode Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjLinkMonitorConfiguration_LinkDownThreshold;

extern llrp_u16_t
LLRP_ImpinjLinkMonitorConfiguration_getLinkDownThreshold (
  LLRP_tSImpinjLinkMonitorConfiguration *pThis);

extern LLRP_tResultCode
LLRP_ImpinjLinkMonitorConfiguration_setLinkDownThreshold (
  LLRP_tSImpinjLinkMonitorConfiguration *pThis,
  llrp_u16_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjLinkMonitorConfiguration_beginCustom (
  LLRP_tSImpinjLinkMonitorConfiguration *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjLinkMonitorConfiguration_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjLinkMonitorConfiguration_clearCustom (
  LLRP_tSImpinjLinkMonitorConfiguration *pThis);

extern int
LLRP_ImpinjLinkMonitorConfiguration_countCustom (
  LLRP_tSImpinjLinkMonitorConfiguration *pThis);

extern LLRP_tResultCode
LLRP_ImpinjLinkMonitorConfiguration_addCustom (
  LLRP_tSImpinjLinkMonitorConfiguration *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjReportBufferConfiguration
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjReportBufferMode eReportBufferMode;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjReportBufferConfiguration;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjReportBufferConfiguration[];

extern LLRP_tSImpinjReportBufferConfiguration *
LLRP_ImpinjReportBufferConfiguration_construct (void);

extern void
LLRP_ImpinjReportBufferConfiguration_destruct (
 LLRP_tSImpinjReportBufferConfiguration * pThis);

extern void
LLRP_ImpinjReportBufferConfiguration_decodeFields (
 LLRP_tSImpinjReportBufferConfiguration * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjReportBufferConfiguration_assimilateSubParameters (
 LLRP_tSImpinjReportBufferConfiguration * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjReportBufferConfiguration_encode (
  const LLRP_tSImpinjReportBufferConfiguration *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjReportBufferConfiguration_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjReportBufferConfiguration_ReportBufferMode;

extern LLRP_tEImpinjReportBufferMode
LLRP_ImpinjReportBufferConfiguration_getReportBufferMode (
  LLRP_tSImpinjReportBufferConfiguration *pThis);

extern LLRP_tResultCode
LLRP_ImpinjReportBufferConfiguration_setReportBufferMode (
  LLRP_tSImpinjReportBufferConfiguration *pThis,
  LLRP_tEImpinjReportBufferMode Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjReportBufferConfiguration_beginCustom (
  LLRP_tSImpinjReportBufferConfiguration *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjReportBufferConfiguration_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjReportBufferConfiguration_clearCustom (
  LLRP_tSImpinjReportBufferConfiguration *pThis);

extern int
LLRP_ImpinjReportBufferConfiguration_countCustom (
  LLRP_tSImpinjReportBufferConfiguration *pThis);

extern LLRP_tResultCode
LLRP_ImpinjReportBufferConfiguration_addCustom (
  LLRP_tSImpinjReportBufferConfiguration *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjAccessSpecConfiguration
{
    LLRP_tSParameter hdr;
  
  
    LLRP_tSImpinjBlockWriteWordCount * pImpinjBlockWriteWordCount;

    LLRP_tSImpinjOpSpecRetryCount * pImpinjOpSpecRetryCount;

    LLRP_tSImpinjAccessSpecOrdering * pImpinjAccessSpecOrdering;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjAccessSpecConfiguration;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjAccessSpecConfiguration[];

extern LLRP_tSImpinjAccessSpecConfiguration *
LLRP_ImpinjAccessSpecConfiguration_construct (void);

extern void
LLRP_ImpinjAccessSpecConfiguration_destruct (
 LLRP_tSImpinjAccessSpecConfiguration * pThis);

extern void
LLRP_ImpinjAccessSpecConfiguration_decodeFields (
 LLRP_tSImpinjAccessSpecConfiguration * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjAccessSpecConfiguration_assimilateSubParameters (
 LLRP_tSImpinjAccessSpecConfiguration * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjAccessSpecConfiguration_encode (
  const LLRP_tSImpinjAccessSpecConfiguration *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjAccessSpecConfiguration_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
  
extern LLRP_tSImpinjBlockWriteWordCount *
LLRP_ImpinjAccessSpecConfiguration_getImpinjBlockWriteWordCount (
  LLRP_tSImpinjAccessSpecConfiguration *pThis);

extern LLRP_tResultCode
LLRP_ImpinjAccessSpecConfiguration_setImpinjBlockWriteWordCount (
  LLRP_tSImpinjAccessSpecConfiguration *pThis,
  LLRP_tSImpinjBlockWriteWordCount *pValue);

extern LLRP_tSImpinjOpSpecRetryCount *
LLRP_ImpinjAccessSpecConfiguration_getImpinjOpSpecRetryCount (
  LLRP_tSImpinjAccessSpecConfiguration *pThis);

extern LLRP_tResultCode
LLRP_ImpinjAccessSpecConfiguration_setImpinjOpSpecRetryCount (
  LLRP_tSImpinjAccessSpecConfiguration *pThis,
  LLRP_tSImpinjOpSpecRetryCount *pValue);

extern LLRP_tSImpinjAccessSpecOrdering *
LLRP_ImpinjAccessSpecConfiguration_getImpinjAccessSpecOrdering (
  LLRP_tSImpinjAccessSpecConfiguration *pThis);

extern LLRP_tResultCode
LLRP_ImpinjAccessSpecConfiguration_setImpinjAccessSpecOrdering (
  LLRP_tSImpinjAccessSpecConfiguration *pThis,
  LLRP_tSImpinjAccessSpecOrdering *pValue);

extern LLRP_tSParameter *
LLRP_ImpinjAccessSpecConfiguration_beginCustom (
  LLRP_tSImpinjAccessSpecConfiguration *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjAccessSpecConfiguration_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjAccessSpecConfiguration_clearCustom (
  LLRP_tSImpinjAccessSpecConfiguration *pThis);

extern int
LLRP_ImpinjAccessSpecConfiguration_countCustom (
  LLRP_tSImpinjAccessSpecConfiguration *pThis);

extern LLRP_tResultCode
LLRP_ImpinjAccessSpecConfiguration_addCustom (
  LLRP_tSImpinjAccessSpecConfiguration *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjBlockWriteWordCount
{
    LLRP_tSParameter hdr;
  
    llrp_u16_t WordCount;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjBlockWriteWordCount;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjBlockWriteWordCount[];

extern LLRP_tSImpinjBlockWriteWordCount *
LLRP_ImpinjBlockWriteWordCount_construct (void);

extern void
LLRP_ImpinjBlockWriteWordCount_destruct (
 LLRP_tSImpinjBlockWriteWordCount * pThis);

extern void
LLRP_ImpinjBlockWriteWordCount_decodeFields (
 LLRP_tSImpinjBlockWriteWordCount * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjBlockWriteWordCount_assimilateSubParameters (
 LLRP_tSImpinjBlockWriteWordCount * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjBlockWriteWordCount_encode (
  const LLRP_tSImpinjBlockWriteWordCount *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjBlockWriteWordCount_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjBlockWriteWordCount_WordCount;

extern llrp_u16_t
LLRP_ImpinjBlockWriteWordCount_getWordCount (
  LLRP_tSImpinjBlockWriteWordCount *pThis);

extern LLRP_tResultCode
LLRP_ImpinjBlockWriteWordCount_setWordCount (
  LLRP_tSImpinjBlockWriteWordCount *pThis,
  llrp_u16_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjBlockWriteWordCount_beginCustom (
  LLRP_tSImpinjBlockWriteWordCount *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjBlockWriteWordCount_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjBlockWriteWordCount_clearCustom (
  LLRP_tSImpinjBlockWriteWordCount *pThis);

extern int
LLRP_ImpinjBlockWriteWordCount_countCustom (
  LLRP_tSImpinjBlockWriteWordCount *pThis);

extern LLRP_tResultCode
LLRP_ImpinjBlockWriteWordCount_addCustom (
  LLRP_tSImpinjBlockWriteWordCount *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjBlockPermalock
{
    LLRP_tSParameter hdr;
  
    llrp_u16_t OpSpecID;

    llrp_u32_t AccessPassword;

    llrp_u2_t MB;

    llrp_u16_t BlockPointer;

    llrp_u16v_t BlockMask;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjBlockPermalock;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjBlockPermalock[];

extern LLRP_tSImpinjBlockPermalock *
LLRP_ImpinjBlockPermalock_construct (void);

extern void
LLRP_ImpinjBlockPermalock_destruct (
 LLRP_tSImpinjBlockPermalock * pThis);

extern void
LLRP_ImpinjBlockPermalock_decodeFields (
 LLRP_tSImpinjBlockPermalock * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjBlockPermalock_assimilateSubParameters (
 LLRP_tSImpinjBlockPermalock * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjBlockPermalock_encode (
  const LLRP_tSImpinjBlockPermalock *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjBlockPermalock_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjBlockPermalock_OpSpecID;

extern llrp_u16_t
LLRP_ImpinjBlockPermalock_getOpSpecID (
  LLRP_tSImpinjBlockPermalock *pThis);

extern LLRP_tResultCode
LLRP_ImpinjBlockPermalock_setOpSpecID (
  LLRP_tSImpinjBlockPermalock *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjBlockPermalock_AccessPassword;

extern llrp_u32_t
LLRP_ImpinjBlockPermalock_getAccessPassword (
  LLRP_tSImpinjBlockPermalock *pThis);

extern LLRP_tResultCode
LLRP_ImpinjBlockPermalock_setAccessPassword (
  LLRP_tSImpinjBlockPermalock *pThis,
  llrp_u32_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjBlockPermalock_MB;

extern llrp_u2_t
LLRP_ImpinjBlockPermalock_getMB (
  LLRP_tSImpinjBlockPermalock *pThis);

extern LLRP_tResultCode
LLRP_ImpinjBlockPermalock_setMB (
  LLRP_tSImpinjBlockPermalock *pThis,
  llrp_u2_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjBlockPermalock_BlockPointer;

extern llrp_u16_t
LLRP_ImpinjBlockPermalock_getBlockPointer (
  LLRP_tSImpinjBlockPermalock *pThis);

extern LLRP_tResultCode
LLRP_ImpinjBlockPermalock_setBlockPointer (
  LLRP_tSImpinjBlockPermalock *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjBlockPermalock_BlockMask;

extern llrp_u16v_t
LLRP_ImpinjBlockPermalock_getBlockMask (
  LLRP_tSImpinjBlockPermalock *pThis);

extern LLRP_tResultCode
LLRP_ImpinjBlockPermalock_setBlockMask (
  LLRP_tSImpinjBlockPermalock *pThis,
  llrp_u16v_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjBlockPermalock_beginCustom (
  LLRP_tSImpinjBlockPermalock *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjBlockPermalock_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjBlockPermalock_clearCustom (
  LLRP_tSImpinjBlockPermalock *pThis);

extern int
LLRP_ImpinjBlockPermalock_countCustom (
  LLRP_tSImpinjBlockPermalock *pThis);

extern LLRP_tResultCode
LLRP_ImpinjBlockPermalock_addCustom (
  LLRP_tSImpinjBlockPermalock *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjBlockPermalockOpSpecResult
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjBlockPermalockResultType eResult;

    llrp_u16_t OpSpecID;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjBlockPermalockOpSpecResult;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjBlockPermalockOpSpecResult[];

extern LLRP_tSImpinjBlockPermalockOpSpecResult *
LLRP_ImpinjBlockPermalockOpSpecResult_construct (void);

extern void
LLRP_ImpinjBlockPermalockOpSpecResult_destruct (
 LLRP_tSImpinjBlockPermalockOpSpecResult * pThis);

extern void
LLRP_ImpinjBlockPermalockOpSpecResult_decodeFields (
 LLRP_tSImpinjBlockPermalockOpSpecResult * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjBlockPermalockOpSpecResult_assimilateSubParameters (
 LLRP_tSImpinjBlockPermalockOpSpecResult * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjBlockPermalockOpSpecResult_encode (
  const LLRP_tSImpinjBlockPermalockOpSpecResult *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjBlockPermalockOpSpecResult_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjBlockPermalockOpSpecResult_Result;

extern LLRP_tEImpinjBlockPermalockResultType
LLRP_ImpinjBlockPermalockOpSpecResult_getResult (
  LLRP_tSImpinjBlockPermalockOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjBlockPermalockOpSpecResult_setResult (
  LLRP_tSImpinjBlockPermalockOpSpecResult *pThis,
  LLRP_tEImpinjBlockPermalockResultType Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjBlockPermalockOpSpecResult_OpSpecID;

extern llrp_u16_t
LLRP_ImpinjBlockPermalockOpSpecResult_getOpSpecID (
  LLRP_tSImpinjBlockPermalockOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjBlockPermalockOpSpecResult_setOpSpecID (
  LLRP_tSImpinjBlockPermalockOpSpecResult *pThis,
  llrp_u16_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjBlockPermalockOpSpecResult_beginCustom (
  LLRP_tSImpinjBlockPermalockOpSpecResult *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjBlockPermalockOpSpecResult_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjBlockPermalockOpSpecResult_clearCustom (
  LLRP_tSImpinjBlockPermalockOpSpecResult *pThis);

extern int
LLRP_ImpinjBlockPermalockOpSpecResult_countCustom (
  LLRP_tSImpinjBlockPermalockOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjBlockPermalockOpSpecResult_addCustom (
  LLRP_tSImpinjBlockPermalockOpSpecResult *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjGetBlockPermalockStatus
{
    LLRP_tSParameter hdr;
  
    llrp_u16_t OpSpecID;

    llrp_u32_t AccessPassword;

    llrp_u2_t MB;

    llrp_u16_t BlockPointer;

    llrp_u16_t BlockRange;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjGetBlockPermalockStatus;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjGetBlockPermalockStatus[];

extern LLRP_tSImpinjGetBlockPermalockStatus *
LLRP_ImpinjGetBlockPermalockStatus_construct (void);

extern void
LLRP_ImpinjGetBlockPermalockStatus_destruct (
 LLRP_tSImpinjGetBlockPermalockStatus * pThis);

extern void
LLRP_ImpinjGetBlockPermalockStatus_decodeFields (
 LLRP_tSImpinjGetBlockPermalockStatus * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjGetBlockPermalockStatus_assimilateSubParameters (
 LLRP_tSImpinjGetBlockPermalockStatus * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjGetBlockPermalockStatus_encode (
  const LLRP_tSImpinjGetBlockPermalockStatus *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjGetBlockPermalockStatus_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjGetBlockPermalockStatus_OpSpecID;

extern llrp_u16_t
LLRP_ImpinjGetBlockPermalockStatus_getOpSpecID (
  LLRP_tSImpinjGetBlockPermalockStatus *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGetBlockPermalockStatus_setOpSpecID (
  LLRP_tSImpinjGetBlockPermalockStatus *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjGetBlockPermalockStatus_AccessPassword;

extern llrp_u32_t
LLRP_ImpinjGetBlockPermalockStatus_getAccessPassword (
  LLRP_tSImpinjGetBlockPermalockStatus *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGetBlockPermalockStatus_setAccessPassword (
  LLRP_tSImpinjGetBlockPermalockStatus *pThis,
  llrp_u32_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjGetBlockPermalockStatus_MB;

extern llrp_u2_t
LLRP_ImpinjGetBlockPermalockStatus_getMB (
  LLRP_tSImpinjGetBlockPermalockStatus *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGetBlockPermalockStatus_setMB (
  LLRP_tSImpinjGetBlockPermalockStatus *pThis,
  llrp_u2_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjGetBlockPermalockStatus_BlockPointer;

extern llrp_u16_t
LLRP_ImpinjGetBlockPermalockStatus_getBlockPointer (
  LLRP_tSImpinjGetBlockPermalockStatus *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGetBlockPermalockStatus_setBlockPointer (
  LLRP_tSImpinjGetBlockPermalockStatus *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjGetBlockPermalockStatus_BlockRange;

extern llrp_u16_t
LLRP_ImpinjGetBlockPermalockStatus_getBlockRange (
  LLRP_tSImpinjGetBlockPermalockStatus *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGetBlockPermalockStatus_setBlockRange (
  LLRP_tSImpinjGetBlockPermalockStatus *pThis,
  llrp_u16_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjGetBlockPermalockStatus_beginCustom (
  LLRP_tSImpinjGetBlockPermalockStatus *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjGetBlockPermalockStatus_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjGetBlockPermalockStatus_clearCustom (
  LLRP_tSImpinjGetBlockPermalockStatus *pThis);

extern int
LLRP_ImpinjGetBlockPermalockStatus_countCustom (
  LLRP_tSImpinjGetBlockPermalockStatus *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGetBlockPermalockStatus_addCustom (
  LLRP_tSImpinjGetBlockPermalockStatus *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjGetBlockPermalockStatusOpSpecResult
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjGetBlockPermalockStatusResultType eResult;

    llrp_u16_t OpSpecID;

    llrp_u16v_t PermalockStatus;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjGetBlockPermalockStatusOpSpecResult;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjGetBlockPermalockStatusOpSpecResult[];

extern LLRP_tSImpinjGetBlockPermalockStatusOpSpecResult *
LLRP_ImpinjGetBlockPermalockStatusOpSpecResult_construct (void);

extern void
LLRP_ImpinjGetBlockPermalockStatusOpSpecResult_destruct (
 LLRP_tSImpinjGetBlockPermalockStatusOpSpecResult * pThis);

extern void
LLRP_ImpinjGetBlockPermalockStatusOpSpecResult_decodeFields (
 LLRP_tSImpinjGetBlockPermalockStatusOpSpecResult * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjGetBlockPermalockStatusOpSpecResult_assimilateSubParameters (
 LLRP_tSImpinjGetBlockPermalockStatusOpSpecResult * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjGetBlockPermalockStatusOpSpecResult_encode (
  const LLRP_tSImpinjGetBlockPermalockStatusOpSpecResult *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjGetBlockPermalockStatusOpSpecResult_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjGetBlockPermalockStatusOpSpecResult_Result;

extern LLRP_tEImpinjGetBlockPermalockStatusResultType
LLRP_ImpinjGetBlockPermalockStatusOpSpecResult_getResult (
  LLRP_tSImpinjGetBlockPermalockStatusOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGetBlockPermalockStatusOpSpecResult_setResult (
  LLRP_tSImpinjGetBlockPermalockStatusOpSpecResult *pThis,
  LLRP_tEImpinjGetBlockPermalockStatusResultType Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjGetBlockPermalockStatusOpSpecResult_OpSpecID;

extern llrp_u16_t
LLRP_ImpinjGetBlockPermalockStatusOpSpecResult_getOpSpecID (
  LLRP_tSImpinjGetBlockPermalockStatusOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGetBlockPermalockStatusOpSpecResult_setOpSpecID (
  LLRP_tSImpinjGetBlockPermalockStatusOpSpecResult *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjGetBlockPermalockStatusOpSpecResult_PermalockStatus;

extern llrp_u16v_t
LLRP_ImpinjGetBlockPermalockStatusOpSpecResult_getPermalockStatus (
  LLRP_tSImpinjGetBlockPermalockStatusOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGetBlockPermalockStatusOpSpecResult_setPermalockStatus (
  LLRP_tSImpinjGetBlockPermalockStatusOpSpecResult *pThis,
  llrp_u16v_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjGetBlockPermalockStatusOpSpecResult_beginCustom (
  LLRP_tSImpinjGetBlockPermalockStatusOpSpecResult *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjGetBlockPermalockStatusOpSpecResult_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjGetBlockPermalockStatusOpSpecResult_clearCustom (
  LLRP_tSImpinjGetBlockPermalockStatusOpSpecResult *pThis);

extern int
LLRP_ImpinjGetBlockPermalockStatusOpSpecResult_countCustom (
  LLRP_tSImpinjGetBlockPermalockStatusOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGetBlockPermalockStatusOpSpecResult_addCustom (
  LLRP_tSImpinjGetBlockPermalockStatusOpSpecResult *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjSetQTConfig
{
    LLRP_tSParameter hdr;
  
    llrp_u16_t OpSpecID;

    llrp_u32_t AccessPassword;

    LLRP_tEImpinjQTDataProfile eDataProfile;

    LLRP_tEImpinjQTAccessRange eAccessRange;

    LLRP_tEImpinjQTPersistence ePersistence;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjSetQTConfig;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjSetQTConfig[];

extern LLRP_tSImpinjSetQTConfig *
LLRP_ImpinjSetQTConfig_construct (void);

extern void
LLRP_ImpinjSetQTConfig_destruct (
 LLRP_tSImpinjSetQTConfig * pThis);

extern void
LLRP_ImpinjSetQTConfig_decodeFields (
 LLRP_tSImpinjSetQTConfig * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjSetQTConfig_assimilateSubParameters (
 LLRP_tSImpinjSetQTConfig * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjSetQTConfig_encode (
  const LLRP_tSImpinjSetQTConfig *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjSetQTConfig_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjSetQTConfig_OpSpecID;

extern llrp_u16_t
LLRP_ImpinjSetQTConfig_getOpSpecID (
  LLRP_tSImpinjSetQTConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjSetQTConfig_setOpSpecID (
  LLRP_tSImpinjSetQTConfig *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjSetQTConfig_AccessPassword;

extern llrp_u32_t
LLRP_ImpinjSetQTConfig_getAccessPassword (
  LLRP_tSImpinjSetQTConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjSetQTConfig_setAccessPassword (
  LLRP_tSImpinjSetQTConfig *pThis,
  llrp_u32_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjSetQTConfig_DataProfile;

extern LLRP_tEImpinjQTDataProfile
LLRP_ImpinjSetQTConfig_getDataProfile (
  LLRP_tSImpinjSetQTConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjSetQTConfig_setDataProfile (
  LLRP_tSImpinjSetQTConfig *pThis,
  LLRP_tEImpinjQTDataProfile Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjSetQTConfig_AccessRange;

extern LLRP_tEImpinjQTAccessRange
LLRP_ImpinjSetQTConfig_getAccessRange (
  LLRP_tSImpinjSetQTConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjSetQTConfig_setAccessRange (
  LLRP_tSImpinjSetQTConfig *pThis,
  LLRP_tEImpinjQTAccessRange Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjSetQTConfig_Persistence;

extern LLRP_tEImpinjQTPersistence
LLRP_ImpinjSetQTConfig_getPersistence (
  LLRP_tSImpinjSetQTConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjSetQTConfig_setPersistence (
  LLRP_tSImpinjSetQTConfig *pThis,
  LLRP_tEImpinjQTPersistence Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjSetQTConfig_beginCustom (
  LLRP_tSImpinjSetQTConfig *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjSetQTConfig_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjSetQTConfig_clearCustom (
  LLRP_tSImpinjSetQTConfig *pThis);

extern int
LLRP_ImpinjSetQTConfig_countCustom (
  LLRP_tSImpinjSetQTConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjSetQTConfig_addCustom (
  LLRP_tSImpinjSetQTConfig *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjSetQTConfigOpSpecResult
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjSetQTConfigResultType eResult;

    llrp_u16_t OpSpecID;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjSetQTConfigOpSpecResult;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjSetQTConfigOpSpecResult[];

extern LLRP_tSImpinjSetQTConfigOpSpecResult *
LLRP_ImpinjSetQTConfigOpSpecResult_construct (void);

extern void
LLRP_ImpinjSetQTConfigOpSpecResult_destruct (
 LLRP_tSImpinjSetQTConfigOpSpecResult * pThis);

extern void
LLRP_ImpinjSetQTConfigOpSpecResult_decodeFields (
 LLRP_tSImpinjSetQTConfigOpSpecResult * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjSetQTConfigOpSpecResult_assimilateSubParameters (
 LLRP_tSImpinjSetQTConfigOpSpecResult * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjSetQTConfigOpSpecResult_encode (
  const LLRP_tSImpinjSetQTConfigOpSpecResult *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjSetQTConfigOpSpecResult_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjSetQTConfigOpSpecResult_Result;

extern LLRP_tEImpinjSetQTConfigResultType
LLRP_ImpinjSetQTConfigOpSpecResult_getResult (
  LLRP_tSImpinjSetQTConfigOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjSetQTConfigOpSpecResult_setResult (
  LLRP_tSImpinjSetQTConfigOpSpecResult *pThis,
  LLRP_tEImpinjSetQTConfigResultType Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjSetQTConfigOpSpecResult_OpSpecID;

extern llrp_u16_t
LLRP_ImpinjSetQTConfigOpSpecResult_getOpSpecID (
  LLRP_tSImpinjSetQTConfigOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjSetQTConfigOpSpecResult_setOpSpecID (
  LLRP_tSImpinjSetQTConfigOpSpecResult *pThis,
  llrp_u16_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjSetQTConfigOpSpecResult_beginCustom (
  LLRP_tSImpinjSetQTConfigOpSpecResult *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjSetQTConfigOpSpecResult_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjSetQTConfigOpSpecResult_clearCustom (
  LLRP_tSImpinjSetQTConfigOpSpecResult *pThis);

extern int
LLRP_ImpinjSetQTConfigOpSpecResult_countCustom (
  LLRP_tSImpinjSetQTConfigOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjSetQTConfigOpSpecResult_addCustom (
  LLRP_tSImpinjSetQTConfigOpSpecResult *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjGetQTConfig
{
    LLRP_tSParameter hdr;
  
    llrp_u16_t OpSpecID;

    llrp_u32_t AccessPassword;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjGetQTConfig;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjGetQTConfig[];

extern LLRP_tSImpinjGetQTConfig *
LLRP_ImpinjGetQTConfig_construct (void);

extern void
LLRP_ImpinjGetQTConfig_destruct (
 LLRP_tSImpinjGetQTConfig * pThis);

extern void
LLRP_ImpinjGetQTConfig_decodeFields (
 LLRP_tSImpinjGetQTConfig * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjGetQTConfig_assimilateSubParameters (
 LLRP_tSImpinjGetQTConfig * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjGetQTConfig_encode (
  const LLRP_tSImpinjGetQTConfig *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjGetQTConfig_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjGetQTConfig_OpSpecID;

extern llrp_u16_t
LLRP_ImpinjGetQTConfig_getOpSpecID (
  LLRP_tSImpinjGetQTConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGetQTConfig_setOpSpecID (
  LLRP_tSImpinjGetQTConfig *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjGetQTConfig_AccessPassword;

extern llrp_u32_t
LLRP_ImpinjGetQTConfig_getAccessPassword (
  LLRP_tSImpinjGetQTConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGetQTConfig_setAccessPassword (
  LLRP_tSImpinjGetQTConfig *pThis,
  llrp_u32_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjGetQTConfig_beginCustom (
  LLRP_tSImpinjGetQTConfig *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjGetQTConfig_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjGetQTConfig_clearCustom (
  LLRP_tSImpinjGetQTConfig *pThis);

extern int
LLRP_ImpinjGetQTConfig_countCustom (
  LLRP_tSImpinjGetQTConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGetQTConfig_addCustom (
  LLRP_tSImpinjGetQTConfig *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjGetQTConfigOpSpecResult
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjGetQTConfigResultType eResult;

    llrp_u16_t OpSpecID;

    LLRP_tEImpinjQTDataProfile eDataProfile;

    LLRP_tEImpinjQTAccessRange eAccessRange;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjGetQTConfigOpSpecResult;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjGetQTConfigOpSpecResult[];

extern LLRP_tSImpinjGetQTConfigOpSpecResult *
LLRP_ImpinjGetQTConfigOpSpecResult_construct (void);

extern void
LLRP_ImpinjGetQTConfigOpSpecResult_destruct (
 LLRP_tSImpinjGetQTConfigOpSpecResult * pThis);

extern void
LLRP_ImpinjGetQTConfigOpSpecResult_decodeFields (
 LLRP_tSImpinjGetQTConfigOpSpecResult * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjGetQTConfigOpSpecResult_assimilateSubParameters (
 LLRP_tSImpinjGetQTConfigOpSpecResult * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjGetQTConfigOpSpecResult_encode (
  const LLRP_tSImpinjGetQTConfigOpSpecResult *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjGetQTConfigOpSpecResult_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjGetQTConfigOpSpecResult_Result;

extern LLRP_tEImpinjGetQTConfigResultType
LLRP_ImpinjGetQTConfigOpSpecResult_getResult (
  LLRP_tSImpinjGetQTConfigOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGetQTConfigOpSpecResult_setResult (
  LLRP_tSImpinjGetQTConfigOpSpecResult *pThis,
  LLRP_tEImpinjGetQTConfigResultType Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjGetQTConfigOpSpecResult_OpSpecID;

extern llrp_u16_t
LLRP_ImpinjGetQTConfigOpSpecResult_getOpSpecID (
  LLRP_tSImpinjGetQTConfigOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGetQTConfigOpSpecResult_setOpSpecID (
  LLRP_tSImpinjGetQTConfigOpSpecResult *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjGetQTConfigOpSpecResult_DataProfile;

extern LLRP_tEImpinjQTDataProfile
LLRP_ImpinjGetQTConfigOpSpecResult_getDataProfile (
  LLRP_tSImpinjGetQTConfigOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGetQTConfigOpSpecResult_setDataProfile (
  LLRP_tSImpinjGetQTConfigOpSpecResult *pThis,
  LLRP_tEImpinjQTDataProfile Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjGetQTConfigOpSpecResult_AccessRange;

extern LLRP_tEImpinjQTAccessRange
LLRP_ImpinjGetQTConfigOpSpecResult_getAccessRange (
  LLRP_tSImpinjGetQTConfigOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGetQTConfigOpSpecResult_setAccessRange (
  LLRP_tSImpinjGetQTConfigOpSpecResult *pThis,
  LLRP_tEImpinjQTAccessRange Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjGetQTConfigOpSpecResult_beginCustom (
  LLRP_tSImpinjGetQTConfigOpSpecResult *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjGetQTConfigOpSpecResult_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjGetQTConfigOpSpecResult_clearCustom (
  LLRP_tSImpinjGetQTConfigOpSpecResult *pThis);

extern int
LLRP_ImpinjGetQTConfigOpSpecResult_countCustom (
  LLRP_tSImpinjGetQTConfigOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGetQTConfigOpSpecResult_addCustom (
  LLRP_tSImpinjGetQTConfigOpSpecResult *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjTagReportContentSelector
{
    LLRP_tSParameter hdr;
  
  
    LLRP_tSImpinjEnableSerializedTID * pImpinjEnableSerializedTID;

    LLRP_tSImpinjEnableRFPhaseAngle * pImpinjEnableRFPhaseAngle;

    LLRP_tSImpinjEnablePeakRSSI * pImpinjEnablePeakRSSI;

    LLRP_tSImpinjEnableGPSCoordinates * pImpinjEnableGPSCoordinates;

    LLRP_tSImpinjEnableOptimizedRead * pImpinjEnableOptimizedRead;

    LLRP_tSImpinjEnableRFDopplerFrequency * pImpinjEnableRFDopplerFrequency;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjTagReportContentSelector;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjTagReportContentSelector[];

extern LLRP_tSImpinjTagReportContentSelector *
LLRP_ImpinjTagReportContentSelector_construct (void);

extern void
LLRP_ImpinjTagReportContentSelector_destruct (
 LLRP_tSImpinjTagReportContentSelector * pThis);

extern void
LLRP_ImpinjTagReportContentSelector_decodeFields (
 LLRP_tSImpinjTagReportContentSelector * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjTagReportContentSelector_assimilateSubParameters (
 LLRP_tSImpinjTagReportContentSelector * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjTagReportContentSelector_encode (
  const LLRP_tSImpinjTagReportContentSelector *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjTagReportContentSelector_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
  
extern LLRP_tSImpinjEnableSerializedTID *
LLRP_ImpinjTagReportContentSelector_getImpinjEnableSerializedTID (
  LLRP_tSImpinjTagReportContentSelector *pThis);

extern LLRP_tResultCode
LLRP_ImpinjTagReportContentSelector_setImpinjEnableSerializedTID (
  LLRP_tSImpinjTagReportContentSelector *pThis,
  LLRP_tSImpinjEnableSerializedTID *pValue);

extern LLRP_tSImpinjEnableRFPhaseAngle *
LLRP_ImpinjTagReportContentSelector_getImpinjEnableRFPhaseAngle (
  LLRP_tSImpinjTagReportContentSelector *pThis);

extern LLRP_tResultCode
LLRP_ImpinjTagReportContentSelector_setImpinjEnableRFPhaseAngle (
  LLRP_tSImpinjTagReportContentSelector *pThis,
  LLRP_tSImpinjEnableRFPhaseAngle *pValue);

extern LLRP_tSImpinjEnablePeakRSSI *
LLRP_ImpinjTagReportContentSelector_getImpinjEnablePeakRSSI (
  LLRP_tSImpinjTagReportContentSelector *pThis);

extern LLRP_tResultCode
LLRP_ImpinjTagReportContentSelector_setImpinjEnablePeakRSSI (
  LLRP_tSImpinjTagReportContentSelector *pThis,
  LLRP_tSImpinjEnablePeakRSSI *pValue);

extern LLRP_tSImpinjEnableGPSCoordinates *
LLRP_ImpinjTagReportContentSelector_getImpinjEnableGPSCoordinates (
  LLRP_tSImpinjTagReportContentSelector *pThis);

extern LLRP_tResultCode
LLRP_ImpinjTagReportContentSelector_setImpinjEnableGPSCoordinates (
  LLRP_tSImpinjTagReportContentSelector *pThis,
  LLRP_tSImpinjEnableGPSCoordinates *pValue);

extern LLRP_tSImpinjEnableOptimizedRead *
LLRP_ImpinjTagReportContentSelector_getImpinjEnableOptimizedRead (
  LLRP_tSImpinjTagReportContentSelector *pThis);

extern LLRP_tResultCode
LLRP_ImpinjTagReportContentSelector_setImpinjEnableOptimizedRead (
  LLRP_tSImpinjTagReportContentSelector *pThis,
  LLRP_tSImpinjEnableOptimizedRead *pValue);

extern LLRP_tSImpinjEnableRFDopplerFrequency *
LLRP_ImpinjTagReportContentSelector_getImpinjEnableRFDopplerFrequency (
  LLRP_tSImpinjTagReportContentSelector *pThis);

extern LLRP_tResultCode
LLRP_ImpinjTagReportContentSelector_setImpinjEnableRFDopplerFrequency (
  LLRP_tSImpinjTagReportContentSelector *pThis,
  LLRP_tSImpinjEnableRFDopplerFrequency *pValue);

extern LLRP_tSParameter *
LLRP_ImpinjTagReportContentSelector_beginCustom (
  LLRP_tSImpinjTagReportContentSelector *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjTagReportContentSelector_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjTagReportContentSelector_clearCustom (
  LLRP_tSImpinjTagReportContentSelector *pThis);

extern int
LLRP_ImpinjTagReportContentSelector_countCustom (
  LLRP_tSImpinjTagReportContentSelector *pThis);

extern LLRP_tResultCode
LLRP_ImpinjTagReportContentSelector_addCustom (
  LLRP_tSImpinjTagReportContentSelector *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEnableSerializedTID
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjSerializedTIDMode eSerializedTIDMode;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEnableSerializedTID;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEnableSerializedTID[];

extern LLRP_tSImpinjEnableSerializedTID *
LLRP_ImpinjEnableSerializedTID_construct (void);

extern void
LLRP_ImpinjEnableSerializedTID_destruct (
 LLRP_tSImpinjEnableSerializedTID * pThis);

extern void
LLRP_ImpinjEnableSerializedTID_decodeFields (
 LLRP_tSImpinjEnableSerializedTID * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEnableSerializedTID_assimilateSubParameters (
 LLRP_tSImpinjEnableSerializedTID * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEnableSerializedTID_encode (
  const LLRP_tSImpinjEnableSerializedTID *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEnableSerializedTID_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEnableSerializedTID_SerializedTIDMode;

extern LLRP_tEImpinjSerializedTIDMode
LLRP_ImpinjEnableSerializedTID_getSerializedTIDMode (
  LLRP_tSImpinjEnableSerializedTID *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEnableSerializedTID_setSerializedTIDMode (
  LLRP_tSImpinjEnableSerializedTID *pThis,
  LLRP_tEImpinjSerializedTIDMode Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjEnableSerializedTID_beginCustom (
  LLRP_tSImpinjEnableSerializedTID *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEnableSerializedTID_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEnableSerializedTID_clearCustom (
  LLRP_tSImpinjEnableSerializedTID *pThis);

extern int
LLRP_ImpinjEnableSerializedTID_countCustom (
  LLRP_tSImpinjEnableSerializedTID *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEnableSerializedTID_addCustom (
  LLRP_tSImpinjEnableSerializedTID *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEnableRFPhaseAngle
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjRFPhaseAngleMode eRFPhaseAngleMode;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEnableRFPhaseAngle;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEnableRFPhaseAngle[];

extern LLRP_tSImpinjEnableRFPhaseAngle *
LLRP_ImpinjEnableRFPhaseAngle_construct (void);

extern void
LLRP_ImpinjEnableRFPhaseAngle_destruct (
 LLRP_tSImpinjEnableRFPhaseAngle * pThis);

extern void
LLRP_ImpinjEnableRFPhaseAngle_decodeFields (
 LLRP_tSImpinjEnableRFPhaseAngle * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEnableRFPhaseAngle_assimilateSubParameters (
 LLRP_tSImpinjEnableRFPhaseAngle * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEnableRFPhaseAngle_encode (
  const LLRP_tSImpinjEnableRFPhaseAngle *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEnableRFPhaseAngle_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEnableRFPhaseAngle_RFPhaseAngleMode;

extern LLRP_tEImpinjRFPhaseAngleMode
LLRP_ImpinjEnableRFPhaseAngle_getRFPhaseAngleMode (
  LLRP_tSImpinjEnableRFPhaseAngle *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEnableRFPhaseAngle_setRFPhaseAngleMode (
  LLRP_tSImpinjEnableRFPhaseAngle *pThis,
  LLRP_tEImpinjRFPhaseAngleMode Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjEnableRFPhaseAngle_beginCustom (
  LLRP_tSImpinjEnableRFPhaseAngle *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEnableRFPhaseAngle_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEnableRFPhaseAngle_clearCustom (
  LLRP_tSImpinjEnableRFPhaseAngle *pThis);

extern int
LLRP_ImpinjEnableRFPhaseAngle_countCustom (
  LLRP_tSImpinjEnableRFPhaseAngle *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEnableRFPhaseAngle_addCustom (
  LLRP_tSImpinjEnableRFPhaseAngle *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEnablePeakRSSI
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjPeakRSSIMode ePeakRSSIMode;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEnablePeakRSSI;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEnablePeakRSSI[];

extern LLRP_tSImpinjEnablePeakRSSI *
LLRP_ImpinjEnablePeakRSSI_construct (void);

extern void
LLRP_ImpinjEnablePeakRSSI_destruct (
 LLRP_tSImpinjEnablePeakRSSI * pThis);

extern void
LLRP_ImpinjEnablePeakRSSI_decodeFields (
 LLRP_tSImpinjEnablePeakRSSI * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEnablePeakRSSI_assimilateSubParameters (
 LLRP_tSImpinjEnablePeakRSSI * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEnablePeakRSSI_encode (
  const LLRP_tSImpinjEnablePeakRSSI *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEnablePeakRSSI_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEnablePeakRSSI_PeakRSSIMode;

extern LLRP_tEImpinjPeakRSSIMode
LLRP_ImpinjEnablePeakRSSI_getPeakRSSIMode (
  LLRP_tSImpinjEnablePeakRSSI *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEnablePeakRSSI_setPeakRSSIMode (
  LLRP_tSImpinjEnablePeakRSSI *pThis,
  LLRP_tEImpinjPeakRSSIMode Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjEnablePeakRSSI_beginCustom (
  LLRP_tSImpinjEnablePeakRSSI *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEnablePeakRSSI_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEnablePeakRSSI_clearCustom (
  LLRP_tSImpinjEnablePeakRSSI *pThis);

extern int
LLRP_ImpinjEnablePeakRSSI_countCustom (
  LLRP_tSImpinjEnablePeakRSSI *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEnablePeakRSSI_addCustom (
  LLRP_tSImpinjEnablePeakRSSI *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEnableGPSCoordinates
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjGPSCoordinatesMode eGPSCoordinatesMode;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEnableGPSCoordinates;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEnableGPSCoordinates[];

extern LLRP_tSImpinjEnableGPSCoordinates *
LLRP_ImpinjEnableGPSCoordinates_construct (void);

extern void
LLRP_ImpinjEnableGPSCoordinates_destruct (
 LLRP_tSImpinjEnableGPSCoordinates * pThis);

extern void
LLRP_ImpinjEnableGPSCoordinates_decodeFields (
 LLRP_tSImpinjEnableGPSCoordinates * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEnableGPSCoordinates_assimilateSubParameters (
 LLRP_tSImpinjEnableGPSCoordinates * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEnableGPSCoordinates_encode (
  const LLRP_tSImpinjEnableGPSCoordinates *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEnableGPSCoordinates_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEnableGPSCoordinates_GPSCoordinatesMode;

extern LLRP_tEImpinjGPSCoordinatesMode
LLRP_ImpinjEnableGPSCoordinates_getGPSCoordinatesMode (
  LLRP_tSImpinjEnableGPSCoordinates *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEnableGPSCoordinates_setGPSCoordinatesMode (
  LLRP_tSImpinjEnableGPSCoordinates *pThis,
  LLRP_tEImpinjGPSCoordinatesMode Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjEnableGPSCoordinates_beginCustom (
  LLRP_tSImpinjEnableGPSCoordinates *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEnableGPSCoordinates_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEnableGPSCoordinates_clearCustom (
  LLRP_tSImpinjEnableGPSCoordinates *pThis);

extern int
LLRP_ImpinjEnableGPSCoordinates_countCustom (
  LLRP_tSImpinjEnableGPSCoordinates *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEnableGPSCoordinates_addCustom (
  LLRP_tSImpinjEnableGPSCoordinates *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjSerializedTID
{
    LLRP_tSParameter hdr;
  
    llrp_u16v_t TID;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjSerializedTID;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjSerializedTID[];

extern LLRP_tSImpinjSerializedTID *
LLRP_ImpinjSerializedTID_construct (void);

extern void
LLRP_ImpinjSerializedTID_destruct (
 LLRP_tSImpinjSerializedTID * pThis);

extern void
LLRP_ImpinjSerializedTID_decodeFields (
 LLRP_tSImpinjSerializedTID * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjSerializedTID_assimilateSubParameters (
 LLRP_tSImpinjSerializedTID * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjSerializedTID_encode (
  const LLRP_tSImpinjSerializedTID *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjSerializedTID_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjSerializedTID_TID;

extern llrp_u16v_t
LLRP_ImpinjSerializedTID_getTID (
  LLRP_tSImpinjSerializedTID *pThis);

extern LLRP_tResultCode
LLRP_ImpinjSerializedTID_setTID (
  LLRP_tSImpinjSerializedTID *pThis,
  llrp_u16v_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjSerializedTID_beginCustom (
  LLRP_tSImpinjSerializedTID *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjSerializedTID_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjSerializedTID_clearCustom (
  LLRP_tSImpinjSerializedTID *pThis);

extern int
LLRP_ImpinjSerializedTID_countCustom (
  LLRP_tSImpinjSerializedTID *pThis);

extern LLRP_tResultCode
LLRP_ImpinjSerializedTID_addCustom (
  LLRP_tSImpinjSerializedTID *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjRFPhaseAngle
{
    LLRP_tSParameter hdr;
  
    llrp_u16_t PhaseAngle;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjRFPhaseAngle;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjRFPhaseAngle[];

extern LLRP_tSImpinjRFPhaseAngle *
LLRP_ImpinjRFPhaseAngle_construct (void);

extern void
LLRP_ImpinjRFPhaseAngle_destruct (
 LLRP_tSImpinjRFPhaseAngle * pThis);

extern void
LLRP_ImpinjRFPhaseAngle_decodeFields (
 LLRP_tSImpinjRFPhaseAngle * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjRFPhaseAngle_assimilateSubParameters (
 LLRP_tSImpinjRFPhaseAngle * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjRFPhaseAngle_encode (
  const LLRP_tSImpinjRFPhaseAngle *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjRFPhaseAngle_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjRFPhaseAngle_PhaseAngle;

extern llrp_u16_t
LLRP_ImpinjRFPhaseAngle_getPhaseAngle (
  LLRP_tSImpinjRFPhaseAngle *pThis);

extern LLRP_tResultCode
LLRP_ImpinjRFPhaseAngle_setPhaseAngle (
  LLRP_tSImpinjRFPhaseAngle *pThis,
  llrp_u16_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjRFPhaseAngle_beginCustom (
  LLRP_tSImpinjRFPhaseAngle *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjRFPhaseAngle_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjRFPhaseAngle_clearCustom (
  LLRP_tSImpinjRFPhaseAngle *pThis);

extern int
LLRP_ImpinjRFPhaseAngle_countCustom (
  LLRP_tSImpinjRFPhaseAngle *pThis);

extern LLRP_tResultCode
LLRP_ImpinjRFPhaseAngle_addCustom (
  LLRP_tSImpinjRFPhaseAngle *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjPeakRSSI
{
    LLRP_tSParameter hdr;
  
    llrp_s16_t RSSI;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjPeakRSSI;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjPeakRSSI[];

extern LLRP_tSImpinjPeakRSSI *
LLRP_ImpinjPeakRSSI_construct (void);

extern void
LLRP_ImpinjPeakRSSI_destruct (
 LLRP_tSImpinjPeakRSSI * pThis);

extern void
LLRP_ImpinjPeakRSSI_decodeFields (
 LLRP_tSImpinjPeakRSSI * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjPeakRSSI_assimilateSubParameters (
 LLRP_tSImpinjPeakRSSI * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjPeakRSSI_encode (
  const LLRP_tSImpinjPeakRSSI *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjPeakRSSI_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjPeakRSSI_RSSI;

extern llrp_s16_t
LLRP_ImpinjPeakRSSI_getRSSI (
  LLRP_tSImpinjPeakRSSI *pThis);

extern LLRP_tResultCode
LLRP_ImpinjPeakRSSI_setRSSI (
  LLRP_tSImpinjPeakRSSI *pThis,
  llrp_s16_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjPeakRSSI_beginCustom (
  LLRP_tSImpinjPeakRSSI *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjPeakRSSI_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjPeakRSSI_clearCustom (
  LLRP_tSImpinjPeakRSSI *pThis);

extern int
LLRP_ImpinjPeakRSSI_countCustom (
  LLRP_tSImpinjPeakRSSI *pThis);

extern LLRP_tResultCode
LLRP_ImpinjPeakRSSI_addCustom (
  LLRP_tSImpinjPeakRSSI *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjGPSCoordinates
{
    LLRP_tSParameter hdr;
  
    llrp_s32_t Latitude;

    llrp_s32_t Longitude;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjGPSCoordinates;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjGPSCoordinates[];

extern LLRP_tSImpinjGPSCoordinates *
LLRP_ImpinjGPSCoordinates_construct (void);

extern void
LLRP_ImpinjGPSCoordinates_destruct (
 LLRP_tSImpinjGPSCoordinates * pThis);

extern void
LLRP_ImpinjGPSCoordinates_decodeFields (
 LLRP_tSImpinjGPSCoordinates * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjGPSCoordinates_assimilateSubParameters (
 LLRP_tSImpinjGPSCoordinates * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjGPSCoordinates_encode (
  const LLRP_tSImpinjGPSCoordinates *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjGPSCoordinates_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjGPSCoordinates_Latitude;

extern llrp_s32_t
LLRP_ImpinjGPSCoordinates_getLatitude (
  LLRP_tSImpinjGPSCoordinates *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGPSCoordinates_setLatitude (
  LLRP_tSImpinjGPSCoordinates *pThis,
  llrp_s32_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjGPSCoordinates_Longitude;

extern llrp_s32_t
LLRP_ImpinjGPSCoordinates_getLongitude (
  LLRP_tSImpinjGPSCoordinates *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGPSCoordinates_setLongitude (
  LLRP_tSImpinjGPSCoordinates *pThis,
  llrp_s32_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjGPSCoordinates_beginCustom (
  LLRP_tSImpinjGPSCoordinates *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjGPSCoordinates_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjGPSCoordinates_clearCustom (
  LLRP_tSImpinjGPSCoordinates *pThis);

extern int
LLRP_ImpinjGPSCoordinates_countCustom (
  LLRP_tSImpinjGPSCoordinates *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGPSCoordinates_addCustom (
  LLRP_tSImpinjGPSCoordinates *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjLoopSpec
{
    LLRP_tSParameter hdr;
  
    llrp_u32_t LoopCount;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjLoopSpec;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjLoopSpec[];

extern LLRP_tSImpinjLoopSpec *
LLRP_ImpinjLoopSpec_construct (void);

extern void
LLRP_ImpinjLoopSpec_destruct (
 LLRP_tSImpinjLoopSpec * pThis);

extern void
LLRP_ImpinjLoopSpec_decodeFields (
 LLRP_tSImpinjLoopSpec * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjLoopSpec_assimilateSubParameters (
 LLRP_tSImpinjLoopSpec * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjLoopSpec_encode (
  const LLRP_tSImpinjLoopSpec *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjLoopSpec_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjLoopSpec_LoopCount;

extern llrp_u32_t
LLRP_ImpinjLoopSpec_getLoopCount (
  LLRP_tSImpinjLoopSpec *pThis);

extern LLRP_tResultCode
LLRP_ImpinjLoopSpec_setLoopCount (
  LLRP_tSImpinjLoopSpec *pThis,
  llrp_u32_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjLoopSpec_beginCustom (
  LLRP_tSImpinjLoopSpec *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjLoopSpec_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjLoopSpec_clearCustom (
  LLRP_tSImpinjLoopSpec *pThis);

extern int
LLRP_ImpinjLoopSpec_countCustom (
  LLRP_tSImpinjLoopSpec *pThis);

extern LLRP_tResultCode
LLRP_ImpinjLoopSpec_addCustom (
  LLRP_tSImpinjLoopSpec *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjGPSNMEASentences
{
    LLRP_tSParameter hdr;
  
  
    LLRP_tSImpinjGGASentence * pImpinjGGASentence;

    LLRP_tSImpinjRMCSentence * pImpinjRMCSentence;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjGPSNMEASentences;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjGPSNMEASentences[];

extern LLRP_tSImpinjGPSNMEASentences *
LLRP_ImpinjGPSNMEASentences_construct (void);

extern void
LLRP_ImpinjGPSNMEASentences_destruct (
 LLRP_tSImpinjGPSNMEASentences * pThis);

extern void
LLRP_ImpinjGPSNMEASentences_decodeFields (
 LLRP_tSImpinjGPSNMEASentences * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjGPSNMEASentences_assimilateSubParameters (
 LLRP_tSImpinjGPSNMEASentences * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjGPSNMEASentences_encode (
  const LLRP_tSImpinjGPSNMEASentences *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjGPSNMEASentences_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
  
extern LLRP_tSImpinjGGASentence *
LLRP_ImpinjGPSNMEASentences_getImpinjGGASentence (
  LLRP_tSImpinjGPSNMEASentences *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGPSNMEASentences_setImpinjGGASentence (
  LLRP_tSImpinjGPSNMEASentences *pThis,
  LLRP_tSImpinjGGASentence *pValue);

extern LLRP_tSImpinjRMCSentence *
LLRP_ImpinjGPSNMEASentences_getImpinjRMCSentence (
  LLRP_tSImpinjGPSNMEASentences *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGPSNMEASentences_setImpinjRMCSentence (
  LLRP_tSImpinjGPSNMEASentences *pThis,
  LLRP_tSImpinjRMCSentence *pValue);

extern LLRP_tSParameter *
LLRP_ImpinjGPSNMEASentences_beginCustom (
  LLRP_tSImpinjGPSNMEASentences *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjGPSNMEASentences_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjGPSNMEASentences_clearCustom (
  LLRP_tSImpinjGPSNMEASentences *pThis);

extern int
LLRP_ImpinjGPSNMEASentences_countCustom (
  LLRP_tSImpinjGPSNMEASentences *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGPSNMEASentences_addCustom (
  LLRP_tSImpinjGPSNMEASentences *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjGGASentence
{
    LLRP_tSParameter hdr;
  
    llrp_utf8v_t GGASentence;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjGGASentence;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjGGASentence[];

extern LLRP_tSImpinjGGASentence *
LLRP_ImpinjGGASentence_construct (void);

extern void
LLRP_ImpinjGGASentence_destruct (
 LLRP_tSImpinjGGASentence * pThis);

extern void
LLRP_ImpinjGGASentence_decodeFields (
 LLRP_tSImpinjGGASentence * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjGGASentence_assimilateSubParameters (
 LLRP_tSImpinjGGASentence * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjGGASentence_encode (
  const LLRP_tSImpinjGGASentence *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjGGASentence_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjGGASentence_GGASentence;

extern llrp_utf8v_t
LLRP_ImpinjGGASentence_getGGASentence (
  LLRP_tSImpinjGGASentence *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGGASentence_setGGASentence (
  LLRP_tSImpinjGGASentence *pThis,
  llrp_utf8v_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjGGASentence_beginCustom (
  LLRP_tSImpinjGGASentence *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjGGASentence_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjGGASentence_clearCustom (
  LLRP_tSImpinjGGASentence *pThis);

extern int
LLRP_ImpinjGGASentence_countCustom (
  LLRP_tSImpinjGGASentence *pThis);

extern LLRP_tResultCode
LLRP_ImpinjGGASentence_addCustom (
  LLRP_tSImpinjGGASentence *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjRMCSentence
{
    LLRP_tSParameter hdr;
  
    llrp_utf8v_t RMCSentence;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjRMCSentence;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjRMCSentence[];

extern LLRP_tSImpinjRMCSentence *
LLRP_ImpinjRMCSentence_construct (void);

extern void
LLRP_ImpinjRMCSentence_destruct (
 LLRP_tSImpinjRMCSentence * pThis);

extern void
LLRP_ImpinjRMCSentence_decodeFields (
 LLRP_tSImpinjRMCSentence * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjRMCSentence_assimilateSubParameters (
 LLRP_tSImpinjRMCSentence * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjRMCSentence_encode (
  const LLRP_tSImpinjRMCSentence *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjRMCSentence_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjRMCSentence_RMCSentence;

extern llrp_utf8v_t
LLRP_ImpinjRMCSentence_getRMCSentence (
  LLRP_tSImpinjRMCSentence *pThis);

extern LLRP_tResultCode
LLRP_ImpinjRMCSentence_setRMCSentence (
  LLRP_tSImpinjRMCSentence *pThis,
  llrp_utf8v_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjRMCSentence_beginCustom (
  LLRP_tSImpinjRMCSentence *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjRMCSentence_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjRMCSentence_clearCustom (
  LLRP_tSImpinjRMCSentence *pThis);

extern int
LLRP_ImpinjRMCSentence_countCustom (
  LLRP_tSImpinjRMCSentence *pThis);

extern LLRP_tResultCode
LLRP_ImpinjRMCSentence_addCustom (
  LLRP_tSImpinjRMCSentence *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjOpSpecRetryCount
{
    LLRP_tSParameter hdr;
  
    llrp_u16_t RetryCount;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjOpSpecRetryCount;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjOpSpecRetryCount[];

extern LLRP_tSImpinjOpSpecRetryCount *
LLRP_ImpinjOpSpecRetryCount_construct (void);

extern void
LLRP_ImpinjOpSpecRetryCount_destruct (
 LLRP_tSImpinjOpSpecRetryCount * pThis);

extern void
LLRP_ImpinjOpSpecRetryCount_decodeFields (
 LLRP_tSImpinjOpSpecRetryCount * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjOpSpecRetryCount_assimilateSubParameters (
 LLRP_tSImpinjOpSpecRetryCount * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjOpSpecRetryCount_encode (
  const LLRP_tSImpinjOpSpecRetryCount *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjOpSpecRetryCount_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjOpSpecRetryCount_RetryCount;

extern llrp_u16_t
LLRP_ImpinjOpSpecRetryCount_getRetryCount (
  LLRP_tSImpinjOpSpecRetryCount *pThis);

extern LLRP_tResultCode
LLRP_ImpinjOpSpecRetryCount_setRetryCount (
  LLRP_tSImpinjOpSpecRetryCount *pThis,
  llrp_u16_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjOpSpecRetryCount_beginCustom (
  LLRP_tSImpinjOpSpecRetryCount *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjOpSpecRetryCount_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjOpSpecRetryCount_clearCustom (
  LLRP_tSImpinjOpSpecRetryCount *pThis);

extern int
LLRP_ImpinjOpSpecRetryCount_countCustom (
  LLRP_tSImpinjOpSpecRetryCount *pThis);

extern LLRP_tResultCode
LLRP_ImpinjOpSpecRetryCount_addCustom (
  LLRP_tSImpinjOpSpecRetryCount *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjAdvancedGPOConfiguration
{
    LLRP_tSParameter hdr;
  
    llrp_u16_t GPOPortNum;

    LLRP_tEImpinjAdvancedGPOMode eGPOMode;

    llrp_u32_t GPOPulseDurationMSec;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjAdvancedGPOConfiguration;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjAdvancedGPOConfiguration[];

extern LLRP_tSImpinjAdvancedGPOConfiguration *
LLRP_ImpinjAdvancedGPOConfiguration_construct (void);

extern void
LLRP_ImpinjAdvancedGPOConfiguration_destruct (
 LLRP_tSImpinjAdvancedGPOConfiguration * pThis);

extern void
LLRP_ImpinjAdvancedGPOConfiguration_decodeFields (
 LLRP_tSImpinjAdvancedGPOConfiguration * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjAdvancedGPOConfiguration_assimilateSubParameters (
 LLRP_tSImpinjAdvancedGPOConfiguration * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjAdvancedGPOConfiguration_encode (
  const LLRP_tSImpinjAdvancedGPOConfiguration *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjAdvancedGPOConfiguration_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjAdvancedGPOConfiguration_GPOPortNum;

extern llrp_u16_t
LLRP_ImpinjAdvancedGPOConfiguration_getGPOPortNum (
  LLRP_tSImpinjAdvancedGPOConfiguration *pThis);

extern LLRP_tResultCode
LLRP_ImpinjAdvancedGPOConfiguration_setGPOPortNum (
  LLRP_tSImpinjAdvancedGPOConfiguration *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjAdvancedGPOConfiguration_GPOMode;

extern LLRP_tEImpinjAdvancedGPOMode
LLRP_ImpinjAdvancedGPOConfiguration_getGPOMode (
  LLRP_tSImpinjAdvancedGPOConfiguration *pThis);

extern LLRP_tResultCode
LLRP_ImpinjAdvancedGPOConfiguration_setGPOMode (
  LLRP_tSImpinjAdvancedGPOConfiguration *pThis,
  LLRP_tEImpinjAdvancedGPOMode Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjAdvancedGPOConfiguration_GPOPulseDurationMSec;

extern llrp_u32_t
LLRP_ImpinjAdvancedGPOConfiguration_getGPOPulseDurationMSec (
  LLRP_tSImpinjAdvancedGPOConfiguration *pThis);

extern LLRP_tResultCode
LLRP_ImpinjAdvancedGPOConfiguration_setGPOPulseDurationMSec (
  LLRP_tSImpinjAdvancedGPOConfiguration *pThis,
  llrp_u32_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjAdvancedGPOConfiguration_beginCustom (
  LLRP_tSImpinjAdvancedGPOConfiguration *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjAdvancedGPOConfiguration_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjAdvancedGPOConfiguration_clearCustom (
  LLRP_tSImpinjAdvancedGPOConfiguration *pThis);

extern int
LLRP_ImpinjAdvancedGPOConfiguration_countCustom (
  LLRP_tSImpinjAdvancedGPOConfiguration *pThis);

extern LLRP_tResultCode
LLRP_ImpinjAdvancedGPOConfiguration_addCustom (
  LLRP_tSImpinjAdvancedGPOConfiguration *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEnableOptimizedRead
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjOptimizedReadMode eOptimizedReadMode;

  
    LLRP_tSC1G2Read * listC1G2Read;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEnableOptimizedRead;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEnableOptimizedRead[];

extern LLRP_tSImpinjEnableOptimizedRead *
LLRP_ImpinjEnableOptimizedRead_construct (void);

extern void
LLRP_ImpinjEnableOptimizedRead_destruct (
 LLRP_tSImpinjEnableOptimizedRead * pThis);

extern void
LLRP_ImpinjEnableOptimizedRead_decodeFields (
 LLRP_tSImpinjEnableOptimizedRead * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEnableOptimizedRead_assimilateSubParameters (
 LLRP_tSImpinjEnableOptimizedRead * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEnableOptimizedRead_encode (
  const LLRP_tSImpinjEnableOptimizedRead *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEnableOptimizedRead_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEnableOptimizedRead_OptimizedReadMode;

extern LLRP_tEImpinjOptimizedReadMode
LLRP_ImpinjEnableOptimizedRead_getOptimizedReadMode (
  LLRP_tSImpinjEnableOptimizedRead *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEnableOptimizedRead_setOptimizedReadMode (
  LLRP_tSImpinjEnableOptimizedRead *pThis,
  LLRP_tEImpinjOptimizedReadMode Value);

  
extern LLRP_tSC1G2Read *
LLRP_ImpinjEnableOptimizedRead_beginC1G2Read (
  LLRP_tSImpinjEnableOptimizedRead *pThis);

extern LLRP_tSC1G2Read *
LLRP_ImpinjEnableOptimizedRead_nextC1G2Read (
  LLRP_tSC1G2Read *pCurrent);

extern void
LLRP_ImpinjEnableOptimizedRead_clearC1G2Read (
  LLRP_tSImpinjEnableOptimizedRead *pThis);

extern int
LLRP_ImpinjEnableOptimizedRead_countC1G2Read (
  LLRP_tSImpinjEnableOptimizedRead *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEnableOptimizedRead_addC1G2Read (
  LLRP_tSImpinjEnableOptimizedRead *pThis,
  LLRP_tSC1G2Read *pValue);


extern LLRP_tSParameter *
LLRP_ImpinjEnableOptimizedRead_beginCustom (
  LLRP_tSImpinjEnableOptimizedRead *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEnableOptimizedRead_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEnableOptimizedRead_clearCustom (
  LLRP_tSImpinjEnableOptimizedRead *pThis);

extern int
LLRP_ImpinjEnableOptimizedRead_countCustom (
  LLRP_tSImpinjEnableOptimizedRead *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEnableOptimizedRead_addCustom (
  LLRP_tSImpinjEnableOptimizedRead *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjAccessSpecOrdering
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjAccessSpecOrderingMode eOrderingMode;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjAccessSpecOrdering;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjAccessSpecOrdering[];

extern LLRP_tSImpinjAccessSpecOrdering *
LLRP_ImpinjAccessSpecOrdering_construct (void);

extern void
LLRP_ImpinjAccessSpecOrdering_destruct (
 LLRP_tSImpinjAccessSpecOrdering * pThis);

extern void
LLRP_ImpinjAccessSpecOrdering_decodeFields (
 LLRP_tSImpinjAccessSpecOrdering * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjAccessSpecOrdering_assimilateSubParameters (
 LLRP_tSImpinjAccessSpecOrdering * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjAccessSpecOrdering_encode (
  const LLRP_tSImpinjAccessSpecOrdering *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjAccessSpecOrdering_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjAccessSpecOrdering_OrderingMode;

extern LLRP_tEImpinjAccessSpecOrderingMode
LLRP_ImpinjAccessSpecOrdering_getOrderingMode (
  LLRP_tSImpinjAccessSpecOrdering *pThis);

extern LLRP_tResultCode
LLRP_ImpinjAccessSpecOrdering_setOrderingMode (
  LLRP_tSImpinjAccessSpecOrdering *pThis,
  LLRP_tEImpinjAccessSpecOrderingMode Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjAccessSpecOrdering_beginCustom (
  LLRP_tSImpinjAccessSpecOrdering *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjAccessSpecOrdering_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjAccessSpecOrdering_clearCustom (
  LLRP_tSImpinjAccessSpecOrdering *pThis);

extern int
LLRP_ImpinjAccessSpecOrdering_countCustom (
  LLRP_tSImpinjAccessSpecOrdering *pThis);

extern LLRP_tResultCode
LLRP_ImpinjAccessSpecOrdering_addCustom (
  LLRP_tSImpinjAccessSpecOrdering *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEnableRFDopplerFrequency
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjRFDopplerFrequencyMode eRFDopplerFrequencyMode;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEnableRFDopplerFrequency;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEnableRFDopplerFrequency[];

extern LLRP_tSImpinjEnableRFDopplerFrequency *
LLRP_ImpinjEnableRFDopplerFrequency_construct (void);

extern void
LLRP_ImpinjEnableRFDopplerFrequency_destruct (
 LLRP_tSImpinjEnableRFDopplerFrequency * pThis);

extern void
LLRP_ImpinjEnableRFDopplerFrequency_decodeFields (
 LLRP_tSImpinjEnableRFDopplerFrequency * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEnableRFDopplerFrequency_assimilateSubParameters (
 LLRP_tSImpinjEnableRFDopplerFrequency * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEnableRFDopplerFrequency_encode (
  const LLRP_tSImpinjEnableRFDopplerFrequency *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEnableRFDopplerFrequency_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEnableRFDopplerFrequency_RFDopplerFrequencyMode;

extern LLRP_tEImpinjRFDopplerFrequencyMode
LLRP_ImpinjEnableRFDopplerFrequency_getRFDopplerFrequencyMode (
  LLRP_tSImpinjEnableRFDopplerFrequency *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEnableRFDopplerFrequency_setRFDopplerFrequencyMode (
  LLRP_tSImpinjEnableRFDopplerFrequency *pThis,
  LLRP_tEImpinjRFDopplerFrequencyMode Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjEnableRFDopplerFrequency_beginCustom (
  LLRP_tSImpinjEnableRFDopplerFrequency *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEnableRFDopplerFrequency_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEnableRFDopplerFrequency_clearCustom (
  LLRP_tSImpinjEnableRFDopplerFrequency *pThis);

extern int
LLRP_ImpinjEnableRFDopplerFrequency_countCustom (
  LLRP_tSImpinjEnableRFDopplerFrequency *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEnableRFDopplerFrequency_addCustom (
  LLRP_tSImpinjEnableRFDopplerFrequency *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjRFDopplerFrequency
{
    LLRP_tSParameter hdr;
  
    llrp_s16_t DopplerFrequency;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjRFDopplerFrequency;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjRFDopplerFrequency[];

extern LLRP_tSImpinjRFDopplerFrequency *
LLRP_ImpinjRFDopplerFrequency_construct (void);

extern void
LLRP_ImpinjRFDopplerFrequency_destruct (
 LLRP_tSImpinjRFDopplerFrequency * pThis);

extern void
LLRP_ImpinjRFDopplerFrequency_decodeFields (
 LLRP_tSImpinjRFDopplerFrequency * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjRFDopplerFrequency_assimilateSubParameters (
 LLRP_tSImpinjRFDopplerFrequency * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjRFDopplerFrequency_encode (
  const LLRP_tSImpinjRFDopplerFrequency *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjRFDopplerFrequency_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjRFDopplerFrequency_DopplerFrequency;

extern llrp_s16_t
LLRP_ImpinjRFDopplerFrequency_getDopplerFrequency (
  LLRP_tSImpinjRFDopplerFrequency *pThis);

extern LLRP_tResultCode
LLRP_ImpinjRFDopplerFrequency_setDopplerFrequency (
  LLRP_tSImpinjRFDopplerFrequency *pThis,
  llrp_s16_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjRFDopplerFrequency_beginCustom (
  LLRP_tSImpinjRFDopplerFrequency *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjRFDopplerFrequency_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjRFDopplerFrequency_clearCustom (
  LLRP_tSImpinjRFDopplerFrequency *pThis);

extern int
LLRP_ImpinjRFDopplerFrequency_countCustom (
  LLRP_tSImpinjRFDopplerFrequency *pThis);

extern LLRP_tResultCode
LLRP_ImpinjRFDopplerFrequency_addCustom (
  LLRP_tSImpinjRFDopplerFrequency *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjSTPCapabilities
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjEncodeStatus eEncodeStatus;

  
    LLRP_tSImpinjTagIC * listImpinjTagIC;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjSTPCapabilities;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjSTPCapabilities[];

extern LLRP_tSImpinjSTPCapabilities *
LLRP_ImpinjSTPCapabilities_construct (void);

extern void
LLRP_ImpinjSTPCapabilities_destruct (
 LLRP_tSImpinjSTPCapabilities * pThis);

extern void
LLRP_ImpinjSTPCapabilities_decodeFields (
 LLRP_tSImpinjSTPCapabilities * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjSTPCapabilities_assimilateSubParameters (
 LLRP_tSImpinjSTPCapabilities * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjSTPCapabilities_encode (
  const LLRP_tSImpinjSTPCapabilities *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjSTPCapabilities_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjSTPCapabilities_EncodeStatus;

extern LLRP_tEImpinjEncodeStatus
LLRP_ImpinjSTPCapabilities_getEncodeStatus (
  LLRP_tSImpinjSTPCapabilities *pThis);

extern LLRP_tResultCode
LLRP_ImpinjSTPCapabilities_setEncodeStatus (
  LLRP_tSImpinjSTPCapabilities *pThis,
  LLRP_tEImpinjEncodeStatus Value);

  
extern LLRP_tSImpinjTagIC *
LLRP_ImpinjSTPCapabilities_beginImpinjTagIC (
  LLRP_tSImpinjSTPCapabilities *pThis);

extern LLRP_tSImpinjTagIC *
LLRP_ImpinjSTPCapabilities_nextImpinjTagIC (
  LLRP_tSImpinjTagIC *pCurrent);

extern void
LLRP_ImpinjSTPCapabilities_clearImpinjTagIC (
  LLRP_tSImpinjSTPCapabilities *pThis);

extern int
LLRP_ImpinjSTPCapabilities_countImpinjTagIC (
  LLRP_tSImpinjSTPCapabilities *pThis);

extern LLRP_tResultCode
LLRP_ImpinjSTPCapabilities_addImpinjTagIC (
  LLRP_tSImpinjSTPCapabilities *pThis,
  LLRP_tSImpinjTagIC *pValue);


extern LLRP_tSParameter *
LLRP_ImpinjSTPCapabilities_beginCustom (
  LLRP_tSImpinjSTPCapabilities *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjSTPCapabilities_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjSTPCapabilities_clearCustom (
  LLRP_tSImpinjSTPCapabilities *pThis);

extern int
LLRP_ImpinjSTPCapabilities_countCustom (
  LLRP_tSImpinjSTPCapabilities *pThis);

extern LLRP_tResultCode
LLRP_ImpinjSTPCapabilities_addCustom (
  LLRP_tSImpinjSTPCapabilities *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjTagIC
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjTagICType eType;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjTagIC;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjTagIC[];

extern LLRP_tSImpinjTagIC *
LLRP_ImpinjTagIC_construct (void);

extern void
LLRP_ImpinjTagIC_destruct (
 LLRP_tSImpinjTagIC * pThis);

extern void
LLRP_ImpinjTagIC_decodeFields (
 LLRP_tSImpinjTagIC * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjTagIC_assimilateSubParameters (
 LLRP_tSImpinjTagIC * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjTagIC_encode (
  const LLRP_tSImpinjTagIC *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjTagIC_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjTagIC_Type;

extern LLRP_tEImpinjTagICType
LLRP_ImpinjTagIC_getType (
  LLRP_tSImpinjTagIC *pThis);

extern LLRP_tResultCode
LLRP_ImpinjTagIC_setType (
  LLRP_tSImpinjTagIC *pThis,
  LLRP_tEImpinjTagICType Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjTagIC_beginCustom (
  LLRP_tSImpinjTagIC *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjTagIC_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjTagIC_clearCustom (
  LLRP_tSImpinjTagIC *pThis);

extern int
LLRP_ImpinjTagIC_countCustom (
  LLRP_tSImpinjTagIC *pThis);

extern LLRP_tResultCode
LLRP_ImpinjTagIC_addCustom (
  LLRP_tSImpinjTagIC *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEncodeDataCache
{
    LLRP_tSParameter hdr;
  
    llrp_u32_t EncodeDataCacheID;

    llrp_u16_t LowEncodeDataThreshold;

  
    LLRP_tSImpinjEncodeDataDefaults * pImpinjEncodeDataDefaults;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEncodeDataCache;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEncodeDataCache[];

extern LLRP_tSImpinjEncodeDataCache *
LLRP_ImpinjEncodeDataCache_construct (void);

extern void
LLRP_ImpinjEncodeDataCache_destruct (
 LLRP_tSImpinjEncodeDataCache * pThis);

extern void
LLRP_ImpinjEncodeDataCache_decodeFields (
 LLRP_tSImpinjEncodeDataCache * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEncodeDataCache_assimilateSubParameters (
 LLRP_tSImpinjEncodeDataCache * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEncodeDataCache_encode (
  const LLRP_tSImpinjEncodeDataCache *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEncodeDataCache_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataCache_EncodeDataCacheID;

extern llrp_u32_t
LLRP_ImpinjEncodeDataCache_getEncodeDataCacheID (
  LLRP_tSImpinjEncodeDataCache *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataCache_setEncodeDataCacheID (
  LLRP_tSImpinjEncodeDataCache *pThis,
  llrp_u32_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataCache_LowEncodeDataThreshold;

extern llrp_u16_t
LLRP_ImpinjEncodeDataCache_getLowEncodeDataThreshold (
  LLRP_tSImpinjEncodeDataCache *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataCache_setLowEncodeDataThreshold (
  LLRP_tSImpinjEncodeDataCache *pThis,
  llrp_u16_t Value);

  
extern LLRP_tSImpinjEncodeDataDefaults *
LLRP_ImpinjEncodeDataCache_getImpinjEncodeDataDefaults (
  LLRP_tSImpinjEncodeDataCache *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataCache_setImpinjEncodeDataDefaults (
  LLRP_tSImpinjEncodeDataCache *pThis,
  LLRP_tSImpinjEncodeDataDefaults *pValue);

extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataCache_beginCustom (
  LLRP_tSImpinjEncodeDataCache *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataCache_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEncodeDataCache_clearCustom (
  LLRP_tSImpinjEncodeDataCache *pThis);

extern int
LLRP_ImpinjEncodeDataCache_countCustom (
  LLRP_tSImpinjEncodeDataCache *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataCache_addCustom (
  LLRP_tSImpinjEncodeDataCache *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEncodeDataDefaults
{
    LLRP_tSParameter hdr;
  
  
    LLRP_tSImpinjEncodeDataPCBits * pImpinjEncodeDataPCBits;

    LLRP_tSImpinjEncodeDataAccessPassword * pImpinjEncodeDataAccessPassword;

    LLRP_tSImpinjEncodeDataKillPassword * pImpinjEncodeDataKillPassword;

    LLRP_tSImpinjEncodeDataUserMemory * pImpinjEncodeDataUserMemory;

    LLRP_tSImpinjEncodeDataAlternateEPC * pImpinjEncodeDataAlternateEPC;

    LLRP_tSImpinjEncodeDataQTConfig * pImpinjEncodeDataQTConfig;

    LLRP_tSImpinjEncodeDataLockConfig * pImpinjEncodeDataLockConfig;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEncodeDataDefaults;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEncodeDataDefaults[];

extern LLRP_tSImpinjEncodeDataDefaults *
LLRP_ImpinjEncodeDataDefaults_construct (void);

extern void
LLRP_ImpinjEncodeDataDefaults_destruct (
 LLRP_tSImpinjEncodeDataDefaults * pThis);

extern void
LLRP_ImpinjEncodeDataDefaults_decodeFields (
 LLRP_tSImpinjEncodeDataDefaults * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEncodeDataDefaults_assimilateSubParameters (
 LLRP_tSImpinjEncodeDataDefaults * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEncodeDataDefaults_encode (
  const LLRP_tSImpinjEncodeDataDefaults *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEncodeDataDefaults_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
  
extern LLRP_tSImpinjEncodeDataPCBits *
LLRP_ImpinjEncodeDataDefaults_getImpinjEncodeDataPCBits (
  LLRP_tSImpinjEncodeDataDefaults *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataDefaults_setImpinjEncodeDataPCBits (
  LLRP_tSImpinjEncodeDataDefaults *pThis,
  LLRP_tSImpinjEncodeDataPCBits *pValue);

extern LLRP_tSImpinjEncodeDataAccessPassword *
LLRP_ImpinjEncodeDataDefaults_getImpinjEncodeDataAccessPassword (
  LLRP_tSImpinjEncodeDataDefaults *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataDefaults_setImpinjEncodeDataAccessPassword (
  LLRP_tSImpinjEncodeDataDefaults *pThis,
  LLRP_tSImpinjEncodeDataAccessPassword *pValue);

extern LLRP_tSImpinjEncodeDataKillPassword *
LLRP_ImpinjEncodeDataDefaults_getImpinjEncodeDataKillPassword (
  LLRP_tSImpinjEncodeDataDefaults *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataDefaults_setImpinjEncodeDataKillPassword (
  LLRP_tSImpinjEncodeDataDefaults *pThis,
  LLRP_tSImpinjEncodeDataKillPassword *pValue);

extern LLRP_tSImpinjEncodeDataUserMemory *
LLRP_ImpinjEncodeDataDefaults_getImpinjEncodeDataUserMemory (
  LLRP_tSImpinjEncodeDataDefaults *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataDefaults_setImpinjEncodeDataUserMemory (
  LLRP_tSImpinjEncodeDataDefaults *pThis,
  LLRP_tSImpinjEncodeDataUserMemory *pValue);

extern LLRP_tSImpinjEncodeDataAlternateEPC *
LLRP_ImpinjEncodeDataDefaults_getImpinjEncodeDataAlternateEPC (
  LLRP_tSImpinjEncodeDataDefaults *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataDefaults_setImpinjEncodeDataAlternateEPC (
  LLRP_tSImpinjEncodeDataDefaults *pThis,
  LLRP_tSImpinjEncodeDataAlternateEPC *pValue);

extern LLRP_tSImpinjEncodeDataQTConfig *
LLRP_ImpinjEncodeDataDefaults_getImpinjEncodeDataQTConfig (
  LLRP_tSImpinjEncodeDataDefaults *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataDefaults_setImpinjEncodeDataQTConfig (
  LLRP_tSImpinjEncodeDataDefaults *pThis,
  LLRP_tSImpinjEncodeDataQTConfig *pValue);

extern LLRP_tSImpinjEncodeDataLockConfig *
LLRP_ImpinjEncodeDataDefaults_getImpinjEncodeDataLockConfig (
  LLRP_tSImpinjEncodeDataDefaults *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataDefaults_setImpinjEncodeDataLockConfig (
  LLRP_tSImpinjEncodeDataDefaults *pThis,
  LLRP_tSImpinjEncodeDataLockConfig *pValue);

extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataDefaults_beginCustom (
  LLRP_tSImpinjEncodeDataDefaults *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataDefaults_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEncodeDataDefaults_clearCustom (
  LLRP_tSImpinjEncodeDataDefaults *pThis);

extern int
LLRP_ImpinjEncodeDataDefaults_countCustom (
  LLRP_tSImpinjEncodeDataDefaults *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataDefaults_addCustom (
  LLRP_tSImpinjEncodeDataDefaults *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEncodeData
{
    LLRP_tSParameter hdr;
  
    llrp_u1v_t EPC;

  
    LLRP_tSImpinjEncodeDataPCBits * pImpinjEncodeDataPCBits;

    LLRP_tSImpinjEncodeDataAccessPassword * pImpinjEncodeDataAccessPassword;

    LLRP_tSImpinjEncodeDataKillPassword * pImpinjEncodeDataKillPassword;

    LLRP_tSImpinjEncodeDataUserMemory * pImpinjEncodeDataUserMemory;

    LLRP_tSImpinjEncodeDataAlternateEPC * pImpinjEncodeDataAlternateEPC;

    LLRP_tSImpinjEncodeDataQTConfig * pImpinjEncodeDataQTConfig;

    LLRP_tSImpinjEncodeDataLockConfig * pImpinjEncodeDataLockConfig;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEncodeData;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEncodeData[];

extern LLRP_tSImpinjEncodeData *
LLRP_ImpinjEncodeData_construct (void);

extern void
LLRP_ImpinjEncodeData_destruct (
 LLRP_tSImpinjEncodeData * pThis);

extern void
LLRP_ImpinjEncodeData_decodeFields (
 LLRP_tSImpinjEncodeData * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEncodeData_assimilateSubParameters (
 LLRP_tSImpinjEncodeData * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEncodeData_encode (
  const LLRP_tSImpinjEncodeData *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEncodeData_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeData_EPC;

extern llrp_u1v_t
LLRP_ImpinjEncodeData_getEPC (
  LLRP_tSImpinjEncodeData *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeData_setEPC (
  LLRP_tSImpinjEncodeData *pThis,
  llrp_u1v_t Value);

  
extern LLRP_tSImpinjEncodeDataPCBits *
LLRP_ImpinjEncodeData_getImpinjEncodeDataPCBits (
  LLRP_tSImpinjEncodeData *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeData_setImpinjEncodeDataPCBits (
  LLRP_tSImpinjEncodeData *pThis,
  LLRP_tSImpinjEncodeDataPCBits *pValue);

extern LLRP_tSImpinjEncodeDataAccessPassword *
LLRP_ImpinjEncodeData_getImpinjEncodeDataAccessPassword (
  LLRP_tSImpinjEncodeData *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeData_setImpinjEncodeDataAccessPassword (
  LLRP_tSImpinjEncodeData *pThis,
  LLRP_tSImpinjEncodeDataAccessPassword *pValue);

extern LLRP_tSImpinjEncodeDataKillPassword *
LLRP_ImpinjEncodeData_getImpinjEncodeDataKillPassword (
  LLRP_tSImpinjEncodeData *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeData_setImpinjEncodeDataKillPassword (
  LLRP_tSImpinjEncodeData *pThis,
  LLRP_tSImpinjEncodeDataKillPassword *pValue);

extern LLRP_tSImpinjEncodeDataUserMemory *
LLRP_ImpinjEncodeData_getImpinjEncodeDataUserMemory (
  LLRP_tSImpinjEncodeData *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeData_setImpinjEncodeDataUserMemory (
  LLRP_tSImpinjEncodeData *pThis,
  LLRP_tSImpinjEncodeDataUserMemory *pValue);

extern LLRP_tSImpinjEncodeDataAlternateEPC *
LLRP_ImpinjEncodeData_getImpinjEncodeDataAlternateEPC (
  LLRP_tSImpinjEncodeData *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeData_setImpinjEncodeDataAlternateEPC (
  LLRP_tSImpinjEncodeData *pThis,
  LLRP_tSImpinjEncodeDataAlternateEPC *pValue);

extern LLRP_tSImpinjEncodeDataQTConfig *
LLRP_ImpinjEncodeData_getImpinjEncodeDataQTConfig (
  LLRP_tSImpinjEncodeData *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeData_setImpinjEncodeDataQTConfig (
  LLRP_tSImpinjEncodeData *pThis,
  LLRP_tSImpinjEncodeDataQTConfig *pValue);

extern LLRP_tSImpinjEncodeDataLockConfig *
LLRP_ImpinjEncodeData_getImpinjEncodeDataLockConfig (
  LLRP_tSImpinjEncodeData *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeData_setImpinjEncodeDataLockConfig (
  LLRP_tSImpinjEncodeData *pThis,
  LLRP_tSImpinjEncodeDataLockConfig *pValue);

extern LLRP_tSParameter *
LLRP_ImpinjEncodeData_beginCustom (
  LLRP_tSImpinjEncodeData *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEncodeData_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEncodeData_clearCustom (
  LLRP_tSImpinjEncodeData *pThis);

extern int
LLRP_ImpinjEncodeData_countCustom (
  LLRP_tSImpinjEncodeData *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeData_addCustom (
  LLRP_tSImpinjEncodeData *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEncodeDataPCBits
{
    LLRP_tSParameter hdr;
  
    llrp_u16_t PCBits;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEncodeDataPCBits;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEncodeDataPCBits[];

extern LLRP_tSImpinjEncodeDataPCBits *
LLRP_ImpinjEncodeDataPCBits_construct (void);

extern void
LLRP_ImpinjEncodeDataPCBits_destruct (
 LLRP_tSImpinjEncodeDataPCBits * pThis);

extern void
LLRP_ImpinjEncodeDataPCBits_decodeFields (
 LLRP_tSImpinjEncodeDataPCBits * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEncodeDataPCBits_assimilateSubParameters (
 LLRP_tSImpinjEncodeDataPCBits * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEncodeDataPCBits_encode (
  const LLRP_tSImpinjEncodeDataPCBits *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEncodeDataPCBits_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataPCBits_PCBits;

extern llrp_u16_t
LLRP_ImpinjEncodeDataPCBits_getPCBits (
  LLRP_tSImpinjEncodeDataPCBits *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataPCBits_setPCBits (
  LLRP_tSImpinjEncodeDataPCBits *pThis,
  llrp_u16_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataPCBits_beginCustom (
  LLRP_tSImpinjEncodeDataPCBits *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataPCBits_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEncodeDataPCBits_clearCustom (
  LLRP_tSImpinjEncodeDataPCBits *pThis);

extern int
LLRP_ImpinjEncodeDataPCBits_countCustom (
  LLRP_tSImpinjEncodeDataPCBits *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataPCBits_addCustom (
  LLRP_tSImpinjEncodeDataPCBits *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEncodeDataAccessPassword
{
    LLRP_tSParameter hdr;
  
    llrp_u32_t AccessPassword;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEncodeDataAccessPassword;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEncodeDataAccessPassword[];

extern LLRP_tSImpinjEncodeDataAccessPassword *
LLRP_ImpinjEncodeDataAccessPassword_construct (void);

extern void
LLRP_ImpinjEncodeDataAccessPassword_destruct (
 LLRP_tSImpinjEncodeDataAccessPassword * pThis);

extern void
LLRP_ImpinjEncodeDataAccessPassword_decodeFields (
 LLRP_tSImpinjEncodeDataAccessPassword * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEncodeDataAccessPassword_assimilateSubParameters (
 LLRP_tSImpinjEncodeDataAccessPassword * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEncodeDataAccessPassword_encode (
  const LLRP_tSImpinjEncodeDataAccessPassword *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEncodeDataAccessPassword_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataAccessPassword_AccessPassword;

extern llrp_u32_t
LLRP_ImpinjEncodeDataAccessPassword_getAccessPassword (
  LLRP_tSImpinjEncodeDataAccessPassword *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataAccessPassword_setAccessPassword (
  LLRP_tSImpinjEncodeDataAccessPassword *pThis,
  llrp_u32_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataAccessPassword_beginCustom (
  LLRP_tSImpinjEncodeDataAccessPassword *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataAccessPassword_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEncodeDataAccessPassword_clearCustom (
  LLRP_tSImpinjEncodeDataAccessPassword *pThis);

extern int
LLRP_ImpinjEncodeDataAccessPassword_countCustom (
  LLRP_tSImpinjEncodeDataAccessPassword *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataAccessPassword_addCustom (
  LLRP_tSImpinjEncodeDataAccessPassword *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEncodeDataKillPassword
{
    LLRP_tSParameter hdr;
  
    llrp_u32_t KillPassword;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEncodeDataKillPassword;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEncodeDataKillPassword[];

extern LLRP_tSImpinjEncodeDataKillPassword *
LLRP_ImpinjEncodeDataKillPassword_construct (void);

extern void
LLRP_ImpinjEncodeDataKillPassword_destruct (
 LLRP_tSImpinjEncodeDataKillPassword * pThis);

extern void
LLRP_ImpinjEncodeDataKillPassword_decodeFields (
 LLRP_tSImpinjEncodeDataKillPassword * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEncodeDataKillPassword_assimilateSubParameters (
 LLRP_tSImpinjEncodeDataKillPassword * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEncodeDataKillPassword_encode (
  const LLRP_tSImpinjEncodeDataKillPassword *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEncodeDataKillPassword_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataKillPassword_KillPassword;

extern llrp_u32_t
LLRP_ImpinjEncodeDataKillPassword_getKillPassword (
  LLRP_tSImpinjEncodeDataKillPassword *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataKillPassword_setKillPassword (
  LLRP_tSImpinjEncodeDataKillPassword *pThis,
  llrp_u32_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataKillPassword_beginCustom (
  LLRP_tSImpinjEncodeDataKillPassword *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataKillPassword_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEncodeDataKillPassword_clearCustom (
  LLRP_tSImpinjEncodeDataKillPassword *pThis);

extern int
LLRP_ImpinjEncodeDataKillPassword_countCustom (
  LLRP_tSImpinjEncodeDataKillPassword *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataKillPassword_addCustom (
  LLRP_tSImpinjEncodeDataKillPassword *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEncodeDataUserMemory
{
    LLRP_tSParameter hdr;
  
    llrp_u16_t WordPointer;

    llrp_u16v_t WriteData;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEncodeDataUserMemory;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEncodeDataUserMemory[];

extern LLRP_tSImpinjEncodeDataUserMemory *
LLRP_ImpinjEncodeDataUserMemory_construct (void);

extern void
LLRP_ImpinjEncodeDataUserMemory_destruct (
 LLRP_tSImpinjEncodeDataUserMemory * pThis);

extern void
LLRP_ImpinjEncodeDataUserMemory_decodeFields (
 LLRP_tSImpinjEncodeDataUserMemory * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEncodeDataUserMemory_assimilateSubParameters (
 LLRP_tSImpinjEncodeDataUserMemory * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEncodeDataUserMemory_encode (
  const LLRP_tSImpinjEncodeDataUserMemory *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEncodeDataUserMemory_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataUserMemory_WordPointer;

extern llrp_u16_t
LLRP_ImpinjEncodeDataUserMemory_getWordPointer (
  LLRP_tSImpinjEncodeDataUserMemory *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataUserMemory_setWordPointer (
  LLRP_tSImpinjEncodeDataUserMemory *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataUserMemory_WriteData;

extern llrp_u16v_t
LLRP_ImpinjEncodeDataUserMemory_getWriteData (
  LLRP_tSImpinjEncodeDataUserMemory *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataUserMemory_setWriteData (
  LLRP_tSImpinjEncodeDataUserMemory *pThis,
  llrp_u16v_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataUserMemory_beginCustom (
  LLRP_tSImpinjEncodeDataUserMemory *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataUserMemory_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEncodeDataUserMemory_clearCustom (
  LLRP_tSImpinjEncodeDataUserMemory *pThis);

extern int
LLRP_ImpinjEncodeDataUserMemory_countCustom (
  LLRP_tSImpinjEncodeDataUserMemory *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataUserMemory_addCustom (
  LLRP_tSImpinjEncodeDataUserMemory *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEncodeDataAlternateEPC
{
    LLRP_tSParameter hdr;
  
    llrp_u16v_t AlternateEPC;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEncodeDataAlternateEPC;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEncodeDataAlternateEPC[];

extern LLRP_tSImpinjEncodeDataAlternateEPC *
LLRP_ImpinjEncodeDataAlternateEPC_construct (void);

extern void
LLRP_ImpinjEncodeDataAlternateEPC_destruct (
 LLRP_tSImpinjEncodeDataAlternateEPC * pThis);

extern void
LLRP_ImpinjEncodeDataAlternateEPC_decodeFields (
 LLRP_tSImpinjEncodeDataAlternateEPC * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEncodeDataAlternateEPC_assimilateSubParameters (
 LLRP_tSImpinjEncodeDataAlternateEPC * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEncodeDataAlternateEPC_encode (
  const LLRP_tSImpinjEncodeDataAlternateEPC *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEncodeDataAlternateEPC_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataAlternateEPC_AlternateEPC;

extern llrp_u16v_t
LLRP_ImpinjEncodeDataAlternateEPC_getAlternateEPC (
  LLRP_tSImpinjEncodeDataAlternateEPC *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataAlternateEPC_setAlternateEPC (
  LLRP_tSImpinjEncodeDataAlternateEPC *pThis,
  llrp_u16v_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataAlternateEPC_beginCustom (
  LLRP_tSImpinjEncodeDataAlternateEPC *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataAlternateEPC_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEncodeDataAlternateEPC_clearCustom (
  LLRP_tSImpinjEncodeDataAlternateEPC *pThis);

extern int
LLRP_ImpinjEncodeDataAlternateEPC_countCustom (
  LLRP_tSImpinjEncodeDataAlternateEPC *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataAlternateEPC_addCustom (
  LLRP_tSImpinjEncodeDataAlternateEPC *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEncodeDataQTConfig
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjQTDataProfile eDataProfile;

    LLRP_tEImpinjQTAccessRange eAccessRange;

    LLRP_tEImpinjQTPersistence ePersistence;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEncodeDataQTConfig;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEncodeDataQTConfig[];

extern LLRP_tSImpinjEncodeDataQTConfig *
LLRP_ImpinjEncodeDataQTConfig_construct (void);

extern void
LLRP_ImpinjEncodeDataQTConfig_destruct (
 LLRP_tSImpinjEncodeDataQTConfig * pThis);

extern void
LLRP_ImpinjEncodeDataQTConfig_decodeFields (
 LLRP_tSImpinjEncodeDataQTConfig * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEncodeDataQTConfig_assimilateSubParameters (
 LLRP_tSImpinjEncodeDataQTConfig * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEncodeDataQTConfig_encode (
  const LLRP_tSImpinjEncodeDataQTConfig *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEncodeDataQTConfig_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataQTConfig_DataProfile;

extern LLRP_tEImpinjQTDataProfile
LLRP_ImpinjEncodeDataQTConfig_getDataProfile (
  LLRP_tSImpinjEncodeDataQTConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataQTConfig_setDataProfile (
  LLRP_tSImpinjEncodeDataQTConfig *pThis,
  LLRP_tEImpinjQTDataProfile Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataQTConfig_AccessRange;

extern LLRP_tEImpinjQTAccessRange
LLRP_ImpinjEncodeDataQTConfig_getAccessRange (
  LLRP_tSImpinjEncodeDataQTConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataQTConfig_setAccessRange (
  LLRP_tSImpinjEncodeDataQTConfig *pThis,
  LLRP_tEImpinjQTAccessRange Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataQTConfig_Persistence;

extern LLRP_tEImpinjQTPersistence
LLRP_ImpinjEncodeDataQTConfig_getPersistence (
  LLRP_tSImpinjEncodeDataQTConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataQTConfig_setPersistence (
  LLRP_tSImpinjEncodeDataQTConfig *pThis,
  LLRP_tEImpinjQTPersistence Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataQTConfig_beginCustom (
  LLRP_tSImpinjEncodeDataQTConfig *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataQTConfig_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEncodeDataQTConfig_clearCustom (
  LLRP_tSImpinjEncodeDataQTConfig *pThis);

extern int
LLRP_ImpinjEncodeDataQTConfig_countCustom (
  LLRP_tSImpinjEncodeDataQTConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataQTConfig_addCustom (
  LLRP_tSImpinjEncodeDataQTConfig *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEncodeDataLockConfig
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjLockPrivilege eAccessPasswordLock;

    LLRP_tEImpinjLockPrivilege eKillPasswordLock;

    LLRP_tEImpinjLockPrivilege eEPCMemoryLock;

    LLRP_tEImpinjLockPrivilege eTIDMemoryLock;

    LLRP_tEImpinjLockPrivilege eUserMemoryLock;

    llrp_u16_t UserBlockPermalockPointer;

    llrp_u16v_t UserBlockPermalockMask;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEncodeDataLockConfig;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEncodeDataLockConfig[];

extern LLRP_tSImpinjEncodeDataLockConfig *
LLRP_ImpinjEncodeDataLockConfig_construct (void);

extern void
LLRP_ImpinjEncodeDataLockConfig_destruct (
 LLRP_tSImpinjEncodeDataLockConfig * pThis);

extern void
LLRP_ImpinjEncodeDataLockConfig_decodeFields (
 LLRP_tSImpinjEncodeDataLockConfig * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEncodeDataLockConfig_assimilateSubParameters (
 LLRP_tSImpinjEncodeDataLockConfig * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEncodeDataLockConfig_encode (
  const LLRP_tSImpinjEncodeDataLockConfig *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEncodeDataLockConfig_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataLockConfig_AccessPasswordLock;

extern LLRP_tEImpinjLockPrivilege
LLRP_ImpinjEncodeDataLockConfig_getAccessPasswordLock (
  LLRP_tSImpinjEncodeDataLockConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataLockConfig_setAccessPasswordLock (
  LLRP_tSImpinjEncodeDataLockConfig *pThis,
  LLRP_tEImpinjLockPrivilege Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataLockConfig_KillPasswordLock;

extern LLRP_tEImpinjLockPrivilege
LLRP_ImpinjEncodeDataLockConfig_getKillPasswordLock (
  LLRP_tSImpinjEncodeDataLockConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataLockConfig_setKillPasswordLock (
  LLRP_tSImpinjEncodeDataLockConfig *pThis,
  LLRP_tEImpinjLockPrivilege Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataLockConfig_EPCMemoryLock;

extern LLRP_tEImpinjLockPrivilege
LLRP_ImpinjEncodeDataLockConfig_getEPCMemoryLock (
  LLRP_tSImpinjEncodeDataLockConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataLockConfig_setEPCMemoryLock (
  LLRP_tSImpinjEncodeDataLockConfig *pThis,
  LLRP_tEImpinjLockPrivilege Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataLockConfig_TIDMemoryLock;

extern LLRP_tEImpinjLockPrivilege
LLRP_ImpinjEncodeDataLockConfig_getTIDMemoryLock (
  LLRP_tSImpinjEncodeDataLockConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataLockConfig_setTIDMemoryLock (
  LLRP_tSImpinjEncodeDataLockConfig *pThis,
  LLRP_tEImpinjLockPrivilege Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataLockConfig_UserMemoryLock;

extern LLRP_tEImpinjLockPrivilege
LLRP_ImpinjEncodeDataLockConfig_getUserMemoryLock (
  LLRP_tSImpinjEncodeDataLockConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataLockConfig_setUserMemoryLock (
  LLRP_tSImpinjEncodeDataLockConfig *pThis,
  LLRP_tEImpinjLockPrivilege Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataLockConfig_UserBlockPermalockPointer;

extern llrp_u16_t
LLRP_ImpinjEncodeDataLockConfig_getUserBlockPermalockPointer (
  LLRP_tSImpinjEncodeDataLockConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataLockConfig_setUserBlockPermalockPointer (
  LLRP_tSImpinjEncodeDataLockConfig *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataLockConfig_UserBlockPermalockMask;

extern llrp_u16v_t
LLRP_ImpinjEncodeDataLockConfig_getUserBlockPermalockMask (
  LLRP_tSImpinjEncodeDataLockConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataLockConfig_setUserBlockPermalockMask (
  LLRP_tSImpinjEncodeDataLockConfig *pThis,
  llrp_u16v_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataLockConfig_beginCustom (
  LLRP_tSImpinjEncodeDataLockConfig *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataLockConfig_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEncodeDataLockConfig_clearCustom (
  LLRP_tSImpinjEncodeDataLockConfig *pThis);

extern int
LLRP_ImpinjEncodeDataLockConfig_countCustom (
  LLRP_tSImpinjEncodeDataLockConfig *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataLockConfig_addCustom (
  LLRP_tSImpinjEncodeDataLockConfig *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjLowEncodeDataThresholdEvent
{
    LLRP_tSParameter hdr;
  
    llrp_u32_t EncodeDataCacheID;

    llrp_u16_t Threshold;

    llrp_u16_t Count;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjLowEncodeDataThresholdEvent;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjLowEncodeDataThresholdEvent[];

extern LLRP_tSImpinjLowEncodeDataThresholdEvent *
LLRP_ImpinjLowEncodeDataThresholdEvent_construct (void);

extern void
LLRP_ImpinjLowEncodeDataThresholdEvent_destruct (
 LLRP_tSImpinjLowEncodeDataThresholdEvent * pThis);

extern void
LLRP_ImpinjLowEncodeDataThresholdEvent_decodeFields (
 LLRP_tSImpinjLowEncodeDataThresholdEvent * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjLowEncodeDataThresholdEvent_assimilateSubParameters (
 LLRP_tSImpinjLowEncodeDataThresholdEvent * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjLowEncodeDataThresholdEvent_encode (
  const LLRP_tSImpinjLowEncodeDataThresholdEvent *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjLowEncodeDataThresholdEvent_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjLowEncodeDataThresholdEvent_EncodeDataCacheID;

extern llrp_u32_t
LLRP_ImpinjLowEncodeDataThresholdEvent_getEncodeDataCacheID (
  LLRP_tSImpinjLowEncodeDataThresholdEvent *pThis);

extern LLRP_tResultCode
LLRP_ImpinjLowEncodeDataThresholdEvent_setEncodeDataCacheID (
  LLRP_tSImpinjLowEncodeDataThresholdEvent *pThis,
  llrp_u32_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjLowEncodeDataThresholdEvent_Threshold;

extern llrp_u16_t
LLRP_ImpinjLowEncodeDataThresholdEvent_getThreshold (
  LLRP_tSImpinjLowEncodeDataThresholdEvent *pThis);

extern LLRP_tResultCode
LLRP_ImpinjLowEncodeDataThresholdEvent_setThreshold (
  LLRP_tSImpinjLowEncodeDataThresholdEvent *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjLowEncodeDataThresholdEvent_Count;

extern llrp_u16_t
LLRP_ImpinjLowEncodeDataThresholdEvent_getCount (
  LLRP_tSImpinjLowEncodeDataThresholdEvent *pThis);

extern LLRP_tResultCode
LLRP_ImpinjLowEncodeDataThresholdEvent_setCount (
  LLRP_tSImpinjLowEncodeDataThresholdEvent *pThis,
  llrp_u16_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjLowEncodeDataThresholdEvent_beginCustom (
  LLRP_tSImpinjLowEncodeDataThresholdEvent *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjLowEncodeDataThresholdEvent_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjLowEncodeDataThresholdEvent_clearCustom (
  LLRP_tSImpinjLowEncodeDataThresholdEvent *pThis);

extern int
LLRP_ImpinjLowEncodeDataThresholdEvent_countCustom (
  LLRP_tSImpinjLowEncodeDataThresholdEvent *pThis);

extern LLRP_tResultCode
LLRP_ImpinjLowEncodeDataThresholdEvent_addCustom (
  LLRP_tSImpinjLowEncodeDataThresholdEvent *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEncodeOpSpec
{
    LLRP_tSParameter hdr;
  
    llrp_u16_t OpSpecID;

    llrp_u32_t AccessPassword;

    llrp_u32_t EncodeDataCacheID;

    LLRP_tEImpinjEncodeMode eMode;

    LLRP_tEImpinjTagICType eTagIC;

    llrp_u32_t EncodeCount;

    llrp_u16_t TagsInViewCount;

    llrp_u16_t EncodeReportCount;

    llrp_u16_t TagInViewTimeout;

  
    LLRP_tSImpinjOpSpecGPOPulse * listImpinjOpSpecGPOPulse;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEncodeOpSpec;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEncodeOpSpec[];

extern LLRP_tSImpinjEncodeOpSpec *
LLRP_ImpinjEncodeOpSpec_construct (void);

extern void
LLRP_ImpinjEncodeOpSpec_destruct (
 LLRP_tSImpinjEncodeOpSpec * pThis);

extern void
LLRP_ImpinjEncodeOpSpec_decodeFields (
 LLRP_tSImpinjEncodeOpSpec * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEncodeOpSpec_assimilateSubParameters (
 LLRP_tSImpinjEncodeOpSpec * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEncodeOpSpec_encode (
  const LLRP_tSImpinjEncodeOpSpec *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEncodeOpSpec_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeOpSpec_OpSpecID;

extern llrp_u16_t
LLRP_ImpinjEncodeOpSpec_getOpSpecID (
  LLRP_tSImpinjEncodeOpSpec *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeOpSpec_setOpSpecID (
  LLRP_tSImpinjEncodeOpSpec *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeOpSpec_AccessPassword;

extern llrp_u32_t
LLRP_ImpinjEncodeOpSpec_getAccessPassword (
  LLRP_tSImpinjEncodeOpSpec *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeOpSpec_setAccessPassword (
  LLRP_tSImpinjEncodeOpSpec *pThis,
  llrp_u32_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeOpSpec_EncodeDataCacheID;

extern llrp_u32_t
LLRP_ImpinjEncodeOpSpec_getEncodeDataCacheID (
  LLRP_tSImpinjEncodeOpSpec *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeOpSpec_setEncodeDataCacheID (
  LLRP_tSImpinjEncodeOpSpec *pThis,
  llrp_u32_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeOpSpec_Mode;

extern LLRP_tEImpinjEncodeMode
LLRP_ImpinjEncodeOpSpec_getMode (
  LLRP_tSImpinjEncodeOpSpec *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeOpSpec_setMode (
  LLRP_tSImpinjEncodeOpSpec *pThis,
  LLRP_tEImpinjEncodeMode Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeOpSpec_TagIC;

extern LLRP_tEImpinjTagICType
LLRP_ImpinjEncodeOpSpec_getTagIC (
  LLRP_tSImpinjEncodeOpSpec *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeOpSpec_setTagIC (
  LLRP_tSImpinjEncodeOpSpec *pThis,
  LLRP_tEImpinjTagICType Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeOpSpec_EncodeCount;

extern llrp_u32_t
LLRP_ImpinjEncodeOpSpec_getEncodeCount (
  LLRP_tSImpinjEncodeOpSpec *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeOpSpec_setEncodeCount (
  LLRP_tSImpinjEncodeOpSpec *pThis,
  llrp_u32_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeOpSpec_TagsInViewCount;

extern llrp_u16_t
LLRP_ImpinjEncodeOpSpec_getTagsInViewCount (
  LLRP_tSImpinjEncodeOpSpec *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeOpSpec_setTagsInViewCount (
  LLRP_tSImpinjEncodeOpSpec *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeOpSpec_EncodeReportCount;

extern llrp_u16_t
LLRP_ImpinjEncodeOpSpec_getEncodeReportCount (
  LLRP_tSImpinjEncodeOpSpec *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeOpSpec_setEncodeReportCount (
  LLRP_tSImpinjEncodeOpSpec *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeOpSpec_TagInViewTimeout;

extern llrp_u16_t
LLRP_ImpinjEncodeOpSpec_getTagInViewTimeout (
  LLRP_tSImpinjEncodeOpSpec *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeOpSpec_setTagInViewTimeout (
  LLRP_tSImpinjEncodeOpSpec *pThis,
  llrp_u16_t Value);

  
extern LLRP_tSImpinjOpSpecGPOPulse *
LLRP_ImpinjEncodeOpSpec_beginImpinjOpSpecGPOPulse (
  LLRP_tSImpinjEncodeOpSpec *pThis);

extern LLRP_tSImpinjOpSpecGPOPulse *
LLRP_ImpinjEncodeOpSpec_nextImpinjOpSpecGPOPulse (
  LLRP_tSImpinjOpSpecGPOPulse *pCurrent);

extern void
LLRP_ImpinjEncodeOpSpec_clearImpinjOpSpecGPOPulse (
  LLRP_tSImpinjEncodeOpSpec *pThis);

extern int
LLRP_ImpinjEncodeOpSpec_countImpinjOpSpecGPOPulse (
  LLRP_tSImpinjEncodeOpSpec *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeOpSpec_addImpinjOpSpecGPOPulse (
  LLRP_tSImpinjEncodeOpSpec *pThis,
  LLRP_tSImpinjOpSpecGPOPulse *pValue);


extern LLRP_tSParameter *
LLRP_ImpinjEncodeOpSpec_beginCustom (
  LLRP_tSImpinjEncodeOpSpec *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEncodeOpSpec_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEncodeOpSpec_clearCustom (
  LLRP_tSImpinjEncodeOpSpec *pThis);

extern int
LLRP_ImpinjEncodeOpSpec_countCustom (
  LLRP_tSImpinjEncodeOpSpec *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeOpSpec_addCustom (
  LLRP_tSImpinjEncodeOpSpec *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjOpSpecGPOPulse
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjOpSpecAction eOpSpecAction;

    llrp_u16_t GPOPortNumber;

    llrp_u1_t GPOData;

    llrp_u16_t GPOPulseDurationMSec;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjOpSpecGPOPulse;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjOpSpecGPOPulse[];

extern LLRP_tSImpinjOpSpecGPOPulse *
LLRP_ImpinjOpSpecGPOPulse_construct (void);

extern void
LLRP_ImpinjOpSpecGPOPulse_destruct (
 LLRP_tSImpinjOpSpecGPOPulse * pThis);

extern void
LLRP_ImpinjOpSpecGPOPulse_decodeFields (
 LLRP_tSImpinjOpSpecGPOPulse * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjOpSpecGPOPulse_assimilateSubParameters (
 LLRP_tSImpinjOpSpecGPOPulse * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjOpSpecGPOPulse_encode (
  const LLRP_tSImpinjOpSpecGPOPulse *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjOpSpecGPOPulse_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjOpSpecGPOPulse_OpSpecAction;

extern LLRP_tEImpinjOpSpecAction
LLRP_ImpinjOpSpecGPOPulse_getOpSpecAction (
  LLRP_tSImpinjOpSpecGPOPulse *pThis);

extern LLRP_tResultCode
LLRP_ImpinjOpSpecGPOPulse_setOpSpecAction (
  LLRP_tSImpinjOpSpecGPOPulse *pThis,
  LLRP_tEImpinjOpSpecAction Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjOpSpecGPOPulse_GPOPortNumber;

extern llrp_u16_t
LLRP_ImpinjOpSpecGPOPulse_getGPOPortNumber (
  LLRP_tSImpinjOpSpecGPOPulse *pThis);

extern LLRP_tResultCode
LLRP_ImpinjOpSpecGPOPulse_setGPOPortNumber (
  LLRP_tSImpinjOpSpecGPOPulse *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjOpSpecGPOPulse_GPOData;

extern llrp_u1_t
LLRP_ImpinjOpSpecGPOPulse_getGPOData (
  LLRP_tSImpinjOpSpecGPOPulse *pThis);

extern LLRP_tResultCode
LLRP_ImpinjOpSpecGPOPulse_setGPOData (
  LLRP_tSImpinjOpSpecGPOPulse *pThis,
  llrp_u1_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjOpSpecGPOPulse_GPOPulseDurationMSec;

extern llrp_u16_t
LLRP_ImpinjOpSpecGPOPulse_getGPOPulseDurationMSec (
  LLRP_tSImpinjOpSpecGPOPulse *pThis);

extern LLRP_tResultCode
LLRP_ImpinjOpSpecGPOPulse_setGPOPulseDurationMSec (
  LLRP_tSImpinjOpSpecGPOPulse *pThis,
  llrp_u16_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjOpSpecGPOPulse_beginCustom (
  LLRP_tSImpinjOpSpecGPOPulse *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjOpSpecGPOPulse_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjOpSpecGPOPulse_clearCustom (
  LLRP_tSImpinjOpSpecGPOPulse *pThis);

extern int
LLRP_ImpinjOpSpecGPOPulse_countCustom (
  LLRP_tSImpinjOpSpecGPOPulse *pThis);

extern LLRP_tResultCode
LLRP_ImpinjOpSpecGPOPulse_addCustom (
  LLRP_tSImpinjOpSpecGPOPulse *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEncodeReportData
{
    LLRP_tSParameter hdr;
  
    llrp_u32_t AccessSpecID;

  
    LLRP_tSImpinjEncodeOpSpecResult * pImpinjEncodeOpSpecResult;

    LLRP_tSImpinjEncodeDataResult * listImpinjEncodeDataResult;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEncodeReportData;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEncodeReportData[];

extern LLRP_tSImpinjEncodeReportData *
LLRP_ImpinjEncodeReportData_construct (void);

extern void
LLRP_ImpinjEncodeReportData_destruct (
 LLRP_tSImpinjEncodeReportData * pThis);

extern void
LLRP_ImpinjEncodeReportData_decodeFields (
 LLRP_tSImpinjEncodeReportData * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEncodeReportData_assimilateSubParameters (
 LLRP_tSImpinjEncodeReportData * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEncodeReportData_encode (
  const LLRP_tSImpinjEncodeReportData *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEncodeReportData_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeReportData_AccessSpecID;

extern llrp_u32_t
LLRP_ImpinjEncodeReportData_getAccessSpecID (
  LLRP_tSImpinjEncodeReportData *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeReportData_setAccessSpecID (
  LLRP_tSImpinjEncodeReportData *pThis,
  llrp_u32_t Value);

  
extern LLRP_tSImpinjEncodeOpSpecResult *
LLRP_ImpinjEncodeReportData_getImpinjEncodeOpSpecResult (
  LLRP_tSImpinjEncodeReportData *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeReportData_setImpinjEncodeOpSpecResult (
  LLRP_tSImpinjEncodeReportData *pThis,
  LLRP_tSImpinjEncodeOpSpecResult *pValue);

extern LLRP_tSImpinjEncodeDataResult *
LLRP_ImpinjEncodeReportData_beginImpinjEncodeDataResult (
  LLRP_tSImpinjEncodeReportData *pThis);

extern LLRP_tSImpinjEncodeDataResult *
LLRP_ImpinjEncodeReportData_nextImpinjEncodeDataResult (
  LLRP_tSImpinjEncodeDataResult *pCurrent);

extern void
LLRP_ImpinjEncodeReportData_clearImpinjEncodeDataResult (
  LLRP_tSImpinjEncodeReportData *pThis);

extern int
LLRP_ImpinjEncodeReportData_countImpinjEncodeDataResult (
  LLRP_tSImpinjEncodeReportData *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeReportData_addImpinjEncodeDataResult (
  LLRP_tSImpinjEncodeReportData *pThis,
  LLRP_tSImpinjEncodeDataResult *pValue);


extern LLRP_tSParameter *
LLRP_ImpinjEncodeReportData_beginCustom (
  LLRP_tSImpinjEncodeReportData *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEncodeReportData_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEncodeReportData_clearCustom (
  LLRP_tSImpinjEncodeReportData *pThis);

extern int
LLRP_ImpinjEncodeReportData_countCustom (
  LLRP_tSImpinjEncodeReportData *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeReportData_addCustom (
  LLRP_tSImpinjEncodeReportData *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEncodeOpSpecResult
{
    LLRP_tSParameter hdr;
  
    llrp_u16_t OpSpecID;

    LLRP_tEImpinjEncodeResultType eResult;

    llrp_u64_t ElapsedTime;

    llrp_u32_t AttemptCount;

    llrp_u32_t SuccessCount;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEncodeOpSpecResult;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEncodeOpSpecResult[];

extern LLRP_tSImpinjEncodeOpSpecResult *
LLRP_ImpinjEncodeOpSpecResult_construct (void);

extern void
LLRP_ImpinjEncodeOpSpecResult_destruct (
 LLRP_tSImpinjEncodeOpSpecResult * pThis);

extern void
LLRP_ImpinjEncodeOpSpecResult_decodeFields (
 LLRP_tSImpinjEncodeOpSpecResult * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEncodeOpSpecResult_assimilateSubParameters (
 LLRP_tSImpinjEncodeOpSpecResult * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEncodeOpSpecResult_encode (
  const LLRP_tSImpinjEncodeOpSpecResult *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEncodeOpSpecResult_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeOpSpecResult_OpSpecID;

extern llrp_u16_t
LLRP_ImpinjEncodeOpSpecResult_getOpSpecID (
  LLRP_tSImpinjEncodeOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeOpSpecResult_setOpSpecID (
  LLRP_tSImpinjEncodeOpSpecResult *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeOpSpecResult_Result;

extern LLRP_tEImpinjEncodeResultType
LLRP_ImpinjEncodeOpSpecResult_getResult (
  LLRP_tSImpinjEncodeOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeOpSpecResult_setResult (
  LLRP_tSImpinjEncodeOpSpecResult *pThis,
  LLRP_tEImpinjEncodeResultType Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeOpSpecResult_ElapsedTime;

extern llrp_u64_t
LLRP_ImpinjEncodeOpSpecResult_getElapsedTime (
  LLRP_tSImpinjEncodeOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeOpSpecResult_setElapsedTime (
  LLRP_tSImpinjEncodeOpSpecResult *pThis,
  llrp_u64_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeOpSpecResult_AttemptCount;

extern llrp_u32_t
LLRP_ImpinjEncodeOpSpecResult_getAttemptCount (
  LLRP_tSImpinjEncodeOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeOpSpecResult_setAttemptCount (
  LLRP_tSImpinjEncodeOpSpecResult *pThis,
  llrp_u32_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeOpSpecResult_SuccessCount;

extern llrp_u32_t
LLRP_ImpinjEncodeOpSpecResult_getSuccessCount (
  LLRP_tSImpinjEncodeOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeOpSpecResult_setSuccessCount (
  LLRP_tSImpinjEncodeOpSpecResult *pThis,
  llrp_u32_t Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjEncodeOpSpecResult_beginCustom (
  LLRP_tSImpinjEncodeOpSpecResult *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEncodeOpSpecResult_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEncodeOpSpecResult_clearCustom (
  LLRP_tSImpinjEncodeOpSpecResult *pThis);

extern int
LLRP_ImpinjEncodeOpSpecResult_countCustom (
  LLRP_tSImpinjEncodeOpSpecResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeOpSpecResult_addCustom (
  LLRP_tSImpinjEncodeOpSpecResult *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEncodeDataResult
{
    LLRP_tSParameter hdr;
  
    llrp_u16_t OpSpecID;

    LLRP_tEImpinjEncodeDataResultType eResult;

  
    LLRP_tSEPCData * pEPCData;

    LLRP_tSImpinjEncodeDataDetailedResult * pImpinjEncodeDataDetailedResult;

    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEncodeDataResult;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEncodeDataResult[];

extern LLRP_tSImpinjEncodeDataResult *
LLRP_ImpinjEncodeDataResult_construct (void);

extern void
LLRP_ImpinjEncodeDataResult_destruct (
 LLRP_tSImpinjEncodeDataResult * pThis);

extern void
LLRP_ImpinjEncodeDataResult_decodeFields (
 LLRP_tSImpinjEncodeDataResult * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEncodeDataResult_assimilateSubParameters (
 LLRP_tSImpinjEncodeDataResult * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEncodeDataResult_encode (
  const LLRP_tSImpinjEncodeDataResult *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEncodeDataResult_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataResult_OpSpecID;

extern llrp_u16_t
LLRP_ImpinjEncodeDataResult_getOpSpecID (
  LLRP_tSImpinjEncodeDataResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataResult_setOpSpecID (
  LLRP_tSImpinjEncodeDataResult *pThis,
  llrp_u16_t Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataResult_Result;

extern LLRP_tEImpinjEncodeDataResultType
LLRP_ImpinjEncodeDataResult_getResult (
  LLRP_tSImpinjEncodeDataResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataResult_setResult (
  LLRP_tSImpinjEncodeDataResult *pThis,
  LLRP_tEImpinjEncodeDataResultType Value);

  
extern LLRP_tSEPCData *
LLRP_ImpinjEncodeDataResult_getEPCData (
  LLRP_tSImpinjEncodeDataResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataResult_setEPCData (
  LLRP_tSImpinjEncodeDataResult *pThis,
  LLRP_tSEPCData *pValue);

extern LLRP_tSImpinjEncodeDataDetailedResult *
LLRP_ImpinjEncodeDataResult_getImpinjEncodeDataDetailedResult (
  LLRP_tSImpinjEncodeDataResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataResult_setImpinjEncodeDataDetailedResult (
  LLRP_tSImpinjEncodeDataResult *pThis,
  LLRP_tSImpinjEncodeDataDetailedResult *pValue);

extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataResult_beginCustom (
  LLRP_tSImpinjEncodeDataResult *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataResult_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEncodeDataResult_clearCustom (
  LLRP_tSImpinjEncodeDataResult *pThis);

extern int
LLRP_ImpinjEncodeDataResult_countCustom (
  LLRP_tSImpinjEncodeDataResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataResult_addCustom (
  LLRP_tSImpinjEncodeDataResult *pThis,
  LLRP_tSParameter *pValue);




  
struct LLRP_SImpinjEncodeDataDetailedResult
{
    LLRP_tSParameter hdr;
  
    LLRP_tEImpinjEncodeDataResultType eEncodeEPCResult;

    LLRP_tEImpinjEncodeDataResultType eEncodePCBitsResult;

    LLRP_tEImpinjEncodeDataResultType eEncodeAccessPasswordResult;

    LLRP_tEImpinjEncodeDataResultType eEncodeKillPasswordResult;

    LLRP_tEImpinjEncodeDataResultType eEncodeUserMemoryResult;

    LLRP_tEImpinjEncodeDataResultType eEncodeAlternateEPCResult;

    LLRP_tEImpinjEncodeDataResultType eEncodeQTConfigResult;

    LLRP_tEImpinjEncodeDataResultType eEncodeLockConfigResult;

  
    LLRP_tSParameter * listCustom;

};

extern const LLRP_tSTypeDescriptor
LLRP_tdImpinjEncodeDataDetailedResult;

extern const LLRP_tSFieldDescriptor *
LLRP_apfdImpinjEncodeDataDetailedResult[];

extern LLRP_tSImpinjEncodeDataDetailedResult *
LLRP_ImpinjEncodeDataDetailedResult_construct (void);

extern void
LLRP_ImpinjEncodeDataDetailedResult_destruct (
 LLRP_tSImpinjEncodeDataDetailedResult * pThis);

extern void
LLRP_ImpinjEncodeDataDetailedResult_decodeFields (
 LLRP_tSImpinjEncodeDataDetailedResult * pThis,
 LLRP_tSDecoderStream * pDecoderStream);

extern void
LLRP_ImpinjEncodeDataDetailedResult_assimilateSubParameters (
 LLRP_tSImpinjEncodeDataDetailedResult * pThis,
 LLRP_tSErrorDetails *          pError);

extern void
LLRP_ImpinjEncodeDataDetailedResult_encode (
  const LLRP_tSImpinjEncodeDataDetailedResult *pThis,
  LLRP_tSEncoderStream *        pEncoderStream);

  
extern llrp_bool_t
LLRP_ImpinjEncodeDataDetailedResult_isAllowedIn (
  const LLRP_tSTypeDescriptor *pEnclosingElementType);
  

  
extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataDetailedResult_EncodeEPCResult;

extern LLRP_tEImpinjEncodeDataResultType
LLRP_ImpinjEncodeDataDetailedResult_getEncodeEPCResult (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataDetailedResult_setEncodeEPCResult (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis,
  LLRP_tEImpinjEncodeDataResultType Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataDetailedResult_EncodePCBitsResult;

extern LLRP_tEImpinjEncodeDataResultType
LLRP_ImpinjEncodeDataDetailedResult_getEncodePCBitsResult (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataDetailedResult_setEncodePCBitsResult (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis,
  LLRP_tEImpinjEncodeDataResultType Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataDetailedResult_EncodeAccessPasswordResult;

extern LLRP_tEImpinjEncodeDataResultType
LLRP_ImpinjEncodeDataDetailedResult_getEncodeAccessPasswordResult (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataDetailedResult_setEncodeAccessPasswordResult (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis,
  LLRP_tEImpinjEncodeDataResultType Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataDetailedResult_EncodeKillPasswordResult;

extern LLRP_tEImpinjEncodeDataResultType
LLRP_ImpinjEncodeDataDetailedResult_getEncodeKillPasswordResult (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataDetailedResult_setEncodeKillPasswordResult (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis,
  LLRP_tEImpinjEncodeDataResultType Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataDetailedResult_EncodeUserMemoryResult;

extern LLRP_tEImpinjEncodeDataResultType
LLRP_ImpinjEncodeDataDetailedResult_getEncodeUserMemoryResult (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataDetailedResult_setEncodeUserMemoryResult (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis,
  LLRP_tEImpinjEncodeDataResultType Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataDetailedResult_EncodeAlternateEPCResult;

extern LLRP_tEImpinjEncodeDataResultType
LLRP_ImpinjEncodeDataDetailedResult_getEncodeAlternateEPCResult (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataDetailedResult_setEncodeAlternateEPCResult (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis,
  LLRP_tEImpinjEncodeDataResultType Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataDetailedResult_EncodeQTConfigResult;

extern LLRP_tEImpinjEncodeDataResultType
LLRP_ImpinjEncodeDataDetailedResult_getEncodeQTConfigResult (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataDetailedResult_setEncodeQTConfigResult (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis,
  LLRP_tEImpinjEncodeDataResultType Value);

extern const LLRP_tSFieldDescriptor
LLRP_fdImpinjEncodeDataDetailedResult_EncodeLockConfigResult;

extern LLRP_tEImpinjEncodeDataResultType
LLRP_ImpinjEncodeDataDetailedResult_getEncodeLockConfigResult (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataDetailedResult_setEncodeLockConfigResult (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis,
  LLRP_tEImpinjEncodeDataResultType Value);

  
extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataDetailedResult_beginCustom (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis);

extern LLRP_tSParameter *
LLRP_ImpinjEncodeDataDetailedResult_nextCustom (
  LLRP_tSParameter *pCurrent);

extern void
LLRP_ImpinjEncodeDataDetailedResult_clearCustom (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis);

extern int
LLRP_ImpinjEncodeDataDetailedResult_countCustom (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis);

extern LLRP_tResultCode
LLRP_ImpinjEncodeDataDetailedResult_addCustom (
  LLRP_tSImpinjEncodeDataDetailedResult *pThis,
  LLRP_tSParameter *pValue);





void
LLRP_enrollImpinjTypesIntoRegistry (
  LLRP_tSTypeRegistry *         pTypeRegistry);

