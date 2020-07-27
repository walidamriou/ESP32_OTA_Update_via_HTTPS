# ESP32 OTA Update via HTTPS
Implement Esperssif ESP32 OTA (Over-The-Air) updates via HTTPS with the ESP-IDF framework.
you can use this project as a template. 

### SourceCode
Github: https://github.com/walidamriou/ESP32_OTA_Update_via_HTTPS

### Notes
#### Tools used:
- __Platformio__ (https://platformio.org)
- __VScode__ (https://code.visualstudio.com)
- __ESP-IDF__ (https://docs.espressif.com/projects/esp-idf/en/stable/get-started/) 

#### Development notes
- If you start a new Platformio project, use:
   - monitor_speed = 115200 in platformio.ini (in platformio.ini file)
   - board_build.partitions = partitions_two_ota.csv (in platformio.ini file)
   - #CONFIG_PARTITION_TABLE_SINGLE_APP is not set (in sdkconfig file)
   - CONFIG_PARTITION_TABLE_TWO_OTA=y (in sdkconfig file)
   - #CONFIG_PARTITION_TABLE_CUSTOM is not set (in sdkconfig file)
   - CONFIG_PARTITION_TABLE_CUSTOM_FILENAME="partitions.csv" (in sdkconfig file)
   - CONFIG_PARTITION_TABLE_FILENAME="partitions_two_ota.csv" (in sdkconfig file)
you can see this edit in the example.

- Functions & API:
   - put firmware_status.json , partitions_two_ota.csv , update.c , update.h , update_info.h , wifi.c and wifi.h in /src folder.
   - Edit firmware_status.json and put the current firmware version and the url when we can get new one, this file we call it from the server, in the example I use it directly from the src folder because I upload it to github. 
   - Edit update_info.h and put the current firmware version that you upload to the board with the url when we can get new one.
   - Edit wifi_info.h and put the username and password of the wifi.
   - in your main.c call this functions with this order:    
      wifi_init();  
      wifi_connect();  
      int a = check_updates(); //if there is new firmware, check_updates() return 1 if not return 0  
      if(a==1){    
        update();  
      }  
   - you can play with the last functions. For example, you can call it when a click button or an event happens, but with the same order.   
   
### Website
https://www.walidamriou.com

### Copyright CC 2020 Walid Amriou

<a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-nd/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/4.0/">Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License</a>.

__You are free to:__
- __Share__ copy and redistribute the material in any medium or format

__Under the following terms:__
- __Attribution__ You must give appropriate credit, provide a link to the license, and indicate if changes were made. You may do so in any reasonable manner, but not in any way that suggests the licensor endorses you or your use.

- __NonCommercial__ You may not use the material for commercial purposes.

- __NoDerivatives__ If you remix, transform, or build upon the material, you may not distribute the modified material.

- __No additional restrictions__ You may not apply legal terms or technological measures that legally restrict others from doing anything the license permits.


the software or Code or Scripts or any files in this source is provided "as is" and the author disclaims all warranties with regard to this files including all implied warranties of merchantability and fitness. in no event shall the author be liable for any special, direct, indirect, or consequential damages or any damages whatsoever resulting from loss of use, data or profits, whether in an action of contract, negligence or other tortious action, arising out of or in connection with the use or performance of this software or code or scripts or any files in this source.

The logo and the name of the project are owned by Walid Amriou, and do not fall under the open license for reconstruction, it must be preserved in full without modification. 
