//
//  EventPacket.h
//  F1Telemetry
//
//  Created by Brad Slayter on 7/20/20.
//

/**
 Frequency: When the event occurs
 Size: 35 bytes (Packet size updated in Beta 3)
 */

/**
 Event

 Code

 Description

 Session Started

 “SSTA”

 Sent when the session starts

 Session Ended

 “SEND”

 Sent when the session ends

 Fastest Lap

 “FTLP”

 When a driver achieves the fastest lap

 Retirement

 “RTMT”

 When a driver retires

 DRS enabled

 “DRSE”

 Race control have enabled DRS

 DRS disabled

 “DRSD”

 Race control have disabled DRS

 Team mate in pits

 “TMPT”

 Your team mate has entered the pits

 Chequered flag

 “CHQF”

 The chequered flag has been waved

 Race Winner

 “RCWN”

 The race winner is announced

 Penalty Issued

 “PENA”

 A penalty has been issued – details in event

 Speed Trap Triggered

 “SPTP”

 Speed trap has been triggered by fastest speed
 */

#ifndef EventPacket_h
#define EventPacket_h

// The event details packet is different for each type of event.
// Make sure only the correct type is interpreted.
union EventDataDetails
{
    struct
    {
        uint8    vehicleIdx; // Vehicle index of car achieving fastest lap
        float    lapTime;    // Lap time is in seconds
    } FastestLap;

    struct
    {
        uint8   vehicleIdx; // Vehicle index of car retiring
    } Retirement;

    struct
    {
        uint8   vehicleIdx; // Vehicle index of team mate
    } TeamMateInPits;

    struct
    {
        uint8   vehicleIdx; // Vehicle index of the race winner
    } RaceWinner;

    struct
    {
        uint8 penaltyType;          // Penalty type – see Appendices
        uint8 infringementType;     // Infringement type – see Appendices
        uint8 vehicleIdx;           // Vehicle index of the car the penalty is applied to
        uint8 otherVehicleIdx;      // Vehicle index of the other car involved
        uint8 time;                 // Time gained, or time spent doing action in seconds
        uint8 lapNum;               // Lap the penalty occurred on
        uint8 placesGained;         // Number of places gained by this
    } Penalty;

    struct
    {
        uint8 vehicleIdx; // Vehicle index of the vehicle triggering speed trap
        float speed;      // Top speed achieved in kilometres per hour
    } SpeedTrap;
};

struct PacketEventData
{
    PacketHeader        m_header;             // Header
    
uint8               m_eventStringCode[4]; // Event string code, see below
EventDataDetails    m_eventDetails;       // Event details - should be interpreted differently
                                              // for each type
};

#endif /* EventPacket_h */
