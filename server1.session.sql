CREATE TABLE customer(
    customerID INT PRIMARY KEY,
    customerFirstName VARCHAR(25),
    customerLastName VARCHAR(25),
    customerEmail VARCHAR(40),
    customerPhoneNumber INT
);

DESCRIBE customer; 

ALTER TABLE customer ADD 