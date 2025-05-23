/**
 * Evolis C library
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
 * ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 */
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <wchar.h>
#include <sys/types.h>

#include "evolis_version.h"
#include "evosettings_keys.h"

/// @cond DO_NOT_DOCUMENT
#ifndef __ATTR_SAL
    #define _In_
    #define _Out_
    #define _Inout_
#endif
/// @endcond

//
// Table of contents:
// -----------------
//
// - LIBRARY MACROS
// - LIBRARY SETTINGS
// - ERROR MANAGEMENT
// - DEVICE ENUMERATION
// - DEVICE I/O
// - DEVICE INFO
// - DEVICE STATE
// - DEVICE STATUS [evo-printers.h]
// - CARD OPERATIONS
// - BEZEL SETTINGS
// - MAG ENCODING
// - PRINTING
// - SERVICE REQUESTS [evo-service.h]
// - LAMINATION MODULE [evo-laminator.h]
// - PRINTER DISCOVERY
// - SCAN
// - LOGGING
// - FILE HELPERS
//

//
// ToC/LIBRARY MACROS
// ------------------
//

//
// LibEvolis's export macros.
// The options are:
//   - EVOLIS_BUILD defined: We are building the library.
//   - EVOLIS_SHARED defined: Library is being built in shared mode.
//   - EVOLIS_STATIC defined: Library is being build in static mode.
//

#ifdef _WIN32
#  define EVOLIS_DECL_EXPORT __declspec(dllexport)
#  define EVOLIS_DECL_IMPORT __declspec(dllimport)
#else
#  define EVOLIS_DECL_EXPORT
#  define EVOLIS_DECL_IMPORT
#endif

#if defined(EVOLIS_SHARED) || !defined(EVOLIS_STATIC)
#  ifdef EVOLIS_STATIC
#    error "Both EVOLIS_SHARED and EVOLIS_STATIC defined, please make up your mind"
#  endif
#  ifndef EVOLIS_SHARED
#    define EVOLIS_SHARED
#  endif
#  ifdef EVOLIS_BUILD
#    define EVOLIS_LIB EVOLIS_DECL_EXPORT
#  else
#    define EVOLIS_LIB EVOLIS_DECL_IMPORT
#  endif
#else
#  define EVOLIS_LIB
#endif
#define EVOLIS_WRA EVOLIS_LIB

#if defined(__GNUC__) || defined(__clang__)
#  define EVOLIS_DEPRECATED __attribute__((deprecated))
#elif defined(_MSC_VER)
#  define EVOLIS_DEPRECATED __declspec(deprecated)
#else
#  define EVOLIS_DEPRECATED
#endif

#define EVOLIS_STRX(x) #x
#define EVOLIS_STR(x) EVOLIS_STRX(x)

#define EVOLIS_UNUSED_ATTR(x) (void)(x)

/// 30s, printer communication timeout.
#define EVOLIS_TIMEOUT 30000

/// Default timeout value of a print job.
#define EVOLIS_PRINT_TIMEOUT 5 * 60000

/// Value of session when printer is available.
#define EVOLIS_SESSION_FREE 0

/// Session taken by evoservice.
#define EVOLIS_SESSION_MANAGE 1

/// Session taken when printing.
#define EVOLIS_SESSION_PRINT 2

/// Session taken by evomanager.
#define EVOLIS_SESSION_UI 3

/// 5s, a good value to use to reserve the printer.
#define EVOLIS_SESSION_WAIT 5000

/// 45s, timeout after which the printer release a session.
#define EVOLIS_SESSION_TIMEOUT 45

/// Test if return value of `evolis_reserve()` means
/// printer is already reserved.
#define EVOLIS_SESSION_IS_BUSY(s) (s == EVOLIS_RC_SESSION_EBUSY)

/// Test if the session is empty.
#define EVOLIS_SESSION_IS_FREE(s) (s == EVOLIS_SESSION_FREE)

/// Test if return value of `evolis_reserve()` succeed.
#define EVOLIS_SESSION_IS_OK(s) (s > 0)

/// True if printer reply is "OK".
#define EVOLIS_REPLY_IS_OK(REPLY) (strcmp(REPLY, "OK") == 0)

/// True if printer reply starts with "ERR".
#define EVOLIS_REPLY_IS_ERR(REPLY) (strncmp(REPLY, "ERR", 3) == 0)
#define EVOLIS_REPLY_IS_ERROR_CDE(REPLY) (strncmp(REPLY, "ERROR CDE", 9) == 0)

#define evobuf char

//
// ToC/LIBRARY SETTINGS
// --------------------
//

/// Get library version at runtime.
EVOLIS_WRA const char* evolis_version(void);

/// Convert error code to a c-string.
EVOLIS_LIB const char* evolis_get_error_name(_In_ int r);

#ifdef _WIN32
    /// Convert a wide chars string to UTF-8 string. Returns a static pointer.
    EVOLIS_LIB const char* evolis_to_utf8(const wchar_t* src);

    /// Convert UTF-8 string to UTF-16 string (wide chars). Returns a static pointer.
    EVOLIS_LIB const wchar_t* evolis_to_utf16(const char* src);
#endif // _WIN32

//
// ToC/ERROR MANAGEMENT
// --------------------
//

#define EVOLIS_RETURN_CODES(X) \
    X(OK, 0) \
    X(EUNDEFINED, -1) \
    X(EUNSUPPORTED, -5) \
    X(EPARAMS, -6) \
    X(ETIMEOUT, -7) \
    X(SESSION_ETIMEOUT, -10) \
    X(SESSION_EBUSY, -11) \
    X(SESSION_DISABLED, -12) \
    X(SESSION_FAILED, -13) \
    X(SESSION_ENABLED, -14) \
    X(PRINT_EDATA, -20) \
    X(PRINT_NEEDACTION, -21) \
    X(PRINT_EMECHANICAL, -22) \
    X(PRINT_WAITCARDINSERT, -23) \
    X(PRINT_WAITCARDEJECT, -24) \
    X(PRINT_EUNKNOWNRIBBON, -25) \
    X(PRINT_ENOIMAGE, -26) \
    X(PRINT_WSETTING, -27) \
    X(LAM_ENOCOM, -40) \
    X(LAM_EDEVICE, -41) \
    X(LAM_ERROR, -42) \
    X(LAM_EVALUE, -43) \
    X(MAG_ERROR, -50) \
    X(MAG_EDATA, -51) \
    X(MAG_EBLANK, -52) \
    X(PRINTER_ENOCOM, -60) \
    X(PRINTER_EREPLY, -61) \
    X(PRINTER_EOTHER, -62) \
    X(PRINTER_EBUSY, -63) \
    X(PRINTER_NOSTATUS, -64) \
    X(SVC_ENOCOM, -10000) \
    X(SVC_EREPLY, -10001) \
    X(SVC_ERROR, -10002) \
    X(SVC_EDATA, -10003) \
    X(SVC_NO_EVENT, -10004) \
    X(SVC_EEVENT, -10005) \
    X(SVC_EACTION, -10006) \
    X(HTTP_REPLY_NOT_OK, -20000) \
    X(HTTP_EREQUEST_ERROR, -20001) \
    X(HTTP_EREPLY_FORMAT, -20002) \
    X(HTTP_ERROR, -20500) \

typedef enum evolis_return_code_e {
    EVOLIS_RC_OK = 0,                       //!< Everything is good.
    EVOLIS_RC_EUNDEFINED = -1,              //!< Error code when an undefined error occurs.
    EVOLIS_RC_EUNSUPPORTED = -5,            //!< Error code when the library or printer does not support requested feature.
    EVOLIS_RC_EPARAMS = -6,                 //!< Invalid params given to the API.
    EVOLIS_RC_ETIMEOUT = -7,                //!< A timeout occured during function call.
    EVOLIS_RC_SESSION_ETIMEOUT = -10,       //!< Printer reservation have expired.
    EVOLIS_RC_SESSION_EBUSY = -11,          //!< Printer in use, session detected.
    EVOLIS_RC_SESSION_DISABLED = -12,       //!< Session management is disabled. See evolis_set_session_management().
    EVOLIS_RC_SESSION_FAILED = -13,         //!< An error was encountered while trying to reserve the printer
    EVOLIS_RC_SESSION_ENABLED = -14,        //!< This operation is not available when the session management is on. See evolis_set_session_management().
    EVOLIS_RC_PRINT_EDATA = -20,            //!< Bad input data, check images and settings.
    EVOLIS_RC_PRINT_NEEDACTION = -21,       //!< Printer not ready to print. Cover open ? Feeder ?
    EVOLIS_RC_PRINT_EMECHANICAL = -22,      //!< Mechanical error happened while printing.
    EVOLIS_RC_PRINT_WAITCARDINSERT = -23,   //!< Avansia only
    EVOLIS_RC_PRINT_WAITCARDEJECT = -24,    //!< Avansia only
    EVOLIS_RC_PRINT_EUNKNOWNRIBBON = -25,   //!< Missing GRibbonType setting.
    EVOLIS_RC_PRINT_ENOIMAGE = -26,         //!< No image given.
    EVOLIS_RC_PRINT_WSETTING = -27,         //!< Settings were imported from the driver, and at least one could not be read
    EVOLIS_RC_LAM_ENOCOM = -40,             //!< The laminator module is missing or can't communicate with the printer
    EVOLIS_RC_LAM_EDEVICE = -41,            //!< The device is not a laminator module
    EVOLIS_RC_LAM_ERROR = -42,              //!< The lamination module indicated an error
    EVOLIS_RC_LAM_EVALUE = -43,             //!< The value used or returned by the lamination module doesn't match the expected format
    EVOLIS_RC_MAG_ERROR = -50,              //!< Error reading or writing magnetic data.
    EVOLIS_RC_MAG_EDATA = -51,              //!< The data that you are trying to write on the magnetic track is not valid.
    EVOLIS_RC_MAG_EBLANK = -52,             //!< Magnetic track is blank.
    EVOLIS_RC_PRINTER_ENOCOM = -60,         //!< Printer offline.
    EVOLIS_RC_PRINTER_EREPLY = -61,         //!< Printer reply contains "ERR".
    EVOLIS_RC_PRINTER_EOTHER = -62,         //!< macOS only. USB printer in use by other software.
    EVOLIS_RC_PRINTER_EBUSY = -63,          //!< macOS only. CUPS is printing.
    EVOLIS_RC_PRINTER_NOSTATUS = -64,       //!< Status disabled on the printer.
    EVOLIS_RC_SVC_ENOCOM = -10000,          //!< Failed to communicate with the service
    EVOLIS_RC_SVC_EREPLY = -10001,          //!< Invalid service reply
    EVOLIS_RC_SVC_ERROR = -10002,           //!< The service indicated an error
    EVOLIS_RC_SVC_EDATA = -10003,           //!< The input data could not be sent to the service
    EVOLIS_RC_SVC_NO_EVENT = -10004,        //!< There is no active event for the printer
    EVOLIS_RC_SVC_EEVENT = -10005,          //!< The selected event is not active for the printer
    EVOLIS_RC_SVC_EACTION = -10006,         //!< The selected action is not active for current printer event
    EVOLIS_RC_HTTP_REPLY_NOT_OK = -20000,   //!< A reply was received with an HTTP error code (internal usage)
    EVOLIS_RC_HTTP_EREQUEST_ERROR = -20001, //!< The HTTP request is invalid
    EVOLIS_RC_HTTP_EREPLY_FORMAT = -20002,  //!< The received data didn't match the expected format
    EVOLIS_RC_HTTP_ERROR = -20500,          //!< An unexpected HTTP communication error occured
} evolis_return_code_t;

