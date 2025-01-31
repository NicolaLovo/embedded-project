#ifndef __SENSOR_ON_READ_H__
#define __SENSOR_ON_READ_H__

/*
 * TRUE = 1  --> There is a contact revealed
 * FALSE = 0  --> No contact revealed
 */
enum Contact {
  TRUE = 1,
  FALSE = 0,
} typedef Contact;

void buzzer_on_read(Contact contact);

#endif
