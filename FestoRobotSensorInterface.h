/**
 * @file FestoRobotSensorInterface.h
 * @brief Header file for the FestoRobotSensorInterface class.
 *
 * This file defines the FestoRobotSensorInterface class, which provides an implementation
 * of the SensorInterface using FestoRobotAPI. It serves as a base class for specific
 * sensor implementations.
 */

#pragma once
#ifndef FESTOROBOTSENSORINTERFACE_H
#define FESTOROBOTSENSORINTERFACE_H

#include "FestoRobotAPI.h"
#include "SensorInterface.h"

 /**
  * @class FestoRobotSensorInterface
  * @brief Provides a sensor interface implementation using FestoRobotAPI.
  *
  * The FestoRobotSensorInterface class acts as an abstract base class for sensors that
  * interact with the FestoRobotAPI. It provides constructors and a destructor for
  * managing the API instance.
  */
class FestoRobotSensorInterface : public SensorInterface {
protected:
    FestoRobotAPI* robotAPI; /**< Pointer to the FestoRobotAPI instance. */

public:
    /**
     * @brief Default constructor for FestoRobotSensorInterface.
     */
    FestoRobotSensorInterface() {}

    /**
     * @brief Constructor with FestoRobotAPI instance.
     * @param api Pointer to an instance of FestoRobotAPI.
     */
    FestoRobotSensorInterface(FestoRobotAPI* api) : robotAPI(api) {}

    /**
     * @brief Destructor for FestoRobotSensorInterface.
     */
    virtual ~FestoRobotSensorInterface() {}
};

#endif // FESTOROBOTSENSORINTERFACE_H
