#include "MyMod.h"
#include <ll/api/memory/Hook.h>
#include <mc/world/item/Item.h>

// Bắt buộc phải có namespace này để kết nối với MyMod.h
namespace my_mod {

// Khai báo Hook bằng Symbol (tên mã hóa) thay vì trỏ hàm, giúp bỏ qua lỗi thiếu header
LL_TYPE_INSTANCE_HOOK(
    AllowOffhandHook,
    ll::memory::HookPriority::Normal,
    Item,
    "_ZNK4Item13allowOffhandEv", 
    bool
) {
    return true; // Ép game luôn cho phép cầm trên tay trái
}

bool MyMod::load() {
    getSelf().getLogger().info("Dang tai mod AllOffhand...");
    // Kích hoạt tính năng can thiệp (Hook)
    ll::memory::HookRegistrar<AllowOffhandHook>().hook();
    return true;
}

bool MyMod::enable() {
    getSelf().getLogger().info("Mod da hoat dong! Ban co the cam moi thu o tay trai.");
    return true;
}

bool MyMod::disable() {
    return true;
}

bool MyMod::unload() {
    return true;
}

} // Kết thúc namespace my_mod
