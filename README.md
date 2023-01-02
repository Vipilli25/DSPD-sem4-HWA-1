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

  1)  insert 
   a. Insert a list of passengers and their details for the reservation. 
   
   b. I/p parameters: Reservation request that includes a list of passenger names, 
      passenger ids, boarding train, boarding station, travelling class(Sleeper, 3AC, 
      2AC, 1AC), destination station, train id. 
      
   c. O/P: Reservation done successfully, partially or the reservation failed. 
   
   d. Note – The set of passengers in a single reservation request should be 
    allocated seats together. If all of them cannot get the seats together, then they 
    need to be accommodated as close to each other in trains, that is, their 
    bogie/seat numbers should be as close to each other.
    
  2)  delete
   a. Deletes an element if the passenger cancels the reservation.
   
   b. I/p parameters: deleting all records of that particular passenger id.
   
   c. O/p: If node gets deleted print Reservation cancelled successfully or if it gets 
      failed then print Reservation Cancellation failed.
      
  3)  getListDestination
   a. Get the list of passengers having the same destination station and same train id
     
  4)  SortByTravelDate
   a. Input – Passenger id 
   
   b. Output – Display the list of destination stations for a particular passenger as 
      per the dates of the travel.

