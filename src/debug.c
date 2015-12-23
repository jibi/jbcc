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

#define _GNU_SOURCE
#include <stdio.h>

#include <jbcc/lex.h>

void
dbg_dump_token(token_t *t, char **str) {
	switch(t->type) {
		case BEGIN_OF_SOURCE:
			asprintf(str, "SOURCE_BEGIN");
			break;
		case RIGHT_ASSIGN:
			asprintf(str, ">>=");
			break;
		case RIGHT_OP:
			asprintf(str, ">>");
			break;
		case GE_OP:
			asprintf(str, ">=");
			break;
		case GT_OP:
			asprintf(str, ">");
			break;
		case LEFT_ASSIGN:
			asprintf(str, "<<=");
			break;
		case LEFT_OP:
			asprintf(str, "<<");
			break;
		case LE_OP:
			asprintf(str, "<=");
			break;
		case LT_OP:
			asprintf(str, "<");
			break;
		case INC_OP:
			asprintf(str, "++");
			break;
		case ADD_ASSIGN:
			asprintf(str, "+=");
			break;
		case PLUS_OP:
			asprintf(str, "+");
			break;
		case DEC_OP:
			asprintf(str, "--");
			break;
		case SUB_ASSIGN:
			asprintf(str, "-=");
			break;
		case PTR_OP:
			asprintf(str, "->");
			break;
		case MINUS_OP:
			asprintf(str, "-");
			break;
		case MUL_ASSIGN:
			asprintf(str, "*=");
			break;
		case STAR_OP:
			asprintf(str, "*");
			break;
		case DIV_ASSIGN:
			asprintf(str, "/=");
			break;
		case DIV_OP:
			asprintf(str, "/");
			break;
		case MOD_ASSIGN:
			asprintf(str, "%%=");
			break;
		case MOD_OP:
			asprintf(str, "%%");
			break;
		case BIT_AND_ASSIGN:
			asprintf(str, "&=");
			break;
		case AND_OP:
			asprintf(str, "&&");
			break;
		case BIT_AND_OP:
			asprintf(str, "&");
			break;
		case BIT_OR_ASSIGN:
			asprintf(str, "|=");
			break;
		case OR_OP:
			asprintf(str, "||");
			break;
		case BIT_OR_OP:
			asprintf(str, "|");
			break;
		case BIT_NOT_OP:
			asprintf(str, "~");
			break;
		case BIT_XOR_ASSIGN:
			asprintf(str, "^=");
			break;
		case BIT_XOR_OP:
			asprintf(str, "^");
			break;
		case NOT_OP:
			asprintf(str, "!");
			break;
		case SEMICOLON:
			asprintf(str, ";");
			break;
		case LEFT_PAREN:
			asprintf(str, "(");
			break;
		case RIGHT_PAREN:
			asprintf(str, ")");
			break;
		case LEFT_BRACKET:
			asprintf(str, "]");
			break;
		case RIGHT_BRACKET:
			asprintf(str, "]");
			break;
		case LEFT_BRACE:
			asprintf(str, "{");
			break;
		case RIGHT_BRACE:
			asprintf(str, "}");
			break;
		case TERN_OP:
			asprintf(str, "?");
			break;
		case COLON:
			asprintf(str, ":");
			break;
		case COMMA:
			asprintf(str, ",");
			break;
		case EQ_OP:
			asprintf(str, "==");
			break;
		case NE_OP:
			asprintf(str, "!=");
			break;
		case ASSIGN_OP:
			asprintf(str, "=");
			break;
		case IDENTIFIER:
			asprintf(str, "id: %s", t->lex);
			break;
		case NUMBER:
			asprintf(str, "num: %s", t->lex);
			break;

		case AUTO:
			asprintf(str, "auto");
			break;
		case BREAK:
			asprintf(str, "break");
			break;
		case CASE:
			break;
			asprintf(str, "case");
		case CHAR:
			break;
		case CONST:
			asprintf(str, "const");
			break;
		case CONTINUE:
			asprintf(str, "continue");
			break;
		case DEFAULT:
			asprintf(str, "default");
			break;
		case DO:
			asprintf(str, "do");
			break;
		case DOUBLE:
			asprintf(str, "double");
			break;
		case ELSE:
			asprintf(str, "else");
			break;
		case ENUM:
			asprintf(str, "enum");
			break;
		case EXTERN:
			asprintf(str, "extern");
			break;
		case FLOAT:
			asprintf(str, "float");
			break;
		case FOR:
			asprintf(str, "for");
			break;
		case GOTO:
			asprintf(str, "goto");
			break;
		case IF:
			asprintf(str, "if");
			break;
		case INT:
			asprintf(str, "int");
			break;
		case LONG:
			asprintf(str, "long");
			break;
		case REGISTER:
			asprintf(str, "register");
			break;
		case RETURN:
			asprintf(str, "return");
			break;
		case SHORT:
			asprintf(str, "short");
			break;
		case SIGNED:
			asprintf(str, "signed");
			break;
		case SIZEOF:
			asprintf(str, "sizeof");
			break;
		case STATIC:
			asprintf(str, "static");
			break;
		case STRUCT:
			asprintf(str, "struct");
			break;
		case SWITCH:
			asprintf(str, "switch");
			break;
		case TYPEDEF:
			asprintf(str, "typeof");
			break;
		case UNION:
			asprintf(str, "union");
			break;
		case UNSIGNED:
			asprintf(str, "unsigned");
			break;
		case VOID:
			asprintf(str, "void");
			break;
		case VOLATILE:
			asprintf(str, "volatile");
			break;
		case WHILE:
			asprintf(str, "while");
			break;

		default:
			asprintf(str, "UNKNOWN");
	}
}

void
dbg_dump_tokens(token_t *t) {
	int l_nr = -1;

	while (t) {
		char *s;

		if (t->l_nr > l_nr) {
			l_nr = t->l_nr;
			printf("\b\b  \n");
		}

		dbg_dump_token(t, &s);

		printf("[ \033[34m%s\033[0m ], ", s);


		t = t->next;
	}

	printf("\b\b  \n");
}
