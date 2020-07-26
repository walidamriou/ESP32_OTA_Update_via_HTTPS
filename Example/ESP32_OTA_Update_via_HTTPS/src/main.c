#include <wifi.h>
#include <esp_system.h>

void app_main() {
    wifi_init();
    printf("wifi init done.\n");
    wifi_connect();
    printf("Connected to wifi network\n");
}