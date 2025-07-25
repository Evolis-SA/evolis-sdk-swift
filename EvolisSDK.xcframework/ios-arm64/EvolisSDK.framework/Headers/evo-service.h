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

#include "evolis.h"

/// Actions that may be applied in response to a printer event
typedef enum evolis_service_action_e {
    EVOLIS_SVA_NONE = 0, 
    EVOLIS_SVA_OK = 1, //<! Accept the proposed action
    EVOLIS_SVA_RETRY = 2, //<! Retry the ongoing operation
    EVOLIS_SVA_CANCEL = 4, //<! Cancel the ongoing operation
} evolis_service_action_t;

/// Set the supervision service information.
EVOLIS_WRA bool evolis_service_select(_In_ evolis_model_t model);

/// Set the supervision service information and overrides the default URL
EVOLIS_WRA bool evolis_service_select_with_url(_In_ evolis_model_t model, _In_ const char* url);

/// Returns the url of the supervision service currently selected.
EVOLIS_LIB const char* evolis_service_get_url(void);

/// Return the name of the supervision service currently selected.
EVOLIS_LIB const char* evolis_service_get_name(void);

/// Start Evolis service (Windows and Mac)
EVOLIS_WRA bool evolis_service_start(void);

/// Stop Evolis service (Windows and Mac)
EVOLIS_WRA bool evolis_service_stop(void);

/// Restart Evolis service (Windows and Mac)
EVOLIS_WRA bool evolis_service_restart(void);

/// Returns true if Evolis service is running (Windows and Mac).
EVOLIS_WRA bool evolis_service_is_running(void);

/// Send a request to Evolis Service software. Returns `0` on success
/// or an error code (see Premium SDK's documentation for details).
EVOLIS_LIB int evolis_service_request(char* reply, size_t replySize, const char* method, const char* format, ...);

/// Same as evolis_service_request() except it's called with a timeout.
EVOLIS_LIB int evolis_service_requestt(int timeout, char* reply, size_t replySize, const char* method, const char* format, ...);

/// Same as evolis_service_request() except it's called with `va_list` instead of a variable number of arguments.
EVOLIS_LIB int evolis_service_requestv(char* reply, size_t replySize, const char* method, const char* format, va_list ap);

/// Same as evolis_service_requestv() except it's called with a timeout.
EVOLIS_LIB int evolis_service_requestvt(int timeout, char* reply, size_t replySize, const char* method, const char* format, va_list ap);

/// Obtain the ongoing event for a printer
EVOLIS_WRA int evolis_service_get_printer_event(_In_ evolis_t* printer, _Out_ evobuf* reply, _In_ size_t replySize);

/// Set the reply to a printer event
EVOLIS_WRA int evolis_service_set_printer_event(_In_ evolis_t* printer, _In_ const char* eventName, _In_ evolis_service_action_t action);

/// Checks if an action is available for an event
EVOLIS_WRA bool evolis_service_is_action_available(_In_ int actionsMask, _In_ evolis_service_action_t action);

#ifdef __cplusplus
}
#endif
