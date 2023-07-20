/***************************************************
 * File Name: std_types.h
 *
 * Description: types for AVR
 *
 * Module: Common - Platform Types Abstraction
 *
 * Created on: Jun 13, 2023
 *
 * Author: Ahmed Dwidar
 ****************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_
/*boolen data types*/
typedef unsigned char boolen;
/*boolen false value*/
#ifndef FALSE
#define FALSE  (0)
#endif
/*boolen true value*/
#ifndef TRUE
#define TRUE  (1)
#endif

#define LOGIC_HIGH (1)
#define LOGIC_LOW  (0)

#define NULL_PTR   ((void*)0)

typedef unsigned char         uint8;          /*           0 .. 255              */
typedef signed char           sint8;          /*        -128 .. +127             */
typedef unsigned short        uint16;         /*           0 .. 65535            */
typedef signed short          sint16;         /*      -32768 .. +32767           */
typedef unsigned long         uint32;         /*           0 .. 4294967295       */
typedef signed long           sint32;         /* -2147483648 .. +2147483647      */
typedef unsigned long long    uint64;         /*       0 .. 18446744073709551615  */
typedef signed long long      sint64;         /* -9223372036854775808 .. 9223372036854775807 */
typedef float                 float32;
typedef double                float64;


#endif /* STD_TYPES_H_ */
