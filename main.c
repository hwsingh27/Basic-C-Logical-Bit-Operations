/*********************************************************************************
 * Copyright (c) 2021 by Harshwardhan Singh
 * 
 * Redistribution, modification or use of this program in source or binary forms
 * is permitted as long as the files maintain this copyright. Users are permitted
 * to modify this and use it to learn about the field of embedded software.
 * Harshwardhan Singh and the University of Colorado are not liable for any misuse
 * of this material.
**********************************************************************************
/**
 * @file main.c
 * @brief six functions have been given to refresh the C programming skill. Five 
 * out of six functions works perfectly.
 * @author Harshwardhan Singh
 * @date August 30th 2021
 * @tools Visual Studio Code
 * @application links: 
 * TAs (Nimish and Mukta) helped a lot clarifying the specific doubts.
 * Referred Geeks for Geeks to recall the syntax of C.
 * https://www.geeksforgeeks.org/user-defined-data-types-in-c/ 
 */

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h> 

/**
 * @brief function for finding the length of an array or string.
 * 
 * len is a pointer to a char array .
 * 
 * @param len pointer to a data item.
 * @return the function results in finding the length of the char array.
 */
int length_str(char *len)
{
    int count=0;
    for(int i=0;len[i]!='\0';i++)
    {
        count++;
    }
    return count;
}

/**
 * @brief function for reversing the array.
 * 
 * rev is a pointer to a char array.
 * 
 * @param rev pointer to a data item.
 * @return the function results in reversing of the char array.
 */
void reverse(char *rev)
{
    int n=length_str(rev);
    for(int i=0,j=n-1;i<j;i++,j--)
    {
        char ch=rev[i];
        rev[i]=rev[j];
        rev[j]=ch;
    }
}

/**
 * @brief function for converting the unsigned integer to binary.
 * 
 * @param str is a pointer to the char array.
 * @param size char array should be of at least size bytes.
 * @param num num is the input whose value to be converted.
 * @param nbits is the number of bits in the input. 
 * It is also the number of bits to be shown in the array with trailing '0' and 'b'.
 * 
 * @return the function returns the number of characters written in a char array 
 * which signifies the binary representation of the input number.
 */

int uint_to_binstr(char *str,size_t size, uint32_t num, uint8_t nbits)
{
    int i=0;
    int count=0;
    int n=num;
    if(size<=nbits+3 || nbits==0)
    {
        return -1;
        str='\0';
    }
    else
    {
        while(n>0)
        {
            n/=2;
            count++;
        }
        if(count<=nbits)
        {
            while(num>0)
            {
                if(num%2==0)
                {
                    str[i]='0';
                    nbits--;
                }
                else
                {
                    str[i]='1';
                    nbits--;
                }
                i++;
                num=num/2;
            }
            while(nbits>0)
            {
                str[i++]='0';
                nbits--;
            }
            str[i]='b';
            str[i+1]='0';
            str[i+2]='\0';

            int a=length_str(str);
            reverse(str);
            return a;
        }
        else
        {
            return -1;
            str='\0';
        }
    }
}

/**
 * @brief function for converting the signed integer to binary.
 * 
 * @param str is a pointer to the char array.
 * @param size char array should be of atleast size bytes.
 * @param num num is the input whose value to be converted. The value can positive or negative.
 * @param nbits is the number of bits in the input. 
 * It is also the number of bits to be shown in the array with trailing '0' and 'b'.
 * 
 * @return the function returns the number of characters written in a char array 
 * which signifies the binary representation of the input number.
 */

