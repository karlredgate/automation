
mtype = { /* Ghost stages */
    CONTENT_POLICY,
    CLIENT_REQUEST, CLIENT_REQUEST_BODY,
    IPA_RESPONSE, CACHE_HIT,
    FORWARD_START, FORWARD_REQUEST, FORWARD_RESPONSE,
    FORWARD_INSUFFICIENT_RESPONSE,
    CLIENT_RESPONSE, CLIENT_DONE,
};

mtype = { /* header names */
    HOST_HDR,
    TRANSFER_ENCODING,
    CONTENT_TYPE, USER_AGENT,
};

mtype = { /* header actions */
    HDR_ADD, HDR_DEL,
};


typedef RequestState {
    int stage;
    bit content_policy_enabled;
};

/* where to read data from */

typedef HeaderChange {
    int header;
    int action;
};
chan HeaderChanges = [0] of { HeaderChange };

active proctype CollectHeaderChanges() {
    HeaderChange msg;
    do
    :: HeaderChanges ? msg -> printf( "recv header change\n" )
    :: timeout -> printf( "timeout waiting for header\n" ); break;
    od
}

proctype AddHeader( int headerID ) {
    HeaderChange msg;
    msg.header = headerID;
    msg.action = HDR_ADD;
    HeaderChanges ! msg;
}

inline ReportStage( state ) {
    mtype stage = state.stage;
    if
    :: stage == CONTENT_POLICY      -> printf( "stage: content-policy\n" );
    :: stage == CLIENT_REQUEST      -> printf( "stage: client-request\n" );
    :: stage == CLIENT_REQUEST_BODY -> printf( "stage: client-request-body\n" );
    :: stage == IPA_RESPONSE        -> printf( "stage: ipa-response\n" );
    :: stage == CACHE_HIT           -> printf( "stage: cache-hit\n" );
    :: stage == FORWARD_START       -> printf( "stage: forward-start\n" );
    :: stage == FORWARD_REQUEST     -> printf( "stage: forward-request\n" );
    :: stage == FORWARD_RESPONSE    -> printf( "stage: forward-response\n" );
    :: stage == FORWARD_INSUFFICIENT_RESPONSE ->
                                       printf( "stage: forward-insufficient-response\n" );
    :: stage == CLIENT_RESPONSE     -> printf( "stage: client-response\n" );
    :: stage == CLIENT_DONE         -> printf( "stage: client-done\n" );
    fi
}

proctype MetadataForest( RequestState state ) {
    ReportStage( state );
}

/*
 * running the metadata here should leave content policy
 * disabled normally - and not run anything - but if a
 * tag enabled content-poloicy - then run it
 */
inline contentPolicyStage( state ) {
    state.stage = CONTENT_POLICY;
    run MetadataForest(state);
}

inline clientRequestStage( state ) {
    state.stage = CLIENT_REQUEST;
    run MetadataForest(state);
}

inline clientRequestBodyStage( state ) {
    state.stage = CLIENT_REQUEST_BODY;
    run MetadataForest(state);
}

inline ipaResponseStage( state ) {
    state.stage = IPA_RESPONSE;
    run MetadataForest(state);
}

/* only run this if there is a cache hit */
inline cacheHitStage( state ) {
    state.stage = CACHE_HIT;
    run MetadataForest(state);
}

inline forwardStartStage( state ) {
    state.stage = FORWARD_START;
    run MetadataForest(state);
}

inline forwardRequestStage( state ) {
    state.stage = FORWARD_REQUEST;
    run MetadataForest(state);
}

inline forwardResponseStage( state ) {
    state.stage = FORWARD_RESPONSE;
    run MetadataForest(state);
}

inline forwardInsufficientResponseStage( state ) {
    state.stage = FORWARD_INSUFFICIENT_RESPONSE;
    run MetadataForest(state);
}

inline clientResponseStage( state ) {
    state.stage = CLIENT_RESPONSE;
    run MetadataForest(state);
}

inline clientDoneStage( state ) {
    state.stage = CLIENT_DONE;
    run MetadataForest(state);
}

inline postProcess( state ) {
    skip;
    /* send DLR */
}

proctype ProcessRequest() {
    RequestState state;
                  contentPolicyStage( state );
                  clientRequestStage( state );
              clientRequestBodyStage( state );
                    ipaResponseStage( state );
                       cacheHitStage( state );
                   forwardStartStage( state );
                 forwardRequestStage( state );
                forwardResponseStage( state );
    forwardInsufficientResponseStage( state );
                 clientResponseStage( state );
                     clientDoneStage( state );
                         postProcess( state );
}

init {
    skip;
    run ProcessRequest();

    run AddHeader( USER_AGENT );
}

/* vim: set autoindent expandtab sw=4 : */
