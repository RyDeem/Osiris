#include "../fnv.h"
#include "Visuals.h"

#include "../SDK/WeaponId.h"

#include "../SDK/ConVar.h"
#include "../SDK/Entity.h"
#include "../SDK/FrameStage.h"
#include "../SDK/GameEvent.h"
#include "../SDK/GlobalVars.h"
#include "../SDK/Input.h"
#include "../SDK/Material.h"
#include "../SDK/MaterialSystem.h"
#include "../SDK/RenderContext.h"
#include "../SDK/Surface.h"
#include "../SDK/ModelInfo.h"

#include <array>

void Visuals::ViewmodelXYZcreateMove() noexcept {
    
    return;
    
    /*
    

    //config.visuals.viewmodel_xyz_clright_default
    //if (viewmodel_x != viewmodel_x_knife) { viewmodel_offset_x->setValue(viewmodel_x_knife); };
    

    const bool cl_righthand_default = config->visuals.viewmodel_xyz_clright_default;
    const bool cl_righthandCvar     = interfaces->cvar->findVar("cl_righthand");
    //
    const float viewmodel_x_default  = config->visuals.viewmodel_x_default;
    const float viewmodel_y_default  = config->visuals.viewmodel_y_default;
    const float viewmodel_z_default  = config->visuals.viewmodel_z_default;
    //
    const float viewmodel_offset_x   = interfaces->cvar->findVar("viewmodel_offset_x")->getFloat;
    const float viewmodel_offset_y   = interfaces->cvar->findVar("viewmodel_offset_y")->getFloat;
    const float viewmodel_offset_z   = interfaces->cvar->findVar("viewmodel_offset_z")->getFloat;

    if (cl_righthandCvar == 1) { cl_righthand_default == 1; } else { cl_righthand_default == 0; };

    if (viewmodel_x_default != viewmodel_offset_x) { viewmodel_x_default->setValue(viewmodel_offset_x); };


    //if (cl_righthandCvar == 1) { cl_righthand_default->setValue(1); };

    //cl_righthand_default->setValue(config->visuals.fullBright ? 1 : 0);
    
    */

};

