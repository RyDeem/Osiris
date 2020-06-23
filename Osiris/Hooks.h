#pragma once

#include <d3d9.h>
#include <memory>
#include <type_traits>
#include <unordered_map>
#include <Windows.h>

#include "Hooks/MinHook.h"
#include "Hooks/VmtSwap.h"

struct SoundInfo;

using HookType = MinHook;

class Hooks {
public:
    Hooks(HMODULE module) noexcept;

    void install() noexcept;
    void uninstall() noexcept;

    WNDPROC originalWndProc;
    std::add_pointer_t<HRESULT __stdcall(IDirect3DDevice9*, const RECT*, const RECT*, HWND, const RGNDATA*)> originalPresent;
    std::add_pointer_t<HRESULT __stdcall(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*)> originalReset;
    std::add_pointer_t<int __fastcall(SoundInfo&)> originalDispatchSound;

    class Vmt {
    public:
        Vmt(void* const base) noexcept
        {
            init(base);
        }

        Vmt() = default;
        bool init(void* const) noexcept;
        void restore() noexcept;

        template<typename T>
        void hookAt(size_t index, T fun) const noexcept
        {
            if (index <= length)
                newVmt[index + 1] = reinterpret_cast<uintptr_t>(fun);
        }

        template<typename T, std::size_t Idx, typename ...Args>
        constexpr auto callOriginal(Args... args) const noexcept
        {
            return reinterpret_cast<T(__thiscall*)(void*, Args...)>(oldVmt[Idx])(base, args...);
        }

        template<typename T, typename ...Args>
        constexpr auto getOriginal(size_t index, Args... args) const noexcept
        {
            return reinterpret_cast<T(__thiscall*)(void*, Args...)>(oldVmt[index]);
        }
    private:
        static uintptr_t* findFreeDataPage(void* const, size_t) noexcept;
        static auto calculateLength(uintptr_t*) noexcept;
        void* base = nullptr;
        uintptr_t* oldVmt = nullptr;
        uintptr_t* newVmt = nullptr;
        size_t length = 0;
    };

    HookType bspQuery;
    HookType client;
    HookType clientMode;
    HookType engine;
    HookType gameEventManager;
    HookType modelRender;
    HookType panel;
    HookType sound;
    HookType surface;
    HookType viewRender;

    HookType svCheats;
private:
    HMODULE module;
    HWND window;
};

inline std::unique_ptr<Hooks> hooks;