//
// ToC/DEVICE ENUMERATION
// ----------------------
//

typedef enum evolis_mark_e {
    EVOLIS_MA_INVALID = 0x00,
    EVOLIS_MA_EVOLIS = 1,
    EVOLIS_MA_EDIKIO = 3,
    EVOLIS_MA_BADGEPASS = 4,
    EVOLIS_MA_ID_MAKER = 5,
    EVOLIS_MA_DURABLE = 6,
    EVOLIS_MA_PLASCO = 7,
    EVOLIS_MA_IDENTISYS = 8,
    EVOLIS_MA_BODNO = 9,
    EVOLIS_MA_BRAVO = 10,
    EVOLIS_MA_ATC = 11,
} evolis_mark_t;

typedef enum evolis_model_e {
    EVOLIS_MO_INVALID = 0x00,
    EVOLIS_MO_EVOLIS_KC100 = 1,
    EVOLIS_MO_EVOLIS_KC100B = 2,
    EVOLIS_MO_EVOLIS_KC200 = 3,
    EVOLIS_MO_EVOLIS_KC200B = 4,
    EVOLIS_MO_EVOLIS_KM500B = 5,
    EVOLIS_MO_EVOLIS_KM2000B = 6,
    EVOLIS_MO_EVOLIS_PRIMACY = 7,
    EVOLIS_MO_EVOLIS_ALTESS = 8,
    EVOLIS_MO_EVOLIS_ALTESS_ELITE = 9,
    EVOLIS_MO_BADGEPASS_CONNECT = 10,
    EVOLIS_MO_BADGEPASS_NXT5000 = 11,
    EVOLIS_MO_ID_MAKER_PRIMACY = 12,
    EVOLIS_MO_EVOLIS_ELYPSO = 13,
    EVOLIS_MO_ID_MAKER_ELYPSO = 14,
    EVOLIS_MO_EVOLIS_ZENIUS = 15,
    EVOLIS_MO_ID_MAKER_ZENIUS = 16,
    EVOLIS_MO_ATC_ATC300 = 17,
    EVOLIS_MO_EVOLIS_APTEO = 18,
    EVOLIS_MO_BADGEPASS_CONNECT_LITE = 19,
    EVOLIS_MO_DURABLE_DURACARD_ID_300 = 20,
    EVOLIS_MO_EDIKIO_ACCESS = 21,
    EVOLIS_MO_EDIKIO_FLEX = 22,
    EVOLIS_MO_EDIKIO_DUPLEX = 23,
    EVOLIS_MO_EVOLIS_BADGY100 = 24,
    EVOLIS_MO_EVOLIS_BADGY200 = 25,
    EVOLIS_MO_BODNO_BADGY100X = 26,
    EVOLIS_MO_BODNO_BADGY200X = 27,
    EVOLIS_MO_EVOLIS_LAMINATION_MODULE = 28,
    EVOLIS_MO_EVOLIS_KC_ESSENTIAL = 29,
    EVOLIS_MO_EVOLIS_KC_PRIME = 30,
    EVOLIS_MO_ATC_ATC310 = 31,
    EVOLIS_MO_EVOLIS_KC_MAX = 32,
    EVOLIS_MO_EVOLIS_PRIMACY_2 = 33,
    EVOLIS_MO_EVOLIS_ASMI = 34,
    EVOLIS_MO_BADGEPASS_NXTELITE = 35,
    EVOLIS_MO_BADGEPASS_CONNECTPLUS = 36,
    EVOLIS_MO_ID_MAKER_PRIMACY_INFINITY = 37,
    EVOLIS_MO_PLASCO_PRIMACY_2_LE = 38,
    EVOLIS_MO_IDENTISYS_PRIMACY_2_SE = 39,
    EVOLIS_MO_BRAVO_DC_3300 = 40,
    EVOLIS_MO_EVOLIS_EPX300 = 41,
    EVOLIS_MO_EVOLIS_AVANSIA = 42,
    EVOLIS_MO_EVOLIS_AGILIA = 43,
    EVOLIS_MO_ATC_ATC600 = 44,
    EVOLIS_MO_EVOLIS_QUANTUM2 = 45,
} evolis_model_t;

typedef enum evolis_link_e {
    EVOLIS_LI_INVALID,
    EVOLIS_LI_TCP,
    EVOLIS_LI_USB,
    EVOLIS_LI_FILE,
    EVOLIS_LI_MODEL,
} evolis_link_t;

/// Structure holding the printer device information
typedef struct evolis_device_s {
    /// Printer ID
    char            id[128];

    /// Printer Name (UTF-8 string).
    char            name[256];

    /// Display Name (UTF-8 string).
    char            displayName[256];

    /// URI of the printer
    char            uri[512];

    /// Printer's mark enum value
    evolis_mark_t   mark;

    /// Printer's model enum value
    evolis_model_t  model;

    /// Tells if the printer is supervised or not by evolis premium suite service.
    bool            isSupervised;

    /// Reflect the printer state given by operating system.
    bool            isOnline;

    /// Indicates how the device is connected to the computer
    evolis_link_t   link;

    /// Driver version (Windows and CUPS printers only).
    char            driverVersion[128];
} evolis_device_t;

/// Get device list. Takes a list of model ended by zero.
EVOLIS_LIB int evolis_get_devices(evolis_device_t** devices, ...);

/// Free device list returned by evolis_get_devices().
EVOLIS_WRA void evolis_free_devices(_In_ evolis_device_t* devices);

/// Returns a string describing the mark argument.
EVOLIS_LIB const char* evolis_get_mark_name(_In_ evolis_mark_t mark);

/// Returns a string describing the model argument.
EVOLIS_LIB const char* evolis_get_model_name(_In_ evolis_model_t model);

//
// ToC/DEVICE I/O
// --------------
//

/// An internal type representing the device context.
///
/// @see evolis_open()
/// @see evolis_close()
typedef void evolis_t;

/// The printer type is used to establish the connection to the printer. All
/// Evolis printers have the save communication protocol except for the Avansia
/// which have a specific one.
///
/// Over IP, the printer type can be detected thus you can use the
/// `EVOLIS_TY_AUTO` enum value. In any case, specifying the right printer type
/// is more efficient.
typedef enum evolis_type_e {
    EVOLIS_TY_AUTO = 0,
    EVOLIS_TY_EVOLIS = 1,
    EVOLIS_TY_AVANSIA = 2,
} evolis_type_t;

/// List of error management modes of the printer.
typedef enum evolis_error_management_e {
    EVOLIS_EM_UNKNOWN    = -1,

    /// Means that the printer manages errors.
    EVOLIS_EM_PRINTER    = 0,

    /// Let the software using the printer manage errors.
    EVOLIS_EM_SOFTWARE   = 2,

    /// Means that the printer is supervised by the Evolis Premium Suite.
    /// This value can't be set. It can only be read.
    EVOLIS_EM_SUPERVISED = 38,
} evolis_error_management_t;

/// List of the different modes for evolis_open_with_mode
typedef enum evolis_open_mode_e {
    /// Automatically determines which other mode should be used
    EVOLIS_OM_AUTO = 0,
    /// Direct communication with the printer
    EVOLIS_OM_DIRECT = 1,
    /// The communications with the printer will go through the Evolis Supervision Service
    EVOLIS_OM_SUPERVISED = 2,
} evolis_open_mode_t;