void Visuals::ViewmodelXYZ() noexcept {
    ////
    if (!localPlayer)   return;
    if (!localPlayer->getActiveWeapon())   return;
    //
        const auto sv_minSpecCvar = interfaces->cvar->findVar("sv_competitive_minspec");
        //
        const auto cl_righthandCvar = interfaces->cvar->findVar("cl_righthand");
        int cl_righthand_guns  = config->visuals.viewmodel_xyz_clrightguns;
        int cl_righthand_knife = config->visuals.viewmodel_xyz_clrightknife;
        //////
        if (config->visuals.viewmodel_xyz) {
            //
            const auto activeWeapon = localPlayer->getActiveWeapon()->itemDefinitionIndex2();
            const auto activeWeaponClassId = localPlayer->getActiveWeapon()->getClientClass()->classId;
            //
            const auto viewmodel_offset_x = interfaces->cvar->findVar("viewmodel_offset_x");
            const auto viewmodel_offset_y = interfaces->cvar->findVar("viewmodel_offset_y");
            const auto viewmodel_offset_z = interfaces->cvar->findVar("viewmodel_offset_z");
            //
            const auto viewmodel_x_knife = config->visuals.viewmodel_x_knife;
            const auto viewmodel_y_knife = config->visuals.viewmodel_y_knife;
            const auto viewmodel_z_knife = config->visuals.viewmodel_z_knife;
            //
            const auto viewmodel_x_guns = config->visuals.viewmodel_x_guns;
            const auto viewmodel_y_guns = config->visuals.viewmodel_y_guns;
            const auto viewmodel_z_guns = config->visuals.viewmodel_z_guns;
            //
            if (sv_minSpecCvar->getInt() == 1) { sv_minSpecCvar->setValue(0); };
            //
            if (activeWeaponClassId == ClassId::C4) {
                if (viewmodel_offset_x->getFloat() != 0.0f) { viewmodel_offset_x->setValue(0); };
                if (viewmodel_offset_y->getFloat() != 0.0f) { viewmodel_offset_y->setValue(0); };
                if (viewmodel_offset_z->getFloat() != 0.0f) { viewmodel_offset_z->setValue(0); };
            };
            //
            if (activeWeapon == WeaponId::Elite) {
                if (viewmodel_offset_x->getFloat() != 0.0f) { viewmodel_offset_x->setValue(0); };
                if (viewmodel_offset_y->getFloat() != 0.0f) { viewmodel_offset_y->setValue(0); };
                if (viewmodel_offset_z->getFloat() != 0.0f) { viewmodel_offset_z->setValue(0); };
            };
            //
            if (activeWeaponClassId == ClassId::Knife) {
                if (cl_righthandCvar->getInt() != cl_righthand_knife) { cl_righthandCvar->setValue(cl_righthand_knife); };
                if (viewmodel_offset_x->getFloat() != viewmodel_x_knife) { viewmodel_offset_x->setValue(viewmodel_x_knife); };
                if (viewmodel_offset_y->getFloat() != viewmodel_y_knife) { viewmodel_offset_y->setValue(viewmodel_y_knife); };
                if (viewmodel_offset_z->getFloat() != viewmodel_z_knife) { viewmodel_offset_z->setValue(viewmodel_z_knife); };
            };
            //
            if ( (activeWeaponClassId != ClassId::Knife) && (activeWeapon != WeaponId::Elite) && (activeWeaponClassId != ClassId::C4) ) {
                if (cl_righthandCvar->getInt() != cl_righthand_guns) { cl_righthandCvar->setValue(cl_righthand_guns); };
                if (viewmodel_offset_x->getFloat() != viewmodel_x_guns) { viewmodel_offset_x->setValue(viewmodel_x_guns); };
                if (viewmodel_offset_y->getFloat() != viewmodel_y_guns) { viewmodel_offset_y->setValue(viewmodel_y_guns); };
                if (viewmodel_offset_z->getFloat() != viewmodel_z_guns) { viewmodel_offset_z->setValue(viewmodel_z_guns); };
            };
            //
        } else { if (sv_minSpecCvar->getInt() == 0) { sv_minSpecCvar->setValue(1); }; if (cl_righthandCvar->getInt() == 0) { cl_righthandCvar->setValue(1); }; };
};

    /*

    oldxyzcode reference

    if (!localPlayer){return;}; 
    //
    int weaponType = 0;
    const auto activeWeaponClassId = localPlayer->getActiveWeapon()->getClientClass()->classId;
    const auto sv_minSpecCvar = interfaces->cvar->findVar("sv_competitive_minspec");
    const auto viewmodel_offset_x = interfaces->cvar->findVar("viewmodel_offset_x");
    const auto viewmodel_offset_y = interfaces->cvar->findVar("viewmodel_offset_y");
    const auto viewmodel_offset_z = interfaces->cvar->findVar("viewmodel_offset_z");
    const auto cl_righthand_cvar = interfaces->cvar->findVar("cl_righthand");
    //
    if (config->visuals.viewmodel_xyz && localPlayer) {
        //////
        if (activeWeaponClassId == ClassId::C4)     { weaponType = 1; };
        if (activeWeaponClassId == ClassId::Elite)  { weaponType = 2; };
        if (activeWeaponClassId == ClassId::Knife)  { weaponType = 3; };
        //
        if (sv_minSpecCvar != 0) sv_minSpecCvar->setValue(0);
        //
                 //c4
        if (weaponType == 1) {
            if (viewmodel_offset_x != 0) { viewmodel_offset_x->setValue(0); };
            if (viewmodel_offset_y != 0) { viewmodel_offset_y->setValue(0); };
            if (viewmodel_offset_z != 0) { viewmodel_offset_z->setValue(0); };
        };

                //Elite
        if (weaponType == 2) {
            if (viewmodel_offset_x != 0) { viewmodel_offset_x->setValue(0); };
            if (viewmodel_offset_y != 0) { viewmodel_offset_y->setValue(0); };
            if (viewmodel_offset_z != 0) { viewmodel_offset_z->setValue(0); };
        };

                //Knife
        if (weaponType == 3) {
            int viewmodel_x_knife = 0; int viewmodel_y_knife = 0; int viewmodel_z_knife = 0; bool righthand = 0;
            cl_righthand_cvar->setValue(righthand);
            if (righthand != config->visuals.viewmodel_xyz_clrightknife) { cl_righthand_cvar->setValue(config->visuals.viewmodel_xyz_clrightknife); };
            viewmodel_offset_x->setValue(viewmodel_x_knife);
            viewmodel_offset_y->setValue(viewmodel_y_knife);
            viewmodel_offset_z->setValue(viewmodel_z_knife);
            if (viewmodel_x_knife != config->visuals.viewmodel_x_knife) { viewmodel_offset_x->setValue(config->visuals.viewmodel_x_knife); };
            if (viewmodel_y_knife != config->visuals.viewmodel_y_knife) { viewmodel_offset_y->setValue(config->visuals.viewmodel_y_knife); };
            if (viewmodel_z_knife != config->visuals.viewmodel_z_knife) { viewmodel_offset_z->setValue(config->visuals.viewmodel_z_knife); };
        };

        ///////////////////////////////////////////////////////////////////
                //c4               //Knife              //Elite
        if ((weaponType != 1) && (weaponType != 2) && (weaponType != 3)) {
            int viewmodel_x = 0; int viewmodel_y = 0; int viewmodel_z = 0; bool minspec = 0; bool righthand = 0;
            sv_minSpecCvar->setValue(minspec); if (minspec != 0) sv_minSpecCvar->setValue(0);
            cl_righthand_cvar->setValue(righthand);
            if (righthand != config->visuals.viewmodel_xyz_clrightguns)
                cl_righthand_cvar->setValue(config->visuals.viewmodel_xyz_clrightguns);
            viewmodel_offset_x->setValue(viewmodel_x);
            viewmodel_offset_y->setValue(viewmodel_y);
            viewmodel_offset_z->setValue(viewmodel_z);
            if (viewmodel_x != config->visuals.viewmodel_x)
                viewmodel_offset_x->setValue(config->visuals.viewmodel_x);
            if (viewmodel_y != config->visuals.viewmodel_y)
                viewmodel_offset_y->setValue(config->visuals.viewmodel_y);
            if (viewmodel_z != config->visuals.viewmodel_z)
                viewmodel_offset_z->setValue(config->visuals.viewmodel_z);
        };
    };
    if (!config->visuals.viewmodel_xyz) {
        if (viewmodel_offset_x != 0) { viewmodel_offset_x->setValue(0); };
        if (viewmodel_offset_y != 0) { viewmodel_offset_y->setValue(0); };
        if (viewmodel_offset_z != 0) { viewmodel_offset_z->setValue(0); };
        bool minspec = 1; sv_minSpecCvar->setValue(minspec);
        if (minspec != 1) sv_minSpecCvar->setValue(1);
        bool righthand = 1; cl_righthand_cvar->setValue(righthand);
        if (righthand != 1) cl_righthand_cvar->setValue(1);
    };
  
  */


