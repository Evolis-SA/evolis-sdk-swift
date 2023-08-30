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

#include <evolis.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <wchar.h>
#include <sys/types.h>

#include "evolis_version.h"

typedef evolis_mark_t avansia_mark_t;

typedef evolis_model_t avansia_model_t;

typedef evolis_link_t avansia_link_t;

typedef evolis_device_t avansia_device_t;

/// Get device list. Takes a list of model ended by zero.
EVOLIS_LIB int avansia_get_devices(avansia_device_t** devices);

/// Free device list returned by avansia_get_devices().
EVOLIS_LIB void avansia_free_devices(avansia_device_t* devices);

/// An internal type representing the device context.
///
/// @see avansia_open()
/// @see avansia_close()
typedef evolis_t avansia_t;

/// The printer type is used to establish the connection to the printer. All
/// Evolis printers have the save communication protocol except for the Avansia
/// which have a specific one.
///
/// Over IP, the printer type can be detected thus you can use the
/// `AVANSIA_TY_AUTO` enum value. In any case, specifying the right printer type
/// is more efficient.
typedef evolis_type_t avansia_type_t;

/// List of error management modes of the printer.
typedef evolis_error_management_t avansia_error_management_t;

/// Connect to the printer referenced by the `name` argument.
EVOLIS_LIB avansia_t* avansia_open(const char* name, bool supervised);

/// Connect to a printer with URL and printer type.
/// @deprecated Please use `avansia_open()` instead.
EVOLIS_DEPRECATED
EVOLIS_LIB avansia_t* avansia_open2(const char* device, avansia_type_t type);

/// Close connection to the printer.
EVOLIS_LIB void avansia_close(avansia_t* printer);

/// Read data from the printer.
EVOLIS_LIB ssize_t avansia_read(avansia_t* printer, char* data, size_t maxSize);

/// Read data from the printer with custom timeout.
EVOLIS_LIB ssize_t avansia_readt(avansia_t* printer, char* data, size_t maxSize, int timeout);

/// Send data to the printer.
EVOLIS_LIB ssize_t avansia_write(avansia_t* printer, const char* data, size_t size);

/// Send data to the printer with custom timeout.
EVOLIS_LIB ssize_t avansia_writet(avansia_t* printer, const char* data, size_t size, int timeout);

/// Software reset of the printer.
EVOLIS_LIB int avansia_reset(avansia_t* printer, int timeout, char* timeouted);

/// Get error management mode of the printer (see avansia_error_management_t).
EVOLIS_LIB int avansia_get_error_management(avansia_t* printer, avansia_error_management_t* em);

/// Set error management mode of the printer (PRINTER or SOFTWARE only).
EVOLIS_LIB int avansia_set_error_management(avansia_t* printer, avansia_error_management_t em);

/// Clear printer errors, should be use when print returned a AVANSIA_RC_MECHANICAL_ERROR error.
EVOLIS_LIB int avansia_clear_mechanical_errors(avansia_t* printer);

///
/// ToC/DEVICE INFOS
/// ----------------
///

/// The printer infos struct contains general informations of the printer. It is
/// populated when calling `avansia_open()` function. You can retrieve it by
/// calling `avansia_infos()`.
typedef evolis_infos_t avansia_infos_t;

/// Get printer infos.
/// Same as avansia_get_infos2(a, b, AVANSIA_CA_CACHE_ON_ERROR).
EVOLIS_LIB int avansia_get_infos(avansia_t* printer, avansia_infos_t* infos);

///
/// ToC/CARD OPERATIONS
/// -------------------
///

/// The following card entries are available for Evolis printers. Some entries
/// are not valid for all printers. See notes below for details.
///
/// @see avansia_set_input_tray()
typedef evolis_intray_t avansia_intray_t;

/// The following card exit are available for Evolis printers. Some of the exits
/// are not valid for all printers. See notes below for details.
///
/// @see avansia_set_output_tray()
/// @see avansia_set_error_tray()
typedef evolis_outtray_t avansia_outtray_t;

/// Set card insertion mode.
EVOLIS_LIB int avansia_set_input_tray(avansia_t* printer, avansia_intray_t tray);

/// Get card insertion mode value.
EVOLIS_LIB int avansia_get_input_tray(avansia_t* printer, avansia_intray_t* tray);

/// Set card ejection mode.
EVOLIS_LIB int avansia_set_output_tray(avansia_t* printer, avansia_outtray_t tray);

/// Get card ejection mode value.
EVOLIS_LIB int avansia_get_output_tray(avansia_t* printer, avansia_outtray_t* tray);

/// Set card rejection mode.
EVOLIS_LIB int avansia_set_error_tray(avansia_t* printer, avansia_outtray_t tray);

/// Get rejection mode value.
EVOLIS_LIB int avansia_get_error_tray(avansia_t* printer, avansia_outtray_t* tray);

/// Insert a card in the printer.
EVOLIS_LIB int avansia_insert(avansia_t* printer);

/// Eject a card from the printer.
EVOLIS_LIB int avansia_eject(avansia_t* printer);

/// Reject a card from the printer.
EVOLIS_LIB int avansia_reject(avansia_t* printer);

///
/// ToC/PRINTING
/// ------------
///

/// References the card face.
/// @see avansia_print_set_bitmap()
typedef evolis_face_t avansia_face_t;

/// Print a test card.
EVOLIS_LIB int avansia_print_test_card(avansia_t* printer, int type);

/// Initialize a new printing session.
EVOLIS_LIB int avansia_print_init(avansia_t* printer);

/// Set a print processing option.
EVOLIS_LIB void avansia_print_set_option(avansia_t* printer, const char* key, const char* value);

/// Get value of a print processing option.
EVOLIS_LIB bool avansia_print_get_option(avansia_t* printer, const char* key, const char** value);

/// Set PRN log state.
EVOLIS_LIB void avansia_print_set_prnlog(avansia_t* printer, bool enabled, const char* dirPath);

/// Get PRN log state.
EVOLIS_LIB bool avansia_print_get_prnlog(avansia_t* printer);

/// Set the image to print.
EVOLIS_LIB int avansia_print_set_image(avansia_t* printer, avansia_face_t face, const evolis_image_t* img);

/// Set the image path to print.
EVOLIS_LIB int avansia_print_set_imagep(avansia_t* printer, avansia_face_t face, const char* path);

/// Set the image buffer to print.
EVOLIS_LIB int avansia_print_set_imageb(avansia_t* printer, avansia_face_t face, const char* data, size_t size);

/// Load bitmap at path and print it with black panel.
EVOLIS_LIB int avansia_print_set_blackp(avansia_t* printer, avansia_face_t face, const char* path);

/// Print bitmap buffer with black panel.
EVOLIS_LIB int avansia_print_set_blackb(avansia_t* printer, avansia_face_t face, const char* data, size_t size);

/// Use the image at path to print with silver panel (Avansia).
EVOLIS_LIB int avansia_print_set_silverp(avansia_t* printer, avansia_face_t face, const char* path);

/// Use the image buffer to print with silver panel (Avansia).
EVOLIS_LIB int avansia_print_set_silverb(avansia_t* printer, avansia_face_t face, const char* data, size_t size);

/// Start printing.
EVOLIS_LIB int avansia_print_exec(avansia_t* printer);

/// Generate PRN and write it to a file
EVOLIS_LIB int avansia_print_to_file(avansia_t* printer, const char* path);

#ifdef __ANDROID__
#  include <jni.h>
    EVOLIS_LIB void avansia_set_android_env(JavaVM* env, jobject androidContext);
#endif // __ANDROID__

#ifdef __cplusplus
}
#endif