/// Connect to the printer referenced by the `name` argument.
/// Same as evolis_open_with_mode(a, EVOLIS_OM_AUTO)
EVOLIS_WRA evolis_t* evolis_open(_In_ const char* name);

/// Connect to a printer with URL and printer type.
/// @deprecated Please use `evolis_open()` instead.
EVOLIS_DEPRECATED
EVOLIS_LIB evolis_t* evolis_open2(_In_ const char* device, _In_ evolis_type_t type);

/// Connect to the printer referenced by the `name` argument in the given mode.
EVOLIS_WRA evolis_t* evolis_open_with_mode(_In_ const char* name, _In_ evolis_open_mode_t mode);

/// Return the mode of communication used with the printer.
EVOLIS_WRA int evolis_get_open_mode(_In_ evolis_t* printer, _Out_ evolis_open_mode_t* mode);

/// Close connection to the printer.
EVOLIS_WRA void evolis_close(_In_ evolis_t* printer);

/// Printer firmware update.
EVOLIS_WRA int evolis_firmware_update(_In_ evolis_t* printer, _In_ const char* path);

/// Printer firmware update with timeout.
EVOLIS_WRA int evolis_firmware_updatet(_In_ evolis_t* printer, _In_ const char* path, _In_ int timeout);

/// Printer firmware update with buffer.
EVOLIS_WRA int evolis_firmware_updateb(_In_ evolis_t* printer, _In_ const evobuf* data, _In_ size_t size);

/// Printer firmware update with buffer and timeout.
EVOLIS_WRA int evolis_firmware_updatebt(_In_ evolis_t* printer, _In_ const evobuf* data, _In_ size_t size, _In_ int timeout);

/// Set io timeout value.
EVOLIS_LIB void evolis_set_timeout(_In_ evolis_t* printer, _In_ int ms);

/// Get io timeout value.
EVOLIS_LIB int evolis_get_timeout(_In_ evolis_t* printer);

/// Read data from the printer.
EVOLIS_LIB int32_t evolis_read(_In_ evolis_t* printer, _Out_ evobuf* data, _In_ size_t maxSize);

/// Read data from the printer with custom timeout.
EVOLIS_WRA int32_t evolis_readt(_In_ evolis_t* printer, _Out_ evobuf* data, _In_ size_t maxSize, _In_ int timeout);

/// Send data to the printer.
EVOLIS_LIB int32_t evolis_write(_In_ evolis_t* printer, _In_ const evobuf* data, _In_ size_t size);

/// Send data to the printer with custom timeout.
EVOLIS_WRA int32_t evolis_writet(_In_ evolis_t* printer, _In_ const evobuf* data, _In_ size_t size, _In_ int timeout);

/// Send a command to the printer then read the reply.
EVOLIS_LIB int32_t evolis_command(_In_ evolis_t* printer, _In_ const evobuf* cmd, _In_ size_t cmdSize, _Out_ evobuf* reply, _In_ size_t replyMaxSize);

/// Like evolis_command() but with a timeout arg (in milliseconds).
EVOLIS_WRA int32_t evolis_commandt(_In_ evolis_t* printer, _In_ const evobuf* cmd, _In_ size_t cmdSize, _Out_ evobuf* reply, _In_ size_t replyMaxSize, _In_ int timeout);

/// Make a reservation of the printer. If session is EVOLIS_SESSION_FREE (0)
/// a random id is generated. The function will wait the printer to be available,
/// at most, for waitMs. If waitMs is null then only one try is made.
EVOLIS_WRA int evolis_reserve(_In_ evolis_t* printer, _In_ int session, _In_ int waitMs);

/// Release the reservation of the printer.
EVOLIS_WRA int evolis_release(_In_ evolis_t* printer);

/// Software reset of the printer.
EVOLIS_LIB int evolis_reset(_In_ evolis_t* printer, _In_ int timeout, _Out_ char* timeouted);

/// Get error management mode of the printer (see evolis_error_management_t).
EVOLIS_WRA int evolis_get_error_management(_In_ evolis_t* printer, _Out_ evolis_error_management_t* em);

/// Set error management mode of the printer (PRINTER or SOFTWARE only).
EVOLIS_WRA int evolis_set_error_management(_In_ evolis_t* printer, _In_ evolis_error_management_t em);

/// Get session management feature status, true by default.
/// On Android/USB, Quantum it's false by default.
EVOLIS_WRA bool evolis_get_session_management(_In_ evolis_t* printer);

/// Set session management behavior.
/// If false, then session reservation does nothing. Also it doesn't check
/// if printer is reserved before communicating.
EVOLIS_WRA void evolis_set_session_management(_In_ evolis_t* printer, _In_ bool on);

/// Clear printer errors, should be use when print returned a EVOLIS_RC_MECHANICAL_ERROR error.
EVOLIS_WRA int evolis_clear_mechanical_errors(_In_ evolis_t* printer);

//
// ToC/DEVICE INFO
// ----------------
//

/// The printer info struct contains general information of the printer. It is
/// populated when calling `evolis_open()` function. You can retrieve it by
/// calling `evolis_info()`.
typedef struct evolis_info_s {
    char            name[128];                  //!< The device name (UTF-8 string).
    evolis_type_t   type;                       //!< The device type (Evolis or Avansia).
    evolis_mark_t   mark;
    char            markName[32];
    evolis_model_t  model;
    char            modelName[32];              //!< The name of the printer model.
    uint32_t        modelId;                    //!< An id representing the printer model.
                                                //!< Always ``0`` for Avansia printers.
    char            fwVersion[16];              //!< The firmware version.
    char            serialNumber[16];           //!< Serial number of the printer.
    char            printHeadKitNumber[16];     //!< Serial number of the print head kit.
    char            zone[16];                   //!< The printer zone.
    bool            hasFlip;                    //!< ``1`` if the printer can flip the card (duplex mode), ``0`` otherwise.
    bool            hasEthernet;                //!< ``1`` if the printer has ethernet feature, ``0`` otherwise.
    bool            hasWifi;                    //!< ``1`` if the printer has wifi feature, ``0`` otherwise.
    bool            hasLaminator;               //!< ``1`` if the printer has at least one laminator, ``0`` otherwise.
    bool            hasLaminator2;              //!< ``1`` if the printer has two laminators, ``0`` otherwise.
    bool            hasMagEnc;                  //!< ``1`` if the printer has mag encoding feature, ``0`` otherwise.
    bool            hasJisMagEnc;               //!< True if the mag encoder is of type "JIS".
    bool            hasSmartEnc;                //!< ``1`` if the printer has smart encoding feature, ``0`` otherwise.
    bool            hasContactLessEnc;          //!< ``1`` if the printer has contact less feature, ``0`` otherwise.
    bool            hasLcd;                     //!< ``1`` if the printer has LCD screen feature, ``0`` otherwise.
    bool            hasKineclipse;              //!< ``1`` if the printer has kineclipse feature, ``0`` otherwise.
    bool            hasLock;                    //!< ``1`` if the printer has lock system feature, ``0`` otherwise.
    bool            hasScanner;                 //!< ``1`` if the printer has scanner, ``0`` otherwise.

    uint32_t        insertionCaps;              //!< A bitmask containing supported insertion modes.
    uint32_t        ejectionCaps;               //!< A bitmask containing supported ejection modes.
    uint32_t        rejectionCaps;              //!< A bitmask containing supported rejection modes.

    char            lcdFwVersion[16];           //!< The LCD screen firmware version.
    char            lcdGraphVersion[16];        //!< The LCD screen Graphical Resources version.

    char            scannerFwVersion[64];       //!< The scanner's firmware version.
} evolis_info_t;

/// List of ribbon accepted by Evolis printers.
typedef enum evolis_ribbon_type_e {
    EVOLIS_RT_UNKNOWN        = -1,
    EVOLIS_RT_YMCKO          = 0,
    EVOLIS_RT_YMCKOS         = 3,
    EVOLIS_RT_YMCKOS13       = 5,
    EVOLIS_RT_YMCKOK         = 4,
    EVOLIS_RT_YMCKOKS13      = 9,
    EVOLIS_RT_YMCKOKOS       = 10,
    EVOLIS_RT_YMCKOO         = 13,
    EVOLIS_RT_KO             = 1,
    EVOLIS_RT_KBLACK         = 100,
    EVOLIS_RT_KWHITE         = 105,
    EVOLIS_RT_KRED           = 103,
    EVOLIS_RT_KGREEN         = 102,
    EVOLIS_RT_KBLUE          = 101,
    EVOLIS_RT_KSCRATCH       = 108,
    EVOLIS_RT_KMETALSILVER   = 107,
    EVOLIS_RT_KMETALGOLD     = 106,
    EVOLIS_RT_KSIGNATURE     = 114,
    EVOLIS_RT_KWAX           = 112,
    EVOLIS_RT_KPREMIUM       = 115,
    EVOLIS_RT_KRMS           = 116,
    EVOLIS_RT_HOLO           = 91,
    EVOLIS_RT_SOKO           = 12,
    EVOLIS_RT_YMCFK          = 1002,
    EVOLIS_RT_YMCK           = 1000,
    EVOLIS_RT_YMCKS          = 1050,
    EVOLIS_RT_YMCKH          = 1003,
    EVOLIS_RT_YMCKI          = 1004,
    EVOLIS_RT_YMCKK          = 1001,
    EVOLIS_RT_YMCKKS         = 1051,
    EVOLIS_RT_YMCKKI         = 1005,
    EVOLIS_RT_KBLACK_R       = 1100,
    EVOLIS_RT_CLEAR          = 2000,
} evolis_ribbon_type_t;

