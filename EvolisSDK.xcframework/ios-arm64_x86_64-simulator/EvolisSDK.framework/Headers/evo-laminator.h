#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "evolis.h"

typedef enum evolis_laminator_film_type_e {
    /// Unknown or unsupported film
    EVOLIS_LFT_UNKNOWN = 0,
    /// Clear Patch 1.0 Mil
    EVOLIS_LFT_CLEAR_PATCH_1_0_MIL = 500,
    /// Generic Holo Patch 1.0 Mil
    EVOLIS_LFT_GENERIC_HOLO_PATCH_1_0_MIL = 501,
    /// Clear Smart Cut Patch 1.0 Mil
    EVOLIS_LFT_CLEAR_SMART_CUT_PATCH_1_0_MIL = 502,
    /// Clear Mag Cut Patch 1.0 Mil
    EVOLIS_LFT_CLEAR_MAG_CUT_PATCH_1_0_MIL = 503,
    /// Clear Patch 0.5 Mil
    EVOLIS_LFT_CLEAR_PATCH_0_5_MIL = 504,
    /// Generic Holo Patch 0.6 Mil
    EVOLIS_LFT_GENERIC_HOLO_PATCH_0_6_MIL = 505,
    /// Clear Smart Cut Patch 0.5 Mil
    EVOLIS_LFT_CLEAR_SMART_CUT_PATCH_0_5_MIL = 506,
    /// Clear Mag Cut Patch 0.5 Mil
    EVOLIS_LFT_CLEAR_MAG_CUT_PATCH_0_5_MIL = 507,
    /// Generic Holo Continuous
    EVOLIS_LFT_GENERIC_HOLO_CONTINUOUS = 508,
    /// Generic Holo Registered
    EVOLIS_LFT_GENERIC_HOLO_REGISTERED = 509,
    /// Clear Varnish
    EVOLIS_LFT_CLEAR_VARNISH = 510,
    /// Alt Smart Full 1.0 Mil
    EVOLIS_LFT_ALT_SMART_FULL_1_0_MIL = 511,
    /// Alt Smart Mag 1.0 Mil
    EVOLIS_LFT_ALT_SMART_MAG_1_0_MIL = 512,
    /// Alt Full Mag 1.0 Mil
    EVOLIS_LFT_ALT_FULL_MAG_1_0_MI = 513,
} evolis_laminator_film_type_t;

typedef enum evolis_laminator_index_e {
    /// Should be used when the device itself is a laminator module
    EVOLIS_LAM_SELF = 0,
    /// Access the first laminator module connected to the device
    EVOLIS_LAM_FIRST = 1,
    /// Access the second laminator module connected to the device
    EVOLIS_LAM_SECOND = 2,
} evolis_laminator_index_t;

typedef enum evolis_laminator_mode_e {
    /// Unknown or unsupported mode
    EVOLIS_LMO_UNKNOWN = 0,
    /// Eject only
    EVOLIS_LMO_EJECT = 1,
    /// Laminate front only
    EVOLIS_LMO_FRONT = 2,
    /// Laminate back only
    EVOLIS_LMO_BACK = 3,
    /// Laminate both sides
    EVOLIS_LMO_FRONT_BACK = 4,
    /// Laminate back first, then front
    EVOLIS_LMO_BACK_FRONT = 5,
    /// Laminate front only, then flip
    EVOLIS_LMO_FRONT_FLIP = 6,
    /// Laminate back only, then flip
    EVOLIS_LMO_BACK_FLIP = 7,
} evolis_laminator_mode_t;

typedef struct evolis_laminator_film_s
{
    char description[64];
    char zone[8];
    evolis_laminator_film_type_t type;
    char productCode[32];
    int capacity;
    int remaining;
    char buildDate[32];
    char serialNumber[32];
    char internalCode[32];
    char batchNumber[32];
} evolis_laminator_film_t;

typedef struct evolis_laminator_info_s
{
    char fwVersion[16];
    char serialNumber[16];
    char cpuSerialNumber[16];
    char zone[16];
    bool isStandAlone;
    int nbLaminatedSides;
    int nbInsertedCards;

    evolis_laminator_mode_t mode;

    /// true if the first patch (alternate 1) of the film should be applied
    /// to the front side and the second patch to the back
    /// false for the opposite
    bool isFirstPatchFront;

    /// Reference speed for the front side,
    /// corresponds to the configuration's default value 10
    /// in the [1, 20] range
    int defaultFrontSpeed;
    /// Reference speed for the back side,
    /// corresponds to the configuration's default value 10
    /// in the [1, 20] range
    int defaultBackSpeed;
    /// Reference temperature for both sides
    /// corresponds to the configuration's default value 10
    /// in the [1, 20] range
    int defaultTemperature;

    /// Configuration value for the front speed
    /// Takes a value in the [1, 20] range, with 10 as the default
    int frontSpeedCfg;

    /// Configuration value for the front speed
    /// Takes a value in the [1, 20] range, with 10 as the default
    int backSpeedCfg;

    /// Configuration value for the front temperature
    /// Takes a value in the [1, 20] range, with 10 as the default
    int frontTemperatureCfg;

    /// Configuration value for the front temperature
    /// Takes a value in the [1, 20] range, with 10 as the default
    int backTemperatureCfg;

} evolis_laminator_info_t;

