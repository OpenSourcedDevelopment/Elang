static int is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' ||
        c == '\v' || c == '\f' || c == '\r';
}