// /*****
//  * 
//  * 
//  * inheritance: is - a relationship
//  * Composition: Has-a relationship. represented with a close diamond with diamond cleosewd to parent class | represnets tose parent child replations in which the child class cannot exist without the parent class./
//  * 
//  * Agregation: represented with a hollow diamond | 
//  * 
//  * 
//  * 
//  * 
//  */

// Encapsulation: 
/***
 * 
 * 
 * Car: has characters and behaviour
 * It is like a capsule tha tall the berhaviour and characters are in a single capsule and in one class;
 * we represent the data in terms of a class in which we define the variables and methods related to the object.
 * Also enbcapsulation adds oanother point about data security.
 * THose variables and methods which comes out to open world then security can be at stake.
 * acelerate brake; odometer increases.
 * 
 * class Car {
  * variables -> characeers
  * methods: behaviour: 
 *  
 * all variables need not be public, sue access modifiers.
 *  public: can be accessed by any one outside world/  in class
 *  private: can be only accessed within class.
 *  protected: no one from outside can use it but child classes can use it.
 * 
 * }
 * 
 * 
 */

 // Polymorphism:

// are of 2 types;
// dynamic Polymorphism: also called Method overriding
// Static polymorphism: also called as method overloading

// SOLID PRINCIPALS
/****
 *
 *
 * Maintainability:
 * Readability.
 * Bugs
 *
 *
 * S: Single responsibility principle
 * A class hsould have only one principle.
 * A class shoould have only one reason to change.
 *
 * O: open close principle
 *
 *
 * L: Liskov Substitution princile
 * I: Interface segregation principle
 * D: Dependency Inversion principle
 *
 *
 *
 */

 /***
 * 
 * 
 * Open Close Principle: A class should eb open for extension but close for modification;
 * 
 * to integrate the new feature, old code should not be touched
 * 
 * 
 * 
 */

/**
 *
 * subclasses should be substitutable for threit base classes.
 *
 * A base class
 * B sub-class
 *
 * say client which is expecting the base class referrence and we padss the subclass referrence then there should be no breaking changes.
 * Subclass should be simiarly substitutable and should be able to take place of the base class
 *
 * when can we overwrite the parent class with child class: 
 * 
 * Broader class also called as Parent class
 * narrow Class: Child Class
 * 
 * Signature Rule: during function override, the argumets passed to the functions signature shiould be either the same type or should be of the broader class 
 * Property Rule: 
 * Method Rule: 
 *
 */

 // Return type rule: 
/**
 * Animal<- Dog Dog is a animal;
 * when we override a method of parent class then in return type we can either put the same return type as that in base class or 
 * we can put the return type of the narrow type but we cannot put the broader type of the class defined in parent class. 
 * 
 * Co Variance: in return type we can either specify the same class or the narrow class of the already specified class in overridden function
 * 
 * 
 */

/***
 * 
 * Exception Rule: if the function in parent clas tha tis overrriden in child class throws an exception let say a runtime exception, 
 * then overridden fuynction either throws a narrow or same exception but not the exception that belongs to the broader class of the exception. 
 * parent <- child: child is a parent::::: 
 * 
 * Hierarchy of exceptions: 
 * Logical error:
 * - out of range exception
 * runtime error: 
 * 
 */

/*

std:: logic_error:
- incvlidArguement
- domainError
- lengthError
- outOfRange

std::runtimeError:
- rangeError
- overflowError
- udnerflowError
*/

/**
 * 
 * Property Rules: 
 * Class invariant: 
 * history Contraint: 
 * 
 */


 /**
  * Class Invariant:
  * any  fact or rule tha tis true for a class:
  * the rule states that we have a class and we have an invariant r1 so the child class has the reponsibility to follow that invariant and do not break the invarinat.
  * Child class needs to follow the invariant, it can strengthen the invariant but should not make the invariant weak.
  * 
  * just add a comment on top of the parent class about the invariant, nothing else so that the future developer know what invariant needs to be followed in future codes. 
  */


/**
 * history Constraint: 
 * history should nevenr change: the state that parent class maintains should be maintained in child clas as well.
 * 
 */

/***
 * Interface Segregation principle: 
 * many lcient specific interface are better that one geenral interface: 
 * 
 * 
 * Client shouild not be forcesd to implement mehods they do not need.
 * 
 * 
 * 
 * 
 */