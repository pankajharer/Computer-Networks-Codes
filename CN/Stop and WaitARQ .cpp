#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

bool transmitFrame() 
{
	return rand() % 2 == 0;
}

int main() 
{
	int totalFrames;
	cout<<"\n\n\n\t\t =========== STOP AND WAIT ARQ =============\n\n\n\n";
	cout << "--> Enter the total number of frames to simulate: ";
	cin >> totalFrames;
	int frameNumber = 0;
	cout << "\n==> Simulating Stop-and-Wait ARQ:\n\n";
	while (frameNumber < totalFrames) 
	{
		cout << "\nSender sends frame " << frameNumber << endl;
		bool received = transmitFrame();
		if (received) 
		{
			cout << "Receiver acknowledges frame " << frameNumber << endl;
			cout<<"______________________________________________________________________";
			frameNumber++;
		} 
		else 
		{
			cout << "Receiver does not acknowledge frame " << frameNumber << ", retransmitting...\n";
		}
		cout << endl;
	}
	cout << "\n\n\n\t\t !!! All frames have been sent and acknowledged. !!!\n\n\n\n";
	return 0;
}
