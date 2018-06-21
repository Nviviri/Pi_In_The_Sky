#include "OpenInterfaceConfig.h"

// Command data
std::vector<uint8_t> startSafe()
{
   return {START, MODE_SAFE};
}

std::vector<uint8_t> modeSpot()
{
   return {MODE_SPOT};
}

std::vector<uint8_t> modeClean()
{
   return {MODE_CLEAN};
}

std::vector<uint8_t> reqAllData()
{
   return {ALL_SENSORDATA};
}

/// Velocities in mm/sec
std::vector<uint8_t> driveDirect(int16_t rightVelocity, int16_t leftVelocity)
{
   return {DRIVE_DIRECT_4,
           static_cast<uint8_t>(rightVelocity >> 8),
           static_cast<uint8_t>(rightVelocity & 0x00ff),
           static_cast<uint8_t>(leftVelocity >> 8),
           static_cast<uint8_t>(leftVelocity & 0x00ff)
   };
}
