/**
 * Evolis C library
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
 * ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 */
#pragma once

#ifdef _WIN32

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <wchar.h>
#include <sys/types.h>

#include "evolis.h"
#include "evo-pcsc.h"

// This file contains the stdcall equivalent of some evolis functions.
EVOLIS_LIB int __stdcall evolis_stdcall_bezel_get_behavior(evolis_t* printer, evolis_bezel_behavior_t* bb);
EVOLIS_LIB int __stdcall evolis_stdcall_bezel_get_delay(evolis_t* printer, int* seconds);
EVOLIS_LIB int __stdcall evolis_stdcall_bezel_get_offset(evolis_t* printer, int* mm);
EVOLIS_LIB int __stdcall evolis_stdcall_bezel_set_behavior(evolis_t* printer, evolis_bezel_behavior_t bb);
EVOLIS_LIB int __stdcall evolis_stdcall_bezel_set_delay(evolis_t* printer, int seconds);
EVOLIS_LIB int __stdcall evolis_stdcall_bezel_set_offset(evolis_t* printer, int mm);
EVOLIS_LIB int __stdcall evolis_stdcall_card_flip(evolis_t* printer);
EVOLIS_LIB int __stdcall evolis_stdcall_clear_mechanical_errors(evolis_t* printer);
EVOLIS_LIB void __stdcall evolis_stdcall_close(evolis_t* printer);
EVOLIS_LIB int32_t __stdcall evolis_stdcall_commandt(evolis_t* printer, const evobuf* cmd, size_t cmdSize, evobuf* reply, size_t replyMaxSize, int timeout);
EVOLIS_LIB int __stdcall evolis_stdcall_discovery_start(evolis_discovery_cb cb, void* data);
EVOLIS_LIB void __stdcall evolis_stdcall_discovery_stop();
EVOLIS_LIB int __stdcall evolis_stdcall_eject(evolis_t* printer);
EVOLIS_LIB int __stdcall evolis_stdcall_firmware_update(evolis_t* printer, const char* path);
EVOLIS_LIB int __stdcall evolis_stdcall_firmware_updateb(evolis_t* printer, const evobuf* data, size_t size);
EVOLIS_LIB int __stdcall evolis_stdcall_firmware_updatebt(evolis_t* printer, const evobuf* data, size_t size, int timeout);
EVOLIS_LIB int __stdcall evolis_stdcall_firmware_updatet(evolis_t* printer, const char* path, int timeout);
EVOLIS_LIB void __stdcall evolis_stdcall_free_devices(evolis_device_t* devices);
EVOLIS_LIB int __stdcall evolis_stdcall_get_cleaning(evolis_t* printer, evolis_cleaning_t* info);
EVOLIS_LIB int __stdcall evolis_stdcall_get_error_management(evolis_t* printer, evolis_error_management_t* em);
EVOLIS_LIB const char* __stdcall evolis_stdcall_get_error_name(int r);
EVOLIS_LIB int __stdcall evolis_stdcall_get_error_tray(evolis_t* printer, evolis_outtray_t* tray);
EVOLIS_LIB int __stdcall evolis_stdcall_get_feeder(evolis_t* printer, evolis_feeder_t* f);
EVOLIS_LIB int __stdcall evolis_stdcall_get_info(evolis_t* printer, evolis_info_t* info);
EVOLIS_LIB int __stdcall evolis_stdcall_get_input_tray(evolis_t* printer, evolis_intray_t* tray);
EVOLIS_LIB const char* __stdcall evolis_stdcall_get_model_name(evolis_model_t model);
EVOLIS_LIB int __stdcall evolis_stdcall_get_network_interface(evolis_t* printer, evolis_network_interface_type_t nit, evolis_network_interface_t* info);
EVOLIS_LIB int __stdcall evolis_stdcall_get_open_mode(evolis_t* printer, evolis_open_mode_t* mode);
EVOLIS_LIB int __stdcall evolis_stdcall_get_output_tray(evolis_t* printer, evolis_outtray_t* tray);
EVOLIS_LIB int __stdcall evolis_stdcall_get_retransfer_film(evolis_t* printer, evolis_ribbon_t* ribbon);
EVOLIS_LIB int __stdcall evolis_stdcall_get_ribbon(evolis_t* printer, evolis_ribbon_t* ribbon);
EVOLIS_LIB bool __stdcall evolis_stdcall_get_session_management(evolis_t* printer);
EVOLIS_LIB int __stdcall evolis_stdcall_get_state(evolis_t* printer, evolis_major_state_t* major, evolis_minor_state_t* minor);
EVOLIS_LIB int __stdcall evolis_stdcall_get_time_to_auto_shutdown(evolis_t* ctx);
EVOLIS_LIB int __stdcall evolis_stdcall_get_time_to_standby(evolis_t* ctx);
EVOLIS_LIB bool __stdcall evolis_stdcall_http_get_allow_unchecked_cert(evolis_t* printer);
EVOLIS_LIB bool __stdcall evolis_stdcall_http_get_allow_unsafe(evolis_t* printer);
EVOLIS_LIB void __stdcall evolis_stdcall_http_set_allow_unchecked_cert(evolis_t* printer, bool enable);
EVOLIS_LIB void __stdcall evolis_stdcall_http_set_allow_unsafe(evolis_t* printer, bool enable);
EVOLIS_LIB int __stdcall evolis_stdcall_insert(evolis_t* printer);
EVOLIS_LIB int __stdcall evolis_stdcall_kineclipse_disable(evolis_t* ctx);
EVOLIS_LIB int __stdcall evolis_stdcall_kineclipse_enable(evolis_t* ctx);
EVOLIS_LIB int __stdcall evolis_stdcall_kineclipse_get_number_of_passes(evolis_t* ctx);
EVOLIS_LIB int __stdcall evolis_stdcall_kineclipse_is_enabled(evolis_t* ctx, bool* isEnabled);
EVOLIS_LIB int __stdcall evolis_stdcall_kineclipse_set_number_of_passes(evolis_t* ctx, uint8_t passes);
EVOLIS_LIB int __stdcall evolis_stdcall_laminator_enable_parallel_mode(evolis_t* printer, bool enable);
EVOLIS_LIB int __stdcall evolis_stdcall_laminator_enable_parallel_modet(evolis_t* printer, bool enable, int timeout);
EVOLIS_LIB int __stdcall evolis_stdcall_laminator_film(evolis_t* printer, evolis_laminator_index_t laminatorIndex, evolis_laminator_film_t* film);
EVOLIS_LIB int __stdcall evolis_stdcall_laminator_filmt(evolis_t* printer, evolis_laminator_index_t laminatorIndex, evolis_laminator_film_t* film, int timeout);
EVOLIS_LIB int __stdcall evolis_stdcall_laminator_info(evolis_t* printer, evolis_laminator_index_t laminatorIndex, evolis_laminator_info_t* lam);
EVOLIS_LIB int __stdcall evolis_stdcall_laminator_infot(evolis_t* printer, evolis_laminator_index_t laminatorIndex, evolis_laminator_info_t* lam, int timeout);
EVOLIS_LIB int __stdcall evolis_stdcall_laminator_is_parallel_mode_enabled(evolis_t* printer, bool* enabled);
EVOLIS_LIB int __stdcall evolis_stdcall_laminator_is_parallel_mode_enabledt(evolis_t* printer, bool* enabled, int timeout);
EVOLIS_LIB int __stdcall evolis_stdcall_laminator_is_valid(evolis_t* printer, evolis_laminator_index_t laminatorIndex);
EVOLIS_LIB int __stdcall evolis_stdcall_laminator_is_validt(evolis_t* printer, evolis_laminator_index_t laminatorIndex, int timeout);
EVOLIS_LIB int __stdcall evolis_stdcall_laminator_set_first_patch(evolis_t* printer, evolis_laminator_index_t laminatorIndex, bool front);
EVOLIS_LIB int __stdcall evolis_stdcall_laminator_set_first_patcht(evolis_t* printer, evolis_laminator_index_t laminatorIndex, bool front, int timeout);
EVOLIS_LIB int __stdcall evolis_stdcall_laminator_set_mode(evolis_t* printer, evolis_laminator_index_t laminatorIndex, evolis_laminator_mode_t mode);
EVOLIS_LIB int __stdcall evolis_stdcall_laminator_set_modet(evolis_t* printer, evolis_laminator_index_t laminatorIndex, evolis_laminator_mode_t mode, int timeout);
EVOLIS_LIB int __stdcall evolis_stdcall_laminator_set_speed_cfg(evolis_t* printer, evolis_laminator_index_t laminatorIndex, evolis_face_t face, uint16_t value);
EVOLIS_LIB int __stdcall evolis_stdcall_laminator_set_speed_cfgt(evolis_t* printer, evolis_laminator_index_t laminatorIndex, evolis_face_t face, uint16_t value, int timeout);
EVOLIS_LIB int __stdcall evolis_stdcall_laminator_set_temp_cfg(evolis_t* printer, evolis_laminator_index_t laminatorIndex, evolis_face_t face, uint16_t value);
EVOLIS_LIB int __stdcall evolis_stdcall_laminator_set_temp_cfgt(evolis_t* printer, evolis_laminator_index_t laminatorIndex, evolis_face_t face, uint16_t value, int timeout);
EVOLIS_LIB int __stdcall evolis_stdcall_lock(evolis_t* ctx);
EVOLIS_LIB int __stdcall evolis_stdcall_lock_disable(evolis_t* ctx);
EVOLIS_LIB int __stdcall evolis_stdcall_lock_enable(evolis_t* ctx);
EVOLIS_LIB int __stdcall evolis_stdcall_lock_is_enabled(evolis_t* ctx, bool* isEnabled);
EVOLIS_LIB void __stdcall evolis_stdcall_log_set_console(bool on);
EVOLIS_LIB void __stdcall evolis_stdcall_log_set_level(evolis_log_t level);
EVOLIS_LIB void __stdcall evolis_stdcall_log_set_path(const char* path);
EVOLIS_LIB int __stdcall evolis_stdcall_login(evolis_t* printer, const char* username, const char* password);
EVOLIS_LIB int __stdcall evolis_stdcall_logout(evolis_t* printer);
EVOLIS_LIB void __stdcall evolis_stdcall_mag_init(evolis_mag_tracks_t* tracks);
EVOLIS_LIB int __stdcall evolis_stdcall_mag_read(evolis_t* printer, evolis_mag_tracks_t* tracks);
EVOLIS_LIB int __stdcall evolis_stdcall_mag_read_tracks(evolis_t* printer, evolis_mag_tracks_t* tracks, bool track1, bool track2, bool track3);
EVOLIS_LIB int __stdcall evolis_stdcall_mag_read_trackst(evolis_t* printer, evolis_mag_tracks_t* tracks, bool track1, bool track2, bool track3, int timeout);
EVOLIS_LIB int __stdcall evolis_stdcall_mag_readt(evolis_t* printer, evolis_mag_tracks_t* tracks, int timeout);
EVOLIS_LIB int __stdcall evolis_stdcall_mag_write(evolis_t* printer, evolis_mag_tracks_t* tracks);
EVOLIS_LIB int __stdcall evolis_stdcall_mag_writet(evolis_t* printer, evolis_mag_tracks_t* tracks, int timeout);
EVOLIS_LIB evolis_t* __stdcall evolis_stdcall_open(const char* name);
EVOLIS_LIB evolis_t* __stdcall evolis_stdcall_open_with_mode(const char* name, evolis_open_mode_t mode);
EVOLIS_LIB int __stdcall evolis_stdcall_pcsc_connect(evolis_t* p, evolis_pcsc_uid_t uid, evolis_pcsc_protocol_t protocol);
EVOLIS_LIB int __stdcall evolis_stdcall_pcsc_disconnect(evolis_t* p, evolis_pcsc_uid_t uid, evolis_pcsc_disposition_t disposition);
EVOLIS_LIB int __stdcall evolis_stdcall_pcsc_encoder_status(evolis_t* p, evolis_pcsc_uid_t uid, evolis_pcsc_status_t* status);
EVOLIS_LIB int __stdcall evolis_stdcall_pcsc_list(evolis_t* p, evolis_pcsc_encoder_t encoders[], size_t max_size);
EVOLIS_LIB int __stdcall evolis_stdcall_pcsc_read_atr(evolis_t* p, evolis_pcsc_uid_t uid, evolis_pcsc_atr_t* atr);
EVOLIS_LIB int __stdcall evolis_stdcall_pcsc_send_apdu(evolis_t* p, evolis_pcsc_uid_t uid, evobuf* apdu, size_t apdu_size, evobuf* apdu_reply, size_t reply_max_size);
EVOLIS_LIB int __stdcall evolis_stdcall_pcsc_status(evolis_t* p, evolis_pcsc_status_t status[], size_t max_size);
EVOLIS_LIB int __stdcall evolis_stdcall_pcsc_wait_card_absent(evolis_t* p, evolis_pcsc_uid_t uid);
EVOLIS_LIB int __stdcall evolis_stdcall_pcsc_wait_card_absentt(evolis_t* p, evolis_pcsc_uid_t uid, int timeout_ms);
EVOLIS_LIB int __stdcall evolis_stdcall_pcsc_wait_card_present(evolis_t* p, evolis_pcsc_uid_t uid);
EVOLIS_LIB int __stdcall evolis_stdcall_pcsc_wait_card_presentt(evolis_t* p, evolis_pcsc_uid_t uid, int timeout_ms);
EVOLIS_LIB int __stdcall evolis_stdcall_print_apply_color_config(evolis_t* printer, evolis_color_config_t cfg, evolis_face_t face);
EVOLIS_LIB int __stdcall evolis_stdcall_print_exect(evolis_t* printer, int timeout);
EVOLIS_LIB bool __stdcall evolis_stdcall_print_export_config(evolis_t* printer, const char* filepath, char separator);
EVOLIS_LIB bool __stdcall evolis_stdcall_print_get_auto_eject(evolis_t* ctx);
EVOLIS_LIB bool __stdcall evolis_stdcall_print_get_bool_setting(evolis_t* printer, evosettings_key_t key, bool* value);
EVOLIS_LIB bool __stdcall evolis_stdcall_print_get_forced_setting(evolis_t* printer, const char* key, const char** value);
EVOLIS_LIB int __stdcall evolis_stdcall_print_get_forced_setting_count(evolis_t* printer);
EVOLIS_LIB const char* __stdcall evolis_stdcall_print_get_forced_setting_key(evolis_t* printer, int index);
EVOLIS_LIB bool __stdcall evolis_stdcall_print_get_int_setting(evolis_t* printer, evosettings_key_t key, int* value);
EVOLIS_LIB int __stdcall evolis_stdcall_print_get_prn_size(evolis_t* printer);
EVOLIS_LIB bool __stdcall evolis_stdcall_print_get_setting(evolis_t* printer, evosettings_key_t key, const char** value);
EVOLIS_LIB int __stdcall evolis_stdcall_print_get_setting_count(evolis_t* printer);
EVOLIS_LIB evosettings_key_t __stdcall evolis_stdcall_print_get_setting_key(evolis_t* printer, int index);
EVOLIS_LIB int __stdcall evolis_stdcall_print_init(evolis_t* printer);
EVOLIS_LIB int __stdcall evolis_stdcall_print_init_from_driver_settings(evolis_t* printer);
EVOLIS_LIB int __stdcall evolis_stdcall_print_init_with_ribbon(evolis_t* printer, evolis_ribbon_type_t ribbon);
EVOLIS_LIB int __stdcall evolis_stdcall_print_init_with_rw_card(evolis_t* printer, evolis_rw_card_type_t ct);
EVOLIS_LIB bool __stdcall evolis_stdcall_print_is_setting_valid(evolis_t* printer, evosettings_key_t key);
EVOLIS_LIB bool __stdcall evolis_stdcall_print_remove_forced_setting(evolis_t* printer, const char* key);
EVOLIS_LIB bool __stdcall evolis_stdcall_print_remove_setting(evolis_t* printer, evosettings_key_t key);
EVOLIS_LIB bool __stdcall evolis_stdcall_print_set_auto_eject(evolis_t* ctx, bool on);
EVOLIS_LIB int __stdcall evolis_stdcall_print_set_blackp(evolis_t* printer, evolis_face_t face, const char* path);
EVOLIS_LIB bool __stdcall evolis_stdcall_print_set_bool_setting(evolis_t* printer, evosettings_key_t key, bool value);
EVOLIS_LIB void __stdcall evolis_stdcall_print_set_forced_setting(evolis_t* printer, const char* key, const char* value);
EVOLIS_LIB int __stdcall evolis_stdcall_print_set_imagep(evolis_t* printer, evolis_face_t face, const char* path);
EVOLIS_LIB bool __stdcall evolis_stdcall_print_set_int_setting(evolis_t* printer, evosettings_key_t key, int value);
EVOLIS_LIB int __stdcall evolis_stdcall_print_set_overlayp(evolis_t* printer, evolis_face_t face, const char* path);
EVOLIS_LIB void __stdcall evolis_stdcall_print_set_prnlog(evolis_t* printer, bool enabled, const char* dirPath);
EVOLIS_LIB int __stdcall evolis_stdcall_print_set_rw_areasp(evolis_t* printer, evolis_face_t face, const char* path);
EVOLIS_LIB int __stdcall evolis_stdcall_print_set_second_overlayp(evolis_t* printer, evolis_face_t face, const char* path);
EVOLIS_LIB bool __stdcall evolis_stdcall_print_set_setting(evolis_t* printer, evosettings_key_t key, const char* value);
EVOLIS_LIB int __stdcall evolis_stdcall_print_set_silverp(evolis_t* printer, evolis_face_t face, const char* path);
EVOLIS_LIB int __stdcall evolis_stdcall_print_set_uvp(evolis_t* printer, evolis_face_t face, const char* path);
EVOLIS_LIB int __stdcall evolis_stdcall_print_test_card(evolis_t* printer, int type);
EVOLIS_LIB int __stdcall evolis_stdcall_print_to_buffer(evolis_t* printer, evobuf* buffer, size_t bufferSize);
EVOLIS_LIB int __stdcall evolis_stdcall_print_to_file(evolis_t* printer, const char* path);
EVOLIS_LIB int32_t __stdcall evolis_stdcall_readt(evolis_t* printer, evobuf* data, size_t maxSize, int timeout);
EVOLIS_LIB int __stdcall evolis_stdcall_reject(evolis_t* printer);
EVOLIS_LIB int __stdcall evolis_stdcall_release(evolis_t* printer);
EVOLIS_LIB int __stdcall evolis_stdcall_reserve(evolis_t* printer, int session, int waitMs);
EVOLIS_LIB int __stdcall evolis_stdcall_scan_acquire(evolis_t* printer);
EVOLIS_LIB int32_t __stdcall evolis_stdcall_scan_command(evolis_t* printer, const evobuf* cmd, size_t cmdSize, evobuf* reply, size_t replyMaxSize);
EVOLIS_LIB int __stdcall evolis_stdcall_scan_firmware_update(evolis_t* printer, const char* path);
EVOLIS_LIB int __stdcall evolis_stdcall_scan_get_image(evolis_t* printer, evolis_scan_image_t type, evobuf* buffer, size_t* size);
EVOLIS_LIB const char* __stdcall evolis_stdcall_scan_get_library_path();
EVOLIS_LIB int __stdcall evolis_stdcall_scan_get_option(evolis_t* printer, evolis_scan_opt_t key, int* value);
EVOLIS_LIB int __stdcall evolis_stdcall_scan_init(evolis_t* printer);
EVOLIS_LIB int __stdcall evolis_stdcall_scan_save_image(evolis_t* printer, evolis_scan_image_t type, const char* path);
EVOLIS_LIB int __stdcall evolis_stdcall_scan_set_library_path(const char* path);
EVOLIS_LIB int __stdcall evolis_stdcall_scan_set_option(evolis_t* printer, evolis_scan_opt_t key, int value);
EVOLIS_LIB int __stdcall evolis_stdcall_service_get_printer_event(evolis_t* printer, evobuf* reply, size_t replySize);
EVOLIS_LIB bool __stdcall evolis_stdcall_service_is_action_available(int actionsMask, evolis_service_action_t action);
EVOLIS_LIB bool __stdcall evolis_stdcall_service_is_running();
EVOLIS_LIB bool __stdcall evolis_stdcall_service_restart();
EVOLIS_LIB bool __stdcall evolis_stdcall_service_select(evolis_model_t model);
EVOLIS_LIB bool __stdcall evolis_stdcall_service_select_with_url(evolis_model_t model, const char* url);
EVOLIS_LIB int __stdcall evolis_stdcall_service_set_printer_event(evolis_t* printer, const char* eventName, evolis_service_action_t action);
EVOLIS_LIB bool __stdcall evolis_stdcall_service_start();
EVOLIS_LIB bool __stdcall evolis_stdcall_service_stop();
EVOLIS_LIB int __stdcall evolis_stdcall_set_card_pos(evolis_t* printer, evolis_pos_t pos);
EVOLIS_LIB int __stdcall evolis_stdcall_set_error_management(evolis_t* printer, evolis_error_management_t em);
EVOLIS_LIB int __stdcall evolis_stdcall_set_error_tray(evolis_t* printer, evolis_outtray_t tray);
EVOLIS_LIB int __stdcall evolis_stdcall_set_feeder(evolis_t* printer, evolis_feeder_t f);
EVOLIS_LIB int __stdcall evolis_stdcall_set_input_tray(evolis_t* printer, evolis_intray_t tray);
EVOLIS_LIB int __stdcall evolis_stdcall_set_output_tray(evolis_t* printer, evolis_outtray_t tray);
EVOLIS_LIB void __stdcall evolis_stdcall_set_session_management(evolis_t* printer, bool on);
EVOLIS_LIB int __stdcall evolis_stdcall_set_time_to_auto_shutdown(evolis_t* ctx, uint16_t seconds);
EVOLIS_LIB int __stdcall evolis_stdcall_set_time_to_standby(evolis_t* ctx, uint16_t seconds);
EVOLIS_LIB int __stdcall evolis_stdcall_shutdown(evolis_t* ctx);
EVOLIS_LIB int __stdcall evolis_stdcall_status(evolis_t* printer, evolis_status_t* status);
EVOLIS_LIB int __stdcall evolis_stdcall_status_enable(evolis_t* printer);
EVOLIS_LIB bool __stdcall evolis_stdcall_status_is_on(const evolis_status_t* status, evolis_flag_t f);
EVOLIS_LIB bool __stdcall evolis_stdcall_status_is_on_cfg(const evolis_status_t* status, evolis_flag_t f);
EVOLIS_LIB bool __stdcall evolis_stdcall_status_is_on_err(const evolis_status_t* status, evolis_flag_t f);
EVOLIS_LIB bool __stdcall evolis_stdcall_status_is_on_ex1(const evolis_status_t* status, evolis_ex1_flag_t f);
EVOLIS_LIB bool __stdcall evolis_stdcall_status_is_on_ex2(const evolis_status_t* status, evolis_ex2_flag_t f);
EVOLIS_LIB bool __stdcall evolis_stdcall_status_is_on_ex3(const evolis_status_t* status, evolis_ex3_flag_t f);
EVOLIS_LIB bool __stdcall evolis_stdcall_status_is_on_ex4(const evolis_status_t* status, evolis_ex4_flag_t f);
EVOLIS_LIB bool __stdcall evolis_stdcall_status_is_on_inf(const evolis_status_t* status, evolis_flag_t f);
EVOLIS_LIB bool __stdcall evolis_stdcall_status_is_on_war(const evolis_status_t* status, evolis_flag_t f);
EVOLIS_LIB int __stdcall evolis_stdcall_status_send_request(evolis_t* printer, evolis_status_t* status);
EVOLIS_LIB size_t __stdcall evolis_stdcall_status_to_string(const evolis_status_t* status, char* outStr, size_t outSize);
EVOLIS_LIB int __stdcall evolis_stdcall_unlock(evolis_t* ctx);
EVOLIS_LIB int __stdcall evolis_stdcall_unlock_get_time(evolis_t* ctx);
EVOLIS_LIB int __stdcall evolis_stdcall_unlock_set_time(evolis_t* ctx, uint16_t time);
EVOLIS_LIB const char* __stdcall evolis_stdcall_version();
EVOLIS_LIB int32_t __stdcall evolis_stdcall_writet(evolis_t* printer, const evobuf* data, size_t size, int timeout);

EVOLIS_LIB int _stdcall evolis_stdcall_file_read(const char* filename, char** data, size_t* size);
EVOLIS_LIB int _stdcall evolis_stdcall_file_write(const char* filename, const char* data, size_t size);
EVOLIS_LIB void _stdcall evolis_stdcall_file_free(char* p);
EVOLIS_LIB const char* _stdcall evolis_stdcall_get_major_string(evolis_major_state_t major);
EVOLIS_LIB const char* _stdcall evolis_stdcall_get_minor_string(evolis_minor_state_t minor);

#ifdef __cplusplus
}
#endif

#endif // _WIN32

