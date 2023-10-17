Gratulujemy pomyślnego przejścia pierwszego etapu rekrutacji! W drugim etapie chcielibyśmy sprawdzić Twoje umiejętności programowania w C++ oraz posługiwania się systemem kontroli wersji.

Twoim zadaniem będzie zaimplementowanie zadań opisanych poniżej. Ocenie będzie podlegać:
- Poprawność kodu (czy testy przechodzą czy nie)
- Jakość kodu (podział na metody, nazewnictwo zmiennych, porządek w kodzie)
- Złożoność obliczeniowa zastosowanych algorytmów
- Pokrycie testami jednostkowymi
- Historia commitów, ew. podział na branche

Skończone rozwiązanie prześlij nam za pomocą dodania jako kontrybutorów do Twojego forka poniższe konta:
- [paulinagacek](https://github.com/paulinagacek)
- [adakPaleczny](https://github.com/adakPaleczny)

Dodanie tych kont do Twojego forka będzie równoznaczne z oddaniem zadania.

Deadline do przesłania rozwiązań to 23.10.2023 godz. 21:37. Po tym terminie zadania nie będą przyjmowane.

# Konfiguracja środowiska

## Wymagania systemowe
1. Linux albo WSL
    - Wszystkie poniższe komendy są tworzone pod linuxa, gdyż nasz system działa jedynie na linuxie. 
    - Jeśli uda Ci się skonfigurować repo na Macu lub Windowsie to możesz również programować w takiej konfiguracji.
2. GCC lub inny kompilator cpp
3. Git

## Setup repozytorium
1. Utwórz forka tego repozytorium w swoim profilu ([how to fork a repo](https://docs.github.com/en/get-started/quickstart/fork-a-repo)). Wszystkie zmiany powinny być komitowane na forka, a nie do orginalnego repo.
   **Uwaga:** zmień widoczność swojego repozytorium na prywatne! Znajdziesz tę opcję na dole ustawień repo!
3. Sklonuj swoje repozytorium
    ```bash
    git clone ${adres_repo}
    ```
4. Stwórz folder `build` wewnątrz sklonowanego repo
    ```bash
    mkdir build
    ```

## Jak odpalić
1. Zbuduj projekt
```bash
cd build && cmake .. && make
```
2. Puść testy jednostkowe
```bash
ctest -V
```
3. Po modyfikacji kodu źródłowego wystarczy, że w folderze build uruchomisz komendę:
```
make && ctest -V
```
żeby sprawdzić czy testy przechodzą.
Jeśli zmodyfikowałaś/eś dodatkowo `CmakeLists.txt` konieczna jest komenda `cmake`.


# Zadanka

Dana jest klasa AGHRacingTeam, reprezentująca zespół AGH Racing. Posiada ona atrybut `members` będący tablicą reprezentującą członków zespołu. 

## Zad. 1.

Zaimplementuj metodę `addMember(std::string name, int height, int yearOfJoining)`, która doda nowego członka do tablicy `members` TYLKO jeśli podane parametry są poprawne, tzn:

Założenia:
1. Wzrost wyrażony jest jako dodatnia liczba całkowita 100 <= x <= 250. 
2. Imiona członków zespołu składają się z symboli alfanumerycznych, zaczynają się z wielkiej litery oraz `len(name) < 20`.
3. Rok dołączenia jest pomiędzy [2000, 2023] włącznie.

## Zad. 2.
 
Uzupełnij funkcję `getMembersSortedByHeightAsc`, która zwróci imiona członków zespołu posortowane w kolejności rosnącej według ich wzrostu.

## Zad. 3.

Uzupełnij funkcję `getNumberOfMembersWhoJoinedInLeapYear`, która zwróci liczbę członków zespołu, którzy dołączyli do niego w roku przestępnym.

## Zad. 4.

Uzupełnij funkcję `getMaxNumberOfJoinedInTheSameYear`, która zwróci maksymalną liczbę członków, którzy dołączyli do zespołu tego samego roku. 

### Przykład 1
Aktualni członkowie zespołu to A, B, C. Dołączyli oni kolejno w 2020, 2021 i 2020. Funkcja powinna zwrócić liczbę 2, gdyż 2 członków dołączyło w 2020.

### Przykład 2
Aktualni członkowie zespołu to A, B, C, D. Dołączyli oni kolejno w 2020, 2021, 2021, 2021. Funkcja powinna zwrócić liczbę 3, gdyż 3 członków dołączyło w 2021.

## Zad. 5.
Stwórz konstruktor jednoargumentowy dla klasy `AGHRacingTeam`, który jako argumnet przyjmuje std::vector<Member> i doda do zmiennej `members` tylko tych członków, którzy spełniają wymagania z zadania 1. 

## Zad. 6.
Stwórz konstruktor kopujący dla klasy `AGHRacingTeam`. Zadbaj o to, żeby kopia pola `members` była płytka, a nie głęboka.

## Uwagi

1. Nie modyfikuj testów jednostkowych, które zostały podane, ale możesz dopisać swoje własne odrębne testy jednostkowe.
2. Nie modyfikuj struktury dostarczonych klas. Możesz jednak dodać swoje własne metody lub pola.
3. Nie udostępniliśmy Ci wszystkich testów jednostkowych, którymi sprawdzać będziemy Twój kod. W związku z tym nawet jeśli wszystkie testy przechodzą, nie znaczy to, że kod jest poprawny.


Powodzenia!
