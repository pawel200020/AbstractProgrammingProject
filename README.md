# Abstract Programming Project
Założenia Projektu:
- obiektowść:
  - polimorfizmy
  - abstrakcje
  - dziedziczenia
  - iterface
- Szablony
- Biblioteka standardowa
  - pojemniki
  - funktory
  - przeglądanie obiektów
- Koncepty
- Metaprogramowowanie
- Git 

Należy wykorzystać co najmniej 3 z powyżej wymienionych

## Symulator meczu - aplikacja konsolowa
- Technikalia
  - Technologie: *C++ 20*
  - Dev Ide: CLion


### Zastosowanie założeń projektu w aplikacji
- **Obiektowość** - **directory Models**: Human, Fan, Player, Attacker, Defender, Goal keeper
  - **polimorfizmy** - metoda virtualna print w klasie Human, zachowuje się inaczej, w zależność od tego czy obiekt jest typu *Player* czy typu *Fan*
  - **abstrakcje** - klasa abstrakcyjna **Human** posiada metodę czysto virtualną.
  - **Dziedziczenie**: Po klasie Human dziedziczy *Player, Fan* z koleji po klasie *Player* dziedziczy *Attacker, Defender, GoalKeeper*.
  - **interface** - C++ z zasady nie wspiera interface za to możemy powiedzieć że klasa czysto virtualna **Human** jest takim interafacem.
- **Szablony** 
  - *readFromFileToList* wczytująca z pliku do zadanego typu listy.
  - *printList* wypisująca listę dowolnego typu.
  - *printArray* wypisująca tablicę dowolnego typu.
  - *createSubList* tworząca sublistę zadanego typu o zadanym przez szablon rozmiarze.
- **Biblioteka standardowa** 
  - **pojemniki** - przechowywane w listach imienia i nazwiska graczy, przechowywani w wektorach członkowie teamu oraz gracze.
  - **przeglądanie obiektów** - wypisanie graczy i fanów na konsolę, przeglądanie w celu pobrania napastnika do akcji, przeglądanie w celu wypisania n random fanów, przeglądanie list z imionami i nazwiskami w celu stworzenia graczy i fanów.
- **Metaprogramowowanie** - bubble sort do sortowania statystyk graczy wypisywanych na ekran
- **Git** - Zastosowano system kontroli wersji wraz z publikacją projekt do publicznego repozytorium na GitHub'ie.
