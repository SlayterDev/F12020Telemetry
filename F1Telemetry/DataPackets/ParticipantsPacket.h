//
//  ParticipantsPacket.h
//  F1Telemetry
//
//  Created by Brad Slayter on 7/20/20.
//

/**
 Frequency: Every 5 seconds
 Size: 1213 bytes (Packet size updated in Beta 3)
 */

#ifndef ParticipantsPacket_h
#define ParticipantsPacket_h

struct ParticipantData
{
    uint8      m_aiControlled;           // Whether the vehicle is AI (1) or Human (0) controlled
    uint8      m_driverId;               // Driver id - see appendix
    uint8      m_teamId;                 // Team id - see appendix
    uint8      m_raceNumber;             // Race number of the car
    uint8      m_nationality;            // Nationality of the driver
    char       m_name[48];               // Name of participant in UTF-8 format – null terminated
                                         // Will be truncated with … (U+2026) if too long
    uint8      m_yourTelemetry;          // The player's UDP setting, 0 = restricted, 1 = public
};

struct PacketParticipantsData
{
    PacketHeader    m_header;           // Header

    uint8           m_numActiveCars;    // Number of active cars in the data – should match number of
                                        // cars on HUD
    ParticipantData m_participants[22];
};

#endif /* ParticipantsPacket_h */
