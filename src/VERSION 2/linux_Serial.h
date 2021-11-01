
//
// Created by Jacso on 9/29/2021.
//

#ifndef OPEN_BRIDGE_SERIAL_H
#define OPEN_BRIDGE_SERIAL_H
#include <string>
#include <stdio.h>
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h>
class Serial{
private:

public:
    HANDLE hComm;
    DCB dcbSerialParams;
    Serial(std::string com_port);
    int setupParams(int baudRate, int byteSize, int stopBytes, int parity);
    int sendData(std::string data_string);
    int close_handle();

};


#endif //OPEN_BRIDGE_SERIAL_H

// Resources:
// https://stackoverflow.com/questions/1105769/multiplatform-c-project-inclusion-of-platform-specific-sources
// https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/
// https://www.google.com/search?q=cmake+compile+different+cpp+file+depending+on+OS&rlz=1C1ONGR_enUS931US931&oq=cmake+compile+different+cpp+file+depending+on+OS&aqs=chrome..69i57j33i160l2.21903j1j7&sourceid=chrome&ie=UTF-8