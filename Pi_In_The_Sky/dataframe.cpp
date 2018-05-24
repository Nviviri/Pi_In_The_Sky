//!  Dataframe class.
/*!
The Roomba (robotic vacuum cleaner) can be connected by a serial link. Commands and
system state information can be serially communicated by a UART using a data frame
containing bytes.
This class uses the C++ STL container class std::array<uint8_t, 255> for implementing such a
data frame as a data member in the class Dataframe (composition). This data frame has a
fixed size of 255 bytes. Use for these bytes a fixed width integer type uint8_t from C++11.

The format of the data returned is:
[19][N-bytes][Packet ID 1][Packet 1 data…][Packet ID 2][Packet 2 data…][Checksum]
N-bytes is the number of bytes between the N-bytes byte and the checksum.
The checksum is a 1-byte value. It is the 8-bit complement of all of the bytes between the header and
the checksum. That is, if you add all of the bytes after the checksum, and the checksum, the low byte
of the result will be 0
*/

#include "dataframe.h"
#include <iostream>
#include <numeric>

using namespace std;

//!
//! \brief Dataframe::Dataframe
//! The default constructor of the class Dataframe initialise all data frame elements to 0
//! When constructing the object, the first data is always 19. Then it calculates checkSum and store it in the private member variable
//! Finally it performs the function to determine if the checkSum is correct. If it is the dataframe has no error
//!
Dataframe::Dataframe():
   frame{}
{
   frame[0] = 19;
   setChecksum();
   show();
   checksumIsCorrect();
}

//!
//! \brief Dataframe::Dataframe.
//! \param arr.
//! The second constructor takes an std::array argument and copy its contents to Dataframe
//! The rest constructor operations are the same as the ones in the default constructor
//!
Dataframe::Dataframe(std::array<uint8_t, 255>& arr)
   :
     frame{arr}
{
   frame[0] = 19;
   setChecksum();
   show();
   checksumIsCorrect();
}

//!
//! \brief Dataframe::setChecksum
//! This private member function calculates the checkSum value and store it in the private member variable "checkSum"
//!
void Dataframe::setChecksum()
{
   int sum = 0;
   uint32_t frameSize = frame[1] + 3;
   for(uint32_t i = 1; i < frameSize; i++)//start summing from the second byte
   {
      sum += frame[i];
   }
   //set checkSum
   checkSum = 256 - sum;
   //insert checksum into data frame
   frame[frameSize-1] = checkSum;
   std::cerr << "checkSum is " << (int)checkSum << endl;
}

//!
//! \brief Dataframe::show
//! This private member function prints the Dataframe to std::cout
//!
void Dataframe::show() const
{
   uint32_t frameSize = frame[1] + 3;
   for(uint32_t i = 0; i < frameSize; i++)
   {
      std::cout << (int)frame[i] << " ";
   }
   std::cout << endl;
}

//!
//! \brief Dataframe::checksumIsCorrect. This private member function checks whether the checkSum is correct
//! \return true, if the checkSum is correct
//! \return false, if the checkSum is incorrect
//!

bool Dataframe::checksumIsCorrect() const
{
   if((checkSum&256) == 0)
   {
      std::cout << "checkSum correct." << endl;
      return true;
   }
   else
      std::cout << "checkSum incorrect!" << endl;
   return false;
}
