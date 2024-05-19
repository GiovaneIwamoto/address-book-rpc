CC = gcc

CFLAGS = -I/usr/include/tirpc -ltirpc

SERVER_SRC = adb_sif.c adb_svc.c adb_server.c adb_xdr.c
CLIENT_SRC = adb_cif.c adb_clnt.c adb_client.c adb_xdr.c

SERVER_BIN = server
CLIENT_BIN = client

all: $(SERVER_BIN) $(CLIENT_BIN)

$(SERVER_BIN): $(SERVER_SRC)
	$(CC) -o $@ $^ $(CFLAGS)

$(CLIENT_BIN): $(CLIENT_SRC)
	$(CC) -o $@ $^ $(CFLAGS) -fcommon

clean:
	rm -f $(SERVER_BIN) $(CLIENT_BIN)

.PHONY: all clean