# HTTPChat

http://127.0.0.1:1738/lisa/andrew/msg/

127.0.0.1 - work in this address and can not set

1738 - port which you can set in main.c

lisa - your username

andrew - your opponent in chat

msg - your message to opponent

http://127.0.0.1:1738/admin/

Right here some information of users


File responsibility
-----------------------------------------------------------

APIView - In this file realize methods of HTTP proto (GET,POST- in develop) using SessionHTTPMethod

SessionHTTPMethod - Controll session and new clients

OpenConnectionHTTP - Accepting client by getting request and registering him in CommunicationThread

CommunicationThread - Metods for registering new client

TCP - Setting tcp proto

SetString - Methods for work with string and some memory

PagesHTTP - Methods which sends HTTP pages and closing connection

Threads - Unlocked threads for OpenConnection and APIView

-----------------------------------------------------------


*Add NONBLOCK socket

*Set malloc

System
----------------------------------------------------------
Linux
