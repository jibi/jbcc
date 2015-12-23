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

#ifndef JBCC_LEX_H
#define JBCC_LEX_H

#include <jbcc/source.h>

typedef enum toke_type_e {
	BEGIN_OF_SOURCE,

	AUTO,
	BREAK,
	CASE,
	CHAR,
	CONST,
	CONTINUE,
	DEFAULT,
	DO,
	DOUBLE,
	ELSE,
	ENUM,
	EXTERN,
	FLOAT,
	FOR,
	GOTO,
	IF,
	INT,
	LONG,
	REGISTER,
	RETURN,
	SHORT,
	SIGNED,
	SIZEOF,
	STATIC,
	STRUCT,
	SWITCH,
	TYPEDEF,
	UNION,
	UNSIGNED,
	VOID,
	VOLATILE,
	WHILE,

	RIGHT_ASSIGN,
	LEFT_ASSIGN,
	ADD_ASSIGN,
	SUB_ASSIGN,
	MUL_ASSIGN,
	DIV_ASSIGN,
	MOD_ASSIGN,
	BIT_AND_ASSIGN,
	BIT_XOR_ASSIGN,
	BIT_OR_ASSIGN,
	RIGHT_OP,
	LEFT_OP,
	INC_OP,
	DEC_OP,
	PTR_OP,
	AND_OP,
	OR_OP,
	LE_OP,
	GE_OP,
	EQ_OP,
	NE_OP,

	SEMICOLON,
	LEFT_BRACE,
	RIGHT_BRACE,
	COMMA,
	COLON,
	ASSIGN_OP,
	LEFT_PAREN,
	RIGHT_PAREN,
	LEFT_BRACKET,
	RIGHT_BRACKET,
	DOT_OP,
	BIT_AND_OP,
	NOT_OP,
	BIT_NOT_OP,
	MINUS_OP,
	PLUS_OP,
	STAR_OP,
	DIV_OP,
	MOD_OP,
	LT_OP,
	GT_OP,
	BIT_XOR_OP,
	BIT_OR_OP,
	TERN_OP,

	IDENTIFIER,
	NUMBER,
} token_type_t;

typedef struct token_s {
	token_type_t type;
	char        *lex;
	int          l_nr;

	struct token_s *next;
} token_t;

token_t *get_tokens(source_t *s);

#endif

