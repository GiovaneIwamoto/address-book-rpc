# ADDRESS BOOK RPC

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