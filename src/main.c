/* 
ESP32 OTA Update via HTTPS 
Implement Esperssif ESP32 OTA (Over-The-Air) updates via HTTPS with the ESP-IDF framework.
Developed by: Walid Amriou
www.walidamriou.com

This work is licensed under:
Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.

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