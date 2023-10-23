#pragma once

/**
 * Ячейка массива var где начинается указатель на контекст используемая по
 * умолчанию
 */
#define DEFAULT_CONTEXT_CELL 1

/**
 * Ячейка `eng->var` в которой будет читаться указатель на контекст
 */
#ifndef CONTEXT_CELL
#  define CONTEXT_CELL DEFAULT_CONTEXT_CELL
#endif

#include <dll_tools.h>
