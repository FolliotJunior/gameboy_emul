#include <criterion/criterion.h>
#include "cpu.h"

Test(get_flag, test_get_flag1)
{
    uint8_t reg_f1 = 0b10110110;

    cr_assert(GET_FLAG(FLAG_Z, reg_f1) == 1);
    cr_assert(GET_FLAG(FLAG_N, reg_f1) == 0);
    cr_assert(GET_FLAG(FLAG_H, reg_f1) == 1);
    cr_assert(GET_FLAG(FLAG_C, reg_f1) == 1);
}

Test(get_flag, test_get_flag2)
{
    uint8_t reg_f1 = 0b00010000;
    uint8_t reg_f2 = 0b00100000;
    uint8_t reg_f3 = 0b01000000;
    uint8_t reg_f4 = 0b10000000;

    cr_assert(GET_FLAG(FLAG_Z, reg_f1) == 0);
    cr_assert(GET_FLAG(FLAG_N, reg_f1) == 0);
    cr_assert(GET_FLAG(FLAG_H, reg_f1) == 0);
    cr_assert(GET_FLAG(FLAG_C, reg_f1) == 1);

    cr_assert(GET_FLAG(FLAG_Z, reg_f2) == 0);
    cr_assert(GET_FLAG(FLAG_N, reg_f2) == 0);
    cr_assert(GET_FLAG(FLAG_H, reg_f2) == 1);
    cr_assert(GET_FLAG(FLAG_C, reg_f2) == 0);

    cr_assert(GET_FLAG(FLAG_Z, reg_f3) == 0);
    cr_assert(GET_FLAG(FLAG_N, reg_f3) == 1);
    cr_assert(GET_FLAG(FLAG_H, reg_f3) == 0);
    cr_assert(GET_FLAG(FLAG_C, reg_f3) == 0);

    cr_assert(GET_FLAG(FLAG_Z, reg_f4) == 1);
    cr_assert(GET_FLAG(FLAG_N, reg_f4) == 0);
    cr_assert(GET_FLAG(FLAG_H, reg_f4) == 0);
    cr_assert(GET_FLAG(FLAG_C, reg_f4) == 0);
}
