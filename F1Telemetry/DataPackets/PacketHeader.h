//
//  PacketHeader.h
//  F1Telemetry
//
//  Created by Brad Slayter on 7/20/20.
//

/**
 Packet Name

 Value

 Description

 Motion
 
 0

 Contains all motion data for player’s car – only sent while player is in control

 Session

 1

 Data about the session – track, time left

 Lap Data

 2

 Data about all the lap times of cars in the session

 Event

 3

 Various notable events that happen during a session

 Participants

 4

 List of participants in the session, mostly relevant for multiplayer

 Car Setups

 5

 Packet detailing car setups for cars in the race

 Car Telemetry

 6

 Telemetry data for all cars

 Car Status

 7

 Status data for all cars such as damage

 Final Classification

 8

 Final classification confirmation at the end of a race

 Lobby Info

 9

 Information about players in a multiplayer lobby
 */

#ifndef PacketHeader_h
#define PacketHeader_h

struct PacketHeader
{
    uint16    m_packetFormat;             // 2020
    uint8     m_gameMajorVersion;         // Game major version - "X.00"
    uint8     m_gameMinorVersion;         // Game minor version - "1.XX"
    uint8     m_packetVersion;            // Version of this packet type, all start from 1
    uint8     m_packetId;                 // Identifier for the packet type, see below
    uint64    m_sessionUID;               // Unique identifier for the session
    float     m_sessionTime;              // Session timestamp
    uint32    m_frameIdentifier;          // Identifier for the frame the data was retrieved on
    uint8     m_playerCarIndex;           // Index of player's car in the array
    
   // ADDED IN BETA 2:
    uint8     m_secondaryPlayerCarIndex;  // Index of secondary player's car in the array (splitscreen)
                                          // 255 if no second player
};

#endif /* PacketHeader_h */
