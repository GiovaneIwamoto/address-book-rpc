# ADDRESS BOOK RPC

### **OVERVIEW**

This project defines an RPC interface for an address book program and implements both the server and client components essential for its functionality. The RPC interface serves as a communication bridge between the client and server, enabling clients to interact with a basic address book stored on the server. Key functionalities encompass inserting, removing, listing, and searching contacts.

[![Icons](https://skillicons.dev/icons?i=c,py,linux,ubuntu,debian&theme=dark)](https://skillicons.dev)

> [!NOTE]
> RPC is a powerful protocol that enables a program to execute code on a remote server as if it were local, which is essential for distributed computing applications.

---

### **INSTALLATION GUIDE**

> RPC GENERATOR

```ruby
$ rpcgen adb.x
```

> COMPILE SERVER

```ruby
$ gcc -o server adb_sif.c adb_svc.c adb_server.c adb_xdr.c -I/usr/include/tirpc -ltirpc
```

> COMPILE CLIENT

```ruby
$ gcc -o client adb_cif.c adb_clnt.c adb_client.c adb_xdr.c -I/usr/include/tirpc -ltirpc -fcommon
```

---

### **CLEAR RPC STUBS**

> [!TIP]
> The provided Python script is designed to maintain the cleanliness and organization of the directory by removing the stubs generated by the RPC generation process. RPC stubs are intermediary files created to facilitate the communication between client and server during the execution of remote procedures.

```ruby
'Python script'
$ python3 clear_rpc.py
```

---

### **PORTMAP AND RPCBIND**

> [!IMPORTANT]
> Rpcbind is responsible for mapping RPC program numbers to network addresses, thus allowing clients to locate and connect to the appropriate services on the network

```ruby
'Portmap error init service'
$ service portmap start

'Install Portmap'
$ sudo apt install portmap

'Install Rpcbind'
$ sudo systemctl start rpcbind
```

> [!WARNING]
> Starting the rpcbind service using the command sudo systemctl start rpcbind ensures that the RPC programs can register with the rpcbind daemon and be accessible for remote procedure calls, facilitating seamless communication across different systems in a networked environment.

---

### **AUTHOR**

- Giovane Hashinokuti Iwamoto - Computer Science student at UFMS - Brazil - MS
- Alexandre Diniz de Souza - Computer Science student at UFMS - Brazil - MS

I am always open to receiving constructive criticism and suggestions for improvement in my developed code. I believe that feedback is an essential part of the learning and growth process, and I am eager to learn from others and make my code the best it can be. Whether it's a minor tweak or a major overhaul, I am willing to consider all suggestions and implement the changes that will benefit my code and its users.
