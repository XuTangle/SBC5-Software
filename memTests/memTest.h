typedef unsigned char datum;

datum memTestDataBus(volatile datum* address);

datum* memTestAddressBus(volatile datum* baseAddress, unsigned long nBytes);

datum* memTestDevice(volatile datum* baseAddress, unsigned long nBytes);

