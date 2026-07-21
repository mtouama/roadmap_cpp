# roadmap_cpp

je pue la merde en cpp dcp je fais la roadmap cpp : https://roadmap.sh/cpp

## Sommaire

1. Introduction to Language
2. Setting up your environment
3. Basic Operations
4. Control Flow & Statements
5. Functions
6. Data Types
7. Pointers and References
8. Structuring Codebase
9. Exception Handling
10. Language Concepts
11. Standard Library + STL
12. Templates
13. Idioms
14. Standards
15. Debuggers
16. Compilers
17. Build Systems
18. Package Managers
19. Working with libraries

## Introduction to language

What is C++ ?

* extension de C
* OOP
* game dev / OS / high performance computing

## C vs C++

* ajout héritage, polymorphism
* ajout overloading, templates, exception handling

## Setting up your environment

* Installer C++
  * compiler : GCC / Clang
  * build system : Make/CMake
  * IDE

## Basic Operations

* Arithmetic operators
* Logical operators
* Bitwise operators
  * AND : &
  * NOT : ~
  * OR : |
  * XOR : ^
  * left shift : <<x : *2^x
  * right shift : >>x : /2^x (division entière)

## Loops

* for(int i=0; i<5; i++)
* while(condition)
* do{} while(condition)

## Conditional Statements

* if - else
* switch
* goto (déconseillé) : saute directement vers un tag

## Operator Overloading

Permet de redéfinir le fonctionnement d'un opérateur. ex : operator + (Type &t)

## Lambda

* nameless (optionnel)
* ex : [](int param){};

## Static polymorphism

* compile-time
* permet de définir plusieurs fonctions avec le même nom mais des paramètres différents
* définir des templates = utiles pour les fonctions génériques

## Function Overloading

Définir plusieurs fonctions avec le même nom mais des paramètres différents

## Datatypes : Static Typing

* variable connue et vérifiée au temps de compilation
* type conversion
  * implicit conversion
  * compilation error
* utiliser C++ Named Casts
  * static_cast
  * dynamic_cast
  * const_cast
  * reinterpret_cast

## Datatypes : Dynamic Typing

* type déterminé durant le runtime
* void* pointers
* std : any
* auto : type déduit automatiquement
* decltype( lib <type_traits>) : déduire le type d'une expression
* is_same<t1,t2> : retourne un bool, compare 2 types

## RTTI : Run-Time Type Identification

* détermine le type d'un objet durant l'exécution du programme
* utile pour le polymorphisme et l'héritage
* typeid operator : récupère informations du type
* dynamic_cast operator : converti pointers/references entre les types lors du runtime, pour gérer des potentiels problèmes de cast

## Upcasting

```C++
Shape *shape_ptr = nullptr;
Rectangle rect(10.0, 20.0);
shape_ptr = &rec;
```

## Downcasting

```C++
Shape *shape_ptr = nullptr;
Rectangle rect_ref(10.0, 20.0);
shape_ptr = &rec_ref;
Rectangle *rec_ptr = null_ptr;
rec_ptr = (Rectangle *) shape_ptr;
```

### dynamic_cast (safe downcasting) : 

```C++
<type> * ptr_derived = dynamic_cast<<type>*>(ptr_obj);
<type> ref_derived = dynamic_cast<<type>&>(ref_obj);
```

## Pointers & References

* Pointer : sauvegarde l'adresse mémoire d'une variable
  * permet une gestion dynamique de la mémoire
* Reference : alias d'une variable existante
  * permet d'accéder et de modifier sa valeur

## References

* doit être initialisé à sa création
* une fois initialisé, on ne peut pas modifier sur une autre variable
* utiliser en tant que paramètre dans une fonction autorisant la fonction à modifier la variable original

```C++
string &meal = food
meal = "burger" //change meal et food
```

## Memory Model

Organise et gère la mémoire durant l'exécution

* stack (pile) : appels des fonctions + variables locales
* heap (tas) : dynamic memory allocation
* data segment : global + static variables
* code segment : executable instructions

## Lifetime of Objects

* static : existe pour la durée du programme
* thread : existe pour la durée du thread
* automatic : existe dans un scope
* dynamic : controlé avec new et delete

## Smart pointers

* évite les fuites de mémoire
* gestion automatique de la mémoire
* techniques : reference counting et RAII (Resource Acquisition Is Initialized)
* encapsule un raw pointer

### Weak_ptr

* détient une référence à un shared_ptr
* n'est pas compté dans le reference counting
* n'empêche pas d'être détruit si l'objet sort du scope
* permet de détecter si objet shared_ptr existe toujours
* créer un shared_ptr à partir d'une weak_ptr avec lock()
  * si l'objet est déjà détruit, retourne un shared_ptr vide

### Shared_ptr

* créer plusieurs pointers qui partagent le même objet
* quand le dernier shared_ptr sort du scope, l'objet est détruit
* reference count : compteur d'instances shared_ptr qui pointent sur le même objet

### Unique_ptr

* donne la propriété exclusive d'un objet alloué dynamiquement
* seulement un unique_ptr peut pointer sur un objet
* supprime l'objet lorsque le unique_ptr sort du scope/reset
* la propriété peut être transférer à un autre unique_ptr
  * std::move

### Raw pointer 

Variable qui stocke l'adresse mémoire d'une autre variable

## New/Delete Operators

* New : alloue un block de mémoire dans le tas et retourne un pointer du début du block
* Delete : libère le block de mémoire

## Fuite de mémoire

Lorsque la mémoire allouée dynamique n'est plus accessible pour le programme, et que le programme n'arrive plus à libérer de la mémoire
