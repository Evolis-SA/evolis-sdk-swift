/**
 * Evolis C library
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
 * ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 * The APIs exposed in this file is subject to be changed or removed at any
 * time. We do not provide any support to it.
 */
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "evolis.h"

///
/// MAG ENCODING
/// ------------
///

/// Writes a specific magnetic track.
/// @deprecated
EVOLIS_DEPRECATED
EVOLIS_LIB int evolis_mag_write_track(evolis_t* printer, int track, evolis_mag_format_t f, const char* in, size_t inSize);

/// Reads a specific magnetic track.
/// @deprecated
EVOLIS_DEPRECATED
EVOLIS_LIB int evolis_mag_read_track(evolis_t* printer, int track, evolis_mag_format_t f, char* out, size_t outSize);

///
/// IMAGE PROCESSING
/// ----------------
///

/// List of all supported barcode types.
/// @see evolis_print_set_barcode()
typedef enum evolis_barcode_e {
    EVOLIS_BC_CODE11          = 1,
    EVOLIS_BC_C25STANDARD     = 2,
    EVOLIS_BC_C25MATRIX       = 2,
    EVOLIS_BC_C25INTER        = 3,
    EVOLIS_BC_C25IATA         = 4,
    EVOLIS_BC_C25LOGIC        = 6,
    EVOLIS_BC_C25IND          = 7,
    EVOLIS_BC_CODE39          = 8,
    EVOLIS_BC_EXCODE39        = 9,
    EVOLIS_BC_EANX            = 13,
    EVOLIS_BC_EANX_CHK        = 14,
    EVOLIS_BC_GS1_128         = 16,
    EVOLIS_BC_EAN128          = 16,
    EVOLIS_BC_CODABAR         = 18,
    EVOLIS_BC_CODE128         = 20,
    EVOLIS_BC_DPLEIT          = 21,
    EVOLIS_BC_DPIDENT         = 22,
    EVOLIS_BC_CODE16K         = 23,
    EVOLIS_BC_CODE49          = 24,
    EVOLIS_BC_CODE93          = 25,
    EVOLIS_BC_FLAT            = 28,
    EVOLIS_BC_DBAR_OMN        = 29,
    EVOLIS_BC_RSS14           = 29,
    EVOLIS_BC_DBAR_LTD        = 30,
    EVOLIS_BC_RSS_LTD         = 30,
    EVOLIS_BC_DBAR_EXP        = 31,
    EVOLIS_BC_RSS_EXP         = 31,
    EVOLIS_BC_TELEPEN         = 32,
    EVOLIS_BC_UPCA            = 34,
    EVOLIS_BC_UPCA_CHK        = 35,
    EVOLIS_BC_UPCE            = 37,
    EVOLIS_BC_UPCE_CHK        = 38,
    EVOLIS_BC_POSTNET         = 40,
    EVOLIS_BC_MSI_PLESSEY     = 47,
    EVOLIS_BC_FIM             = 49,
    EVOLIS_BC_LOGMARS         = 50,
    EVOLIS_BC_PHARMA          = 51,
    EVOLIS_BC_PZN             = 52,
    EVOLIS_BC_PHARMA_TWO      = 53,
    EVOLIS_BC_PDF417          = 55,
    EVOLIS_BC_PDF417COMP      = 56,
    EVOLIS_BC_PDF417TRUNC     = 56,
    EVOLIS_BC_MAXICODE        = 57,
    EVOLIS_BC_QRCODE          = 58,
    EVOLIS_BC_CODE128B        = 60,
    EVOLIS_BC_AUSPOST         = 63,
    EVOLIS_BC_AUSREPLY        = 66,
    EVOLIS_BC_AUSROUTE        = 67,
    EVOLIS_BC_AUSREDIRECT     = 68,
    EVOLIS_BC_ISBNX           = 69,
    EVOLIS_BC_RM4SCC          = 70,
    EVOLIS_BC_DATAMATRIX      = 71,
    EVOLIS_BC_EAN14           = 72,
    EVOLIS_BC_VIN             = 73,
    EVOLIS_BC_CODABLOCKF      = 74,
    EVOLIS_BC_NVE18           = 75,
    EVOLIS_BC_JAPANPOST       = 76,
    EVOLIS_BC_KOREAPOST       = 77,
    EVOLIS_BC_DBAR_STK        = 79,
    EVOLIS_BC_RSS14STACK      = 79,
    EVOLIS_BC_DBAR_OMNSTK     = 80,
    EVOLIS_BC_RSS14STACK_OMNI = 80,
    EVOLIS_BC_DBAR_EXPSTK     = 81,
    EVOLIS_BC_RSS_EXPSTACK    = 81,
    EVOLIS_BC_PLANET          = 82,
    EVOLIS_BC_MICROPDF417     = 84,
    EVOLIS_BC_USPS_IMAIL      = 85,
    EVOLIS_BC_ONECODE         = 85,
    EVOLIS_BC_PLESSEY         = 86,

    /* Barcode 8 codes */
    EVOLIS_BC_TELEPEN_NUM     = 87,
    EVOLIS_BC_ITF14           = 89,
    EVOLIS_BC_KIX             = 90,
    EVOLIS_BC_AZTEC           = 92,
    EVOLIS_BC_DAFT            = 93,
    EVOLIS_BC_DPD             = 96,
    EVOLIS_BC_MICROQR         = 97,

    /* Barcode 9 codes */
    EVOLIS_BC_HIBC_128        = 98,
    EVOLIS_BC_HIBC_39         = 99,
    EVOLIS_BC_HIBC_DM         = 102,
    EVOLIS_BC_HIBC_QR         = 104,
    EVOLIS_BC_HIBC_PDF        = 106,
    EVOLIS_BC_HIBC_MICPDF     = 108,
    EVOLIS_BC_HIBC_BLOCKF     = 110,
    EVOLIS_BC_HIBC_AZTEC      = 112,

    /* Barcode 10 codes */
    EVOLIS_BC_DOTCODE         = 115,
    EVOLIS_BC_HANXIN          = 116,

    /*Barcode 11 codes*/
    EVOLIS_BC_MAILMARK        = 121,

    /* Specific barcodes */
    EVOLIS_BC_AZRUNE          = 128,
    EVOLIS_BC_CODE32          = 129,
    EVOLIS_BC_EANX_CC         = 130,
    EVOLIS_BC_GS1_128_CC      = 131,
    EVOLIS_BC_EAN128_CC       = 131,
    EVOLIS_BC_DBAR_OMN_CC     = 132,
    EVOLIS_BC_RSS14_CC        = 132,
    EVOLIS_BC_DBAR_LTD_CC     = 133,
    EVOLIS_BC_RSS_LTD_CC      = 133,
    EVOLIS_BC_DBAR_EXP_CC     = 134,
    EVOLIS_BC_RSS_EXP_CC      = 134,
    EVOLIS_BC_UPCA_CC         = 135,
    EVOLIS_BC_UPCE_CC         = 136,
    EVOLIS_BC_DBAR_STK_CC     = 137,
    EVOLIS_BC_RSS14STACK_CC   = 137,
    EVOLIS_BC_DBAR_OMNSTK_CC  = 138,
    EVOLIS_BC_RSS14_OMNI_CC   = 138,
    EVOLIS_BC_DBAR_EXPSTK_CC  = 139,
    EVOLIS_BC_RSS_EXPSTACK_CC = 139,
    EVOLIS_BC_CHANNEL         = 140,
    EVOLIS_BC_CODEONE         = 141,
    EVOLIS_BC_GRIDMATRIX      = 142,
    EVOLIS_BC_UPNQR           = 143,
    EVOLIS_BC_ULTRA           = 144,
    EVOLIS_BC_RMQR            = 145
} evolis_barcode_t;