void Visuals::fullBright() noexcept {
    if (!localPlayer) return;
    static auto mat_fullbright = interfaces->cvar->findVar("mat_fullbright");
    mat_fullbright->setValue(config->visuals.fullBright ? 1 : 0);
}

void Visuals::playerModel(FrameStage stage) noexcept
{
    if (stage != FrameStage::RENDER_START && stage != FrameStage::RENDER_END)
        return;

    static int originalIdx = 0;

    if (!localPlayer) {
        originalIdx = 0;
        return;
    }

    constexpr auto getModel = [](int team) constexpr noexcept -> const char* {
        constexpr std::array models{
        "models/player/custom_player/legacy/ctm_fbi_variantb.mdl",
        "models/player/custom_player/legacy/ctm_fbi_variantf.mdl",
        "models/player/custom_player/legacy/ctm_fbi_variantg.mdl",
        "models/player/custom_player/legacy/ctm_fbi_varianth.mdl",
        "models/player/custom_player/legacy/ctm_sas_variantf.mdl",
        "models/player/custom_player/legacy/ctm_st6_variante.mdl",
        "models/player/custom_player/legacy/ctm_st6_variantg.mdl",
        "models/player/custom_player/legacy/ctm_st6_varianti.mdl",
        "models/player/custom_player/legacy/ctm_st6_variantk.mdl",
        "models/player/custom_player/legacy/ctm_st6_variantm.mdl",
        "models/player/custom_player/legacy/tm_balkan_variantf.mdl",
        "models/player/custom_player/legacy/tm_balkan_variantg.mdl",
        "models/player/custom_player/legacy/tm_balkan_varianth.mdl",
        "models/player/custom_player/legacy/tm_balkan_varianti.mdl",
        "models/player/custom_player/legacy/tm_balkan_variantj.mdl",
        "models/player/custom_player/legacy/tm_leet_variantf.mdl",
        "models/player/custom_player/legacy/tm_leet_variantg.mdl",
        "models/player/custom_player/legacy/tm_leet_varianth.mdl",
        "models/player/custom_player/legacy/tm_leet_varianti.mdl",
        "models/player/custom_player/legacy/tm_phoenix_variantf.mdl",
        "models/player/custom_player/legacy/tm_phoenix_variantg.mdl",
        "models/player/custom_player/legacy/tm_phoenix_varianth.mdl"
        };

        switch (team) {
        case 2: return static_cast<std::size_t>(config->visuals.playerModelT - 1) < models.size() ? models[config->visuals.playerModelT - 1] : nullptr;
        case 3: return static_cast<std::size_t>(config->visuals.playerModelCT - 1) < models.size() ? models[config->visuals.playerModelCT - 1] : nullptr;
        default: return nullptr;
        }
    };

    if (const auto model = getModel(localPlayer->team())) {
        if (stage == FrameStage::RENDER_START)
            originalIdx = localPlayer->modelIndex();

        const auto idx = stage == FrameStage::RENDER_END && originalIdx ? originalIdx : interfaces->modelInfo->getModelIndex(model);

        localPlayer->setModelIndex(idx);

        if (const auto ragdoll = interfaces->entityList->getEntityFromHandle(localPlayer->ragdoll()))
            ragdoll->setModelIndex(idx);
    }
}

