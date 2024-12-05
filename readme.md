This system provides functionalities for managing trading orders in a financial application. It adheres to the SOLID principles for object-oriented design, ensuring a scalable, maintainable.

Scope
The following functionalities are implemented:

Place Order: Create new trading orders with specified parameters.
Cancel Order: Cancel an existing trading order by its ID.
Modify Order: Update the parameters (e.g., price) of an existing order.
Get Orderbook: Fetch the current market orderbook for a specific instrument.
View Current Positions: Retrieve active positions of a user.


#  Design Principals

The system is designed with the SOLID principles:

#  Single responsibility Principal
Each class has a single responsibility, such as managing API requests or handling business logic.

#  Open/close Principal
Classes are open for extension but closed for modification. New functionality can be added without altering existing code.

#  Liskov Principal
Derived classes can replace their base classes without altering program behavior.

# Interface SeggrEgation principal
Clients are not forced to implement unnecessary methods. Interfaces are minimal and focused.


# Dependency Inversion Principal
High-level modules depend on abstractions, not concrete implementations.


CODE OVERVIEW

# Interfaces
OrderManagerInterface
Defines the contract for order management:

# ApiClient
Handles communication with external APIs:

#  main.cpp 
call services
Compile the Project: Run the following command in the root directory:



#  HIGH LEVEL DESIGN OVERVIEW
 +----------------+           +----------------+           +-------------------+
 |  User Interface| <-------> |  Order Manager | <-------> |  API Client       |
 +----------------+           +----------------+           +-------------------+
         |                          |                             |
         v                          v                             v
  [Place Order, Cancel Order]  [Place/Modify/Cancel]      [Communicate with]
           |                        |                             |
           v                        v                             v
   +----------------------------+  +------------------------+   +--------------------+
   | External Trading API       |  | API Response           |   | API Response       |
   | (place, modify, cancel, view)|  | (confirmation or  |   | (order status or failure)|
   +----------------------------+  | failure)             |   +--------------------+
               |                                                   |
               +---------------------------------------------------+
                        [API Response: Success or Failure]



                        Issue Faced: WebSocket Server Creation



# Issue faced 
While creating a WebSocket server, I faced difficulty in choosing the correct library. This issue arose while attempting to implement a WebSocket server in C++, as there was a lack of clarity regarding the compatibility and features of various available libraries.

