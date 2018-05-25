#ifndef DATAFRAME_H
#define DATAFRAME_H

#include <array>

using namespace std;

class Dataframe
{
public:
   Dataframe();
   Dataframe(std::array<uint8_t, 255> &arr);

private:
   std::array<uint8_t, 255> frame;
   /*!
    * \brief checkSum is used to store the sum of the Dataframe data
    */

   void setChecksum();
   void show() const;
   bool checksumIsCorrect() const;
   int checkSum;
};

#endif // DATAFRAME_H