void Visuals::colorWorld() noexcept
{
    if (!config->visuals.world.enabled && !config->visuals.sky.enabled)
        return;

    if (config->visuals.world.enabled)
        static auto _ = (interfaces->cvar->findVar("r_drawspecificstaticprop")->setValue(0), interfaces->cvar->findVar("cl_brushfastpath")->setValue(0), true);

    for (short h = interfaces->materialSystem->firstMaterial(); h != interfaces->materialSystem->invalidMaterial(); h = interfaces->materialSystem->nextMaterial(h)) {
        const auto mat = interfaces->materialSystem->getMaterial(h);

        if (!mat || !mat->isPrecached())
            continue;

        if (config->visuals.world.enabled && (std::strstr(mat->getTextureGroupName(), "World") || std::strstr(mat->getTextureGroupName(), "StaticProp"))) {
            if (config->visuals.world.rainbow)
                mat->colorModulate(rainbowColor(memory->globalVars->realtime, config->visuals.world.rainbowSpeed));
            else
                mat->colorModulate(config->visuals.world.color);
        } else if (config->visuals.sky.enabled && std::strstr(mat->getTextureGroupName(), "SkyBox")) {
            if (config->visuals.sky.rainbow)
                mat->colorModulate(rainbowColor(memory->globalVars->realtime, config->visuals.sky.rainbowSpeed));
            else
                mat->colorModulate(config->visuals.sky.color);
        }
    }
}

