## ShuffleboardSender
## Usage
### Setup
Copy the ShuffleboardSender folder from /include and /cpp into their respective folders.
(If using the vector class, copy the ShuffleboardItems/SI_vector.hpp into the utils folder)
### 
### Implementation
#### Includes

The main file you need to include is ShuffleboardSender.h.
This supports:
* Primitives
* units::volt_t
* frc::PIDController
If you have special classes that implement BasicShuffleboardItem, you need to include their respective SI__classname_.hpp file, as it is a template specialization. (SI stands for ShuffleboardItem)
Currently the special classes implemented:
* svector::Vector (SI_vector.hpp)
#### Constructor
A ShuffleboardSender instance creates a tab on shuffleboard, which allows more organization of shuffleboard 
The constructor takes 2 parameters:
* string **name** -> the name of the tab
* bool **enabled **(default true) -> if the tab is enabled (this allows for an instance of the ShuffleboardSender but no instance of a tab)
#### Update
**VERY IMPORTANT TO IMPLEMENT**
In order for values to be updated on shuffleboard and in the robot code, ShuffleboardSender.update() must be called periodically. It goes through all the ShuffleboardItems on the tab and provides changes.
It has 1 parameter:
* bool **edit **(default false) -> if is true, enables changed values to propagate back into the code, hence enabling add functions to work. **VERY IMPORTANT TO SET TO TRUE IF YOU PLAN TO HAVE SHUFFLEBOARD VALUES EDIT THE ROBOT CODE**



#### add

The add function adds a basic item to the shuffleboard (a text box usually)

It has the ability to edit the value passed in through shuffleboard, as you pass in a pointer. So, this allows for less convoluted debugging code, although it does provide a vulnerability.

It has 1
#### addButton
#### addToggleButton
#### Normal Shuffleboard Behavior+
PutNumber, PutBoolean etc. and GetNumber, GetBoolean etc. still exist, but with the addition that you can specify your pose information. It functions the same, but be aware you need to call the update function.
