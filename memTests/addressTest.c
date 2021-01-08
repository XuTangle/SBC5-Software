#include <stdio.h>
#include <memTest.h>
#include <stddef.h>



datum* memTestAddressBus(volatile datum* baseAddress, unsigned long nBytes)
{
    unsigned long addressMask = (nBytes / sizeof(datum) - 1);
    unsigned long offset;
    unsigned long testOffset;

    datum pattern = (datum)0xAAAAAAAA;
    datum antipattern = (datum)0x55555555;


    /*
     * Write the default pattern at each of the power-of-two offsets.
     */
    for (offset = 1; (offset & addressMask) != 0; offset <<= 1)
    {
        baseAddress[offset] = pattern;
    }

    /*
     * Check for address bits stuck high.
     */
    testOffset = 0;
    baseAddress[testOffset] = antipattern;

    for (offset = 1; (offset & addressMask) != 0; offset <<= 1)
    {
        if (baseAddress[offset] != pattern)
        {
            return ((datum*)&baseAddress[offset]);
        }
    }

    baseAddress[testOffset] = pattern;

    /*
     * Check for address bits stuck low or shorted.
     */
    for (testOffset = 1; (testOffset & addressMask) != 0; testOffset <<= 1)
    {
        baseAddress[testOffset] = antipattern;

        if (baseAddress[0] != pattern)
        {
            return ((datum*)&baseAddress[testOffset]);
        }

        for (offset = 1; (offset & addressMask) != 0; offset <<= 1)
        {
            if ((baseAddress[offset] != pattern) && (offset != testOffset))
            {
                return ((datum*)&baseAddress[testOffset]);
            }
        }

        baseAddress[testOffset] = pattern;
    }

    return (NULL);

}

