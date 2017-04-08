// gpstime.h

#ifndef _GPSTIME_h
#define _GPSTIME_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class GPSTIME {
private:
	unsigned long time_, offset_;
	boolean EOL_;
	String buffer_;
	byte pPPS_;
	void(*triggerUpdate_)(unsigned long);

	void writeTime();
public:
	GPSTIME(byte pPPS, void (*callback)(unsigned long));
	~GPSTIME();

	void serialIn();
	void setOffset();
	unsigned long getTime() { return time_; };
};

#endif

