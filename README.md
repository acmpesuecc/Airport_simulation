# Airport-simulation
## Description
There is a small busy airport with only one runway. In each unit of time one plane can land or one plane can take off, but not both. Planes arrive ready to land or to take off at random times, so at any given unit of time, the runway may be idle or a plane may be landing or taking off. There may be several planes waiting either to land or to take off.
## Overveiw of the program
The program is designed in the following way:  
1. Two queues, one for the planes landing and the other for planes taking off.
2. The maximum number of units for which the simulation program would run.(Input from the user)
3. The expected number of planes arriving in one unit and number of planes ready to take off in one unit .(Input from the user)

The process of simulation would run for many units of time, hence run a loop in main( ) that would run from to where would be 1 and would be the maximum number of units the program has to be run.
Random numbers are given(in step 3 above).Remember that the random number should be less than or equal to 1(or else the simulation is saturated). 

### Algorithm
1. Checking whether or not the queue for landing of planes is full. If the queue is full then the plane is refused to land, otherwise data is added to the queue            maintained for planes landing.

2. If the random number generated is zero, then generate a random number again, checked if this number is less than or equal to 1. If it is , then data for the plane ready to take off is got.Then checked if or not the queue for taking a plane off is full. If the queue is full then the plane is refused to take off otherwise the data is added to the queue maintained for planes taking off.

3. It is better to keep a plane waiting on the ground than in the air, hence allow a plane to take off only, if there are no planes waiting to land.

4. After receiving a request from new plane to land or take off, check the queue of planes waiting to land, and only if the landing queue is empty, allow a plane to take off.

5. If the queue for planes landing is not empty then the data of plane in the queueis removed else the procedure to land the plane takes place.

6. Similarly, if the queue for planes taking off is not empty then the data of plane in the queue is removed else the procedure to take off the plane is executed.

7. If both the queues are empty then the runway would be idle.

8. Finally, the statistical data are displayed.

This is a very beginner friendly program that gives real-life application of c-concepts like linked list and queues.
Hope you all find it helpful and informaive:)))


