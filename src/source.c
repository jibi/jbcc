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

#define _GNU_SOURCE
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <jbcc/source.h>
#include <jbcc/log.h>

source_t *
src_new(const char *path) {

	int fd, ret;
	source_t *src;
	struct stat stat;

	fd = open(path, O_RDONLY);
	if (fd == -1) {
		printf("cannot open source file\n");
		exit(1);
		return NULL;
	}

	src = malloc(sizeof(source_t));
	if (!src) {
		return NULL;
	}

	ret = fstat(fd, &stat);

	if (ret == -1) {
		printf("cannot stat source file\n");
		exit(1);
		return NULL;
	}

	src->len = stat.st_size;
	src->pos = 0;

	src->buf = malloc(src->len * sizeof(src->len));
	if (!src->buf) {
		return NULL;
	}

	read(fd, src->buf, src->len);

	return src;
}

char
src_next_char(source_t *s) {
	if (s->len == s->pos) {
		return 0;
	} else {
		return s->buf[s->pos++];
	}
}

void
src_back_char(source_t *s) {
	s->pos--;
}

void
src_inc_l_nr(source_t *s) {
	s->l_nr++;
}

int
src_get_l_nr(source_t *s) {
	return s->l_nr;
}

char *
src_get_lex(source_t *s, size_t start, size_t len) {
	char *lex;
	asprintf(&lex, "%.*s", (int) len, s->buf + start);
	return lex;
}
