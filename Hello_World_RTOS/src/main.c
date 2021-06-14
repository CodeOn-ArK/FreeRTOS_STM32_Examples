/**
  ******************************************************************************
  * @file    main.c
  * @author  CodeOn-ArK
  * @version V1.0
  * @date    June_2021
  * @brief   Hello World testing
  ******************************************************************************
*/

#include "main.h"
			
void SystemClock_Config(void);
static void task1_handler(void *parameter);
static void task2_handler(void *parameter);


int main(void)
{
	SystemClock_Config();

	TaskHandle_t task1_handle, task2_handle;
	BaseType_t status;

	printf("The application has started\n\r");

	status = xTaskCreate(task1_handler, "TASK 1", 200, "TASK 1\r", 2, &task1_handle);
	configASSERT(status == pdPASS);

	status = xTaskCreate(task2_handler, "TASK 2", 200, "TASK 2\r", 2, &task2_handle);
	configASSERT(status == pdPASS);

	//start FreeRTOS scheduler
	vTaskStartScheduler();

	//if the control comes here, the cpu comes here due to unsufficient task in the memory


	for(;;);
}

static void task1_handler(void *parameter)
{

	while(1){
		printf("%s\n", (char *)parameter);
		taskYIELD();
	}
}
static void task2_handler(void *parameter)
{

	while(1){
		printf("%s\n", (char *)parameter);
		taskYIELD();
	}
}

/**************************************** SYSTEM SPECIFIC ***********************************************/

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}


void Error_Handler()
{
	while(1){
	}
}