void Visuals::modifySmoke() noexcept
{
    static constexpr const char* smokeMaterials[]{
        "particle/vistasmokev1/vistasmokev1_emods",
        "particle/vistasmokev1/vistasmokev1_emods_impactdust",
        "particle/vistasmokev1/vistasmokev1_fire",
        "particle/vistasmokev1/vistasmokev1_smokegrenade",
    };

    for (const auto mat : smokeMaterials) {
        auto material = interfaces->materialSystem->findMaterial(mat);
        material->setMaterialVarFlag(MaterialVarFlag::NO_DRAW, config->visuals.noSmoke);
        material->setMaterialVarFlag(MaterialVarFlag::WIREFRAME, config->visuals.wireframeSmoke);
    }
}

void Visuals::thirdperson() noexcept
{
    static bool isInThirdperson{ true };
    static float lastTime{ 0.0f };

    if (GetAsyncKeyState(config->visuals.thirdpersonKey) && memory->globalVars->realtime - lastTime > 0.5f) {
        isInThirdperson = !isInThirdperson;
        lastTime = memory->globalVars->realtime;
    }

    if (config->visuals.thirdperson)
        if (memory->input->isCameraInThirdPerson = (!config->visuals.thirdpersonKey || isInThirdperson)
            && localPlayer && localPlayer->isAlive())
            memory->input->cameraOffset.z = static_cast<float>(config->visuals.thirdpersonDistance);
}

void Visuals::removeVisualRecoil(FrameStage stage) noexcept
{
    if (!localPlayer || !localPlayer->isAlive())
        return;

    static Vector aimPunch;
    static Vector viewPunch;

    if (stage == FrameStage::RENDER_START) {
        aimPunch = localPlayer->aimPunchAngle();
        viewPunch = localPlayer->viewPunchAngle();

        if (config->visuals.noAimPunch && !config->misc.recoilCrosshair)
            localPlayer->aimPunchAngle() = Vector{ };

        if (config->visuals.noViewPunch)
            localPlayer->viewPunchAngle() = Vector{ };

    } else if (stage == FrameStage::RENDER_END) {
        localPlayer->aimPunchAngle() = aimPunch;
        localPlayer->viewPunchAngle() = viewPunch;
    }
}

void Visuals::removeBlur() noexcept
{
    static auto blur = interfaces->materialSystem->findMaterial("dev/scope_bluroverlay");
    blur->setMaterialVarFlag(MaterialVarFlag::NO_DRAW, config->visuals.noBlur);
}

void Visuals::updateBrightness() noexcept
{
    static auto brightness = interfaces->cvar->findVar("mat_force_tonemap_scale");
    brightness->setValue(config->visuals.brightness);
}

void Visuals::removeGrass() noexcept
{
    constexpr auto getGrassMaterialName = []() constexpr noexcept -> const char* {
        switch (fnv::hashRuntime(interfaces->engine->getLevelName())) {
        case fnv::hash("dz_blacksite"): return "detail/detailsprites_survival";
        case fnv::hash("dz_sirocco"): return "detail/dust_massive_detail_sprites";
        case fnv::hash("dz_junglety"): return "detail/tropical_grass";
        default: return nullptr;
        }
    };

    if (const auto grassMaterialName = getGrassMaterialName())
        interfaces->materialSystem->findMaterial(grassMaterialName)->setMaterialVarFlag(MaterialVarFlag::NO_DRAW, config->visuals.noGrass);
}

