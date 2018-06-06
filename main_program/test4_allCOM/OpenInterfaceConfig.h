#ifndef OPENINTERFACECONFIG_H
#define OPENINTERFACECONFIG_H

#include <cstdint>

enum class Baud: unsigned int {
   ROOMBA_SLOW = 19200,
   ROOMBA_DEFAULT = 115200
};

// Get started
const uint8_t START{128};
const uint8_t BAUD_1{129};

// Mode commands
const uint8_t MODE_SAFE{131};
const uint8_t MODE_FULL{132};
const uint8_t MODE_SPOT{134};
const uint8_t MODE_CLEAN{135};

// Commands
const uint8_t DRIVE_DIRECT_4{145};

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

#endif