/// List of RW cards accepted by Evolis printers.
typedef enum evolis_rw_card_type_e {
    EVOLIS_RW_UNKNOWN = -1,
    EVOLIS_RW_MBLACK = 0,
    EVOLIS_RW_MBLUE = 1,
    EVOLIS_RW_CUSTOM_FRONT = 2,
    EVOLIS_RW_CUSTOM_DUPLEX = 3,
} evolis_rw_card_type_t;


/// Structure containing ribbon information.
///
/// @see evolis_get_ribbon()
typedef struct evolis_ribbon_s {
    char                    description[64];
    char                    zone[8];
    evolis_ribbon_type_t    type;
    int                     capacity;
    int                     remaining;
    int                     progress;
    char                    productCode[16];
    uint32_t                batchNumber;
    char                    buildAt[24];
    char                    serialNumber[24];
    char                    internalCode[24];
} evolis_ribbon_t;

typedef struct evolis_cleaning_s {
    int  totalCardCount;                    //!< Number of card inserted.

    int  cardCount;                         //!< Number of card inserted since last cleaning.
    int  cardCountBeforeWarning;            //!< Remaining card count before warning.
    int  cardCountBeforeWarrantyLost;       //!< Remaining card count before warranty lost.

    int  cardCountAtLastCleaning;           //!< Number of card inserted at last cleaning.

    int  regularCleaningCount;              //!< Number of regular cleaning.
    int  advancedCleaningCount;             //!< Number of advanced cleaning.

    bool printHeadUnderWarranty;            //!< Print head under warranty or not.

    int warningThreshold;                   //!< Advised cleaning interval.
    int warrantyLostThreshold;              //!< Mandatory cleaning interval.
} evolis_cleaning_t;

/// Enumeration to customize cache behavior.
typedef enum evolis_cache_e {
    EVOLIS_CA_NO_CACHE,                     //!< Don't want to retrieve cache, i/o only.
    EVOLIS_CA_CACHE_ON_ERROR,               //!< Retrieve cache if i/o error.
    EVOLIS_CA_CACHE_ONLY,                   //!< Retrieve cache, no i/o operations.
} evolis_cache_t;

/// Get printer info.
/// Same as evolis_get_info2(a, b, EVOLIS_CA_CACHE_ON_ERROR).
EVOLIS_WRA int evolis_get_info(_In_ evolis_t* printer, _Out_ evolis_info_t* info);

/// Get printer info.
EVOLIS_LIB int evolis_get_info2(_In_ evolis_t* printer, _Out_ evolis_info_t* info, _In_ evolis_cache_t c);

/// Get ribbon info.
/// Same as evolis_get_ribbon2(a, b, EVOLIS_CA_CACHE_ON_ERROR).
EVOLIS_WRA int evolis_get_ribbon(_In_ evolis_t* printer, _Out_ evolis_ribbon_t* ribbon);

/// Get ribbon info.
EVOLIS_LIB int evolis_get_ribbon2(_In_ evolis_t* printer, _Out_ evolis_ribbon_t* ribbon, _In_ evolis_cache_t c);

/// Get retransfer film info.
/// Same as evolis_get_retransfer_film2(a, b, EVOLIS_CA_CACHE_ON_ERROR).
EVOLIS_WRA int evolis_get_retransfer_film(_In_ evolis_t* printer, _Out_ evolis_ribbon_t* ribbon);

/// Get retransfer film info.
EVOLIS_LIB int evolis_get_retransfer_film2(_In_ evolis_t* printer, _Out_ evolis_ribbon_t* ribbon, _In_ evolis_cache_t c);

/// Get cleaning info.
/// Same as evolis_get_cleaning2(a, b, EVOLIS_CA_CACHE_ON_ERROR).
EVOLIS_WRA int evolis_get_cleaning(_In_ evolis_t* printer, _Out_ evolis_cleaning_t* info);

/// Get cleaning info.
EVOLIS_LIB int evolis_get_cleaning2(_In_ evolis_t* printer, _Out_ evolis_cleaning_t* info, _In_ evolis_cache_t c);

/// Get ribbon name.
EVOLIS_LIB const char* evolis_get_ribbon_name(_In_ evolis_ribbon_type_t rt);

//
// ToC/DEVICE STATE
// ----------------
//

typedef enum evolis_major_state_e {
    EVOLIS_MJ_OFF = 0,
    EVOLIS_MJ_READY = 1,
    EVOLIS_MJ_WARNING = 2,
    EVOLIS_MJ_ERROR = 3,
} evolis_major_state_t;

typedef enum evolis_minor_state_e {
    EVOLIS_MI_PRINTER_UNKNOWN = 0,
    EVOLIS_MI_PRINTER_OFFLINE = 1,
    /// TODO - MUST be removed.
    EVOLIS_MI_PRINTER_SUPERVISION_UNINITIALIZED = 2,
    /// TODO - MUST be removed.
    EVOLIS_MI_PRINTER_SUPERVISION_INITIALIZING = 3,
    EVOLIS_MI_PRINTER_STATUS_DISABLED = 4,
    EVOLIS_MI_PRINTER_NOT_SUPERVISED = 5,
    EVOLIS_MI_PRINTER_READY = 6,
    EVOLIS_MI_NOT_FLIP_ACT = 7,
    EVOLIS_MI_BUSY = 8,
    EVOLIS_MI_INTERNALERROR = 9,
    EVOLIS_MI_INF_LAMI_CLEANING_RUNNING = 10,
    EVOLIS_MI_INF_LAMI_TEMP_NOT_READY = 11,
    EVOLIS_MI_INF_LAMI_UPDATING_FIRMWARE = 12,
    EVOLIS_MI_INF_LAMINATE_LOW = 13,
    EVOLIS_MI_INF_LAMINATE_UNKNOWN = 14,
    EVOLIS_MI_INF_LAMINATING_RUNNING = 15,
    EVOLIS_MI_DEF_LAMI_COVER_OPEN = 16,
    EVOLIS_MI_DEF_LAMI_HOPPER_FULL = 17,
    EVOLIS_MI_DEF_LAMINATE_END = 18,
    EVOLIS_MI_DEF_LAMINATE_UNSUPPORTED = 19,
    EVOLIS_MI_DEF_NO_LAMINATE = 20,
    EVOLIS_MI_ERR_LAMI_COVER_OPEN = 21,
    EVOLIS_MI_ERR_LAMI_MECHANICAL = 22,
    EVOLIS_MI_ERR_LAMI_TEMPERATURE = 23,
    EVOLIS_MI_ERR_LAMINATE = 24,
    EVOLIS_MI_ERR_LAMINATE_END = 25,
    EVOLIS_MI_CFG_EXTENDED_RESOLUTION = 26,
    EVOLIS_MI_CFG_FLIP = 27,
    EVOLIS_MI_CFG_MAGNETIC = 28,
    EVOLIS_MI_INF_CLEAN_2ND_PASS = 29,
    EVOLIS_MI_INF_CLEAN_LAST_OUTWARRANTY = 30,
    EVOLIS_MI_INF_CLEANING = 31,
    EVOLIS_MI_INF_CLEANING_ADVANCED = 32,
    EVOLIS_MI_INF_CLEANING_REQUIRED = 33,
    EVOLIS_MI_INF_CLEANING_RUNNING = 34,
    EVOLIS_MI_INF_CLEAR_LOW = 35,
    EVOLIS_MI_INF_CLEAR_UNKNOWN = 36,
    EVOLIS_MI_INF_ENCODING_RUNNING = 37,
    EVOLIS_MI_INF_FEEDER_NEAR_EMPTY = 38,
    EVOLIS_MI_INF_PRINTING_RUNNING = 39,
    EVOLIS_MI_INF_RETRANSFER_RUNNING = 40,
    EVOLIS_MI_INF_HEATING = 41,
    EVOLIS_MI_INF_RIBBON_LOW = 42,
    EVOLIS_MI_INF_SLEEP_MODE = 43,
    EVOLIS_MI_INF_SLEEP_MODE_FULL = 44,
    EVOLIS_MI_INF_UNKNOWN_RIBBON1 = 45,
    EVOLIS_MI_INF_UNKNOWN_RIBBON2 = 46,
    EVOLIS_MI_INF_UPDATING_FIRMWARE = 47,
    EVOLIS_MI_INF_WRONG_ZONE_ALERT = 48,
    EVOLIS_MI_INF_WRONG_ZONE_CLEAR = 49,
    EVOLIS_MI_INF_WRONG_ZONE_CLEAR_ALERT = 50,
    EVOLIS_MI_INF_WRONG_ZONE_CLEAR_EXPIRED = 51,
    EVOLIS_MI_INF_WRONG_ZONE_RIBBON = 52,
    EVOLIS_MI_INF_WRONG_ZONE_EXPIRED = 53,
    EVOLIS_MI_DEF_CARD_ON_EJECT = 54,
    EVOLIS_MI_DEF_CLEAR_ENDED = 55,
    EVOLIS_MI_DEF_CLEAR_UNSUPPORTED = 56,
    EVOLIS_MI_DEF_COOLING = 57,
    EVOLIS_MI_DEF_COVER_OPEN = 58,
    EVOLIS_MI_DEF_FEEDER_EMPTY = 59,
    EVOLIS_MI_DEF_HOPPER_FULL = 60,
    EVOLIS_MI_DEF_NO_CLEAR = 61,
    EVOLIS_MI_DEF_NO_RIBBON = 62,
    EVOLIS_MI_DEF_POWER_SUPPLY = 63,
    EVOLIS_MI_DEF_PRINTER_LOCKED = 64,
    /// @warning Not evaluated
    EVOLIS_MI_DEF_RECEPTACLE_OPEN = 65,
    EVOLIS_MI_DEF_REJECT_BOX_COVER_OPEN = 66,
    EVOLIS_MI_DEF_REJECT_BOX_FULL = 67,
    EVOLIS_MI_DEF_REMOVE_RIBBON = 68,
    EVOLIS_MI_DEF_RIBBON_ENDED = 69,
    EVOLIS_MI_DEF_UNSUPPORTED_RIBBON = 70,
    EVOLIS_MI_DEF_WAIT_CARD = 71,
    EVOLIS_MI_ERR_BAD_CLEAR = 72,
    EVOLIS_MI_ERR_BAD_RIBBON = 73,
    EVOLIS_MI_ERR_BLANK_TRACK = 74,
    EVOLIS_MI_ERR_CARD_ON_EJECT = 75,
    EVOLIS_MI_ERR_CLEAR_ENDED = 76,
    EVOLIS_MI_ERR_CLEAR_ERROR = 77,
    EVOLIS_MI_ERR_COVER_OPEN = 78,
    EVOLIS_MI_ERR_FEATURE = 79,
    EVOLIS_MI_ERR_FEEDER_EMPTY = 80,
    EVOLIS_MI_ERR_FEEDER_ERROR = 81,
    EVOLIS_MI_ERR_HEAD_TEMP = 82,
    EVOLIS_MI_ERR_HOPPER_FULL = 83,
    EVOLIS_MI_ERR_MAGNETIC_DATA = 84,
    EVOLIS_MI_ERR_MECHANICAL = 85,
    EVOLIS_MI_ERR_NO_CARD_INSERTED = 86,
    /// @warning Not evaluated
    EVOLIS_MI_ERR_NO_OPTION = 87,
    EVOLIS_MI_ERR_READ_MAGNETIC = 88,
    EVOLIS_MI_ERR_REJECT_BOX_FULL = 89,
    EVOLIS_MI_ERR_REJECT_BOX_COVER_OPEN = 90,
    EVOLIS_MI_ERR_RET_TEMPERATURE = 91,
    EVOLIS_MI_ERR_RIBBON_ENDED = 92,
    EVOLIS_MI_ERR_RIBBON_ERROR = 93,
    EVOLIS_MI_ERR_WRITE_MAGNETIC = 94,
    EVOLIS_MI_AVANSIA_DEF_FEEDER_EMPTY = 95,
    EVOLIS_MI_AVANSIA_ERR_FEEDER_EMPTY = 96,
    EVOLIS_MI_AVANSIA_DEF_COVER_OPEN = 97,
    EVOLIS_MI_AVANSIA_ERR_COVER_OPEN = 98,
    EVOLIS_MI_AVANSIA_DEF_TEMP_TOOLOW = 99,
    EVOLIS_MI_AVANSIA_DEF_RIBBON_ENDED = 100,
    EVOLIS_MI_AVANSIA_ERR_RIBBON_ENDED = 101,
    EVOLIS_MI_AVANSIA_DEF_RIBBON_ERROR = 102,
    EVOLIS_MI_AVANSIA_ERR_RIBBON_ERROR = 103,
    EVOLIS_MI_AVANSIA_DEF_FILM_ENDED = 104,
    EVOLIS_MI_AVANSIA_ERR_FILM_ENDED = 105,
    EVOLIS_MI_AVANSIA_DEF_FILM_ERROR = 106,
    EVOLIS_MI_AVANSIA_ERR_FILM_ERROR = 107,
    EVOLIS_MI_AVANSIA_DEF_RIBBON_FILM_ENDED = 108,
    EVOLIS_MI_AVANSIA_ERR_RIBBON_FILM_ENDED = 109,
    EVOLIS_MI_AVANSIA_ERR_CARD_JAM = 110,
    EVOLIS_MI_AVANSIA_ERR_SERVICE_CALL = 111,
    EVOLIS_MI_AVANSIA_ERR_READ_MAGNETIC = 112,
    EVOLIS_MI_AVANSIA_ERR_WRITE_MAGNETIC = 113,
    EVOLIS_MI_AVANSIA_ERR_IC_ERROR = 114,
    EVOLIS_MI_AVANSIA_INF_UNKNOWN_RIBBON = 115,
    EVOLIS_MI_AVANSIA_ERR_MANUAL_REQUIRED = 116,
    EVOLIS_MI_AVANSIA_OPT_MAGNETIC = 117,
    EVOLIS_MI_AVANSIA_OPT_MAGNETIC_JIS2 = 118,
    EVOLIS_MI_DEF_FEEDER_OPEN = 119,
    EVOLIS_MI_ERR_FEEDER_OPEN = 120,
} evolis_minor_state_t;

