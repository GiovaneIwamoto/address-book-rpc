# ADDRESS BOOK RPC

### **OVERVIEW**

This project defines an RPC interface for an address book program and implements both the server and client components essential for its functionality. The RPC interface serves as a communication bridge between the client and server, enabling clients to interact with a basic address book stored on the server. Key functionalities encompass inserting, removing, listing, and searching contacts.

### **INSTALLATION GUIDE**

```
RPC generator:
$ rpcgen adb.x
```

```
Compile server:

$ gcc -o server adb_sif.c adb_svc.c adb_server.c adb_xdr.c -I/usr/include/tirpc -ltirpc
```

```
Compile client:

$ gcc -o client adb_cif.c adb_clnt.c adb_client.c adb_xdr.c -I/usr/include/tirpc -ltirpc -fcommon
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

### **AUTHOR**

- Giovane Hashinokuti Iwamoto - Computer Science student at UFMS - Brazil - MS
- Alexandre Diniz de Souza - Computer Science student at UFMS - Brazil - MS

I am always open to receiving constructive criticism and suggestions for improvement in my developed code. I believe that feedback is an essential part of the learning and growth process, and I am eager to learn from others and make my code the best it can be. Whether it's a minor tweak or a major overhaul, I am willing to consider all suggestions and implement the changes that will benefit my code and its users.
