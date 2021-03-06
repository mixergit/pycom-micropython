/*
 * Copyright (c) 2016, Pycom Limited.
 *
 * This software is licensed under the GNU GPL version 3 or any
 * later version, with permitted additional terms. For more information
 * see the Pycom Licence v1.0 document supplied with this file, or
 * available at https://www.pycom.io/opensource/licensing
 */

#include <string.h>
#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "freertos/timers.h"
#include "freertos/xtensa_api.h"

#include "heap_alloc_caps.h"
#include "sdkconfig.h"
#include "esp_system.h"
#include "esp_attr.h"
#include "esp_spi_flash.h"
#include "rom/spi_flash.h"
#include "rom/ets_sys.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "soc/dport_reg.h"

#include "mptask.h"

/******************************************************************************
 * FunctionName : app_main
 * Description  : entry of user application, init user function here
 * Parameters   : none
 * Returns      : none
*******************************************************************************/
void app_main(void) {
    nvs_flash_init();
    system_init();

    // create the MicroPython task
    xTaskCreatePinnedToCore(TASK_Micropython, "MicroPy", MICROPY_TASK_STACK_LEN, NULL, MICROPY_TASK_PRIORITY, NULL, 0);
}

int ets_printf_dummy(const char *fmt, ...) {
    return 0;
}
