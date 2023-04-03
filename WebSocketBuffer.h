#ifndef VUSER_WEBSOCKET_BUFFER_HEADER
#define VUSER_WEBSOCKET_BUFFER_HEADER

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive0[] = "{\"id\":1,\"result\":{\"status\":200}}";
long WebSocketReceiveLen0   = sizeof(WebSocketReceive0) - 1;	// (record-time: 32 bytes)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive1[] = "{\"id\":1,\"result\":{\"status\":200}}";
long WebSocketReceiveLen1   = sizeof(WebSocketReceive1) - 1;	// (record-time: 32 bytes)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive2[] = "{\"id\":2,\"result\":{\"status\":200}}";
long WebSocketReceiveLen2   = sizeof(WebSocketReceive2) - 1;	// (record-time: 32 bytes)

#endif
