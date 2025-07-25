#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>

#include "evolis.h"
#include "evosettings_keys.h"

#define EVOSETTINGS_CONNECTORS(X)                                                  \
    X(UNKNOWN, 0x0000)   /* No connector */                                        \
    X(COMPOSITE, 0x0001) /* Internal use only. */                                  \
                                                                                   \
    /* Connectors aliases: */                                                      \
    X(PRINTER, 0x0002) /* Alias for PRN. */                                        \
    X(DRIVER, 0x0004)  /* Windows: Alias for DRV, DRVP, DEV, REG, PC1. */          \
                       /* Linux: Alias for CUPS, CONF, SOLO */                     \
                       /* Android, iOS or settings disabled: Alias for DEFAULTS */ \
    /* Common connectors: */                                                       \
    X(PRN, 0x0008) /* Printer connector. */                                        \
                                                                                   \
    /* Windows connectors: */                                                      \
    X(DRV, 0x0010)  /* Print settings. */                                          \
    X(DRVP, 0x0020) /* Print settings for job. */                                  \
    X(DEV, 0x0040)  /* Current user's DEVMODE. */                                  \
    X(DEVG, 0x0080) /* All users DEVMODE. */                                       \
    X(REG, 0x0100)  /* Big data key/value storage (images). */                     \
    X(REG2, 0x0200) /* Simple key/value storage in registry. */                    \
    X(PC1, 0x0400)  /* Printer Manager storage. */                                 \
                                                                                   \
    /* Linux/Mac connectors: */                                                    \
    X(CUPS, 0x0800) /* CUPS storage. */                                            \
    X(CONF, 0x1000) /* Conf file storage. */                                       \
    X(SOLO, 0x2000) /* Individual file storage. */

#define EVOSETTINGS_TYPES(X) \
    X(UNKNOWN)               \
    X(BLOB)                  \
    X(LIST)                  \
    X(INT)                   \
    X(TEXT)

typedef void evolis_t;
typedef void evosettings_t;

typedef enum evosettings_connector_e
{
#define X(NAME, VALUE) EVOSETTINGS_CO_##NAME = VALUE,
    EVOSETTINGS_CONNECTORS(X)
#undef X
} evosettings_connector_t;

typedef enum evosettings_type_e
{
#define X(NAME) EVOSETTINGS_TY_##NAME,
    EVOSETTINGS_TYPES(X)
#undef X
} evosettings_type_t;

typedef struct evosettings_item_e
{
        char key[256];
        char value[256];
} evosettings_item_t;

/// Returns a string containing library version.
EVOLIS_LIB const char* EvoSettings_GetVersion();

/// Helper to convert a evosettings_key_t value to a corresponding string.
EVOLIS_LIB const char* EvoSettings_KeyToString(evosettings_key_t key);

/// Helper to convert a string to a evosettings_key_t value.
EVOLIS_LIB evosettings_key_t EvoSettings_KeyFromString(const char* key);

/// Create an handle to manage settings. Returns NULL on failure.
/// By default no connectors are selected, EvoSettings_SelectReaders() and
/// EvoSettings_SelectWriters() must be called explicitly.
EVOLIS_LIB evosettings_t* EvoSettings_Create(const char* printerName, evolis_t* connection);

/// Destroys the handle created by EvoSettings_Create().
EVOLIS_LIB void EvoSettings_Delete(evosettings_t* mgr);

/// This function is to select connectors used to read settings.
EVOLIS_LIB void EvoSettings_SelectReaders(evosettings_t* mgr, int connectors);

/// This function is to select connectors used for writing settings.
EVOLIS_LIB void EvoSettings_SelectWriters(evosettings_t* mgr, int connectors);

/// Retrieve all settings referenced by EvoSettings_SelectReaders().
EVOLIS_LIB bool EvoSettings_Pull(evosettings_t* mgr);

/// Push settings to connectors referenced by EvoSettings_SelectWriters().
EVOLIS_LIB bool EvoSettings_Push(evosettings_t* mgr);

/// Will pull then push settings.
EVOLIS_LIB bool EvoSettings_Sync(evosettings_t* mgr);

/// Reset settings to default then save (push).
EVOLIS_LIB void EvoSettings_ResetToDefault(evosettings_t* mgr);

