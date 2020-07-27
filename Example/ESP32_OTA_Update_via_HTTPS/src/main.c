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
    wifi_init();
    printf("wifi init done.\n");
    wifi_connect();
    printf("Connected to wifi network\n");

    printf("Firmware 1\n");

    int a = check_updates();
    if(a==1){
        update();
    }
    printf("Firmware 1\n");

    
}