#ifndef __BUZZER_HW_H__
#define __BUZZER_HW_H__

#define BUZZER_PORT GPIO_PORT_P2
#define BUZZER_PIN GPIO_PIN7

void buzzer_hw_init(void);

void buzzer_on(void);
void buzzer_off(void);

#endif
