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

#define EVOLIS_PCSC_ATR_MAX_SIZE 33

#define EVOLIS_PCSC_READERNAME_MAX_SIZE 128

/// ID to reference a given PCSC encoder
typedef uint16_t evolis_pcsc_uid_t;
/// Name of a PCSC encoder
typedef char evolis_pcsc_readername_t[EVOLIS_PCSC_READERNAME_MAX_SIZE];
/// ATR of a smart/contactless card
typedef char evolis_pcsc_atr_t[EVOLIS_PCSC_ATR_MAX_SIZE];

typedef enum evolis_pcsc_protocol_e
{
    /// Connect using default protocol
    EVOLIS_PCSC_PCL_NONE = 0,
    /// Connect using the T=0 protocol
    EVOLIS_PCSC_PCL_T0 = 1,
    /// Connect using the T=1 protocol
    EVOLIS_PCSC_PCL_T1 = 2,
    /// Connect using the raw protocol
    EVOLIS_PCSC_PCL_RAW = 3,
    /// Connect using any available protocol
    EVOLIS_PCSC_PCL_ANY = 4,
} evolis_pcsc_protocol_t;

typedef enum evolis_pcsc_disposition_e
{
    /// Default behaviour on disconnect
    EVOLIS_PCSC_DSP_NONE = 0,
    /// Do nothing on disconnect
    EVOLIS_PCSC_DSP_LEAVE = 1,
    /// Reset the card on disconnect
    EVOLIS_PCSC_DSP_RESET = 2,
    /// Power down the card on disconnect
    EVOLIS_PCSC_DSP_UNPOWER = 3,
} evolis_pcsc_disposition_t;

typedef struct evolis_pcsc_encoder_s
{
    evolis_pcsc_readername_t name;
    evolis_pcsc_uid_t uid;
} evolis_pcsc_encoder_t;

typedef struct evolis_pcsc_status_s
{
    evolis_pcsc_uid_t uid;
    evolis_pcsc_readername_t name;
    bool card_present;
    bool card_connected;
    bool card_unresponsive;
} evolis_pcsc_status_t;

/// Retrieve a list of available PCSC encoders.
EVOLIS_WRA int evolis_pcsc_list(_In_ evolis_t* p, _Out_ evolis_pcsc_encoder_t encoders[], _In_ size_t max_size);

/// Retrieve status of all available PCSC encoders.
EVOLIS_WRA int evolis_pcsc_status(_In_ evolis_t* p, _Out_ evolis_pcsc_status_t status[], _In_ size_t max_size);

/// Retrieve status of specified PCSC encoder.
EVOLIS_WRA int evolis_pcsc_encoder_status(_In_ evolis_t* p, _In_ evolis_pcsc_uid_t uid, _Out_ evolis_pcsc_status_t* status);

/// Read the ATR of the card present in the encoder matching the specified uid.
EVOLIS_WRA int evolis_pcsc_read_atr(_In_ evolis_t* p, _In_ evolis_pcsc_uid_t uid, _Out_ evolis_pcsc_atr_t* atr);

/// Wait for a card to be present in the encoder matching the specified uid.
EVOLIS_WRA int evolis_pcsc_wait_card_present(_In_ evolis_t* p, _In_ evolis_pcsc_uid_t uid);

/// Wait for a card to be present in the encoder matching the specified uid. (with supplied timeout)
EVOLIS_WRA int evolis_pcsc_wait_card_presentt(_In_ evolis_t* p, _In_ evolis_pcsc_uid_t uid, _In_ int timeout_ms);

/// Wait for a card to be absent in the encoder matching the specified uid.
EVOLIS_WRA int evolis_pcsc_wait_card_absent(_In_ evolis_t* p, _In_ evolis_pcsc_uid_t uid);

/// Wait for a card to be absent in the encoder matching the specified uid. (with supplied timeout)
EVOLIS_WRA int evolis_pcsc_wait_card_absentt(_In_ evolis_t* p, _In_ evolis_pcsc_uid_t uid, _In_ int timeout_ms);

/// Connects to a smart card using the encoder matching the specified uid.
EVOLIS_WRA int evolis_pcsc_connect(_In_ evolis_t* p, _In_ evolis_pcsc_uid_t uid, _In_ evolis_pcsc_protocol_t protocol);

/// Sends an APDU (and receive its response) to the smart card through the PCSC encoder matching the specified uid.
EVOLIS_WRA int evolis_pcsc_send_apdu(_In_ evolis_t* p, _In_ evolis_pcsc_uid_t uid, _In_ evobuf* apdu, _In_ size_t apdu_size, _Out_ evobuf* apdu_reply, _In_ size_t reply_max_size);

/// Disconnects from a smart card.
EVOLIS_WRA int evolis_pcsc_disconnect(_In_ evolis_t* p, _In_ evolis_pcsc_uid_t uid, _In_ evolis_pcsc_disposition_t disposition);

#ifdef __cplusplus
}
#endif
