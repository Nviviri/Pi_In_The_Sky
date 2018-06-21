#ifndef OPENINTERFACECONFIG_H
#define OPENINTERFACECONFIG_H

#include <cstdint>
#include <vector>

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
const std::vector<uint8_t> ALL_SENSORDATA {{142,0}};

// Command data
std::vector<uint8_t> startSafe();

std::vector<uint8_t> modeSpot();

std::vector<uint8_t> modeClean();

std::vector<uint8_t> reqAllData();

/// Velocities in mm/sec
std::vector<uint8_t> driveDirect(int16_t rightVelocity, int16_t leftVelocity);

#endif
