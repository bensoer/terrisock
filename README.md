#terrisock
By Ben Soer and Eric Tsang

#Why use terrisock ?
terrisock is an Object Oriented Library/Wrapper to make working with the C Berkley Socket API easier to handle in
typical tasks. Terrisock allows users to create both UDP and TCP servers and clients with ease and communicate with
each other. Terrisock is designed for any skill level of developer but is mostly oriented towards quick and easy, small to
medium size projects. Terrisock is designed to take a minimal performance hit, for the ease and benefit of saving
developer time and debugging headaches. Even after saying that though, terrisock is also highly flexible, allowing developers
to access the raw socket descriptor at anytime to use it as they prefer with the C berkley socket API or any other tools
of their preference. Additionally, terrisock is IPv neutral! So all of your handling woes of IPv4 and IPv6 are taken care of.
In case visioning matters, terrisock can even be forced to be IPv specific for your coding needs.
See the examples below for a more thorough explanation!

terrisock has many exciting new features coming soon to add onto your application needs including Out of Band data, Heartbeat
monitoring, SSL and the many socket customization options available through `fctnl`, `sockopt`, and `ioctl`. All wrapped
in a clean and simple object-oriented fashion. Network programming has never been so easy!

#Development Notes
_Dec 15/2015_ - Currently the project is in massive development and is not functional <br>
_Apr 26/2016_ - The project is still in large development stages. But a release with basic functionality is coming soon!

#Setup
_Installation instructions are currently in progress_

##Prerequisites
You will need to have `cmake` installed and available in your system path for these instructions

##Installation
1. Download and extract the latest version form the release page: [https://github.com/project-terris/terrisock/releases](https://github.com/project-terris/terrisock/releases)
2. Enter the root directory of the project. Run the command `cmake CMakeLists.txt`. This will compile everything
3. a file named `libterrisock.so` for linux or `libterrisock.dll` will be created containing the compiled library
4. Copy the so/dll file to your own project, and include/import from there. Note you will need to specify the `terrisock`
namespace to use the library. See the examples below for more details

##Examples
Below contains some simple minimal examples on using terrisock. For examples of advanced features available in terrisock,
see the Wiki page at: [https://github.com/project-terris/terrisock/wiki](https://github.com/project-terris/terrisock/wiki)

###Basic TCP Client
Make a basic TCP Client !

```cpp

    #include <SocketAddress.h>
    #include <tcp/TCPSocket.h>
      
    using namespace terrisock;

    int main(){
    
        //create the TCP Socket
        TCPSocket * socket = new TCPSocket();
        //create an address to connect to
        SocketAddress * address = new SocketAddress("localhost", 8001);
        //connect to it
        socket->connect(address);
    
        //now send a message
        long bytesSent = socket->send("Hello World!");
    
    
        //close and cleanup
        socket->shutdown();
        socket->close();
    
        delete(address);
        delete(socket);
    
        return 0;
    }
```
###IPV6/IPV4 Forced TCP Client

Force terrisock to create an IPV6 or IPV4 socket! By default terrisock uses whichever it can resolve first when
connecting with the SocketAddress. If you would like terrisock to _only_ use IPV4 or IPV6, simply pass the `AF_INET`
or `AF_INET6` constants, part of the standard C Berkley Socket API.

Note that this means, terrisock will only connect if an IPV4 or IPV6 address is available, if an endpoint does not have
an address for the forced IP version, an error will occur.

```cpp

    #include <SocketAddress.h>
    #include <tcp/TCPSocket.h>
      
    using namespace terrisock;

    int main(){
    
        //create the TCP Socket - pass AF_INET to force IPV4. pass AF_INET6 to force IPV6
        TCPSocket * socket = new TCPSocket(AF_INET6);
        //create an address to connect to
        SocketAddress * address = new SocketAddress("localhost", 8001);
        //connect to it
        socket->connect(address);
    
        //now send a message
        long bytesSent = socket->send("Hello World!");
    
    
        //close and cleanup
        socket->shutdown();
        socket->close();
    
        delete(address);
        delete(socket);
    
        return 0;
    }
```
###Basic TCP Server
Make a basic TCP Server !

```cpp

    #include <tcp/TCPListenerSocket.h>
    
    using namespace std;
    using namespace terrisock;
    
    int main(){
    
        //create a listener socket
        TCPListenerSocket * server = new TCPListenerSocket();
        //bind it to port 8001
        server->bind(8001);
        //start listening with a max amount of connections of 10
        server->listen(10);
    
        //accept whomever connects
        server->accept();
    
        //new receive the message from whomever has connected.
        string * message = new string();
        long bytes = server->recv(message);
        
        //bytes contains number of bytes transfered
        //message contains the actual message sent as a string
    
        return 0;
    }

```
###Take Back Control
Say you want to create a socket, but you don't like terrisocks bi-directional pipe like handling of message sending.
Easy! simply get your socket at any point your done working with the terrisock library.

If you want, even after the fact, some of terrisock functionality will still work even after you've pulled the descriptor.
Since terrisock only returns a copy, it contains all of the state information from before `getSocket()` was called. This
means functionality such as closing and shutting down connections is still available!

```cpp

    #include <SocketAddress.h>
    #include <tcp/TCPSocket.h>
      
    using namespace terrisock;

    int main(){
    
        //create the TCP Socket
        TCPSocket * socket = new TCPSocket();
        //create an address to connect to
        SocketAddress * address = new SocketAddress("localhost", 8001);
        //connect to it
        socket->connect(address);
    
        int descriptor = socket->getSocket();
        //descriptor is the raw socket descriptor. do what you'd like form here...
        
        
        /* your code */
    
        //cleanup the connection with terrisock
        socket->shutdown();
        socket->close();
    
        delete(address);
        delete(socket);
    
        return 0;
    }
```

###Basic UDP Client
Below sets up a basic UDP socket. With UDP being connectionless, you need to pass the address with every sendto request.
Additionally, terrisock contains functionality to give a _connection-oriented like_ api. This is implemented simply with
the `connect(SocketAddress * address)` call which simply stores the passed `SocketAddress` for you and adds it during 
calls made with `send()`. Further examples of this functionality can be found in the Wiki
```cpp

    #include <SocketAddress.h>
    #include <udp/UDPSocket.h>
    
    using namespace terrisock;
    
    int main(){
    
        UDPSocket * socket = new UDPSocket();
    
        SocketAddress * address = new SocketAddress("localhost", 8001);
    
        socket->sendto("Hello World!", address);
       
    
        return 0;
    
    }
```

###Basic UDP Server
Below is a basic UDP Server. Again because UDP is connecitonless, a SocketAddress needs to be passed to the `recvfrom()`
and `sendto()` methods. For any UDP socket to be able to receive data aswell, it needs to make a call to the `bind()` method
otherwise the socket will be unable to determine where to listen for incoming data.
```cpp

    #include <SocketAddress.h>
    #include <udp/UDPSocket.h>
    
    using namespace terrisock;
    
    int main(){
    
        UDPSocket * server = new UDPSocket();
        server->bind(8001);
    
        string * message = new string();
        SocketAddress * source = new SocketAddress();
    
        long bytesRecieved = server->recvfrom(message, source);
    
        long bytesSent = server->sendto("Hello Back UDP Client!", source);
    
        return 0;
    }
```