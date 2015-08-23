//************************************************************************
//*	Arduino Test Suite
//*	ATS_ToneTest
//*	
//*	Copyright (c) 2010 Mark Sproul  All right reserved.
//*	 
//*	This library is free software; you can redistribute it and/or
//*	modify it under the terms of the GNU Lesser General Public
//*	License as published by the Free Software Foundation; either
//*	version 2.1 of the License, or (at your option) any later version.
//*	
//*	This library is distributed in the hope that it will be useful,
//*	but WITHOUT ANY WARRANTY; without even the implied warranty of
//*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//*	Lesser General Public License for more details.
//*	
//*	You should have received a copy of the GNU Lesser General Public
//*	License along with this library; if not, write to the Free Software
//*	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//************************************************************************
//*	Aug 31,	2010	<MLS> Started on TestArduino
//*	Oct 28,	2010	<MLS> Started on Delay
//************************************************************************

#include <ArduinoTestSuite.h>

//************************************************************************
void setup()
{
	short ii;
	short testNum;
	unsigned long startMillis;
	unsigned long endMillis;
	unsigned long deltaMillis;
	unsigned long errMillis;
	boolean passed;
	char testNameString[80];

	int startMemoryUsage = ATS_GetFreeMemory();
	ATS_begin("Arduino", "DelayTest");
	testNum = 1;
	//* we start at 2 because 0/1 are RXD/TXD
	for (ii = 0; ii < 1000; ii += 15) {
		startMillis = millis();
		delay(ii);
		endMillis = millis();
		deltaMillis = endMillis - startMillis;
		if (deltaMillis >= ii) {
			errMillis = deltaMillis - ii;
		} else {
			errMillis = ii - deltaMillis;
		}
		if (errMillis <= 1) {
			passed = true;
		} else {
			passed = false;
		}
		sprintf(testNameString,
			"DelayTest.%02d (delay= %4d actual delay=%ld err=%ld)",
			testNum, ii, deltaMillis, errMillis);
		ATS_PrintTestStatus(testNameString, passed);
		testNum++;
	}
	ATS_ReportMemoryUsage(startMemoryUsage);
	ATS_end();
}

//************************************************************************
void loop()
{
}

