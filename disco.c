#include <sysinit.h>


#include "basic/basic.h"
#include "basic/random.h"
#include "lcd/display.h"
#include "lcd/lcd.h"
#include "lcd/print.h"
#include <sysdefs.h>
#include "lpc134x.h"
#include "core/ssp/ssp.h"
#include "gpio/gpio.h"
#include "basic/basic.h"
#include "basic/config.h"
#include "usb/usbmsc.h"

#include "filesystem/ff.h"
#include "usetable.h"


void ram(void){
	
  	int x=100;
	char filename[13];
	lcdClear();
	selectFile(filename,"LCD");
	lcdLoadImage(filename);
	lcdRefresh();
	do{
	if(getRandom()%2==0)
		GLOBAL(lcdinvert)=!GLOBAL(lcdinvert);

	TMR_TMR16B1MR0 = (0xFFFF * (100 - (getRandom()%100))) / 100;
	lcdRefresh();
	delayms(getRandom()%100);
	
    }while ((getInputRaw())==BTN_NONE);
	
	
	return;
}
