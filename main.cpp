#include "SerialClass.h"

int main(void){


   Serial* SP;
      
   while(1){
      try{
         SP = new Serial("COM4"); //We may need to adjust this as necessary
         break;
      }
      catch(const int x){
         if(x == 1){
            cout<<"\n Please connect the arduino!"<<endl;
            Sleep(3000);
         }else if(x == 2){
            cout<<"\n Unknown error!"<<endl;
         }
      }
      catch(...){
         cout<<"\n Catch all. Should not be here!"<<endl;
      }
   }

   if (SP->IsConnected()){
		cout<<"\n Ardiuno Connected!"<<endl;
	}else{
		cout<<"\n Arduino not connected?.. Terminating!"<<endl;
	}

	string incomingDataString;
	char incomingData[256] = "";
	int dataLength = 255;
	int readResult = 0;

   for(int i = 0; i < 100; i++){
      readResult = SP->ReadData(incomingData,dataLength); //Data will be written to incomingData, readResult is just to make sure it worked.
   }

}
