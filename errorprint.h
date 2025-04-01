//errorcodes.h
#pragma once
#define PRINT_ERROR(format, ...) \
    fprintf(stderr, (format), ##__VA_ARGS__)
#define ERR_MEM_ALLOC "Failed to allocate memory\n"