void Visuals::remove3dSky() noexcept
{
    static auto sky = interfaces->cvar->findVar("r_3dsky");
    sky->setValue(!config->visuals.no3dSky);
}

void Visuals::removeShadows() noexcept
{
    static auto shadows = interfaces->cvar->findVar("cl_csm_enabled");
    shadows->setValue(!config->visuals.noShadows);
}

void Visuals::applyZoom(FrameStage stage) noexcept
{
    if (config->visuals.zoom && localPlayer) {
        if (stage == FrameStage::RENDER_START && (localPlayer->fov() == 90 || localPlayer->fovStart() == 90)) {
            static bool scoped{ false };

            if (GetAsyncKeyState(config->visuals.zoomKey) & 1)
                scoped = !scoped;

            if (scoped) {
                localPlayer->fov() = 40;
                localPlayer->fovStart() = 40;
            }
        }
    }
}

#define DRAW_SCREEN_EFFECT(material) \
{ \
    const auto drawFunction = memory->drawScreenEffectMaterial; \
    int w, h; \
    interfaces->surface->getScreenSize(w, h); \
    __asm { \
        __asm push h \
        __asm push w \
        __asm push 0 \
        __asm xor edx, edx \
        __asm mov ecx, material \
        __asm call drawFunction \
        __asm add esp, 12 \
    } \
}

void Visuals::applyScreenEffects() noexcept
{
    if (!config->visuals.screenEffect)
        return;

    const auto material = interfaces->materialSystem->findMaterial([] {
        constexpr std::array effects{
            "effects/dronecam",
            "effects/underwater_overlay",
            "effects/healthboost",
            "effects/dangerzone_screen"
        };

        if (config->visuals.screenEffect <= 2 || static_cast<std::size_t>(config->visuals.screenEffect - 2) >= effects.size())
            return effects[0];
        return effects[config->visuals.screenEffect - 2];
    }());

    if (config->visuals.screenEffect == 1)
        material->findVar("$c0_x")->setValue(0.0f);
    else if (config->visuals.screenEffect == 2)
        material->findVar("$c0_x")->setValue(0.1f);
    else if (config->visuals.screenEffect >= 4)
        material->findVar("$c0_x")->setValue(1.0f);

    DRAW_SCREEN_EFFECT(material)
}

void Visuals::hitEffect(GameEvent* event) noexcept
{
    if (config->visuals.hitEffect && localPlayer) {
        static float lastHitTime = 0.0f;

        if (event && interfaces->engine->getPlayerForUserID(event->getInt("attacker")) == localPlayer->index()) {
            lastHitTime = memory->globalVars->realtime;
            return;
        }

        if (lastHitTime + config->visuals.hitEffectTime >= memory->globalVars->realtime) {
            constexpr auto getEffectMaterial = [] {
                static constexpr const char* effects[]{
                "effects/dronecam",
                "effects/underwater_overlay",
                "effects/healthboost",
                "effects/dangerzone_screen"
                };

                if (config->visuals.hitEffect <= 2)
                    return effects[0];
                return effects[config->visuals.hitEffect - 2];
            };

           
            auto material = interfaces->materialSystem->findMaterial(getEffectMaterial());
            if (config->visuals.hitEffect == 1)
                material->findVar("$c0_x")->setValue(0.0f);
            else if (config->visuals.hitEffect == 2)
                material->findVar("$c0_x")->setValue(0.1f);
            else if (config->visuals.hitEffect >= 4)
                material->findVar("$c0_x")->setValue(1.0f);

            DRAW_SCREEN_EFFECT(material)
        }
    }
}