/// References the font types.
/// @see evolis_set_font()
typedef enum evolis_font_e {
    EVOLIS_FT_SIMPLEX,          //!< normal size sans-serif font
    EVOLIS_FT_PLAIN,            //!< small size sans-serif font
    EVOLIS_FT_DUPLEX,           //!< normal size sans-serif font (more complex than EVOLIS_FT_SIMPLEX)
    EVOLIS_FT_COMPLEX,          //!< normal size serif font
    EVOLIS_FT_TRIPLEX,          //!< normal size serif font (more complex than EVOLIS_FT_COMPLEX)
    EVOLIS_FT_COMPLEX_SMALL,    //!< smaller version of EVOLIS_FT_COMPLEX
    EVOLIS_FT_SCRIPT_SIMPLEX,   //!< hand-writing style font
    EVOLIS_FT_SCRIPT_COMPLEX,   //!< more complex variant of EVOLIS_FT_SCRIPT_SIMPLEX
    EVOLIS_FT_ITALIC,           //!< flag for italic font
    EVOLIS_FT_PATH
} evolis_font_t;

typedef enum evolis_ratio_e {
    EVOLIS_RT_IGNORE,   //!< The image is scaled to fit the bounding box.
    EVOLIS_RT_KEEP,     //!< Keep the aspect ratio of the image.
    EVOLIS_RT_EXPAND    //!< Expand to fill the bounding box while keeping image ratio.
} evolis_ratio_t;

