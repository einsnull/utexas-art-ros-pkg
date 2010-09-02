/* -*- mode: C++ -*-
 *
 *  Navigator stop controller
 *
 *  Copyright (C) 2007, 2010, Austin Robot Technology
 *  License: Modified BSD Software License Agreement
 *
 *  $Id$
 */

#ifndef __STOP_H__
#define __STOP_H__

class Stop: public Controller
{
public:

  Stop(Navigator *navptr, int _verbose);
  ~Stop();
  void configure();

  // regular control method -- not supported
  result_t control(pilot_command_t &pcmd);

  // overloaded control method
  result_t control(pilot_command_t &pcmd, float distance, float threshold,
                   float topspeed=3.0);
  void reset(void);

private:
  // .cfg variables
  double min_stop_distance;             // minimum distance to begin stopping
  double stop_creep_speed;              // speed while creeping forward
  double stop_deceleration;             // desired deceleration
  double stop_latency;                  // stop control latency in seconds

  // controller state
  bool stopping;                        // stopping initiated
  bool creeping;                        // creeping up to line
  double initial_speed;                 // initial speed while stopping
  double max_creep_distance;            // applicable distance for creep
};

#endif // __STOP_H__
