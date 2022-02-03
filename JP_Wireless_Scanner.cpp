#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <cstring>


#define RED "\33[31m"
#define BLUE "\33[34m"
#define YELLOW "\33[33m"

using namespace std;

void killboth(){
    system(" osascript -e 'tell application \"Terminal\" to do script \"killall airport & killall tshark & killall Terminal\"' ");


}

int menu(){
    int response;

    cout << "\033[1;31mJP Wireless Scanner\033[0m\n\033[1;34m1)\033[0m Scan for networks\n\033[1;34m2)\033[0m Scan Specific network\n\033[1;34m3)\033[0m Monitor networks\n\033[1;34m4)\033[0m Monitor Specific Channel\n\033[1;34m5)\033[0mScan current Network\n\033[1;34m0)\033[0m Exit"<< endl;cin >> response;

    return response;


}

int command(int response){
    int wtime;
    string channel;
    string SSID;
    string apts;
    string APS = "airport sniff ";
    string APN = "airport -s ";
    string AUX;
    string script ;

    const char * AUXCHAR;

    switch (response)
    {
    case 1:
        /* Scan Networks*///DONE
        system("airport -s");
        usleep(3000000);
        break;
    case 2:
    //Scan Specif network
        cout << "\033[1;33mType Network SSID: \033[0m" ;cin >> SSID;
        cout << endl;
        AUX = APN + SSID;
        AUXCHAR = AUX.c_str();

        system(AUXCHAR);
        break;
    case 3://Monitor Networks YAaa
        cout << "\033[1;33mScan Time In Seconds: \033[0m" ;cin >>wtime;
        wtime = wtime * 1000000;    
        cout << endl;
        system(" osascript -e 'tell application \"Terminal\" to do script \"airport sniff\"' ");
        system(" osascript -e 'tell application \"Terminal\" to do script \"tshark -i en0 -I -w ~/Desktop/test.pcap\"' ");
        usleep(wtime);
        killboth();
        system("wireshark ~/Desktop/test.pcap");
        break;
    case 4:    //Monitor specif channel //DONE
        cout << "\033[1;33mType Channel To Listen: \033[0m";cin >> channel;
        cout << endl;
        cout << "\033[1;33mScan Time In Seconds: \033[0m" ;cin >>wtime;
        wtime = wtime * 1000000;


        //AIRPORT CHANNEL SNIFF
        script = "osascript -e 'tell application \"Terminal\" to do script \"airport sniff "+channel+" \"' ";
        AUXCHAR = script.c_str();
        system(AUXCHAR);

        //TSHARK

        script = "osascript -e 'tell application \"Terminal\" to do script \"tshark -i en0 -I -w ~/Desktop/"+ channel+"channel.pcap\"' ";

        AUXCHAR = script.c_str();
        system(AUXCHAR);//tshark listener


        usleep(wtime);
        killboth();

        //open file
        script = "wireshark ~/Desktop/"+channel+"channel.pcap";
        AUXCHAR = script.c_str();
        system(AUXCHAR);

        break;
    case 5:    //Scan current network DONEEEE
        system("airport -I");
        break;
    case 0:    //exit DONEEEEE
        system("exit");
        return 0;
        break;
    default:
        cout << "invalid key" << endl;
        

        break;
    }

}

int main(){
    system("clear");
    

    int status = 1;

    while (status == 1){

        int resp = menu();
        status = command(resp);
        
    }

    return 0;
}