/// An internal type representing an image.
/// @see evolis_image_new()
/// @see evolis_image_delete()
typedef void evolis_image_t;

/// Create a new instance of the image builder.
EVOLIS_LIB evolis_image_t* evolis_image_new(void);

/// Clone the image.
EVOLIS_LIB evolis_image_t* evolis_image_clone(evolis_image_t* img);

/// Destroys the image builder.
EVOLIS_LIB void evolis_image_delete(evolis_image_t* img);

/// Save the resulting image to a file.
EVOLIS_LIB int evolis_renderp(evolis_image_t* img, const char* path);

/// Save the resulting image to a buffer (.bmp format).
EVOLIS_LIB int evolis_renderb(evolis_image_t* img, char* out, size_t* outSize);

/// Set the image buffer to print.
EVOLIS_LIB int evolis_draw_imageb(evolis_image_t* img, const char* data, size_t size, int angle);

/// Set the image path to print.
EVOLIS_LIB int evolis_draw_imagep(evolis_image_t* img, const char* path, int angle);

/// Set font used for text drawings.
EVOLIS_LIB void evolis_set_font(evolis_image_t* img, evolis_font_t font, int size, int color, int thickness);

/// Load font from file.
EVOLIS_LIB void evolis_set_fontp(evolis_image_t* img, const char* path, int size, int color);

/// Draw a text on top of the image.
EVOLIS_LIB int evolis_draw_text(evolis_image_t* img, int x, int y, int angle, const char* text);

/// Set the barcode type to use for drawing.
EVOLIS_LIB void evolis_set_barcode(evolis_image_t* img, evolis_barcode_t bc, int height, int multiplier, bool showBcText);

/// Set a barcode to the preset image or a blank image.
EVOLIS_LIB int evolis_draw_barcode(evolis_image_t* img, int x, int y, int angle, const char* data);

/// Set the bounding box on the image (used for images).
EVOLIS_LIB void evolis_set_bounding_box(evolis_image_t* img, int x, int y, int w, int h);

/// Get the bounding box values.
EVOLIS_LIB void evolis_get_bounding_box(evolis_image_t* img, int* x, int* y, int* w, int* h);

/// Set the type of ratio to use when scaling the image.
EVOLIS_LIB void evolis_set_ratio(evolis_image_t* img, evolis_ratio_t ratio);

/// Get the ratio.
EVOLIS_LIB evolis_ratio_t evolis_get_ratio(evolis_image_t* img);

/// Set the image to print.
EVOLIS_LIB int evolis_print_set_image(evolis_t* printer, evolis_face_t face, const evolis_image_t* img);

#ifdef __cplusplus
}
#endif

