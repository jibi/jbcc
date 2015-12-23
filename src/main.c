/*
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                    Version 2, December 2004
 *
 * Copyright (C) 2015 Jibi <jibi@paranoici.org>
 *
 * Everyone is permitted to copy and distribute verbatim or modified
 * copies of this license document, and changing it is allowed as long
 * as the name is changed.
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 *  0. You just DO WHAT THE FUCK YOU WANT TO.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <sys/stat.h>
#include <fcntl.h>

#include <jbcc/source.h>
#include <jbcc/lex.h>
#include <jbcc/debug.h>

int main(int argc, char *argv[]) {
	source_t *s;
	token_t  *t;

	if (argc < 2) {
		printf("Usage: %s [source.c]", argv[0]);
		return 1;
	}

	s = src_new(argv[1]);
	t = get_tokens(s);

	dbg_dump_tokens(t);

	return 0;
}

