#include <criterion/criterion.h>
#include "cpu.h"

Test(reg, test_reg_struct)
{
    reg_t reg = {0};

    reg.f = 5;
    reg.c = 6;
    reg.e = 7;
    reg.l = 8;
    cr_assert(reg.af == 5);
    cr_assert(reg.bc == 6);
    cr_assert(reg.de == 7);
    cr_assert(reg.hl == 8);
}
