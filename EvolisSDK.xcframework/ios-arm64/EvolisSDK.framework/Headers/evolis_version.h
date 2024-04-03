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

/* #undef EVOLIS_WITH_SETTINGS */
/* #undef EVOLIS_WITH_CUPS */
/* #undef EVOLIS_WITH_IMAGEPROC */
/* #undef EVOLIS_WITH_NISCASDK */
/* #undef EVOLIS_WITH_WISECUBESDK */
/* #undef EVOLIS_WITH_SSL */

///
/// LibEvolis's version macros.
///
/// `EVOLIS_VERSION` expands to a numeric value of the form 0xMMNNPP (MM = major, NN = minor, PP = patch)
/// that specifies the library's version number. For example, if you compile your
/// application against LibEvolis 1.0.0, the EVOLIS_VERSION macro will expand to 0x010000.
///
/// `EVOLIS_VERSION_STR` expands to a string that specifies library's version number (for example, "1.0.0").
///
/// These macros are the version against which the application is compiled.
///

#define EVOLIS_VERSION_MAJOR 8
#define EVOLIS_VERSION_MINOR 3
#define EVOLIS_VERSION_PATCH 0
#define EVOLIS_VERSION_BUILD 4236

#define EVOLIS_VERSION_CHECK(major, minor, patch) ((major<<16)|(minor<<8)|(patch))

#define EVOLIS_VERSION EVOLIS_VERSION_CHECK(EVOLIS_VERSION_MAJOR, EVOLIS_VERSION_MINOR, EVOLIS_VERSION_PATCH)

#define EVOLIS_VERSION_STR (EVOLIS_STR(EVOLIS_VERSION_MAJOR) "." EVOLIS_STR(EVOLIS_VERSION_MINOR) "." EVOLIS_STR(EVOLIS_VERSION_PATCH) "." EVOLIS_STR(EVOLIS_VERSION_BUILD))

#ifdef __cplusplus
}
#endif
