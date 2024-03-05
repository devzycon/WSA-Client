# TCP/IP Client Application using WinSock API
Server: https://github.com/devzycon/WSA-Server

## Overview
This project implements a client application in C++ using the Windows Socket API (WinSock). It is designed to connect to a server listening on a specified port, send messages to the server, and receive acknowledgments from the server.

## Features
- Connect to a server running on localhost at port 55555.
- Send messages to the server.
- Receive acknowledgments from the server.

## Requirements
- Windows operating system
- Visual Studio or any C++ compiler with support for WinSock API

## Setup and Compilation
1. Ensure the WinSock2.h library is included in your project settings.
2. Compile the client application using your preferred C++ compiler. For Visual Studio, create a new project and add the provided source file.

## Running the Client
1. Ensure the server application is running and listening for connections.
2. Open the command line and navigate to the directory containing the compiled client executable.
3. Run the executable. Follow the prompts to send messages to the server.
4. To terminate the client, close the command line window.
