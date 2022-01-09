#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "uint_binstr.h"
#include "int_binstr.h"
#include "twiggle_bit.h"
#include "grab_bits.h"
#include "hexdump.h"

int test_uint_binstr()
{
    typedef struct
    {
        uint32_t num;
        uint8_t nbits;
        size_t size;
        int expected_res;
        const char *expected_str;
    }test_matrix_t;

    char str[512];
    test_matrix_t tests[]=
    {
        {18,8,sizeof(str),10,"0b00010010"},
        {65400,16,sizeof(str),18,"0b1111111101111000"},
        {310,0,sizeof(str),-1,""},
        {310,4,sizeof(str),-1,""},

        {15,4,sizeof(str),6,"0b1111"},
        {16,4,sizeof(str),-1,""},
        {16,5,sizeof(str),7,"0b10000"},

        {0,1,sizeof(str),3,"0b0"},
        {1,1,sizeof(str),3,"0b1"},
        {0,2,sizeof(str),4,"0b00"},
        {1,2,sizeof(str),4,"0b01"},
        {2,2,sizeof(str),4,"0b10"},
        {3,2,sizeof(str),4,"0b11"},

        {18,8,0,-1,""},
        {18,8,1,-1,""},
        {18,8,2,-1,""},
        {18,8,3,-1,""},
        {18,8,8,-1,""},
        {18,8,11,10,"0b00010010"},
        {10,4,5,-1,""},
        {10,4,7,6,"0b1010"},

        {0xFFFFFFFE,32,sizeof(str),34,"0b11111111111111111111111111111110"},
        {0xFFFFFFFF,32,sizeof(str),34,"0b11111111111111111111111111111111"},

        {16,33,sizeof(str),-1,""}
    };

    const int num_tests = sizeof(tests)/sizeof(test_matrix_t);
    int tests_passed=0;
    char *test_result;
    int act_res;

    for(int i=0;i<num_tests;i++)
    {
        act_res = uint_to_binstr(str,tests[i].size,tests[i].num,tests[i].nbits);
        if(act_res==tests[i].expected_res && strcmp(str,tests[i].expected_str)==0)
        {
            test_result = "PASSED";
            tests_passed++;
        }
        else
        {
            test_result = "FAILED";
        }
        //printf("%s\n",str); //for printing the string in each case
    }
    printf("%s: PASSED %d/%d\n",__FUNCTION__, tests_passed,num_tests);
}

int test_int_binstr()
{
    typedef struct
    {
        int32_t num;
        uint8_t nbits;
        size_t size;
        int expected_res;
        const char *expected_str;
    }test_matrix_t;

    char str[512];
    test_matrix_t tests[]=
    {
        {18,8,sizeof(str),10,"0b00010010"},
        {-1,4,sizeof(str),6,"0b1111"},
        {-3,8,sizeof(str),10,"0b11111101"},

        {8,4,sizeof(str),-1,""}
    };

    const int num_tests = sizeof(tests)/sizeof(test_matrix_t);
    int tests_passed=0;
    char *test_result;
    int act_res;

    for(int i=0;i<num_tests;i++)
    {
        act_res = int_to_binstr(str,tests[i].size,tests[i].num,tests[i].nbits);
        if(act_res==tests[i].expected_res && strcmp(str,tests[i].expected_str)==0)
        {
            test_result = "PASSED";
            tests_passed++;
        }
        else
        {
            test_result = "FAILED";
        }
        //printf("%s\n",str); //for printing the string in each case
    }
    printf("%s: PASSED %d/%d\n",__FUNCTION__, tests_passed,num_tests);
}

int test_twiggle_bit()
{
    typedef struct
    {
        uint32_t input;
        int bit;
        operation_t operation;
        int expected_res;
    }test_matrix_t;

    char str[512];
    test_matrix_t tests[]=
    {
        {0,0,SET,1},
        {0,3,SET,8},
        {0x7337,5,TOGGLE,0x7317},

        {3,1,CLEAR,1},
        {10,3,5,0xFFFFFFFF}, //error case
    };

    const int num_tests = sizeof(tests)/sizeof(test_matrix_t);
    int tests_passed=0;
    char *test_result;
    int act_res;

    for(int i=0;i<num_tests;i++)
    {
        act_res = twiggle_bit(tests[i].input,tests[i].bit,tests[i].operation);
        if(act_res==tests[i].expected_res)
        {
            test_result = "PASSED";
            tests_passed++;
        }
        else
        {
            test_result = "FAILED";
        }
        //printf("%s\n",str); //for printing the string in each case
    }
    printf("%s: PASSED %d/%d\n",__FUNCTION__, tests_passed,num_tests);
}

int test_grab_bits()
{
    typedef struct
    {
        uint32_t input;
        int start_bit;
        int expected_res;
    }test_matrix_t;

    char str[512];
    test_matrix_t tests[]=
    {
        {0x7337,6,4},
        {0x7337,7,6},

        {56,32,0xFFFFFFFF},
        {56,29,0},
    };

    const int num_tests = sizeof(tests)/sizeof(test_matrix_t);
    int tests_passed=0;
    char *test_result;
    int act_res;

    for(int i=0;i<num_tests;i++)
    {
        act_res = grab_three_bits(tests[i].input,tests[i].start_bit);
        if(act_res==tests[i].expected_res)
        {
            test_result = "PASSED";
            tests_passed++;
        }
        else
        {
            test_result = "FAILED";
        }
        //printf("%s\n",str); //for printing the string in each case
    }
    printf("%s: PASSED %d/%d\n",__FUNCTION__, tests_passed,num_tests);
}

char test_hexdump()
{
    const char *buf = "To achieve great things, two things are needed: a plan, and not quite enough time.";
    char str[1024];
    printf(hexdump(str, sizeof(str), buf, strlen(buf)+1));
}
