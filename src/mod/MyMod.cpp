#include "MyMod.h"
#include <ll/api/memory/Hook.h>
#include <ll/api/mod/NativeMod.h>
#include <mc/world/item/Item.h>

// Khai báo cấu trúc Hook theo chuẩn LeviLamina mới
LL_TYPE_INSTANCE_HOOK(
    AllowOffhandHook,
    ll::memory::HookPriority::Normal,
    Item,
    &Item::allowOffhand, // Trình biên dịch sẽ tự động tìm đúng tên hàm
    bool
) {
    return true; // Ép game luôn cho phép cầm trên tay trái
}

// Khởi tạo mod khi game nạp vào bộ nhớ
bool MyMod::load() {
    getSelf().getLogger().info("Dang tai mod AllOffhand...");
    // Kích hoạt tính năng can thiệp (Hook)
    ll::memory::HookRegistrar<AllowOffhandHook>().hook();
    return true;
}

bool MyMod::enable() {
    getSelf().getLogger().info("Mod da hoat dong! Bay gio ban co the cam moi thu o tay trai.");
    return true;
}

bool MyMod::disable() {
    return true;
}

bool MyMod::unload() {
    return true;
}
