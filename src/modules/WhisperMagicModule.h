#pragma once
#include "SinglePortModule.h"

/**
 * WhisperMagic custom module.
 *
 * Phase 1: Observe text messages passing through the mesh and log them.
 * Returns CONTINUE so TextMessageModule still handles display/notifications.
 *
 * Future phases: voice packet handling, power-aware queuing, custom BLE surface.
 */
class WhisperMagicModule : public SinglePortModule
{
  public:
    WhisperMagicModule() : SinglePortModule("whispermagic", meshtastic_PortNum_TEXT_MESSAGE_APP) {}

  protected:
    virtual ProcessMessage handleReceived(const meshtastic_MeshPacket &mp) override;
    virtual bool wantPacket(const meshtastic_MeshPacket *p) override;
};

extern WhisperMagicModule *whisperMagicModule;
