# Zadanie 1: Królewski namiestnik 

Królewski Namiestnik siedmiu królestw musi na co dzień zmagać się z niezliczoną ilością problemów, które napływają do niego z całego kraju. Są to za równo sprawy wielkiej wagi, np. raporty nocnej straży o zagrożeniach z za muru, informacje wywiadowcze, jak i sprawy tak prozaiczne jak kłótnie szlachty, które jednak bez odpowiedniej reakcji mogą zagrozić bezpieczeństwu wewnętrznemu państwa. Aby usprawnić cały proces decyzyjny, namiestnik rozkazał Ci opracować sposób przechowywania informacji, który pozwoli mu na optymalne zarządzanie państwem. Grupa zawiadowców pism codziennie zbiera korespondencję, która spływa z wszystkich stron kontynentu za pośrednictwem kruków pocztowych.  Przydzielają oni każdej sprawie priorytet (1-10) oraz kategorię (zagrożenie militarne, finanse, zagrożenie wewnętrzne, dyplomacja). Twoim zadaniem jest zebranie zaistniałych problemów w sposób, który usystematyzuje pracę Namiestnika.
## Wymagania:

1.  **Implementacja struktury drzewa:**

	Stwórz strukturę danych opartą na kopcu wraz z uwzględnieniem kategorii i priorytetu.

2.  **Operacje na drzewie:**

-   **Dodawanie:** Zaimplementuj funkcję/metodę **insert**, która pozwoli na dodawanie nowego problemu do drzewa.
-   **Pobranie / Usuwanie:** Zaimplementuj funkcję/metodę **pop**, która pozwoli na pobranie problemu i jego usunięcie z drzewa.


# Zadanie 2: Eskpansja systemu 

Twój system sprawdził się do tego stopnia, że Namiestnik Królewski nakazał wprowadzenie go wszystkim namiestnikom poszczególnych regionów Królestwa. Od tej pory raporty są przysyłane do królestwa w postaci **opracowanych przez Ciebie** struktur i konieczne jest ich połączenie. 

## Wymagania:

1. **Operacje na drzewie:**
   
-   **Łączenie:** Stwórz funkcję/metodę **merge**, która pozwoli na dodawanie kolejnych raportów napływających w postaci stert do sterty głównej.


# Zadanie 3: Dziel i zwyciężaj 

Na cotygodniowych spotkaniach małej rady Namiestnik naradza się ze starszym nad monetą, głównodowodzącym wojsk, ministrem dyplomacji oraz starszym nad szeptami. Ponieważ są oni ekspertami w swoich dziedzinach jest to świetna okazja aby przerzucić część obowiązków na nich.

## Wymagania:

1. **Operacje na drzewie**

-   **Dzielenie:** Stwórz funkcję/metodę **divide**, która  podzieli stertę główną na mniejsze drzewa, z czego w każdej z nich będą znajdować się tylko i wyłącznie problemy z jednej kategorii.