/// Get device state.
EVOLIS_WRA int evolis_get_state(_In_ evolis_t* printer, _Out_ evolis_major_state_t* major, _Out_ evolis_minor_state_t* minor);

/// Helper to convert major state to a string.
EVOLIS_LIB const char* evolis_get_major_string(_In_ evolis_major_state_t major);

/// Helper to convert minor state to a string.
EVOLIS_LIB const char* evolis_get_minor_string(_In_ evolis_minor_state_t minor);

//
// ToC/CARD OPERATIONS
// -------------------
//

/// The following card entries are available for Evolis printers. Some entries
/// are not valid for all printers. See notes below for details.
///
/// @see evolis_set_input_tray()
typedef enum evolis_intray_e {
    /// The card insertion will be made with the cards feeder.
    /// Supported by :
    ///     - Avansia
    ///     - Zenius
    ///     - Primacy, Primacy 2
    ///     - Agilia, Excelio
    ///     - KC200, KC200B
    ///     - KM500B, KM2000B
    ///     - KC Prime, 
    EVOLIS_IT_FEEDER = 1,

    /// The card insertion will be made card by card.
    /// Supported by :
    ///     - Zenius
    ///     - Primacy, Primacy 2
    ///     - Elypso
    ///     - Agilia, Excelio
    ///     - KC Essential
    EVOLIS_IT_MANUAL = 2,

    /// The card insertion will be made card by card but will be triggered when
    /// a insertion command is received by the printer.
    /// Supported by :
    ///     - Avansia
    ///     - Zenius
    ///     - Primacy, Primacy 2
    ///     - Elypso
    ///     - Agilia, Excelio
    ///     - KC200, KC200B
    ///     - KM500B, KM2000B
    ///     - KC Essential, KC Prime, KC Max
    /// 
    /// To use this with Avansia printers, you will have to call `evolis_insert()`
    /// during the printing process in order to trigger the card insertion.
    /// @see avansia_print_status()
    EVOLIS_IT_MANUALANDCMD = 4,

    /// The card insertion will be made from printer's bezel.
    /// Supported by :
    ///     - KC200B
    ///     - KM500B, KM2000B
    ///     - KC Essential, KC Prime, KC Max
    EVOLIS_IT_BEZEL = 8,

    /// The card insertion can be made from to ways :
    ///     - MANUAL/FEEDER :
    ///       Concerned printers : Zenius, Agilia, Excelio, KC Prime, KC Max.
    ///       Card inserted like MANUAL (card-by-card). If no card
    ///       present, card is taken from FEEDER.
    ///     - BEZEL/FEEDER :
    ///       Concerned printers : KC200B, KM500B, KM2000B, KC Essential.
    ///       Card inserted from BEZEL. If no card present, card is
    ///       taken from FEEDER.
    EVOLIS_IT_BOTH = 16,

    /// Only available for customized printers without any feeder.
    EVOLIS_IT_NOFEEDER = 32,

    /// Insert card from standard card output.
    /// Supported by :
    ///     - Agilia, Excelio
    ///     - KC Essential, KC Prime, KC Max
    EVOLIS_IT_REAR = 64,

} evolis_intray_t;

/// The following card exit are available for Evolis printers. Some of the exits
/// are not valid for all printers. See notes below for details.
///
/// @see evolis_set_output_tray()
/// @see evolis_set_error_tray()
typedef enum evolis_outtray_e {
    /// Eject the card in the standard output tray (receptacle).
    /// Supported by :
    ///     - Avansia
    ///     - Zenius
    ///     - Primacy, Primacy 2
    ///     - KC200, KC200B
    ///     - KM500B, KM2000B
    ///     - Agilia, Excelio
    ///     - KC Prime
    /// 
    /// For Avansia printers the standard exit is the left side of the printer.
    EVOLIS_OT_STANDARD = 1,

    /// Supported by Avansia printers only. If set, the printer will wait for
    /// ejection command (see `evolis_eject()`) at the end of print.
    EVOLIS_OT_STANDARDSTANDBY = 2,

    /// Card by card ejection mode.
    /// Supported by :
    ///     - Agilia, Excelio
    ///     - Elypso
    ///     - Zenius
    ///     - KC Essential
    EVOLIS_OT_MANUAL = 4,

    /// Card will be ejected in the rejection tray.
    /// Supported by :
    ///     - Agilia, Excelio
    ///     - Avansia
    ///     - Elypso
    ///     - KC200
    ///     - KM500B
    ///     - KM2000B.
    ///     - Primacy
    ///     - Zenius
    ///     - KC Prime
    /// 
    /// With Avansia printers, the standard rejection tray is the right side.
    EVOLIS_OT_ERROR = 8,

    /// Supported by Avansia printers only. If set, the printer will wait for
    /// ejection command (see `evolis_eject()`) at the end of print.
    EVOLIS_OT_ERRORSTANDBY = 16,

    /// Eject the card without waiting.
    /// Supported by :
    ///     - Zenius
    ///     - Elypso
    ///     - KC Essential
    EVOLIS_OT_EJECT = 32,

    /// Eject the card through the bezel.
    /// Supported by :
    ///     - KC200B
    ///     - KM500B, KM2000B
    ///     - KC Prime, KC Max
    EVOLIS_OT_BEZEL = 64,

    /// Eject the card through the lower reject slot.
    /// Supported by :
    ///     - KC200, KC200B
    ///     - KM500B, KM2000B
    ///     - KC Essential, KC Prime, KC Max
    EVOLIS_OT_ERRORSLOT = 128,

    /// Eject the card to the locked box.
    /// Supported by Primacys with locking system.
    EVOLIS_OT_LOCKED = 256,

} evolis_outtray_t;

