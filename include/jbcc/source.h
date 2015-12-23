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

#ifndef JBCC_SOURCE_H
#define JBCC_SOURCE_H

typedef struct source_s {
	char *buf;
	size_t len;
	size_t pos;
	int    l_nr;
} source_t;

source_t *src_new(const char *path);
char src_next_char(source_t *s);
void src_back_char(source_t *s);
void src_inc_l_nr(source_t *s);
int src_get_l_nr(source_t *s);
char *src_get_lex(source_t *s, size_t start, size_t end);

#endif
