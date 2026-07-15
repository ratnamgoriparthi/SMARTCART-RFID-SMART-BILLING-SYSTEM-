🛒 Smart Cart – RFID Smart Billing System using LPC2148 ARM7
________________________________________
⭐ Overview

An RFID-Based Smart Cart Billing System developed using the LPC2148 ARM7 Microcontroller to automate the shopping and billing process.
Unlike the conventional billing system, this project automatically identifies products using RFID technology, calculates the total bill in real time, and reduces the need for manual billing.

The system performs the following operations:

🛒 Product Identification

🏷️ RFID Tag Scanning

💰 Automatic Bill Calculation

📟 Real-Time LCD Display

➕ Product Addition

➖ Product Removal

The EM4095 RFID reader reads the unique RFID tag of each product, while the LPC2148 retrieves the corresponding product name and price from the database. The total bill is updated instantly and displayed on the LCD, providing a fast, accurate, and queue-free shopping experience.
________________________________________
📷 Complete System Architecture
<img width="979" height="769" alt="image" src="https://github.com/user-attachments/assets/35066381-cd3c-48ec-ac43-381d847d4e9d" />

 
_______________________________________________________________
🎯 Project Objectives


•	Eliminate long billing queues 

•	Automate product identification 

•	Reduce manual billing errors 

•	Provide real-time bill calculation 

•	Improve shopping convenience 

•	Fast and secure RFID-based billing 

•	Easy product addition and removal 

•	Database-based product management

____________________________________________________
Hardware Component	       and its              Purpose

LPC2148 (ARM7 Microcontroller)	Main controller that manages the entire smart cart billing system.
RFID Reader (EM4095)	Reads RFID tags attached to products and sends the tag ID to the LPC2148 via UART.
RFID Tags	Store a unique product identification number for each item.
16×2 LCD Display	Displays product name, price, quantity, and the total bill.
UART Interface	Provides serial communication between the RFID reader and the LPC2148 microcontroller.
Push Buttons (Optional)	Used for checkout, reset, or other user operations.
Power Supply	Supplies the required regulated voltage to power the complete system.
______________________________________________________________
🛒 System Working Flow

1.	Customer places products inside the smart cart. 
2.	Each product contains an RFID tag with a unique identification number. 
3.	RFID reader scans the product tag. 
4.	LPC2148 receives the tag ID through UART. 
5.	Controller searches the product database. 
6.	Product Name and Price are retrieved. 
7.	LCD displays: 
o	Product Name 
o	Product Price 
o	Total Bill 
9.	If the same tag is scanned again, the product is removed from the cart. 
10.	Final bill is displayed during checkout.
    
    <img width="731" height="1565" alt="image" src="https://github.com/user-attachments/assets/b03cb43e-d4a6-4f9e-a649-e9adbd07b62c" />


 

➕ Product Addition

When a new RFID tag is scanned:

•	Read RFID Tag ID 

•	Search Product Database

•	Retrieve Product Information 

•	Display Product Details 

•	Add Product Price to Total Bill 

•	Update LCD 
________________________________________
➖ Product Removal

When an already scanned RFID tag is scanned again:

•	Detect Existing Product 

•	Remove Product from Cart 

•	Deduct Product Price 

•	Update Total Bill 

•	Refresh LCD Display 


💾 Database Management

The system maintains a product database containing:

    Field	       Description
    
RFID Tag ID	               --->              Unique Product Identifier

Product Name	              --->                Name of the Product

Product Price	               --->                Cost of Product

Product Status	              --->               Present/Removed

The RFID tag stores only the unique product ID, while all product information is stored in the database. This makes updating prices or product details simple without modifying the RFID tags.
________________________________________
🔧 Communication Protocols
Device	              Protocol

RFID Reader	        -->     UART

LCD	                -->     GPIO

LPC2148	         -->  ARM7 Architecture

________________________________________
🔒 System Features

•	RFID-Based Product Identification 

•	Automatic Billing 

•	Real-Time Total Calculation 

•	Product Add/Remove Functionality 

•	LCD Display Interface 

•	Database-Based Product Lookup

•	Faster Checkout Process 

•	Reduced Human Errors 

•	Low Power Embedded System 

•	ARM7 Based Embedded Design 

________________________________________
🚀 Features	

•	Smart Shopping Cart 

•	RFID Product Identification

•	Automatic Bill Generation 

•	Real-Time Price Display 

•	Product Addition 

•	Product Removal 

•	Instant Total Calculation

•	Database Integration 

•	LCD User Interface 

•	Embedded C Firmware 

•	ARM7 Based Embedded System 
________________________________________
📸 Project Gallery
Project Screenshot | Project Screenshot | Project Screenshot | Project Screenshot | Project Screenshot
________________________________________
⚙ Working Principle

•	RFID Reader continuously searches for nearby RFID tags.

•	Every tag transmits its unique ID through electromagnetic induction. 

•	LPC2148 receives the ID through UART. 

•	The controller compares the received ID with the product database. 

•	Matching product details are fetched. 

•	Product information is displayed on the LCD. 

•	The bill is automatically updated. 

•	Scanning the same tag again removes the product from the cart. 
________________________________________
📚 Applications

•	Supermarkets 

•	Shopping Malls 

•	Hypermarkets 

•	Retail Stores 

•	Department Stores 

•	Smart Retail Systems 

•	Automated Billing Counters 

________________________________________
🎯 Advantages

•	Saves Customer Time 

•	Eliminates Billing Queues

•	Easy Product Tracking 

•	Accurate Billing 

•	Less Human Intervention 

•	Easy Inventory Integration

•	User-Friendly Interface 

•	Cost Effective 
________________________________________
💻 Software Used

•	Embedded C 

•	Keil μVision 

•	Flash Magic 
________________________________________
🔌 Hardware Used

•	LPC2148 ARM7 

•	RFID Reader (EM4095) 

•	RFID Tags 

•	16×2 LCD 

•	Power Supply

•	Connecting Wires 

•	Breadboard/PCB 
________________________________________
👨‍💻 Author

Ratnam Goriparthi

Bachelor of Technology (Electronics and Communication Engineering)

Embedded Systems Enthusiast

2025 Graduate

________________________________________

📜 License

This project is intended for educational and academic purposes.

Feel free to work, modify, and improve the project.

⭐ If you found this project helpful, consider giving it a Star on GitHub.

________________________________________
🙏 Thank You
Happy Coding! 🚀



