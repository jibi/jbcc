/*
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                    Version 2, December 2004
 *
 * Copyright (C) 2015 Jibi <jibi@paranoici.org>
 *
 * Everyone is permitypeed to copy and distribute verbatim or modified
 * copies of this license document, and changing it is allowed as long
 * as the name is changed.
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 *  0. You just DO WHAT THE FUCK YOU WANT TO.
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <jbcc/lex.h>
#include <jbcc/source.h>

token_t *
new_token(int l_nr, token_type_t type) {
	token_t *t;

	t       = malloc(sizeof(token_t));
	t->l_nr  = l_nr;
	t->type = type;

	return t;
}

token_t *
new_id_token(int l_nr, char *lex) {
	token_t *t;

	t       = malloc(sizeof(token_t));
	t->l_nr = l_nr;
	t->type = IDENTIFIER;
	t->lex  = lex;

	return t;
}

bool
is_digit(char c) {
	return c >= '0' && c <= '9';
}

bool
is_oct_digit(char c) {
	return (c >= '0' && c <= '7');
}

bool
is_hex_digit(char c) {
	return is_digit(c) ||
		(c >= 'a' && c <= 'f') ||
		(c >= 'A' && c <= 'F');
}

bool
is_letter(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');

}

bool
is_double_quote(char c) {
	return c == '"';
}

bool
is_space(char c) {
	return c == ' ' || c == '\t';
}

token_t *
read_number(source_t *s) {
	char c;
	int start, len, l_nr;
	token_t *t;

	start = s->pos;
	len   = 0;
	l_nr  = src_get_l_nr(s);
	c     = src_next_char(s);
	t     = NULL;

	switch(c) {
		case '0':
			switch(src_next_char(s)) {
				case 'x':
				case 'X':
					//hex
					//boring
					len++;
					break;
				default:
					//octal
					//boring
					break;
			}
		default:
			src_back_char(s);
	}

	while ((c = src_next_char(s))) {
		if (!(is_digit(c))) {
			goto end_of_token;
		}
		len++;
	}

end_of_token:
	src_back_char(s);

	if (len) {
		t = malloc(sizeof(token_t));
		t->type = NUMBER;
		t->lex  = src_get_lex(s, start, len);
	}

	return t;
}

token_t *
read_identifier(source_t *s) {
	int start, len, l_nr;
	char c, *lex;
	token_t *t;

	start = s->pos;
	l_nr  = src_get_l_nr(s);
	t     = NULL;

	for (len = 0; (c = src_next_char(s)); len++) {
		if (!(is_letter(c) || is_digit(c))) {
			src_back_char(s);
			break;
		}
	}

	lex = src_get_lex(s, start, len);

	switch(len) {
		case 2:
			       if (!strcmp(lex, "if")) {
				return new_token(l_nr, IF);
			} else if (!strcmp(lex, "do")) {
				return new_token(l_nr, DO);
			}
			break;

		case 3:
			       if (!strcmp(lex, "for")) {
				return new_token(l_nr, FOR);
			} else if (!strcmp(lex, "int")) {
				return new_token(l_nr, INT);
			}
			break;

		case 4:
			       if (!strcmp(lex, "auto")) {
				return new_token(l_nr, AUTO);
			} else if (!strcmp(lex, "case")) {
				return new_token(l_nr, CASE);
			} else if (!strcmp(lex, "char")) {
				return new_token(l_nr, CHAR);
			} else if (!strcmp(lex, "else")) {
				return new_token(l_nr, ELSE);
			} else if (!strcmp(lex, "enum")) {
				return new_token(l_nr, ENUM);
			} else if (!strcmp(lex, "goto")) {
				return new_token(l_nr, GOTO);
			} else if (!strcmp(lex, "long")) {
				return new_token(l_nr, LONG);
			} else if (!strcmp(lex, "void")) {
				return new_token(l_nr, VOID);
			}
			break;

		case 5:
			       if (!strcmp(lex, "break")) {
				return new_token(l_nr, BREAK);
			} else if (!strcmp(lex, "const")) {
				return new_token(l_nr, CONST);
			} else if (!strcmp(lex, "float")) {
				return new_token(l_nr, FLOAT);
			} else if (!strcmp(lex, "short")) {
				return new_token(l_nr, SHORT);
			} else if (!strcmp(lex, "union")) {
				return new_token(l_nr, UNION);
			} else if (!strcmp(lex, "while")) {
				return new_token(l_nr, WHILE);
			}

			break;
		case 6:
			       if (!strcmp(lex, "double")) {
				return new_token(l_nr, DOUBLE);
			} else if (!strcmp(lex, "extern")) {
				return new_token(l_nr, EXTERN);
			} else if (!strcmp(lex, "return")) {
				return new_token(l_nr, RETURN);
			} else if (!strcmp(lex, "signed")) {
				return new_token(l_nr, SIGNED);
			} else if (!strcmp(lex, "sizeof")) {
				return new_token(l_nr, SIZEOF);
			} else if (!strcmp(lex, "static")) {
				return new_token(l_nr, STATIC);
			} else if (!strcmp(lex, "struct")) {
				return new_token(l_nr, STRUCT);
			} else if (!strcmp(lex, "switch")) {
				return new_token(l_nr, SWITCH);
			}

			break;
		case 7:
			       if (!strcmp(lex, "default")) {
				return new_token(l_nr, DEFAULT);
			} else if (!strcmp(lex, "typedef")) {
				return new_token(l_nr, TYPEDEF);
			}

			break;
		case 8:
			       if (!strcmp(lex, "continue")) {
				return new_token(l_nr, CONTINUE);
			} else if (!strcmp(lex, "register")) {
				return new_token(l_nr, REGISTER);
			} else if (!strcmp(lex, "unsigned")) {
				return new_token(l_nr, UNSIGNED);
			} else if (!strcmp(lex, "volatile")) {
				return new_token(l_nr, VOLATILE);
			}

			break;
	}

	if (len) {
		t = new_id_token(l_nr, lex);
	}

	return t;
}

token_t *
read_string(source_t *s) {
	return NULL;
}

token_t *
next_token(source_t *s) {
	token_t *token;
	char next_char;
	int l_nr;

next_token:
	do {
		next_char = src_next_char(s);
	} while (is_space(next_char));

	token = NULL;
	l_nr  = src_get_l_nr(s);

	switch (next_char) {
		case '>':
			switch(src_next_char(s)) {
				case '>':
					switch(src_next_char(s)) {
						case '=':
							return new_token(l_nr, RIGHT_ASSIGN);
						default:
							src_back_char(s);
							return new_token(l_nr, RIGHT_OP);
					}
				case '=':
					return new_token(l_nr, GE_OP);
				default:
					src_back_char(s);
					return new_token(l_nr, GT_OP);
			}
		case '<':
			switch(src_next_char(s)) {
				case '<':
					switch(src_next_char(s)) {
						case '=':
							return new_token(l_nr, LEFT_ASSIGN);
						default:
							src_back_char(s);
							return new_token(l_nr, LEFT_OP);
					}
				case '=':
					return new_token(l_nr, LE_OP);
				default:
					src_back_char(s);
					return new_token(l_nr, LT_OP);
			}
		case '+':
			switch(src_next_char(s)) {
				case '+':
					return new_token(l_nr, INC_OP);
				case '=':
					return new_token(l_nr, ADD_ASSIGN);
				default:
					src_back_char(s);
					return new_token(l_nr, PLUS_OP);
			}
		case '-':
			switch(src_next_char(s)) {
				case '-':
					return new_token(l_nr, DEC_OP);
				case '=':
					return new_token(l_nr, SUB_ASSIGN);
				case '>':
					return new_token(l_nr, PTR_OP);
				default:
					src_back_char(s);
					return new_token(l_nr, MINUS_OP);
			}
		case '*':
			switch(src_next_char(s)) {
				case '=':
					return new_token(l_nr, MUL_ASSIGN);
				default:
					src_back_char(s);
					return new_token(l_nr, STAR_OP);
			}
		case '/':
			switch(src_next_char(s)) {
				case '=':
					return new_token(l_nr, DIV_ASSIGN);
				default:
					src_back_char(s);
					return new_token(l_nr, DIV_OP);
			}
		case '%':
			switch (src_next_char(s)) {
				case '=':
					return new_token(l_nr, MOD_ASSIGN);
				default:
					src_back_char(s);
					return new_token(l_nr, MOD_OP);
			}

		case '&':
			switch(src_next_char(s)) {
				case '=':
					return new_token(l_nr, BIT_AND_ASSIGN);
				case '&':
					return new_token(l_nr, AND_OP);
				default:
					src_back_char(s);
					return new_token(l_nr, BIT_AND_OP);
			}
		case '|':
			switch(src_next_char(s)) {
				case '=':
					return new_token(l_nr, BIT_OR_ASSIGN);
				case '|':
					return new_token(l_nr, OR_OP);
				default:
					src_back_char(s);
					return new_token(l_nr, BIT_OR_OP);
			}
		case '^':
			switch(src_next_char(s)) {
				case '=':
					return new_token(l_nr, BIT_XOR_ASSIGN);
				default:
					src_back_char(s);
					return new_token(l_nr, BIT_XOR_OP);
			}
		case '~':
			return new_token(l_nr, BIT_NOT_OP);
		case '!':
			switch(src_next_char(s)) {
				case '=':
					return new_token(l_nr, NE_OP);
				default:
					src_back_char(s);
					return new_token(l_nr, NOT_OP);
			}
		case ';':
			return new_token(l_nr, SEMICOLON);
		case '(':
			return new_token(l_nr, LEFT_PAREN);
		case ')':
			return new_token(l_nr, RIGHT_PAREN);
		case '[':
			return new_token(l_nr, LEFT_BRACKET);
		case ']':
			return new_token(l_nr, RIGHT_BRACKET);
		case '{':
			return new_token(l_nr, LEFT_BRACE);
		case '}':
			return new_token(l_nr, RIGHT_BRACE);
		case '?':
			return new_token(l_nr, TERN_OP);
		case ':':
			return new_token(l_nr, COLON);
		case ',':
			return new_token(l_nr, COMMA);
		case '=':
			switch(src_next_char(s)) {
				case '=':
					return new_token(l_nr, EQ_OP);
				default:
					src_back_char(s);
					return new_token(l_nr, ASSIGN_OP);
			}
		case '\n':
			src_inc_l_nr(s);
			goto next_token;

		default:
			src_back_char(s);

			if (is_digit(next_char)) {
				token = read_number(s);
			} else if (is_letter(next_char)) {
				token = read_identifier(s);
			} else if (is_double_quote(next_char)) {
				token = read_string(s);
			}
	}


	return token;
}

static token_t *
new_begin_of_source_token() {
	token_t *t;
	
	t       = malloc(sizeof(token_t));
	t->l_nr = -1;
	t->type = BEGIN_OF_SOURCE;
	t->next = NULL;

	return t;
}

token_t *
get_tokens(source_t *s) {
	token_t *start;
	token_t *cur;
	token_t *new;

	start  = new_begin_of_source_token();
	cur    = start;

	while ((new = next_token(s))) {
		cur->next = new;
		cur = new;
		cur->next = NULL;
	}

	return start;
}

