#define ENABLE_ASSERT

#include "defines.h"
#include "base/base_inc.h"
#include "os/os_inc.h"

#include "base/base_inc.cpp"
#include "os/os_inc.cpp"

int app() {
    U64 bytes = Bytes(1);
    U64 kilobytes = Kilobytes(1);
    U64 megabytes = Megabytes(1);
    U64 gigabytes = Gigabytes(1);

    printf("B: %llu, KB: %llu, MB: %llu, GB: %llu\n", bytes, kilobytes, megabytes, gigabytes);

    U64 thousands = Thousand(1);
    U64 millions = Million(1);
    U64 billions = Billion(1);

    printf("T: %llu, M: %llu, B: %llu\n", thousands, millions, billions);

    U8 a = 'a';
    U8 b = 'b';

    printf("A: %c, B: %c\n", a, b);
    Swap(U8, a, b);
    printf("Swapped: A: %c, B: %c\n", a, b);

    U8 char_arr[3] = {'a', 'b', 'c'};
    for(U8 i = 0; i < 3; i++){
        printf("%c", char_arr[i]);
    }
    printf("\ncount: %d\n", (U8)ArrayCount(char_arr));

    U16 align = 10;
    U16 power = 8;

    if(IsPow2(power)){
    printf("Is pow2\n");
    printf("Align up: %d, Align down: %d", AlignUpPow2(align, power), AlignDownPow2(align, power));
    } 
    else printf("Not pow2\n");

    U16 higher = 100;
    U16 lower = 50;

    printf("Min: %d, Max: %d, Clamp 1: %d, Clamp 2: %d, Clamp 3: %d\n", Min(higher, lower), Max(higher, lower),
           Clamp(10, 20, 100), Clamp(50, 25, 100), Clamp(10, 50, 30));
    
    printf("U8Max : %llu\n", (U64)U8Max );
    printf("U16Max: %llu\n", (U64)U16Max);
    printf("U32Max: %llu\n", (U64)U32Max);
    printf("U64Max: %llu\n", (U64)U64Max);
    printf("U8Min : %llu\n", (U64)U8Min );
    printf("U16Min: %llu\n", (U64)U16Min);
    printf("U32Min: %llu\n", (U64)U32Min);
    printf("U64Min: %llu\n", (U64)U64Min);

    printf("S8Max : %lld\n", (S64)S8Max );
    printf("S16Max: %lld\n", (S64)S16Max);
    printf("S32Max: %lld\n", (S64)S32Max);
    printf("S64Max: %lld\n", (S64)S64Max);
    printf("S8Min : %lld\n", (S64)S8Min );
    printf("S16Min: %lld\n", (S64)S16Min);
    printf("S32Min: %lld\n", (S64)S32Min);
    printf("S64Min: %lld\n", (S64)S64Min);    

    printf("machine_epsilon_F32: %.16f\n", machine_epsilon_F32);
    printf("pi_F32: %.16f\n", pi_F32);
    printf("tau_F32: %.16f\n", tau_F32);
    printf("e_F32: %.16f\n", e_F32);
    printf("gold_big_F32: %.16f\n", gold_big_F32);
    printf("gold_small_F32: %.16f\n", gold_small_F32);

    U8 arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    U8 arr2[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    printf("arr1: ");
    for(U8 i = 0; i < ArrayCount(arr1); i++){
        printf("%d ", arr1[i]);
    }
    printf("\narr2: ");
    for(U8 i = 0; i < ArrayCount(arr2); i++){
        printf("%d ", arr2[i]);
    }
    printf("\nMemCpy arr1 -> arr2, arr2: ");
    MemoryCopy(arr2, arr1, ArrayCount(arr1));
    for(U8 i = 0; i < ArrayCount(arr2); i++){
        printf("%d ", arr2[i]);
    }
     printf("\nMemset arr2 -> 3, arr2: ");
    MemorySet(arr2, 3, ArrayCount(arr1));
    for(U8 i = 0; i < ArrayCount(arr2); i++){
        printf("%d ", arr2[i]);
    }
    printf("\narr1: ");
    for(U8 i = 0; i < ArrayCount(arr1); i++){
        printf("%d ", arr1[i]);
    }
    printf("\nMemCpyArr arr2 -> arr1, arr1: ");
    MemoryCopyArray(arr1, arr2);
    for(U8 i = 0; i < ArrayCount(arr1); i++){
        printf("%d ", arr1[i]);
    }    
   
    printf("\nZero array, arr1: ");
    MemoryZeroArray(arr1);
    for(U8 i = 0; i < ArrayCount(arr1); i++){
        printf("%d", arr1[i]);
    }

    typedef struct Test_Struct{
        U8 elmnt1;
        U8 elmnt2;
    } Test_Struct;

    Test_Struct test_struct = {82, 65};
    Test_Struct test_struct1 = {65, 82};

    printf("\nstruct elmnt1: %d, elmnt2: %d", test_struct.elmnt1, test_struct.elmnt2);
    printf("\nstruct1 elmnt1: %d, elmnt2: %d", test_struct1.elmnt1, test_struct1.elmnt2);
    MemoryCopyStruct(&test_struct1, &test_struct);
    printf("\nMemCpyStruct struct -> struct1:\nstruct elmnt1: %d, elmnt2: %d", test_struct.elmnt1, test_struct.elmnt2);
    printf("\nstruct1 elmnt1: %d, elmnt2: %d", test_struct1.elmnt1, test_struct1.elmnt2);
    MemoryZeroStruct(&test_struct);
    printf("\nMemZeroStruct struct elmnt1: %d, elmnt2: %d", test_struct.elmnt1, test_struct.elmnt2);

    return(0);
}