void Visuals::hitMarker(GameEvent* event) noexcept
{
    if (config->visuals.hitMarker == 0 || !localPlayer)
        return;

    static float lastHitTime = 0.0f;

    if (event && interfaces->engine->getPlayerForUserID(event->getInt("attacker")) == localPlayer->index()) {
        lastHitTime = memory->globalVars->realtime;
        return;
    }

    if (lastHitTime + config->visuals.hitMarkerTime < memory->globalVars->realtime)
        return;

    const auto [width, height] = interfaces->surface->getScreenSize();
    const auto width_mid = width / 2;
    const auto height_mid = height / 2;

    switch (config->visuals.hitMarker) {
    case 1:

        interfaces->surface->setDrawColor(255, 255, 255, 255);
        interfaces->surface->drawLine(width_mid + 10, height_mid + 10, width_mid + 4, height_mid + 4);
        interfaces->surface->drawLine(width_mid - 10, height_mid + 10, width_mid - 4, height_mid + 4);
        interfaces->surface->drawLine(width_mid + 10, height_mid - 10, width_mid + 4, height_mid - 4);
        interfaces->surface->drawLine(width_mid - 10, height_mid - 10, width_mid - 4, height_mid - 4);
        break;
    /*
    
    case 2:
        
        static auto crosshairR = interfaces->cvar->findVar("cl_crosshaircolor_r");
        static auto crosshairG = interfaces->cvar->findVar("cl_crosshaircolor_g");
        static auto crosshairB = interfaces->cvar->findVar("cl_crosshaircolor_b");

        interfaces->surface->setDrawColor(crosshairR, crosshairG, crosshairB, 255);
        interfaces->surface->drawLine(width_mid + 10, height_mid + 10, width_mid + 4, height_mid + 4);
        interfaces->surface->drawLine(width_mid - 10, height_mid + 10, width_mid - 4, height_mid + 4);
        interfaces->surface->drawLine(width_mid + 10, height_mid - 10, width_mid + 4, height_mid - 4);
        interfaces->surface->drawLine(width_mid - 10, height_mid - 10, width_mid - 4, height_mid - 4);
        break;
       
       */
    }
}

void Visuals::disablePostProcessing() noexcept
{
    if (*memory->disablePostProcessing != config->visuals.disablePostProcessing)
        *memory->disablePostProcessing = config->visuals.disablePostProcessing;
}

void Visuals::reduceFlashEffect() noexcept
{
    if (localPlayer)
        localPlayer->flashMaxAlpha() = 255.0f - config->visuals.flashReduction * 2.55f;
}

bool Visuals::removeHands(const char* modelName) noexcept
{
    return config->visuals.noHands && std::strstr(modelName, "arms") && !std::strstr(modelName, "sleeve");
}

bool Visuals::removeSleeves(const char* modelName) noexcept
{
    return config->visuals.noSleeves && std::strstr(modelName, "sleeve");
}

bool Visuals::removeWeapons(const char* modelName) noexcept
{
    return config->visuals.noWeapons && std::strstr(modelName, "models/weapons/v_")
        && !std::strstr(modelName, "arms") && !std::strstr(modelName, "tablet")
        && !std::strstr(modelName, "parachute") && !std::strstr(modelName, "fists");
}

void Visuals::skybox() noexcept
{
    constexpr std::array skyboxes{ "cs_baggage_skybox_", "cs_tibet", "embassy", "italy", "jungle", "nukeblank", "office", "sky_cs15_daylight01_hdr", "sky_cs15_daylight02_hdr", "sky_cs15_daylight03_hdr", "sky_cs15_daylight04_hdr", "sky_csgo_cloudy01", "sky_csgo_night_flat", "sky_csgo_night02", "sky_day02_05_hdr", "sky_day02_05", "sky_dust", "sky_l4d_rural02_ldr", "sky_venice", "vertigo_hdr", "vertigo", "vertigoblue_hdr", "vietnam" };

    if (static_cast<std::size_t>(config->visuals.skybox - 1) < skyboxes.size()) {
        memory->loadSky(skyboxes[config->visuals.skybox - 1]);
    } else {
        static const auto sv_skyname = interfaces->cvar->findVar("sv_skyname");
        memory->loadSky(sv_skyname->string);
    }
}
