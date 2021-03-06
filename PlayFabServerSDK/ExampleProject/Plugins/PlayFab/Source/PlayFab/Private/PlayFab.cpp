//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
// This cpp file is the main cpp file for the plugin. We set up globals here.
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabPrivatePCH.h"

const FString IPlayFab::PlayFabURL(TEXT(".playfabapi.com"));

class FPlayFab : public IPlayFab
{
    /** IModuleInterface implementation */
    virtual void StartupModule() override
    {
        //Force classes to be compiled on shipping build
        UPlayFabJsonObject::StaticClass();
        UPlayFabJsonValue::StaticClass();

        UPlayFabAdminAPI::StaticClass();
        UPlayFabMatchmakerAPI::StaticClass();
        UPlayFabServerAPI::StaticClass();
    }

    virtual void ShutdownModule() override
    {

    }

};

IMPLEMENT_MODULE(FPlayFab, PlayFab)

DEFINE_LOG_CATEGORY(LogPlayFab);
