//
//  CarSetupsPacket.h
//  F1Telemetry
//
//  Created by Brad Slayter on 7/20/20.
//

/**
 Frequency: 2 per second
 Size: 1102 bytes (Packet size updated in Beta 3)
 */

#ifndef CarSetupsPacket_h
#define CarSetupsPacket_h

struct CarSetupData
{
    uint8     m_frontWing;                // Front wing aero
    uint8     m_rearWing;                 // Rear wing aero
    uint8     m_onThrottle;               // Differential adjustment on throttle (percentage)
    uint8     m_offThrottle;              // Differential adjustment off throttle (percentage)
    float     m_frontCamber;              // Front camber angle (suspension geometry)
    float     m_rearCamber;               // Rear camber angle (suspension geometry)
    float     m_frontToe;                 // Front toe angle (suspension geometry)
    float     m_rearToe;                  // Rear toe angle (suspension geometry)
    uint8     m_frontSuspension;          // Front suspension
    uint8     m_rearSuspension;           // Rear suspension
    uint8     m_frontAntiRollBar;         // Front anti-roll bar
    uint8     m_rearAntiRollBar;          // Front anti-roll bar
    uint8     m_frontSuspensionHeight;    // Front ride height
    uint8     m_rearSuspensionHeight;     // Rear ride height
    uint8     m_brakePressure;            // Brake pressure (percentage)
    uint8     m_brakeBias;                // Brake bias (percentage)
    float     m_rearLeftTyrePressure;     // Rear left tyre pressure (PSI)
    float     m_rearRightTyrePressure;    // Rear right tyre pressure (PSI)
    float     m_frontLeftTyrePressure;    // Front left tyre pressure (PSI)
    float     m_frontRightTyrePressure;   // Front right tyre pressure (PSI)
    uint8     m_ballast;                  // Ballast
    float     m_fuelLoad;                 // Fuel load
};

struct PacketCarSetupData
{
    PacketHeader    m_header;            // Header

    CarSetupData    m_carSetups[22];
};

#endif /* CarSetupsPacket_h */
