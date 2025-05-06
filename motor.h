#ifndef MOTOR_H
#define MOTOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"

// Pins für TB6600 (Microstep Driver)
#define STEP_PIN GPIO_PIN_6    // XSTEP auf PA6
#define DIR_PIN  GPIO_PIN_1    // XDIR auf PE1
#define ENA_PIN  GPIO_PIN_0    // XEN auf PE0

#define TIMER htim3            // Timer für PWM (TIM3)

// Timer-Handle aus main.c importieren
extern TIM_HandleTypeDef TIMER;

// Funktionsprototypen

// Initialisiert die Motorsteuerung und den Timer
void Motor_Init(void);

// Setzt die Drehrichtung des Motors
void Motor_SetDirection(uint8_t direction);

// Setzt die Geschwindigkeit des Motors (PWM Duty Cycle)
void Motor_SetSpeed(uint16_t speed);

// Aktiviert den Motor
void Motor_Enable(void);

// Deaktiviert den Motor
void Motor_Disable(void);

#ifdef __cplusplus
}
#endif

#endif /* MOTOR_H */