/// Below is the available card positions that you can use. Some could be
/// unavailable for your printer. See notes below for details.
typedef enum evolis_pos_e {
    /// Insert a card in the printer.
    /// 
    /// For Avansia printers, the insert is made inside a printing job when the
    /// return status of `avansia_print_restult()` is `AVANSIA_PR_STANDBY_INS`.
    EVOLIS_CP_INSERT = 0,
    /// Insert card from back side. Move it to
    /// default position.
    EVOLIS_CP_INSERTBACK = 1,
    /// Insert then eject a card from the printer.
    EVOLIS_CP_INSERTEJECT = 2,
    /// Eject the card from the printer.
    /// 
    /// For Avansia printers, the eject is made inside a printing job when the
    /// return status of `avansia_print_result()` is `AVANSIA_PR_STANDBY_EJE`.
    EVOLIS_CP_EJECT = 3,
    /// Reject the card from the printer.
    /// 
    /// TODO
    /// For Avansia printers, the insert is made inside a printing job when the
    /// return status is STANDBY. TODO Terminer la doc en fonction du retour de print_exec().
    EVOLIS_CP_REJECT = 4,
    /// Move the card to the smart station.
    /// The card is inserted if none in the printer.
    EVOLIS_CP_CONTACT = 5,
    /// Move the card to the contact station.
    /// The card is inserted if none in the printer.
    EVOLIS_CP_CONTACTLESS = 6,
    /// Move the card in order to scan it (below the contact station).
    /// The card is inserted if none in the printer.
    EVOLIS_CP_SCAN = 7,
#ifdef EVOLIS_SP_GWI
    /// Eject the card under the printer throught the bridge.
    EVOLIS_CP_EJECTBRIDGE = 1000,
    /// Insert the card to the indenting module.
    EVOLIS_CP_INSERTINDENTING = 1001,
    /// Eject the card from indenting module.
    EVOLIS_CP_EJECTINDENTING = 1002,
    /// Eject the card to the manual feeder.
    EVOLIS_CP_EJECTMANUALFEEDER = 1003,
    /// Eject the card to the reject box.
    EVOLIS_CP_EJECTREJECTBOX = 1004,
    /// Insert the card from bridge to contactless station.
    EVOLIS_CP_INSERTBRIDGECONTACLESS = 1005,
#endif
} evolis_pos_t;

/// Set card insertion mode.
EVOLIS_WRA int evolis_set_input_tray(_In_ evolis_t* printer, _In_ evolis_intray_t tray);

/// Get card insertion mode value.
EVOLIS_WRA int evolis_get_input_tray(_In_ evolis_t* printer, _Out_ evolis_intray_t* tray);

/// Set card ejection mode.
EVOLIS_WRA int evolis_set_output_tray(_In_ evolis_t* printer, _In_ evolis_outtray_t tray);

/// Get card ejection mode value.
EVOLIS_WRA int evolis_get_output_tray(_In_ evolis_t* printer, _Out_ evolis_outtray_t* tray);

/// Set card rejection mode.
EVOLIS_WRA int evolis_set_error_tray(_In_ evolis_t* printer, _In_ evolis_outtray_t tray);

/// Get rejection mode value.
EVOLIS_WRA int evolis_get_error_tray(_In_ evolis_t* printer, _Out_ evolis_outtray_t* tray);

/// Move the card in the printer.
EVOLIS_WRA int evolis_set_card_pos(_In_ evolis_t* printer, _In_ evolis_pos_t pos);

/// Insert a card in the printer.
EVOLIS_WRA int evolis_insert(_In_ evolis_t* printer);

/// Eject a card from the printer.
EVOLIS_WRA int evolis_eject(_In_ evolis_t* printer);

/// Reject a card from the printer.
EVOLIS_WRA int evolis_reject(_In_ evolis_t* printer);

//
// ToC/BEZEL SETTINGS
// ------------------
//

/// The default ejection length value.
/// @see evolis_bezel_set_offset
#define EVOLIS_DEFAULT_BEZEL_OFFSET 53 // In millimetters

/// The enumeration describe available BEZEL behavior.
typedef enum evolis_bezel_behavior_e {
    EVOLIS_BB_UNKNOWN = 0, //!< Unknown BEZEL behavior.
    EVOLIS_BB_REJECT = 1, //!< Card is ejected to the error tray if not taken.
    EVOLIS_BB_INSERT = 2, //!< Card is re-inserted if not taken.
    EVOLIS_BB_DONOTHING = 3, //!< Card stays in the BEZEL if not taken.
} evolis_bezel_behavior_t;

/// Get BEZEL behavior.
EVOLIS_WRA int evolis_bezel_get_behavior(_In_ evolis_t* printer, _Out_ evolis_bezel_behavior_t* bb);

/// Set BEZEL behavior.
EVOLIS_WRA int evolis_bezel_set_behavior(_In_ evolis_t* printer, _In_ evolis_bezel_behavior_t bb);

/// Get BEZEL delay (in seconds).
EVOLIS_WRA int evolis_bezel_get_delay(_In_ evolis_t* printer, _Out_ int* seconds);

/// Set BEZEL delay (in seconds).
EVOLIS_WRA int evolis_bezel_set_delay(_In_ evolis_t* printer, _In_ int seconds);

/// Get the ejection length (in millimetters) of the card.
EVOLIS_WRA int evolis_bezel_get_offset(_In_ evolis_t* printer, _Out_ int* mm);

/// Set the ejection length (in millimetters) of the card.
EVOLIS_WRA int evolis_bezel_set_offset(_In_ evolis_t* printer, _In_ int mm);

//
// ToC/FEEDER SELECTION
// --------------------
//

/// The enumeration is used to configure feeder of KC Max printers.
typedef enum evolis_feeder_e {
    EVOLIS_FE_UNKNOWN = 0, //!< Unknown feeder.
    EVOLIS_FE_A = 1, //!< Feeder A, KC Max printers only.
    EVOLIS_FE_B = 2, //!< Feeder B, KC Max printers only.
    EVOLIS_FE_C = 3, //!< Feeder C, KC Max printers only.
    EVOLIS_FE_D = 4, //!< Feeder D, KC Max printers only.
} evolis_feeder_t;

/// Get selected feeder for printer (KC Max (aka K24) only).
EVOLIS_WRA int evolis_get_feeder(_In_ evolis_t* printer, _Out_ evolis_feeder_t* f);

/// Set printer feeder to use for next card insertion (KC Max (aka K24) only).
EVOLIS_WRA int evolis_set_feeder(_In_ evolis_t* printer, _In_ evolis_feeder_t f);

//
// ToC/MAG ENCODING
// ----------------
//

/// List available track formats.
/// @see evolis_mag_write
/// @see evolis_mag_read
typedef enum evolis_mag_format_e {
    EVOLIS_MF_UNKNOWN = 0, 
    EVOLIS_MF_ISO1 = 1, //!< Accepts alphanumeric characters, see ISO/IEC-7811 for details.
    EVOLIS_MF_ISO2 = 2, //!< Accepts numeric characters, see ISO/IEC-7811 for details.
    EVOLIS_MF_ISO3 = 3, //!< Accepts numeric characters, see ISO/IEC-7811 for details.
    EVOLIS_MF_SIPASS = 4, 
    EVOLIS_MF_CUSTOM2 = 5, 
    EVOLIS_MF_JIS2 = 6, 
    EVOLIS_MF_CUSTOM4 = 7, 
} evolis_mag_format_t;

/// List coercivity level of magnetic stripes of the card.
/// @see evolis_mag_set_coercivity
typedef enum evolis_mag_coercivity_e {
    /// Use printer setting.
    EVOLIS_MC_PRINTER = 'p',

    /// Automatic mode, the printer will find the coercivity alone.
    EVOLIS_MC_AUTO = 'a',

    /// Low coercivity cards.
    EVOLIS_MC_LOCO = 'l',

    /// High coercivity cards.
    EVOLIS_MC_HICO = 'h',

} evolis_mag_coercivity_t;

/// Structure for reading/writing on magnetic tracks.
typedef struct evolis_mag_tracks_s {
    /// Tracks data.
    char tracks[3][256];

    /// The format to use for reading/writing data.
    evolis_mag_format_t formats[3];

    /// The coercivity to use for reading/writing on the card.
    evolis_mag_coercivity_t coercivity;

    /// The results of reading/writing each track.
    int results[3];

    /// True if the corresponding track must be read or encoded.
    bool processTrack[3];
} evolis_mag_tracks_t;

/// Initialize `evolis_mag_tracks_t` structure with default values.
/// No printer communication made here.
EVOLIS_WRA void evolis_mag_init(_Out_ evolis_mag_tracks_t* tracks);

