//
//  CarStatusPacket.h
//  F1Telemetry
//
//  Created by Brad Slayter on 7/20/20.
//

/**
 Frequency: Rate as specified in menus
 Size: 1344 bytes (Packet updated in Beta 3)
 */

#ifndef CarStatusPacket_h
#define CarStatusPacket_h

struct CarStatusData
{
    uint8       m_tractionControl;          // 0 (off) - 2 (high)
    uint8       m_antiLockBrakes;           // 0 (off) - 1 (on)
    uint8       m_fuelMix;                  // Fuel mix - 0 = lean, 1 = standard, 2 = rich, 3 = max
    uint8       m_frontBrakeBias;           // Front brake bias (percentage)
    uint8       m_pitLimiterStatus;         // Pit limiter status - 0 = off, 1 = on
    float       m_fuelInTank;               // Current fuel mass
    float       m_fuelCapacity;             // Fuel capacity
    float       m_fuelRemainingLaps;        // Fuel remaining in terms of laps (value on MFD)
    uint16      m_maxRPM;                   // Cars max RPM, point of rev limiter
    uint16      m_idleRPM;                  // Cars idle RPM
    uint8       m_maxGears;                 // Maximum number of gears
    uint8       m_drsAllowed;               // 0 = not allowed, 1 = allowed, -1 = unknown
    

    // Added in Beta3:
    uint16      m_drsActivationDistance;    // 0 = DRS not available, non-zero - DRS will be available
                                            // in [X] metres
    
    uint8       m_tyresWear[4];             // Tyre wear percentage
    uint8       m_actualTyreCompound;        // F1 Modern - 16 = C5, 17 = C4, 18 = C3, 19 = C2, 20 = C1
                           // 7 = inter, 8 = wet
                           // F1 Classic - 9 = dry, 10 = wet
                           // F2 – 11 = super soft, 12 = soft, 13 = medium, 14 = hard
                           // 15 = wet
   uint8       m_visualTyreCompound;        // F1 visual (can be different from actual compound)
                                            // 16 = soft, 17 = medium, 18 = hard, 7 = inter, 8 = wet
                                            // F1 Classic – same as above
                                            // F2 – same as above
    uint8       m_tyresAgeLaps;             // Age in laps of the current set of tyres
    uint8       m_tyresDamage[4];           // Tyre damage (percentage)
    uint8       m_frontLeftWingDamage;      // Front left wing damage (percentage)
    uint8       m_frontRightWingDamage;     // Front right wing damage (percentage)
    uint8       m_rearWingDamage;           // Rear wing damage (percentage)
    
    // Added Beta 3:
    uint8       m_drsFault;                 // Indicator for DRS fault, 0 = OK, 1 = fault
    
    uint8       m_engineDamage;             // Engine damage (percentage)
    uint8       m_gearBoxDamage;            // Gear box damage (percentage)
    int8        m_vehicleFiaFlags;          // -1 = invalid/unknown, 0 = none, 1 = green
                                            // 2 = blue, 3 = yellow, 4 = red
    float       m_ersStoreEnergy;           // ERS energy store in Joules
    uint8       m_ersDeployMode;            // ERS deployment mode, 0 = none, 1 = medium
                                            // 2 = overtake, 3 = hotlap
    float       m_ersHarvestedThisLapMGUK;  // ERS energy harvested this lap by MGU-K
    float       m_ersHarvestedThisLapMGUH;  // ERS energy harvested this lap by MGU-H
    float       m_ersDeployedThisLap;       // ERS energy deployed this lap
};

struct PacketCarStatusData
{
    PacketHeader        m_header;           // Header

    CarStatusData    m_carStatusData[22];
};

#endif /* CarStatusPacket_h */
