#pragma once
#include "Observer.h"
#include "SinglePortModule.h"
#include "sleep.h"

/**
 * WhisperMagic custom module.
 *
 * Phase 1: Observe text messages, log them, hook sleep lifecycle.
 * Returns CONTINUE so TextMessageModule still handles display/BLE notify.
 *
 * Future phases: voice packet handling, power-aware queuing, custom BLE surface.
 */
class WhisperMagicModule : public SinglePortModule
{
  public:
    WhisperMagicModule();

  protected:
    virtual ProcessMessage handleReceived(const meshtastic_MeshPacket &mp) override;
    virtual bool wantPacket(const meshtastic_MeshPacket *p) override;

  private:
    // Veto deep sleep if we have a pending outbound message (returns 1 to veto)
    CallbackObserver<WhisperMagicModule, void *> preflightSleepObserver =
        CallbackObserver<WhisperMagicModule, void *>(this, &WhisperMagicModule::preflightSleepHandler);

    // Flush any transient state before deep sleep
    CallbackObserver<WhisperMagicModule, void *> deepSleepObserver =
        CallbackObserver<WhisperMagicModule, void *>(this, &WhisperMagicModule::deepSleepHandler);

    int preflightSleepHandler(void *unused);
    int deepSleepHandler(void *unused);

    bool pendingOutbound = false;
};

extern WhisperMagicModule *whisperMagicModule;
