#ifndef __WATERLEVEL_H
#define __WATERLEVEL_H

/* Includes */

/* Definitions and Macros */
#define MAX_WATER_LEVEL 50	// req 23: "The volume of the tank shall be 50 L."
#define SIGNO 30

/* Type, enum, and struct definitions */
typedef enum {
	WATER_SENSOR_NONE = 0,
	WATER_SENSOR_LOW,
	WATER_SENSOR_LOWMID,
	WATER_SENSOR_MIDHIGH,
	WATER_SENSOR_HIGH
} water_sensor_level_t;

typedef struct {
	water_sensor_level_t previous_sensor;
	water_sensor_level_t current_sensor;
	int water_level;
} water_sensor_t;

/* Function prototypes */
void WATER_Init(void);
void WATER_TaskInit(void);
void setWaterLevelSensor(int sensorNumber, int newWaterLevel);
void sigHand(int sigNo);
TASK_ID WATER_getTaskId(void);

#endif
