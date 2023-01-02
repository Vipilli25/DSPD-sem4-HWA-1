# DSPD-sem4-project
Developed Train seat allocation model using concepts of Data structures and algorithms, majorly used linked lists for storing data.

Implement the following system using a linked list of structures where every node of that list 
represents a record of passenger name, passenger id, boarding train, boarding station, 
travelling class(Sleeper, 3AC, 2AC, 1AC), destination station, train id, Seat number (bogie 
number/seat number), and any other field you think that would be useful to passengers. You 
can also take a confirmation from the passenger whether upgrade of travel class is desired. 

The passenger id can be thought as a key in the list and will represent a unique record in the 
list. The records should be always kept sorted according to the train id so that passengers
boarding the same train have their data together.

You can assume number of bogies of each class and number of seats in each bogie.

Write the following functions :

  -insert
  • Insert a list of passengers and their details for the reservation. <br>
  • I/p parameters: Reservation request that includes a list of passenger names, 
    passenger ids, boarding train, boarding station, travelling class(Sleeper, 3AC, 
    2AC, 1AC), destination station, train id.
  • O/P: Reservation done successfully, partially or the reservation failed.
  • Note – The set of passengers in a single reservation request should be 
    allocated seats together. If all of them cannot get the seats together, then they 
    need to be accommodated as close to each other in trains, that is, their 
    bogie/seat numbers should be as close to each other. 