/// Get number of settings available.
EVOLIS_LIB int EvoSettings_GetCollectionSize(evosettings_t* mgr);

/// Get the key at index `index`. See EvoSettings_GetCollectionSize().
EVOLIS_LIB evosettings_key_t EvoSettings_GetKey(evosettings_t* mgr, int index);

/// Checks if the key is available for the printer.
EVOLIS_LIB bool EvoSettings_ContainsKey(evosettings_t* mgr, evosettings_key_t key);

/// Returns true if the key is available for the printer and is
/// made readable by the selected readers.
EVOLIS_LIB bool EvoSettings_IsReadable(evosettings_t* mgr, evosettings_key_t key);

/// Returns true if the key is available for the printer and is
/// made writable by the selected writers.
EVOLIS_LIB bool EvoSettings_IsWritable(evosettings_t* mgr, evosettings_key_t key);

/// Returns list of connectors associated to a key.
EVOLIS_LIB int EvoSettings_GetConnectors(evosettings_t* mgr, evosettings_key_t key);

/// On success (the key is valid) the value is set and true is returned. False is returned ortherwise.
EVOLIS_LIB bool EvoSettings_GetValue(evosettings_t* mgr, evosettings_key_t key, const char** value);
/// On success (the key is a valid key to a boolean value) the value is set and true is returned. False is returned
/// ortherwise.
EVOLIS_LIB bool EvoSettings_GetBoolValue(evosettings_t* mgr, evosettings_key_t key, bool* value);
/// On success (the key is a valid key to an integer value) the value is set and true is returned. False is returned
/// ortherwise.
EVOLIS_LIB bool EvoSettings_GetIntValue(evosettings_t* mgr, evosettings_key_t key, int* value);

/// Returns the type of the value matching the 'key' parameter
EVOLIS_LIB evosettings_type_t EvoSettings_GetValueType(evosettings_t* mgr, evosettings_key_t key);

/**
 *  If the setting is of type LIST, the allowed values are written to 'range', up to rangeSize maximum values.
 *  If range is NULL, the total number of available values is returned.
 *  Returns -1 on failure.
 */
EVOLIS_LIB int EvoSettings_GetValueRange(evosettings_t* mgr, evosettings_key_t key, char** range, int rangeSize);
/// On success, true is returned and min and max parameter are filled to the values matching 'key'. Otherwise false
/// is returned and min/max should be ignored.
EVOLIS_LIB bool EvoSettings_GetIntValueRange(evosettings_t* mgr, evosettings_key_t key, int* min, int* max);
/// On success, returns a valid string matching the parameter 'key'. Returns NULL on failure.
EVOLIS_LIB const char* EvoSettings_GetDefaultValue(evosettings_t* mgr, evosettings_key_t key);
/// Returns the boolean value matching the 'key' parameter.
EVOLIS_LIB bool EvoSettings_GetDefaultBoolValue(evosettings_t* mgr, evosettings_key_t key);
/// Returns the integer value matching the 'key' parameter.
EVOLIS_LIB int EvoSettings_GetDefaultIntValue(evosettings_t* mgr, evosettings_key_t key);

/// Returns the type of the value matching the 'model' and 'key' parameters.
EVOLIS_LIB evosettings_type_t EvoSettings_GetValueType2(evolis_model_t model, evosettings_key_t key);
/**
 *  On success, returns the number of strings of the array matching the 'key' parameter, otherwise returns -1 on
 * failure. Will return the number of strings of the array matching the 'key' parameter when NULL is passed as
 * 'range'.
 */
EVOLIS_LIB int EvoSettings_GetValueRange2(evolis_model_t model, evosettings_key_t key, char** range, int rangeSize);
/// On success, true is returned and min and max parameter are filled to the values matching 'model' and 'key'.
/// Otherwise false is returned and min/max should be ignored.
EVOLIS_LIB bool EvoSettings_GetIntValueRange2(evolis_model_t model, evosettings_key_t key, int* min, int* max);

