#ifndef _EMUL_GAMEBOY_CPU_H_
    #define _EMUL_GAMEBOY_CPU_H_
    #include <stdint.h>

//////////////////////////////////////////////////////////////
/// @brief The Game Boy has a set of registers
///        that are crucial for its operation, including
///        both 8-bit and 16-bit registers. The internal
///        8-bit registers are A, B, C, D, E, F, H, and L.
///        These registers may be used in pairs for 16-bit
///        operations as AF, BC, DE, and HL. The two remaining
///        16-bit registers are the program counter (PC) and
///        the stack pointer (SP). The F register holds the CPU
///        flags, and the operation of these flags is identical
///        to their Z80 relative. The lower four bits of this
///        register always read zero even if written with a one
////////////////////////////////////////////////////////////////
typedef struct reg_s {
    union {
        struct {
            uint8_t f;
            uint8_t a;
        };
        uint16_t af;
    };
    union {
        struct {
            uint8_t c;
            uint8_t b;
        };
        uint16_t bc;
    };
    union {
        struct {
            uint8_t e;
            uint8_t d;
        };
        uint16_t de;
    };
    union {
        struct {
            uint8_t l;
            uint8_t h;
        };
        uint16_t hl;
    };
    uint16_t pc;
    uint16_t sp;
} reg_t;

#endif