/// Indicates whether the targeted device is a laminator or not
EVOLIS_WRA int evolis_laminator_is_valid(_In_ evolis_t* printer, _In_ evolis_laminator_index_t laminatorIndex);
EVOLIS_WRA int evolis_laminator_is_validt(_In_ evolis_t* printer, _In_ evolis_laminator_index_t laminatorIndex, _In_ int timeout);

/// Returns information from the selected laminator
EVOLIS_WRA int evolis_laminator_info(_In_ evolis_t* printer, _In_ evolis_laminator_index_t laminatorIndex, _Out_ evolis_laminator_info_t* lam);
EVOLIS_WRA int evolis_laminator_infot(_In_ evolis_t* printer, _In_ evolis_laminator_index_t laminatorIndex, _Out_ evolis_laminator_info_t* lam, _In_ int timeout);

/// Returns film information from the selected laminator
EVOLIS_WRA int evolis_laminator_film(_In_ evolis_t* printer, _In_ evolis_laminator_index_t laminatorIndex, _Out_ evolis_laminator_film_t* film);
EVOLIS_WRA int evolis_laminator_filmt(_In_ evolis_t* printer, _In_ evolis_laminator_index_t laminatorIndex, _Out_ evolis_laminator_film_t* film, _In_ int timeout);

/// Indicates whether the parallel mode is enabled for lamination
EVOLIS_WRA int evolis_laminator_is_parallel_mode_enabled(_In_ evolis_t* printer, _Out_ bool* enabled);
EVOLIS_WRA int evolis_laminator_is_parallel_mode_enabledt(_In_ evolis_t* printer, _Out_ bool* enabled, _In_ int timeout);

/// Enables or disables the parallel mode
EVOLIS_WRA int evolis_laminator_enable_parallel_mode(_In_ evolis_t* printer, _In_ bool enable);
EVOLIS_WRA int evolis_laminator_enable_parallel_modet(_In_ evolis_t* printer, _In_ bool enable, _In_ int timeout);

/// Sets the lamination speed for one side
EVOLIS_WRA int evolis_laminator_set_speed_cfg(_In_ evolis_t* printer, _In_ evolis_laminator_index_t laminatorIndex, _In_ evolis_face_t face, _In_ uint16_t value);
EVOLIS_WRA int evolis_laminator_set_speed_cfgt(_In_ evolis_t* printer, _In_ evolis_laminator_index_t laminatorIndex, _In_ evolis_face_t face, _In_ uint16_t value, _In_ int timeout);

/// Sets the lamination temperature for one side
EVOLIS_WRA int evolis_laminator_set_temp_cfg(_In_ evolis_t* printer, _In_ evolis_laminator_index_t laminatorIndex, _In_ evolis_face_t face, _In_ uint16_t value);
EVOLIS_WRA int evolis_laminator_set_temp_cfgt(_In_ evolis_t* printer, _In_ evolis_laminator_index_t laminatorIndex, _In_ evolis_face_t face, _In_ uint16_t value, _In_ int timeout);

/// Sets the lamination mode
EVOLIS_WRA int evolis_laminator_set_mode(_In_ evolis_t* printer, _In_ evolis_laminator_index_t laminatorIndex, _In_ evolis_laminator_mode_t mode);
EVOLIS_WRA int evolis_laminator_set_modet(_In_ evolis_t* printer, _In_ evolis_laminator_index_t laminatorIndex, _In_ evolis_laminator_mode_t mode, _In_ int timeout);

/// Defines on which face the first patch should be applied
EVOLIS_WRA int evolis_laminator_set_first_patch(_In_ evolis_t* printer, _In_ evolis_laminator_index_t laminatorIndex, _In_ bool front);
EVOLIS_WRA int evolis_laminator_set_first_patcht(_In_ evolis_t* printer, _In_ evolis_laminator_index_t laminatorIndex, _In_ bool front, _In_ int timeout);

#ifdef __cplusplus
}
#endif