/// On success, returns a valid string matching the parameter 'model' and 'key'. Returns NULL on failure.
EVOLIS_LIB const char* EvoSettings_GetDefaultValue2(evolis_model_t model, evosettings_key_t key);
/// Returns the boolean value matching the 'model' and 'key' parameter.
EVOLIS_LIB bool EvoSettings_GetDefaultBoolValue2(evolis_model_t model, evosettings_key_t key);
/// Returns the integer value matching the 'model' and 'key' parameter.
EVOLIS_LIB int EvoSettings_GetDefaultIntValue2(evolis_model_t model, evosettings_key_t key);

/// If returns true, the string value has been successfully set for 'key' parameter. False is returned on failure.
EVOLIS_LIB bool EvoSettings_SetValue(evosettings_t* mgr, evosettings_key_t key, const char* value);
/// If returns true, the boolean value has been successfully set for 'key' parameter. False is returned on failure.
EVOLIS_LIB bool EvoSettings_SetBoolValue(evosettings_t* mgr, evosettings_key_t key, bool value);
/// If returns true, the integer value has been successfully set for 'key' parameter. False is returned on failure.
EVOLIS_LIB bool EvoSettings_SetIntValue(evosettings_t* mgr, evosettings_key_t key, int value);

/// Same as EvoSettings_SetValue(). But apply rules to validate settings.
EVOLIS_LIB bool EvoSettings_SetValue_WithRules(evosettings_t* mgr, evosettings_key_t key, const char* value);
/// Same as EvoSettings_SetBoolValue(). But apply rules to validate settings.
EVOLIS_LIB bool EvoSettings_SetBoolValue_WithRules(evosettings_t* mgr, evosettings_key_t key, bool value);
/// Same as EvoSettings_SetIntValue(). But apply rules to validate settings.
EVOLIS_LIB bool EvoSettings_SetIntValue_WithRules(evosettings_t* mgr, evosettings_key_t key, int value);
/// Apply rules
EVOLIS_LIB bool EvoSettings_ApplyRules(evosettings_t* mgr);

/// On success, returns the number of elements in 'keys', fill the 'keys' impacted by the execution of rules.
/// Returns -1 on failure.
EVOLIS_LIB size_t EvoSettings_GetKeysUpdatedByRules(evosettings_t* mgr, evosettings_key_t* keys);
/// Returns true if settings were modified by the driver. False otherwise.
EVOLIS_LIB bool EvoSettings_CheckIfUpdatedByDrv(evosettings_t* mgr);

/// Export settings to 'out' parameter. Call this method with 'out' set to NULL to get the neededSize. Returns true
/// on sucess, false on failure.
EVOLIS_LIB bool EvoSettings_Export(evosettings_t* mgr, size_t* neededSize, char* out, size_t outSize);
/// Export settings to the file specified in 'filePath' parameter. Returns true on sucess, false on failure.
EVOLIS_LIB bool EvoSettings_ExportFile(evosettings_t* mgr, const char* filePath);
/// Export settings specified in 'optionals' (specify the number of elements of that array to optionalsCount) to the
/// file specified in 'filePath' parameter. Returns true on sucess, false on failure.
EVOLIS_LIB bool EvoSettings_ExportFile2(evosettings_t* mgr, const char* filePath, const evosettings_item_t* optionals,
                                        int optionalsCount);

/// Import settings from 'data' parameter. Returns true on sucess, false on failure.
EVOLIS_LIB bool EvoSettings_Import(evosettings_t* mgr, const char* data);
/// Import settings to the file specified in 'filePath' parameter. Returns true on sucess, false on failure.
EVOLIS_LIB bool EvoSettings_ImportFile(evosettings_t* mgr, const char* filePath);
/// Import settings specified in 'optionals' (specify the number of elements of that array to optionalsCount) from
/// the file specified in 'filePath' parameter. Returns the number of elements imported on sucess, -1 on failure.
EVOLIS_LIB int EvoSettings_ImportFile2(evosettings_t* mgr, const char* filePath, evosettings_item_t* optionals,
                                       int optionalsCount);

/// Get evosettings_connector_t enum value matching string 's'
EVOLIS_LIB evosettings_connector_t EvoSettings_ConnectorFromString(const char* s);
/// Get string matching enum value 'c'
EVOLIS_LIB const char* EvoSettings_ConnectorToString(evosettings_connector_t c);

#ifdef __cplusplus
}
#endif
