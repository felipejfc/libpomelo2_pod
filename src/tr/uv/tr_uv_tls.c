/**
 * Copyright (c) 2014,2015 NetEase, Inc. and other Pomelo contributors
 * MIT Licensed.
 */

#include <assert.h>

#include <pc_lib.h>

#include "pr_msg.h"
#include "tr_uv_tls.h"
#include "tr_uv_tls_i.h"

#ifdef ANDROID
//Dirty hack for making it possible to link openssl statically against libpomelo2 on android
//Be warned that I don't know the implications of doing that
typedef void (*sighandler_t)(int);
sighandler_t __unused bsd_signal(int __unused signum, sighandler_t __unused handler);
sighandler_t __unused bsd_signal(int __unused signum, sighandler_t __unused handler) {
  return 0;
}
#endif

static tr_uv_tls_transport_plugin_t instance =
{
    {
        {
            tr_uv_tls_create,
            tr_uv_tls_release,
            tr_uv_tls_plugin_on_register,
            tr_uv_tls_plugin_on_deregister,
            PC_TR_NAME_UV_TLS
        }, /* pc_transport_plugin_t */
        pr_default_msg_encoder, /* encoder */
        pr_default_msg_decoder  /* decoder */
    },
    NULL, /* ssl ctx */
    0 /* enable verify */
};

pc_transport_plugin_t* pc_tr_uv_tls_trans_plugin()
{
    return (pc_transport_plugin_t* )&instance;
}

void tr_uv_tls_set_ca_file(const char* ca_file, const char* ca_path)
{
    int ret;
    if (instance.ctx) {
        ret = SSL_CTX_load_verify_locations(instance.ctx, ca_file, ca_path);
        if (!ret) {
            pc_lib_log(PC_LOG_WARN, "tr_uv_tls_set_ca_file - load verify locations error, cafile: %s, capath: %s", ca_file, ca_path);
            instance.enable_verify = 0;
        } else {
            instance.enable_verify = 1;
        }
    }
}

