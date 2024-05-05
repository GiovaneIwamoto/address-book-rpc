# ADDRESS BOOK RPC

### **OVERVIEW**

This project defines an RPC interface for an address book program and implements both the server and client components essential for its functionality. The RPC interface serves as a communication bridge between the client and server, enabling clients to interact with a basic address book stored on the server. Key functionalities encompass inserting, removing, listing, and searching contacts.

### **INSTALLATION GUIDE**

```
RPC generator:
$ rpcgen adb.x
```

### **CLEAR RPC STUBS**

```
Python script:
$ python3 clear_rpc.py
```

### **PORTMAP AND RPCBIND**

```
Portmap error init service:
$ service portmap start
  
Install Portmap:
$ sudo apt install portmap

Linux and Debian-based distros use Rpcbind:
$ sudo systemctl start rpcbind
```