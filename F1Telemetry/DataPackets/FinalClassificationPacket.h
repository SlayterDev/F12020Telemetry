//
//  FinalClassificationPacket.h
//  F1Telemetry
//
//  Created by Brad Slayter on 7/20/20.
//

/**
 Frequency: Once at the end of a race
 Size: 839 bytes (Packet size updated in Beta 3)
 */

#ifndef FinalClassificationPacket_h
#define FinalClassificationPacket_h

struct FinalClassificationData
{
    uint8     m_position;              // Finishing position
    uint8     m_numLaps;               // Number of laps completed
    uint8     m_gridPosition;          // Grid position of the car
    uint8     m_points;                // Number of points scored
    uint8     m_numPitStops;           // Number of pit stops made
    uint8     m_resultStatus;          // Result status - 0 = invalid, 1 = inactive, 2 = active
                                       // 3 = finished, 4 = disqualified, 5 = not classified
                                       // 6 = retired
    float     m_bestLapTime;           // Best lap time of the session in seconds
    double    m_totalRaceTime;         // Total race time in seconds without penalties
    uint8     m_penaltiesTime;         // Total penalties accumulated in seconds
    uint8     m_numPenalties;          // Number of penalties applied to this driver
    uint8     m_numTyreStints;         // Number of tyres stints up to maximum
    uint8     m_tyreStintsActual[8];   // Actual tyres used by this driver
    uint8     m_tyreStintsVisual[8];   // Visual tyres used by this driver
};
struct PacketFinalClassificationData
{
    PacketHeader    m_header;                             // Header

    uint8                      m_numCars;                 // Number of cars in the final classification
    FinalClassificationData    m_classificationData[22];
};

#endif /* FinalClassificationPacket_h */
