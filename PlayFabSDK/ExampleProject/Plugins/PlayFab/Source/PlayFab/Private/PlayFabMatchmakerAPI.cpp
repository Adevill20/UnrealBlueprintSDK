//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Matchmaker
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabPrivatePCH.h"
#include "PlayFabEnums.h"
#include "PlayFabMatchmakerAPI.h"

UPlayFabMatchmakerAPI::UPlayFabMatchmakerAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

void UPlayFabMatchmakerAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabMatchmakerAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabMatchmakerAPI::PercentEncode(const FString& Text)
{
    FString OutText = Text;

    OutText = OutText.Replace(TEXT("!"), TEXT("%21"));
    OutText = OutText.Replace(TEXT("\""), TEXT("%22"));
    OutText = OutText.Replace(TEXT("#"), TEXT("%23"));
    OutText = OutText.Replace(TEXT("$"), TEXT("%24"));
    //OutText = OutText.Replace(TEXT("&"), TEXT("%26"));
    OutText = OutText.Replace(TEXT("'"), TEXT("%27"));
    OutText = OutText.Replace(TEXT("("), TEXT("%28"));
    OutText = OutText.Replace(TEXT(")"), TEXT("%29"));
    OutText = OutText.Replace(TEXT("*"), TEXT("%2A"));
    OutText = OutText.Replace(TEXT("+"), TEXT("%2B"));
    OutText = OutText.Replace(TEXT(","), TEXT("%2C"));
    //OutText = OutText.Replace(TEXT("/"), TEXT("%2F"));
    OutText = OutText.Replace(TEXT(":"), TEXT("%3A"));
    OutText = OutText.Replace(TEXT(";"), TEXT("%3B"));
    OutText = OutText.Replace(TEXT("="), TEXT("%3D"));
    //OutText = OutText.Replace(TEXT("?"), TEXT("%3F"));
    OutText = OutText.Replace(TEXT("@"), TEXT("%40"));
    OutText = OutText.Replace(TEXT("["), TEXT("%5B"));
    OutText = OutText.Replace(TEXT("]"), TEXT("%5D"));
    OutText = OutText.Replace(TEXT("{"), TEXT("%7B"));
    OutText = OutText.Replace(TEXT("}"), TEXT("%7D"));

    return OutText;
}

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Matchmaker API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Matchmaking
//////////////////////////////////////////////////////
/** Validates a user with the PlayFab service */
UPlayFabMatchmakerAPI* UPlayFabMatchmakerAPI::AuthUser(FMatchmakerAuthUserRequest request,
    FDelegateOnSuccessAuthUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMatchmakerAPI* manager = NewObject<UPlayFabMatchmakerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAuthUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMatchmakerAPI::HelperAuthUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Matchmaker/AuthUser";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.AuthorizationTicket.IsEmpty() || request.AuthorizationTicket == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AuthorizationTicket"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AuthorizationTicket"), request.AuthorizationTicket);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMatchmakerRequestCompleted
void UPlayFabMatchmakerAPI::HelperAuthUser(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessAuthUser.IsBound())
    {
        FMatchmakerAuthUserResponse result = UPlayFabMatchmakerModelDecoder::decodeAuthUserResponseResponse(response.responseData);
        OnSuccessAuthUser.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Informs the PlayFab game server hosting service that the indicated user has joined the Game Server Instance specified */
UPlayFabMatchmakerAPI* UPlayFabMatchmakerAPI::PlayerJoined(FMatchmakerPlayerJoinedRequest request,
    FDelegateOnSuccessPlayerJoined onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMatchmakerAPI* manager = NewObject<UPlayFabMatchmakerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessPlayerJoined = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMatchmakerAPI::HelperPlayerJoined);

    // Setup the request
    manager->PlayFabRequestURL = "/Matchmaker/PlayerJoined";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.LobbyId.IsEmpty() || request.LobbyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("LobbyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("LobbyId"), request.LobbyId);
    }
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMatchmakerRequestCompleted
void UPlayFabMatchmakerAPI::HelperPlayerJoined(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessPlayerJoined.IsBound())
    {
        FMatchmakerPlayerJoinedResponse result = UPlayFabMatchmakerModelDecoder::decodePlayerJoinedResponseResponse(response.responseData);
        OnSuccessPlayerJoined.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Informs the PlayFab game server hosting service that the indicated user has left the Game Server Instance specified */
UPlayFabMatchmakerAPI* UPlayFabMatchmakerAPI::PlayerLeft(FMatchmakerPlayerLeftRequest request,
    FDelegateOnSuccessPlayerLeft onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMatchmakerAPI* manager = NewObject<UPlayFabMatchmakerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessPlayerLeft = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMatchmakerAPI::HelperPlayerLeft);

    // Setup the request
    manager->PlayFabRequestURL = "/Matchmaker/PlayerLeft";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.LobbyId.IsEmpty() || request.LobbyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("LobbyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("LobbyId"), request.LobbyId);
    }
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMatchmakerRequestCompleted
void UPlayFabMatchmakerAPI::HelperPlayerLeft(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessPlayerLeft.IsBound())
    {
        FMatchmakerPlayerLeftResponse result = UPlayFabMatchmakerModelDecoder::decodePlayerLeftResponseResponse(response.responseData);
        OnSuccessPlayerLeft.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Instructs the PlayFab game server hosting service to instantiate a new Game Server Instance */
UPlayFabMatchmakerAPI* UPlayFabMatchmakerAPI::StartGame(FMatchmakerStartGameRequest request,
    FDelegateOnSuccessStartGame onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMatchmakerAPI* manager = NewObject<UPlayFabMatchmakerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessStartGame = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMatchmakerAPI::HelperStartGame);

    // Setup the request
    manager->PlayFabRequestURL = "/Matchmaker/StartGame";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Build.IsEmpty() || request.Build == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Build"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Build"), request.Build);
    }
    if (request.CustomCommandLineData.IsEmpty() || request.CustomCommandLineData == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CustomCommandLineData"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CustomCommandLineData"), request.CustomCommandLineData);
    }
    if (request.ExternalMatchmakerEventEndpoint.IsEmpty() || request.ExternalMatchmakerEventEndpoint == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ExternalMatchmakerEventEndpoint"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ExternalMatchmakerEventEndpoint"), request.ExternalMatchmakerEventEndpoint);
    }
    if (request.GameMode.IsEmpty() || request.GameMode == "") {
        OutRestJsonObj->SetFieldNull(TEXT("GameMode"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("GameMode"), request.GameMode);
    }
    FString temp_Region;
    if (GetEnumValueToString<ERegion>(TEXT("ERegion"), request.Region, temp_Region))
        OutRestJsonObj->SetStringField(TEXT("Region"), temp_Region);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMatchmakerRequestCompleted
void UPlayFabMatchmakerAPI::HelperStartGame(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessStartGame.IsBound())
    {
        FMatchmakerStartGameResponse result = UPlayFabMatchmakerModelDecoder::decodeStartGameResponseResponse(response.responseData);
        OnSuccessStartGame.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the relevant details for a specified user, which the external match-making service can then use to compute effective matches */
UPlayFabMatchmakerAPI* UPlayFabMatchmakerAPI::UserInfo(FMatchmakerUserInfoRequest request,
    FDelegateOnSuccessUserInfo onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMatchmakerAPI* manager = NewObject<UPlayFabMatchmakerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUserInfo = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMatchmakerAPI::HelperUserInfo);

    // Setup the request
    manager->PlayFabRequestURL = "/Matchmaker/UserInfo";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    OutRestJsonObj->SetNumberField(TEXT("MinCatalogVersion"), request.MinCatalogVersion);
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMatchmakerRequestCompleted
void UPlayFabMatchmakerAPI::HelperUserInfo(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUserInfo.IsBound())
    {
        FMatchmakerUserInfoResponse result = UPlayFabMatchmakerModelDecoder::decodeUserInfoResponseResponse(response.responseData);
        OnSuccessUserInfo.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}



void UPlayFabMatchmakerAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    // Be sure that we have no data from previous response
    ResetResponseData();

    if (!IsValidLowLevel())
    {
        UE_LOG(LogPlayFab, Error, TEXT("The request object is invalid during OnProcessRequestComplete."));
        return;
    }
    if (!OnPlayFabResponse.IsBound())
    {
        UE_LOG(LogPlayFab, Error, TEXT("OnPlayFabResponse has come un-bound during OnProcessRequestComplete."));
        return;
    }

    FPlayFabBaseModel myResponse;

    // Check we have result to process further
    if (!bWasSuccessful)
    {
        UE_LOG(LogPlayFab, Error, TEXT("Request failed: %s"), *Request->GetURL());

        // Broadcast the result event
        myResponse.responseError.hasError = true;
        myResponse.responseError.ErrorCode = 503;
        myResponse.responseError.ErrorName = "Unable to contact server";
        myResponse.responseError.ErrorMessage = "Unable to contact server";

        OnPlayFabResponse.Broadcast(myResponse, mCustomData, false);

        return;
    }

    // Save response data as a string
    ResponseContent = Response->GetContentAsString();

    // Save response code as int32
    ResponseCode = Response->GetResponseCode();

    // Try to deserialize data to JSON
    TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(ResponseContent);
    FJsonSerializer::Deserialize(JsonReader, ResponseJsonObj->GetRootObject());

    // Decide whether the request was successful
    bIsValidJsonResponse = bWasSuccessful && ResponseJsonObj->GetRootObject().IsValid();

    // Log errors
    if (!bIsValidJsonResponse)
        UE_LOG(LogPlayFab, Warning, TEXT("JSON could not be decoded!"));

    // Log response state
    UE_LOG(LogPlayFab, Log, TEXT("Response : %s"), *ResponseContent);

    myResponse.responseError.decodeError(ResponseJsonObj);
    myResponse.responseData = ResponseJsonObj;
    IPlayFab* pfSettings = &(IPlayFab::Get());

    // Broadcast the result event
    OnPlayFabResponse.Broadcast(myResponse, mCustomData, myResponse.responseError.hasError);
    pfSettings->ModifyPendingCallCount(-1);
}

void UPlayFabMatchmakerAPI::Activate()
{
    IPlayFab* pfSettings = &(IPlayFab::Get());

    FString RequestUrl;
    RequestUrl = TEXT("https://") + pfSettings->getGameTitleId() + IPlayFab::PlayFabURL + PlayFabRequestURL;

    TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->SetURL(RequestUrl);
    HttpRequest->SetVerb("POST");

    // Headers
    if (useSessionTicket)
        HttpRequest->SetHeader("X-Authentication", pfSettings->getSessionTicket());
    if (useSecretKey)
        HttpRequest->SetHeader("X-SecretKey", pfSettings->getSecretApiKey());
    HttpRequest->SetHeader("Content-Type", "application/json");
    HttpRequest->SetHeader(TEXT("X-PlayFabSDK"), pfSettings->VersionString);
    HttpRequest->SetHeader("X-ReportErrorAsSuccess", "true"); // FHttpResponsePtr doesn't provide sufficient information when an error code is returned
    for (TMap<FString, FString>::TConstIterator It(RequestHeaders); It; ++It)
        HttpRequest->SetHeader(It.Key(), It.Value());

    // Serialize data to json string
    FString OutputString;
    TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
    FJsonSerializer::Serialize(RequestJsonObj->GetRootObject().ToSharedRef(), Writer);

    // Set Json content
    HttpRequest->SetContentAsString(OutputString);

    UE_LOG(LogPlayFab, Log, TEXT("Request: %s"), *OutputString);

    // Bind event
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabMatchmakerAPI::OnProcessRequestComplete);

    // Execute the request
    pfSettings->ModifyPendingCallCount(1);
    HttpRequest->ProcessRequest();
}

void UPlayFabMatchmakerAPI::ResetResponseData()
{
    if (ResponseJsonObj != nullptr)
        ResponseJsonObj->Reset();
    else
        ResponseJsonObj = NewObject<UPlayFabJsonObject>();
    bIsValidJsonResponse = false;
}
