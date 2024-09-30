# Oladoc-Hospital-Management-System
Programmed a back-end system in C++ that represented a hospital management system. It included multiple user portals, appointment scheduling, payment methods, and the ability to handle doctors' and patients' entries using the concepts of inheritance and polymorphism.
## Hierarchy in classes
* Doctor admin and patient class are inherited by the user class, constituting a composition with the menu class.
* Gateways classes make inheritance to payment.
* Payment and feedback classes make a composition to the appointment class.
* Appointment class makes composition to doctor class and aggregation to admin and patient classes.
* Doctor and patient aggregate to admin
* The doctor admin and patient login panels are inherited from the menu.
* Doctor admin and patient registration panel inherit to register class, which makes a composition with the menu.

## UML Case Diagram

![UML class](https://github.com/user-attachments/assets/021da6d5-99bb-42e0-a5fb-eb5d42e59544)
