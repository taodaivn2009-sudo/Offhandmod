#include "llapi/LoggerAPI.h"
#include "llapi/HookAPI.h"
#include "mc/world/item/Item.h"

Logger logger("AllOffhandMod");

TInstanceHook(bool, "_ZNK4Item13allowOffhandEv", Item) {
    return true;
}

void PluginInit() {
    logger.info("Mod 'All Items Offhand' da duoc tai thanh cong!");
}
