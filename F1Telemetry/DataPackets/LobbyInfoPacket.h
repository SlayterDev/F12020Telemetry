//
//  LobbyInfoPacket.h
//  F1Telemetry
//
//  Created by Brad Slayter on 7/20/20.
//

/**
 Frequency: Two every second when in the lobby
 Size: 1169 bytes (Packet size updated in Beta 3)
 */

#ifndef LobbyInfoPacket_h
#define LobbyInfoPacket_h

struct LobbyInfoData
{
    uint8     m_aiControlled;            // Whether the vehicle is AI (1) or Human (0) controlled
    uint8     m_teamId;                  // Team id - see appendix (255 if no team currently selected)
    uint8     m_nationality;             // Nationality of the driver
    char      m_name[48];                // Name of participant in UTF-8 format – null terminated
                                         // Will be truncated with ... (U+2026) if too long
    uint8     m_readyStatus;             // 0 = not ready, 1 = ready, 2 = spectating
};

struct PacketLobbyInfoData
{
    PacketHeader    m_header;                       // Header

    // Packet specific data
    uint8               m_numPlayers;               // Number of players in the lobby data
    LobbyInfoData       m_lobbyPlayers[22];
};

#endif /* LobbyInfoPacket_h */