/// Read coercivity level to use for reading/writing magnetic stripes.
EVOLIS_LIB int evolis_mag_get_coercivity(_In_ evolis_t* printer, _Out_ evolis_mag_coercivity_t* c);

/// Configure coercivity level to use for reading/writing magnetic stripes.
EVOLIS_LIB int evolis_mag_set_coercivity(_In_ evolis_t* printer, _In_ evolis_mag_coercivity_t c);

/// Helper function to retrieve track buffer.
EVOLIS_LIB int evolis_mag_get_track(_In_ evolis_mag_tracks_t* tracks, _In_ int track, _Out_ char** dataPtr);

/// Helper function to fill `evolis_mag_tracks_t` structure.
EVOLIS_LIB void evolis_mag_set_track(evolis_mag_tracks_t* tracks, int track, evolis_mag_format_t fmt, const char* data);

/// Write mag tracks to the card.
EVOLIS_WRA int evolis_mag_write(_In_ evolis_t* printer, _In_ evolis_mag_tracks_t* tracks);

/// Read all mag tracks from the card.
EVOLIS_WRA int evolis_mag_read(_In_ evolis_t* printer, _Out_ evolis_mag_tracks_t* tracks);

/// Read some mag tracks from the card.
EVOLIS_WRA int evolis_mag_read_tracks(_In_ evolis_t* printer, _Out_ evolis_mag_tracks_t* tracks, _In_ bool t0, _In_ bool t1, _In_ bool t2);

//
// ToC/PRINTING
// ------------
//

/// References the card face.
/// @see evolis_print_set_bitmap()
typedef enum evolis_face_e {
    EVOLIS_FA_FRONT = 0, //!< Front face of the card.
    EVOLIS_FA_BACK = 1, //!< Back face of the card.
} evolis_face_t;

/// References DPI resolutions.
typedef enum evolis_dpi_e {
    EVOLIS_DPI_300 = 0,
    EVOLIS_DPI_600 = 1,
    EVOLIS_DPI_1200 = 2,
} evolis_dpi_t;

/// Selects which settings rules to apply
/// Used only for print session settings, because the selection of rules to
/// apply for the SettingsManager is handled through specific settings
typedef enum evolis_settings_rules_level_e {
    /// Apply rules to prevent impossible configuration
    /// (eg overlay on a non overlay ribbon)
    EVOLIS_RL_MINIMUM_RULES = 0x0000,

    /// Update the DuplexType to match the ribbon's default
    EVOLIS_RL_UPDATE_DUPLEX = 0x0001,

    /// Set default layers configuration for the selected ribbon
    /// (eg activate the first overlay and black point if available)
    EVOLIS_RL_UPDATE_LAYERS = 0x0002,

    /// Apply UPDATE_DUPLEX and UPDATE_LAYERS rules
    EVOLIS_RL_RIBBON_FULL_UPDATE = 0x0003,

    /// Set the ribbon setting to match the one detected on the printer (if any)
    /// and applies RIBBON_FULL_UPDATE if the ribbon setting changes
    /// This implies additional I/O operations
    EVOLIS_RL_DETECT_RIBBON = 0x4000,

    /// Use information from the printer while applying the rules
    /// This may trigger additional I/O operations
    EVOLIS_RL_PRINTER_INFO = 0x8000,

    /// Update the Mag settings to match the configuration detected on the printer (if any)
    /// Requires PRINTER_INFO
    EVOLIS_RL_DETECT_MAG = 0x8010,

    /// Set the printing mode to match the one configured on the printer
    /// Requires PRINTER_INFO
    EVOLIS_RL_DETECT_PRINTING_MODE = 0x8020,

    /// Apply all rules
    EVOLIS_RL_ALL_RULES = 0xffff,

} evolis_settings_rules_level_t;

/// Print a test card.
EVOLIS_WRA int evolis_print_test_card(_In_ evolis_t* printer, _In_ int type);

/// Initialize a new printing session, and send a command to the printer to detect the configuration
EVOLIS_WRA int evolis_print_init(_In_ evolis_t* printer);

/// Initialize a new printing session using the defined ribbon as a base configuration
EVOLIS_WRA int evolis_print_init_with_ribbon(_In_ evolis_t* printer, _In_ evolis_ribbon_type_t ribbon);

/// Initialize a new printing session using the defined RW card as a base configuration
EVOLIS_WRA int evolis_print_init_with_rw_card(_In_ evolis_t* printer, _In_ evolis_rw_card_type_t ct);

/// Initialize a new printing session with the settings imported from the driver
EVOLIS_WRA int evolis_print_init_from_driver_settings(_In_ evolis_t* printer);

/// Removes all settings set in the printing session
EVOLIS_LIB void evolis_print_clear_settings(evolis_t* printer);

/// Removes all settings and images set in the printing session
EVOLIS_LIB void evolis_print_clear(evolis_t* printer);

/// Get the number of print settings
EVOLIS_WRA int evolis_print_get_setting_count(_In_ evolis_t* printer);

/// Indicates if a setting is valid for the print session
EVOLIS_WRA bool evolis_print_is_setting_valid(_In_ evolis_t* printer, _In_ evosettings_key_t key);

/// Get the setting at the given index
/// Setting are ordered by key, so inserting a new setting may change
/// the index of already present settings
EVOLIS_WRA evosettings_key_t evolis_print_get_setting_key(_In_ evolis_t* printer, _In_ int index);

/// Set a print context setting.
EVOLIS_WRA bool evolis_print_set_setting(_In_ evolis_t* printer, _In_ evosettings_key_t key, _In_ const char* value);

/// Set a print context setting.
EVOLIS_WRA bool evolis_print_set_int_setting(_In_ evolis_t* printer, _In_ evosettings_key_t key, _In_ int value);

/// Set a print context setting.
EVOLIS_WRA bool evolis_print_set_bool_setting(_In_ evolis_t* printer, _In_ evosettings_key_t key, _In_ bool value);

/// Get value of a print context setting.
EVOLIS_WRA bool evolis_print_get_setting(_In_ evolis_t* printer, _In_ evosettings_key_t key, _Out_ const char** value);

/// Get value of a print context setting.
EVOLIS_WRA bool evolis_print_get_int_setting(_In_ evolis_t* printer, _In_ evosettings_key_t key, _Out_ int* value);

/// Get value of a print context setting.
EVOLIS_WRA bool evolis_print_get_bool_setting(_In_ evolis_t* printer, _In_ evosettings_key_t key, _Out_ bool* value);

/// Apply rules on the settings
EVOLIS_LIB bool evolis_print_apply_settings_rules(_In_ evolis_t* printer, _In_ int rulesToApply);

/// Get the list of keys modified by the rules
EVOLIS_LIB int evolis_print_get_keys_updated_by_rules(_In_ evolis_t* printer, _Out_ evosettings_key_t* keys);

/// Removes a setting from the print context
EVOLIS_WRA bool evolis_print_remove_setting(_In_ evolis_t* printer, _In_ evosettings_key_t key);

/// Get the number of defined forced settings
EVOLIS_WRA int evolis_print_get_forced_setting_count(_In_ evolis_t* printer);

/// Get the forced setting at the given index
/// forced settings are ordered by key, so inserting a new forced setting may change
/// the index of already present forced settings
EVOLIS_WRA const char* evolis_print_get_forced_setting_key(_In_ evolis_t* printer, _In_ int index);

/// Set a print processing forced setting.
EVOLIS_WRA void evolis_print_set_forced_setting(_In_ evolis_t* printer, _In_ const char* key, _In_ const char* value);

/// Get value of a print processing forced setting.
EVOLIS_WRA bool evolis_print_get_forced_setting(_In_ evolis_t* printer, _In_ const char* key, _Out_ const char** value);

/// Removes an forced setting from the print context
EVOLIS_WRA bool evolis_print_remove_forced_setting(_In_ evolis_t* printer, _In_ const char* key);

/// Exports the generated configuration to a file
EVOLIS_WRA bool evolis_print_export_config(_In_ evolis_t* printer, _In_ const char* filepath, _In_ char separator);

/// @deprecated Kept for retrocompatibility, options have been renamed to forced settings
/// @see evolis_print_get_forced_setting_count
EVOLIS_DEPRECATED
EVOLIS_LIB int evolis_print_get_option_count(evolis_t* printer);

/// @deprecated Kept for retrocompatibility, options have been renamed to forced settings
/// @see evolis_print_get_forced_setting_key
EVOLIS_DEPRECATED
EVOLIS_LIB const char* evolis_print_get_option_key(evolis_t* printer, int index);

/// @deprecated Kept for retrocompatibility, options have been renamed to forced settings
/// @see evolis_print_set_forced_settings
EVOLIS_DEPRECATED
EVOLIS_LIB void evolis_print_set_option(evolis_t* printer, const char* key, const char* value);

/// @deprecated Kept for retrocompatibility, options have been renamed to forced settings
/// @see evolis_print_get_forced_settings
EVOLIS_DEPRECATED
EVOLIS_LIB bool evolis_print_get_option(evolis_t* printer, const char* key, const char** value);

/// @deprecated Kept for retrocompatibility, options have been renamed to forced settings
/// @see evolis_print_remove_forced_settings
EVOLIS_DEPRECATED
EVOLIS_LIB bool evolis_print_remove_option(evolis_t* printer, const char* key);

