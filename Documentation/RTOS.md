# Intro to RTOS

## Real Time Application :

- In RTAs the response time is guaranted and predictable, failure to meet the time contraints can cause system failure
- In non RTAs the reponse time increases with system load, unlike RTAs which guarantes constant response time
- There could be small deviations in RTAs reponse time, in wuch case they are called soft-RTAs. Hard RTAs must complete within the time limit, failure to do so will result in absolute failure of the system
- In short they are time deterministic applications

## Task Scheduling : 

- In RTOS, thread executes in the order of priority. Higher Priority threads get more chance over lower priority counterparts. 
- During thread execution if any higher priority thread becomes ready to run then it takes over the CPU and the lower priority thread gets paused.

## FREE-RTOS Task Creation :

- ```TASKS``` are computational unit that runs on a CPU under the control of a ```KERNEL```. Tasks run alternately on a CPU consuming resources in a synchronous way, and giving each activity enough time to complete its job.
- To use a task we first need to create a task and then need to implement the task function.
- Task creation creates mem region for the Task stack and TCB, and the task handler is the one which runs on the CPU.
- Variables within task handler are created locally in stack, of the respective Tasks. If the variable is static and multiple Tasks are using it, then it acts as a single shared resource between the two Tasks
- A task handler has a infinite loop inside it which runs continously just like the infinte loop in main code.
- In case the task implementation breaks the loop, the task must be deleted with APIs such as ```vTaskDelete(NULL)``` or else suffer chaos.
- The Task stack space is used to store code status, variables etc, during context switch
- Once the Task is created it is put undet Ready list for the ```SCHEDULER``` to pick up when needed.

## RTOS Memory management scheme:

- Things such as Tasks, Semaphore, Queues, Mutexes are called Kernel Objects since they are created by the Kernel during the execution of the program, i.e. runtime allocaiton of memory happens.
- Since these are dynamically created they use up the heap memory. 
- The ```RAM``` is divided up in 2 parts; One is Heap region the other is used to store global data, arrays, static data etc.
- In Heap all the mem allocation for TCB and Task's stack is done.
- The TCB is created in heap and initialized
- The heap size can be configured using ```configTOTAL_HEAP_SIZE```.
- The Kernel also maintains its separate stack which it uses during ```SYSTICK``` or ```PendSV``` or any other interrupts
- The Kernel Stack is maintained by ```MSP``` and the Task Stack AKA Process Stack is maintained by ```PSP```.

## Task Scheduling && SCHEDULER

- In FREE-RTOS the Tasks run on the CPU when the scheduler allows them to.
- The scheduler schedules the tasks to run on the CPU. Its basic task is to determine which is the next potential task to run on the CPU.
- There are several types of scheduling policies such as :-
> Pre-emptive :
	The task(s) execute in a round robin manner

> Priority based pre-emptive :
	The task(s) execute in a prioritised way, i.e. tasks with higer priority get more time in CPU and vice versa.

> Co-operative :
	Task(s) work in tandem and yield CPU for next ```READY``` task after it has executed 

## IDLE Task

- IDLE task is a background task which has the lowest priority and runs on CPU when no other task is running. 
- It works as a cleanup task which deallocates mem when a task is deleted.
- It is created by ```scheduler```.

## TIMER Services

- It is also known as timer daemon task which deals with ```Software Timers```.
- Used to manage FreeRTOS s/w timers.
- All s/w timer callback functions execute in the cntext of the timer daemon task.

## FreeRTOS Kernel Interrupts

- Below interrupts are used to schedule tasks in ARM Cortex based architecture
[x] SVC Handler : It is used to launch the very first task
[x] PendSV	: It is used for context switching purpose
[x] SYSTICK 	: It is used for RTOS Tick management, to account for time elapsed in terms of system ticks

- All these interrupts are configured at lowest possible priority value

## Context Switching

- It is the process of switching in of one task and switching out of another task. It is done by the scheduler.
- Whether a switching will happen depends on the scheduling policy.
- The PendSV Kernel Interrupt is used for this purpose.
- During context switch, the ```Task State```, i.e. Processor core regs + Stack Contents, are saved.
> Tasks run in ```THREAD mode```  in ARM Cortex arch

> ISRs run in ```HANDLER mode``` in ARM Cortex arc
h
