#include <stdio.h>
#include <memTest.h>
#include <stddef.h>

typedef unsigned char datum;



datum memTestDataBus(volatile datum* address)
{
    datum pattern;


    /*
     * Perform a walking 1's test at the given address.
     */
    for (pattern = 1; pattern != 0; pattern <<= 1)
    {
        /*
         * Write the test pattern.
         */
        *address = pattern;

        /*
         * Read it back (immediately is okay for this test).
         */
        if (*address != pattern)
        {
            return (pattern);
        }
    }

    return (0);

}
