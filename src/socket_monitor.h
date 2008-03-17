/*
 *   Copyright (c) 2007-2008 C3SL.
 *
 *   This file is part of Bosh.
 *
 *   Bosh is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   any later version.
 *
 *   Bosh is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 */


#ifndef SM_MONITOR_H
#define SM_MONITOR_H

#include <poll.h>

#include "time.h"
#include "hash.h"
#include "list.h"

#define MAX_CLIENTS (1024*16)

typedef void (*Callback)(void* user_data);

struct SocketMonitor;
typedef struct SocketMonitor SocketMonitor;

/*! \brief Create a new monitor. */
SocketMonitor* sm_new();

/*! \brief Destroy a monitor. */
void sm_delete(SocketMonitor* monitor);

/*! \brief Add a socket to the monitor. */
void sm_add_socket(SocketMonitor* monitor, int socket_fd, Callback callback, void* user_data);

/*! \brief Replace a socket from the monitor. */
void sm_replace_socket(SocketMonitor* monitor, int socket_fd, Callback callback, void* user_data);

/*! \brief Remove a socket from the monitor. */
void sm_remove_socket(SocketMonitor* monitor, int socket_fd);

/*! \brief Poll the sockets for any activity. */
void sm_poll(SocketMonitor* monitor, time_type max_time);

#endif
