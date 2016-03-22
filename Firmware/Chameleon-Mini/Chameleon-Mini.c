#include "Chameleon-Mini.h"

char FUSEBIT0, FUSEBIT1, FUSEBIT2, FUSEBIT3, FUSEBIT4, FUSEBIT5;

FUSES = {
          FUSEBIT0 = .byte[0],
          FUSEBIT4 = .byte[4],
        };



int main(void)
{
    SystemInit();
    SettingsLoad();
    LogInit();
    LEDInit();
    MemoryInit();
    ConfigurationInit();
    TerminalInit();
    RandomInit();
    ButtonInit();
    AntennaLevelInit();

    SystemInterruptInit();
    SystemSleepEnable();

    while(1) {
        if (SystemTick100ms()) {
            RandomTick();
            TerminalTick();
            ButtonTick();
            LogTick();
            LEDTick();
        }

		TerminalTask();
		ApplicationTask();
		LogTask();
		CodecTask();
    }
}



