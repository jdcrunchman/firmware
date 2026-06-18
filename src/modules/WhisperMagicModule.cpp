#include "WhisperMagicModule.h"
#include "MeshService.h"
#include "configuration.h"

WhisperMagicModule *whisperMagicModule;

WhisperMagicModule::WhisperMagicModule() : SinglePortModule("whispermagic", meshtastic_PortNum_TEXT_MESSAGE_APP)
{
    preflightSleepObserver.observe(&preflightSleep);
    deepSleepObserver.observe(&notifyDeepSleep);
}

ProcessMessage WhisperMagicModule::handleReceived(const meshtastic_MeshPacket &mp)
{
    auto &p = mp.decoded;
    LOG_INFO("WhisperMagic: text from=0x%08x id=0x%x len=%u", mp.from, mp.id, p.payload.size);

    // Phase 1: nothing else to do — TextMessageModule handles display + BLE notify.
    // Phase 2 hook: voice packets, power-aware store-and-forward, etc. go here.

    return ProcessMessage::CONTINUE;
}

bool WhisperMagicModule::wantPacket(const meshtastic_MeshPacket *p)
{
    return MeshService::isTextPayload(p);
}

int WhisperMagicModule::preflightSleepHandler(void *unused)
{
    if (pendingOutbound) {
        LOG_DEBUG("WhisperMagic: vetoing sleep — outbound message pending");
        return 1; // veto
    }
    return 0; // allow
}

int WhisperMagicModule::deepSleepHandler(void *unused)
{
    LOG_DEBUG("WhisperMagic: entering deep sleep, clearing state");
    pendingOutbound = false;
    return 0;
}
