/*
 *
 *  BlueZ - Bluetooth protocol stack for Linux
 *
 *  Copyright (C) 2014  Intel Corporation. All rights reserved.
 *
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* Control PDU ids */
#define AVRCP_GET_CAPABILITIES		0x10
#define AVRCP_LIST_PLAYER_ATTRIBUTES	0X11
#define AVRCP_LIST_PLAYER_VALUES	0x12
#define AVRCP_GET_CURRENT_PLAYER_VALUE	0x13
#define AVRCP_SET_PLAYER_VALUE		0x14
#define AVRCP_GET_PLAYER_ATTRIBUTE_TEXT	0x15
#define AVRCP_GET_PLAYER_VALUE_TEXT	0x16
#define AVRCP_DISPLAYABLE_CHARSET	0x17
#define AVRCP_CT_BATTERY_STATUS		0x18
#define AVRCP_GET_ELEMENT_ATTRIBUTES	0x20
#define AVRCP_GET_PLAY_STATUS		0x30
#define AVRCP_REGISTER_NOTIFICATION	0x31
#define AVRCP_REQUEST_CONTINUING	0x40
#define AVRCP_ABORT_CONTINUING		0x41
#define AVRCP_SET_ABSOLUTE_VOLUME	0x50
#define AVRCP_SET_BROWSED_PLAYER	0x70
#define AVRCP_GET_FOLDER_ITEMS		0x71
#define AVRCP_CHANGE_PATH		0x72
#define AVRCP_GET_ITEM_ATTRIBUTES	0x73
#define AVRCP_PLAY_ITEM			0x74
#define AVRCP_SEARCH			0x80
#define AVRCP_ADD_TO_NOW_PLAYING	0x90
#define AVRCP_GENERAL_REJECT		0xA0

struct avrcp;

struct avrcp_control_handler {
	uint8_t id;
	uint8_t code;
	uint8_t (*func) (struct avrcp *session, uint8_t transaction,
			uint16_t *params_len, uint8_t *params, void *user_data);
};

typedef void (*avrcp_destroy_cb_t) (void *user_data);

struct avrcp *avrcp_new(int fd, size_t imtu, size_t omtu, uint16_t version);
void avrcp_shutdown(struct avrcp *session);
void avrcp_set_destroy_cb(struct avrcp *session, avrcp_destroy_cb_t cb,
							void *user_data);
void avrcp_set_control_handlers(struct avrcp *session,
				const struct avrcp_control_handler *handlers,
				void *user_data);
int avrcp_init_uinput(struct avrcp *session, const char *name,
							const char *address);
