#include "motor.h"

// Initialisiere die Pins und Timer für den Motor
void Motor_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Aktivierung der benötigten Taktquellen
    __HAL_RCC_GPIOA_CLK_ENABLE();  // Für STEP (PA6)
    __HAL_RCC_GPIOE_CLK_ENABLE();  // Für DIR (PE1) & ENA (PE0)
    __HAL_RCC_TIM3_CLK_ENABLE();   // Für Timer 3 (Falls noch nicht aktiviert)

    // DIR und ENA auf Port E setzen
    GPIO_InitStruct.Pin = DIR_PIN | ENA_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);  // **Hier GPIOE statt MOTOR_PORT!**

    // STEP als Alternativfunktion für PWM setzen
    GPIO_InitStruct.Pin = STEP_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM3; // TIM3_CH1 auf PA6
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);  // **Hier GPIOA für STEP!**

    // Timer 3 konfigurieren (falls noch nicht geschehen)
    TIM_OC_InitTypeDef sConfigOC = {0};
    TIMER.Instance = TIM3;
    TIMER.Init.Prescaler = 0;  // Keine Prescaler, direkte Timer-Frequenz
    TIMER.Init.CounterMode = TIM_COUNTERMODE_UP;
    TIMER.Init.Period = 1000 - 1;  // Timerperiode
    TIMER.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    HAL_TIM_PWM_Init(&TIMER);

    // PWM-Kanal konfigurieren
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 500;  // Initialer Duty Cycle
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    HAL_TIM_PWM_ConfigChannel(&TIMER, &sConfigOC, TIM_CHANNEL_1);

    // PWM starten
    HAL_TIM_PWM_Start(&TIMER, TIM_CHANNEL_1);
}

// Setzt die Richtung des Motors
void Motor_SetDirection(uint8_t direction) {
    HAL_GPIO_WritePin(GPIOE, DIR_PIN, direction ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

// Setzt die Geschwindigkeit (PWM Duty Cycle)
void Motor_SetSpeed(uint16_t speed) {
    __HAL_TIM_SET_COMPARE(&TIMER, TIM_CHANNEL_1, speed);
}

// Aktiviert den Motor (ENA auf LOW)
void Motor_Enable(void) {
    HAL_GPIO_WritePin(GPIOE, ENA_PIN, GPIO_PIN_SET);
}

// Deaktiviert den Motor (ENA auf HIGH)
void Motor_Disable(void) {
    HAL_GPIO_WritePin(GPIOE, ENA_PIN, GPIO_PIN_SET);
}

