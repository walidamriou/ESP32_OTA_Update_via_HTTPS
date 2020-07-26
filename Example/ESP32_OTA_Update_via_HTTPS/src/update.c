/* 
Update system 
Developed by: Walid Amriou
www.walidamriou.com

Last update: July 2020
*/

#include <wifi_info.h>
#include <wifi.h>

#include <update_info.h>
#include <update.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/event_groups.h>
#include <esp_wifi.h>
#include <esp_system.h>
#include <esp_event.h>
#include <esp_event_loop.h>
#include <nvs_flash.h>
#include <tcpip_adapter.h>
#include <cJSON.h>
#include <esp_log.h>
#include <esp_http_client.h>
#include <esp_https_ota.h>
#include <string.h>

cJSON *version;
cJSON *file;

// esp_http_client event handler
esp_err_t _http_event_handler(esp_http_client_event_t *evt) {
    
	switch(evt->event_id) {
        case HTTP_EVENT_ERROR:
            break;
        case HTTP_EVENT_ON_CONNECTED:
            break;
        case HTTP_EVENT_HEADER_SENT:
            break;
        case HTTP_EVENT_ON_HEADER:
            break;
        case HTTP_EVENT_ON_DATA:
            if (!esp_http_client_is_chunked_response(evt->client)) {
				strncpy(rcv_buffer, (char*)evt->data, evt->data_len);
            }
            break;
        case HTTP_EVENT_ON_FINISH:
            break;
        case HTTP_EVENT_DISCONNECTED:
            break;
    }
    return ESP_OK;
}

	
int check_updates(){
    printf(" check firmware version...\n");
	
    // configure http client
    esp_http_client_config_t config = {
        .url = FIRMWARE_STATUS_JSON_URL,
        .event_handler = _http_event_handler,
    };

    esp_http_client_handle_t client = esp_http_client_init(&config);
	
	// downloading the json file
	esp_err_t err = esp_http_client_perform(client);
    if(err == ESP_OK) {
        // parse the json file	
		cJSON *json = cJSON_Parse(rcv_buffer);
		if(json == NULL){
            printf(" Problem with json file from the server\n Aborting update system\n");
            return 0;
        }
        else{	
            version = cJSON_GetObjectItemCaseSensitive(json, "version");
			file = cJSON_GetObjectItemCaseSensitive(json, "file");
            
            // check the version
            if(!cJSON_IsNumber(version)){
                printf(" Problem with the version number from json file\n Aborting update system\n");
                return 0;
            }
            else {
                double current_version_number_from_server = version->valuedouble;
                if(current_version_number_from_server > FIRMWARE_VERSION) {
                    printf(" Current firmware version (%.1f) is lower than the available one (%.1f), upgrading...\n", FIRMWARE_VERSION, current_version_number_from_server);
                return 1;
                }
                else {
                    return 0;
                }
            }
        }
    }
    else {
        return 0;
    }
}

void update(){
    if(cJSON_IsString(file) && (file->valuestring != NULL)) {
        printf(" Downloading and installing new firmware (%s)...\n", file->valuestring);							
		esp_http_client_config_t ota_client_config = {
			.url = file->valuestring,
			.cert_pem = server_cert_pem_start,
	    };
        esp_err_t ret = esp_https_ota(&ota_client_config);
        if (ret == ESP_OK) {
            printf(" download and installation of the new firmware is done");
		    printf(" Restarting board ...\n");
		    esp_restart();
        } 
        else {
		    printf("Failed to download and the install new firmware...\n");
	    }
    }
    else {
        printf("Unable to read the new file name, aborting...\n");
    }
}