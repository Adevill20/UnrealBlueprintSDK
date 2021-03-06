#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the utilities functions that supports the plugin.
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabUtilities.generated.h"

class UPlayFabJsonObject;

UCLASS()
class PLAYFAB_API UPlayFabUtilities : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    /** Setup the PlayFab settings used throughout the plugin. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Settings")
        static void setPlayFabSettings(FString GameTitleId, FString PhotonRealtimeAppId = "", FString PhotonTurnbasedAppId = "", FString PhotonChatAppId = "");

    /** Returns the error code text given the error code */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Errors")
        static FString getErrorText(int32 code);

    /** Returns the requested photon application id. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Photon | Authentication")
        static FString getPhotonAppId(bool Realtime = false, bool Chat = false, bool Turnbased = false);
};
