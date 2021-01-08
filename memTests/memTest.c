#include <memTest.h>
#include <stddef.h>

int main()
{
#define BASE_ADDRESS  (volatile datum *) 0x00000000
#define NUM_BYTES     (64 * 1024)

    if ((memTestDataBus(BASE_ADDRESS) != 0) ||
        (memTestAddressBus(BASE_ADDRESS, NUM_BYTES) != NULL) ||
        (memTestDevice(BASE_ADDRESS, NUM_BYTES) != NULL))
    {
        return (-1);
    }
    else
    {
        return (0);
    }
}
