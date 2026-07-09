#include "MyMod.h"
#include <ll/api/memory/Hook.h>
#include <ll/api/memory/Memory.h> // Bổ sung thư viện xử lý bộ nhớ
#include <mc/world/item/Item.h>

namespace my_mod {

// Khai báo Hook an toàn
// Thay vì truyền chuỗi, chúng ta sẽ ép kiểu chuỗi thành SymbolView để hàm resolveIdentifier hiểu được
LL_TYPE_INSTANCE_HOOK(
    AllowOffhandHook,
    ll::memory::HookPriority::Normal,
    Item,
    ll::memory::SymbolView("_ZNK4Item13allowOffhandEv"), 
    bool
) {
    return true; // Ép game luôn cho phép cầm trên tay trái
}

bool MyMod::load() {
    getSelf().getLogger().info("Dang tai mod AllOffhand...");
    ll::memory::HookRegistrar<AllowOffhandHook>().hook();
    return true;
}

bool MyMod::enable() {
    getSelf().getLogger().info("Mod da hoat dong!");
    return true;
}

bool MyMod::disable() {
    return true;
}

// Bỏ hàm unload() đi vì file MyMod.h không yêu cầu hàm này.

} // namespace my_mod
