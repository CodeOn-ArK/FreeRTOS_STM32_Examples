# Intro to RTOS

## Real Time Application :

- In RTAs the response time is guaranted and predictable, failure to meet the time contraints can cause system failure
- In non RTAs the reponse time increases with system load, unlike RTAs which guarantes constant response time
- There could be small deviations in RTAs reponse time, in wuch case they are called soft-RTAs. Hard RTAs must complete within the time limit, failure to do so will result in absolute failure of the system
- In short they are time deterministic applications

## Task Scheduling : 

- In RTOS, thread executes in the order of priority. Higher Priority threads get more chance over lower priority counterparts. 
- During thread execution if any higher priority thread becomes ready to run then it takes over the CPU and the lower priority thread gets paused.

   
