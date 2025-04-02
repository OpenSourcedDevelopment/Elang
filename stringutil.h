//stringlib.h
#pragma once

/**
 * @brief Find the closest character after c that has no whitespace
 * 
 * @param c Starting position
 * @return char* Pointer to closest character after c with no whitespace
 */
char* loop_until_no_whitespace(char* c);

/**
 * @brief Find the closest character after c that has whitespace
 * 
 * @param c Starting position
 * @return char* Pointer to closest character after c with whitespace
 */
char* loop_until_whitespace(char* c);

/**
 * @brief Replace all substrings with substring and return new string
 * 
 * @param str String
 * @param before Substring to be replaced
 * @param new Substring as replacement
 * @return char* Newly allocated string
 */
char* replace_a(const char* str, const char* before, const char* new);