int int_to_binstr(char *str, size_t size, int32_t num, uint8_t nbits)
{
    uint32_t n=abs(num);
    uint32_t m1=abs(num);
    uint32_t m2=abs(num);
    uint32_t count=0;
    uint32_t i=0;
    uint32_t k=0;
    uint32_t m=0;
    uint32_t a=0;
    if(size<nbits+3 || nbits==0)
    {
        return -1;
        str='\0';
    }
    else
    {
        while(n>0)
        {
            n/=2;
            count++;
        }
        if(count<=nbits)
        {
            if(num<0)
            {
                while(m1>0)
                {
                    if(m1%2==0)
                    {
                        str[i]='1';
                        nbits--;
                    }
                    else
                    {
                        str[i]='0';
                        nbits--;
                    }
                    i++;
                    m1=m1/2;
                }
                while(nbits>0)
                {
                    str[i++]='1';
                    nbits--;
                }
                str[i]='b';
                str[i+1]='0';
                str[i+2]='\0';

                a=length_str(str);

                for(k=0;k<=a-2;k++)
                {
                    if(str[k]=='0')
                    {
                        str[k]='1';
                        break;
                    }
                    else if(str[k]=='1' && str[k+1]=='0')
                    {
                        str[k]='0';
                        str[k+1]='1';
                        break;
                    }
                    else
                    {
                        for(m=0;str[m]=='1';m++)
                        {
                            str[m]='0';
                        }
                        str[m]='1';
                        break;
                    }
                }
                reverse(str);
                return a;
            }
            else
            {
                while(num>0)
                {
                    if(num%2==0)
                    {
                        str[i]='0';
                        nbits--;
                    }
                    else
                    {
                        str[i]='1';
                        nbits--;
                    }
                    i++;
                    num=num/2;
                }
                while(nbits>0)
                {
                    str[i++]='0';
                    nbits--;
                }
                str[i]='b';
                str[i+1]='0';
                str[i+2]='\0';

                a=length_str(str);
                reverse(str);
                return a;
            }
        }
        else
        {
            return -1;
            str='\0';
        }
    }
    
}

/**
 * @brief function for converting the unsigned integer to its 
 * corresponding hexadecimal value.
 * 
 * @param str is a pointer to the char array.
 * @param size char array should be of atleast size bytes.
 * @param num num is the input whose value to be converted.
 * @param nbits is the number of bits in the input. 
 * It is also the number of bits to be shown in the array with trailing '0' and 'X'.
 * 
 * @return the function returns the number of characters written in a char array 
 * which signifies the hexadecimal representation of the input value.
 */
int uint_to_hexstr(char *str, size_t size, uint32_t num, uint8_t nbits)
{
    int n=num;
    int count=0;
    int rem=0;
    int i=0;
    uint8_t hexdec=nbits;
    if(size<=nbits+3 || nbits==0)
    {
        return -1;
        str='\0';
    }
    else
    {
        while(n>0)
        {
            n/=16;
            count++;
        }
        if(nbits==4)
        {
            hexdec=1;
        }
        else if(nbits==8)
        {
            hexdec=2;
        }
        else if(nbits==16)
        {
            hexdec=4;
        }
        else if(nbits==32)
        {
            hexdec=8;
        }
        else
        {
            return -1;
            str='\0';
        }
        if(count<=hexdec)
        {
            while(num!=0)
            {
                rem=num%16;
                if(rem<10)
                {
                    str[i++]='0'+rem;
                    hexdec--;
                }
                else
                {
                    str[i++]='A'+rem-10;
                    hexdec--;
                }
                num=num/16;
            }
            while(hexdec>0)
            {
                str[i++]='0';
                hexdec--;
            }
            str[i]='x';
            str[i+1]='0';
            str[i+2]='\0';
            reverse(str);
            int a=length_str(str);
            return a;
        }
        else
        {
            return -1;
            str='\0';
        }
    }
}

/**
 * @brief function for converting the signed integer to binary.
 * 
 * @param input is the value whose bits need to be twiggled.
 * @param bit is the specific bit which needs to be twiggled.
 * @param operation is the type of operation i.e. CLEAR, SET and TOGGLE  
 * that needs to be performed on the input.
 * 
 * @return the function returns the integer number after twiggling the actual number
 */

typedef enum
{
    CLEAR, SET, TOGGLE
}
operation_t;
uint32_t twiggle_bit(uint32_t input, int bit, operation_t operation)
{
    if(bit>=0 && bit<=31)
    {
        uint32_t res;
        if(operation==CLEAR)
        {
            res = input & ~(1<<bit);
        }
        else if(operation==SET)
        {
            res= input | (1<<bit);
        }
        else if(operation==TOGGLE)
        {
            res= input ^ (1<<bit);
        }
        else
        {
            return 0xFFFFFFFF;
        }
        return res;
    }
    else
    {
        return 0xFFFFFFFF;
    }
}

