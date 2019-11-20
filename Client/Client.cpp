#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <thread>

using namespace std;    


// Function that receives the data from the Server.
// Takes 2 arguments; a socket and a char buffer[].
void receive(int file_d, char buffer[]){

    // Array where the received message from a client is stored.
	char client_name[100];

    // Infinite loop.
    while(true){

        // Receives the client name and message and stores it in client_name and buffer.
        recv(file_d, client_name, (sizeof(client_name) / sizeof(*client_name)), 0);
        recv(file_d, buffer, 1024, 0);

        // If statement that controls whether or not the message received is a '#
        // If true it will go down into the if statment.
        if(*client_name == '#') {
            cout << "Terminating program now" << endl;

            // Close the file_d socket.
            close(file_d);

            // Exit the program.
            exit(1);
        }

        // Print the message.
	    cout << client_name << " says:";
        cout << " " << buffer << "\n\n";
    }
}

// Main thread
int main(){

    return 0;
}
