// gpstime.h

#ifndef _GPSTIME_h
#define _GPSTIME_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

enum Time { H2, H1, M2, M1, S2, S1 };

class GPSTIME {
private:
	unsigned long time_, offset_;
	char t_[7];
	boolean EOL_;
	String buffer_;
	byte pPPS_;
	void(*triggerUpdate_)(char*);

	void writeTime();
	static void sync();

public:
	GPSTIME(byte pPPS, void (*callback)(char*));
	~GPSTIME();

	void serialIn();
	void setOffset();
	unsigned long getTime() { return time_; };
};

#endif