/// @deprecated Kept for retrocompatibility, options have been renamed to forced settings
/// @see evolis_print_export_forced_settings
EVOLIS_DEPRECATED
EVOLIS_LIB bool evolis_print_export_options(evolis_t* printer, const char* filepath, char separator);

/// Set PRN log state.
EVOLIS_WRA void evolis_print_set_prnlog(_In_ evolis_t* printer, _In_ bool enabled, _In_ const char* dirPath);

/// Get PRN log state.
EVOLIS_LIB bool evolis_print_get_prnlog(_In_ evolis_t* printer);

/// Set the image path to print.
EVOLIS_WRA int evolis_print_set_imagep(_In_ evolis_t* printer, _In_ evolis_face_t face, _In_ const char* path);

/// Set the image buffer to print.
EVOLIS_LIB int evolis_print_set_imageb(_In_ evolis_t* printer, _In_ evolis_face_t face, _In_ const evobuf* data, _In_ size_t size);

/// Set a blank image for one face
EVOLIS_LIB int evolis_print_set_blank_image(_In_ evolis_t* printer, _In_ evolis_face_t face);

/// Load bitmap at path and print it with black panel.
EVOLIS_WRA int evolis_print_set_blackp(_In_ evolis_t* printer, _In_ evolis_face_t face, _In_ const char* path);

/// Print bitmap buffer with black panel.
EVOLIS_LIB int evolis_print_set_blackb(_In_ evolis_t* printer, _In_ evolis_face_t face, _In_ const evobuf* data, _In_ size_t size);

/// Use the image at path to print with overlay panel.
EVOLIS_WRA int evolis_print_set_overlayp(_In_ evolis_t* printer, _In_ evolis_face_t face, _In_ const char* path);

/// Use the image buffer to print with overlay panel.
EVOLIS_LIB int evolis_print_set_overlayb(_In_ evolis_t* printer, _In_ evolis_face_t face, _In_ const evobuf* data, _In_ size_t size);

/// Use the image at path to print with second overlay panel.
EVOLIS_WRA int evolis_print_set_second_overlayp(_In_ evolis_t* printer, _In_ evolis_face_t face, _In_ const char* path);

/// Use the image buffer to print with second overlay panel.
EVOLIS_LIB int evolis_print_set_second_overlayb(_In_ evolis_t* printer, _In_ evolis_face_t face, _In_ const evobuf* data, _In_ size_t size);

/// Use the image at path as rewritable area definition.
EVOLIS_WRA int evolis_print_set_rw_areasp(_In_ evolis_t* printer, _In_ evolis_face_t face, _In_ const char* path);

/// Use the image buffer as rewritable area definition.
EVOLIS_LIB int evolis_print_set_rw_areasb(_In_ evolis_t* printer, _In_ evolis_face_t face, _In_ const char* data, _In_ size_t size);

/// Use the image at path to print with silver panel (Avansia).
EVOLIS_WRA int evolis_print_set_silverp(_In_ evolis_t* printer, _In_ evolis_face_t face, _In_ const char* path);

/// Use the image buffer to print with silver panel (Avansia).
EVOLIS_LIB int evolis_print_set_silverb(_In_ evolis_t* printer, _In_ evolis_face_t face, _In_ const evobuf* data, _In_ size_t size);

/// Start printing.
EVOLIS_LIB int evolis_print_exec(_In_ evolis_t* printer);

/// Start printing with a timeout (in seconds).
EVOLIS_WRA int evolis_print_exect(_In_ evolis_t* printer, _In_ int timeout);

/// Generate PRN and write it to a file
EVOLIS_WRA int evolis_print_to_file(_In_ evolis_t* printer, _In_ const char* path);

/// Generate PRN and write it to a buffer
EVOLIS_WRA int evolis_print_to_buffer(_In_ evolis_t* printer, _Out_ evobuf* buffer, _In_ size_t bufferSize);

/// Generate PRN and return its size
EVOLIS_WRA int evolis_print_get_prn_size(_In_ evolis_t* printer);

/// Set the value of the post-print auto-ejection setting.
EVOLIS_WRA bool evolis_print_set_auto_eject(_In_ evolis_t* ctx, _In_ bool on);

/// Get the value of the post-print auto-ejection setting.
EVOLIS_WRA bool evolis_print_get_auto_eject(_In_ evolis_t* ctx);

//
// ToC/SCAN
// --------
//

typedef enum evolis_scan_opt_e {
    EVOLIS_SO_WIDTH = 0,        //!< Card width in millimeters.
    EVOLIS_SO_HEIGHT = 1,       //!< Card height in millimeters.
    EVOLIS_SO_DPI = 2,          //!< By default scan is 600 DPI. See `evolis_dpi_t`.
    EVOLIS_SO_CARD_OFFSET = 3,  //!< Default value is 155. Should be between 90 and 220.
    EVOLIS_SO_CARD_LENGTH = 4,  //!< Default value is 1200 (CR80 cards).
    EVOLIS_SO_CARD_SPEED = 5,   //!< Depends of DPI. For 600 DPI a good value is between 150 and 350.
} evolis_scan_opt_t;

typedef enum evolis_scan_image_e {
    EVOLIS_SI_TOP = 0,
    EVOLIS_SI_TOP_IR = 2,
    EVOLIS_SI_BOTTOM = 1,
    EVOLIS_SI_BOTTOM_IR = 3,
} evolis_scan_image_t;

/// Configure scanner's library path.
EVOLIS_WRA int evolis_scan_set_library_path(_In_ const char* path);

/// Get scanner's library path.
EVOLIS_WRA const char* evolis_scan_get_library_path(void);

/// Initialize a new scan session.
EVOLIS_WRA int evolis_scan_init(_In_ evolis_t* printer);

/// Get scan options.
EVOLIS_WRA int evolis_scan_get_option(_In_ evolis_t* printer, _In_ evolis_scan_opt_t key, _Out_ int* value);

/// Set scan options.
EVOLIS_WRA int evolis_scan_set_option(_In_ evolis_t* printer, _In_ evolis_scan_opt_t key, _In_ int value);

/// Direct communication with scanner.
EVOLIS_WRA int32_t evolis_scan_command(_In_ evolis_t* printer, _In_ const evobuf* cmd, _In_ size_t cmdSize, _Out_ evobuf* reply, _In_ size_t replyMaxSize);

/// Insert and scan a card.
EVOLIS_WRA int evolis_scan_acquire(_In_ evolis_t* printer);

/// Retrieve image previously acquired.
EVOLIS_WRA int evolis_scan_get_image(_In_ evolis_t* printer, _In_ evolis_scan_image_t type, _Out_ evobuf* buffer, _Out_ size_t* size);

/// Save image previously acquired to file.
EVOLIS_WRA int evolis_scan_save_image(_In_ evolis_t* printer, _In_ evolis_scan_image_t type, _In_ const char* path);

/// Firmware update for scanner.
EVOLIS_WRA int evolis_scan_firmware_update(_In_ evolis_t* printer, _In_ const char* path);

//
// ToC/PRINTER DISCOVERY
// ---------------------
//

/// Structure holding the network printer information.
typedef struct evolis_netdevice_s {
    /// Network protocol version in use.
    int version;
    /// Printer's product ID.
    int pid;
    /// Printer's product name.
    char productName[128];
    /// Printer's serial number.
    char serialNumber[128];
    /// Printer's hostname.
    char hostName[32];
    /// Printer's IP address.
    char ip[32];
    /// True if Printer is configured to use DHCP.
    bool isDhcpEnabled;
    /// Indicates the branding code.
    int oem;
} evolis_netdevice_t;

typedef void (*evolis_discovery_cb)(evolis_netdevice_t* dev, void* data);

EVOLIS_WRA int evolis_discovery_start(_In_ evolis_discovery_cb cb, _Out_ void* data);

EVOLIS_WRA void evolis_discovery_stop(void);

//
// ToC/LOGGING
// -----------
//

/// Log level values.
typedef enum evolis_log_e {
    EVOLIS_LG_TRACE = 0,     //<! Show ERROR, WARNING, INFO, DEBUG, TRACE messages.
    EVOLIS_LG_DEBUG = 1,     //<! Show ERROR, WARNING, INFO, DEBUG messages.
    EVOLIS_LG_INFO = 2,      //<! Show ERROR, WARNING, INFO messages.
    EVOLIS_LG_WARNING = 3,   //<! Show ERROR, WARNING messages.
    EVOLIS_LG_ERROR = 4,     //<! Show ERROR messages.
} evolis_log_t;

/// Sets the file where messages are stored.
EVOLIS_WRA void evolis_log_set_path(_In_ const char* path);

/// Sets the log level (`EVOLIS_LG_ERROR` by default).
EVOLIS_WRA void evolis_log_set_level(_In_ evolis_log_t level);

/// Show log messages on console.
EVOLIS_WRA void evolis_log_set_console(_In_ bool on);

//
// ToC/FILE HELPERS
// ----------------
//

/// Load a file from disk.
EVOLIS_LIB int evolis_file_read(const char* filename, char** data, size_t* size);

/// Save a file to disk.
EVOLIS_LIB int evolis_file_write(const char* filename, const char* data, size_t size);

/// Free memory allocated by `evolis_file_read()`.
EVOLIS_LIB void evolis_file_free(char* p);

#ifdef __ANDROID__
#  include <jni.h>
    EVOLIS_LIB void evolis_set_android_env(JavaVM* env, jobject androidContext);
#endif // __ANDROID__

#include "evo-printers.h"
#include "ava-printers.h"
#include "evo-laminator.h"
#include "evo-service.h"

#ifdef __cplusplus
}
#endif