/**
 * @brief function for grabbing the three bits from the start_bit value
 * and move those bits to the extreme left for returning the corresponding
 * integer value.
 * 
 * @param input is an integer whose three bits need to be shifted down.
 * @param start_bit is the starting bit position.
 * 
 * @return the function returns three bits from the input value 
 * shifted down to the extreme left.
 */
uint32_t grab_three_bits(uint32_t input, int start_bit)
{
    uint32_t res;
    if(start_bit>=0 && start_bit<=29)
    {
        res= (input >> start_bit) & 7;
        return res;
    }
    else
    {
        return 0xFFFFFFFF;
    }
}



/**
 * @brief a test function for converting the unsigned integer to binary.
 * 
 * @return the function returns '1' if all the test cases are passed
 * and returns '0' if any one of the test cases fails.
 */
int test_uint_to_binstr()
{
    char b[100];
    uint32_t n;
    uint8_t nb;
    uint32_t flag=0;
    uint32_t a;
    
    a=uint_to_binstr(b,sizeof(b),18,8); 
    if(a==10)
    {
        flag++;
    }
    a=uint_to_binstr(b,sizeof(b),65400,16);  
    if(a==18)
    {
        flag++;
    }
    a=uint_to_binstr(b,sizeof(b),310,0); 
    if(a==-1)
    {
        flag++;
    }
    a=uint_to_binstr(b,sizeof(b),310,4); 
    if(a==-1)
    {
        flag++;
    }
    a=uint_to_binstr(b,sizeof(b),18,-8); 
    if(a==-1)
    {
        flag++;
    }
    a=uint_to_binstr(b,sizeof(b),0,5); 
    if(a==7)
    {
        flag++;
    }
    a=uint_to_binstr(b,sizeof(b),0,0); 
    if(a==-1)
    {
        flag++;
    }
    a=uint_to_binstr(b,sizeof(b),18,101); 
    if(a==-1)
    {
        flag++;
    }
    if(flag==8)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/**
 * @brief a test function for converting the signed integer to binary.
 * 
 * @return the function returns '1' if all the test cases are passed
 * and returns '0' if any one of the test cases fails.
 */
int test_int_to_binstr()
{
    char b[100];
    int32_t n;
    uint8_t nb;
    int32_t a;
    uint32_t flag=0;
    a=int_to_binstr(b,sizeof(b),18,8); 
    if(a==10)
    {
        flag++;
    }
    a=int_to_binstr(b,sizeof(b),-1,4); 
    if(a==6)
    {
        flag++;
    }
    a=int_to_binstr(b,sizeof(b),-3,8); 
    if(a==10)
    {
        flag++;
    }
    a=int_to_binstr(b,sizeof(b),18,103); 
    if(a==-1)
    {
        flag++;
    }
    a=int_to_binstr(b,sizeof(b),0,8); 
    if(a==10)
    {
        flag++;
    }
    a=int_to_binstr(b,sizeof(b),6,2); 
    if(a==-1)
    {
        flag++;
    }
    a=int_to_binstr(b,sizeof(b),-6,2); 
    if(a==-1)
    {
        flag++;
    }
    a=int_to_binstr(b,sizeof(b),6,-8); 
    if(a==-1)
    {
        flag++;
    }
    a=int_to_binstr(b,sizeof(b),0,0);
    if(a==-1)
    {
        flag++;
    }
    if(flag==9)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief a test function for converting the unsigned integer to hexadecimal value.
 * 
 * @return the function returns '1' if all the test cases are passed
 * and returns '0' if any one of the test cases fails.
 */
int test_uint_to_hexstr()
{
    char b[100];
    uint32_t n;
    uint8_t nb;
    int32_t a;
    uint32_t flag=0;

    a=uint_to_hexstr(b,sizeof(b),18,8); 
    if(a==4)
    {
        flag++;
    }
    a=uint_to_hexstr(b,sizeof(b),18,16); 
    if(a==6)
    {
        flag++;
    }
    a=uint_to_hexstr(b,sizeof(b),65400,16); 
    if(a==6)
    {
        flag++;
    }
    a=uint_to_hexstr(b,sizeof(b),310,16); 
    if(a==6)
    {
        flag++;
    }
    a=uint_to_hexstr(b,sizeof(b),18,7); 
    if(a==-1)
    {
        flag++;
    }
    a=uint_to_hexstr(b,sizeof(b),65400,8); 
    if(a==-1)
    {
        flag++;
    }
    a=uint_to_hexstr(b,sizeof(b),0,8); 
    if(a==4)
    {
        flag++;
    }
    a=uint_to_hexstr(b,sizeof(b),18,101); 
    if(a==-1)
    {
        flag++;
    }
    if(flag==8)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief a test function for twiggling the bits of the input.
 * 
 * @return the function returns '1' if all the test cases pass
 * and returns '0' if any one of the test cases fails.
 */
int test_twiggle_bit()
{
    uint32_t n;
    int b;
    uint32_t op;
    int32_t a;
    uint32_t flag=0;
    
    a=twiggle_bit(0,0,SET);
    if(a==1)
    {
        flag++;
    }
    a=twiggle_bit(0,3,SET);
    if(a==8)
    {
        flag++;
    }
    a=twiggle_bit(0x7337,5,TOGGLE); 
    if(a==0x7317)
    {
        flag++;
    }
    a=twiggle_bit(0,3,1); 
    if(a==8)
    {
        flag++;
    }
    a=twiggle_bit(19,4,CLEAR);
    if(a==3)
    {
        flag++;
    }
    a=twiggle_bit(19,4,0);
    if(a==3)
    {
        flag++;
    }
    a=twiggle_bit(18,1,TOGGLE); 
    if(a==16)
    {
        flag++;
    }
    a=twiggle_bit(18,1,2); 
    if(a==16)
    {
        flag++;
    }
    a=twiggle_bit(10,-3,CLEAR); 
    if(a==0xFFFFFFFF)
    {
        flag++;
    }
    a=twiggle_bit(8,33,SET);
    if(a==0xFFFFFFFF)
    {
        flag++;
    }
    a=twiggle_bit(18,1,3); 
    if(a==0xFFFFFFFF)
    {
        flag++;
    }
    if(flag==11)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief a test function for grabbing three bits and shift down.
 * 
 * @return the function returns '1' if all the test cases are passed
 * and returns '0' if any one of the test cases fails.
 */
int test_grab_three_bits()
{
    uint32_t n;
    int st;
    uint32_t flag=0;
    uint32_t a;
    a=grab_three_bits(0x7337,6);
    if(a==4)
    {
        flag++;
    }
    a=grab_three_bits(0x7337,7);
    if(a==6)
    {
        flag++;
    }
    a=grab_three_bits(0x7337,-6);
    if(a==0xFFFFFFFF)
    {
        flag++;
    }
    a=grab_three_bits(0x7337,30);
    if(a==0xFFFFFFFF)
    {
        flag++;
    }
    a=grab_three_bits(0x7337,32);
    if(a==0xFFFFFFFF)
    {
        flag++;
    }
    a=grab_three_bits(0x7337,29);
    if(a==0)
    {
        flag++;
    }
    a=grab_three_bits(0,3);
    if(a==0)
    {
        flag++;
    }
    if(flag==7)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief a main() function which calls all the test functions
 * for checking different test cases.
 * 
 * @return the function prints the result of all the test functions.
 */
int main()
{
    printf("Unsigned Integer to Binary Function\n");
    int32_t res_1=test_uint_to_binstr();
    printf("%d\n",res_1);

    printf("Signed Integer to Binary Function\n");
    int32_t res_2=test_int_to_binstr();
    printf("%d\n",res_2);
    
    printf("Integer to Hexadecimal Function\n");
    int32_t res_3=test_uint_to_hexstr();
    printf("%d\n",res_3);
    
    printf("Twiggle Bit Function\n");
    int32_t res_4=test_twiggle_bit();
    printf("%d\n",res_4);

    printf("Grab Three Bits Function\n");
    uint32_t res_5=test_grab_three_bits();
    printf("%d",res_5);

    return 0;
}
