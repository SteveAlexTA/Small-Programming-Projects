#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

void songLyricsDisplay(const string lyrics, int typeSpeed, int pauseDuration, bool clearConsole) {
	for (int i = 0; i < lyrics.length(); i++) {
		cout << lyrics[i] << flush;
		Sleep(typeSpeed);
	}
	Sleep(pauseDuration);
	if(clearConsole) {
		system("cls");
	}
}

int main()
{
	songLyricsDisplay("So let mercy come...", 95, 1200, true);
	songLyricsDisplay("And wash away...", 95, 1200, true);
	songLyricsDisplay("What", 120, 1200, false);
	songLyricsDisplay(" I've ", 100, 1200, false);
	songLyricsDisplay("DONEEEEEEEEEEEEEE!", 85, 1000, true);
	songLyricsDisplay("I'll face myself", 95, 1200, true);
	songLyricsDisplay("To cross out what I've become", 95, 1200, true);
	songLyricsDisplay("Erase myself...", 95, 1000, true);
	songLyricsDisplay("And let go of what...", 95, 1500, true);
	songLyricsDisplay("I've...", 120, 1200, true);
	songLyricsDisplay("DONE!", 120, 1200, true);
}
