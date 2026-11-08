// Name: project_08.c
// Purpose: Provide flight information based on given time.
// Author: Georg

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int input_hours, input_minutes, input_time;
  int rv;
  int distance, time;
  int min_distance, closest_time;
  bool debug = false;

  puts("This program asks for a time and returns the flight with the closest\n"
       "departure time.");
  printf("\nEnter a 24-hour time (8:45, 08:45, 20:45): ");
  fflush(stdout);
  rv = scanf("%d:%d", &input_hours, &input_minutes);

  if (rv != 2 || input_hours < 0 || input_hours > 23 || input_minutes < 0 ||
      input_minutes > 59) {
    fprintf(stderr, "\nError: bad input - expected 24h format time\n");
    return EXIT_FAILURE;
  }

  input_time = input_hours * 60 + input_minutes;
  if (debug)
    printf("input_time: %d\n", input_time);

  time = 480;
  min_distance = input_time - time > 0 ? input_time - time : time - input_time;
  closest_time = time;

  if (debug)
    printf("time: %d, min_distance: %d, closest_time: %d\n", time, min_distance,
           closest_time);

  time = 583;
  distance = input_time - time > 0 ? input_time - time : time - input_time;
  if (distance < min_distance) {
    min_distance = distance;
    closest_time = time;
  }
  if (debug)
    printf("time: %d, min_distance: %d, closest_time: %d\n", time, min_distance,
           closest_time);

  time = 679;
  distance = input_time - time > 0 ? input_time - time : time - input_time;
  if (distance < min_distance) {
    min_distance = distance;
    closest_time = time;
  }
  if (debug)
    printf("time: %d, min_distance: %d, closest_time: %d\n", time, min_distance,
           closest_time);

  time = 767;
  distance = input_time - time > 0 ? input_time - time : time - input_time;
  if (distance < min_distance) {
    min_distance = distance;
    closest_time = time;
  }
  if (debug)
    printf("time: %d, min_distance: %d, closest_time: %d\n", time, min_distance,
           closest_time);

  time = 840;
  distance = input_time - time > 0 ? input_time - time : time - input_time;
  if (distance < min_distance) {
    min_distance = distance;
    closest_time = time;
  }
  if (debug)
    printf("time: %d, min_distance: %d, closest_time: %d\n", time, min_distance,
           closest_time);

  time = 945;
  distance = input_time - time > 0 ? input_time - time : time - input_time;
  if (distance < min_distance) {
    min_distance = distance;
    closest_time = time;
  }
  if (debug)
    printf("time: %d, min_distance: %d, closest_time: %d\n", time, min_distance,
           closest_time);

  time = 1140;
  distance = input_time - time > 0 ? input_time - time : time - input_time;
  if (distance < min_distance) {
    min_distance = distance;
    closest_time = time;
  }
  if (debug)
    printf("time: %d, min_distance: %d, closest_time: %d\n", time, min_distance,
           closest_time);

  time = 1305;
  distance = input_time - time > 0 ? input_time - time : time - input_time;
  if (distance < min_distance) {
    min_distance = distance;
    closest_time = time;
  }
  if (debug)
    printf("time: %d, min_distance: %d, closest_time: %d\n", time, min_distance,
           closest_time);

  // Allow calendar day switches
  input_time = input_time + 1440;
  distance = input_time - time > 0 ? input_time - time : time - input_time;
  if (distance < min_distance) {
    min_distance = distance;
    closest_time = time;
  }
  if (debug)
    printf("time: %d, min_distance: %d, closest_time: %d\n", time, min_distance,
           closest_time);

  printf("\nClosest departure time is ");
  if (closest_time == 480) {
    printf("8:00 a.m.");
  } else if (closest_time == 583) {
    printf("9:43 a.m.");
  } else if (closest_time == 679) {
    printf("11:19 a.m.");
  } else if (closest_time == 767) {
    printf("12:47 p.m.");
  } else if (closest_time == 840) {
    printf("2:00 p.m.");
  } else if (closest_time == 945) {
    printf("3:45 p.m.");
  } else if (closest_time == 1140) {
    printf("7:00 p.m.");
  } else if (closest_time == 1305) {
    printf("9:45 p.m.");
  }
  printf(", arriving at ");
  if (closest_time == 480) {
    printf("10:16 a.m.");
  } else if (closest_time == 583) {
    printf("11:52 a.m.");
  } else if (closest_time == 679) {
    printf("1:31 p.m.");
  } else if (closest_time == 767) {
    printf("3:00 p.m.");
  } else if (closest_time == 840) {
    printf("4:08 p.m.");
  } else if (closest_time == 945) {
    printf("5:55 p.m.");
  } else if (closest_time == 1140) {
    printf("9:20 p.m.");
  } else if (closest_time == 1305) {
    printf("11:58 p.m.");
  }
  printf("\n");

  return EXIT_SUCCESS;
}
