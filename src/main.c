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


#include <stdlib.h>
#include <stdio.h>

#include <iksemel.h>

#include "jabber_bind.h"

int main(void) {
    iks* config = 0;
	JabberBind* bind = 0;
    int ret;

    ret = iks_load("config.xml", &config);

    if(ret != IKS_OK) {
        fprintf(stderr, "Could not load config.xml.\n");
        return 1;
    }

    bind = jb_new(config);

    iks_delete(config);

	if(bind == NULL) {
        fprintf(stderr, "Failed to start service.\n");
		return 1;
	}

	jb_run(bind);

	jb_delete(bind);

    return 0;
}