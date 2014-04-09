/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/** RPC's from the server to the client
 *
 * implementation of the server stub's
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef LIBDMCONFIG_DEBUG
#include "libdmconfig/debug.h"
#endif

#ifdef HAVE_TALLOC_TALLOC_H
# include <talloc/talloc.h>
#else
# include <talloc.h>
#endif

#include "libdmconfig/dmmsg.h"
#include "libdmconfig/dmconfig.h"
#include "libdmconfig/dmcontext.h"
#include "libdmconfig/codes.h"

#include "mand/dm_token.h"

#include "dm_dmclient_rpc_stub.h"

/*
 * RPC stub's
 */

uint32_t rpc_event_broadcast(DMCONTEXT *ctx, const char *path, uint32_t type)
{
	uint32_t rc;
	DM2_REQUEST *req;

	if (!(req = dm_new_request(ctx, CMD_CLIENT_EVENT_BROADCAST, CMD_FLAG_REQUEST, 0, 0)))
		return RC_ERR_ALLOC;

	if ((rc = dm_add_string(req, AVP_PATH, VP_TRAVELPING, path)) != RC_OK
	    || (rc = dm_add_uint32(req, AVP_EVENT_TYPE, VP_TRAVELPING, type)) != RC_OK
	    || (rc = dm_finalize_packet(req)) != RC_OK)
		return rc;

	return dm_enqueue(ctx, req, ONE_WAY, NULL, NULL);

}
