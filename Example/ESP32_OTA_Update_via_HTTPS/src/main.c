/* 
Connecting to an WiFi Access Point 
Developed by: Walid Amriou
www.walidamriou.com

Last update: July 2020
*/

#include <wifi.h>
#include <update.h>
#include <esp_system.h>

void app_main() {
    printf("Firmware2\n");
    wifi_init();
    printf("wifi init done.\n");
    wifi_connect();
    printf("Connected to wifi network\n");


    
}